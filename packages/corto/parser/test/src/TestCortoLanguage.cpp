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
    test_assert(parser_BaseParser_parse(_this->parser, "1, 3, 4") == 0);
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

corto_void _test_TestCortoLanguage_test_elementAccess(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_elementAccess) */
    test_assert(parser_BaseParser_parse(_this->parser, "a[1]\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "a[1, 2, 3]\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionCall(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionCall) */
    test_assert(parser_BaseParser_parse(_this->parser, "a()\n") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "a(b)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionCall2(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionCall2) */
    test_assert(parser_BaseParser_parse(_this->parser, "a(b, 1, this or that, isReady ? 3 : 5)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionCall3(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionCall3) */
    test_assert(parser_BaseParser_parse(_this->parser, "a(c, d, e,)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionCall4(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionCall4) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "myFunctionCall("
        "    c.a(), "
        "    d.x.y,"
        "    otherVariable,"
        ")\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration1(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration1) */
    test_assert(parser_BaseParser_parse(_this->parser, "void myfunction()\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration2(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration2) */
    test_assert(parser_BaseParser_parse(_this->parser, "void myfunction(int8 a)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration3(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration3) */
    test_assert(parser_BaseParser_parse(_this->parser, "void myfunction(int8 a, string b)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration4(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration4) */
    // test_assert(parser_BaseParser_parse(_this->parser, "int8 addTwoNumbers(int8 a, int8 b) = a + b") == 0);
    test_assert(parser_BaseParser_parse(_this->parser, "int8 addTwoNumbers(int8 a, int8 b) = a + b\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration5(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration5) */
    test_assert(parser_BaseParser_parse(_this->parser, "list{int64} giveRandomNumbers(uint16 size)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration6(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration6) */
    test_assert(parser_BaseParser_parse(_this->parser, "list{int64} copyList(list{int64} input)\n") == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_functionDeclaration7(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_functionDeclaration7) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "int8 copyList(list{int64} input):\n"
        "    1 + 1\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_ifStatement1(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_ifStatement1) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "if finished():\n"
        "    ready = true\n"
        "    cleanUp()\n"
    ) == 0);
    test_assert(parser_BaseParser_parse(_this->parser,
        "if finished():\n"
        "    ready = true\n"
        "    cleanUp()"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_ifStatement2(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_ifStatement2) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "if ready == true and numberList.empty():\n"
        "    finish()\n"
        "else:\n"
        "    unfinish()\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_ifStatement3(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_ifStatement3) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "if finished(): cleanUp()\n"
        "else: messUp()\n"
    ) == 0);
    test_assert(parser_BaseParser_parse(_this->parser,
        "if finished(): cleanUp()\n"
        "else:\n"
        "    messUp()\n"
        "    randomize()\n"
    ) == 0);
    test_assert(parser_BaseParser_parse(_this->parser,
        "if finished():\n"
        "    cleanUp()\n"
        "    doubleCheck()\n"
        "else: messUp()\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_ifStatement4(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_ifStatement4) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "if test1():\n"
        "    statement1()\n"
        "    if test2():\n"
        "        statement2()\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_ifStatement5(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_ifStatement5) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "if test1():\n"
        "    statement1()\n"
        "    if test2():\n"
        "        statement2()\n"
        "    else:\n"
        "        statement3()\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_ifStatement6(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_ifStatement6) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "if test1():\n"
        "    statement1()\n"
        "    if test2():\n"
        "        statement2()\n"
        "    else:\n"
        "        statement3()\n"
        "else:\n"
        "    statement4()\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_ifStatement7(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_ifStatement7) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "if test1():\n"
        "    statement1()\n"
        "    if test2():\n"
        "        statement2()\n"
        "else:\n"
        "    statement3()\n"
    ) == 0);
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

corto_void _test_TestCortoLanguage_test_observer1(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_observer1) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "on update this\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_observer2(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_observer2) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "on update this: \"an update occurred\"\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_observer3(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_observer3) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "on update this:\n"
        "    \"an update occurred\""
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_observer4(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_observer4) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "on declare|update|scope object.member:\n"
        "    if object.member == x:\n"
        "        fun1()\n"
        "    else:\n"
        "        fun2()\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_observer5(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_observer5) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "on declare|update|tree object:\n"
        "    while !object.ready:\n"
        "        object.count += 1\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_scope1(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_scope1) */
    /* Declaration */
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass::\n"
        "    a = b\n"
    ) == 0);
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass::\n"
        "    a = b\n"
        "    b = c + 4\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_scope2(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_scope2) */
    /* Definition */
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: BaseClass::\n"
        "    a = b\n"
        "    d + 3\n"
    ) == 0);
    /* No line break after last (scoped) statement */
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: base=BaseClass::\n"
        "    a = b\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_scope3(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_scope3) */
    /* Statements after block */
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: BaseClass:: \n"
        "    a = b\n"
        "print()"
        "\n"
    ) == 0);
    
/* $end */
}

corto_void _test_TestCortoLanguage_test_scope4(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_scope4) */
    /* No newline at the end */
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: base=BaseClass::\n"
        "    a = b"
    ) == 0);
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: base=BaseClass::\n"
        "    a = b\n"
        "    6 + 5\n"
        "    print()"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_test_scope5(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/test_scope5) */
    /* Single statement in declaration */
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: base=BaseClass:: print()\n"
    ) == 0);
    test_assert(parser_BaseParser_parse(_this->parser,
        "class MyClass: base=BaseClass:: print"
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

corto_void _test_TestCortoLanguage_testWhileStatement1(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/testWhileStatement1) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "while this or that:\n"
        "    1 + 1\n"
        "    functioncall()\n"
        "    if ready:\n"
        "        break"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_testWhileStatement2(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/testWhileStatement2) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "while this or that: a += 1\n"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_testWhileStatement3(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/testWhileStatement3) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "while i -= 1:\n"
        "    while j -= 1:\n"
        "        a = b\n"
        "        if mytest:\n"
        "            continue\n"
        "        b = c"
    ) == 0);
/* $end */
}

corto_void _test_TestCortoLanguage_testWhileStatement4(
    test_TestCortoLanguage _this)
{
/* $begin(test/TestCortoLanguage/testWhileStatement4) */
    test_assert(parser_BaseParser_parse(_this->parser,
        "while i -= 1: while j -= 1: m[i][j] = 0\n"
    ) == 0);
/* $end */
}
