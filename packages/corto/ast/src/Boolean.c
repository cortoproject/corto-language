/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Boolean_init(
    ast_Boolean this)
{
    ast_Literal(this)->kind = Ast_Bool;
    return ast_Literal_init(ast_Literal(this));
}

int16_t ast_Boolean_serialize(
    ast_Boolean this,
    corto_type dstType,
    uintptr_t dst)
{
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);

    switch(kind) {
    case Ast_Bool:
    case Ast_Int:
        memset((void*)dst, 0, corto_type_sizeof(dstType));
        *(corto_bool*)dst = this->value;
        break;
    case Ast_Text:
        if (*(corto_string*)dst) {
            corto_dealloc(*(corto_string*)dst);
        }
        if (this->value) {
            *(corto_string*)dst = corto_strdup("true");
        } else {
            *(corto_string*)dst = corto_strdup("false");
        }
        break;
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "cannot serialize boolean value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
}

ic_node ast_Boolean_toIc(
    ast_Boolean this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    ic_node result;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(program);

    corto_any l = {corto_type(corto_bool_o), &this->value, FALSE};
    result = (ic_node)ic_literal_create(NULL, NULL, l);

    return result;
}

