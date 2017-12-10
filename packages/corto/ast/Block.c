/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

void ast_Block_addStatement(
    ast_Block this,
    ast_Node statement)
{
    /* Insert implementation */
}

ast_Local ast_Block_declare(
    ast_Block this,
    corto_string id,
    corto_type type,
    bool isParameter,
    bool isReference)
{
    /* Insert implementation */
}

ast_Local ast_Block_declareReturnVariable(
    ast_Block this,
    corto_function function)
{
    /* Insert implementation */
}

ast_Template ast_Block_declareTemplate(
    ast_Block this,
    corto_string id,
    corto_type type,
    bool isParameter,
    bool isReference)
{
    /* Insert implementation */
}

ast_Expression ast_Block_lookup(
    ast_Block this,
    corto_string id)
{
    /* Insert implementation */
}

ast_Local ast_Block_lookupLocal(
    ast_Block this,
    corto_string id)
{
    /* Insert implementation */
}

ast_Expression ast_Block_resolve(
    ast_Block this,
    corto_string id)
{
    /* Insert implementation */
}

ast_Local ast_Block_resolveLocal(
    ast_Block this,
    corto_string id)
{
    /* Insert implementation */
}

void ast_Block_setFunction(
    ast_Block this,
    corto_function function)
{
    /* Insert implementation */
}

ic_node ast_Block_toIc(
    ast_Block this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    /* Insert implementation */
}

ic_node ast_Block_toIcBody(
    ast_Block this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    /* Insert implementation */
}

