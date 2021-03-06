/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>
#include "ast__private.h"
void ast_Block_addStatement(
    ast_Block this,
    ast_Node statement)
{
    if (statement) {
        corto_assert(this->statements != NULL, "initialization failed");
        ast_NodeList__append(this->statements, statement);
    }
}

ast_Local ast_Block_declareVar(
    ast_Block this,
    const char *id,
    corto_type type,
    bool isParameter,
    bool isReference)
{
    ast_Local result;
    ast_LocalKind kind = 0;

    corto_assert(this->locals != NULL, "initialization failed");

    /* Check if variable already exists. Use lookupLocal instead of lookup since the ordinary lookup also
     * looks for member-variables if the block is part of a function. */
    if (ast_Block_lookupLocal(this, id)) {
        printf("%s:%d:%d: local '%s' already declared\n", yparser()->filename, yparser()->line, yparser()->column, id);
        goto error;
    }

    /* If variable did not exist, declare it in this block */
    kind = isParameter ? Ast_LocalParameter : Ast_LocalDefault;
    result = ast_Local__create(NULL, NULL, id, type, kind, isReference);
    if (result) {
        corto_ll_append(this->locals, result);
    } else {
        goto error;
    }

    return result;
error:
    return NULL;
}

ast_Local ast_Block_declareReturnVariable(
    ast_Block this,
    corto_function function)
{
    ast_Local result;
    corto_id id;

    /* Get name of function from signature */
    corto_sig_name(corto_idof(function), id);

    corto_assert(this->locals != NULL, "initialization failed");

    /* If variable did not exist, declare it in this block */
    result = ast_Local__create(NULL, NULL, id, function->return_type, Ast_LocalReturn, function->is_reference);
    if (result) {
        corto_ll_append(this->locals, result);
    }

    return result;
}

ast_Template ast_Block_declareTemplate(
    ast_Block this,
    const char *id,
    corto_type type,
    bool isParameter,
    bool isReference)
{
    ast_Template result;

    corto_assert(this->locals != NULL, "initialization failed");

    /* Check if variable already exists */
    if (ast_Block_lookup(this, id)) {
        printf("%s:%d:%d: variable '%s' already declared\n", yparser()->filename, yparser()->line, yparser()->column, id);
        goto error;
    }

    /* If variable did not exist, declare it in this block */
    result = ast_Template__create(NULL, NULL, id, type, isParameter, isReference);
    if (result) {
        corto_ll_insert(this->locals, result);
    }

    return result;
error:
    return NULL;
}

ast_Expression ast_Block_lookup(
    ast_Block this,
    const char *id)
{
    ast_Expression result = NULL;

    result = ast_Expression(ast_Block_lookupLocal(this, id));

    if (!result) {
        if (this->function && corto_instanceof(corto_interface_o, corto_parentof(this->function))) {
            if (corto_procedure(corto_typeof(this->function))->has_this) {
                if (strcmp(id, "this")) {
                    corto_object parent;
                    corto_member m;
                    ast_Expression thisLocal;

                    thisLocal = ast_Block_lookup(this, "this");

                    /* If function is scoped use the parentof function to determine it's parent. The current scope can point
                     * to a different object since functions can be forward declared. If the function is anonymous (for example
                     * in the case of anonymous observers) using the parser-scope is safe since these functions can't be forward
                     * declared.
                     */
                    if (corto_check_attr(this->function, CORTO_ATTR_NAMED)) {
                        parent = corto_parentof(this->function);
                    } else {
                        parent = yparser()->scope;
                    }

                    /* If parent is not of an interface type, this could be a
                     * delegate member implementation. Get type of the parent
                     * instead. */
                    if (!corto_instanceof(corto_type(corto_interface_o), parent)) {
                        parent = corto_typeof(parent);
                    }

                    /* If parent is still not of an interface type, resolving
                     * a 'this' from either a method or observer is illegal */
                    if (!corto_instanceof(corto_type(corto_interface_o), parent)) {
                        corto_id id;
                        ast_Parser_error(yparser(),
                            "'this' illegal in procedure '%s'",
                            ast_Parser_id(this->function, id));
                        goto error;
                    }

                    m = corto_interface_resolve_member(corto_interface(parent), id);
                    /* If 'this' is not yet declared, lookup is used while declaring
                     * function parameters. */
                    if (thisLocal) {
                        /* If a member is found, create memberexpression */
                        if (m) {
                            ast_String memberIdExpr;
                            memberIdExpr = ast_String__create(NULL, NULL, id);
                            result = ast_Expression(ast_Member__create(NULL, NULL,
                                     thisLocal, ast_Expression(memberIdExpr)));
                            ast_Parser_collect(yparser(), memberIdExpr);
                            ast_Parser_collect(yparser(), result);
                        } else {
                            corto_method m;
                            /* If no member is found, lookup method */
                            m = corto_interface_resolve_method(corto_interface(parent), id);
                            if (m) {
                                ast_String memberIdExpr;
                                memberIdExpr = ast_String__create(NULL, NULL, id);
                                result = ast_Expression(ast_Member__create(NULL, NULL,
                                         thisLocal, ast_Expression(memberIdExpr)));
                                ast_Parser_collect(yparser(), memberIdExpr);
                                ast_Parser_collect(yparser(), result);
                            }

                        }

                    }

                }

            }

        }

    }

    return result;
error:
    return NULL;
}

