/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

int16_t ast_Binary_construct(
    ast_Binary this)
{
    /* Insert implementation */
}

ast_Expression ast_Binary_fold(
    ast_Binary this)
{
    /* Insert implementation */
}

bool ast_Binary_hasReturnedResource(
    ast_Binary this)
{
    /* Insert implementation */
}

bool ast_Binary_hasSideEffects(
    ast_Binary this)
{
    /* Insert implementation */
}

ast_Expression ast_Binary_resolve(
    ast_Binary this,
    corto_type type)
{
    /* Insert implementation */
}

void ast_Binary_setOperator(
    ast_Binary this,
    corto_operatorKind kind)
{
    /* Insert implementation */
}

ic_node ast_Binary_toIc(
    ast_Binary this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    /* Insert implementation */
}

