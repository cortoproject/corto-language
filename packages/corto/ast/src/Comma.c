/* $CORTO_GENERATED
 *
 * Comma.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/ast/ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_Comma_addExpression(ast_Comma this, ast_Expression expr) {
/* $begin(corto/ast/Comma/addExpression) */
    if (expr) {
        corto_assert(this->expressions != NULL, "initialization failed");
        corto_llAppend(this->expressions, expr); corto_claim(expr);
        if (corto_llSize(this->expressions) == 1) {
            corto_setref(&ast_Expression(this)->type, expr->type);
        }
    }

    return 0;
/* $end */
}

ast_Expression _ast_Comma_addOrCreate(ast_Expression list, ast_Expression expr) {
/* $begin(corto/ast/Comma/addOrCreate) */
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
/* $end */
}

corto_int16 _ast_Comma_construct(ast_Comma this) {
/* $begin(corto/ast/Comma/construct) */
    if (this->expressions) {
        ast_Expression firstExpr = corto_llGet(this->expressions, 0);

        if (yparser()->line == 8) {
            if (firstExpr) {
                corto_setref(&ast_Expression(this)->type, firstExpr->type);
            }
        }
    }
    
    return 0;
/* $end */
}

corto_bool _ast_Comma_hasReturnedResource_v(ast_Comma this) {
/* $begin(corto/ast/Comma/hasReturnedResource) */
    corto_bool result = FALSE;

    ast_ExpressionListForeach(this->expressions, elem) {
        if (ast_Expression_hasReturnedResource(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
/* $end */
}

corto_bool _ast_Comma_hasSideEffects_v(ast_Comma this) {
/* $begin(corto/ast/Comma/hasSideEffects) */
    corto_bool result = FALSE;
    
    ast_ExpressionListForeach(this->expressions, elem) {
        if (ast_Expression_hasSideEffects(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
/* $end */
}

corto_int16 _ast_Comma_init(ast_Comma this) {
/* $begin(corto/ast/Comma/init) */

    ast_Node(this)->kind = Ast_CommaExpr;
    ast_Expression(this)->type = NULL;

    return ast_Node_init(ast_Node(this));
/* $end */
}

ast_Expression _ast_Comma_insertOrCreate(ast_Expression list, ast_Expression expr) {
/* $begin(corto/ast/Comma/insertOrCreate) */
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
/* $end */
}

ic_node _ast_Comma_toIc_v(ast_Comma this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(corto/ast/Comma/toIc) */

    ast_ExpressionListForeach(this->expressions, expr) {
        ast_Node_toIc(expr, program, storage, stored);
    }

    return NULL;
/* $end */
}

ast_NodeList _ast_Comma_toList(ast_Comma this) {
/* $begin(corto/ast/Comma/toList) */

    ast_NodeList result = corto_llNew();
    ast_ExpressionListForeach(this->expressions, expr) {
        corto_llAppend(result, expr); corto_claim(expr);
    }

    return result;
/* $end */
}
