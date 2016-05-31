/* SimpleParser.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_PARSER_SIMPLEPARSER_H
#define CORTO_PARSER_SIMPLEPARSER_H

#include <corto/corto.h>
#include <corto/parser/_interface.h>
#include <corto/parser/_type.h>
#include <corto/parser/_api.h>
#include <corto/parser/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_PARSER_EXPORT corto_void _parser_SimpleParser_displayRecognitionError(
    parser_SimpleParser _this,
    corto_word recognizer,
    corto_word tokenNames);
#define parser_SimpleParser_displayRecognitionError(_this, recognizer, tokenNames) _parser_SimpleParser_displayRecognitionError(parser_SimpleParser(_this), recognizer, tokenNames)

#ifdef __cplusplus
}
#endif
#endif

