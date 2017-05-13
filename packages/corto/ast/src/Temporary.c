/* $CORTO_GENERATED
 *
 * Temporary.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ast/ast.h>

int16_t _ast_Temporary_construct(
    ast_Temporary this)
{
/* $begin(corto/ast/Temporary/construct) */

    ast_Storage(this)->kind = Ast_TemporaryStorage;
    corto_ptr_setref(&ast_Expression(this)->type, this->type);
    ast_Expression(this)->isReference = this->reference;

    return ast_Storage_construct(ast_Storage(this));
/* $end */
}

void _ast_Temporary_setProxy(
    ast_Temporary this,
    ast_Temporary proxy)
{
/* $begin(corto/ast/Temporary/setProxy) */
    corto_ptr_setref(&this->proxy, proxy);
/* $end */
}

ic_node _ast_Temporary_toIc(
    ast_Temporary this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
/* $begin(corto/ast/Temporary/toIc) */
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(program);

    if (!this->proxy && !this->ic) {
        ic_node acc = ic_node(ic_accumulatorCreate(NULL, this->type, this->reference || this->type->reference, FALSE));
        corto_ptr_setref(&this->ic, acc);
        corto_release(acc);
    } else if (this->proxy) {
        ic_node acc = ast_Temporary_toIc(this->proxy, program, storage, stored);
        corto_ptr_setref(&this->ic, acc);
    }

    return this->ic;
/* $end */
}
