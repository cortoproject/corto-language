
#include "ast__private.h"

void ast_OptimizeExpr_printExpression(ast_Expression expr) {
    if (ast_Node(expr)->kind == Ast_BinaryExpr) {
        printf("(");
        ast_OptimizeExpr_printExpression(ast_Binary(expr)->lvalue);
        printf(" %s ", corto_strp(&ast_Binary(expr)->_operator, corto_operatorKind_o, 0));
        ast_OptimizeExpr_printExpression(ast_Binary(expr)->rvalue);
        printf(")");
    } else {
        if (ast_Node(expr)->kind == Ast_LiteralExpr) {
            corto_word value = ast_Expression_getValue(expr);
            printf("%s", corto_strp((void*)value, expr->type, 0));
        } else if (ast_Node(expr)->kind == Ast_StorageExpr) {
            if (ast_Storage(expr)->kind == Ast_LocalStorage) {
                printf("%s", ast_Local(expr)->name);
            }
        } else {
            printf("???\n");
        }
    }
}

ast_Expression ast_OptimizeExpr_multiplyBinary(ast_Binary b, ast_Expression e, corto_operatorKind oper, corto_bool invert) {
    ast_Expression left = ast_Binary(b)->lvalue;
    ast_Expression right = ast_Binary(b)->rvalue;
    ast_Expression newLeft = NULL, newRight = NULL;

    /* Don't do divisions right now, like "(x + 2) / (x + 4)" */

    if ((oper == CORTO_MUL) && ((b->_operator == CORTO_ADD) || (b->_operator == CORTO_SUB))) {
        newLeft = (ast_Expression)ast_BinaryCreate(invert ? e : left, invert ? left : e, oper);
        newRight = (ast_Expression)ast_BinaryCreate(invert ? e : right, invert ? right : e, oper);
    } else if ((b->_operator == CORTO_MUL) || (b->_operator == CORTO_DIV)) {
        if (left == e) {
            newLeft = (ast_Expression)ast_BinaryCreate(invert ? e : left, invert ? left : e, oper);
            newRight = right;
        } else if (right == e) {
            newRight = (ast_Expression)ast_BinaryCreate(invert ? e : right, invert ? e : right, oper);
            newLeft = left;
        } else if (ast_Node(e)->kind == Ast_BinaryExpr) {
            if ((ast_Binary(e)->_operator == CORTO_ADD) || (ast_Binary(e)->_operator == CORTO_SUB)) {
                return ast_OptimizeExpr_multiplyBinary(ast_Binary(e), ast_Expression(b), oper, !invert);
            }
        }
    }

    if (newLeft && newRight) {
        newLeft = ast_Expression_fold(newLeft);
        newRight = ast_Expression_fold(newRight);
        return (ast_Expression)ast_BinaryCreate(newLeft, newRight, b->_operator);
    } else {
        return NULL;
    }
}

ast_Expression ast_OptimizeExpr_reorderExpression(ast_Expression expr) {
    ast_Expression result = NULL;

    if (ast_Node(expr)->kind == Ast_BinaryExpr) {
        ast_Expression left = ast_Binary(expr)->lvalue;
        ast_Expression right = ast_Binary(expr)->rvalue;
        corto_operatorKind oper = ast_Binary(expr)->_operator;

        left = ast_OptimizeExpr_reorderExpression(left);
        right = ast_OptimizeExpr_reorderExpression(right);

        /* Turning SUB into ADD makes processing easier when adding constants */
        if (oper == CORTO_SUB) {
            corto_int32 minusOneVar = -1;
            ast_Expression minusOne = ast_Expression_literalFromType(
                ast_Expression_getType(right),
                corto_type(corto_int32_o),
                &minusOneVar
            );
            right = ast_Expression(ast_BinaryCreate(
                right,
                minusOne,
                CORTO_MUL
            ));
            right = ast_Expression_fold(right);
            ast_Binary(expr)->_operator = oper = CORTO_ADD;
        }

        corto_setref(&ast_Binary(expr)->lvalue, left);
        corto_setref(&ast_Binary(expr)->rvalue, right);

        if ((oper == CORTO_MUL) || (oper == CORTO_DIV)) {
            if (ast_Node(left)->kind == Ast_BinaryExpr) {
                result = ast_OptimizeExpr_multiplyBinary(ast_Binary(left), right, oper, FALSE);
            } else if (ast_Node(right)->kind == Ast_BinaryExpr) {
                result = ast_OptimizeExpr_multiplyBinary(ast_Binary(right), left, oper, TRUE);
            }
        }
    }

    return result ? result : expr;
}


