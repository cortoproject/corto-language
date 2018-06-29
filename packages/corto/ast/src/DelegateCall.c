/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_DelegateCall_construct(
    ast_DelegateCall this)
{
    if (!this->expr) {
        ast_Parser_error(yparser(), "no expression provided for delegate call");
        goto error;
    } else {
        corto_uint32 i;
        corto_delegate type = corto_delegate(ast_Expression_getType(this->expr));

        /* Create expression to obtain pointer to the instance */
        ast_String instanceString = ast_String__create(NULL, NULL, "instance");
        ast_Member iExpr = ast_Member__create(NULL, NULL, this->expr, ast_Expression(instanceString));
        corto_set_ref(&ast_Call(this)->instanceExpr, iExpr);
        ast_Parser_collect(yparser(), iExpr);
        ast_Parser_collect(yparser(), instanceString);

        /* Set function expression to delegate */
        corto_set_ref(&ast_Call(this)->functionExpr, this->expr);

        /* Set parameters */
        corto_set_ref(&ast_Call(this)->return_type, type->return_type);
        ast_Call(this)->is_reference = type->is_reference;

        corto_parameterSeq__resize(&ast_Call(this)->parameters, type->parameters.length);

        for (i = 0; i < type->parameters.length; i++) {
            corto_set_ref(&ast_Call(this)->parameters.buffer[i].type, type->parameters.buffer[i].type);
            ast_Call(this)->parameters.buffer[i].is_reference = type->parameters.buffer[i].is_reference;
        }
    }

    return ast_Call_construct(ast_Call(this));
error:
    return -1;
}
