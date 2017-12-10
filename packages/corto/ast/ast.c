/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

bool ast_isOperatorAssignment(
    corto_operatorKind _operator)
{
    /* Insert implementation */
}

void ast_report(
    corto_string kind,
    corto_string filename,
    uint32_t line,
    uint32_t column,
    corto_string error,
    corto_string token)
{
    /* Insert implementation */
}

void ast_reportError(
    corto_string filename,
    uint32_t line,
    uint32_t column,
    corto_string error,
    corto_string token)
{
    /* Insert implementation */
}

void ast_reportWarning(
    corto_string filename,
    uint32_t line,
    uint32_t column,
    corto_string error,
    corto_string token)
{
    /* Insert implementation */
}

ast_valueKind ast_valueKindFromType(
    corto_type type)
{
    /* Insert implementation */
}

int cortomain(int argc, char *argv[]) {

    /* Insert implementation */
    
    return 0;
}

