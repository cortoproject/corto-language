/* $CORTO_GENERATED
 *
 * Character.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ast/ast.h>

/* $header() */
#include "ast__private.h"
/* $end */

int16_t _ast_Character_init(
    ast_Character this)
{
/* $begin(corto/ast/Character/init) */
    ast_Literal(this)->kind = Ast_Char;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

int16_t _ast_Character_serialize(
    ast_Character this,
    corto_type dstType,
    uintptr_t dst)
{
/* $begin(corto/ast/Character/serialize) */
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
        corto_convert(corto_primitive(corto_char_o), &this->value, corto_primitive(dstType), (void*)dst);
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
/* $end */
}

ic_node _ast_Character_toIc(
    ast_Character this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
/* $begin(corto/ast/Character/toIc) */
    ic_literal result;
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    corto_any l = {corto_type(corto_char_o), &this->value, FALSE};
    result = ic_literalCreate(l);

    return ic_node(result);
/* $end */
}
