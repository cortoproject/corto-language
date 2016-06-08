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
/* $end */
}
