/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

static
int comparator(void *t, const void *ptr1, const void *ptr2) {
    return corto_ptr_compare(ptr1, t, ptr2);
}

corto_word ast_Initializer_offset(ast_StaticInitializer this, corto_uint32 variable) {
    corto_word result, base;
    corto_uint16 fp = ast_Initializer(this)->fp;
    ast_InitializerFrame *frame = &ast_Initializer(this)->frames[fp?fp-1:0];
    ast_StaticInitializerFrame *baseFrame = &(this->frames[fp?fp-1:0]);
    ast_InitializerFrame *thisFrame = &ast_Initializer(this)->frames[fp];
    result = 0;

    base = baseFrame->ptr[variable];
    if (!base) {
        ast_Parser_error(yparser(), "parser error: base is zero in offset calculation");
        goto error;
    }

    /* Switch on current type */
    switch(frame->type->kind) {
    case CORTO_PRIMITIVE:
        result = base;
        break;
    case CORTO_COMPOSITE:
        if (fp) {
            result = base + thisFrame->member->offset;
        } else {
            result = base;
        }
        break;
    case CORTO_ITERATOR:
        result = base;
        break;
    case CORTO_COLLECTION: {
        if (fp) {
            corto_collection t = corto_collection(frame->type);
            corto_type element_type = t->element_type;
            corto_uint32 elementSize = corto_type_sizeof(element_type);
            switch(t->kind) {
            case CORTO_SEQUENCE:
                ((corto_objectseq*)base)->length++;
                ((corto_objectseq*)base)->buffer = corto_realloc(((corto_objectseq*)base)->buffer, ((corto_objectseq*)base)->length * elementSize);
                base = (corto_word)((corto_objectseq*)base)->buffer;
            case CORTO_ARRAY:
                result = base + thisFrame->location * corto_type_sizeof(element_type);
                memset((void*)result, 0, elementSize);
                break;
            case CORTO_LIST: {
                if (corto_collection_requires_alloc(element_type)) {
                    result = (corto_word)corto_calloc(elementSize);
                }
                if (!*(corto_ll*)base) {
                    *(corto_ll*)base = corto_ll_new();
                }
                corto_ll_append(*(corto_ll*)base, (void*)result);
                if (!result) {
                    result = (corto_word)corto_ll_getPtr(*(corto_ll*)base, corto_ll_count(*(corto_ll*)base)-1);
                }
                break;
            }
            case CORTO_MAP: {
                corto_type key_type = corto_map(frame->type)->key_type;
                if (!thisFrame->isKey) {
                    if (corto_collection_requires_alloc(element_type)) {
                        result = (corto_word)corto_calloc(elementSize);
                    }
                    if (!*(corto_rb*)base) {
                        *(corto_rb*)base = corto_rb_new(comparator, frame->type);
                    }
                    corto_rb_set(*(corto_rb*)base, (void*)this->frames[fp].keyPtr[variable], (void*)result);
                    if (!result) {
                        if (this->frames[fp].keyPtr[variable]) {
                            result = (corto_word)corto_rb_findPtr(*(corto_rb*)base, (void*)this->frames[fp].keyPtr[variable]);
                        } else {
                            ast_Parser_error(yparser(), "cannot set element without keyvalue");
                            goto error;
                        }
                    }
                } else {
                    result = (corto_word)corto_calloc(corto_type_sizeof(key_type));
                    this->frames[fp].keyPtr[variable] = result;
                    thisFrame->isKey = FALSE;
                }
                break;
            }
            }
        } else {
            result = base;
        }
        break;
    }
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "invalid initializer type '%s'", ast_Parser_id(frame->type, id));
        break;
    }
    }

    return result;
error:
    return 0;
}

int16_t ast_StaticInitializer_construct(
    ast_StaticInitializer this)
{
    corto_int8 variable;

    /* Copy offsets of variables into frames */
    for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
         this->frames[0].ptr[variable] =
                (corto_word)ast_Object(ast_Initializer(this)->variables[variable].object)->value;
        if (!this->frames[0].ptr[variable]) {
            ast_Parser_error(yparser(), "non-static variable in static initializer");
            goto error;
        }
    }

    return ast_Initializer_construct(ast_Initializer(this));
