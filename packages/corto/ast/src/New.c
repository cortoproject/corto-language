/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_New_construct(
    ast_New this)
{

    ast_Node(this)->kind = Ast_NewExpr;
    corto_set_ref(&ast_Expression(this)->type, this->type);
    ast_Expression(this)->isReference = TRUE;

    return 0;
}

bool ast_New_hasSideEffects(
    ast_New this)
{
    CORTO_UNUSED(this);
    return TRUE;
}

corto_ic_node ast_New_toIc(
    ast_New this,
    corto_ic_program program,
    corto_ic_storage storage,
    bool stored)
{
    ic_node type, attrs, result;
    CORTO_UNUSED(stored);

    if (storage) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(program, ast_Expression_getType(ast_Expression(this)), TRUE, FALSE);
    }

    type = (ic_node)ic_object__create(NULL, NULL, ast_Expression(this)->type);
    if (this->attributes) {
        attrs = ast_Node_toIc(ast_Node(this->attributes), program, NULL, TRUE);
    } else {
        attrs = NULL;
    }

    IC_3(program, ast_Node(this)->line, ic_new, 
        result, type, attrs, IC_DEREF_ADDRESS, IC_DEREF_ADDRESS, IC_DEREF_VALUE)

    return result;
}