void ast_OptimizeExpr_valueFromExpr(ast_Expression e, corto_value *out) {
    *out = corto_value_value(
        (void*)ast_Expression_getValue(e),
        ast_Expression_getType(e));
}

corto_int32 ast_OptimizeExpr_operatorPrecedence(corto_operatorKind oper) {
    corto_int32 result = 0;
    switch(oper) {
    case CORTO_ADD:
    case CORTO_SUB:
        result = 1;
        break;
    case CORTO_MUL:
    case CORTO_DIV:
        result = 2;
        break;
    default: break;
    }
    return result;
}

corto_bool ast_OptimizeExpr_samePrecendence(ast_Binary e1, ast_Binary e2) {
    corto_int32 e = ast_OptimizeExpr_operatorPrecedence(e1->_operator);
    return e && (e == ast_OptimizeExpr_operatorPrecedence(e2->_operator));
}

typedef struct ast_OptimizeExpr_exprElem {
    corto_operatorKind oper;
    ast_Expression e;
} ast_OptimizeExpr_exprElem;

corto_bool ast_OptimizeExpr_isNoop(corto_operatorKind oper, ast_Expression e) {
    if (e && (ast_Node(e)->kind == Ast_LiteralExpr)) {
        corto_value isNoop = corto_value_bool(FALSE);
        corto_value eValue, v;
        ast_OptimizeExpr_valueFromExpr(e, &eValue);
        if ((oper == CORTO_ADD) || (oper == CORTO_SUB)) {
            v = corto_value_int(0);
        } else if ((oper == CORTO_MUL) || (oper == CORTO_DIV)) {
            v = corto_value_int(1);
        } else {
            return FALSE;
        }
        corto_value_binaryOp(CORTO_COND_EQ, &v, &eValue, &isNoop);
        return *(corto_bool*)corto_value_ptrof(&isNoop);
    }
    return e == NULL;
}

ast_OptimizeExpr_exprElem* ast_OptimizeExpr_elemNew(corto_operatorKind oper, ast_Expression e) {
    ast_OptimizeExpr_exprElem *elem = corto_alloc(sizeof(ast_OptimizeExpr_exprElem));
    elem->oper = oper;
    elem->e = e;
    return elem;
}
void ast_OptimizeExpr_elemsInsert(corto_ll elems, corto_operatorKind oper, ast_Expression e) {
    if (!ast_OptimizeExpr_isNoop(oper, e)) {
        corto_llInsert(elems, ast_OptimizeExpr_elemNew(oper, e));
    }
}
void ast_OptimizeExpr_elemsAppend(corto_ll elems, corto_operatorKind oper, ast_Expression e) {
    if (!ast_OptimizeExpr_isNoop(oper, e)) {
        corto_llAppend(elems, ast_OptimizeExpr_elemNew(oper, e));
    }
}

void ast_OptimizeExpr_elemsFree(corto_ll elems) {
    corto_iter it = corto_llIter(elems);
    while (corto_iterHasNext(&it)) {
        ast_OptimizeExpr_exprElem *elem = corto_iterNext(&it);
        corto_dealloc(elem);
    }
    corto_llFree(elems);
}

ast_Expression ast_OptimizeExpr_collectTerm(ast_Expression e, corto_value *constant, corto_ll elems) {
    ast_Expression result = NULL;

    if (ast_Node(e)->kind == Ast_BinaryExpr) {
        ast_Expression left = ast_Binary(e)->lvalue;
        ast_Expression right = ast_Binary(e)->rvalue;
        ast_nodeKind leftKind = ast_Node(left)->kind;
        ast_nodeKind rightKind = ast_Node(right)->kind;
        corto_operatorKind oper = ast_Binary(e)->_operator;

        if (leftKind == Ast_LiteralExpr) {
            ast_OptimizeExpr_valueFromExpr(left, constant);
        } else if ((leftKind == Ast_BinaryExpr) &&
            (ast_OptimizeExpr_samePrecendence(ast_Binary(e), ast_Binary(left))))
        {
            ast_OptimizeExpr_elemsInsert(
                elems,
                CORTO_ASSIGN,
                ast_OptimizeExpr_collectTerm(left, constant, elems));
        } else {
            result = left;
        }

        if (rightKind == Ast_LiteralExpr) {
            corto_value v;
            ast_OptimizeExpr_valueFromExpr(right, &v);
            corto_value_binaryOp(oper, constant, &v, constant);
        } else if ((rightKind == Ast_BinaryExpr) &&
            (ast_OptimizeExpr_samePrecendence(ast_Binary(e), ast_Binary(right))))
        {
            corto_value v = corto_value_int(0);
            if ((oper == CORTO_MUL) || (oper == CORTO_DIV)) {
                v = corto_value_int(1);
            }
            ast_OptimizeExpr_elemsAppend(
                elems,
                oper,
                ast_OptimizeExpr_collectTerm(right, constant, elems));
            corto_value_binaryOp(oper, constant, &v, constant);
        } else {
            ast_OptimizeExpr_elemsAppend(elems, oper, right);
        }
    }

    return result;
}

