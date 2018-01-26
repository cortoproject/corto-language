/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Integer_init(
    ast_Integer this)
{
    ast_Literal(this)->kind = Ast_Int;
    return ast_Literal_init((ast_Literal)this);
}

int16_t ast_Integer_serialize(
    ast_Integer this,
    corto_type dstType,
    uintptr_t dst)
{
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);
    memset((void*)dst, 0, corto_type_sizeof(dstType));

    switch(kind) {
    case Ast_Bool:
        *(corto_bool*)dst = this->value ? TRUE : FALSE;
        break;
    case Ast_Char:
    case Ast_Int:
    case Ast_SignedInt:
    case Ast_Float:
    case Ast_Enum:
    case Ast_Text:
        corto_ptr_cast(corto_primitive(corto_uint64_o), &this->value, corto_primitive(dstType), (void*)dst);
        break;
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "cannot serialize integer value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
}

ic_node ast_Integer_toIc(
    ast_Integer this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    ic_node result;
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    corto_any l = {ast_Expression_getType(ast_Expression(this)), &this->value, FALSE};
    result = (ic_node)ic_literal__create(NULL, NULL, l);

    return result;
}

