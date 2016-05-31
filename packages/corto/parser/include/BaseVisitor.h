/* BaseVisitor.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_PARSER_BASEVISITOR_H
#define CORTO_PARSER_BASEVISITOR_H

#include <corto/corto.h>
#include <corto/parser/_interface.h>
#include <corto/parser/_type.h>
#include <corto/parser/_api.h>
#include <corto/parser/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_PARSER_EXPORT corto_int16 _parser_BaseVisitor_construct(
    parser_BaseVisitor _this);
#define parser_BaseVisitor_construct(_this) _parser_BaseVisitor_construct(parser_BaseVisitor(_this))

CORTO_PARSER_EXPORT corto_void _parser_BaseVisitor_destruct(
    parser_BaseVisitor _this);
#define parser_BaseVisitor_destruct(_this) _parser_BaseVisitor_destruct(parser_BaseVisitor(_this))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visit(
    parser_BaseVisitor _this);
#define parser_BaseVisitor_visit(_this) _parser_BaseVisitor_visit(parser_BaseVisitor(_this))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visit_v(
    parser_BaseVisitor _this);
#define parser_BaseVisitor_visit_v(_this) _parser_BaseVisitor_visit_v(parser_BaseVisitor(_this))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitBinaryExpressionNode(
    parser_BaseVisitor _this,
    parser_BinaryExpressionNode node);
#define parser_BaseVisitor_visitBinaryExpressionNode(_this, node) _parser_BaseVisitor_visitBinaryExpressionNode(parser_BaseVisitor(_this), parser_BinaryExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitBinaryExpressionNode_v(
    parser_BaseVisitor _this,
    parser_BinaryExpressionNode node);
#define parser_BaseVisitor_visitBinaryExpressionNode_v(_this, node) _parser_BaseVisitor_visitBinaryExpressionNode_v(parser_BaseVisitor(_this), parser_BinaryExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitCommaExpressionNode(
    parser_BaseVisitor _this,
    parser_CommaExpressionNode node);
#define parser_BaseVisitor_visitCommaExpressionNode(_this, node) _parser_BaseVisitor_visitCommaExpressionNode(parser_BaseVisitor(_this), parser_CommaExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitCommaExpressionNode_v(
    parser_BaseVisitor _this,
    parser_CommaExpressionNode node);
#define parser_BaseVisitor_visitCommaExpressionNode_v(_this, node) _parser_BaseVisitor_visitCommaExpressionNode_v(parser_BaseVisitor(_this), parser_CommaExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitConditionalExpressionNode(
    parser_BaseVisitor _this,
    parser_ConditionalExpressionNode node);
#define parser_BaseVisitor_visitConditionalExpressionNode(_this, node) _parser_BaseVisitor_visitConditionalExpressionNode(parser_BaseVisitor(_this), parser_ConditionalExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitConditionalExpressionNode_v(
    parser_BaseVisitor _this,
    parser_ConditionalExpressionNode node);
#define parser_BaseVisitor_visitConditionalExpressionNode_v(_this, node) _parser_BaseVisitor_visitConditionalExpressionNode_v(parser_BaseVisitor(_this), parser_ConditionalExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitExpressionNode(
    parser_BaseVisitor _this,
    parser_ExpressionNode node);
#define parser_BaseVisitor_visitExpressionNode(_this, node) _parser_BaseVisitor_visitExpressionNode(parser_BaseVisitor(_this), parser_ExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitExpressionNode_v(
    parser_BaseVisitor _this,
    parser_ExpressionNode node);
#define parser_BaseVisitor_visitExpressionNode_v(_this, node) _parser_BaseVisitor_visitExpressionNode_v(parser_BaseVisitor(_this), parser_ExpressionNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitExpressionStatementNode(
    parser_BaseVisitor _this,
    parser_ExpressionStatementNode node);
#define parser_BaseVisitor_visitExpressionStatementNode(_this, node) _parser_BaseVisitor_visitExpressionStatementNode(parser_BaseVisitor(_this), parser_ExpressionStatementNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitExpressionStatementNode_v(
    parser_BaseVisitor _this,
    parser_ExpressionStatementNode node);
#define parser_BaseVisitor_visitExpressionStatementNode_v(_this, node) _parser_BaseVisitor_visitExpressionStatementNode_v(parser_BaseVisitor(_this), parser_ExpressionStatementNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitProgramNode(
    parser_BaseVisitor _this,
    parser_ProgramNode node);
#define parser_BaseVisitor_visitProgramNode(_this, node) _parser_BaseVisitor_visitProgramNode(parser_BaseVisitor(_this), parser_ProgramNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitProgramNode_v(
    parser_BaseVisitor _this,
    parser_ProgramNode node);
#define parser_BaseVisitor_visitProgramNode_v(_this, node) _parser_BaseVisitor_visitProgramNode_v(parser_BaseVisitor(_this), parser_ProgramNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitStatementNode(
    parser_BaseVisitor _this,
    parser_StatementNode node);
#define parser_BaseVisitor_visitStatementNode(_this, node) _parser_BaseVisitor_visitStatementNode(parser_BaseVisitor(_this), parser_StatementNode(node))

CORTO_PARSER_EXPORT corto_object _parser_BaseVisitor_visitStatementNode_v(
    parser_BaseVisitor _this,
    parser_StatementNode node);
#define parser_BaseVisitor_visitStatementNode_v(_this, node) _parser_BaseVisitor_visitStatementNode_v(parser_BaseVisitor(_this), parser_StatementNode(node))

#ifdef __cplusplus
}
#endif
#endif

