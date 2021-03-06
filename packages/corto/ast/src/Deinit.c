/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Deinit_construct(
    ast_Deinit this)
{
	corto_type t = ast_Expression_getType(ast_Expression(this->storage));
    ast_Node(this)->kind = Ast_DeinitExpr;
    corto_set_ref(&ast_Expression(this)->type, t);
    return 0;
}

corto_ic_node ast_Deinit_toIc(
    ast_Deinit this,
    corto_ic_program program,
    corto_ic_storage storage,
    bool stored)
{
    ic_node s;
    CORTO_UNUSED(stored);
    CORTO_UNUSED(storage);

    s = ast_Node_toIc(ast_Node(this->storage), program, NULL, TRUE);
    IC_1(program, ast_Node(this)->line, ic_deinit, s, IC_DEREF_ADDRESS);

    return NULL;
}

