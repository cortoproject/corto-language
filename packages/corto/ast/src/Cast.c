/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

int16_t ast_Cast_construct(
    ast_Cast this)
{

    ast_Node(this)->kind = Ast_CallExpr;

    corto_type rvalueType;
    rvalueType = ast_Expression_getType(this->rvalue);
    if (rvalueType) {
        if ((this->isReference && rvalueType->reference && (rvalueType->kind == CORTO_VOID)) ||
           (corto_type_castable(this->lvalue, rvalueType) || corto_type_castable(rvalueType, this->lvalue))) {
            corto_set_ref(&ast_Expression(this)->type, this->lvalue);
            ast_Expression(this)->isReference = this->lvalue->reference || this->isReference;
        } else {
            corto_id id1, id2;
            ast_Parser_error(yparser(), "cannot cast from type '%s' to '%s'",
                    ast_Parser_id(rvalueType, id1), ast_Parser_id(this->lvalue, id2));
            goto error;
        }
    } else {
        /* If type of rvalue is unknown, cast is performed at runtime. Set type even though to introduce the
         * type barrier for code using this expression. */
        corto_set_ref(&ast_Expression(this)->type, this->lvalue);
    }

    return 0;
error:
    return -1;
}

bool ast_Cast_hasReturnedResource(
    ast_Cast this)
{

    return ast_Expression_hasReturnedResource(this->rvalue);

}

corto_ic_node ast_Cast_toIc(
    ast_Cast this,
    corto_ic_program program,
    corto_ic_storage storage,
    bool stored)
{
    ic_node lvalue, rvalue, result;
    corto_bool deref1 = IC_DEREF_VALUE, deref2 = IC_DEREF_VALUE;
    corto_type this_type = ast_Expression_getType(ast_Expression(this));
    CORTO_UNUSED(stored);

    if (storage && (storage->type == this_type)) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(
            program,
            ast_Expression_getType(ast_Expression(this)),
            (this->rvalue->deref == Ast_ByReference) || this_type->reference,
            FALSE);
    }

    lvalue = (ic_node)ic_object__create(NULL, NULL, this->lvalue);
    rvalue = ast_Node_toIc(ast_Node(this->rvalue), program, (ic_storage)NULL, TRUE);

    if ((this->rvalue->deref == Ast_ByReference) || this_type->reference) {
        deref2 = IC_DEREF_ADDRESS;
    }
    if ((this->rvalue->deref == Ast_ByReference) || this_type->reference) {
        deref1 = IC_DEREF_ADDRESS;
    }

    IC_3(program, ast_Node(this)->line, ic_cast, result, rvalue, lvalue,
        deref1, deref2, IC_DEREF_ADDRESS);

    return result;
}

