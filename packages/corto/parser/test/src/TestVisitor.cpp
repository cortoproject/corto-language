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

corto_void _test_TestVisitor_test_addExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_addExpression1) */
    char* input =
        "a + b + -c * d - b"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   binary expression\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: a\n"
"|   |   |   |   |   operator: ADD\n"
"|   |   |   |   |   identifier: b\n"
"|   |   |   |   operator: ADD\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   unary expression\n"
"|   |   |   |   |   |   operator: SUB\n"
"|   |   |   |   |   |   identifier: c\n"
"|   |   |   |   |   operator: MUL\n"
"|   |   |   |   |   identifier: d\n"
"|   |   |   operator: SUB\n"
"|   |   |   identifier: b\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_bitAndExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_bitAndExpression1) */
    char* input =
        "a & b"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   identifier: a\n"
"|   |   |   operator: AND\n"
"|   |   |   identifier: b\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_bitOrExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_bitOrExpression1) */
    char* input =
        "flags = flags | isInactive"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   identifier: flags\n"
"|   |   |   operator: ASSIGN\n"
"|   |   |   binary expression\n"
"|   |   |   |   identifier: flags\n"
"|   |   |   |   operator: OR\n"
"|   |   |   |   identifier: isInactive\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_bitOrExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_bitOrExpression2) */
    char* input =
        "r & a | 32 | 1024"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   binary expression\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: r\n"
"|   |   |   |   |   operator: AND\n"
"|   |   |   |   |   identifier: a\n"
"|   |   |   |   operator: OR\n"
"|   |   |   |   literal\n"
"|   |   |   operator: OR\n"
"|   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_callExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_callExpression1) */
    char* input =
        "myFun(1, 3 + 4) + moreFun(a, b)"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   call\n"
"|   |   |   |   identifier: myFun\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   binary expression\n"
"|   |   |   |   |   |   literal\n"
"|   |   |   |   |   |   operator: ADD\n"
"|   |   |   |   |   |   literal\n"
"|   |   |   operator: ADD\n"
"|   |   |   call\n"
"|   |   |   |   identifier: moreFun\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   identifier: a\n"
"|   |   |   |   |   identifier: b\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_callExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_callExpression2) */
    char* input =
        "Obj.myFun(1, 3 + 4) + moreFun(a, hi.there())"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   call\n"
"|   |   |   |   member expression\n"
"|   |   |   |   |   identifier: Obj\n"
"|   |   |   |   |   member: myFun\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   binary expression\n"
"|   |   |   |   |   |   literal\n"
"|   |   |   |   |   |   operator: ADD\n"
"|   |   |   |   |   |   literal\n"
"|   |   |   operator: ADD\n"
"|   |   |   call\n"
"|   |   |   |   identifier: moreFun\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   identifier: a\n"
"|   |   |   |   |   call\n"
"|   |   |   |   |   |   member expression\n"
"|   |   |   |   |   |   |   identifier: hi\n"
"|   |   |   |   |   |   |   member: there\n"
"|   |   |   |   |   |   full comma expression\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_comparisonExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_comparisonExpression1) */
    char* input =
        "5 + a < b or a < c == r >= b"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   binary expression\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   operator: ADD\n"
"|   |   |   |   |   identifier: a\n"
"|   |   |   |   operator: COND_LT\n"
"|   |   |   |   identifier: b\n"
"|   |   |   operator: COND_OR\n"
"|   |   |   binary expression\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: a\n"
"|   |   |   |   |   operator: COND_LT\n"
"|   |   |   |   |   identifier: c\n"
"|   |   |   |   operator: COND_EQ\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: r\n"
"|   |   |   |   |   operator: COND_GTEQ\n"
"|   |   |   |   |   identifier: b\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_comparisonExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_comparisonExpression2) */
    char* input =
        "a < b and b > c and c <= d == d >= e"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   binary expression\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: a\n"
"|   |   |   |   |   operator: COND_LT\n"
"|   |   |   |   |   identifier: b\n"
"|   |   |   |   operator: COND_AND\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: b\n"
"|   |   |   |   |   operator: COND_GT\n"
"|   |   |   |   |   identifier: c\n"
"|   |   |   operator: COND_AND\n"
"|   |   |   binary expression\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: c\n"
"|   |   |   |   |   operator: COND_LTEQ\n"
"|   |   |   |   |   identifier: d\n"
"|   |   |   |   operator: COND_EQ\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: d\n"
"|   |   |   |   |   operator: COND_GTEQ\n"
"|   |   |   |   |   identifier: e\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_ConditionalExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_ConditionalExpression1) */
    char* input =
        "a = b ? c : d\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   identifier: a\n"
