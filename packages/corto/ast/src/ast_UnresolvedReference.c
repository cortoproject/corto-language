/* $CORTO_GENERATED
 *
 * ast_UnresolvedReference.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
 /* $end */

corto_int16 _ast_UnresolvedReference_construct(ast_UnresolvedReference this) {
/* $begin(::corto::ast::UnresolvedReference::construct) */

    ast_Storage(this)->kind = Ast_UnresolvedReferenceStorage;
    corto_setref(&ast_Expression(this)->type, corto_void_o);

    return ast_Storage_construct(this);
/* $end */
}

corto_void _ast_UnresolvedReference_error(ast_UnresolvedReference this) {
/* $begin(::corto::ast::UnresolvedReference::error) */
    corto_id errMsg;

    sprintf(errMsg, "unresolved identifier: %s", this->ref);
    ast_reportError(
        yparser()->filename, 
        this->line, 
        this->column,
        errMsg,
        NULL);

    yparser()->errors++;

/* $end */
}

corto_object _ast_UnresolvedReference_resolve(ast_UnresolvedReference this, corto_type targetType) {
/* $begin(::corto::ast::UnresolvedReference::resolve) */
    corto_object result = NULL;

    if (targetType) {
        result = corto_resolve(targetType, this->ref);
    }

    if (!result) {
        result = corto_resolve(this->scope, this->ref);
        if (!result) {
            ast_UnresolvedReference_error(this);
        }
    }

    return result;
/* $end */
}

ic_node _ast_UnresolvedReference_toIc_v(ast_UnresolvedReference this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::UnresolvedReference::toIc) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    ast_UnresolvedReference_error(this);

    return NULL;
/* $end */
}
