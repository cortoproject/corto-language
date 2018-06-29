/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

ast_Call ast_CallBuilder_buildMethod(ast_CallBuilder *this) {
    ast_Call result = NULL;
    corto_member m;
    corto_function f;
    corto_type t = ast_Expression_getType(this->instance);

    /* First try to resolve a member with a delegate type */
    if (t->kind == CORTO_COMPOSITE) {
        m = corto_interface_resolve_member(corto_interface(t), this->name);
        if (m) {
            ast_String nameExpr = ast_String__create(NULL, NULL, this->name);
            ast_Parser_collect(yparser(), nameExpr);
            if ((m->type->kind == CORTO_COMPOSITE) && (corto_interface(m->type)->kind == CORTO_DELEGATE)) {
                ast_Expression fExpr = ast_Expression(ast_Member__create(NULL, NULL, this->instance, ast_Expression(nameExpr)));
                if (!fExpr) {
                    goto error;
                }
                result = ast_Call(ast_DelegateCall__create(NULL, NULL, NULL, this->arguments, fExpr));
            }
        }
    }

    /* Resolve procedure in interface */
    if (!result) {
        f = corto_function(corto_type_resolve_procedure(t, this->signature));
        if (!f) {
            if (!result) {
                corto_id id;
                ast_Parser_error(yparser(), "no procedure with signature '%s' found in type '%s'",
                    this->signature,
                    ast_Parser_id(t, id));
                goto error;
            }
        }

        /* If function is a metaprocedure, validate whether the instance pointer should be a refernce */
        if (corto_instanceof(corto_metaprocedure_o, f)) {
            if (corto_metaprocedure(f)->referenceOnly && !this->instance->isReference) {
                ast_Parser_error(yparser(), "can only call %s on objects", corto_idof(f));
                goto error;
            }
        }

        /* Create call-expression */
        result = ast_Call(ast_StaticCall__create(NULL, NULL, this->instance, this->arguments, f));
    }

    return result;
error:
    return NULL;
}


ast_Call ast_CallBuilder_build(
    ast_CallBuilder* this)
{
    ast_Call result = NULL;

    /* Obtain signature */
    if (ast_CallBuilder_buildSignature(this)) {
        goto error;
    }

    /* If instance is explicitly set call must be a named callable (method, metaprocedure) */
    if (this->instance) {
        result = ast_CallBuilder_buildMethod(this);
    } else {
        /* If block is set, test for callable variables */
        if (this->block) {
            ast_Local l = ast_Block_resolveLocal(this->block, this->name);
            if (l) {
                /* Check if l is of a delegate type */
                if ((l->type->kind == CORTO_COMPOSITE) && (corto_interface(l->type)->kind == CORTO_DELEGATE)) {
                    result = ast_Call(ast_DelegateCall__create(NULL, NULL, NULL, this->arguments, ast_Expression(l)));
                    if (!result) {
                        goto error;
                    }
                }

            /* If no local is found and block has this-local, try the corresponding interface */
            } else if ((l = ast_Block_resolveLocal(this->block, "this"))) {
                if (corto_type_resolve_procedure(l->type, this->signature)) {
                    /* Set instance to 'this' */
                    corto_set_ref(&this->instance, l);
                    result = ast_CallBuilder_buildMethod(this);
                }
            }
        }

        /* If function is not found (implicitly) in interface or in block, look in scope */
        if (!result) {
            corto_object f = corto_resolve(this->scope, this->signature);
            if (!f) {
                corto_id id;
                ast_Parser_error(yparser(), "no procedure found with signature '%s' in scope '%s'",
                    this->signature,
                    ast_Parser_id(this->scope, id));
                goto error;
            }
            if ((corto_typeof(f)->kind == CORTO_COMPOSITE) && (corto_interface(corto_typeof(f))->kind == CORTO_DELEGATE)) {
                ast_Expression fExpr = ast_Expression(ast_Object__create(NULL, NULL, f));
                result = ast_Call(ast_DelegateCall__create(NULL, NULL, NULL, this->arguments, fExpr));
            } else {
                if (corto_function(f)->overloaded) {
                    /* If function is overloaded, re-resolve with explicit reference requests in signature */
                    this->overloaded = TRUE;
                    if (ast_CallBuilder_buildSignature(this)) {
                        goto error;
                    }
                    corto_release(f);
                    f = corto_resolve(this->scope, this->signature);
                }
                result = ast_Call(ast_StaticCall__create(NULL, NULL, NULL, this->arguments, f));
            }
        }
    }

    return result;
error:
    return NULL;
}

int16_t ast_CallBuilder_buildSignature(
    ast_CallBuilder* this)
{
    corto_string signature;
    corto_iter argumentIter;
    ast_Expression argument;
    corto_type argumentType;

    if (!strchr(this->name, '(')) {
        /* Build request-signature */
        signature = corto_sig_open(this->name);

        if (this->arguments) {
            corto_ll arguments = ast_Expression_toList(this->arguments);
            argumentIter = corto_ll_iter(arguments);
            while(corto_iter_hasNext(&argumentIter)) {
                int flags = 0;
                argument = corto_iter_next(&argumentIter);
                argumentType = ast_Expression_narrowType(argument);

                /* If there is no type and the argument is an initializer, insert a wildcard */
                if (!argumentType && (ast_Node(argument)->kind == Ast_InitializerExpr)) {
                    flags |= CORTO_PARAMETER_WILDCARD;
                }

                /* If the argument is an UnresolvedReference, add a wildcard */
                if (ast_Expression(argument)->unresolved) {
                    argumentType = NULL;
                    flags |= CORTO_PARAMETER_WILDCARD;
                }

                flags |= argument->isReference ? CORTO_PARAMETER_REFERENCE : 0;
                flags |= (argument->deref == Ast_ByReference) ? CORTO_PARAMETER_FORCEREFERENCE : 0;
                signature = corto_sig_add(signature, corto_type(argumentType), flags);
            }
            ast_Expression_cleanList(arguments);
        }

        /* Store signature for when a method needs to be resolved at runtime */
        this->signature = corto_sig_close(signature);
    } else {
        this->signature = corto_strdup(this->name);
    }

    return 0;
}
