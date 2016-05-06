/* $CORTO_GENERATED
 *
 * TestCortoLanguage.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_TestCortoLanguage_setup(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/setup) */
    corto_setref(&_this->parser, parser_SimpleParserCreate());
/* $end */
}

corto_void _test_TestCortoLanguage_teardown(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/teardown) */
    corto_delete(_this->parser);
    _this->parser = NULL;
/* $end */
}

corto_void _test_TestCortoLanguage_test_addExpr(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_addExpr) */
    test_assert(parser_BaseParser_parse(_this->parser, "1, 3, 4\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "1, 3 + b, 4\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_assignmentExpr(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_assignmentExpr) */
    test_assert(parser_BaseParser_parse(_this->parser, "a = 5\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "a + (b = 6 + 4)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_atom(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_atom) */
    test_assert(parser_BaseParser_parse(_this->parser, "1\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "\"hello world\"\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "\"hello world\"\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_badToken(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_badToken) */
    test_assert(parser_BaseParser_parse(_this->parser, "4f\n") == -1);
    test_assert(corto_llSize(_this->parser->errors) == 1);
    /* TODO assert text in the error message */
/* $end */
}

corto_void _test_TestCortoLanguage_test_commaExpr(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_commaExpr) */
    test_assert(parser_BaseParser_parse(_this->parser, "1, 3, 4\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "1, 3 + b, 4\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_declaration1(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_declaration1) */
    test_assert(parser_BaseParser_parse(_this->parser, "int8 a\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "string a\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_declaration2(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_declaration2) */
    test_assert(parser_BaseParser_parse(_this->parser, "list{int8} a\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "list{elemType=int8} a\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_declaration3(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_declaration3) */
    test_assert(parser_BaseParser_parse(_this->parser, "list{int, 4, \"hi\"} a\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_declaration4(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_declaration4) */
    test_assert(parser_BaseParser_parse(_this->parser, "list{a=int8, b=c} a\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration1(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration1) */
    test_assert(parser_BaseParser_parse(_this->parser, "void myfunction()\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "void myfunction(int8 a)\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "void myfunction(int8 a, string b)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration2(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration2) */

    test_assert(TRUE);

/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration3(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration3) */

    test_assert(TRUE);

/* $end */
}

corto_void _test_TestCortoLanguage_test_logicAndExpr(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_logicAndExpr) */
    test_assert(parser_BaseParser_parse(_this->parser, "true and false\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "a == b and b == c\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_logicOrExpr(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_logicOrExpr) */
    test_assert(parser_BaseParser_parse(_this->parser, "true or false\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "(3 == a) or (4 == b)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_multExpr(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_multExpr) */
    test_assert(parser_BaseParser_parse(_this->parser, "4 * 9\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "4 * -8\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_scope1(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_scope1) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass:: INDENT a = b\n DEDENT\n"
    ) == 0);
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass:: INDENT a = b\n c = 1 + d\n DEDENT\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_scope2(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_scope2) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: BaseClass:: INDENT a = b\n DEDENT\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_scope3(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_scope3) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: base=BaseClass:: INDENT a = b\n DEDENT\n"
    ) == 0);
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: 1, base=BaseClass:: INDENT a = b\nc = d\n DEDENT\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_unary(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_unary) */
    test_assert(parser_BaseParser_parse(_this->parser, "-8\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "~2\n") == 0);
/* $end */
}
