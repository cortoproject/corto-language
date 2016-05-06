/* _api.cpp
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <test.h>
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
    corto_valueObjectInit(&v, value, corto_type(test_TestCortoLanguage_o));
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

