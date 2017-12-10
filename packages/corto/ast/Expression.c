/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

ast_Expression ast_Expression_cast(
    ast_Expression this,
    corto_type type,
    bool isReference)
{
    /* Insert implementation */
}

void ast_Expression_cleanList(
    ast_ExpressionList list)
{
    /* Insert implementation */
}

ast_Expression ast_Expression_fold_v(
    ast_Expression this)
{
    /* Insert implementation */
}

ast_Expression ast_Expression_fromList(
    ast_ExpressionList list)
{
    /* Insert implementation */
}

corto_type ast_Expression_getType(
    ast_Expression this)
{
    /* Insert implementation */
}

corto_type ast_Expression_getType_expr(
    ast_Expression this,
    ast_Expression target)
{
    /* Insert implementation */
}

corto_type ast_Expression_getType_type(
    ast_Expression this,
    corto_type target)
{
    /* Insert implementation */
}

uintptr_t ast_Expression_getValue_v(
    ast_Expression this)
{
    /* Insert implementation */
}

bool ast_Expression_hasReturnedResource_v(
    ast_Expression this)
{
    /* Insert implementation */
}

bool ast_Expression_hasSideEffects_v(
    ast_Expression this)
{
    /* Insert implementation */
}

corto_string ast_Expression_id_v(
    ast_Expression this)
{
    /* Insert implementation */
}

ast_Expression ast_Expression_resolve_v(
    ast_Expression this,
    corto_type type)
{
    /* Insert implementation */
}

int16_t ast_Expression_serialize_v(
    ast_Expression this,
    corto_type dstType,
    uintptr_t dst)
{
    /* Insert implementation */
}

ast_ExpressionList ast_Expression_toList_v(
    ast_Expression this)
{
    /* Insert implementation */
}

