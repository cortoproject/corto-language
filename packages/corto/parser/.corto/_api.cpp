/* _api.cpp
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/parser/parser.h>
parser_BaseParser _parser_BaseParserCreate(void) {
    parser_BaseParser _this;
    _this = parser_BaseParser(corto_declare(parser_BaseParser_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_BaseParser _parser_BaseParserCreateChild(corto_object _parent, corto_string _name) {
    parser_BaseParser _this;
    _this = parser_BaseParser(corto_declareChild(_parent, _name, parser_BaseParser_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_BaseParserUpdate(parser_BaseParser _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_BaseParser _parser_BaseParserDeclare(void) {
    parser_BaseParser _this;
    _this = parser_BaseParser(corto_declare(parser_BaseParser_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_BaseParser _parser_BaseParserDeclareChild(corto_object _parent, corto_string _name) {
    parser_BaseParser _this;
    _this = parser_BaseParser(corto_declareChild(_parent, _name, parser_BaseParser_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_BaseParserDefine(parser_BaseParser _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

void _parser_BaseParserSet(parser_BaseParser _this) {
    CORTO_UNUSED(_this);
}

corto_string _parser_BaseParserStr(parser_BaseParser value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_BaseParser_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_BaseParser parser_BaseParserFromStr(parser_BaseParser value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_BaseParser_o), str);
    return value;
}

corto_equalityKind _parser_BaseParserCompare(parser_BaseParser dst, parser_BaseParser src) {
    return corto_compare(dst, src);
}

parser_BaseVisitor _parser_BaseVisitorCreate(parser_BaseParser parser) {
    parser_BaseVisitor _this;
    _this = parser_BaseVisitor(corto_declare(parser_BaseVisitor_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_BaseVisitor _parser_BaseVisitorCreateChild(corto_object _parent, corto_string _name, parser_BaseParser parser) {
    parser_BaseVisitor _this;
    _this = parser_BaseVisitor(corto_declareChild(_parent, _name, parser_BaseVisitor_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_BaseVisitorUpdate(parser_BaseVisitor _this, parser_BaseParser parser) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_BaseVisitor _parser_BaseVisitorDeclare(void) {
    parser_BaseVisitor _this;
    _this = parser_BaseVisitor(corto_declare(parser_BaseVisitor_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_BaseVisitor _parser_BaseVisitorDeclareChild(corto_object _parent, corto_string _name) {
    parser_BaseVisitor _this;
    _this = parser_BaseVisitor(corto_declareChild(_parent, _name, parser_BaseVisitor_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_BaseVisitorDefine(parser_BaseVisitor _this, parser_BaseParser parser) {
    CORTO_UNUSED(_this);
    corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
    return corto_define(_this);
}

void _parser_BaseVisitorSet(parser_BaseVisitor _this, parser_BaseParser parser) {
    CORTO_UNUSED(_this);
    corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
}

corto_string _parser_BaseVisitorStr(parser_BaseVisitor value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_BaseVisitor_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_BaseVisitor parser_BaseVisitorFromStr(parser_BaseVisitor value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_BaseVisitor_o), str);
    return value;
}

corto_equalityKind _parser_BaseVisitorCompare(parser_BaseVisitor dst, parser_BaseVisitor src) {
    return corto_compare(dst, src);
}

parser_BinaryExpressionNode _parser_BinaryExpressionNodeCreate(corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right) {
    parser_BinaryExpressionNode _this;
    _this = parser_BinaryExpressionNode(corto_declare(parser_BinaryExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_BinaryExpressionNode)_this)->left, left);
    corto_setstr(&((parser_BinaryExpressionNode)_this)->_operator, _operator);
    corto_setref(&((parser_BinaryExpressionNode)_this)->right, right);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_BinaryExpressionNode _parser_BinaryExpressionNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right) {
    parser_BinaryExpressionNode _this;
    _this = parser_BinaryExpressionNode(corto_declareChild(_parent, _name, parser_BinaryExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_BinaryExpressionNode)_this)->left, left);
    corto_setstr(&((parser_BinaryExpressionNode)_this)->_operator, _operator);
    corto_setref(&((parser_BinaryExpressionNode)_this)->right, right);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_BinaryExpressionNodeUpdate(parser_BinaryExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((parser_Node)_this)->line = line;
        ((parser_Node)_this)->column = column;
        corto_setref(&((parser_BinaryExpressionNode)_this)->left, left);
        corto_setstr(&((parser_BinaryExpressionNode)_this)->_operator, _operator);
        corto_setref(&((parser_BinaryExpressionNode)_this)->right, right);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_BinaryExpressionNode _parser_BinaryExpressionNodeDeclare(void) {
    parser_BinaryExpressionNode _this;
    _this = parser_BinaryExpressionNode(corto_declare(parser_BinaryExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_BinaryExpressionNode _parser_BinaryExpressionNodeDeclareChild(corto_object _parent, corto_string _name) {
    parser_BinaryExpressionNode _this;
    _this = parser_BinaryExpressionNode(corto_declareChild(_parent, _name, parser_BinaryExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_BinaryExpressionNodeDefine(parser_BinaryExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_BinaryExpressionNode)_this)->left, left);
    corto_setstr(&((parser_BinaryExpressionNode)_this)->_operator, _operator);
    corto_setref(&((parser_BinaryExpressionNode)_this)->right, right);
    return corto_define(_this);
}

void _parser_BinaryExpressionNodeSet(parser_BinaryExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode left, corto_string _operator, parser_ExpressionNode right) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_BinaryExpressionNode)_this)->left, left);
    corto_setstr(&((parser_BinaryExpressionNode)_this)->_operator, _operator);
    corto_setref(&((parser_BinaryExpressionNode)_this)->right, right);
}

corto_string _parser_BinaryExpressionNodeStr(parser_BinaryExpressionNode value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_BinaryExpressionNode_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_BinaryExpressionNode parser_BinaryExpressionNodeFromStr(parser_BinaryExpressionNode value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_BinaryExpressionNode_o), str);
    return value;
}

corto_equalityKind _parser_BinaryExpressionNodeCompare(parser_BinaryExpressionNode dst, parser_BinaryExpressionNode src) {
    return corto_compare(dst, src);
}

parser_CommaExpressionNode _parser_CommaExpressionNodeCreate(corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions) {
    parser_CommaExpressionNode _this;
    _this = parser_CommaExpressionNode(corto_declare(parser_CommaExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_copyp(&((parser_CommaExpressionNode)_this)->expressions, parser_ExpressionList_o, &expressions);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_CommaExpressionNode _parser_CommaExpressionNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions) {
    parser_CommaExpressionNode _this;
    _this = parser_CommaExpressionNode(corto_declareChild(_parent, _name, parser_CommaExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_copyp(&((parser_CommaExpressionNode)_this)->expressions, parser_ExpressionList_o, &expressions);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_CommaExpressionNodeUpdate(parser_CommaExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((parser_Node)_this)->line = line;
        ((parser_Node)_this)->column = column;
        corto_copyp(&((parser_CommaExpressionNode)_this)->expressions, parser_ExpressionList_o, &expressions);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_CommaExpressionNode _parser_CommaExpressionNodeDeclare(void) {
    parser_CommaExpressionNode _this;
    _this = parser_CommaExpressionNode(corto_declare(parser_CommaExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_CommaExpressionNode _parser_CommaExpressionNodeDeclareChild(corto_object _parent, corto_string _name) {
    parser_CommaExpressionNode _this;
    _this = parser_CommaExpressionNode(corto_declareChild(_parent, _name, parser_CommaExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_CommaExpressionNodeDefine(parser_CommaExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_copyp(&((parser_CommaExpressionNode)_this)->expressions, parser_ExpressionList_o, &expressions);
    return corto_define(_this);
}

void _parser_CommaExpressionNodeSet(parser_CommaExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionList expressions) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_copyp(&((parser_CommaExpressionNode)_this)->expressions, parser_ExpressionList_o, &expressions);
}

corto_string _parser_CommaExpressionNodeStr(parser_CommaExpressionNode value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_CommaExpressionNode_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_CommaExpressionNode parser_CommaExpressionNodeFromStr(parser_CommaExpressionNode value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_CommaExpressionNode_o), str);
    return value;
}

corto_equalityKind _parser_CommaExpressionNodeCompare(parser_CommaExpressionNode dst, parser_CommaExpressionNode src) {
    return corto_compare(dst, src);
}

parser_ConditionalExpressionNode _parser_ConditionalExpressionNodeCreate(corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue) {
    parser_ConditionalExpressionNode _this;
    _this = parser_ConditionalExpressionNode(corto_declare(parser_ConditionalExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_ConditionalExpressionNode)_this)->condition, condition);
    corto_setref(&((parser_ConditionalExpressionNode)_this)->trueValue, trueValue);
    corto_setref(&((parser_ConditionalExpressionNode)_this)->falseValue, falseValue);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_ConditionalExpressionNode _parser_ConditionalExpressionNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue) {
    parser_ConditionalExpressionNode _this;
    _this = parser_ConditionalExpressionNode(corto_declareChild(_parent, _name, parser_ConditionalExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_ConditionalExpressionNode)_this)->condition, condition);
    corto_setref(&((parser_ConditionalExpressionNode)_this)->trueValue, trueValue);
    corto_setref(&((parser_ConditionalExpressionNode)_this)->falseValue, falseValue);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_ConditionalExpressionNodeUpdate(parser_ConditionalExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((parser_Node)_this)->line = line;
        ((parser_Node)_this)->column = column;
        corto_setref(&((parser_ConditionalExpressionNode)_this)->condition, condition);
        corto_setref(&((parser_ConditionalExpressionNode)_this)->trueValue, trueValue);
        corto_setref(&((parser_ConditionalExpressionNode)_this)->falseValue, falseValue);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_ConditionalExpressionNode _parser_ConditionalExpressionNodeDeclare(void) {
    parser_ConditionalExpressionNode _this;
    _this = parser_ConditionalExpressionNode(corto_declare(parser_ConditionalExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_ConditionalExpressionNode _parser_ConditionalExpressionNodeDeclareChild(corto_object _parent, corto_string _name) {
    parser_ConditionalExpressionNode _this;
    _this = parser_ConditionalExpressionNode(corto_declareChild(_parent, _name, parser_ConditionalExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_ConditionalExpressionNodeDefine(parser_ConditionalExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_ConditionalExpressionNode)_this)->condition, condition);
    corto_setref(&((parser_ConditionalExpressionNode)_this)->trueValue, trueValue);
    corto_setref(&((parser_ConditionalExpressionNode)_this)->falseValue, falseValue);
    return corto_define(_this);
}

void _parser_ConditionalExpressionNodeSet(parser_ConditionalExpressionNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode condition, parser_ExpressionNode trueValue, parser_ExpressionNode falseValue) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_ConditionalExpressionNode)_this)->condition, condition);
    corto_setref(&((parser_ConditionalExpressionNode)_this)->trueValue, trueValue);
    corto_setref(&((parser_ConditionalExpressionNode)_this)->falseValue, falseValue);
}

corto_string _parser_ConditionalExpressionNodeStr(parser_ConditionalExpressionNode value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_ConditionalExpressionNode_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_ConditionalExpressionNode parser_ConditionalExpressionNodeFromStr(parser_ConditionalExpressionNode value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_ConditionalExpressionNode_o), str);
    return value;
}

corto_equalityKind _parser_ConditionalExpressionNodeCompare(parser_ConditionalExpressionNode dst, parser_ConditionalExpressionNode src) {
    return corto_compare(dst, src);
}

parser_ExpressionList* _parser_ExpressionListCreate(corto_uint32 length, parser_ExpressionNode* elements) {
    parser_ExpressionList* _this;
    _this = parser_ExpressionList(corto_declare(parser_ExpressionList_o));
    if (!_this) {
        return NULL;
    }
    corto_uint32 i = 0;
    parser_ExpressionListClear(*_this);
    for (i = 0; i < length; i ++) {
        parser_ExpressionListAppend(*_this, elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_ExpressionList* _parser_ExpressionListCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, parser_ExpressionNode* elements) {
    parser_ExpressionList* _this;
    _this = parser_ExpressionList(corto_declareChild(_parent, _name, parser_ExpressionList_o));
    if (!_this) {
        return NULL;
    }
    corto_uint32 i = 0;
    parser_ExpressionListClear(*_this);
    for (i = 0; i < length; i ++) {
        parser_ExpressionListAppend(*_this, elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_ExpressionListUpdate(parser_ExpressionList* _this, corto_uint32 length, parser_ExpressionNode* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_uint32 i = 0;
        parser_ExpressionListClear(*_this);
        for (i = 0; i < length; i ++) {
            parser_ExpressionListAppend(*_this, elements[i]);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_ExpressionList* _parser_ExpressionListDeclare(void) {
    parser_ExpressionList* _this;
    _this = parser_ExpressionList(corto_declare(parser_ExpressionList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_ExpressionList* _parser_ExpressionListDeclareChild(corto_object _parent, corto_string _name) {
    parser_ExpressionList* _this;
    _this = parser_ExpressionList(corto_declareChild(_parent, _name, parser_ExpressionList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_ExpressionListDefine(parser_ExpressionList* _this, corto_uint32 length, parser_ExpressionNode* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    parser_ExpressionListClear(*_this);
    for (i = 0; i < length; i ++) {
        parser_ExpressionListAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

void _parser_ExpressionListSet(parser_ExpressionList* _this, corto_uint32 length, parser_ExpressionNode* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    parser_ExpressionListClear(*_this);
    for (i = 0; i < length; i ++) {
        parser_ExpressionListAppend(*_this, elements[i]);
    }
}

corto_string _parser_ExpressionListStr(parser_ExpressionList value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(parser_ExpressionList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

parser_ExpressionList* parser_ExpressionListFromStr(parser_ExpressionList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_ExpressionList_o), str);
    return value;
}

corto_equalityKind parser_ExpressionListCompare(parser_ExpressionList dst, parser_ExpressionList src) {
    return corto_comparep(&dst, parser_ExpressionList_o, &src);
}

corto_int16 _parser_ExpressionListInit(parser_ExpressionList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(parser_ExpressionList_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(parser_ExpressionList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _parser_ExpressionListDeinit(parser_ExpressionList* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(parser_ExpressionList_o), value);
    result = corto_deinitv(&v);
    return result;
}

parser_ExpressionNode _parser_ExpressionNodeCreate(corto_uint32 line, corto_uint32 column) {
    parser_ExpressionNode _this;
    _this = parser_ExpressionNode(corto_declare(parser_ExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_ExpressionNode _parser_ExpressionNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column) {
    parser_ExpressionNode _this;
    _this = parser_ExpressionNode(corto_declareChild(_parent, _name, parser_ExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_ExpressionNodeUpdate(parser_ExpressionNode _this, corto_uint32 line, corto_uint32 column) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((parser_Node)_this)->line = line;
        ((parser_Node)_this)->column = column;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_ExpressionNode _parser_ExpressionNodeDeclare(void) {
    parser_ExpressionNode _this;
    _this = parser_ExpressionNode(corto_declare(parser_ExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_ExpressionNode _parser_ExpressionNodeDeclareChild(corto_object _parent, corto_string _name) {
    parser_ExpressionNode _this;
    _this = parser_ExpressionNode(corto_declareChild(_parent, _name, parser_ExpressionNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_ExpressionNodeDefine(parser_ExpressionNode _this, corto_uint32 line, corto_uint32 column) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    return corto_define(_this);
}

void _parser_ExpressionNodeSet(parser_ExpressionNode _this, corto_uint32 line, corto_uint32 column) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
}

corto_string _parser_ExpressionNodeStr(parser_ExpressionNode value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_ExpressionNode_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_ExpressionNode parser_ExpressionNodeFromStr(parser_ExpressionNode value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_ExpressionNode_o), str);
    return value;
}

corto_equalityKind _parser_ExpressionNodeCompare(parser_ExpressionNode dst, parser_ExpressionNode src) {
    return corto_compare(dst, src);
}

parser_ExpressionStatementNode _parser_ExpressionStatementNodeCreate(corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression) {
    parser_ExpressionStatementNode _this;
    _this = parser_ExpressionStatementNode(corto_declare(parser_ExpressionStatementNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_ExpressionStatementNode)_this)->expression, expression);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_ExpressionStatementNode _parser_ExpressionStatementNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression) {
    parser_ExpressionStatementNode _this;
    _this = parser_ExpressionStatementNode(corto_declareChild(_parent, _name, parser_ExpressionStatementNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_ExpressionStatementNode)_this)->expression, expression);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_ExpressionStatementNodeUpdate(parser_ExpressionStatementNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((parser_Node)_this)->line = line;
        ((parser_Node)_this)->column = column;
        corto_setref(&((parser_ExpressionStatementNode)_this)->expression, expression);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_ExpressionStatementNode _parser_ExpressionStatementNodeDeclare(void) {
    parser_ExpressionStatementNode _this;
    _this = parser_ExpressionStatementNode(corto_declare(parser_ExpressionStatementNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_ExpressionStatementNode _parser_ExpressionStatementNodeDeclareChild(corto_object _parent, corto_string _name) {
    parser_ExpressionStatementNode _this;
    _this = parser_ExpressionStatementNode(corto_declareChild(_parent, _name, parser_ExpressionStatementNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_ExpressionStatementNodeDefine(parser_ExpressionStatementNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_ExpressionStatementNode)_this)->expression, expression);
    return corto_define(_this);
}

void _parser_ExpressionStatementNodeSet(parser_ExpressionStatementNode _this, corto_uint32 line, corto_uint32 column, parser_ExpressionNode expression) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_setref(&((parser_ExpressionStatementNode)_this)->expression, expression);
}

corto_string _parser_ExpressionStatementNodeStr(parser_ExpressionStatementNode value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_ExpressionStatementNode_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_ExpressionStatementNode parser_ExpressionStatementNodeFromStr(parser_ExpressionStatementNode value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_ExpressionStatementNode_o), str);
    return value;
}

corto_equalityKind _parser_ExpressionStatementNodeCompare(parser_ExpressionStatementNode dst, parser_ExpressionStatementNode src) {
    return corto_compare(dst, src);
}

parser_Node _parser_NodeCreate(corto_uint32 line, corto_uint32 column) {
    parser_Node _this;
    _this = parser_Node(corto_declare(parser_Node_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_Node _parser_NodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column) {
    parser_Node _this;
    _this = parser_Node(corto_declareChild(_parent, _name, parser_Node_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_NodeUpdate(parser_Node _this, corto_uint32 line, corto_uint32 column) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((parser_Node)_this)->line = line;
        ((parser_Node)_this)->column = column;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_Node _parser_NodeDeclare(void) {
    parser_Node _this;
    _this = parser_Node(corto_declare(parser_Node_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_Node _parser_NodeDeclareChild(corto_object _parent, corto_string _name) {
    parser_Node _this;
    _this = parser_Node(corto_declareChild(_parent, _name, parser_Node_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_NodeDefine(parser_Node _this, corto_uint32 line, corto_uint32 column) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    return corto_define(_this);
}

void _parser_NodeSet(parser_Node _this, corto_uint32 line, corto_uint32 column) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
}

corto_string _parser_NodeStr(parser_Node value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_Node_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_Node parser_NodeFromStr(parser_Node value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_Node_o), str);
    return value;
}

corto_equalityKind _parser_NodeCompare(parser_Node dst, parser_Node src) {
    return corto_compare(dst, src);
}

parser_PrintVisitor _parser_PrintVisitorCreate(parser_BaseParser parser) {
    parser_PrintVisitor _this;
    _this = parser_PrintVisitor(corto_declare(parser_PrintVisitor_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_PrintVisitor _parser_PrintVisitorCreateChild(corto_object _parent, corto_string _name, parser_BaseParser parser) {
    parser_PrintVisitor _this;
    _this = parser_PrintVisitor(corto_declareChild(_parent, _name, parser_PrintVisitor_o));
    if (!_this) {
        return NULL;
    }
    corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_PrintVisitorUpdate(parser_PrintVisitor _this, parser_BaseParser parser) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_PrintVisitor _parser_PrintVisitorDeclare(void) {
    parser_PrintVisitor _this;
    _this = parser_PrintVisitor(corto_declare(parser_PrintVisitor_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_PrintVisitor _parser_PrintVisitorDeclareChild(corto_object _parent, corto_string _name) {
    parser_PrintVisitor _this;
    _this = parser_PrintVisitor(corto_declareChild(_parent, _name, parser_PrintVisitor_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_PrintVisitorDefine(parser_PrintVisitor _this, parser_BaseParser parser) {
    CORTO_UNUSED(_this);
    corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
    return corto_define(_this);
}

void _parser_PrintVisitorSet(parser_PrintVisitor _this, parser_BaseParser parser) {
    CORTO_UNUSED(_this);
    corto_setref(&((parser_BaseVisitor)_this)->parser, parser);
}

corto_string _parser_PrintVisitorStr(parser_PrintVisitor value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_PrintVisitor_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_PrintVisitor parser_PrintVisitorFromStr(parser_PrintVisitor value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_PrintVisitor_o), str);
    return value;
}

corto_equalityKind _parser_PrintVisitorCompare(parser_PrintVisitor dst, parser_PrintVisitor src) {
    return corto_compare(dst, src);
}

parser_ProgramNode _parser_ProgramNodeCreate(corto_uint32 line, corto_uint32 column, parser_StatementList statements) {
    parser_ProgramNode _this;
    _this = parser_ProgramNode(corto_declare(parser_ProgramNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_copyp(&((parser_ProgramNode)_this)->statements, parser_StatementList_o, &statements);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_ProgramNode _parser_ProgramNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column, parser_StatementList statements) {
    parser_ProgramNode _this;
    _this = parser_ProgramNode(corto_declareChild(_parent, _name, parser_ProgramNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_copyp(&((parser_ProgramNode)_this)->statements, parser_StatementList_o, &statements);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_ProgramNodeUpdate(parser_ProgramNode _this, corto_uint32 line, corto_uint32 column, parser_StatementList statements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((parser_Node)_this)->line = line;
        ((parser_Node)_this)->column = column;
        corto_copyp(&((parser_ProgramNode)_this)->statements, parser_StatementList_o, &statements);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_ProgramNode _parser_ProgramNodeDeclare(void) {
    parser_ProgramNode _this;
    _this = parser_ProgramNode(corto_declare(parser_ProgramNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_ProgramNode _parser_ProgramNodeDeclareChild(corto_object _parent, corto_string _name) {
    parser_ProgramNode _this;
    _this = parser_ProgramNode(corto_declareChild(_parent, _name, parser_ProgramNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_ProgramNodeDefine(parser_ProgramNode _this, corto_uint32 line, corto_uint32 column, parser_StatementList statements) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_copyp(&((parser_ProgramNode)_this)->statements, parser_StatementList_o, &statements);
    return corto_define(_this);
}

void _parser_ProgramNodeSet(parser_ProgramNode _this, corto_uint32 line, corto_uint32 column, parser_StatementList statements) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    corto_copyp(&((parser_ProgramNode)_this)->statements, parser_StatementList_o, &statements);
}

corto_string _parser_ProgramNodeStr(parser_ProgramNode value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_ProgramNode_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_ProgramNode parser_ProgramNodeFromStr(parser_ProgramNode value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_ProgramNode_o), str);
    return value;
}

corto_equalityKind _parser_ProgramNodeCompare(parser_ProgramNode dst, parser_ProgramNode src) {
    return corto_compare(dst, src);
}

parser_SimpleParser _parser_SimpleParserCreate(void) {
    parser_SimpleParser _this;
    _this = parser_SimpleParser(corto_declare(parser_SimpleParser_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_SimpleParser _parser_SimpleParserCreateChild(corto_object _parent, corto_string _name) {
    parser_SimpleParser _this;
    _this = parser_SimpleParser(corto_declareChild(_parent, _name, parser_SimpleParser_o));
    if (!_this) {
        return NULL;
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_SimpleParserUpdate(parser_SimpleParser _this) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_SimpleParser _parser_SimpleParserDeclare(void) {
    parser_SimpleParser _this;
    _this = parser_SimpleParser(corto_declare(parser_SimpleParser_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_SimpleParser _parser_SimpleParserDeclareChild(corto_object _parent, corto_string _name) {
    parser_SimpleParser _this;
    _this = parser_SimpleParser(corto_declareChild(_parent, _name, parser_SimpleParser_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_SimpleParserDefine(parser_SimpleParser _this) {
    CORTO_UNUSED(_this);
    return corto_define(_this);
}

void _parser_SimpleParserSet(parser_SimpleParser _this) {
    CORTO_UNUSED(_this);
}

corto_string _parser_SimpleParserStr(parser_SimpleParser value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_SimpleParser_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_SimpleParser parser_SimpleParserFromStr(parser_SimpleParser value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_SimpleParser_o), str);
    return value;
}

corto_equalityKind _parser_SimpleParserCompare(parser_SimpleParser dst, parser_SimpleParser src) {
    return corto_compare(dst, src);
}

parser_StatementList* _parser_StatementListCreate(corto_uint32 length, parser_StatementNode* elements) {
    parser_StatementList* _this;
    _this = parser_StatementList(corto_declare(parser_StatementList_o));
    if (!_this) {
        return NULL;
    }
    corto_uint32 i = 0;
    parser_StatementListClear(*_this);
    for (i = 0; i < length; i ++) {
        parser_StatementListAppend(*_this, elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_StatementList* _parser_StatementListCreateChild(corto_object _parent, corto_string _name, corto_uint32 length, parser_StatementNode* elements) {
    parser_StatementList* _this;
    _this = parser_StatementList(corto_declareChild(_parent, _name, parser_StatementList_o));
    if (!_this) {
        return NULL;
    }
    corto_uint32 i = 0;
    parser_StatementListClear(*_this);
    for (i = 0; i < length; i ++) {
        parser_StatementListAppend(*_this, elements[i]);
    }
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_StatementListUpdate(parser_StatementList* _this, corto_uint32 length, parser_StatementNode* elements) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        corto_uint32 i = 0;
        parser_StatementListClear(*_this);
        for (i = 0; i < length; i ++) {
            parser_StatementListAppend(*_this, elements[i]);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_StatementList* _parser_StatementListDeclare(void) {
    parser_StatementList* _this;
    _this = parser_StatementList(corto_declare(parser_StatementList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_StatementList* _parser_StatementListDeclareChild(corto_object _parent, corto_string _name) {
    parser_StatementList* _this;
    _this = parser_StatementList(corto_declareChild(_parent, _name, parser_StatementList_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_StatementListDefine(parser_StatementList* _this, corto_uint32 length, parser_StatementNode* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    parser_StatementListClear(*_this);
    for (i = 0; i < length; i ++) {
        parser_StatementListAppend(*_this, elements[i]);
    }
    return corto_define(_this);
}

void _parser_StatementListSet(parser_StatementList* _this, corto_uint32 length, parser_StatementNode* elements) {
    CORTO_UNUSED(_this);
    corto_uint32 i = 0;
    parser_StatementListClear(*_this);
    for (i = 0; i < length; i ++) {
        parser_StatementListAppend(*_this, elements[i]);
    }
}

corto_string _parser_StatementListStr(parser_StatementList value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(parser_StatementList_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

parser_StatementList* parser_StatementListFromStr(parser_StatementList* value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_StatementList_o), str);
    return value;
}

corto_equalityKind parser_StatementListCompare(parser_StatementList dst, parser_StatementList src) {
    return corto_comparep(&dst, parser_StatementList_o, &src);
}

corto_int16 _parser_StatementListInit(parser_StatementList* value) {
    corto_int16 result;
    memset(value, 0, corto_type(parser_StatementList_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(parser_StatementList_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _parser_StatementListDeinit(parser_StatementList* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(parser_StatementList_o), value);
    result = corto_deinitv(&v);
    return result;
}

parser_StatementNode _parser_StatementNodeCreate(corto_uint32 line, corto_uint32 column) {
    parser_StatementNode _this;
    _this = parser_StatementNode(corto_declare(parser_StatementNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

parser_StatementNode _parser_StatementNodeCreateChild(corto_object _parent, corto_string _name, corto_uint32 line, corto_uint32 column) {
    parser_StatementNode _this;
    _this = parser_StatementNode(corto_declareChild(_parent, _name, parser_StatementNode_o));
    if (!_this) {
        return NULL;
    }
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _parser_StatementNodeUpdate(parser_StatementNode _this, corto_uint32 line, corto_uint32 column) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((parser_Node)_this)->line = line;
        ((parser_Node)_this)->column = column;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

parser_StatementNode _parser_StatementNodeDeclare(void) {
    parser_StatementNode _this;
    _this = parser_StatementNode(corto_declare(parser_StatementNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

parser_StatementNode _parser_StatementNodeDeclareChild(corto_object _parent, corto_string _name) {
    parser_StatementNode _this;
    _this = parser_StatementNode(corto_declareChild(_parent, _name, parser_StatementNode_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _parser_StatementNodeDefine(parser_StatementNode _this, corto_uint32 line, corto_uint32 column) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
    return corto_define(_this);
}

void _parser_StatementNodeSet(parser_StatementNode _this, corto_uint32 line, corto_uint32 column) {
    CORTO_UNUSED(_this);
    ((parser_Node)_this)->line = line;
    ((parser_Node)_this)->column = column;
}

corto_string _parser_StatementNodeStr(parser_StatementNode value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(parser_StatementNode_o));
    result = corto_strv(&v, 0);
    return result;
}

parser_StatementNode parser_StatementNodeFromStr(parser_StatementNode value, corto_string str) {
    corto_fromStrp(&value, corto_type(parser_StatementNode_o), str);
    return value;
}

corto_equalityKind _parser_StatementNodeCompare(parser_StatementNode dst, parser_StatementNode src) {
    return corto_compare(dst, src);
}

void parser_ExpressionListInsert(parser_ExpressionList list, parser_ExpressionNode element) {
    corto_llInsert(list, (void*)(corto_word)element);
    corto_claim(element);
}

void parser_ExpressionListAppend(parser_ExpressionList list, parser_ExpressionNode element) {
    corto_llAppend(list, (void*)(corto_word)element);
    corto_claim(element);
}

void parser_ExpressionListRemove(parser_ExpressionList list, parser_ExpressionNode element) {
    corto_llRemove(list, element);
    corto_release(element);
}

parser_ExpressionNode parser_ExpressionListTakeFirst(parser_ExpressionList list) {
    return (parser_ExpressionNode)(corto_word)corto_llTakeFirst(list);
}

parser_ExpressionNode parser_ExpressionListLast(parser_ExpressionList list) {
    return (parser_ExpressionNode)(corto_word)corto_llLast(list);
}

parser_ExpressionNode parser_ExpressionListGet(parser_ExpressionList list, corto_uint32 index) {
    return (parser_ExpressionNode)(corto_word)corto_llGet(list, index);
}

corto_uint32 parser_ExpressionListSize(parser_ExpressionList list) {
    return corto_llSize(list);
}

void parser_ExpressionListClear(parser_ExpressionList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_release(ptr);
    }
    corto_llClear(list);
}

void parser_StatementListInsert(parser_StatementList list, parser_StatementNode element) {
    corto_llInsert(list, (void*)(corto_word)element);
    corto_claim(element);
}

void parser_StatementListAppend(parser_StatementList list, parser_StatementNode element) {
    corto_llAppend(list, (void*)(corto_word)element);
    corto_claim(element);
}

void parser_StatementListRemove(parser_StatementList list, parser_StatementNode element) {
    corto_llRemove(list, element);
    corto_release(element);
}

parser_StatementNode parser_StatementListTakeFirst(parser_StatementList list) {
    return (parser_StatementNode)(corto_word)corto_llTakeFirst(list);
}

parser_StatementNode parser_StatementListLast(parser_StatementList list) {
    return (parser_StatementNode)(corto_word)corto_llLast(list);
}

parser_StatementNode parser_StatementListGet(parser_StatementList list, corto_uint32 index) {
    return (parser_StatementNode)(corto_word)corto_llGet(list, index);
}

corto_uint32 parser_StatementListSize(parser_StatementList list) {
    return corto_llSize(list);
}

void parser_StatementListClear(parser_StatementList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_release(ptr);
    }
    corto_llClear(list);
}

void corto_stringListInsert(corto_stringList list, corto_string element) {
    corto_llInsert(list, (void*)(corto_word)element);
}

void corto_stringListAppend(corto_stringList list, corto_string element) {
    corto_llAppend(list, (void*)(corto_word)element);
}

corto_string corto_stringListTakeFirst(corto_stringList list) {
    return (corto_string)(corto_word)corto_llTakeFirst(list);
}

corto_string corto_stringListLast(corto_stringList list) {
    return (corto_string)(corto_word)corto_llLast(list);
}

corto_string corto_stringListGet(corto_stringList list, corto_uint32 index) {
    return (corto_string)(corto_word)corto_llGet(list, index);
}

corto_uint32 corto_stringListSize(corto_stringList list) {
    return corto_llSize(list);
}

void corto_stringListClear(corto_stringList list) {
    corto_iter iter = corto_llIter(list);
    while(corto_iterHasNext(&iter)) {
        void *ptr = corto_iterNext(&iter);
        corto_deinitp(ptr, corto_string_o);
    }
    corto_llClear(list);
}

