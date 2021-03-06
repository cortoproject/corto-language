/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>
#include "ast__private.h"
/*#define CORTO_INIT_DEBUG*/
#ifdef CORTO_INIT_DEBUG
static int indent;
#endif
typedef struct ast_Initializer_findMember_t {
    corto_int32 lookForLocation;
    const char *lookForString;
    corto_uint32 id;
    corto_uint32 count;
    corto_uint32 current;
    corto_member m;
}ast_Initializer_findMember_t;
/* Walk members, look it up */
corto_int16 ast_Initializer_findMember(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_uint32 result;
    ast_Initializer_findMember_t* data;

    result = 0;
    data = userData;

    switch(v->kind) {
    case CORTO_MEMBER:
        if (v->is.member.member->id == (corto_uint32)-1) {
            result = corto_walk_value(s, v, userData);
        } else {
            if ((data->lookForLocation >= 0) && ((corto_uint32)data->lookForLocation == data->count)) {
                data->m = v->is.member.member;
                data->id = data->count;
                goto found;
            } else if (data->lookForString && !strcmp(data->lookForString, corto_idof(v->is.member.member))) {
                data->m = v->is.member.member;
                data->id = data->count;
                if (data->current >= data->count) {
                    goto found;
                }

            }

            data->count++;
        }

        break;
    default:
        corto_assert(0, "invalid valueKind for member-callback.");
        break;
    }

    return result;
found:
    return -1;
}

/* Create serializer */
corto_walk_opt ast_findMemberSerializer(corto_bool findHidden) {
    corto_walk_opt s;
    corto_walk_init(&s);
    s.metaprogram[CORTO_MEMBER] = ast_Initializer_findMember;
    s.access = CORTO_LOCAL | CORTO_PRIVATE | CORTO_READONLY;
    if (!findHidden) {
        s.access |= CORTO_HIDDEN;
    }

    s.accessKind = CORTO_NOT;
    s.traceKind = CORTO_WALK_TRACE_NEVER;
    s.aliasAction = CORTO_WALK_ALIAS_FOLLOW;
    s.optionalAction = CORTO_WALK_OPTIONAL_ALWAYS;
    return s;
}

corto_type ast_Parser_initGetType(ast_Initializer this, corto_member *m_out) {
    corto_type t, result;

    result = NULL;

    if (m_out) {
        *m_out = NULL;
    }

    if (this->fp > 0) {
        t = this->frames[this->fp-1].type;
        if (this->frames[this->fp].isKey) {
            result = corto_map(t)->key_type;
        } else {
            switch(t->kind) {
            case CORTO_COMPOSITE: {
                corto_walk_opt s;
                ast_Initializer_findMember_t walkData;
                if (!this->frames[this->fp].member) {
                    s = ast_findMemberSerializer(FALSE);
                    walkData.id = 0;
                    walkData.count = 0;
                    walkData.lookForLocation = this->frames[this->fp].location;
                    walkData.lookForString = NULL;
                    walkData.m = NULL;
                    walkData.current = 0;
                    corto_metawalk(&s, t, &walkData);
                } else {
                    walkData.m = this->frames[this->fp].member;
                }

                if (walkData.m) {
                    result = walkData.m->type;
                    if (m_out) {
                        *m_out = walkData.m;
                    }

                } else {
                    /* If m_out is not set this function is not used to determine the type
                     * for setting a value in an initializer. */
                    if (m_out) {
                        ast_Parser_error(yparser(), "member out of range");
                    }

                }

                break;
            }

            case CORTO_COLLECTION:
                result = corto_collection(t)->element_type;
                break;
            default: {
                /* If value is a non-composite type it can only have one initializer value. If there are more
                 * values specified (thus location != 0) report an error. */
                if (!this->frames[this->fp].location) {
                    result = t;
                } else {
                    if (m_out) {
                        corto_id id;
                        ast_Parser_error(yparser(),
                            "too many elements for non-composite\\collection type '%s'", ast_Parser_id(t, id));
                        result = NULL;
                    }

                }

                break;
            }

            }

        }

    } else {
        if (this->frames[0].location == 0) {
            result = this->frames[0].type;
        } else {
            corto_id id;
            if (this->frames[0].type->reference) {
                ast_Parser_error(yparser(), "excess elements in initializer for reference type '%s' (location=%d)",
                        ast_Parser_id(this->frames[0].type, id), this->frames[0].location);
            } else {
                ast_Parser_error(yparser(), "excess elements in initializer for primitive type '%s' (location=%d)",
                            ast_Parser_id(this->frames[0].type, id), this->frames[0].location);
            }

        }

    }

    return result;
}