ast_Expression ast_OptimizeExpr_getTermExp(ast_Binary binary, ast_Expression var, corto_int32 *a) {
    ast_Expression left = ast_Binary(binary)->lvalue;
    ast_Expression right = ast_Binary(binary)->rvalue;
    corto_int32 addRight = binary->_operator == CORTO_MUL;

    if (ast_Node(left)->kind != Ast_BinaryExpr) {
        if (!var) {
            var = left;
            (*a)++;
        } else if (left == var) {
            (*a)++;
        } else {
            var = ast_Expression(binary);
            *a = 1;
        }
    } else {
        var = ast_OptimizeExpr_getTermExp(ast_Binary(left), var, a);
    }

    if (ast_Node(right)->kind != Ast_BinaryExpr) {
        if (!var) {
            var = right;
            *a = addRight ? *a + 1 : *a - 1;
        } else if (right == var) {
            *a = addRight ? *a + 1 : *a - 1;
        } else {
            var = ast_Expression(binary);
            *a = 1;
        }
    } else {
        corto_int32 aTemp = 0;
        var = ast_OptimizeExpr_getTermExp(ast_Binary(right), var, &aTemp);
        *a = addRight ? *a + aTemp : *a - aTemp;
    }

    return var;
}

ast_Expression ast_OptimizeExpr_getTermWithBinary(
    ast_Binary result,
    ast_Binary binary,
    ast_Expression e,
    corto_int32 *a,
    ast_Expression *b,
    ast_Expression *v)
{
    if (ast_Node(e)->kind == Ast_LiteralExpr) {
        /* Count exponent in binary expression for 'e' */
        *v = ast_OptimizeExpr_getTermExp(binary, NULL, a);
        result = binary;
        *b = e;
    } else {
        /* Find term & count exponent in result */
        *v = ast_OptimizeExpr_getTermExp(result, e, a);
        *b = NULL;
    }

    return ast_Expression(result);
}

ast_Expression ast_OptimizeExpr_getTerm(
    ast_Expression e,
    corto_int32 *a,
    ast_Expression *b,
    ast_Expression *v)
{
    ast_Expression result = e;

    *a = 0;
    *b = NULL;
    *v = NULL;

    if (ast_Node(result)->kind == Ast_BinaryExpr) {
        ast_Expression left = ast_Binary(result)->lvalue;
        ast_Expression right = ast_Binary(result)->rvalue;
        if (left == right) {
            result = left;
            *a = 2;
            *b = NULL;
        } else if (ast_Node(left)->kind == Ast_BinaryExpr) {
            result = ast_OptimizeExpr_getTermWithBinary(ast_Binary(result), ast_Binary(left), right, a, b, v);
        }  else if (ast_Node(right)->kind == Ast_BinaryExpr) {
            result = ast_OptimizeExpr_getTermWithBinary(ast_Binary(result), ast_Binary(right), left, a, b, v);
        } else if ((ast_Node(left)->kind != Ast_LiteralExpr) && (ast_Node(right)->kind == Ast_LiteralExpr)) {
            result = left;
            *v = left;
            *a = 1;
            *b = right;
        } else if ((ast_Node(right)->kind != Ast_LiteralExpr) && (ast_Node(left)->kind == Ast_LiteralExpr)) {
            result = right;
            *v = right;
            *a = 1;
            *b = left;
        }
    } else {
        *a = 1;
        *v = result;
    }

    return result;
}

