/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Local_construct(
    ast_Local this)
{

    ast_Node(this)->kind = Ast_StorageExpr;
    ast_Storage(this)->kind = Ast_LocalStorage;
    corto_set_ref(&ast_Expression(this)->type, this->type);
    ast_Expression(this)->isReference = this->reference || this->type->reference;

    return ast_Storage_construct(ast_Storage(this));
}

corto_ic_node ast_Local_toIc(
    ast_Local this,
    corto_ic_program program,
    corto_ic_storage storage,
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