error:
    return -1;
}

int16_t ast_StaticInitializer_defineObject(
    ast_StaticInitializer this)
{
    corto_uint32 variable;
    corto_object o;

    /* Types are defined during 1st pass. All other objects are defined when a program starts. Defining types
     * at compile-time is required to do validity checking while parsing. On the other hand, objects cannot be
     * defined at compile-time because class constructors\destructors are not yet defined at that point. This
     * would cause object creation\destruction without calling the appropriate constructors\destructors.
     */
    for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
        o = (corto_object)ast_Object(ast_Initializer(this)->variables[variable].object)->value;
        if (corto_instanceof(corto_type(corto_type_o), o)
                || (corto_check_attr(o, CORTO_ATTR_NAMED) && corto_instanceof(corto_type(corto_type_o), corto_parentof(o)))) {

            corto_type t = corto_typeof(o);
            if (!corto_check_attr(o, CORTO_ATTR_NAMED) ||
                (corto_parentof(o) && corto_check_state(corto_parentof(o), CORTO_VALID)) ||
                (t->parent_state != CORTO_VALID))
            {
                if (!corto(CORTO_DEFINE, {.object = o})) {
                    corto_id id1;
                    ast_Parser_error(yparser(), "failed to define '%s",
                            ast_Parser_id(o, id1));
                    goto error;
                }
            }
        } else {
            ast_Expression refVar = ast_Expression(ast_Object__create(NULL, NULL, o));
            refVar->isReference = TRUE; /* Always treat object as reference */
            ast_Define defineStmt = ast_Define__create(NULL, NULL, refVar);
            ast_Parser_addStatement(yparser(), ast_Node(defineStmt));
            ast_Parser_collect(yparser(), defineStmt);
            ast_Parser_collect(yparser(), refVar);
        }
    }

    ast_Initializer_defineObject_v(ast_Initializer(this));

    return 0;
error:
    return -1;
}

int16_t ast_StaticInitializer_push(
    ast_StaticInitializer this)
{
    corto_uint8 variable;

    /* Obtain offset for all that variables being initialized */
    for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
        /* Calculate the offset for the current value */
        this->frames[ast_Initializer(this)->fp].ptr[variable] = ast_Initializer_offset(this, variable);
    }

    return ast_Initializer_push_v(ast_Initializer(this));
}

int16_t ast_StaticInitializer_value(
    ast_StaticInitializer this,
    ast_Expression v)
{
    corto_word offset;
    corto_uint32 variable;
    corto_uint32 fp = ast_Initializer(this)->fp;
    corto_type type = ast_Initializer_currentType(ast_Initializer(this));

    /* With the type, it might be able to resolve an unresolve identifier */
    v = ast_Expression_resolve(v, type);
    if (!v) {
        goto error;
    }

    corto_type vType = ast_Expression_getType_type(v, type);

    if (!type) {
        corto_id id;
        ast_Parser_error(yparser(), "excess elements in initializer of type '%s'",
            ast_Parser_id(ast_Expression(this)->type, id));
        goto error;
    }

    if (!vType) {
        goto error;
    }

    /* Validate whether expression type matches current type of initializer */
    if (vType && !corto_type_castable(type, vType)) {
        corto_id id, id2;
        ast_Parser_error(yparser(), "type '%s' invalid here (expected '%s')",
            ast_Parser_id(vType, id), ast_Parser_id(type, id2));
        goto error;
    }

    /* Validate whether value has no side-effects - which are not allowed in a static initializer */
    if (ast_Expression_hasSideEffects(v)) {
        ast_Parser_error(yparser(), "expressions with side-effects are not allowed in static initializers.");
        goto error;
    }

    /* Serialize value to all variables being initialized */
    for(variable=0; variable<ast_Initializer(this)->variableCount; variable++) {
        /* Calculate the offset for the current value */
        this->frames[fp].ptr[variable] = ast_Initializer_offset(this, variable);
        offset = this->frames[fp].ptr[variable];

        if (!offset) {
            goto error;
        }

        if (ast_Expression_serialize(v, type, offset)) {
            goto error;
        }
    }

    return ast_Initializer_next(ast_Initializer(this));
error:
    return -1;
}
