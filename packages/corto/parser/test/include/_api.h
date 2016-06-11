/* _api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef TEST__API_H
#define TEST__API_H

#include <corto/corto.h>
#include <_interface.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /test/Point */
TEST_EXPORT test_Point _test_PointCreate(corto_int32 x, corto_int32 y);
#define test_PointCreate(x, y) _test_PointCreate(x, y)
#define test_PointCreate_auto(_name, x, y) test_Point _name = test_PointCreate(x, y); (void)_name
TEST_EXPORT test_Point _test_PointCreateChild(corto_object _parent, corto_string _name, corto_int32 x, corto_int32 y);
#define test_PointCreateChild(_parent, _name, x, y) _test_PointCreateChild(_parent, _name, x, y)
#define test_PointCreateChild_auto(_parent, _name, x, y) test_Point _name = test_PointCreateChild(_parent, #_name, x, y); (void)_name
TEST_EXPORT corto_int16 _test_PointUpdate(test_Point _this, corto_int32 x, corto_int32 y);
#define test_PointUpdate(_this, x, y) _test_PointUpdate(test_Point(_this), x, y)

TEST_EXPORT test_Point _test_PointDeclare(void);
#define test_PointDeclare() _test_PointDeclare()
#define test_PointDeclare_auto(_name) test_Point _name = test_PointDeclare(); (void)_name
TEST_EXPORT test_Point _test_PointDeclareChild(corto_object _parent, corto_string _name);
#define test_PointDeclareChild(_parent, _name) _test_PointDeclareChild(_parent, _name)
#define test_PointDeclareChild_auto(_parent, _name) test_Point _name = test_PointDeclareChild(_parent, #_name); (void)_name
TEST_EXPORT corto_int16 _test_PointDefine(test_Point _this, corto_int32 x, corto_int32 y);
#define test_PointDefine(_this, x, y) _test_PointDefine(test_Point(_this), x, y)
TEST_EXPORT void _test_PointSet(test_Point _this, corto_int32 x, corto_int32 y);
#define test_PointSet(_this, x, y) _test_PointSet(test_Point(_this), x, y)
TEST_EXPORT corto_string _test_PointStr(test_Point value);
#define test_PointStr(value) _test_PointStr(test_Point(value))
TEST_EXPORT test_Point test_PointFromStr(test_Point value, corto_string str);
TEST_EXPORT corto_equalityKind _test_PointCompare(test_Point dst, test_Point src);
#define test_PointCompare(dst, src) _test_PointCompare(test_Point(dst), test_Point(src))

/* /test/TestCortoLanguage */
TEST_EXPORT test_TestCortoLanguage _test_TestCortoLanguageCreate(corto_uint32 assertCount, parser_SimpleParser parser);
#define test_TestCortoLanguageCreate(assertCount, parser) _test_TestCortoLanguageCreate(assertCount, parser_SimpleParser(parser))
#define test_TestCortoLanguageCreate_auto(_name, assertCount, parser) test_TestCortoLanguage _name = test_TestCortoLanguageCreate(assertCount, parser); (void)_name
TEST_EXPORT test_TestCortoLanguage _test_TestCortoLanguageCreateChild(corto_object _parent, corto_string _name, corto_uint32 assertCount, parser_SimpleParser parser);
#define test_TestCortoLanguageCreateChild(_parent, _name, assertCount, parser) _test_TestCortoLanguageCreateChild(_parent, _name, assertCount, parser_SimpleParser(parser))
#define test_TestCortoLanguageCreateChild_auto(_parent, _name, assertCount, parser) test_TestCortoLanguage _name = test_TestCortoLanguageCreateChild(_parent, #_name, assertCount, parser); (void)_name
TEST_EXPORT corto_int16 _test_TestCortoLanguageUpdate(test_TestCortoLanguage _this, corto_uint32 assertCount, parser_SimpleParser parser);
#define test_TestCortoLanguageUpdate(_this, assertCount, parser) _test_TestCortoLanguageUpdate(test_TestCortoLanguage(_this), assertCount, parser_SimpleParser(parser))