ast_Local ast_Block_lookupLocal(
    ast_Block this,
    const char *id)
{
    ast_Local result = NULL;

    if (this->locals) {
        corto_iter iter;
        ast_Local local;
        iter = corto_ll_iter(this->locals);
        while(corto_iter_hasNext(&iter)) {
            local = corto_iter_next(&iter);
            if (!strcmp(local->name, id)) {
                result = local;
                break;
            }

        }

    }

    return result;
}

ast_Expression ast_Block_resolve(
    ast_Block this,
    const char *id)
{
    ast_Expression result = NULL;

    if (!(result = ast_Block_lookup(this, id))) {
        if (this->parent && !this->function) {
            result = ast_Block_resolve(this->parent, id);
        }

    }

    return result;
}

ast_Local ast_Block_resolveLocal(
    ast_Block this,
    const char *id)
{
    ast_Local result = NULL;

    if (!(result = ast_Block_lookupLocal(this, id))) {
        if (this->parent && !this->function) {
            result = ast_Block_resolveLocal(this->parent, id);
        }

    }

    return result;
}

void ast_Block_setFunction(
    ast_Block this,
    corto_function function)
{
    corto_set_ref(&this->function, function);
}

corto_ic_node ast_Block_toIc(
    ast_Block this,
    corto_ic_program program,
    corto_ic_storage storage,
    bool stored)
{
    ic_scope scope;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    scope = ic_program_pushScope(program);

    if (!this->_while) {
        ast_Block_toIcBody(this, program, storage, stored);
    } else {
        ast_While_toIc(this->_while, program, storage, stored);
    }

    ic_program_popScope(program);
    return (ic_node)scope;
}

corto_ic_node ast_Block_toIcBody(
    ast_Block this,
    corto_ic_program program,
    corto_ic_storage storage,
    bool stored)
{
    ast_Node statement;
    corto_iter statementIter;
    corto_iter localIter;
    ast_Local local;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    /* Declare locals */
    if (this->locals) {
        localIter = corto_ll_iter(this->locals);
        while(corto_iter_hasNext(&localIter)) {
            local = corto_iter_next(&localIter);
            ic_program_declareVariable(
                    program,
                    local->name,
                    ast_Expression_getType(ast_Expression(local)),
                    ast_Expression(local)->isReference,
                    FALSE,
                    local->kind == Ast_LocalParameter,
                    local->kind == Ast_LocalReturn);
        }

    }

    if (this->statements) {
        statementIter = corto_ll_iter(this->statements);
        while(corto_iter_hasNext(&statementIter)) {
            statement = corto_iter_next(&statementIter);
            ast_Node_toIc(statement, program, NULL, FALSE);
        }

    }

    return NULL;
}
