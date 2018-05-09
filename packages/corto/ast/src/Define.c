/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Define_construct(
    ast_Define this)
{

    ast_Node(this)->kind = Ast_DefineExpr;

    return 0;
}

corto_ic_node ast_Define_toIc(
    ast_Define this,
    corto_ic_program program,
    corto_ic_storage storage,
    bool stored)
{
    ic_node object;
    CORTO_UNUSED(stored);
    CORTO_UNUSED(storage);

    object = ast_Node_toIc(ast_Node(this->object), program, NULL, TRUE);
    IC_1(program, ast_Node(this)->line, ic_define, object, IC_DEREF_ADDRESS);

    return NULL;
}