TEST_EXPORT test_TestCortoLanguage _test_TestCortoLanguageDeclare(void);
#define test_TestCortoLanguageDeclare() _test_TestCortoLanguageDeclare()
#define test_TestCortoLanguageDeclare_auto(_name) test_TestCortoLanguage _name = test_TestCortoLanguageDeclare(); (void)_name
TEST_EXPORT test_TestCortoLanguage _test_TestCortoLanguageDeclareChild(corto_object _parent, corto_string _name);
#define test_TestCortoLanguageDeclareChild(_parent, _name) _test_TestCortoLanguageDeclareChild(_parent, _name)
#define test_TestCortoLanguageDeclareChild_auto(_parent, _name) test_TestCortoLanguage _name = test_TestCortoLanguageDeclareChild(_parent, #_name); (void)_name
TEST_EXPORT corto_int16 _test_TestCortoLanguageDefine(test_TestCortoLanguage _this, corto_uint32 assertCount, parser_SimpleParser parser);
#define test_TestCortoLanguageDefine(_this, assertCount, parser) _test_TestCortoLanguageDefine(test_TestCortoLanguage(_this), assertCount, parser_SimpleParser(parser))
TEST_EXPORT void _test_TestCortoLanguageSet(test_TestCortoLanguage _this, corto_uint32 assertCount, parser_SimpleParser parser);
#define test_TestCortoLanguageSet(_this, assertCount, parser) _test_TestCortoLanguageSet(test_TestCortoLanguage(_this), assertCount, parser_SimpleParser(parser))
TEST_EXPORT corto_string _test_TestCortoLanguageStr(test_TestCortoLanguage value);
#define test_TestCortoLanguageStr(value) _test_TestCortoLanguageStr(test_TestCortoLanguage(value))
TEST_EXPORT test_TestCortoLanguage test_TestCortoLanguageFromStr(test_TestCortoLanguage value, corto_string str);
TEST_EXPORT corto_equalityKind _test_TestCortoLanguageCompare(test_TestCortoLanguage dst, test_TestCortoLanguage src);
#define test_TestCortoLanguageCompare(dst, src) _test_TestCortoLanguageCompare(test_TestCortoLanguage(dst), test_TestCortoLanguage(src))

/* /test/TestDeclarationVisitor */
TEST_EXPORT test_TestDeclarationVisitor _test_TestDeclarationVisitorCreate(corto_uint32 assertCount);
#define test_TestDeclarationVisitorCreate(assertCount) _test_TestDeclarationVisitorCreate(assertCount)
#define test_TestDeclarationVisitorCreate_auto(_name, assertCount) test_TestDeclarationVisitor _name = test_TestDeclarationVisitorCreate(assertCount); (void)_name
TEST_EXPORT test_TestDeclarationVisitor _test_TestDeclarationVisitorCreateChild(corto_object _parent, corto_string _name, corto_uint32 assertCount);
#define test_TestDeclarationVisitorCreateChild(_parent, _name, assertCount) _test_TestDeclarationVisitorCreateChild(_parent, _name, assertCount)
#define test_TestDeclarationVisitorCreateChild_auto(_parent, _name, assertCount) test_TestDeclarationVisitor _name = test_TestDeclarationVisitorCreateChild(_parent, #_name, assertCount); (void)_name
TEST_EXPORT corto_int16 _test_TestDeclarationVisitorUpdate(test_TestDeclarationVisitor _this, corto_uint32 assertCount);
#define test_TestDeclarationVisitorUpdate(_this, assertCount) _test_TestDeclarationVisitorUpdate(test_TestDeclarationVisitor(_this), assertCount)

TEST_EXPORT test_TestDeclarationVisitor _test_TestDeclarationVisitorDeclare(void);
#define test_TestDeclarationVisitorDeclare() _test_TestDeclarationVisitorDeclare()
#define test_TestDeclarationVisitorDeclare_auto(_name) test_TestDeclarationVisitor _name = test_TestDeclarationVisitorDeclare(); (void)_name
TEST_EXPORT test_TestDeclarationVisitor _test_TestDeclarationVisitorDeclareChild(corto_object _parent, corto_string _name);
#define test_TestDeclarationVisitorDeclareChild(_parent, _name) _test_TestDeclarationVisitorDeclareChild(_parent, _name)
#define test_TestDeclarationVisitorDeclareChild_auto(_parent, _name) test_TestDeclarationVisitor _name = test_TestDeclarationVisitorDeclareChild(_parent, #_name); (void)_name
TEST_EXPORT corto_int16 _test_TestDeclarationVisitorDefine(test_TestDeclarationVisitor _this, corto_uint32 assertCount);
#define test_TestDeclarationVisitorDefine(_this, assertCount) _test_TestDeclarationVisitorDefine(test_TestDeclarationVisitor(_this), assertCount)
TEST_EXPORT void _test_TestDeclarationVisitorSet(test_TestDeclarationVisitor _this, corto_uint32 assertCount);
#define test_TestDeclarationVisitorSet(_this, assertCount) _test_TestDeclarationVisitorSet(test_TestDeclarationVisitor(_this), assertCount)
TEST_EXPORT corto_string _test_TestDeclarationVisitorStr(test_TestDeclarationVisitor value);
#define test_TestDeclarationVisitorStr(value) _test_TestDeclarationVisitorStr(test_TestDeclarationVisitor(value))
TEST_EXPORT test_TestDeclarationVisitor test_TestDeclarationVisitorFromStr(test_TestDeclarationVisitor value, corto_string str);
TEST_EXPORT corto_equalityKind _test_TestDeclarationVisitorCompare(test_TestDeclarationVisitor dst, test_TestDeclarationVisitor src);
#define test_TestDeclarationVisitorCompare(dst, src) _test_TestDeclarationVisitorCompare(test_TestDeclarationVisitor(dst), test_TestDeclarationVisitor(src))

