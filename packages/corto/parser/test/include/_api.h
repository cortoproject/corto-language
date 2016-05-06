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


#ifdef __cplusplus
}
#endif
#endif

