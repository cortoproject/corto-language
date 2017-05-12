/* $CORTO_GENERATED
 *
 * Expression.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ast/ast.h>

/* $header() */
#include "ast__private.h"

/* Rate types based on expressibility */
corto_int8 ast_Expression_getTypeScore(corto_primitive t) {
    corto_int8 result = 0;
    switch(t->kind) {
    case CORTO_ENUM:
    case CORTO_BITMASK:
        result = 1;
        break;
    case CORTO_BOOLEAN:
    case CORTO_BINARY:
    case CORTO_INTEGER:
    case CORTO_UINTEGER:
        result = 2;
        break;
    case CORTO_CHARACTER:
        result = 3;
        break;
    case CORTO_FLOAT:
        result = 4;
        break;
    case CORTO_TEXT:
        result = 5;
        break;
    }
    return result;
}

/* Categorize types on castability - if equal no cast is required when width is equal */
corto_int8 ast_Expression_getCastScore(corto_primitive t) {
    corto_int8 result = 0;
    switch(t->kind) {
        case CORTO_ENUM:
        case CORTO_BITMASK:
            result = 1;
            break;
        case CORTO_BOOLEAN:
        case CORTO_BINARY:
        case CORTO_INTEGER:
        case CORTO_UINTEGER:
        case CORTO_CHARACTER:
            result = 2;
            break;
        case CORTO_FLOAT:
            result = 3;
            break;
        case CORTO_TEXT:
            result = 4;
            break;
    }
    return result;
}

/* Obtain inttype from value */
corto_type ast_Expression_getIntTypeFromValue(corto_int64 v, corto_primitive t) {
    corto_type result = NULL;

    if (v < 0) {
        if(t->kind == CORTO_UINTEGER) {
            /* Overflow */
            if (((corto_uint64)v) <= 4294967295) {
                result = corto_type(corto_uint32_o);
            } else {
                result = corto_type(corto_uint64_o);
            }
        } else if (v >= -128) {
            result = corto_type(corto_int8_o);
        } else if (v >= -32768) {
            result = corto_type(corto_int16_o);
        } else if (v >= -2147483648) {
            result = corto_type(corto_int32_o);
        } else {
            result = corto_type(corto_int64_o);
        }
    } else {
        if (v <= 255) {
            result = corto_type(corto_uint8_o);
        } else if (v <= 65535) {
            result = corto_type(corto_uint16_o);
        } else {
            result = corto_type(corto_uint32_o);
        }
    }

    return result;
}

corto_type ast_Expression_narrowType(ast_Expression expr) {
    corto_int64 v;
    corto_type t = ast_Expression_getType(expr);
    if (ast_Node(expr)->kind == Ast_LiteralExpr) {
        if (t && (t->kind == CORTO_PRIMITIVE)) {
            switch(corto_primitive(t)->kind) {
            case CORTO_INTEGER:
            case CORTO_UINTEGER:
                ast_Expression_serialize(expr, corto_type(corto_int64_o), (corto_word)&v);
                t = ast_Expression_getIntTypeFromValue(v, corto_primitive(t));
                break;
            default:
                break;
            }
        }
    }

    return t;
}

/* Reduce integer literals to smallest possible dimensions */
ast_Expression ast_Expression_narrow(ast_Expression expr) {

    if (ast_Node(expr)->kind == Ast_LiteralExpr) {
        corto_ptr_setref(&expr->type, ast_Expression_narrowType(expr));
    }

    return expr;
}