"|   |   |   operator: ASSIGN\n"
"|   |   |   conditional expression\n"
"|   |   |   |   identifier: b\n"
"|   |   |   |   identifier: c\n"
"|   |   |   |   identifier: d\n"
    ;
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
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   identifier: a\n"
"|   |   |   operator: ASSIGN\n"
"|   |   |   conditional expression\n"
"|   |   |   |   identifier: b\n"
"|   |   |   |   identifier: c\n"
"|   |   |   |   conditional expression\n"
"|   |   |   |   |   identifier: d\n"
"|   |   |   |   |   identifier: e\n"
"|   |   |   |   |   identifier: f\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_elementExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_elementExpression1) */
    char* input =
        "a[1] = 4"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   element expression\n"
"|   |   |   |   identifier: a\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   operator: ASSIGN\n"
"|   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_elementExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_elementExpression2) */
    char* input =
        "a[1, 2, 3] = b[a, 5, 6 + c]"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   element expression\n"
"|   |   |   |   identifier: a\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
"|   |   |   operator: ASSIGN\n"
"|   |   |   element expression\n"
"|   |   |   |   identifier: b\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   identifier: a\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   binary expression\n"
"|   |   |   |   |   |   literal\n"
"|   |   |   |   |   |   operator: ADD\n"
"|   |   |   |   |   |   identifier: c\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_equalityExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_equalityExpression1) */
    char* input =
        "a == (b != c)"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   identifier: a\n"
"|   |   |   operator: COND_EQ\n"
"|   |   |   binary expression\n"
"|   |   |   |   identifier: b\n"
"|   |   |   |   operator: COND_NEQ\n"
"|   |   |   |   identifier: c\n"
    ;
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
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   identifier: a\n"
"|   |   |   operator: COND_EQ\n"
"|   |   |   identifier: b\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_functionDeclaration1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_functionDeclaration1) */
    char* input =
        "void myFunction()\n"
        ;
    char* expected =
"program"
"|   statement"
"|   |   function declaration: myFunction"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_functionDeclaration2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_functionDeclaration2) */
    char* input =
        "void myFunction(int8 a, string b)\n"
        ;
    char* expected =
""
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_functionDeclaration3(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_functionDeclaration3) */
    char* input =
        "list{int32} duplicate(list{int32} input)\n"
        ;
    char* expected =
""
    ;
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
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   identifier: p\n"
"|   |   |   operator: COND_AND\n"
"|   |   |   identifier: q\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_logicAndExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_logicAndExpression2) */
    char* input =
        "a and b == c and isEnabled\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   binary expression\n"
"|   |   |   |   identifier: a\n"
"|   |   |   |   operator: COND_AND\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: b\n"
"|   |   |   |   |   operator: COND_EQ\n"
"|   |   |   |   |   identifier: c\n"
"|   |   |   operator: COND_AND\n"
"|   |   |   identifier: isEnabled\n"
    ;
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
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   identifier: a\n"
"|   |   |   operator: COND_OR\n"
"|   |   |   identifier: b\n"
    ;
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
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   binary expression\n"
"|   |   |   |   identifier: a\n"
"|   |   |   |   operator: COND_OR\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   identifier: b\n"
"|   |   |   |   |   operator: COND_AND\n"
"|   |   |   |   |   identifier: c\n"
"|   |   |   operator: COND_OR\n"
"|   |   |   identifier: d\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_memberExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_memberExpression1) */
    char* input =
        "myObject.itsMember"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   member expression\n"
"|   |   |   identifier: myObject\n"
"|   |   |   member: itsMember\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_memberExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_memberExpression2) */
    char* input =
        "myObject.itsMember.itsOtherMember"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   member expression\n"
"|   |   |   member expression\n"
"|   |   |   |   identifier: myObject\n"
"|   |   |   |   member: itsMember\n"
"|   |   |   member: itsOtherMember\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_multExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_multExpression1) */
        char* input =
        "a * b / c / -d * e\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   binary expression\n"
"|   |   |   |   binary expression\n"
"|   |   |   |   |   binary expression\n"
"|   |   |   |   |   |   identifier: a\n"
"|   |   |   |   |   |   operator: MUL\n"
"|   |   |   |   |   |   identifier: b\n"
"|   |   |   |   |   operator: DIV\n"
"|   |   |   |   |   identifier: c\n"
"|   |   |   |   operator: DIV\n"
"|   |   |   |   unary expression\n"
"|   |   |   |   |   operator: SUB\n"
"|   |   |   |   |   identifier: d\n"
"|   |   |   operator: MUL\n"
"|   |   |   identifier: e\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration1) */
    char* input =
        "string s\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   type: string\n"
"|   |   |   name: s\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration10(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration10) */
    char* input =
        "SomeType{1}{2} a\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   initializer type expression node\n"
"|   |   |   |   initializer type expression node\n"
"|   |   |   |   |   type: SomeType\n"
"|   |   |   |   |   full comma expression\n"
"|   |   |   |   |   |   literal\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   name: a\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration11(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration11) */
    char* input =
        "bitmask flags:: isActive, isAdmin, isRemote\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   type: bitmask\n"
