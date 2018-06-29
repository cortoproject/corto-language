/* $CORTO_GENERATED
 *
 * expr.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/expr/expr.h>

/* $header() */
static corto_int16 corto_expr_getParamName(char *out, char *id) {
    char *ptr, *outPtr = out;

    for (ptr = id; (isalpha(*ptr) || isdigit(*ptr) || (*ptr == '_')); ptr++) {
        *outPtr = *ptr;
        outPtr ++;
    }
    *outPtr = '\0';

    if (outPtr == out) {
        corto_throw("invalid parameter name: %s", id);
        goto error;
    }

    return 0;
error:
    return -1;
}

static corto_int32 corto_expr_addParam(corto_function f, corto_string name) {
    corto_int32 i;
    corto_int32 length = f->parameters.length;
    corto_id param_name = {'_', '\0'};

    if (corto_expr_getParamName(param_name + 1, name)) {
        goto error;
    }

    for (i = 0; i < length; i ++) {
        corto_parameter *p = &f->parameters.buffer[i];
        if (!strcmp(p->name, param_name)) {
            return length;
        }
    }

    f->parameters.buffer =
        corto_realloc(f->parameters.buffer, sizeof(corto_parameter) * (length + 1));
    f->parameters.length ++;

    corto_parameter *p = &f->parameters.buffer[length];
    p->name = corto_strdup(param_name);
    p->type = NULL;
    p->is_reference = FALSE;
    p->inout = CORTO_IN;

    return f->parameters.length;
error:
    return 0;
}

static char* corto_expr_toCortoExpr(corto_function f, char *expr) {
    char *ptr, *result = corto_strdup(expr);
    for (ptr = result; (ptr = strchr(ptr, '%')); ptr++) {
        *ptr = '_';
    }
    return result;
}

static corto_int16 corto_expr_setParamType(corto_parameter *p, corto_string typeId) {
    corto_type type = corto_resolve(NULL, typeId);
    if (!type) {
        corto_throw("unresolved type '%s'", typeId);
        goto error;
    }
    p->type = type;
    return 0;
error:
    return -1;
}

static corto_int16 corto_expr_finalize(corto_expr *out, corto_expr_opt *opt, char *expr, corto_function f) {
    char *cortoExpr;

    if (!(cortoExpr = corto_expr_toCortoExpr(f, expr))) {
        corto_throw("corto: expr: parser error (toCorto) '%s': %s", expr, corto_lasterr());
        goto error;
    }

    if (opt) {
        corto_set_ref(&f->return_type, opt->return_type);
        f->is_reference = opt->is_reference;
    }

    if (ast_Parser_parseFunction(f, cortoExpr, opt ? opt->inverse : FALSE)) {
        corto_throw("corto: expr: failed to parse '%s': %s", cortoExpr, corto_lasterr());
        goto error;
    }

    corto_dealloc(cortoExpr);

    out->function = f;

    return 0;
error:
    return -1;
}

corto_int16 corto_expr_comp(corto_expr *out, corto_expr_opt *opt, char *expr, ...) {
    corto_int32 prev = 0, length;
    char *ptr;
    corto_function f = corto_declare(NULL, NULL, corto_function_o);
    va_list list;

    va_start(list, expr);
    for (ptr = expr; ptr && *ptr && (ptr = strchr(ptr, '%')); ptr ++) {
        if (!(length = corto_expr_addParam(f, ptr + 1))) {
            corto_throw("corto: expr: failed to add parameter for expr '%s': %s", expr, corto_lasterr());
            goto error;
        }

        if (length != prev) {
            corto_parameter *p = &f->parameters.buffer[length - 1];
            if (corto_expr_setParamType(p, va_arg(list, char*))) {
                corto_throw("corto: expr: failed to set parameter type for '%s': %s", expr, corto_lasterr());
                goto error;
            }
            prev = length;
        }
    }
    va_end(list);

    if (corto_expr_finalize(out, opt, expr, f)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_expr_compb(corto_expr *out, corto_expr_opt *opt, char *expr, char **types) {
    corto_int32 prev = 0, length;
    char *ptr;
    corto_function f = corto_declare(NULL, NULL, corto_function_o);

    for (ptr = expr; ptr && *ptr && (ptr = strchr(ptr, '%')); ptr ++) {
        if (!(length = corto_expr_addParam(f, ptr + 1))) {
            corto_throw("corto: expr: failed to add parameter for expr '%s': %s", expr, corto_lasterr());
            goto error;
        }

        if (length != prev) {
            corto_parameter *p = &f->parameters.buffer[length - 1];
            if (corto_expr_setParamType(p, types[length - 1])) {
                corto_throw("corto: expr: failed to set parameter type for '%s': %s", expr, corto_lasterr());
                goto error;
            }
            prev = length;
        }
    }

    if (corto_expr_finalize(out, opt, expr, f)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_expr_run(corto_expr *expr, corto_value *out, ...) {
    va_list args;
    corto_uint64 dummy;
    void *ptr = &dummy;

    va_start(args, out);
    corto_invokev(expr->function, ptr, args);
    va_end(args);

    if (expr->function->is_reference) {
        *out = corto_value_object(*(corto_object*)ptr, NULL);
    } else {
        *out = corto_value_ptr(&out->is.pointer.storage, expr->function->return_type);
        *(corto_uint64*)&out->is.pointer.storage = dummy;
    }

    return 0;
}

corto_int16 corto_expr_runb(corto_expr *expr, corto_value *out, void **args) {
    corto_uint64 dummy;
    void *ptr = &dummy;

    corto_invokeb(expr->function, ptr, args);

    if (expr->function->is_reference) {
        *out = corto_value_object(*(corto_object*)ptr, NULL);
    } else {
        *out = corto_value_ptr(&out->is.pointer.storage, expr->function->return_type);
        *(corto_uint64*)&out->is.pointer.storage = dummy;
    }

    return 0;
}

void corto_expr_free(corto_expr *expr) {
    corto_release(expr->function);
}

/* $end */

int cortomain(int argc, char *argv[]) {
/* $begin(main) */

    /* Insert implementation */

    return 0;
/* $end */
}
