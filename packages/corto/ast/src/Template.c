/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>
int16_t ast_Template_construct(
    ast_Template this)
{

    if (ast_Local_construct(ast_Local(this))) {
        goto error;
    } else {
        ast_Storage(this)->kind = Ast_TemplateStorage;
    }

    return ast_Storage_construct(ast_Storage(this));
error:
    return -1;
}

