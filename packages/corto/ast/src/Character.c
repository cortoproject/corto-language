/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Character_init(
    ast_Character this)
{
    ast_Literal(this)->kind = Ast_Char;
    return ast_Literal_init(ast_Literal(this));
}

int16_t ast_Character_serialize(
    ast_Character this,
    corto_type dstType,
    uintptr_t dst)
{
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);

    switch(kind) {
    case Ast_Bool:
        *(corto_bool*)dst = this->value ? TRUE : FALSE;
        break;
    case Ast_Char:
    case Ast_Int:
    case Ast_SignedInt:
    case Ast_Text:
        corto_ptr_cast(corto_primitive(corto_char_o), &this->value, corto_primitive(dstType), (void*)dst);
        break;
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "cannot serialize character value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
}

ic_node ast_Character_toIc(
    ast_Character this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    ic_literal result;
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    corto_any l = {corto_type(corto_char_o), &this->value, FALSE};
    result = ic_literal_create(NULL, NULL, l);

    return ic_node(result);
}

