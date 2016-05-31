/* PrintVisitor.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_PARSER_PRINTVISITOR_H
#define CORTO_PARSER_PRINTVISITOR_H

#include <corto/corto.h>
#include <corto/parser/_interface.h>
#include <corto/parser/_type.h>
#include <corto/parser/_api.h>
#include <corto/parser/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_PARSER_EXPORT corto_int16 _parser_PrintVisitor_construct(
    parser_PrintVisitor _this);
#define parser_PrintVisitor_construct(_this) _parser_PrintVisitor_construct(parser_PrintVisitor(_this))

CORTO_PARSER_EXPORT corto_void _parser_PrintVisitor_destruct(
    parser_PrintVisitor _this);
#define parser_PrintVisitor_destruct(_this) _parser_PrintVisitor_destruct(parser_PrintVisitor(_this))

CORTO_PARSER_EXPORT corto_string _parser_PrintVisitor_getText(
    parser_PrintVisitor _this);
#define parser_PrintVisitor_getText(_this) _parser_PrintVisitor_getText(parser_PrintVisitor(_this))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitBinaryExpressionNode(
    parser_PrintVisitor _this,
    parser_BinaryExpressionNode node);
#define parser_PrintVisitor_visitBinaryExpressionNode(_this, node) _parser_PrintVisitor_visitBinaryExpressionNode(parser_PrintVisitor(_this), parser_BinaryExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitBinaryExpressionNode_v(
    parser_PrintVisitor _this,
    parser_BinaryExpressionNode node);
#define parser_PrintVisitor_visitBinaryExpressionNode_v(_this, node) _parser_PrintVisitor_visitBinaryExpressionNode_v(parser_PrintVisitor(_this), parser_BinaryExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitCommaExpressionNode(
    parser_PrintVisitor _this,
    parser_CommaExpressionNode node);
#define parser_PrintVisitor_visitCommaExpressionNode(_this, node) _parser_PrintVisitor_visitCommaExpressionNode(parser_PrintVisitor(_this), parser_CommaExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitCommaExpressionNode_v(
    parser_PrintVisitor _this,
    parser_CommaExpressionNode node);
#define parser_PrintVisitor_visitCommaExpressionNode_v(_this, node) _parser_PrintVisitor_visitCommaExpressionNode_v(parser_PrintVisitor(_this), parser_CommaExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitConditionalExpressionNode(
    parser_PrintVisitor _this,
    parser_ConditionalExpressionNode node);
#define parser_PrintVisitor_visitConditionalExpressionNode(_this, node) _parser_PrintVisitor_visitConditionalExpressionNode(parser_PrintVisitor(_this), parser_ConditionalExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitConditionalExpressionNode_v(
    parser_PrintVisitor _this,
    parser_ConditionalExpressionNode node);
#define parser_PrintVisitor_visitConditionalExpressionNode_v(_this, node) _parser_PrintVisitor_visitConditionalExpressionNode_v(parser_PrintVisitor(_this), parser_ConditionalExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitExpressionNode(
    parser_PrintVisitor _this,
    parser_ExpressionNode node);
#define parser_PrintVisitor_visitExpressionNode(_this, node) _parser_PrintVisitor_visitExpressionNode(parser_PrintVisitor(_this), parser_ExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitExpressionNode_v(
    parser_PrintVisitor _this,
    parser_ExpressionNode node);
#define parser_PrintVisitor_visitExpressionNode_v(_this, node) _parser_PrintVisitor_visitExpressionNode_v(parser_PrintVisitor(_this), parser_ExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitProgramNode(
    parser_PrintVisitor _this,
    parser_ProgramNode node);
#define parser_PrintVisitor_visitProgramNode(_this, node) _parser_PrintVisitor_visitProgramNode(parser_PrintVisitor(_this), parser_ProgramNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitProgramNode_v(
    parser_PrintVisitor _this,
    parser_ProgramNode node);
#define parser_PrintVisitor_visitProgramNode_v(_this, node) _parser_PrintVisitor_visitProgramNode_v(parser_PrintVisitor(_this), parser_ProgramNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitStatementNode(
    parser_PrintVisitor _this,
    parser_StatementNode node);
#define parser_PrintVisitor_visitStatementNode(_this, node) _parser_PrintVisitor_visitStatementNode(parser_PrintVisitor(_this), parser_StatementNode(node))

CORTO_PARSER_EXPORT corto_object _parser_PrintVisitor_visitStatementNode_v(
    parser_PrintVisitor _this,
    parser_StatementNode node);
#define parser_PrintVisitor_visitStatementNode_v(_this, node) _parser_PrintVisitor_visitStatementNode_v(parser_PrintVisitor(_this), parser_StatementNode(node))

#ifdef __cplusplus
}
#endif
#endif

