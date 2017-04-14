/* ast.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_AST_H
#define CORTO_AST_H

#include <corto/corto.h>
#include <corto/corto.h>
#include <corto/ast/_project.h>
#include <corto/c/c.h>
#include <corto/ic/ic.h>

/* $header() */
/* Enter additional code here. */
/* $end */

#include <corto/ast/_type.h>
#include <corto/ast/_load.h>
#include <corto/ast/c/_api.h>

/* $body() */
CORTO_AST_EXPORT
int ast_loadFile(corto_string file, int argc, char* argv[]);
/* $end */

#ifdef __cplusplus
extern "C" {
#endif

#define ast_isOperatorAssignment(_operator) _ast_isOperatorAssignment(_operator)
CORTO_AST_EXPORT
corto_bool _ast_isOperatorAssignment(
    corto_operatorKind _operator);

#define ast_report(kind, filename, line, column, error, token) _ast_report(kind, filename, line, column, error, token)
CORTO_AST_EXPORT
corto_void _ast_report(
    corto_string kind,
    corto_string filename,
    corto_uint32 line,
    corto_uint32 column,
    corto_string error,
    corto_string token);

#define ast_reportError(filename, line, column, error, token) _ast_reportError(filename, line, column, error, token)
CORTO_AST_EXPORT
corto_void _ast_reportError(
    corto_string filename,
    corto_uint32 line,
    corto_uint32 column,
    corto_string error,
    corto_string token);

#define ast_reportWarning(filename, line, column, error, token) _ast_reportWarning(filename, line, column, error, token)
CORTO_AST_EXPORT
corto_void _ast_reportWarning(
    corto_string filename,
    corto_uint32 line,
    corto_uint32 column,
    corto_string error,
    corto_string token);

#define ast_valueKindFromType(type) _ast_valueKindFromType(corto_type(type))
CORTO_AST_EXPORT
ast_valueKind _ast_valueKindFromType(
    corto_type type);

#include <corto/ast/Binary.h>
#include <corto/ast/Binding.h>
#include <corto/ast/Block.h>
#include <corto/ast/Boolean.h>
#include <corto/ast/Call.h>
#include <corto/ast/CallBuilder.h>
#include <corto/ast/Cast.h>
#include <corto/ast/Character.h>
#include <corto/ast/Comma.h>
#include <corto/ast/Define.h>
#include <corto/ast/Deinit.h>
#include <corto/ast/DelegateCall.h>
#include <corto/ast/DynamicInitializer.h>
#include <corto/ast/DynamicInitializerFrame.h>
#include <corto/ast/Element.h>
#include <corto/ast/Expression.h>
#include <corto/ast/FloatingPoint.h>
#include <corto/ast/If.h>
#include <corto/ast/Init.h>
#include <corto/ast/Initializer.h>
#include <corto/ast/InitializerExpression.h>
#include <corto/ast/InitializerFrame.h>
#include <corto/ast/InitializerVariable.h>
#include <corto/ast/InitOper.h>
#include <corto/ast/Integer.h>
#include <corto/ast/Literal.h>
#include <corto/ast/Local.h>
#include <corto/ast/Lvalue.h>
#include <corto/ast/Member.h>
#include <corto/ast/New.h>
#include <corto/ast/Node.h>
#include <corto/ast/Null.h>
#include <corto/ast/Object.h>
#include <corto/ast/Parser.h>
#include <corto/ast/ParserDeclaration.h>
#include <corto/ast/ParserNew.h>
#include <corto/ast/PostFix.h>
#include <corto/ast/SignedInteger.h>
#include <corto/ast/StaticCall.h>
#include <corto/ast/StaticInitializer.h>
#include <corto/ast/StaticInitializerFrame.h>
#include <corto/ast/Storage.h>
#include <corto/ast/String.h>
#include <corto/ast/Template.h>
#include <corto/ast/Temporary.h>
#include <corto/ast/Ternary.h>
#include <corto/ast/Unary.h>
#include <corto/ast/UnresolvedReference.h>
#include <corto/ast/Update.h>
#include <corto/ast/While.h>

#ifdef __cplusplus
}
#endif

#endif