"|   |   |   name: flags\n"
"|   |   |   scope (post scope? 1)\n"
"|   |   |   |   statement\n"
"|   |   |   |   |   object declaration\n"
"|   |   |   |   |   |   name: isActive\n"
"|   |   |   |   |   |   name: isAdmin\n"
"|   |   |   |   |   |   name: isRemote\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration2) */
    char* input =
        "string s: 8\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   type: string\n"
"|   |   |   name: s\n"
"|   |   |   full comma expression\n"
"|   |   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration3(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration3) */
    char* input =
        "numberarray a: 1, 2, 3, 4\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   type: numberarray\n"
"|   |   |   name: a\n"
"|   |   |   full comma expression\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration4(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration4) */
    char* input =
        "numberarray a{1, 2, 3, 4}\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   type: numberarray\n"
"|   |   |   name: a\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration5(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration5) */
    char* input =
        "numberarray a, b, c\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   type: numberarray\n"
"|   |   |   name: a\n"
"|   |   |   name: b\n"
"|   |   |   name: c\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration6(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration6) */
    char* input =
        "MyClass a, b{4, 5}, c{4, 6}\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   type: MyClass\n"
"|   |   |   name: a\n"
"|   |   |   name: b\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
"|   |   |   name: c\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration7(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration7) */
    char* input =
        "MyClass a, b{4, 5}, c{4, 6}: 4, 5, 6, \"xyz\"\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   type: MyClass\n"
"|   |   |   name: a\n"
"|   |   |   name: b\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
"|   |   |   name: c\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
"|   |   |   full comma expression\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration8(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration8) */
    char* input =
        "MyClass a, b{4, 5}, c{4, 6}: 4, 5, 6, \"xyz\"::\n"
        "     c = d\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   type: MyClass\n"
"|   |   |   name: a\n"
"|   |   |   name: b\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
"|   |   |   name: c\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   literal\n"
"|   |   |   |   |   literal\n"
"|   |   |   full comma expression\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
"|   |   |   scope (post scope? 1)\n"
"|   |   |   |   statement\n"
"|   |   |   |   |   binary expression\n"
"|   |   |   |   |   |   identifier: c\n"
"|   |   |   |   |   |   operator: ASSIGN\n"
"|   |   |   |   |   |   identifier: d\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_objectDeclaration9(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_objectDeclaration9) */
    char* input =
        "list{int8} numberlist: 1, 2, 3"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   object declaration\n"
"|   |   |   initializer type expression node\n"
"|   |   |   |   type: list\n"
"|   |   |   |   full comma expression\n"
"|   |   |   |   |   identifier: int8\n"
"|   |   |   name: numberlist\n"
"|   |   |   full comma expression\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
"|   |   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_shiftExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_shiftExpression1) */
    char* input =
        "a << 1 | b >> 3\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   binary expression\n"
"|   |   |   |   identifier: a\n"
"|   |   |   |   operator: SHIFT_LEFT\n"
"|   |   |   |   literal\n"
"|   |   |   operator: OR\n"
"|   |   |   binary expression\n"
"|   |   |   |   identifier: b\n"
"|   |   |   |   operator: SHIFT_RIGHT\n"
"|   |   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_unaryExpression1(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_unaryExpression1) */
    char* input =
        "-a, ~b, !c\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   comma expression\n"
"|   |   |   unary expression\n"
"|   |   |   |   operator: SUB\n"
"|   |   |   |   identifier: a\n"
"|   |   |   unary expression\n"
"|   |   |   |   operator: NOT\n"
"|   |   |   |   identifier: b\n"
"|   |   |   unary expression\n"
"|   |   |   |   operator: COND_NOT\n"
"|   |   |   |   identifier: c\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_unaryExpression2(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_unaryExpression2) */
    char* input =
        "-a + b * -c\n"
        ;
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   unary expression\n"
"|   |   |   |   operator: SUB\n"
"|   |   |   |   identifier: a\n"
"|   |   |   operator: ADD\n"
"|   |   |   binary expression\n"
"|   |   |   |   identifier: b\n"
"|   |   |   |   operator: MUL\n"
"|   |   |   |   unary expression\n"
"|   |   |   |   |   operator: SUB\n"
"|   |   |   |   |   identifier: c\n"
    ;
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
    char* expected =
"program\n"
"|   statement\n"
"|   |   binary expression\n"
"|   |   |   identifier: a\n"
"|   |   |   operator: ASSIGN\n"
"|   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}

corto_void _test_TestVisitor_test_visitorAtom(
    test_TestVisitor _this)
{
/* $begin(test/TestVisitor/test_visitorAtom) */
    char* input = "1";
    char* expected =
"program\n"
"|   statement\n"
"|   |   literal\n"
    ;
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
    char* expected =
"program\n"
"|   statement\n"
"|   |   comma expression\n"
"|   |   |   literal\n"
"|   |   |   literal\n"
"|   |   |   literal\n"
    ;
    _testExpectedBuffer(input, expected);
/* $end */
}
