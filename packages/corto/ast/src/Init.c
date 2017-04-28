/* $CORTO_GENERATED
 *
 * Init.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ast/ast.h>

/* $header() */
#include "ast__private.h"
/* $end */

int16_t _ast_Init_construct(
    ast_Init this)
{
/* $begin(corto/ast/Init/construct) */
	corto_type t = ast_Expression_getType(ast_Expression(this->storage));
    ast_Node(this)->kind = Ast_InitExpr;
    corto_setref(&ast_Expression(this)->type, t);
    return 0;
/* $end */
}

ic_node _ast_Init_toIc(
    ast_Init this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
/* $begin(corto/ast/Init/toIc) */
    ic_node s;
    CORTO_UNUSED(stored);
    CORTO_UNUSED(storage);

    s = ast_Node_toIc(ast_Node(this->storage), program, NULL, TRUE);
    IC_1(program, ast_Node(this)->line, ic_init, s, IC_DEREF_ADDRESS);

    return NULL;
/* $end */
}
