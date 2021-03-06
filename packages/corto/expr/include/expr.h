/* expr.h
 *
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef CORTO_EXPR_H
#define CORTO_EXPR_H

#include <corto/corto.h>
#include <corto/c/c.h>
#include <corto/ast/c/c.h>
#include <corto/ast/ast.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_expr {
    corto_function function;
} corto_expr;

typedef struct corto_expr_opt {
    corto_object scope;
    corto_type return_type;
    corto_bool is_reference;
    corto_bool inverse;
} corto_expr_opt;

corto_int16 corto_expr_comp(corto_expr *out, corto_expr_opt *opt, char *expr, ...);

corto_int16 corto_expr_compb(corto_expr *out, corto_expr_opt *opt, char *expr, char **types);

corto_int16 corto_expr_run(corto_expr *expr, corto_value *out, ...);

corto_int16 corto_expr_runb(corto_expr *expr, corto_value *out, void **args);

void corto_expr_free(corto_expr *expr);

#ifdef __cplusplus
}
#endif

#endif
