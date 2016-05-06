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
#define test_TestCortoLanguage(o) ((test_TestCortoLanguage)corto_assertType((corto_type)test_TestCortoLanguage_o, o))

/* Type definitions */
/*  /test/TestCortoLanguage */
CORTO_CLASS(test_TestCortoLanguage);

CORTO_CLASS_DEF(test_TestCortoLanguage) {
    CORTO_EXTEND(test_SuiteData);
    parser_SimpleParser parser;
};

#ifdef __cplusplus
}
#endif
#endif

