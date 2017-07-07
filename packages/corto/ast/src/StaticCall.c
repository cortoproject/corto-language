/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_StaticCall_construct(
    ast_StaticCall this)
{
    ast_Object fExpr;

    fExpr = ast_ObjectCreate(this->function);
    ast_Parser_collect(yparser(), fExpr);
    corto_ptr_setref(&ast_Call(this)->functionExpr, fExpr);

    /* Set parameters */
    ast_Call_setParameters(ast_Call(this), this->function);

    /* If function is a metaprocedure, signal Call class to push this as any */
    ast_Call(this)->instanceIsAny = 
        (corto_procedure(corto_typeof(this->function))->thisType == corto_any_o);

    return ast_Call_construct(ast_Call(this));
}

