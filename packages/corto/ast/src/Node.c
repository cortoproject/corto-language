/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

/* Optimize condition, check if condition can be evaluated at compile-time or can be unwinded */
ast_Expression ast_Node_optimizeCondition(ast_Expression condition, corto_bool *staticResult, corto_bool *inverse) {
    ast_Expression result = NULL;
    ast_ExpressionList conditions = ast_Expression_toList(condition);
    *inverse = FALSE;
    
    /* If condition is an expression list, inserts && between each expression. */
    corto_iter it = corto_ll_iter(conditions);
    while (corto_iter_hasNext(&it)) {
        ast_Expression elem = corto_iter_next(&it);

        /* If condition is a unary NOT inverse the condition and evaluate lvalue of NOT expression instead */
        if (ast_Node(elem)->kind == Ast_UnaryExpr) {
            if (ast_Unary(elem)->_operator == CORTO_COND_NOT) {
                *inverse = TRUE;
                elem = ast_Unary(elem)->lvalue;
            }
        }
      
        /* If condition is a literal, serialize it to a boolean and resolve condition at compile-time */
        if (elem && (ast_Node(elem)->kind == Ast_LiteralExpr)) {
            if (ast_Expression_serialize(elem, corto_type(corto_bool_o), (corto_word)staticResult)) {
                ast_Parser_error(yparser(), "failed to serialize literal condition expression");
                goto error;
            }
            if (*inverse) {
                *staticResult = !*staticResult;
            }
            elem = NULL;
        }
    
        if (!result) {
            result = elem;
        } else {
            /* If element, add element to AND expression */
            if (elem) {
                result = ast_Expression(ast_BinaryCreate(result, elem, CORTO_COND_AND));
                ast_Parser_collect(yparser(), result);
                
            /* If element was a literal either ignore it (if result was TRUE) or discard all other
             * expressions if result of literal expression was FALSE. */
            } else if (!*staticResult) {
                result = NULL;
                break;
            }
        }
    }

    ast_Expression_cleanList(conditions);
    
    return result;
error:
    return NULL;
}


int16_t ast_Node_init(
    ast_Node this)
{
    this->line = yparser()->line;
    this->column = yparser()->column;
    return 0;
}

ic_node ast_Node_toIc_v(
    ast_Node this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    /* No code is generated for statement */
    return NULL;
}