ast_Expression ast_OptimizeExpr_combine(
    ast_Expression out,
    ast_Expression outLiteral,
    ast_Expression eLiteral,
    corto_operatorKind oper)
{
    ast_Expression result = out;

    /*printf("combine: %s\n out=%s\n outLiteral=%s\n eLiteral=%s\n",
        corto_strp(&oper, corto_operatorKind_o, 0),
        out ? corto_contentof(NULL, "text/corto-color", out) : "-",
        outLiteral ? corto_contentof(NULL, "text/corto-color", outLiteral) : "-",
        eLiteral ? corto_contentof(NULL, "text/corto-color", eLiteral) : "-");*/

    corto_value outValue, eValue;
    if (outLiteral) {
        ast_OptimizeExpr_valueFromExpr(outLiteral, &outValue);
    } else {
        outValue = corto_value_int(1);
    }
    if (eLiteral) {
        ast_OptimizeExpr_valueFromExpr(eLiteral, &eValue);
    } else {
        eValue = corto_value_int(1);
    }

    corto_value_binaryOp(oper, &outValue, &eValue, &outValue);

    corto_value one = corto_value_int(1);
    corto_value equals = corto_value_bool(FALSE);
    corto_value_binaryOp(CORTO_COND_EQ, &one, &outValue, &equals);
    ast_Expression literal = NULL;

    if (!*(corto_bool*)corto_value_ptrof(&equals)) {
        literal = ast_Expression_literalFromType(
            ast_Expression_getType(out),
            corto_value_typeof(&outValue),
            corto_value_ptrof(&outValue)
        );
    }

    if (literal && ((oper == CORTO_ADD) || (oper == CORTO_SUB))) {
        result = ast_Expression(ast_BinaryCreate(
            out,
            literal,
            CORTO_MUL
        ));
    } else {
        result = ast_Expression(ast_BinaryCreate(
            out,
            out,
            oper
        ));
        if (literal) {
            result = ast_Expression(ast_BinaryCreate(
                result,
                literal,
                oper
            ));
        }
    }

    /* Filter out redundant operations */
    if (ast_Node(result)->kind == Ast_BinaryExpr) {
        if (ast_Binary(result)->_operator == CORTO_DIV) {
            if (ast_Binary(result)->lvalue == ast_Binary(result)->rvalue) {
                corto_release(result);
                result = ast_Expression(ast_IntegerCreate(1));
            }
        }
    }

    return result;
}

ast_Expression ast_OptimizeExpr_reducedToExpression(corto_ll elems) {
    ast_Expression result = NULL;

    corto_iter it = corto_llIter(elems);
    while (corto_iterHasNext(&it)) {
        ast_OptimizeExpr_exprElem *elem = corto_iterNext(&it);
        if (!result) {
            result = elem->e;
        } else {
            result = ast_Expression(ast_BinaryCreate(
                result, elem->e, elem->oper
            ));
        }
    }

    return result;
}

corto_bool ast_OptimizeExpr_isValueNull(corto_value *v) {
    corto_value b = corto_value_bool(FALSE);
    corto_value null = corto_value_int(0);
    corto_value_binaryOp(CORTO_COND_EQ, v, &null, &b);
    return *(corto_bool*)corto_value_ptrof(&b);
}

