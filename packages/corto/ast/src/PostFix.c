/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_PostFix_construct(
    ast_PostFix this)
{
    corto_type lvalueType = ast_Expression_getType(this->lvalue);

    /* Validate whether operation is allowed */
    if (lvalueType->reference) {
        corto_id id;
        ast_Parser_error(
            yparser(), "invalid operator for reference type '%s'", ast_Parser_id(lvalueType, id));
        goto error;
    } else {
        corto_id id;
        switch(lvalueType->kind) {

        case CORTO_PRIMITIVE:
            switch(corto_primitive(lvalueType)->kind) {
            case CORTO_INTEGER:
            case CORTO_UINTEGER:
            case CORTO_BINARY:
            case CORTO_CHARACTER:
            case CORTO_FLOAT:
                break;
            default:
                ast_Parser_error(
                    yparser(), "invalid operator for type '%s'", ast_Parser_id(lvalueType, id));
                goto error;
                break;       
            }
            corto_ptr_setref(&ast_Expression(this)->type, lvalueType);
            break;

        case CORTO_ITERATOR:
            if (this->_operator == CORTO_INC) {
                /* The result of an expression that increments an iterator is a boolean */
                corto_ptr_setref(&ast_Expression(this)->type, corto_bool_o);
            } else {
                ast_Parser_error(yparser(), "invalid operator for iterator");
                goto error;
            }
            break;

        default:
            ast_Parser_error(
                yparser(), "invalid operator for type '%s'", ast_Parser_id(lvalueType, id));
            goto error;
            break;
        }
    }

    ast_Node(this)->kind = Ast_PostfixExpr;
    
    return 0;
error:
    return -1;
}

bool ast_PostFix_hasReturnedResource(
    ast_PostFix this)
{
    return ast_Expression_hasReturnedResource(this->lvalue);
}

ic_node ast_PostFix_toIc(
    ast_PostFix this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    ic_storage result;
    ic_node lvalue;
    corto_type lvalueType = ast_Expression_getType(this->lvalue);
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
    IC_3(program, ast_Node(this)->line, ic_opKindFromOperator(this->_operator), lvalue, ic_node(result), NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);

    if (!storage) {
        ic_program_popAccumulator(program);
    } else if ((lvalueType->kind == CORTO_ITERATOR) && (this->_operator == CORTO_INC)) {
        lvalue = (ic_node)storage;
    }

    return (ic_node)lvalue;
}

