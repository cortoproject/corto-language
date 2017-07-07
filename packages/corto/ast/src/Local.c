/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Local_construct(
    ast_Local this)
{

    ast_Node(this)->kind = Ast_StorageExpr;
    ast_Storage(this)->kind = Ast_LocalStorage;
    corto_ptr_setref(&ast_Expression(this)->type, this->type);
    ast_Expression(this)->isReference = this->reference || this->type->reference;

    return ast_Storage_construct(ast_Storage(this));
}

ic_node ast_Local_toIc(
    ast_Local this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    ic_node result;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(program);

    result = (ic_node)ic_program_getVariable(
                program,
                this->name);

    return result;
}

