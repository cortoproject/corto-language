/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

/* Insert implicit casts when argument-expressions do not match */
corto_int16 ast_Call_insertCasts(ast_Call this) {
    corto_iter argumentIter;
    ast_Expression argument;
    corto_uint32 i = 0;
    corto_type parameterType, argumentType;

    if (this->arguments) {
        corto_ll arguments = ast_Expression_toList(this->arguments);
        argumentIter = corto_ll_iter(arguments);
        while(corto_iter_hasNext(&argumentIter)) {
            argument = corto_iter_next(&argumentIter);
            parameterType = this->parameters.buffer[i].type;
            argumentType = ast_Expression_getType(argument);

            if (this->parameters.buffer[i].passByReference) {
                if (argumentType && !argument->isReference) {
                    ast_Parser_error(yparser(), "cannot pass non-reference value as reference");
                    goto error;
                }
            }

            /* If both types are not equal, insert cast */
            if ((parameterType != argumentType) || ((argument->deref == Ast_ByReference) && !argumentType->reference)) {
                ast_Expression expr;

                /* Any types are handled in the translation to the target representation. It is often
                 * more efficient to push a value as any than to first cast it to any and then push it. */
                if (parameterType->kind != CORTO_ANY) {
                    expr = ast_Expression_cast(argument, parameterType, this->parameters.buffer[i].passByReference);
                    if (expr) {
                        corto_claim(expr);
                        corto_ll_replace(arguments, argument, expr);
                        corto_release(argument);
                    }
                }
            }

            i++;
        }
        corto_set_ref(&this->arguments, ast_Expression_fromList(arguments));
        ast_Expression_cleanList(arguments);
    }

    return 0;
error:
    return -1;
}


int16_t ast_Call_construct(
    ast_Call this)
{
    ast_Node(this)->kind = Ast_CallExpr;

    /* Insert casts based on expression list and arguments */
    if (ast_Call_insertCasts(this)) {
        goto error;
    }

    corto_set_ref(&ast_Expression(this)->type, this->returnType);
    ast_Expression(this)->isReference =
        this->returnsReference || this->returnType->reference;

    ast_Expression(this)->deref = this->returnType->reference ? Ast_ByReference : Ast_ByValue;

    return 0;
error:
    return -1;
}

bool ast_Call_hasReturnedResource(
    ast_Call this)
{

    return this->returnType->reference ||
        this->returnsReference ||
        ((this->returnType->kind == CORTO_PRIMITIVE) && (corto_primitive(this->returnType)->kind == CORTO_TEXT));

}

bool ast_Call_hasSideEffects(
    ast_Call this)
{
    CORTO_UNUSED(this);
    return TRUE;
}

void ast_Call_setParameters(
    ast_Call this,
    corto_function function)
{
    corto_uint32 i;

    /* Set parameters */
    corto_set_ref(&this->returnType, function->returnType);
    this->returnsReference = function->returnsReference;

    corto_parameterSeqResize(&this->parameters, function->parameters.length);

    for (i = 0; i < function->parameters.length; i++) {
        corto_set_ref(&this->parameters.buffer[i].type, function->parameters.buffer[i].type);
        this->parameters.buffer[i].name = corto_strdup(function->parameters.buffer[i].name);
        this->parameters.buffer[i].passByReference = function->parameters.buffer[i].passByReference;
    }
}

ic_node ast_Call_toIc(
    ast_Call this,
    ic_program program,
    ic_storage storage,
    bool stored)
{
    ic_storage result = NULL;
    ic_node function;
    ast_Expression argument = NULL;
    ic_op *pushIcs = NULL; /* Cache push instructions before inserting in program to avoid issues with nested calls */
    corto_int32 argumentId = 0, argumentCount = 0;
    corto_type thisType = ast_Expression_getType(ast_Expression(this));
    corto_ll arguments = NULL;
    corto_uint32 argumentStorageCount = 0;
    corto_int32 i = 0;

    CORTO_UNUSED(stored);

    if (storage && (storage->type == thisType)) {
        result = storage;
        result->holdsReturn = TRUE;
    } else {
        result = (ic_storage)ic_program_pushAccumulator(
            program, thisType, this->returnsReference || this->returnType->reference, TRUE);
    }

    /* Convert arguments to iterable list */
    if (this->arguments) {
        arguments = ast_Expression_toList(this->arguments);
        if (arguments) {
            argumentCount = corto_ll_count(arguments);
        }
    }

    /* Push 'this' if function is a method or metaprocedure */
    if (this->instanceExpr) {
        ic_node thisIc = ast_Node_toIc(ast_Node(this->instanceExpr), program, NULL, TRUE);
        argumentCount += 1;
        pushIcs = alloca(argumentCount * sizeof(ic_op));
        pushIcs[argumentId] = IC_1_OP(ast_Node(this)->line, ic_push, thisIc, IC_DEREF_ADDRESS, this->instanceIsAny);
        argumentId++;
    } else {
        if (this->arguments) {
            pushIcs = alloca(argumentCount * sizeof(ic_op));
        }
    }

    /* Push arguments */
    if (arguments) {
        corto_iter argumentIter;
        ic_node argumentIc = NULL;
        ic_storage argumentStorage = NULL;

        /* Temporary storage for push-instructions required for pushing the arguments of this function */
        argumentIter = corto_ll_iter(arguments);
        while(corto_iter_hasNext(&argumentIter)) {
            corto_type paramType, exprType;
            ic_derefKind deref = IC_DEREF_ADDRESS;
            corto_bool isAny = FALSE;

            argument = corto_iter_next(&argumentIter);
            if (!argumentStorage ||
              (argumentIc == (ic_node)argumentStorage) ||
              (ast_Expression_getType(argument) != argumentStorage->type)) {
                argumentStorage = (ic_storage)ic_program_pushAccumulator(
                    program,
                    ast_Expression_getType(argument),
                    this->parameters.buffer[i].passByReference || this->parameters.buffer[i].type->reference,
                    FALSE);
                argumentStorageCount++;
            }

            paramType = this->parameters.buffer[i].type;
            exprType = ast_Expression_getType(argument);

            if (paramType->kind == CORTO_ANY) {
                if (exprType && (exprType->kind != CORTO_ANY)) {
                    isAny = TRUE;
                } else if (!exprType) {
                    isAny = TRUE;
                }
            } else {
                if (!exprType) {
                    exprType = paramType;
                }
            }

            if (!isAny && ast_Expression(argument)->deref == Ast_ByValue) {
                /* If argument is pass by value or argument is not a primitive, pass by value */
                if (!this->parameters.buffer[i].passByReference || (paramType->kind != CORTO_PRIMITIVE)) {
                    /* Void references can't be passed as value */
                    if ((exprType->kind != CORTO_VOID) && (paramType->kind != CORTO_VOID)) {
                        deref = IC_DEREF_VALUE;
                    }
                }
            }

            argumentIc = ast_Node_toIc(ast_Node(argument), program, argumentStorage, TRUE);
            pushIcs[argumentId] = IC_1_OP(
                ast_Node(this)->line,
                ic_push, argumentIc,
                deref,
                isAny);
            i++;
            argumentId++;
        }
        ast_Expression_cleanList(arguments);
    }

    for(i = 0; i < argumentCount; i++) {
        ic_program_add(program, (ic_node)pushIcs[i]);
    }

    function = ast_Node_toIc(ast_Node(this->functionExpr), program, storage, stored);

    IC_3(program, ast_Node(this)->line, ic_call, result, function, NULL,
        (this->returnType->reference || this->returnsReference) ? IC_DEREF_ADDRESS : IC_DEREF_VALUE,
        IC_DEREF_VALUE,
        IC_DEREF_VALUE);

    while(argumentStorageCount) {
        ic_program_popAccumulator(program);
        argumentStorageCount--;
    }

    if (storage != result) {
        ic_program_popAccumulator(program);
    }

    return (ic_node)result;
}
