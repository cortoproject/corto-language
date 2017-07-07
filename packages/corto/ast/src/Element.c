/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Element_construct(
    ast_Element this)
{
    corto_type lvalueType, rvalueType;

    ast_Storage(this)->kind = Ast_ElementStorage;

    lvalueType = ast_Expression_getType(this->lvalue);

    if (lvalueType) {
        if (lvalueType->kind == CORTO_COLLECTION) {
            rvalueType = ast_Expression_getType(this->rvalue);
            if (rvalueType) {
                if (corto_collection(lvalueType)->kind != CORTO_MAP) {
                    if (!corto_type_castable(corto_type(corto_uint32_o), rvalueType)) {
                        corto_id id;
                        ast_Parser_error(yparser(), "expected integer expression for index, got '%s'", ast_Parser_id(rvalueType, id));
                        goto error;
                    }
                } else {
                    if (!corto_type_castable(corto_map(lvalueType)->keyType, rvalueType)) {
                        corto_id id, id2;
                        ast_Parser_error(yparser(), "expected expression of type '%s' for key, got '%s'",
                                ast_Parser_id(corto_map(lvalueType)->keyType, id), ast_Parser_id(rvalueType, id2));
                        goto error;
                    }
                }
            }
            /* Set type of expression */
            corto_ptr_setref(&ast_Expression(this)->type, corto_collection(lvalueType)->elementType);
        } else {
            corto_id id;
            ast_Parser_error(yparser(), "cannot obtain element from this of non-collection type '%s'", ast_Parser_id(lvalueType, id));
            goto error;
        }
    } else {
        ast_Parser_error(yparser(), "dynamic expressions are not yet supported");
        goto error;
    }

    ast_Expression(this)->isReference = corto_collection(lvalueType)->elementType->reference;

    return ast_Storage_construct(ast_Storage(this));
error:
    return -1;
}

ic_node ast_Element_toIc(
    ast_Element this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    ic_element result;
    ic_node lvalue, rvalue;
    CORTO_UNUSED(stored);
    CORTO_UNUSED(storage);

    /* Get lvalue & rvalue */
    lvalue = ast_Node_toIc(ast_Node(this->lvalue), program, NULL, TRUE);
    rvalue = ast_Node_toIc(ast_Node(this->rvalue), program, NULL, TRUE);

    result = ic_program_getElement(program, ic_storage(lvalue), rvalue);

    return (ic_node)result;
}

