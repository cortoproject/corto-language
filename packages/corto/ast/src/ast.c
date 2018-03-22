/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>
#include "ast__private.h"
corto_tls ast_PARSER_KEY;
/* Run a corto file */
int ast_loadFile(corto_string file, int argc, char* argv[]) {
    corto_char* source;
    ast_Parser p;
    corto_int32 i;
    corto_stringSeq seq;

    seq.buffer = corto_alloc(argc * sizeof(corto_string));
    seq.length = argc;
    for (i = 0; i < argc; i++) {
        seq.buffer[i] = argv[i];
    }

    source = corto_file_load(file);
    if (source) {
        /* Create parser */
        p = ast_Parser__create(NULL, NULL, source, file);
        if (!p) {
            corto_throw("failed to create parser for '%s'", file);
            goto error;
        }

        /* Parse & run script */
        ast_Parser_parse(p, seq);
        if (p->errors) {
            corto_throw("found %d errors", p->errors);
            goto error;
        }

        corto_release(p);
        corto_dealloc(source);
    } else {
        goto error;
    }

    corto_dealloc(seq.buffer);
    return 0;
error:
    return -1;
}

/* Create a call-expression */
ast_Call ast_createCallWithArguments(ast_Expression instance, corto_string function, ast_Expression arguments) {
    ast_Call result;
    ast_CallBuilder builder;

    /* Initialize builder */
    corto_ptr_init(&builder, ast_CallBuilder_o);
    ast_CallBuilder__assign(&builder,
        function,
        arguments,
        instance,
        yparser()->scope,
        yparser()->block);
    result = ast_CallBuilder_build(&builder);
    corto_ptr_deinit(&builder, ast_CallBuilder_o);

    return result;
}

/* Create a call-expression */
ast_Call ast_createCall(ast_Expression instance, corto_string function, corto_uint32 numArgs, ...) {
    ast_Expression args = NULL, arg = NULL;
    va_list arglist;
    corto_uint32 i;

    /* Create comma-expression if there is more than one argument */
    va_start(arglist, numArgs);
    if (numArgs > 1) {
        args = ast_Expression(ast_Comma__create(NULL, NULL));
        for(i=0; i<numArgs; i++) {
            arg = va_arg(arglist, ast_Expression);
            ast_Comma_addExpression(ast_Comma(args), arg);
        }

    } else if (numArgs) {
        args = va_arg(arglist, ast_Expression);
    }

    va_end(arglist);
    if (args) {
        ast_Parser_collect(yparser(), args);
    }

    return ast_createCallWithArguments(instance, function, args);
}

ast_Call ast_createCallFromExpr(ast_Expression f, ast_Expression arguments) {
    ast_Call result = NULL;
    ast_Expression instance = NULL;
    corto_id name;
    corto_object scope = yparser()->scope;
    ast_CallBuilder builder;

    if (ast_Node(f)->kind == Ast_StorageExpr) {
        switch(ast_Storage(f)->kind) {

        case Ast_ObjectStorage: {
            corto_object o = ast_Object(f)->value;
            corto_sig_name(corto_idof(o), name);
            scope = corto_parentof(o);
            break;
        }

        case Ast_LocalStorage:
            strcpy(name, ast_Local(f)->name);
            break;
        case Ast_MemberStorage:
            instance = ast_Member(f)->lvalue;
            strcpy(name, ast_String(ast_Member(f)->rvalue)->value);
            break;
        case Ast_ElementStorage:
            result = ast_Call(ast_DelegateCall__create(NULL, NULL, NULL, arguments, f));
            break;
        case Ast_UnresolvedReferenceStorage:
            /* No use in trying to resolve the unresolved identifier here, there
             * is no additional information available that could help resolving
             * the identifier */
            safe_ast_UnresolvedReference_error(f);
            goto error;
        default:
            ast_Parser_error(yparser(), "'%s' expression is not callable",
                corto_idof(corto_enum_constant_from_value(ast_storageKind_o, ast_Storage(f)->kind)));
            goto error;
        }

    }

    if (!result) {
        corto_ptr_init(&builder, ast_CallBuilder_o);
        ast_CallBuilder__assign(&builder, name, arguments, instance, scope, yparser()->block);
        result = ast_CallBuilder_build(&builder);
        corto_ptr_deinit(&builder, ast_CallBuilder_o);
    }

    return result;
error:
    return NULL;
}

bool ast_isOperatorAssignment(
    corto_operatorKind _operator)
{
    corto_bool result;
    switch(_operator) {
    case CORTO_ASSIGN:
    case CORTO_ASSIGN_ADD:
    case CORTO_ASSIGN_SUB:
    case CORTO_ASSIGN_DIV:
    case CORTO_ASSIGN_MUL:
    case CORTO_ASSIGN_MOD:
    case CORTO_ASSIGN_OR:
    case CORTO_ASSIGN_AND:
        result = TRUE;
        break;
    default:
        result = FALSE;
        break;
    }

    return result;
}

void ast_report(
    const char *kind,
    const char *filename,
    uint32_t line,
    uint32_t column,
    const char *error,
    const char *token)
{
    CORTO_UNUSED(token);
    CORTO_UNUSED(kind);

    if (yparser()->repl) {
        if (!yparser()->errors) {
            corto_throw("%d: %s", column, error);
        }

    } else if(filename) {
        corto_error("%s:%d:%d: %s", filename, line, column, error);
    } else {
        corto_error("%d:%d: %s", line, column, error);
    }

}

void ast_reportError(
    const char *filename,
    uint32_t line,
    uint32_t column,
    const char *error,
    const char *token)
{

    ast_report("error", filename, line, column, error, token);

}

void ast_reportWarning(
    const char *filename,
    uint32_t line,
    uint32_t column,
    const char *error,
    const char *token)
{

    ast_report("warning", filename, line, column, error, token);

}

ast_valueKind ast_valueKindFromType(
    corto_type type)
{
    ast_valueKind result = Ast_Nothing;

    if (type->reference) {
        result = Ast_Ref;
    } else {
        if (type->kind != CORTO_PRIMITIVE) {
            /* Exception to common error-reporting pattern: calling functions need to throw an error. The
             * rationale is that at this level there is little information available to report a meaningful
             * error. */
            goto error;
        }

        switch(corto_primitive(type)->kind) {
        case CORTO_BOOLEAN:
            result = Ast_Bool;
            break;
        case CORTO_CHARACTER:
            result = Ast_Char;
            break;
        case CORTO_INTEGER:
            result = Ast_SignedInt;
            break;
        case CORTO_BINARY:
        case CORTO_UINTEGER:
            result = Ast_Int;
            break;
        case CORTO_FLOAT:
            result = Ast_Float;
            break;
        case CORTO_TEXT:
            result = Ast_Text;
            break;
        case CORTO_ENUM:
        case CORTO_BITMASK:
            result = Ast_Enum;
            break;
        }

    }

    return result;
error:
    return Ast_Nothing;
}

int cortomain(int argc, char *argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    if (corto_tls_new(&ast_PARSER_KEY, NULL)) {
        return -1;
    }

    return 0;
}

