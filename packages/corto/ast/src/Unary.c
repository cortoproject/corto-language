/* $CORTO_GENERATED
 *
 * Unary.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ast/ast.h>

/* $header() */
#include "ast__private.h"

corto_int16 ast_Unary_doConstruct(ast_Unary this) {
    corto_type lvalueType;

    lvalueType = ast_Expression_getType(this->lvalue);

    if (lvalueType->kind != CORTO_ITERATOR) {
        if (this->_operator == CORTO_COND_NOT) {
            corto_setref(&ast_Expression(this)->type, corto_bool_o);
        } else {
            corto_setref(&ast_Expression(this)->type, lvalueType);
        }
    } else {
        if (this->_operator == CORTO_MUL) {
            corto_type iterType = corto_iterator(lvalueType)->elementType;
            corto_setref(&ast_Expression(this)->type, iterType);
            ast_Expression(this)->isReference = TRUE;
        } else {
            ast_Parser_error(yparser(), "invalid operator for iterator");
            goto error;
        }
    }

    return 0;
error:
    return -1;    
} 
/* $end */

int16_t _ast_Unary_construct(
    ast_Unary this)
{
/* $begin(corto/ast/Unary/construct) */
    ast_Node(this)->kind = Ast_UnaryExpr;

    if (this->lvalue->unresolved) {
        ast_Expression(this)->unresolved = TRUE;
    } else {
        if (ast_Unary_doConstruct(this)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

ast_Expression _ast_Unary_fold(
    ast_Unary this)
{
/* $begin(corto/ast/Unary/fold) */
    ast_Expression result = ast_Expression(this);
    corto_type type = ast_Expression_getType(this);

    void *resultPtr, *ptr = (void*)ast_Expression_getValue(this->lvalue);
    if (ptr) {
        if (type->kind == CORTO_PRIMITIVE) {
            if (this->_operator == CORTO_NOT) {
                result = ast_Expression(ast_BooleanCreate(FALSE));
            } else {
                switch(corto_primitive(type)->kind) {
                case CORTO_BOOLEAN: result = ast_Expression(ast_BooleanCreate(FALSE)); break;
                case CORTO_CHARACTER: result = ast_Expression(ast_CharacterCreate('a')); break;
                case CORTO_BITMASK:
                case CORTO_UINTEGER: result = ast_Expression(ast_IntegerCreate(0)); break;
                case CORTO_ENUM:
                case CORTO_INTEGER: result = ast_Expression(ast_SignedIntegerCreate(0)); break;
                case CORTO_FLOAT: result = ast_Expression(ast_FloatingPointCreate(0)); break;
                case CORTO_TEXT: result = ast_Expression(ast_StringCreate(NULL)); break;
                default:
                    ast_Parser_error(yparser(), "Invalid primitive for folding expression");
                    goto error;
                    break;
                }
                if ((corto_primitive(type)->kind == CORTO_BITMASK) || (corto_primitive(type)->kind == CORTO_ENUM)) {
                    corto_setref(&ast_Expression(result)->type, type);
                }
            }

            /* Collect new expression */
            ast_Parser_collect(yparser(), result);

            /* Obtain pointer to value-field */
            resultPtr = (void*)ast_Literal_getValue(ast_Literal(result));

            if (corto_unaryOperator(type, this->_operator, ptr, resultPtr)) {
                ast_Parser_error(yparser(), "operator failed: %s", corto_lasterr());
                goto error;
            }
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

bool _ast_Unary_hasReturnedResource(
    ast_Unary this)
{
/* $begin(corto/ast/Unary/hasReturnedResource) */
    return ast_Expression_hasReturnedResource(this->lvalue);
/* $end */
}

bool _ast_Unary_hasSideEffects(
    ast_Unary this)
{
/* $begin(corto/ast/Unary/hasSideEffects) */
    return ast_Expression_hasSideEffects(this->lvalue);
/* $end */
}

ast_Expression _ast_Unary_resolve(
    ast_Unary this,
    corto_type type)
{
/* $begin(corto/ast/Unary/resolve) */

    if (ast_Expression(this)->unresolved) {
        ast_Expression lvalue = ast_Expression_resolve(this->lvalue, type);
        if (!lvalue) {
            goto error;
        }

        corto_setref(&this->lvalue, lvalue);
        ast_Expression(this)->unresolved = FALSE;

        if (ast_Unary_doConstruct(this)) {
            goto error;
        }
    }

    return ast_Expression(this);
error:
    return NULL;
/* $end */
}

ic_node _ast_Unary_toIc(
    ast_Unary this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
/* $begin(corto/ast/Unary/toIc) */
    ic_storage result;
    ic_node lvalue;
    CORTO_UNUSED(stored);

    if (storage) {
        result = storage;
    } else {
        result = (ic_storage)ic_program_pushAccumulator(
            program,  
            ast_Expression_getType(ast_Expression(this)),
            ast_Expression(this)->isReference,
            FALSE);
    }

    lvalue = ast_Node_toIc(ast_Node(this->lvalue), program, result, TRUE);

    switch(this->_operator) {
    case CORTO_INC:
    case CORTO_DEC:
        IC_1(program, ast_Node(this)->line, ic_opKindFromOperator(this->_operator), lvalue, IC_DEREF_VALUE);
        result = ic_storage(lvalue);
        break;
    case CORTO_MUL: {
        /* Create an element with the iterator as base */
        result = (ic_storage)ic_elementCreate(ic_storage(lvalue), NULL);
        break;
    }
    default:
        IC_3(program, ast_Node(this)->line, ic_opKindFromOperator(this->_operator), result, lvalue, NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
        break;
    }

    if (!storage) {
        ic_program_popAccumulator(program);
    }

    return (ic_node)result;
/* $end */
}
