/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_While_construct(
    ast_While this)
{
    corto_type conditionType;

    ast_Node(this)->kind = Ast_WhileExpr;

    conditionType = ast_Expression_getType(this->condition);
    if (conditionType) {
        /* Check if condition can evaluate to a boolean value */
        if (!corto_type_castable(corto_type(corto_bool_o), conditionType)) {
            ast_Parser_error(yparser(), "expression does not evaluate to condition");
            goto error;
        }
    } else {
        ast_Parser_error(yparser(), "dynamic expressions in while-condition not yet supported");
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_ic_node ast_While_toIc(
    ast_While this,
    corto_ic_program program,
    corto_ic_storage storage,
    bool stored)
{
    ic_storage accumulator;
    ic_label labelEval, labelNeq = NULL;
    ast_Expression condition = NULL;
    corto_bool condResult = FALSE, inverse = FALSE;
    ic_node expr = NULL;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    /* Obtain accumulator for evaluating the condition */
    accumulator = (ic_storage)ic_program_pushAccumulator(
        program, ast_Expression_getType(this->condition), this->condition->isReference, FALSE);

    /* Create label to jump back to evaluation */
    labelEval = ic_label__create(NULL, NULL);

    /* Optimize condition - take into account literals, unwind condition for NOT-operator */
    condition = ast_Node_optimizeCondition(this->condition, &condResult, &inverse);

    if (!this->isUntil) {
        if (condition) {
            expr = ast_Node_toIc(ast_Node(condition), program, accumulator, TRUE);
        }

        /* Create label to jump to when condition evaluates false */
        labelNeq = ic_label__create(NULL, NULL);
        
        /* Evaluate condition, insert jump */
        if (expr) {
            IC_3(program, ast_Node(this)->line, inverse ? ic_jeq : ic_jneq, expr, labelNeq, NULL,
                IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
        }
    }

    /* Insert evaluation label */
    ic_program_add(program, ic_node(labelEval));

    /* -- from here it is a straightforward do-while loop */
    ic_program_popAccumulator(program);

    /* Parse block */
    if (this->trueBranch) {
        if (condition || condResult) {
            if (this->trueBranch->_while != this) {
                ast_Block_toIc(this->trueBranch, program, NULL, FALSE);
            } else {
                ast_Block_toIcBody(this->trueBranch, program, NULL, FALSE);
            }
        }
    }

    /* Parse condition */
    if (condition) {
        expr = ast_Node_toIc(ast_Node(condition), program, accumulator, TRUE);
    }

    /* Evaluate condition, insert jump to evaluate */
    if (expr) {
        IC_3(program, ast_Node(this)->line, inverse ? ic_jneq : ic_jeq, expr, labelEval, NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
    }

    if (!this->isUntil) {
        /* Insert label */
        ic_program_add(program, ic_node(labelNeq));
    }

    return NULL;

}

