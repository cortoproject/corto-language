/* _api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_PARSER__API_H
#define CORTO_PARSER__API_H

#include <corto/corto.h>
#include <corto/parser/_interface.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /corto/parser/BaseParser */
CORTO_PARSER_EXPORT parser_BaseParser _parser_BaseParserCreate(void);
#define parser_BaseParserCreate() _parser_BaseParserCreate()
#define parser_BaseParserCreate_auto(_name) parser_BaseParser _name = parser_BaseParserCreate(); (void)_name
CORTO_PARSER_EXPORT parser_BaseParser _parser_BaseParserCreateChild(corto_object _parent, corto_string _name);
#define parser_BaseParserCreateChild(_parent, _name) _parser_BaseParserCreateChild(_parent, _name)
#define parser_BaseParserCreateChild_auto(_parent, _name) parser_BaseParser _name = parser_BaseParserCreateChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_BaseParserUpdate(parser_BaseParser _this);
#define parser_BaseParserUpdate(_this) _parser_BaseParserUpdate(parser_BaseParser(_this))

CORTO_PARSER_EXPORT parser_BaseParser _parser_BaseParserDeclare(void);
#define parser_BaseParserDeclare() _parser_BaseParserDeclare()
#define parser_BaseParserDeclare_auto(_name) parser_BaseParser _name = parser_BaseParserDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_BaseParser _parser_BaseParserDeclareChild(corto_object _parent, corto_string _name);
#define parser_BaseParserDeclareChild(_parent, _name) _parser_BaseParserDeclareChild(_parent, _name)
#define parser_BaseParserDeclareChild_auto(_parent, _name) parser_BaseParser _name = parser_BaseParserDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_BaseParserDefine(parser_BaseParser _this);
#define parser_BaseParserDefine(_this) _parser_BaseParserDefine(parser_BaseParser(_this))
CORTO_PARSER_EXPORT void _parser_BaseParserSet(parser_BaseParser _this);
#define parser_BaseParserSet(_this) _parser_BaseParserSet(parser_BaseParser(_this))
CORTO_PARSER_EXPORT corto_string _parser_BaseParserStr(parser_BaseParser value);
#define parser_BaseParserStr(value) _parser_BaseParserStr(parser_BaseParser(value))
CORTO_PARSER_EXPORT parser_BaseParser parser_BaseParserFromStr(parser_BaseParser value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_BaseParserCompare(parser_BaseParser dst, parser_BaseParser src);
#define parser_BaseParserCompare(dst, src) _parser_BaseParserCompare(parser_BaseParser(dst), parser_BaseParser(src))

/* /corto/parser/BaseVisitor */
CORTO_PARSER_EXPORT parser_BaseVisitor _parser_BaseVisitorCreate(parser_BaseParser parser);
#define parser_BaseVisitorCreate(parser) _parser_BaseVisitorCreate(parser_BaseParser(parser))
#define parser_BaseVisitorCreate_auto(_name, parser) parser_BaseVisitor _name = parser_BaseVisitorCreate(parser); (void)_name
CORTO_PARSER_EXPORT parser_BaseVisitor _parser_BaseVisitorCreateChild(corto_object _parent, corto_string _name, parser_BaseParser parser);
#define parser_BaseVisitorCreateChild(_parent, _name, parser) _parser_BaseVisitorCreateChild(_parent, _name, parser_BaseParser(parser))
#define parser_BaseVisitorCreateChild_auto(_parent, _name, parser) parser_BaseVisitor _name = parser_BaseVisitorCreateChild(_parent, #_name, parser); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_BaseVisitorUpdate(parser_BaseVisitor _this, parser_BaseParser parser);
#define parser_BaseVisitorUpdate(_this, parser) _parser_BaseVisitorUpdate(parser_BaseVisitor(_this), parser_BaseParser(parser))

CORTO_PARSER_EXPORT parser_BaseVisitor _parser_BaseVisitorDeclare(void);
#define parser_BaseVisitorDeclare() _parser_BaseVisitorDeclare()
#define parser_BaseVisitorDeclare_auto(_name) parser_BaseVisitor _name = parser_BaseVisitorDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_BaseVisitor _parser_BaseVisitorDeclareChild(corto_object _parent, corto_string _name);
#define parser_BaseVisitorDeclareChild(_parent, _name) _parser_BaseVisitorDeclareChild(_parent, _name)
#define parser_BaseVisitorDeclareChild_auto(_parent, _name) parser_BaseVisitor _name = parser_BaseVisitorDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_BaseVisitorDefine(parser_BaseVisitor _this, parser_BaseParser parser);
#define parser_BaseVisitorDefine(_this, parser) _parser_BaseVisitorDefine(parser_BaseVisitor(_this), parser_BaseParser(parser))
CORTO_PARSER_EXPORT void _parser_BaseVisitorSet(parser_BaseVisitor _this, parser_BaseParser parser);
#define parser_BaseVisitorSet(_this, parser) _parser_BaseVisitorSet(parser_BaseVisitor(_this), parser_BaseParser(parser))
CORTO_PARSER_EXPORT corto_string _parser_BaseVisitorStr(parser_BaseVisitor value);
#define parser_BaseVisitorStr(value) _parser_BaseVisitorStr(parser_BaseVisitor(value))
CORTO_PARSER_EXPORT parser_BaseVisitor parser_BaseVisitorFromStr(parser_BaseVisitor value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_BaseVisitorCompare(parser_BaseVisitor dst, parser_BaseVisitor src);
#define parser_BaseVisitorCompare(dst, src) _parser_BaseVisitorCompare(parser_BaseVisitor(dst), parser_BaseVisitor(src))

/* /corto/parser/BinaryExpressionNode */
CORTO_PARSER_EXPORT parser_BinaryExpressionNode _parser_BinaryExpressionNodeCreate(corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right);
#define parser_BinaryExpressionNodeCreate(line, column, left, _operator, right) _parser_BinaryExpressionNodeCreate(line, column, parser_ExpressionNode(left), _operator, parser_ExpressionNode(right))
#define parser_BinaryExpressionNodeCreate_auto(_name, line, column, left, _operator, right) parser_BinaryExpressionNode _name = parser_BinaryExpressionNodeCreate(line, column, left, _operator, right); (void)_name
CORTO_PARSER_EXPORT parser_BinaryExpressionNode _parser_BinaryExpressionNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right);
#define parser_BinaryExpressionNodeCreateChild(_parent, _name, line, column, left, _operator, right) _parser_BinaryExpressionNodeCreateChild(_parent, _name, line, column, parser_ExpressionNode(left), _operator, parser_ExpressionNode(right))
#define parser_BinaryExpressionNodeCreateChild_auto(_parent, _name, line, column, left, _operator, right) parser_BinaryExpressionNode _name = parser_BinaryExpressionNodeCreateChild(_parent, #_name, line, column, left, _operator, right); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_BinaryExpressionNodeUpdate(parser_BinaryExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right);
#define parser_BinaryExpressionNodeUpdate(_this, line, column, left, _operator, right) _parser_BinaryExpressionNodeUpdate(parser_BinaryExpressionNode(_this), line, column, parser_ExpressionNode(left), _operator, parser_ExpressionNode(right))

CORTO_PARSER_EXPORT parser_BinaryExpressionNode _parser_BinaryExpressionNodeDeclare(void);
#define parser_BinaryExpressionNodeDeclare() _parser_BinaryExpressionNodeDeclare()
#define parser_BinaryExpressionNodeDeclare_auto(_name) parser_BinaryExpressionNode _name = parser_BinaryExpressionNodeDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_BinaryExpressionNode _parser_BinaryExpressionNodeDeclareChild(corto_object _parent, corto_string _name);
#define parser_BinaryExpressionNodeDeclareChild(_parent, _name) _parser_BinaryExpressionNodeDeclareChild(_parent, _name)
#define parser_BinaryExpressionNodeDeclareChild_auto(_parent, _name) parser_BinaryExpressionNode _name = parser_BinaryExpressionNodeDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_BinaryExpressionNodeDefine(parser_BinaryExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right);
#define parser_BinaryExpressionNodeDefine(_this, line, column, left, _operator, right) _parser_BinaryExpressionNodeDefine(parser_BinaryExpressionNode(_this), line, column, parser_ExpressionNode(left), _operator, parser_ExpressionNode(right))
CORTO_PARSER_EXPORT void _parser_BinaryExpressionNodeSet(parser_BinaryExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right);
#define parser_BinaryExpressionNodeSet(_this, line, column, left, _operator, right) _parser_BinaryExpressionNodeSet(parser_BinaryExpressionNode(_this), line, column, parser_ExpressionNode(left), _operator, parser_ExpressionNode(right))
CORTO_PARSER_EXPORT corto_string _parser_BinaryExpressionNodeStr(parser_BinaryExpressionNode value);
#define parser_BinaryExpressionNodeStr(value) _parser_BinaryExpressionNodeStr(parser_BinaryExpressionNode(value))
CORTO_PARSER_EXPORT parser_BinaryExpressionNode parser_BinaryExpressionNodeFromStr(parser_BinaryExpressionNode value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_BinaryExpressionNodeCompare(parser_BinaryExpressionNode dst, parser_BinaryExpressionNode src);
#define parser_BinaryExpressionNodeCompare(dst, src) _parser_BinaryExpressionNodeCompare(parser_BinaryExpressionNode(dst), parser_BinaryExpressionNode(src))

/* /corto/parser/CommaExpressionNode */
CORTO_PARSER_EXPORT parser_CommaExpressionNode _parser_CommaExpressionNodeCreate(corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions);
#define parser_CommaExpressionNodeCreate(line, column, expressions) _parser_CommaExpressionNodeCreate(line, column, expressions)
#define parser_CommaExpressionNodeCreate_auto(_name, line, column, expressions) parser_CommaExpressionNode _name = parser_CommaExpressionNodeCreate(line, column, expressions); (void)_name
CORTO_PARSER_EXPORT parser_CommaExpressionNode _parser_CommaExpressionNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions);
#define parser_CommaExpressionNodeCreateChild(_parent, _name, line, column, expressions) _parser_CommaExpressionNodeCreateChild(_parent, _name, line, column, expressions)
#define parser_CommaExpressionNodeCreateChild_auto(_parent, _name, line, column, expressions) parser_CommaExpressionNode _name = parser_CommaExpressionNodeCreateChild(_parent, #_name, line, column, expressions); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_CommaExpressionNodeUpdate(parser_CommaExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions);
#define parser_CommaExpressionNodeUpdate(_this, line, column, expressions) _parser_CommaExpressionNodeUpdate(parser_CommaExpressionNode(_this), line, column, expressions)

CORTO_PARSER_EXPORT parser_CommaExpressionNode _parser_CommaExpressionNodeDeclare(void);
#define parser_CommaExpressionNodeDeclare() _parser_CommaExpressionNodeDeclare()
#define parser_CommaExpressionNodeDeclare_auto(_name) parser_CommaExpressionNode _name = parser_CommaExpressionNodeDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_CommaExpressionNode _parser_CommaExpressionNodeDeclareChild(corto_object _parent, corto_string _name);
#define parser_CommaExpressionNodeDeclareChild(_parent, _name) _parser_CommaExpressionNodeDeclareChild(_parent, _name)
#define parser_CommaExpressionNodeDeclareChild_auto(_parent, _name) parser_CommaExpressionNode _name = parser_CommaExpressionNodeDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_CommaExpressionNodeDefine(parser_CommaExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions);
#define parser_CommaExpressionNodeDefine(_this, line, column, expressions) _parser_CommaExpressionNodeDefine(parser_CommaExpressionNode(_this), line, column, expressions)
CORTO_PARSER_EXPORT void _parser_CommaExpressionNodeSet(parser_CommaExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions);
#define parser_CommaExpressionNodeSet(_this, line, column, expressions) _parser_CommaExpressionNodeSet(parser_CommaExpressionNode(_this), line, column, expressions)
CORTO_PARSER_EXPORT corto_string _parser_CommaExpressionNodeStr(parser_CommaExpressionNode value);
#define parser_CommaExpressionNodeStr(value) _parser_CommaExpressionNodeStr(parser_CommaExpressionNode(value))
CORTO_PARSER_EXPORT parser_CommaExpressionNode parser_CommaExpressionNodeFromStr(parser_CommaExpressionNode value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_CommaExpressionNodeCompare(parser_CommaExpressionNode dst, parser_CommaExpressionNode src);
#define parser_CommaExpressionNodeCompare(dst, src) _parser_CommaExpressionNodeCompare(parser_CommaExpressionNode(dst), parser_CommaExpressionNode(src))

/* /corto/parser/ConditionalExpressionNode */
CORTO_PARSER_EXPORT parser_ConditionalExpressionNode _parser_ConditionalExpressionNodeCreate(corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue);
#define parser_ConditionalExpressionNodeCreate(line, column, condition, trueValue, falseValue) _parser_ConditionalExpressionNodeCreate(line, column, parser_ExpressionNode(condition), parser_ExpressionNode(trueValue), parser_ExpressionNode(falseValue))
#define parser_ConditionalExpressionNodeCreate_auto(_name, line, column, condition, trueValue, falseValue) parser_ConditionalExpressionNode _name = parser_ConditionalExpressionNodeCreate(line, column, condition, trueValue, falseValue); (void)_name
CORTO_PARSER_EXPORT parser_ConditionalExpressionNode _parser_ConditionalExpressionNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue);
#define parser_ConditionalExpressionNodeCreateChild(_parent, _name, line, column, condition, trueValue, falseValue) _parser_ConditionalExpressionNodeCreateChild(_parent, _name, line, column, parser_ExpressionNode(condition), parser_ExpressionNode(trueValue), parser_ExpressionNode(falseValue))
#define parser_ConditionalExpressionNodeCreateChild_auto(_parent, _name, line, column, condition, trueValue, falseValue) parser_ConditionalExpressionNode _name = parser_ConditionalExpressionNodeCreateChild(_parent, #_name, line, column, condition, trueValue, falseValue); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ConditionalExpressionNodeUpdate(parser_ConditionalExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue);
#define parser_ConditionalExpressionNodeUpdate(_this, line, column, condition, trueValue, falseValue) _parser_ConditionalExpressionNodeUpdate(parser_ConditionalExpressionNode(_this), line, column, parser_ExpressionNode(condition), parser_ExpressionNode(trueValue), parser_ExpressionNode(falseValue))

CORTO_PARSER_EXPORT parser_ConditionalExpressionNode _parser_ConditionalExpressionNodeDeclare(void);
#define parser_ConditionalExpressionNodeDeclare() _parser_ConditionalExpressionNodeDeclare()
#define parser_ConditionalExpressionNodeDeclare_auto(_name) parser_ConditionalExpressionNode _name = parser_ConditionalExpressionNodeDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_ConditionalExpressionNode _parser_ConditionalExpressionNodeDeclareChild(corto_object _parent, corto_string _name);
#define parser_ConditionalExpressionNodeDeclareChild(_parent, _name) _parser_ConditionalExpressionNodeDeclareChild(_parent, _name)
#define parser_ConditionalExpressionNodeDeclareChild_auto(_parent, _name) parser_ConditionalExpressionNode _name = parser_ConditionalExpressionNodeDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ConditionalExpressionNodeDefine(parser_ConditionalExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue);
#define parser_ConditionalExpressionNodeDefine(_this, line, column, condition, trueValue, falseValue) _parser_ConditionalExpressionNodeDefine(parser_ConditionalExpressionNode(_this), line, column, parser_ExpressionNode(condition), parser_ExpressionNode(trueValue), parser_ExpressionNode(falseValue))
CORTO_PARSER_EXPORT void _parser_ConditionalExpressionNodeSet(parser_ConditionalExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue);
#define parser_ConditionalExpressionNodeSet(_this, line, column, condition, trueValue, falseValue) _parser_ConditionalExpressionNodeSet(parser_ConditionalExpressionNode(_this), line, column, parser_ExpressionNode(condition), parser_ExpressionNode(trueValue), parser_ExpressionNode(falseValue))
CORTO_PARSER_EXPORT corto_string _parser_ConditionalExpressionNodeStr(parser_ConditionalExpressionNode value);
#define parser_ConditionalExpressionNodeStr(value) _parser_ConditionalExpressionNodeStr(parser_ConditionalExpressionNode(value))
CORTO_PARSER_EXPORT parser_ConditionalExpressionNode parser_ConditionalExpressionNodeFromStr(parser_ConditionalExpressionNode value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_ConditionalExpressionNodeCompare(parser_ConditionalExpressionNode dst, parser_ConditionalExpressionNode src);
#define parser_ConditionalExpressionNodeCompare(dst, src) _parser_ConditionalExpressionNodeCompare(parser_ConditionalExpressionNode(dst), parser_ConditionalExpressionNode(src))

/* /corto/parser/ExpressionList */
CORTO_PARSER_EXPORT parser_ExpressionList* _parser_ExpressionListCreate(corto_uint32 length, parser_ExpressionNode* elements);
#define parser_ExpressionListCreate(length, elements) _parser_ExpressionListCreate(length, std::move(elements))
#define parser_ExpressionListCreate_auto(_name, length, elements) parser_ExpressionList* _name = parser_ExpressionListCreate(length, elements); (void)_name
CORTO_PARSER_EXPORT parser_ExpressionList* _parser_ExpressionListCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, parser_ExpressionNode* elements);
#define parser_ExpressionListCreateChild(_parent, _name, length, elements) _parser_ExpressionListCreateChild(_parent, _name, length, std::move(elements))
#define parser_ExpressionListCreateChild_auto(_parent, _name, length, elements) parser_ExpressionList* _name = parser_ExpressionListCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ExpressionListUpdate(parser_ExpressionList* _this, corto_uint32 length, parser_ExpressionNode* elements);
#define parser_ExpressionListUpdate(_this, length, elements) _parser_ExpressionListUpdate(_this, length, std::move(elements))

CORTO_PARSER_EXPORT parser_ExpressionList* _parser_ExpressionListDeclare(void);
#define parser_ExpressionListDeclare() _parser_ExpressionListDeclare()
#define parser_ExpressionListDeclare_auto(_name) parser_ExpressionList* _name = parser_ExpressionListDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_ExpressionList* _parser_ExpressionListDeclareChild(corto_object _parent, corto_string _name);
#define parser_ExpressionListDeclareChild(_parent, _name) _parser_ExpressionListDeclareChild(_parent, _name)
#define parser_ExpressionListDeclareChild_auto(_parent, _name) parser_ExpressionList* _name = parser_ExpressionListDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ExpressionListDefine(parser_ExpressionList* _this, corto_uint32 length, parser_ExpressionNode* elements);
#define parser_ExpressionListDefine(_this, length, elements) _parser_ExpressionListDefine(_this, length, std::move(elements))
CORTO_PARSER_EXPORT void _parser_ExpressionListSet(parser_ExpressionList* _this, corto_uint32 length, parser_ExpressionNode* elements);
#define parser_ExpressionListSet(_this, length, elements) _parser_ExpressionListSet(_this, length, std::move(elements))
CORTO_PARSER_EXPORT corto_string _parser_ExpressionListStr(parser_ExpressionList value);
#define parser_ExpressionListStr(value) _parser_ExpressionListStr(value)
CORTO_PARSER_EXPORT parser_ExpressionList* parser_ExpressionListFromStr(parser_ExpressionList* value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind parser_ExpressionListCompare(parser_ExpressionList dst, parser_ExpressionList src);

CORTO_PARSER_EXPORT corto_int16 _parser_ExpressionListInit(parser_ExpressionList* value);
#define parser_ExpressionListInit(value) _parser_ExpressionListInit(value)
CORTO_PARSER_EXPORT corto_int16 _parser_ExpressionListDeinit(parser_ExpressionList* value);
#define parser_ExpressionListDeinit(value) _parser_ExpressionListDeinit(value)

/* /corto/parser/ExpressionNode */
CORTO_PARSER_EXPORT parser_ExpressionNode _parser_ExpressionNodeCreate(corto_uint32 line, corto_uint32 column);
#define parser_ExpressionNodeCreate(line, column) _parser_ExpressionNodeCreate(line, column)
#define parser_ExpressionNodeCreate_auto(_name, line, column) parser_ExpressionNode _name = parser_ExpressionNodeCreate(line, column); (void)_name
CORTO_PARSER_EXPORT parser_ExpressionNode _parser_ExpressionNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column);
#define parser_ExpressionNodeCreateChild(_parent, _name, line, column) _parser_ExpressionNodeCreateChild(_parent, _name, line, column)
#define parser_ExpressionNodeCreateChild_auto(_parent, _name, line, column) parser_ExpressionNode _name = parser_ExpressionNodeCreateChild(_parent, #_name, line, column); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ExpressionNodeUpdate(parser_ExpressionNode _this, corto_uint32 line, corto_uint32 column);
#define parser_ExpressionNodeUpdate(_this, line, column) _parser_ExpressionNodeUpdate(parser_ExpressionNode(_this), line, column)

CORTO_PARSER_EXPORT parser_ExpressionNode _parser_ExpressionNodeDeclare(void);
#define parser_ExpressionNodeDeclare() _parser_ExpressionNodeDeclare()
#define parser_ExpressionNodeDeclare_auto(_name) parser_ExpressionNode _name = parser_ExpressionNodeDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_ExpressionNode _parser_ExpressionNodeDeclareChild(corto_object _parent, corto_string _name);
#define parser_ExpressionNodeDeclareChild(_parent, _name) _parser_ExpressionNodeDeclareChild(_parent, _name)
#define parser_ExpressionNodeDeclareChild_auto(_parent, _name) parser_ExpressionNode _name = parser_ExpressionNodeDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ExpressionNodeDefine(parser_ExpressionNode _this, corto_uint32 line, corto_uint32 column);
#define parser_ExpressionNodeDefine(_this, line, column) _parser_ExpressionNodeDefine(parser_ExpressionNode(_this), line, column)
CORTO_PARSER_EXPORT void _parser_ExpressionNodeSet(parser_ExpressionNode _this, corto_uint32 line, corto_uint32 column);
#define parser_ExpressionNodeSet(_this, line, column) _parser_ExpressionNodeSet(parser_ExpressionNode(_this), line, column)
CORTO_PARSER_EXPORT corto_string _parser_ExpressionNodeStr(parser_ExpressionNode value);
#define parser_ExpressionNodeStr(value) _parser_ExpressionNodeStr(parser_ExpressionNode(value))
CORTO_PARSER_EXPORT parser_ExpressionNode parser_ExpressionNodeFromStr(parser_ExpressionNode value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_ExpressionNodeCompare(parser_ExpressionNode dst, parser_ExpressionNode src);
#define parser_ExpressionNodeCompare(dst, src) _parser_ExpressionNodeCompare(parser_ExpressionNode(dst), parser_ExpressionNode(src))

/* /corto/parser/ExpressionStatementNode */
CORTO_PARSER_EXPORT parser_ExpressionStatementNode _parser_ExpressionStatementNodeCreate(corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression);
#define parser_ExpressionStatementNodeCreate(line, column, expression) _parser_ExpressionStatementNodeCreate(line, column, parser_ExpressionNode(expression))
#define parser_ExpressionStatementNodeCreate_auto(_name, line, column, expression) parser_ExpressionStatementNode _name = parser_ExpressionStatementNodeCreate(line, column, expression); (void)_name
CORTO_PARSER_EXPORT parser_ExpressionStatementNode _parser_ExpressionStatementNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression);
#define parser_ExpressionStatementNodeCreateChild(_parent, _name, line, column, expression) _parser_ExpressionStatementNodeCreateChild(_parent, _name, line, column, parser_ExpressionNode(expression))
#define parser_ExpressionStatementNodeCreateChild_auto(_parent, _name, line, column, expression) parser_ExpressionStatementNode _name = parser_ExpressionStatementNodeCreateChild(_parent, #_name, line, column, expression); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ExpressionStatementNodeUpdate(parser_ExpressionStatementNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression);
#define parser_ExpressionStatementNodeUpdate(_this, line, column, expression) _parser_ExpressionStatementNodeUpdate(parser_ExpressionStatementNode(_this), line, column, parser_ExpressionNode(expression))

CORTO_PARSER_EXPORT parser_ExpressionStatementNode _parser_ExpressionStatementNodeDeclare(void);
#define parser_ExpressionStatementNodeDeclare() _parser_ExpressionStatementNodeDeclare()
#define parser_ExpressionStatementNodeDeclare_auto(_name) parser_ExpressionStatementNode _name = parser_ExpressionStatementNodeDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_ExpressionStatementNode _parser_ExpressionStatementNodeDeclareChild(corto_object _parent, corto_string _name);
#define parser_ExpressionStatementNodeDeclareChild(_parent, _name) _parser_ExpressionStatementNodeDeclareChild(_parent, _name)
#define parser_ExpressionStatementNodeDeclareChild_auto(_parent, _name) parser_ExpressionStatementNode _name = parser_ExpressionStatementNodeDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ExpressionStatementNodeDefine(parser_ExpressionStatementNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression);
#define parser_ExpressionStatementNodeDefine(_this, line, column, expression) _parser_ExpressionStatementNodeDefine(parser_ExpressionStatementNode(_this), line, column, parser_ExpressionNode(expression))
CORTO_PARSER_EXPORT void _parser_ExpressionStatementNodeSet(parser_ExpressionStatementNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression);
#define parser_ExpressionStatementNodeSet(_this, line, column, expression) _parser_ExpressionStatementNodeSet(parser_ExpressionStatementNode(_this), line, column, parser_ExpressionNode(expression))
CORTO_PARSER_EXPORT corto_string _parser_ExpressionStatementNodeStr(parser_ExpressionStatementNode value);
#define parser_ExpressionStatementNodeStr(value) _parser_ExpressionStatementNodeStr(parser_ExpressionStatementNode(value))
CORTO_PARSER_EXPORT parser_ExpressionStatementNode parser_ExpressionStatementNodeFromStr(parser_ExpressionStatementNode value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_ExpressionStatementNodeCompare(parser_ExpressionStatementNode dst, parser_ExpressionStatementNode src);
#define parser_ExpressionStatementNodeCompare(dst, src) _parser_ExpressionStatementNodeCompare(parser_ExpressionStatementNode(dst), parser_ExpressionStatementNode(src))

/* /corto/parser/Node */
CORTO_PARSER_EXPORT parser_Node _parser_NodeCreate(corto_uint32 line, corto_uint32 column);
#define parser_NodeCreate(line, column) _parser_NodeCreate(line, column)
#define parser_NodeCreate_auto(_name, line, column) parser_Node _name = parser_NodeCreate(line, column); (void)_name
CORTO_PARSER_EXPORT parser_Node _parser_NodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column);
#define parser_NodeCreateChild(_parent, _name, line, column) _parser_NodeCreateChild(_parent, _name, line, column)
#define parser_NodeCreateChild_auto(_parent, _name, line, column) parser_Node _name = parser_NodeCreateChild(_parent, #_name, line, column); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_NodeUpdate(parser_Node _this, corto_uint32 line, corto_uint32 column);
#define parser_NodeUpdate(_this, line, column) _parser_NodeUpdate(parser_Node(_this), line, column)

CORTO_PARSER_EXPORT parser_Node _parser_NodeDeclare(void);
#define parser_NodeDeclare() _parser_NodeDeclare()
#define parser_NodeDeclare_auto(_name) parser_Node _name = parser_NodeDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_Node _parser_NodeDeclareChild(corto_object _parent, corto_string _name);
#define parser_NodeDeclareChild(_parent, _name) _parser_NodeDeclareChild(_parent, _name)
#define parser_NodeDeclareChild_auto(_parent, _name) parser_Node _name = parser_NodeDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_NodeDefine(parser_Node _this, corto_uint32 line, corto_uint32 column);
#define parser_NodeDefine(_this, line, column) _parser_NodeDefine(parser_Node(_this), line, column)
CORTO_PARSER_EXPORT void _parser_NodeSet(parser_Node _this, corto_uint32 line, corto_uint32 column);
#define parser_NodeSet(_this, line, column) _parser_NodeSet(parser_Node(_this), line, column)
CORTO_PARSER_EXPORT corto_string _parser_NodeStr(parser_Node value);
#define parser_NodeStr(value) _parser_NodeStr(parser_Node(value))
CORTO_PARSER_EXPORT parser_Node parser_NodeFromStr(parser_Node value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_NodeCompare(parser_Node dst, parser_Node src);
#define parser_NodeCompare(dst, src) _parser_NodeCompare(parser_Node(dst), parser_Node(src))

/* /corto/parser/PrintVisitor */
CORTO_PARSER_EXPORT parser_PrintVisitor _parser_PrintVisitorCreate(parser_BaseParser parser);
#define parser_PrintVisitorCreate(parser) _parser_PrintVisitorCreate(parser_BaseParser(parser))
#define parser_PrintVisitorCreate_auto(_name, parser) parser_PrintVisitor _name = parser_PrintVisitorCreate(parser); (void)_name
CORTO_PARSER_EXPORT parser_PrintVisitor _parser_PrintVisitorCreateChild(corto_object _parent, corto_string _name, parser_BaseParser parser);
#define parser_PrintVisitorCreateChild(_parent, _name, parser) _parser_PrintVisitorCreateChild(_parent, _name, parser_BaseParser(parser))
#define parser_PrintVisitorCreateChild_auto(_parent, _name, parser) parser_PrintVisitor _name = parser_PrintVisitorCreateChild(_parent, #_name, parser); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_PrintVisitorUpdate(parser_PrintVisitor _this, parser_BaseParser parser);
#define parser_PrintVisitorUpdate(_this, parser) _parser_PrintVisitorUpdate(parser_PrintVisitor(_this), parser_BaseParser(parser))

CORTO_PARSER_EXPORT parser_PrintVisitor _parser_PrintVisitorDeclare(void);
#define parser_PrintVisitorDeclare() _parser_PrintVisitorDeclare()
#define parser_PrintVisitorDeclare_auto(_name) parser_PrintVisitor _name = parser_PrintVisitorDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_PrintVisitor _parser_PrintVisitorDeclareChild(corto_object _parent, corto_string _name);
#define parser_PrintVisitorDeclareChild(_parent, _name) _parser_PrintVisitorDeclareChild(_parent, _name)
#define parser_PrintVisitorDeclareChild_auto(_parent, _name) parser_PrintVisitor _name = parser_PrintVisitorDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_PrintVisitorDefine(parser_PrintVisitor _this, parser_BaseParser parser);
#define parser_PrintVisitorDefine(_this, parser) _parser_PrintVisitorDefine(parser_PrintVisitor(_this), parser_BaseParser(parser))
CORTO_PARSER_EXPORT void _parser_PrintVisitorSet(parser_PrintVisitor _this, parser_BaseParser parser);
#define parser_PrintVisitorSet(_this, parser) _parser_PrintVisitorSet(parser_PrintVisitor(_this), parser_BaseParser(parser))
CORTO_PARSER_EXPORT corto_string _parser_PrintVisitorStr(parser_PrintVisitor value);
#define parser_PrintVisitorStr(value) _parser_PrintVisitorStr(parser_PrintVisitor(value))
CORTO_PARSER_EXPORT parser_PrintVisitor parser_PrintVisitorFromStr(parser_PrintVisitor value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_PrintVisitorCompare(parser_PrintVisitor dst, parser_PrintVisitor src);
#define parser_PrintVisitorCompare(dst, src) _parser_PrintVisitorCompare(parser_PrintVisitor(dst), parser_PrintVisitor(src))

/* /corto/parser/ProgramNode */
CORTO_PARSER_EXPORT parser_ProgramNode _parser_ProgramNodeCreate(corto_uint32 line, corto_uint32 column, parser_StatementList statements);
#define parser_ProgramNodeCreate(line, column, statements) _parser_ProgramNodeCreate(line, column, statements)
#define parser_ProgramNodeCreate_auto(_name, line, column, statements) parser_ProgramNode _name = parser_ProgramNodeCreate(line, column, statements); (void)_name
CORTO_PARSER_EXPORT parser_ProgramNode _parser_ProgramNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_StatementList statements);
#define parser_ProgramNodeCreateChild(_parent, _name, line, column, statements) _parser_ProgramNodeCreateChild(_parent, _name, line, column, statements)
#define parser_ProgramNodeCreateChild_auto(_parent, _name, line, column, statements) parser_ProgramNode _name = parser_ProgramNodeCreateChild(_parent, #_name, line, column, statements); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ProgramNodeUpdate(parser_ProgramNode _this, corto_uint32 line, corto_uint32 column, parser_StatementList statements);
#define parser_ProgramNodeUpdate(_this, line, column, statements) _parser_ProgramNodeUpdate(parser_ProgramNode(_this), line, column, statements)

CORTO_PARSER_EXPORT parser_ProgramNode _parser_ProgramNodeDeclare(void);
#define parser_ProgramNodeDeclare() _parser_ProgramNodeDeclare()
#define parser_ProgramNodeDeclare_auto(_name) parser_ProgramNode _name = parser_ProgramNodeDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_ProgramNode _parser_ProgramNodeDeclareChild(corto_object _parent, corto_string _name);
#define parser_ProgramNodeDeclareChild(_parent, _name) _parser_ProgramNodeDeclareChild(_parent, _name)
#define parser_ProgramNodeDeclareChild_auto(_parent, _name) parser_ProgramNode _name = parser_ProgramNodeDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_ProgramNodeDefine(parser_ProgramNode _this, corto_uint32 line, corto_uint32 column, parser_StatementList statements);
#define parser_ProgramNodeDefine(_this, line, column, statements) _parser_ProgramNodeDefine(parser_ProgramNode(_this), line, column, statements)
CORTO_PARSER_EXPORT void _parser_ProgramNodeSet(parser_ProgramNode _this, corto_uint32 line, corto_uint32 column, parser_StatementList statements);
#define parser_ProgramNodeSet(_this, line, column, statements) _parser_ProgramNodeSet(parser_ProgramNode(_this), line, column, statements)
CORTO_PARSER_EXPORT corto_string _parser_ProgramNodeStr(parser_ProgramNode value);
#define parser_ProgramNodeStr(value) _parser_ProgramNodeStr(parser_ProgramNode(value))
CORTO_PARSER_EXPORT parser_ProgramNode parser_ProgramNodeFromStr(parser_ProgramNode value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_ProgramNodeCompare(parser_ProgramNode dst, parser_ProgramNode src);
#define parser_ProgramNodeCompare(dst, src) _parser_ProgramNodeCompare(parser_ProgramNode(dst), parser_ProgramNode(src))

/* /corto/parser/SimpleParser */
CORTO_PARSER_EXPORT parser_SimpleParser _parser_SimpleParserCreate(void);
#define parser_SimpleParserCreate() _parser_SimpleParserCreate()
#define parser_SimpleParserCreate_auto(_name) parser_SimpleParser _name = parser_SimpleParserCreate(); (void)_name
CORTO_PARSER_EXPORT parser_SimpleParser _parser_SimpleParserCreateChild(corto_object _parent, corto_string _name);
#define parser_SimpleParserCreateChild(_parent, _name) _parser_SimpleParserCreateChild(_parent, _name)
#define parser_SimpleParserCreateChild_auto(_parent, _name) parser_SimpleParser _name = parser_SimpleParserCreateChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_SimpleParserUpdate(parser_SimpleParser _this);
#define parser_SimpleParserUpdate(_this) _parser_SimpleParserUpdate(parser_SimpleParser(_this))

CORTO_PARSER_EXPORT parser_SimpleParser _parser_SimpleParserDeclare(void);
#define parser_SimpleParserDeclare() _parser_SimpleParserDeclare()
#define parser_SimpleParserDeclare_auto(_name) parser_SimpleParser _name = parser_SimpleParserDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_SimpleParser _parser_SimpleParserDeclareChild(corto_object _parent, corto_string _name);
#define parser_SimpleParserDeclareChild(_parent, _name) _parser_SimpleParserDeclareChild(_parent, _name)
#define parser_SimpleParserDeclareChild_auto(_parent, _name) parser_SimpleParser _name = parser_SimpleParserDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_SimpleParserDefine(parser_SimpleParser _this);
#define parser_SimpleParserDefine(_this) _parser_SimpleParserDefine(parser_SimpleParser(_this))
CORTO_PARSER_EXPORT void _parser_SimpleParserSet(parser_SimpleParser _this);
#define parser_SimpleParserSet(_this) _parser_SimpleParserSet(parser_SimpleParser(_this))
CORTO_PARSER_EXPORT corto_string _parser_SimpleParserStr(parser_SimpleParser value);
#define parser_SimpleParserStr(value) _parser_SimpleParserStr(parser_SimpleParser(value))
CORTO_PARSER_EXPORT parser_SimpleParser parser_SimpleParserFromStr(parser_SimpleParser value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_SimpleParserCompare(parser_SimpleParser dst, parser_SimpleParser src);
#define parser_SimpleParserCompare(dst, src) _parser_SimpleParserCompare(parser_SimpleParser(dst), parser_SimpleParser(src))

/* /corto/parser/StatementList */
CORTO_PARSER_EXPORT parser_StatementList* _parser_StatementListCreate(corto_uint32 length, parser_StatementNode* elements);
#define parser_StatementListCreate(length, elements) _parser_StatementListCreate(length, std::move(elements))
#define parser_StatementListCreate_auto(_name, length, elements) parser_StatementList* _name = parser_StatementListCreate(length, elements); (void)_name
CORTO_PARSER_EXPORT parser_StatementList* _parser_StatementListCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, parser_StatementNode* elements);
#define parser_StatementListCreateChild(_parent, _name, length, elements) _parser_StatementListCreateChild(_parent, _name, length, std::move(elements))
#define parser_StatementListCreateChild_auto(_parent, _name, length, elements) parser_StatementList* _name = parser_StatementListCreateChild(_parent, #_name, length, elements); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_StatementListUpdate(parser_StatementList* _this, corto_uint32 length, parser_StatementNode* elements);
#define parser_StatementListUpdate(_this, length, elements) _parser_StatementListUpdate(_this, length, std::move(elements))

CORTO_PARSER_EXPORT parser_StatementList* _parser_StatementListDeclare(void);
#define parser_StatementListDeclare() _parser_StatementListDeclare()
#define parser_StatementListDeclare_auto(_name) parser_StatementList* _name = parser_StatementListDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_StatementList* _parser_StatementListDeclareChild(corto_object _parent, corto_string _name);
#define parser_StatementListDeclareChild(_parent, _name) _parser_StatementListDeclareChild(_parent, _name)
#define parser_StatementListDeclareChild_auto(_parent, _name) parser_StatementList* _name = parser_StatementListDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_StatementListDefine(parser_StatementList* _this, corto_uint32 length, parser_StatementNode* elements);
#define parser_StatementListDefine(_this, length, elements) _parser_StatementListDefine(_this, length, std::move(elements))
CORTO_PARSER_EXPORT void _parser_StatementListSet(parser_StatementList* _this, corto_uint32 length, parser_StatementNode* elements);
#define parser_StatementListSet(_this, length, elements) _parser_StatementListSet(_this, length, std::move(elements))
CORTO_PARSER_EXPORT corto_string _parser_StatementListStr(parser_StatementList value);
#define parser_StatementListStr(value) _parser_StatementListStr(value)
CORTO_PARSER_EXPORT parser_StatementList* parser_StatementListFromStr(parser_StatementList* value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind parser_StatementListCompare(parser_StatementList dst, parser_StatementList src);

CORTO_PARSER_EXPORT corto_int16 _parser_StatementListInit(parser_StatementList* value);
#define parser_StatementListInit(value) _parser_StatementListInit(value)
CORTO_PARSER_EXPORT corto_int16 _parser_StatementListDeinit(parser_StatementList* value);
#define parser_StatementListDeinit(value) _parser_StatementListDeinit(value)

/* /corto/parser/StatementNode */
CORTO_PARSER_EXPORT parser_StatementNode _parser_StatementNodeCreate(corto_uint32 line, corto_uint32 column);
#define parser_StatementNodeCreate(line, column) _parser_StatementNodeCreate(line, column)
#define parser_StatementNodeCreate_auto(_name, line, column) parser_StatementNode _name = parser_StatementNodeCreate(line, column); (void)_name
CORTO_PARSER_EXPORT parser_StatementNode _parser_StatementNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column);
#define parser_StatementNodeCreateChild(_parent, _name, line, column) _parser_StatementNodeCreateChild(_parent, _name, line, column)
#define parser_StatementNodeCreateChild_auto(_parent, _name, line, column) parser_StatementNode _name = parser_StatementNodeCreateChild(_parent, #_name, line, column); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_StatementNodeUpdate(parser_StatementNode _this, corto_uint32 line, corto_uint32 column);
#define parser_StatementNodeUpdate(_this, line, column) _parser_StatementNodeUpdate(parser_StatementNode(_this), line, column)

CORTO_PARSER_EXPORT parser_StatementNode _parser_StatementNodeDeclare(void);
#define parser_StatementNodeDeclare() _parser_StatementNodeDeclare()
#define parser_StatementNodeDeclare_auto(_name) parser_StatementNode _name = parser_StatementNodeDeclare(); (void)_name
CORTO_PARSER_EXPORT parser_StatementNode _parser_StatementNodeDeclareChild(corto_object _parent, corto_string _name);
#define parser_StatementNodeDeclareChild(_parent, _name) _parser_StatementNodeDeclareChild(_parent, _name)
#define parser_StatementNodeDeclareChild_auto(_parent, _name) parser_StatementNode _name = parser_StatementNodeDeclareChild(_parent, #_name); (void)_name
CORTO_PARSER_EXPORT corto_int16 _parser_StatementNodeDefine(parser_StatementNode _this, corto_uint32 line, corto_uint32 column);
#define parser_StatementNodeDefine(_this, line, column) _parser_StatementNodeDefine(parser_StatementNode(_this), line, column)
CORTO_PARSER_EXPORT void _parser_StatementNodeSet(parser_StatementNode _this, corto_uint32 line, corto_uint32 column);
#define parser_StatementNodeSet(_this, line, column) _parser_StatementNodeSet(parser_StatementNode(_this), line, column)
CORTO_PARSER_EXPORT corto_string _parser_StatementNodeStr(parser_StatementNode value);
#define parser_StatementNodeStr(value) _parser_StatementNodeStr(parser_StatementNode(value))
CORTO_PARSER_EXPORT parser_StatementNode parser_StatementNodeFromStr(parser_StatementNode value, corto_string str);
CORTO_PARSER_EXPORT corto_equalityKind _parser_StatementNodeCompare(parser_StatementNode dst, parser_StatementNode src);
#define parser_StatementNodeCompare(dst, src) _parser_StatementNodeCompare(parser_StatementNode(dst), parser_StatementNode(src))


/* /corto/parser/ExpressionList */
#define parser_ExpressionListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    parser_ExpressionNode elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_PARSER_EXPORT void parser_ExpressionListInsert(parser_ExpressionList list, parser_ExpressionNode element);
CORTO_PARSER_EXPORT void parser_ExpressionListAppend(parser_ExpressionList list, parser_ExpressionNode element);
CORTO_PARSER_EXPORT void parser_ExpressionListRemove(parser_ExpressionList list, parser_ExpressionNode element);
CORTO_PARSER_EXPORT parser_ExpressionNode parser_ExpressionListTakeFirst(parser_ExpressionList list);
CORTO_PARSER_EXPORT parser_ExpressionNode parser_ExpressionListLast(parser_ExpressionList list);
CORTO_PARSER_EXPORT parser_ExpressionNode parser_ExpressionListGet(parser_ExpressionList list, corto_uint32 index);
CORTO_PARSER_EXPORT corto_uint32 parser_ExpressionListSize(parser_ExpressionList list);
CORTO_PARSER_EXPORT void parser_ExpressionListClear(parser_ExpressionList list);

/* /corto/parser/StatementList */
#define parser_StatementListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    parser_StatementNode elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_PARSER_EXPORT void parser_StatementListInsert(parser_StatementList list, parser_StatementNode element);
CORTO_PARSER_EXPORT void parser_StatementListAppend(parser_StatementList list, parser_StatementNode element);
CORTO_PARSER_EXPORT void parser_StatementListRemove(parser_StatementList list, parser_StatementNode element);
CORTO_PARSER_EXPORT parser_StatementNode parser_StatementListTakeFirst(parser_StatementList list);
CORTO_PARSER_EXPORT parser_StatementNode parser_StatementListLast(parser_StatementList list);
CORTO_PARSER_EXPORT parser_StatementNode parser_StatementListGet(parser_StatementList list, corto_uint32 index);
CORTO_PARSER_EXPORT corto_uint32 parser_StatementListSize(parser_StatementList list);
CORTO_PARSER_EXPORT void parser_StatementListClear(parser_StatementList list);

/* <0x910f70> */
#define corto_stringListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    corto_string elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = (corto_string)(corto_word)corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_PARSER_EXPORT void corto_stringListInsert(corto_stringList list, corto_string element);
CORTO_PARSER_EXPORT void corto_stringListAppend(corto_stringList list, corto_string element);
CORTO_PARSER_EXPORT corto_string corto_stringListTakeFirst(corto_stringList list);
CORTO_PARSER_EXPORT corto_string corto_stringListLast(corto_stringList list);
CORTO_PARSER_EXPORT corto_string corto_stringListGet(corto_stringList list, corto_uint32 index);
CORTO_PARSER_EXPORT corto_uint32 corto_stringListSize(corto_stringList list);
CORTO_PARSER_EXPORT void corto_stringListClear(corto_stringList list);

#ifdef __cplusplus
}
#endif
#endif

