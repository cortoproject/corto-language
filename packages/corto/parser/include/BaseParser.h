/* BaseParser.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_PARSER_BASEPARSER_H
#define CORTO_PARSER_BASEPARSER_H

#include <corto/corto.h>
#include <corto/parser/_interface.h>
#include <corto/parser/_type.h>
#include <corto/parser/_api.h>
#include <corto/parser/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_PARSER_EXPORT void _parser_BaseParser_displayRecognitionError(
    parser_BaseParser _this,
    corto_word recognizer,
    corto_word tokenNames);
#define parser_BaseParser_displayRecognitionError(_this, recognizer, tokenNames) _parser_BaseParser_displayRecognitionError(parser_BaseParser(_this), recognizer, tokenNames)

CORTO_PARSER_EXPORT corto_void _parser_BaseParser_displayRecognitionError_v(
    parser_BaseParser _this,
    corto_word recognizer,
    corto_word tokenNames);
#define parser_BaseParser_displayRecognitionError_v(_this, recognizer, tokenNames) _parser_BaseParser_displayRecognitionError_v(parser_BaseParser(_this), recognizer, tokenNames)

CORTO_PARSER_EXPORT corto_int16 _parser_BaseParser_parse(
    parser_BaseParser _this,
    corto_string text);
#define parser_BaseParser_parse(_this, text) _parser_BaseParser_parse(parser_BaseParser(_this), text)

CORTO_PARSER_EXPORT corto_int16 _parser_BaseParser_parseFile(
    parser_BaseParser _this,
    corto_string filename);
#define parser_BaseParser_parseFile(_this, filename) _parser_BaseParser_parseFile(parser_BaseParser(_this), filename)

#ifdef __cplusplus
}
#endif
#endif

