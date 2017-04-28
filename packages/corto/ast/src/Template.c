/* $CORTO_GENERATED
 *
 * Template.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ast/ast.h>

int16_t _ast_Template_construct(
    ast_Template this)
{
/* $begin(corto/ast/Template/construct) */

    if (ast_Local_construct(ast_Local(this))) {
        goto error;
    } else {
        ast_Storage(this)->kind = Ast_TemplateStorage;
    }

    return ast_Storage_construct(ast_Storage(this));
error:
    return -1;
/* $end */
}