ast_Expression ast_Expression_literalFromType(corto_type type, corto_type exprType, void *value) {
    ast_Expression result = NULL;

    if (type->kind != CORTO_PRIMITIVE) {
        corto_seterr("cannot create literal from non-primitive type '%s'",
            corto_fullpath(NULL, type));
        goto error;
    }

    /* Create literal expressions based on destination type */
    switch(corto_primitive(type)->kind) {
    case CORTO_BOOLEAN: {
        corto_bool dstValue = FALSE;
        corto_ptr_cast(corto_primitive(exprType), value, corto_primitive(corto_bool_o), &dstValue);
        result = ast_Expression(ast_BooleanCreate(dstValue));
        break;
    }
    case CORTO_CHARACTER: {
        corto_char dstValue;
        corto_ptr_cast(corto_primitive(exprType), value, corto_primitive(corto_char_o), &dstValue);
        result = ast_Expression(ast_CharacterCreate(dstValue));
        break;
    }
    case CORTO_BINARY:
    case CORTO_UINTEGER: {
        corto_uint64 dstValue;
        corto_ptr_cast(corto_primitive(exprType), value, corto_primitive(corto_uint64_o), &dstValue);
        result = ast_Expression(ast_IntegerCreate(dstValue));
        break;
    }
    case CORTO_INTEGER: {
        corto_int64 dstValue;
        corto_ptr_cast(corto_primitive(exprType), value, corto_primitive(corto_int64_o), &dstValue);
        result = ast_Expression(ast_SignedIntegerCreate(dstValue));
        break;
    }
    case CORTO_FLOAT: {
        corto_float64 dstValue;
        corto_ptr_cast(corto_primitive(exprType), value, type, &dstValue);
        result = ast_Expression(ast_FloatingPointCreate(dstValue));
        break;
    }
    case CORTO_TEXT: {
        corto_string dstValue;
        corto_ptr_cast(corto_primitive(exprType), value, corto_primitive(corto_string_o), &dstValue);
        result = ast_Expression(ast_StringCreate(dstValue));
        break;
    }
    case CORTO_ENUM:
    case CORTO_BITMASK: {
        corto_int32 dstValue;
        corto_ptr_cast(corto_primitive(exprType), value, corto_primitive(corto_int32_o), &dstValue);
        result = ast_Expression(ast_SignedIntegerCreate(dstValue));
        break;
    }
    }

    return result;
error:
    return NULL;
}

/* $end */

