/* expr.h
 *
 * This file is generated. Do not modify.
 */

#ifndef CORTO_EXPR_H
#define CORTO_EXPR_H

#include <corto/corto.h>

#include <corto/core/c/c.h>
#include <corto/lang/c/c.h>
#include <corto/ast/ast.h>
/* $header() */

typedef struct corto_expr {
    corto_function function;
} corto_expr;

typedef struct corto_expr_opt {
    corto_object scope;
    corto_type returnType;
    corto_bool returnsReference;
} corto_expr_opt;

corto_int16 corto_expr_comp(corto_expr *out, corto_expr_opt *opt, char *expr, ...);

corto_int16 corto_expr_compb(corto_expr *out, corto_expr_opt *opt, char *expr, char **types);

corto_int16 corto_expr_call(corto_expr *expr, corto_value *out, ...);

corto_int16 corto_expr_callb(corto_expr *expr, corto_value *out, void **args);

void corto_expr_free(corto_expr *expr);

/* $end */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif
