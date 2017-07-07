/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Init_construct(
    ast_Init this)
{
	corto_type t = ast_Expression_getType(ast_Expression(this->storage));
    ast_Node(this)->kind = Ast_InitExpr;
    corto_ptr_setref(&ast_Expression(this)->type, t);
    return 0;
}

ic_node ast_Init_toIc(
    ast_Init this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    ic_node s;
    CORTO_UNUSED(stored);
    CORTO_UNUSED(storage);

    s = ast_Node_toIc(ast_Node(this->storage), program, NULL, TRUE);
    IC_1(program, ast_Node(this)->line, ic_init, s, IC_DEREF_ADDRESS);

    return NULL;
}