ast_Expression _ast_Expression_cast(
    ast_Expression this,
    corto_type type,
    bool isReference)
{
/* $begin(corto/ast/Expression/cast) */
    corto_type exprType, refType;
    ast_Expression result = NULL;
    corto_bool castRequired = TRUE;

    corto_assert(type != NULL, "cannot cast to unknown type NULL");

    /* When object is unresolved reference, it may be possible to resolve it now
     * with additional information about the target type */
    this = ast_Expression_resolve(this, type);
    if (ast_Expression_getType(this) == type) {
        return this;
    }

    exprType = ast_Expression_getType(this);
    if((this->deref == Ast_ByReference) && !isReference && !exprType->reference) {
        refType = corto_object_o;
    } else {
        refType = exprType;
    }

    /* If types are different, cast */
    if (refType != type) {
        if (!exprType) {
            /* If expression is an untyped initializer, create an anonymous variable of the destination type
             * and assign it to the initializer. */
            if(ast_Node(this)->kind == Ast_InitializerExpr) {
                ast_Expression local = ast_Expression(ast_TemporaryCreate(type, FALSE));
                ast_InitializerExpression_insert(ast_InitializerExpression(this), local);
                result = local;
                castRequired = TRUE;
            }else {
                castRequired = FALSE;
            }
        } else if (corto_type_castable(type, refType)) {
            void *value = NULL;

            /* If expression is a literal or constant create new literal of right type */
            value = (void*)ast_Expression_getValue(this);
            if (value) {
                if (type->reference && (ast_Node(this)->kind == Ast_LiteralExpr)) {
                    /* If destination type is a reference and the literal is a string this results
                     * in a resolve at run-time. */
                    switch(ast_Literal(this)->kind) {
                    case Ast_Text:
                        break;
                    case Ast_Nothing:
                        /* No cast required */
                        break;
                    default: {
                        corto_id id1, id2;
                        /* Invalid cast */
                        ast_Parser_error(yparser(), "cannot cast from '%s' to '%s'", ast_Parser_id(exprType, id1), ast_Parser_id(type, id2));
                        break;
                    }
                    }
                }

                /* Create literal expressions based on destination type */
                result = ast_Expression_literalFromType(type, exprType, value);

                if (result){
                    corto_ptr_setref(&ast_Expression(result)->type, type);
                }
            } else {
                /* TODO: This functionality must be pushed down to the assembler. For all this function is concerned a cast
                 should only be required when a type is a) castable and b) not compatible. */

                /* If both types are primitive make sure that no cast is inserted for primitives
                 * of the same kind or 'score' to the same width */
                if ((refType->kind == CORTO_PRIMITIVE) &&
                   (type->kind == CORTO_PRIMITIVE) &&
                   (ast_Expression_getCastScore(corto_primitive(refType)) ==
                    ast_Expression_getCastScore(corto_primitive(type)))) {
                    if (corto_primitive(exprType)->width != corto_primitive(type)->width) {
                        result = ast_Expression(ast_CastCreate(type, this, isReference));
                    } else {
                        /* Types have the same width, so no cast required */
                        castRequired = FALSE;
                    }

                /* Interface-downcasting doesn't require an explicit cast */
                } else if (corto_instanceof(corto_type(corto_interface_o), type)) {
                    castRequired = FALSE;

                /* If collections are castable, they must be equivalent */
                } else if (type->kind == CORTO_COLLECTION) {
                    castRequired = FALSE;

                /* For all other cases, insert cast */
                } else {
                    result = ast_Expression(ast_CastCreate(type, this, isReference));
                }
            }
        /* If object is a reference and targetType is string, insert toString operation */
        } else /*if (this->isReference || ast_Expression_getType(this)->reference)*/ {
            if ((type->kind == CORTO_PRIMITIVE) && (corto_primitive(type)->kind == CORTO_TEXT)) {

                /* Create call-expression */
                result = ast_Expression(ast_createCallWithArguments(this, "toString", NULL));
                if (!result) {
                    goto error;
                }
                corto_claim(result);

            /* If type is of a generic reference type, accept any reference without cast */
            } else if (type->kind == CORTO_VOID && type->reference) {
                castRequired = FALSE;

            /* If assigning to a generic reference, insert cast */
            } else if (exprType->kind == CORTO_VOID && (exprType->reference || isReference)) {
                result = ast_Expression(ast_CastCreate(type, this, isReference));
            }
        }
    } else {
        castRequired = FALSE;
    }

    if (result && castRequired) {
        ast_Parser_collect(yparser(), result);
    } else {
        if (castRequired) {
            corto_id id1, id2;
                ast_Parser_error(yparser(), "no conversion from '%s' to '%s'",
                        ast_Parser_id(exprType, id1),
                        ast_Parser_id(type, id2));
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

void _ast_Expression_cleanList(
    ast_ExpressionList list)
{
/* $begin(corto/ast/Expression/cleanList) */
    if (list) {
        corto_iter iter = corto_ll_iter(list);
        while(corto_iter_hasNext(&iter)) {
            corto_release(corto_iter_next(&iter));
        }
        corto_ll_free(list);
    }
/* $end */
}

ast_Expression _ast_Expression_fold_v(
    ast_Expression this)
{
/* $begin(corto/ast/Expression/fold) */
    CORTO_UNUSED(this);
    return this;
/* $end */
}

ast_Expression _ast_Expression_fromList(
    ast_ExpressionList list)
{
/* $begin(corto/ast/Expression/fromList) */
    ast_Expression result = NULL;

    /* Convert list to comma expression */
    if (list) {
        if (corto_ll_size(list) == 1) {
            result = corto_ll_get(list, 0);
        } else {
            corto_ll toList = corto_ll_new(); /* Copy list */
            corto_iter iter;
            ast_Expression expr;

            result = ast_Expression(ast_CommaCreate());

            iter = corto_ll_iter(list);
            while(corto_iter_hasNext(&iter)) {
                expr = corto_iter_next(&iter);
                ast_ExpressionListAppend(toList, expr);
            }
            ast_Comma(result)->expressions = toList;
            ast_Parser_collect(yparser(), result);
        }
    }

    return result;
/* $end */
}

corto_type _ast_Expression_getType(
    ast_Expression this)
{
/* $begin(corto/ast/Expression/getType) */
    return this->type;
/* $end */
}

/* $header(corto/ast/Expression/getType_expr) */
corto_type ast_Expression_getType_intern(ast_Expression this, corto_type target, ast_Expression targetExpr) {
    corto_type result = ast_Expression_getType(this);

    if (!result) {
        if ((ast_Node(this)->kind == Ast_LiteralExpr) && (ast_Literal(this)->kind == Ast_Nothing)) {
            if (target) {
                if (target->reference) {
                    result = target;
                } else if ((target->kind == CORTO_PRIMITIVE) && (corto_primitive(target)->kind == CORTO_TEXT)) {
                    result = corto_type(corto_string_o);
                } else {
                    if (targetExpr && targetExpr->isReference) {
                        result = target;
                    } else {
                        goto error;
                    }
                }
            } else {
                goto error;
            }
        } else if (ast_Node(this)->kind == Ast_InitializerExpr) {
            result = target;
        } else {
            goto error;
        }
    } else if ((target && (target->kind == CORTO_VOID) && target->reference)) {
        result = corto_object_o;
    }

    return result;
error:
    ast_Parser_error(yparser(), "inconsistent usage of references");
    return NULL;
}
/* $end */
corto_type _ast_Expression_getType_expr(
    ast_Expression this,
    ast_Expression target)
{
/* $begin(corto/ast/Expression/getType_expr) */
    corto_type type,result;

    result = ast_Expression_getType(this);
    type = ast_Expression_getType(target);

    if (!result) {
        if (type) {
            result = ast_Expression_getType_intern(this, type, target);
        } else {
            result = corto_void_o;
        }
    } else {
        result = ast_Expression_getType_intern(this, type, target);
    }

    return result;
/* $end */
}

corto_type _ast_Expression_getType_type(
    ast_Expression this,
    corto_type target)
{
/* $begin(corto/ast/Expression/getType_type) */
    return ast_Expression_getType_intern(this, target, NULL);
/* $end */
}

uintptr_t _ast_Expression_getValue_v(
    ast_Expression this)
{
/* $begin(corto/ast/Expression/getValue) */
    CORTO_UNUSED(this);
    return 0;
/* $end */
}

bool _ast_Expression_hasReturnedResource_v(
    ast_Expression this)
{
/* $begin(corto/ast/Expression/hasReturnedResource) */
    CORTO_UNUSED(this);
    return FALSE;
/* $end */
}

bool _ast_Expression_hasSideEffects_v(
    ast_Expression this)
{
/* $begin(corto/ast/Expression/hasSideEffects) */
    CORTO_UNUSED(this);
    return FALSE;
/* $end */
}

corto_string _ast_Expression_id_v(
    ast_Expression this)
{
/* $begin(corto/ast/Expression/id) */
    CORTO_UNUSED(this);
    return NULL;
/* $end */
}

ast_Expression _ast_Expression_resolve_v(
    ast_Expression this,
    corto_type type)
{
/* $begin(corto/ast/Expression/resolve) */
    CORTO_UNUSED(type);
    return this;
/* $end */
}

int16_t _ast_Expression_serialize_v(
    ast_Expression this,
    corto_type dstType,
    uintptr_t dst)
{
/* $begin(corto/ast/Expression/serialize) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(dstType);
    CORTO_UNUSED(dst);
    corto_assert(0, "call to pure virtual function ast::Expression::serialize");
    return 0;
/* $end */
}

ast_ExpressionList _ast_Expression_toList_v(
    ast_Expression this)
{
/* $begin(corto/ast/Expression/toList) */
    ast_NodeList result = NULL;

    if (this) {
        result = corto_ll_new();
        ast_ExpressionListInsert(result, this);
    }

    return result;
/* $end */
}