corto_ll ast_OptimizeExpr_reduceExpression(ast_Expression e) {
    corto_value constant = corto_value_int(0);
    corto_operatorKind constantOper = CORTO_ADD;
    corto_ll elems = corto_llNew();
    corto_ll final = corto_llNew();

    if (ast_Node(e)->kind == Ast_BinaryExpr) {
        if ((ast_Binary(e)->_operator == CORTO_MUL) ||
            (ast_Binary(e)->_operator == CORTO_DIV))
        {
            constant = corto_value_int(1);
            constantOper = CORTO_MUL;
        }
    }

    /* Recursively collect expressions with variables * constants */
    ast_OptimizeExpr_elemsInsert(
        elems,
        CORTO_ASSIGN,
        ast_OptimizeExpr_collectTerm(e, &constant, elems));

    if (ast_OptimizeExpr_isValueNull(&constant)) {
        constantOper = CORTO_ADD;
    }

    /* Reduce subexpressions */
    if (corto_llSize(elems) > 1) {
        corto_iter it = corto_llIter(elems);
        while (corto_iterHasNext(&it)) {
            ast_OptimizeExpr_exprElem *elem = corto_iterNext(&it);
            if (ast_Node(elem->e)->kind == Ast_BinaryExpr) {
                corto_ll subElems = ast_OptimizeExpr_reduceExpression(elem->e);
                elem->e = ast_OptimizeExpr_reducedToExpression(subElems);
                ast_OptimizeExpr_elemsFree(subElems);
            }
        }
    }

    /* Combine expressions with same variable */
    ast_OptimizeExpr_exprElem *elem;
    corto_int32 i = 0;
    corto_operatorKind firstOperator;
    while ((elem = corto_llTakeFirst(elems))) {
        corto_bool found = FALSE;
        corto_iter it = corto_llIter(final);

        /*printf("elem = %s\n", corto_contentof(NULL, "text/corto-color", elem->e));*/

        while (corto_iterHasNext(&it) && !found) {
            ast_OptimizeExpr_exprElem *finalElem = corto_iterNext(&it);
            corto_int32 a, aFinal;
            ast_Expression b, bFinal, var, varFinal, expr;
            expr = ast_OptimizeExpr_getTerm(elem->e, &a, &b, &var);
            ast_OptimizeExpr_getTerm(finalElem->e, &aFinal, &bFinal, &varFinal);

            /*printf("expr:\n expr=%s, a=%d, b=%s, var=%s\n",
                expr ? corto_contentof(NULL, "text/corto-color", expr) : "-",
                a,
                b ? corto_contentof(NULL, "text/corto-color", b) : "-",
                var ? corto_contentof(NULL, "text/corto-color", var) : "-");
            printf("final:\n expr=%s, a=%d, b=%s, var=%s\n",
                exprFinal ? corto_contentof(NULL, "text/corto-color", exprFinal) : "-",
                aFinal,
                bFinal ? corto_contentof(NULL, "text/corto-color", bFinal) : "-",
                varFinal ? corto_contentof(NULL, "text/corto-color", varFinal) : "-");*/

            if ((var == varFinal) && (a == aFinal)) {
                finalElem->e = ast_OptimizeExpr_combine(expr, bFinal, b, elem->oper);
                elem = finalElem;
                found = TRUE;
                /*printf("combined: [%p] %s\n", finalElem,
                    finalElem->e ? corto_contentof(NULL, "text/corto-color", finalElem->e) : "-");*/
            }
        }
        if (!found) {
            corto_llAppend(final, elem);
        }

        /* If the combined expression resulted in a literal, remove it
         * from the list and add it to the constant */
        if (ast_Node(elem->e)->kind == Ast_LiteralExpr) {
            corto_value v; ast_OptimizeExpr_valueFromExpr(elem->e, &v);
            corto_value_binaryOp(CORTO_ADD, &constant, &v, &constant);
            corto_llRemove(final, elem);
            corto_dealloc(elem);
        } else {
            if (!i) firstOperator = elem->oper;
            i++;
        }
    }

    /* Append/insert constant */
    ast_Expression constantExpr = ast_Expression_literalFromType(
        corto_value_typeof(&constant),
        corto_value_typeof(&constant),
        corto_value_ptrof(&constant)
    );
    if ((firstOperator == CORTO_DIV) || (firstOperator == CORTO_SUB)) {
        ast_OptimizeExpr_elemsInsert(final, firstOperator, constantExpr);
    } else {
        ast_OptimizeExpr_elemsAppend(final, constantOper, constantExpr);
    }

    return final;
}

void ast_OptimizeExpr_inverse(corto_ll elems) {
    corto_iter it = corto_llIter(elems);
    corto_bool prevIsLiteral = FALSE;
    while (corto_iterHasNext(&it)) {
        ast_OptimizeExpr_exprElem *elem = corto_iterNext(&it);
        if ((ast_Node(elem->e)->kind == Ast_LiteralExpr) || prevIsLiteral) {
            switch(elem->oper) {
            case CORTO_ADD: elem->oper = CORTO_SUB; break;
            case CORTO_SUB: elem->oper = CORTO_ADD; break;
            case CORTO_MUL: elem->oper = CORTO_DIV; break;
            case CORTO_DIV: elem->oper = CORTO_MUL; break;
            default: break;
            }
        }
        if (ast_Node(elem->e)->kind == Ast_BinaryExpr) {
            ast_Expression left = ast_Binary(elem->e)->lvalue;
            ast_Expression right = ast_Binary(elem->e)->rvalue;
            if ((ast_Node(left)->kind == Ast_LiteralExpr) ||
                (ast_Node(right)->kind == Ast_LiteralExpr))
            {
                switch(ast_Binary(elem->e)->_operator) {
                case CORTO_ADD: ast_Binary(elem->e)->_operator = CORTO_SUB; break;
                case CORTO_SUB: ast_Binary(elem->e)->_operator = CORTO_ADD; break;
                case CORTO_MUL: ast_Binary(elem->e)->_operator = CORTO_DIV; break;
                case CORTO_DIV: ast_Binary(elem->e)->_operator = CORTO_MUL; break;
                default: break;
                }
            }

        }
        prevIsLiteral = (ast_Node(elem->e)->kind == Ast_LiteralExpr);
    }
}