int16_t ast_Initializer_construct(
    ast_Initializer this)
{
    corto_uint32 variable;
    corto_type t = ast_Expression_getType(this->variables[0].object);

    if (!t) {
        ast_Parser_error(yparser(), "parser error: invalid object in initializer"); abort();
        goto error;
    }

    /* Initialize first frame with type */
    for(variable=0; variable<this->variableCount; variable++) {
        corto_set_ref(&this->frames[variable].type, t);
        /* corto_set_ref(&this->rvalueType, t); */
        this->frames[variable].location = 0;
    }

    this->fp = 0;
#ifdef CORTO_INIT_DEBUG
    {
        corto_id id, id2;
        printf("%*s%d[%s %p]: construct (type=%s)\n",
            indent, " ", yparser()->line, ast_Parser_id(corto_typeof(this), id), this, ast_Parser_id(t, id2));
        indent++;
    }

#endif
    /* If type of initializer is either a composite or a collection type, do an initial push */
    if ((((t->kind == CORTO_COMPOSITE) && (corto_interface(t)->kind != CORTO_DELEGATE)) || (t->kind == CORTO_COLLECTION))) {
        if (ast_Initializer_push(this)) {
            goto error;
        }

    }

    ast_Node(this)->kind = Ast_InitializerExpr;
    corto_set_ref(&ast_Expression(this)->type, t);
    return 0;
error:
    return -1;
}

corto_type ast_Initializer_currentType(
    ast_Initializer this)
{
    return ast_Parser_initGetType(this, NULL);
}

int16_t ast_Initializer_defineObject_v(
    ast_Initializer this)
{
    CORTO_UNUSED(this);
#ifdef CORTO_INIT_DEBUG
    {
        corto_id id;
        indent--;
        printf("%*s%d[%s %p]: define\n",
               indent, " ", yparser()->line, ast_Parser_id(corto_typeof(this), id), this);
    }

#endif
    return 0;
}

uint16_t ast_Initializer_initFrame(
    ast_Initializer this)
{
    corto_walk_opt s;
    corto_type t;
    ast_Initializer_findMember_t walkData;

    /* Lookup corresponding member for current value (if there is any) */
    if (this->fp) {
        t = this->frames[this->fp-1].type;
        s = ast_findMemberSerializer(FALSE);
        walkData.id = 0;
        walkData.count = 0;
        walkData.lookForLocation = this->frames[this->fp].location;
        walkData.lookForString = NULL;
        walkData.m = NULL;
        walkData.current = this->frames[this->fp].location;
        if (t->kind == CORTO_COMPOSITE) {
            corto_metawalk(&s, t, &walkData);
        }

        if (walkData.m) {
            this->frames[this->fp].location = walkData.id;
            corto_set_ref(&this->frames[this->fp].member, walkData.m);
            corto_set_ref(&this->frames[this->fp].type, walkData.m->type);
            /*corto_set_ref(&yparser()->rvalueType, walkData.m->type);*/
        } else {
            corto_set_ref(&this->frames[this->fp].member, NULL);
            if (t->kind == CORTO_COLLECTION) {
                corto_set_ref(&this->frames[this->fp].type, corto_collection(t)->element_type);
                /*corto_set_ref(&yparser()->rvalueType, corto_collection(t)->element_type);*/
            } else {
                corto_set_ref(&this->frames[this->fp].type, NULL);
            }

        }

    }

    return 0;
}

