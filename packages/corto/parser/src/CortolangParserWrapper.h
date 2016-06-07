#ifndef PARSER_CORTOLANG_PARSER_WRAPPER_H
#define PARSER_CORTOLANG_PARSER_WRAPPER_H

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

/*
 * The following functions are wrappers around <TypeName>Create because the
 * return type needs to be parser_ExpressionNode to unclutter the grammar file.
 */

parser_BlockNode parser_createBlockFromExpression(
    parser_ExpressionNode expression
    );

parser_ExpressionNode parser_createBinaryExpression(
    parser_ExpressionNode left,
    corto_operatorKind operator_,
    parser_ExpressionNode right);

parser_ExpressionNode parser_createCallExpression(
    parser_ExpressionNode caller,
    parser_FullCommaExpressionNode arguments);

parser_ExpressionNode parser_createMemberExpression(
    parser_ExpressionNode owner,
    char* memberName);

parser_ExpressionNode parser_createElementExpression(
    parser_ExpressionNode owner,
    parser_FullCommaExpressionNode elements);

parser_LiteralNode parser_IntegerLiteralNodeCreate_wrapper(
    char* text);

#ifdef __cplusplus
}
#endif
#endif
