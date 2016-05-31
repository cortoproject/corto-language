/* _type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_PARSER__TYPE_H
#define CORTO_PARSER__TYPE_H

#include <corto/corto.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's */
#define parser_Node(o) ((parser_Node)corto_assertType((corto_type)parser_Node_o, o))
#define parser_StatementNode(o) ((parser_StatementNode)corto_assertType((corto_type)parser_StatementNode_o, o))
#define parser_StatementList(o) ((parser_StatementList*)corto_assertType((corto_type)parser_StatementList_o, o))
#define parser_ProgramNode(o) ((parser_ProgramNode)corto_assertType((corto_type)parser_ProgramNode_o, o))
#define parser_BaseParser(o) ((parser_BaseParser)corto_assertType((corto_type)parser_BaseParser_o, o))
#define parser_BaseVisitor(o) ((parser_BaseVisitor)corto_assertType((corto_type)parser_BaseVisitor_o, o))
#define parser_ExpressionNode(o) ((parser_ExpressionNode)corto_assertType((corto_type)parser_ExpressionNode_o, o))
#define parser_BinaryExpressionNode(o) ((parser_BinaryExpressionNode)corto_assertType((corto_type)parser_BinaryExpressionNode_o, o))
#define parser_ExpressionList(o) ((parser_ExpressionList*)corto_assertType((corto_type)parser_ExpressionList_o, o))
#define parser_CommaExpressionNode(o) ((parser_CommaExpressionNode)corto_assertType((corto_type)parser_CommaExpressionNode_o, o))
#define parser_ConditionalExpressionNode(o) ((parser_ConditionalExpressionNode)corto_assertType((corto_type)parser_ConditionalExpressionNode_o, o))
#define parser_ExpressionStatementNode(o) ((parser_ExpressionStatementNode)corto_assertType((corto_type)parser_ExpressionStatementNode_o, o))
#define parser_PrintVisitor(o) ((parser_PrintVisitor)corto_assertType((corto_type)parser_PrintVisitor_o, o))
#define corto_stringList(o) ((corto_stringList*)corto_assertType((corto_type)corto_stringList_o, o))
#define parser_SimpleParser(o) ((parser_SimpleParser)corto_assertType((corto_type)parser_SimpleParser_o, o))

/* Type definitions */
/*  /corto/parser/Node */
CORTO_CLASS(parser_Node);

CORTO_CLASS_DEF(parser_Node) {
    corto_uint32 line;
    corto_uint32 column;
};

/*  /corto/parser/StatementNode */
CORTO_CLASS(parser_StatementNode);

CORTO_CLASS_DEF(parser_StatementNode) {
    CORTO_EXTEND(parser_Node);
};

CORTO_LIST(parser_StatementList);

/*  /corto/parser/ProgramNode */
CORTO_CLASS(parser_ProgramNode);

CORTO_CLASS_DEF(parser_ProgramNode) {
    CORTO_EXTEND(parser_Node);
    parser_StatementList statements;
};

/*  /corto/parser/BaseParser */
CORTO_CLASS(parser_BaseParser);

CORTO_CLASS_DEF(parser_BaseParser) {
    corto_bool success;
    parser_ProgramNode programReturn;
};

/*  /corto/parser/BaseVisitor */
CORTO_CLASS(parser_BaseVisitor);

CORTO_CLASS_DEF(parser_BaseVisitor) {
    parser_BaseParser parser;
};

/*  /corto/parser/ExpressionNode */
CORTO_CLASS(parser_ExpressionNode);

CORTO_CLASS_DEF(parser_ExpressionNode) {
    CORTO_EXTEND(parser_Node);
};

/*  /corto/parser/BinaryExpressionNode */
CORTO_CLASS(parser_BinaryExpressionNode);

CORTO_CLASS_DEF(parser_BinaryExpressionNode) {
    CORTO_EXTEND(parser_ExpressionNode);
    parser_ExpressionNode left;
    corto_string _operator;
    parser_ExpressionNode right;
};

CORTO_LIST(parser_ExpressionList);

/*  /corto/parser/CommaExpressionNode */
CORTO_CLASS(parser_CommaExpressionNode);

CORTO_CLASS_DEF(parser_CommaExpressionNode) {
    CORTO_EXTEND(parser_ExpressionNode);
    parser_ExpressionList expressions;
};

/*  /corto/parser/ConditionalExpressionNode */
CORTO_CLASS(parser_ConditionalExpressionNode);

CORTO_CLASS_DEF(parser_ConditionalExpressionNode) {
    CORTO_EXTEND(parser_ExpressionNode);
    parser_ExpressionNode condition;
    parser_ExpressionNode trueValue;
    parser_ExpressionNode falseValue;
};

/*  /corto/parser/ExpressionStatementNode */
CORTO_CLASS(parser_ExpressionStatementNode);

CORTO_CLASS_DEF(parser_ExpressionStatementNode) {
    CORTO_EXTEND(parser_StatementNode);
    parser_ExpressionNode expression;
};

/*  /corto/parser/PrintVisitor */
CORTO_CLASS(parser_PrintVisitor);

CORTO_CLASS_DEF(parser_PrintVisitor) {
    CORTO_EXTEND(parser_BaseVisitor);
    corto_word buffer;
    corto_uint32 level;
};

CORTO_LIST(corto_stringList);

/*  /corto/parser/SimpleParser */
CORTO_CLASS(parser_SimpleParser);

CORTO_CLASS_DEF(parser_SimpleParser) {
    CORTO_EXTEND(parser_BaseParser);
    corto_stringList errors;
};

#ifdef __cplusplus
}
#endif
#endif