int32_t ast_Initializer_member_v(
    ast_Initializer this,
    const char *name)
{
    corto_walk_opt s;
    corto_type t;
    ast_Initializer_findMember_t walkData;

    if (!this->fp) {
        ast_Parser_error(yparser(), "unexpected member '%s' in initializer", name);
        goto error;
    }

    t = this->frames[this->fp-1].type;
    s = ast_findMemberSerializer(TRUE);
    walkData.id = 0;
    walkData.count = 0;
    walkData.lookForLocation = -1;
    walkData.lookForString = name;
    walkData.m = NULL;
    walkData.current = this->frames[this->fp].location;
    if (t->kind == CORTO_COMPOSITE) {
        corto_metawalk(&s, t, &walkData);
    }

    if (walkData.m) {
        /* this->frames[this->fp].location = walkData.id; */
        corto_set_ref(&this->frames[this->fp].member, walkData.m);
        corto_set_ref(&this->frames[this->fp].type, walkData.m->type);
        /*corto_set_ref(&yparser()->rvalueType, walkData.m->type);*/
    } else {
        corto_id id;
        ast_Parser_error(yparser(), "member '%s' invalid for type '%s'", name, ast_Parser_id(t, id));
        corto_set_ref(&this->frames[this->fp].type, NULL);
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t ast_Initializer_next_v(
    ast_Initializer this)
{

    /* Increase location by one */
    this->frames[this->fp].location++;
    ast_Initializer_initFrame(this);

#ifdef CORTO_INIT_DEBUG
    {
        corto_id id, id2;
        printf("%*s%d[%s %p]: next(fp=%d, location=%d, type=%s, member=%s)\n",
               indent, " ", yparser()->line, ast_Parser_id(corto_typeof(this), id), this, this->fp,
               this->frames[this->fp].location,
               this->frames[this->fp].type?ast_Parser_id(this->frames[this->fp].type, id2):NULL,
               this->frames[this->fp].member?corto_idof(this->frames[this->fp].member):NULL);
    }

#endif
    return 0;
}

int8_t ast_Initializer_pop_v(
    ast_Initializer this)
{
    if (this->fp) {
        this->fp--;
#ifdef CORTO_INIT_DEBUG
    {
        corto_id id;
        indent--;
        printf("%*s%d[%s %p]: pop(fp=%d, location=%d)\n",
            indent, " ", yparser()->line,
            ast_Parser_id(corto_typeof(this), id), this, this->fp, this->frames[this->fp].location);
    }

#endif
        ast_Initializer_next(this);
    }

    return 0;
}

int16_t ast_Initializer_popKey_v(
    ast_Initializer this)
{
    return ast_Initializer_pop(this);
}

int16_t ast_Initializer_push_v(
    ast_Initializer this)
{
    corto_type t = ast_Initializer_currentType(this);

    if (!this->fp || (this->fp && !t->reference)) {
        this->fp++;
        this->frames[this->fp].location = 0;
        corto_set_ref(&this->frames[this->fp].type, t);
        ast_Initializer_initFrame(this);

#ifdef CORTO_INIT_DEBUG
        {
            corto_id id, id2;
            printf("%*s%d[%s %p]: push(fp=%d, location=%d, type=%s, member=%s)\n",
                   indent, " ", yparser()->line, ast_Parser_id(corto_typeof(this), id), this, this->fp,
                   this->frames[this->fp].location,
                   this->frames[this->fp].type ? ast_Parser_id(this->frames[this->fp].type, id2) : NULL,
                   this->frames[this->fp].member?corto_idof(this->frames[this->fp].member):NULL);
            indent++;
        }

#endif
    } else {
        corto_id id;
        ast_Parser_error(yparser(), "unexpected initializer scope for value of reference type '%s'", ast_Parser_id(t, id));
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t ast_Initializer_pushKey_v(
    ast_Initializer this)
{
    this->frames[this->fp+1].isKey = TRUE;
    return ast_Initializer_push(this);
}

corto_type ast_Initializer_type(
    ast_Initializer this)
{
    return ast_Expression_getType(this->variables[0].object);
}

int16_t ast_Initializer_value_v(
    ast_Initializer this,
    ast_Expression v)
{
    CORTO_UNUSED(v);
    return ast_Initializer_next(this);
}

int16_t ast_Initializer_valueKey_v(
    ast_Initializer this,
    ast_Expression key)
{
    this->frames[this->fp].isKey = TRUE;
    return ast_Initializer_value(this, key);
}
