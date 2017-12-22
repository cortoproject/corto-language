/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>
#include "ast__private.h"
int16_t ast_InitializerExpression_construct(
    ast_InitializerExpression this)
{
    corto_int16 result = 0;

    ast_Node(this)->kind = Ast_InitializerExpr;

    return result;
}

int16_t ast_InitializerExpression_defineObject(
    ast_InitializerExpression this)
{
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpDefine;
    return 0;
}

bool ast_InitializerExpression_hasReturnedResource(
    ast_InitializerExpression this)
{
    CORTO_UNUSED(this);
    return FALSE;
}

int16_t ast_InitializerExpression_insert(
    ast_InitializerExpression this,
    ast_Expression variable)
{
    ast_DynamicInitializer initializer;

    corto_set_ref(&ast_Initializer(this)->variables[0].object, variable);
    corto_set_ref(&ast_Expression(this)->type, variable->type);

    ast_Expression var = ast_Initializer(this)->variables[0].object;
    if (ast_Storage(var)->kind == Ast_TemporaryStorage) {
        ast_Init init = ast_InitCreate(ast_Storage(var));
        ast_Parser_addStatement(yparser(), ast_Node(init));
        ast_Parser_collect(yparser(), init);
    }

    /* Create initializer */
    /* Note that since I'm passing MY list of variables, I need to fix the reference count! */
    corto_claim(ast_Initializer(this)->variables[0].object);
    initializer = ast_DynamicInitializerCreate(ast_Initializer(this)->variables, 1, this->assignValue);
    /* Walk operations */
    corto_iter it = corto_ll_iter(this->operations);
    while (corto_iter_hasNext(&it)) {
        ast_InitOper *elem = corto_iter_next(&it);
        switch(elem->kind) {
        case Ast_InitOpPush:
            if (ast_DynamicInitializer_push(initializer)) {
                goto error;
            }

            break;
        case Ast_InitOpPop:
            if (ast_DynamicInitializer_pop(initializer)) {
                goto error;
            }

            break;
        case Ast_InitOpDefine:
            if (ast_DynamicInitializer_defineObject(initializer)) {
                goto error;
            }

            break;
        case Ast_InitOpValue:
            if (ast_DynamicInitializer_value(initializer, elem->expr)) {
                goto error;
            }

            break;
        case Ast_InitOpMember:
            if (ast_Initializer_member(ast_Initializer(initializer), elem->name)) {
                goto error;
            }

           break;
        }

    }

    corto_release(initializer);
    return 0;
error:
    return -1;
}

int32_t ast_InitializerExpression_member(
    ast_InitializerExpression this,
    const char *name)
{
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpMember;
    elem->name = corto_strdup(name);
    return 0;
}

int16_t ast_InitializerExpression_pop(
    ast_InitializerExpression this)
{
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpPop;
    return 0;
}

int16_t ast_InitializerExpression_push(
    ast_InitializerExpression this)
{
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpPush;
    return 0;
}

int16_t ast_InitializerExpression_value(
    ast_InitializerExpression this,
    ast_Expression v)
{
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpValue;
    corto_set_ref(&elem->expr, v);
    return 0;
}

