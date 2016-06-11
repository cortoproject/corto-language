/* _api.cpp
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <test.h>
test_Point _test_PointCreate(corto_int32 x, corto_int32 y) {
    test_Point _this;
    _this = test_Point(corto_declare(test_Point_o));
    if (!_this) {
        return NULL;
    }
    ((test_Point)_this)->x = x;
    ((test_Point)_this)->y = y;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

test_Point _test_PointCreateChild(corto_object _parent, corto_string _name, corto_int32 x, corto_int32 y) {
    test_Point _this;
    _this = test_Point(corto_declareChild(_parent, _name, test_Point_o));
    if (!_this) {
        return NULL;
    }
    ((test_Point)_this)->x = x;
    ((test_Point)_this)->y = y;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _test_PointUpdate(test_Point _this, corto_int32 x, corto_int32 y) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((test_Point)_this)->x = x;
        ((test_Point)_this)->y = y;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_Point _test_PointDeclare(void) {
    test_Point _this;
    _this = test_Point(corto_declare(test_Point_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_Point _test_PointDeclareChild(corto_object _parent, corto_string _name) {
    test_Point _this;
    _this = test_Point(corto_declareChild(_parent, _name, test_Point_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_PointDefine(test_Point _this, corto_int32 x, corto_int32 y) {
    CORTO_UNUSED(_this);
    ((test_Point)_this)->x = x;
    ((test_Point)_this)->y = y;
    return corto_define(_this);
}

void _test_PointSet(test_Point _this, corto_int32 x, corto_int32 y) {
    CORTO_UNUSED(_this);
    ((test_Point)_this)->x = x;
    ((test_Point)_this)->y = y;
}

corto_string _test_PointStr(test_Point value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_Point_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Point test_PointFromStr(test_Point value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Point_o), str);
    return value;
}

corto_equalityKind _test_PointCompare(test_Point dst, test_Point src) {
    return corto_compare(dst, src);
}

test_TestCortoLanguage _test_TestCortoLanguageCreate(corto_uint32 assertCount, parser_SimpleParser parser) {
    test_TestCortoLanguage _this;
    _this = test_TestCortoLanguage(corto_declare(test_TestCortoLanguage_o));
    if (!_this) {
        return NULL;
    }
    ((test_SuiteData)_this)->assertCount = assertCount;
    corto_setref(&((test_TestCortoLanguage)_this)->parser, parser);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

test_TestCortoLanguage _test_TestCortoLanguageCreateChild(corto_object _parent, corto_string _name, corto_uint32 assertCount, parser_SimpleParser parser) {
    test_TestCortoLanguage _this;
    _this = test_TestCortoLanguage(corto_declareChild(_parent, _name, test_TestCortoLanguage_o));
    if (!_this) {
        return NULL;
    }
    ((test_SuiteData)_this)->assertCount = assertCount;
    corto_setref(&((test_TestCortoLanguage)_this)->parser, parser);
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _test_TestCortoLanguageUpdate(test_TestCortoLanguage _this, corto_uint32 assertCount, parser_SimpleParser parser) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        corto_setref(&((test_TestCortoLanguage)_this)->parser, parser);
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TestCortoLanguage _test_TestCortoLanguageDeclare(void) {
    test_TestCortoLanguage _this;
    _this = test_TestCortoLanguage(corto_declare(test_TestCortoLanguage_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TestCortoLanguage _test_TestCortoLanguageDeclareChild(corto_object _parent, corto_string _name) {
    test_TestCortoLanguage _this;
    _this = test_TestCortoLanguage(corto_declareChild(_parent, _name, test_TestCortoLanguage_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TestCortoLanguageDefine(test_TestCortoLanguage _this, corto_uint32 assertCount, parser_SimpleParser parser) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    corto_setref(&((test_TestCortoLanguage)_this)->parser, parser);
    return corto_define(_this);
}

void _test_TestCortoLanguageSet(test_TestCortoLanguage _this, corto_uint32 assertCount, parser_SimpleParser parser) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    corto_setref(&((test_TestCortoLanguage)_this)->parser, parser);
}

corto_string _test_TestCortoLanguageStr(test_TestCortoLanguage value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TestCortoLanguage_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TestCortoLanguage test_TestCortoLanguageFromStr(test_TestCortoLanguage value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TestCortoLanguage_o), str);
    return value;
}

corto_equalityKind _test_TestCortoLanguageCompare(test_TestCortoLanguage dst, test_TestCortoLanguage src) {
    return corto_compare(dst, src);
}

test_TestDeclarationVisitor _test_TestDeclarationVisitorCreate(corto_uint32 assertCount) {
    test_TestDeclarationVisitor _this;
    _this = test_TestDeclarationVisitor(corto_declare(test_TestDeclarationVisitor_o));
    if (!_this) {
        return NULL;
    }
    ((test_SuiteData)_this)->assertCount = assertCount;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

test_TestDeclarationVisitor _test_TestDeclarationVisitorCreateChild(corto_object _parent, corto_string _name, corto_uint32 assertCount) {
    test_TestDeclarationVisitor _this;
    _this = test_TestDeclarationVisitor(corto_declareChild(_parent, _name, test_TestDeclarationVisitor_o));
    if (!_this) {
        return NULL;
    }
    ((test_SuiteData)_this)->assertCount = assertCount;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _test_TestDeclarationVisitorUpdate(test_TestDeclarationVisitor _this, corto_uint32 assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TestDeclarationVisitor _test_TestDeclarationVisitorDeclare(void) {
    test_TestDeclarationVisitor _this;
    _this = test_TestDeclarationVisitor(corto_declare(test_TestDeclarationVisitor_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TestDeclarationVisitor _test_TestDeclarationVisitorDeclareChild(corto_object _parent, corto_string _name) {
    test_TestDeclarationVisitor _this;
    _this = test_TestDeclarationVisitor(corto_declareChild(_parent, _name, test_TestDeclarationVisitor_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TestDeclarationVisitorDefine(test_TestDeclarationVisitor _this, corto_uint32 assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

void _test_TestDeclarationVisitorSet(test_TestDeclarationVisitor _this, corto_uint32 assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
}

corto_string _test_TestDeclarationVisitorStr(test_TestDeclarationVisitor value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TestDeclarationVisitor_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TestDeclarationVisitor test_TestDeclarationVisitorFromStr(test_TestDeclarationVisitor value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TestDeclarationVisitor_o), str);
    return value;
}

corto_equalityKind _test_TestDeclarationVisitorCompare(test_TestDeclarationVisitor dst, test_TestDeclarationVisitor src) {
    return corto_compare(dst, src);
}

test_TestPrintVisitor _test_TestPrintVisitorCreate(corto_uint32 assertCount) {
    test_TestPrintVisitor _this;
    _this = test_TestPrintVisitor(corto_declare(test_TestPrintVisitor_o));
    if (!_this) {
        return NULL;
    }
    ((test_SuiteData)_this)->assertCount = assertCount;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

test_TestPrintVisitor _test_TestPrintVisitorCreateChild(corto_object _parent, corto_string _name, corto_uint32 assertCount) {
    test_TestPrintVisitor _this;
    _this = test_TestPrintVisitor(corto_declareChild(_parent, _name, test_TestPrintVisitor_o));
    if (!_this) {
        return NULL;
    }
    ((test_SuiteData)_this)->assertCount = assertCount;
    if (corto_define(_this)) {
        corto_release(_this);
        _this = NULL;
    }
    return _this;
}

corto_int16 _test_TestPrintVisitorUpdate(test_TestPrintVisitor _this, corto_uint32 assertCount) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        ((test_SuiteData)_this)->assertCount = assertCount;
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

test_TestPrintVisitor _test_TestPrintVisitorDeclare(void) {
    test_TestPrintVisitor _this;
    _this = test_TestPrintVisitor(corto_declare(test_TestPrintVisitor_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

test_TestPrintVisitor _test_TestPrintVisitorDeclareChild(corto_object _parent, corto_string _name) {
    test_TestPrintVisitor _this;
    _this = test_TestPrintVisitor(corto_declareChild(_parent, _name, test_TestPrintVisitor_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _test_TestPrintVisitorDefine(test_TestPrintVisitor _this, corto_uint32 assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
    return corto_define(_this);
}

void _test_TestPrintVisitorSet(test_TestPrintVisitor _this, corto_uint32 assertCount) {
    CORTO_UNUSED(_this);
    ((test_SuiteData)_this)->assertCount = assertCount;
}

corto_string _test_TestPrintVisitorStr(test_TestPrintVisitor value) {
    corto_string result;
    corto_value v;
    v = corto_value_object(value, corto_type(test_TestPrintVisitor_o));
    result = corto_strv(&v, 0);
    return result;
}

test_TestPrintVisitor test_TestPrintVisitorFromStr(test_TestPrintVisitor value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_TestPrintVisitor_o), str);
    return value;
}

corto_equalityKind _test_TestPrintVisitorCompare(test_TestPrintVisitor dst, test_TestPrintVisitor src) {
    return corto_compare(dst, src);
}