/* /test/TestPrintVisitor */
TEST_EXPORT test_TestPrintVisitor _test_TestPrintVisitorCreate(corto_uint32 assertCount);
#define test_TestPrintVisitorCreate(assertCount) _test_TestPrintVisitorCreate(assertCount)
#define test_TestPrintVisitorCreate_auto(_name, assertCount) test_TestPrintVisitor _name = test_TestPrintVisitorCreate(assertCount); (void)_name
TEST_EXPORT test_TestPrintVisitor _test_TestPrintVisitorCreateChild(corto_object _parent, corto_string _name, corto_uint32 assertCount);
#define test_TestPrintVisitorCreateChild(_parent, _name, assertCount) _test_TestPrintVisitorCreateChild(_parent, _name, assertCount)
#define test_TestPrintVisitorCreateChild_auto(_parent, _name, assertCount) test_TestPrintVisitor _name = test_TestPrintVisitorCreateChild(_parent, #_name, assertCount); (void)_name
TEST_EXPORT corto_int16 _test_TestPrintVisitorUpdate(test_TestPrintVisitor _this, corto_uint32 assertCount);
#define test_TestPrintVisitorUpdate(_this, assertCount) _test_TestPrintVisitorUpdate(test_TestPrintVisitor(_this), assertCount)

TEST_EXPORT test_TestPrintVisitor _test_TestPrintVisitorDeclare(void);
#define test_TestPrintVisitorDeclare() _test_TestPrintVisitorDeclare()
#define test_TestPrintVisitorDeclare_auto(_name) test_TestPrintVisitor _name = test_TestPrintVisitorDeclare(); (void)_name
TEST_EXPORT test_TestPrintVisitor _test_TestPrintVisitorDeclareChild(corto_object _parent, corto_string _name);
#define test_TestPrintVisitorDeclareChild(_parent, _name) _test_TestPrintVisitorDeclareChild(_parent, _name)
#define test_TestPrintVisitorDeclareChild_auto(_parent, _name) test_TestPrintVisitor _name = test_TestPrintVisitorDeclareChild(_parent, #_name); (void)_name
TEST_EXPORT corto_int16 _test_TestPrintVisitorDefine(test_TestPrintVisitor _this, corto_uint32 assertCount);
#define test_TestPrintVisitorDefine(_this, assertCount) _test_TestPrintVisitorDefine(test_TestPrintVisitor(_this), assertCount)
TEST_EXPORT void _test_TestPrintVisitorSet(test_TestPrintVisitor _this, corto_uint32 assertCount);
#define test_TestPrintVisitorSet(_this, assertCount) _test_TestPrintVisitorSet(test_TestPrintVisitor(_this), assertCount)
TEST_EXPORT corto_string _test_TestPrintVisitorStr(test_TestPrintVisitor value);
#define test_TestPrintVisitorStr(value) _test_TestPrintVisitorStr(test_TestPrintVisitor(value))
TEST_EXPORT test_TestPrintVisitor test_TestPrintVisitorFromStr(test_TestPrintVisitor value, corto_string str);
TEST_EXPORT corto_equalityKind _test_TestPrintVisitorCompare(test_TestPrintVisitor dst, test_TestPrintVisitor src);
#define test_TestPrintVisitorCompare(dst, src) _test_TestPrintVisitorCompare(test_TestPrintVisitor(dst), test_TestPrintVisitor(src))


#ifdef __cplusplus
}
#endif
#endif

