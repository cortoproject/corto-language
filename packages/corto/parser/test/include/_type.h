/* _type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef TEST__TYPE_H
#define TEST__TYPE_H

#include <corto/corto.h>
#include <corto/parser/_type.h>
#include <corto/test/_type.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's */
#define test_Point(o) ((test_Point)corto_assertType((corto_type)test_Point_o, o))
#define test_TestCortoLanguage(o) ((test_TestCortoLanguage)corto_assertType((corto_type)test_TestCortoLanguage_o, o))
#define test_TestDeclarationVisitor(o) ((test_TestDeclarationVisitor)corto_assertType((corto_type)test_TestDeclarationVisitor_o, o))
#define test_TestPrintVisitor(o) ((test_TestPrintVisitor)corto_assertType((corto_type)test_TestPrintVisitor_o, o))

/* Type definitions */
/*  /test/Point */
CORTO_CLASS(test_Point);

CORTO_CLASS_DEF(test_Point) {
    corto_int32 x;
    corto_int32 y;
};

/*  /test/TestCortoLanguage */
CORTO_CLASS(test_TestCortoLanguage);

CORTO_CLASS_DEF(test_TestCortoLanguage) {
    CORTO_EXTEND(test_SuiteData);
    parser_SimpleParser parser;
};

/*  /test/TestDeclarationVisitor */
CORTO_CLASS(test_TestDeclarationVisitor);

CORTO_CLASS_DEF(test_TestDeclarationVisitor) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/TestPrintVisitor */
CORTO_CLASS(test_TestPrintVisitor);

CORTO_CLASS_DEF(test_TestPrintVisitor) {
    CORTO_EXTEND(test_SuiteData);
};

#ifdef __cplusplus
}
#endif
#endif

