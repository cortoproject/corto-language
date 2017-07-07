/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Comma_addExpression(
    ast_Comma this,
    ast_Expression expr)
{
    if (expr) {
        corto_assert(this->expressions != NULL, "initialization failed");
        corto_ll_append(this->expressions, expr); corto_claim(expr);
        if (corto_ll_size(this->expressions) == 1) {
            corto_ptr_setref(&ast_Expression(this)->type, expr->type);
        }
    }

    return 0;
}

ast_Expression ast_Comma_addOrCreate(
    ast_Expression list,
    ast_Expression expr)
{
    ast_Expression result;
    
    if (!list) {
        result = expr;
    } else if (ast_Node(list)->kind == Ast_CommaExpr) {
        ast_Comma_addExpression(ast_Comma(list), expr);
        result = list;
    } else {
        result = ast_Expression(ast_CommaCreate());
        ast_Comma_addExpression(ast_Comma(result), list);
        ast_Comma_addExpression(ast_Comma(result), expr);
        ast_Parser_collect(yparser(), result);
    }
    
    return result;
}

int16_t ast_Comma_construct(
    ast_Comma this)
{
    if (this->expressions) {
        ast_Expression firstExpr = corto_ll_get(this->expressions, 0);

        if (yparser()->line == 8) {
            if (firstExpr) {
                corto_ptr_setref(&ast_Expression(this)->type, firstExpr->type);
            }
        }
    }
    
    return 0;
}

bool ast_Comma_hasReturnedResource(
    ast_Comma this)
{
    corto_bool result = FALSE;

    corto_iter it = corto_ll_iter(this->expressions);
    while (corto_iter_hasNext(&it)) {
        ast_Expression elem = corto_iter_next(&it);
        if (ast_Expression_hasReturnedResource(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
}

bool ast_Comma_hasSideEffects(
    ast_Comma this)
{
    corto_bool result = FALSE;
    
    corto_iter it = corto_ll_iter(this->expressions);
    while (corto_iter_hasNext(&it)) {
        ast_Expression elem = corto_iter_next(&it);
        if (ast_Expression_hasSideEffects(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
}

int16_t ast_Comma_init(
    ast_Comma this)
{

    ast_Node(this)->kind = Ast_CommaExpr;
    ast_Expression(this)->type = NULL;

    return ast_Node_init(ast_Node(this));
}

ast_Expression ast_Comma_insertOrCreate(
    ast_Expression list,
    ast_Expression expr)
{
    ast_Expression result;
    
    if (!list) {
        result = expr;
    } else if (ast_Node(list)->kind == Ast_CommaExpr) {
        ast_Comma_addExpression(ast_Comma(list), expr);
        result = list;
    } else {
        result = ast_Expression(ast_CommaCreate());
        ast_Comma_addExpression(ast_Comma(result), expr);
        ast_Comma_addExpression(ast_Comma(result), list);
        ast_Parser_collect(yparser(), result);
    }
    
    return result;
}

ic_node ast_Comma_toIc(
    ast_Comma this,
    ic_program program,
    ic_storage storage,
    bool stored)
{

    corto_iter it = corto_ll_iter(this->expressions);
    while (corto_iter_hasNext(&it)) {
        ast_Expression elem = corto_iter_next(&it);
        ast_Node_toIc(elem, program, storage, stored);
    }

    return NULL;
}

ast_ExpressionList ast_Comma_toList(
    ast_Comma this)
{

    ast_NodeList result = corto_ll_new();
    corto_iter it = corto_ll_iter(this->expressions);
    while (corto_iter_hasNext(&it)) {
        ast_Expression elem = corto_iter_next(&it);
        corto_ll_append(result, elem); corto_claim(elem);
    }

    return result;
}

