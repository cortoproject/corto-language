/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

uintptr_t ast_Literal_getValue_v(
    ast_Literal this)
{
    corto_word result = 0;

    switch(this->kind) {
    case Ast_Bool: result = (corto_word)&ast_Boolean(this)->value; break;
    case Ast_Char: result = (corto_word)&ast_Character(this)->value; break;
    case Ast_Int: result = (corto_word)&ast_Integer(this)->value; break;
    case Ast_SignedInt: result = (corto_word)&ast_SignedInteger(this)->value; break;
    case Ast_Float: result = (corto_word)&ast_FloatingPoint(this)->value; break;
    default: break; /* Enumerated, Reference & Null have no value. String handles it's own value. */
    }

    return result;
}

int16_t ast_Literal_init(
    ast_Literal this)
{
    if (!ast_Expression(this)->type) {
        switch(this->kind) {
        case Ast_Bool:
            corto_set_ref(&ast_Expression(this)->type, corto_bool_o);
            break;
        case Ast_Char:
            corto_set_ref(&ast_Expression(this)->type, corto_char_o);
            break;
        case Ast_Int:
            corto_set_ref(&ast_Expression(this)->type, corto_uint64_o);
            break;
        case Ast_SignedInt:
            corto_set_ref(&ast_Expression(this)->type, corto_int64_o);
            break;
        case Ast_Float:
            corto_set_ref(&ast_Expression(this)->type, corto_float64_o);
            break;
        case Ast_Text:
            corto_set_ref(&ast_Expression(this)->type, corto_string_o);
            break;
        case Ast_Enum:
            corto_set_ref(&ast_Expression(this)->type, corto_uint32_o);
            break;
        case Ast_Ref:
            corto_set_ref(&ast_Expression(this)->type, corto_object_o);
            break;
        case Ast_Nothing:
            /* No type. */
            break;
        }
    }

    ast_Node(this)->kind = Ast_LiteralExpr;

    return ast_Node_init(ast_Node(this));
}

