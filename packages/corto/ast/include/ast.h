/* ast.h
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef CORTO_AST_H
#define CORTO_AST_H

#include <corto/corto.h>
#include <corto/ast/_project.h>
#include <corto/ic/c/c.h>
#include <corto/c/c.h>
#include <corto/ic/ic.h>

/* $header() */
/* Enter additional code here. */
/* $end */

#include <corto/ast/_type.h>
#include <corto/ast/_interface.h>
#include <corto/ast/_load.h>
#include <corto/ast/_binding.h>
#include <corto/ast/c/_api.h>

/* $body() */
CORTO_AST_EXPORT
int ast_loadFile(corto_string file, int argc, char* argv[]);
/* $end */

#endif

