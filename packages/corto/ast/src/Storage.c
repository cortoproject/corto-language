/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>
int16_t ast_Storage_construct(
    ast_Storage this)
{

    ast_Node(this)->kind = Ast_StorageExpr;
    ast_Expression(this)->deref = ast_Expression(this)->type->reference ? Ast_ByReference : Ast_ByValue;

    return 0;
}

