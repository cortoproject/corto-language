/* $CORTO_GENERATED
 *
 * TestDeclarationVisitor.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

/* $header() */

static corto_void _run(corto_string code)
{
    parser_SimpleParser parser = parser_SimpleParserCreate();
    test_assert(parser_BaseParser_parse(parser, code) == 0);
    parser_DeclarationVisitor visitor = parser_DeclarationVisitorCreate(parser);
    parser_DeclarationVisitor_visit(visitor);
    corto_delete(visitor);
    corto_delete(parser);
}

/* $end */

corto_void _test_TestDeclarationVisitor_testInt8Declaration(
    test_TestDeclarationVisitor _this)
{
/* $begin(test/TestDeclarationVisitor/testInt8Declaration) */
    _run(
        "int8 a"
    );
    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);
    test_assert(corto_checkState(a, CORTO_DECLARED));
    test_assert(!corto_checkState(a, CORTO_DEFINED));
/* $end */
}

corto_void _test_TestDeclarationVisitor_testInt8DeclarationAndDefinition(
    test_TestDeclarationVisitor _this)
{
/* $begin(test/TestDeclarationVisitor/testInt8DeclarationAndDefinition) */
    _run(
        "int8 a: 11"
    );
    corto_int8* a = corto_int8(corto_resolve(NULL, "a"));
    test_assert(a != NULL);
    test_assert(corto_checkState(a, CORTO_DECLARED));
    test_assert(corto_checkState(a, CORTO_DEFINED));
    test_assert(*a == 11);
/* $end */
}

corto_void _test_TestDeclarationVisitor_testMultipleInt8Declaration(
    test_TestDeclarationVisitor _this)
{
/* $begin(test/TestDeclarationVisitor/testMultipleInt8Declaration) */
    _run(
        "int8 a, b"
    );
    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);
    test_assert(corto_typeof(a) == corto_type(corto_int8_o));
    test_assert(corto_checkState(a, CORTO_DECLARED));
    test_assert(!corto_checkState(a, CORTO_DEFINED));

    corto_object b = corto_resolve(NULL, "b");
    test_assert(b != NULL);
    test_assert(corto_typeof(a) == corto_type(corto_int8_o));
    test_assert(corto_checkState(b, CORTO_DECLARED));
    test_assert(!corto_checkState(b, CORTO_DEFINED));
/* $end */
}

corto_void _test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition(
    test_TestDeclarationVisitor _this)
{
/* $begin(test/TestDeclarationVisitor/testMultipleInt8DeclarationAndDefinition) */
    _run(
        "int8 a, b: 33"
    );
    corto_int8* a = corto_int8(corto_resolve(NULL, "a"));
    test_assert(a != NULL);
    test_assert(*a == 33);
    test_assert(corto_checkState(a, CORTO_DECLARED));
    test_assert(corto_checkState(a, CORTO_DEFINED));

    corto_int8* b = corto_int8(corto_resolve(NULL, "b"));
    test_assert(b != NULL);
    test_assert(*b == 33);
    test_assert(corto_checkState(b, CORTO_DECLARED));
    test_assert(corto_checkState(b, CORTO_DEFINED));
/* $end */
}
