/* $CORTO_GENERATED
 *
 * UnresolvedReference.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/ast/ast.h"

/* $header() */
#include "ast__private.h"
 /* $end */

corto_int16 _ast_UnresolvedReference_construct(ast_UnresolvedReference this) {
/* $begin(corto/ast/UnresolvedReference/construct) */

    ast_Storage(this)->kind = Ast_UnresolvedReferenceStorage;
    ast_Expression(this)->unresolved = TRUE;
    corto_setref(&ast_Expression(this)->type, corto_void_o);

    return ast_Storage_construct(this);
/* $end */
}

corto_void _ast_UnresolvedReference_error(ast_UnresolvedReference this) {
/* $begin(corto/ast/UnresolvedReference/error) */
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

corto_string _ast_UnresolvedReference_id_v(ast_UnresolvedReference this) {
/* $begin(corto/ast/UnresolvedReference/id) */

    return this->ref;

/* $end */
}

ast_Expression _ast_UnresolvedReference_resolve_v(ast_UnresolvedReference this, corto_type type) {
/* $begin(corto/ast/UnresolvedReference/resolve) */
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
/* $end */
}

ic_node _ast_UnresolvedReference_toIc_v(ast_UnresolvedReference this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(corto/ast/UnresolvedReference/toIc) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    ast_UnresolvedReference_error(this);

    return NULL;
/* $end */
}
