#ifndef PARSER_CUSTOMPARSER_HPP
#define PARSER_CUSTOMPARSER_HPP

#include <corto/corto.h>
#ifdef __cplusplus
extern "C" {
#endif

#include <corto/parser/parser.h>

#include "CortolangLexer.h"
#include "CortolangParser.h"

void parser_DisplayRecognitionError(ANTLR3_BASE_RECOGNIZER_struct* recognizer, uint8_t**);

typedef struct parser_data {
    parser_BaseParser parser;
} parser_data;

parser_data* parser_parserDataNew(parser_BaseParser parser);

void parser_parserDataDel(parser_data* data);

#ifdef __cplusplus
}
#endif
#endif

