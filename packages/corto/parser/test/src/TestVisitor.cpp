/* $CORTO_GENERATED
 *
 * TestVisitor.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

/* $header() */

corto_void _testExpectedBuffer(char* input, char* expected)
{
    parser_SimpleParser parser = parser_SimpleParserCreate();
    test_assert(parser_BaseParser_parse(parser, input) == 0);
    parser_PrintVisitor visitor = parser_PrintVisitorCreate(parser);
    parser_BaseVisitor_visit(visitor);
    
    char* actual = parser_PrintVisitor_getText(visitor);
    int error = !actual ? -1 : strcmp(actual, expected);
    if (error) {
        corto_error("for input:\n%s\nexpected:\n%s\nactual:\n%s\n", input, expected, actual);
        if (actual) {
            corto_dealloc(actual);
        }
        test_assert(error == 0);
    }

    corto_delete(visitor);
    corto_delete(parser);
}

/* $end */

corto_void _test_TestVisitor_test_ConditionalExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_ConditionalExpression1) */
    char* input =
        "a = b ? c : d\n"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_ConditionalExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_ConditionalExpression2) */
    char* input =
        "a = b ? c : (d ? e : f)\n"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_equalityExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_equalityExpression1) */
    char* input =
        "a < b and b > c and c <= d == d >= e or a != b"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_equalityExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_equalityExpression2) */
    char* input =
        "a == b\n"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_logicAndExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_logicAndExpression1) */
    char* input =
        "p and q\n"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_logicAndExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_logicAndExpression2) */
    char* input =
        "a and b == c\n"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_logicOrExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_logicOrExpression1) */
    char* input =
        "a or b\n"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_logicOrExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_logicOrExpression2) */
    char* input =
        "a or b and c or d\n"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_visitorAssignment(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_visitorAssignment) */
    char* input =
        "a = 1\n"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_visitorAtom(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_visitorAtom) */
    char* input = "1";
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_visitorCommaExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_visitorCommaExpression1) */
    char* input =
        "1, 2, 3\n"
        ;
    char* expected = "";
    _testExpectedBuffer(input, expected);
/* $end */
}
