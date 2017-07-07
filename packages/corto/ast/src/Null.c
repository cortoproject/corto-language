/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Null_init(
    ast_Null this)
{
    ast_Literal(this)->kind = Ast_Nothing;
    ast_Expression(this)->type = NULL;
    return ast_Literal_init(ast_Literal(this));
}

int16_t ast_Null_serialize(
    ast_Null this,
    corto_type dstType,
    uintptr_t dst)
{
    ast_valueKind kind;
    CORTO_UNUSED(this);

    kind = ast_valueKindFromType(dstType);
    
    switch(kind) {
    case Ast_Bool:
        *(corto_bool*)dst = FALSE;
        break;
    case Ast_Text:
        if (*(corto_string*)dst) {
            corto_dealloc(*(corto_string*)dst);
        }
        *(corto_string*)dst = NULL;
        break;
    case Ast_Ref:
        if (*(corto_object*)dst) {
            corto_release(*(corto_object*)dst);
        }
        *(corto_object*)dst = NULL;
        break;
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "cannot serialize null value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
}

ic_node ast_Null_toIc(
    ast_Null this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(this);
    CORTO_UNUSED(program);

    corto_any l = {corto_type(corto_void_o), NULL, FALSE};
    return ic_node(ic_literalCreate(l));
}

