/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"
 
int16_t ast_UnresolvedReference_construct(
    ast_UnresolvedReference this)
{

    ast_Storage(this)->kind = Ast_UnresolvedReferenceStorage;
    ast_Expression(this)->unresolved = TRUE;
    corto_set_ref(&ast_Expression(this)->type, corto_void_o);

    return safe_ast_Storage_construct(this);
}

void ast_UnresolvedReference_error(
    ast_UnresolvedReference this)
{
    corto_id errMsg;

    sprintf(errMsg, "unresolved identifier '%s'", this->ref);
    ast_reportError(
        yparser()->filename,
        this->line,
        this->column,
        errMsg,
        NULL);

    yparser()->errors++;

}

corto_string ast_UnresolvedReference_id(
    ast_UnresolvedReference this)
{

    return this->ref;

}

ast_Expression ast_UnresolvedReference_resolve(
    ast_UnresolvedReference this,
    corto_type type)
{
    ast_Expression result = NULL;
    corto_object o = NULL;

    if (type) {
        o = corto_resolve(type, this->ref);
    }

    if (!o) {
        o = corto_resolve(this->scope, this->ref);
        if (!o) {
            ast_UnresolvedReference_error(this);
        }
    }

    if (o) {
        result = ast_Expression(ast_ObjectCreate(o));
    }

    return result;
}

ic_node ast_UnresolvedReference_toIc(
    ast_UnresolvedReference this,
    ic_program program,
    ic_storage storage,
    bool stored)
{

    CORTO_UNUSED(this);
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    ast_UnresolvedReference_error(this);

    return NULL;
}

