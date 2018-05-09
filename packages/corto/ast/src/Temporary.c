/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>
int16_t ast_Temporary_construct(
    ast_Temporary this)
{

    ast_Storage(this)->kind = Ast_TemporaryStorage;
    corto_set_ref(&ast_Expression(this)->type, this->type);
    ast_Expression(this)->isReference = this->reference;

    return ast_Storage_construct(ast_Storage(this));
}

void ast_Temporary_setProxy(
    ast_Temporary this,
    ast_Temporary proxy)
{
    corto_set_ref(&this->proxy, proxy);
}

corto_ic_node ast_Temporary_toIc(
    ast_Temporary this,
    corto_ic_program program,
    corto_ic_storage storage,
    bool stored)
{
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(program);

    if (!this->proxy && !this->ic) {
        ic_node acc = ic_node(ic_accumulator__create(NULL, NULL, NULL, this->type, this->reference || this->type->reference, FALSE));
        corto_set_ref(&this->ic, acc);
        corto_release(acc);
    } else if (this->proxy) {
        ic_node acc = ast_Temporary_toIc(this->proxy, program, storage, stored);
        corto_set_ref(&this->ic, acc);
    }

    return this->ic;
}

