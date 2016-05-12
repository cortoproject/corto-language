/* $CORTO_GENERATED
 *
 * BaseParser.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/parser/parser.h>

/* $header() */

#include "cortolangLexer.h"
#include "cortolangParser.h"

static corto_int16 parseInputStream(
    parser_BaseParser _this,
    pANTLR3_INPUT_STREAM input)
{
    pCortolangLexer lexer;
    pANTLR3_COMMON_TOKEN_STREAM tokens;
    pCortolangParser parser;
    CortolangParser_program_return_struct prog_return;
    pANTLR3_BASE_TREE tree;
    corto_int16 error = 0;

    lexer = CustomLexer_new(input);
    tokens = antlr3CommonTokenStreamSourceNew(
        ANTLR3_SIZE_HINT,
        TOKENSOURCE(lexer)
    );
    parser = CortolangParserNew(tokens);
    if (!parser) {
        /* TODO check if there is a custom message from antlr3 */
        corto_seterr("error creating parser");
        goto errorParserNew;
    }

    assert(parser->parser_data == NULL);
    parser->parser_data = parser_parserDataNew(_this);
    if (!(parser->parser_data)) {
        goto errorNoParserData;
    }

    _this->success = TRUE;
    prog_return = parser->program(parser);
    error = _this->success ? 0 : -1;
    
    CORTO_UNUSED((tree = prog_return.tree));

    parser->free(parser);
    tokens->free(tokens);
    lexer->free(lexer);
    input->close(input);

    return error;

errorNoParserData:
    parser->free(parser);
    tokens->free(tokens);
    lexer->free(lexer);
    input->close(input);
errorParserNew:;
    return -1;
}

/* $end */

corto_void _parser_BaseParser_displayRecognitionError_v(
    parser_BaseParser _this,
    corto_word recognizer,
    corto_word tokenNames)
{
/* $begin(corto/parser/BaseParser/displayRecognitionError) */
    _this->success = FALSE;
    ANTLR3_BASE_RECOGNIZER_struct* _recognizer = (ANTLR3_BASE_RECOGNIZER_struct*)recognizer;
    uint8_t** _tokenNames = (uint8_t**)tokenNames;
    CORTO_UNUSED(_recognizer);
    CORTO_UNUSED(_tokenNames);
/* $end */
}

corto_int16 _parser_BaseParser_parse(
    parser_BaseParser _this,
    corto_string text)
{
/* $begin(corto/parser/BaseParser/parse) */
    pANTLR3_INPUT_STREAM input = antlr3StringStreamNew(
        (pANTLR3_UINT8)text,
        ANTLR3_ENC_UTF8,
        strlen(text),
        (pANTLR3_UINT8)"_input_string_mock_file"
    );
    if (!input) {
        corto_seterr("input string: %s", text);
        goto errorInput;
    }
    
    return parseInputStream(_this, input);

errorInput:
    return -1;
/* $end */
}

corto_int16 _parser_BaseParser_parseFile(
    parser_BaseParser _this,
    corto_string filename)
{
/* $begin(corto/parser/BaseParser/parseFile) */
    pANTLR3_INPUT_STREAM input;
    if (!filename) {
        goto errorNoFilename;
    }
    input = antlr3FileStreamNew(
        (pANTLR3_UINT8)filename,
        ANTLR3_ENC_UTF8
    );
    if (!input) {
        corto_seterr("input file error: %s", filename);
        goto errorInput;
    }

    return parseInputStream(_this, input);

errorInput:
errorNoFilename:
    return -1;
/* $end */
}
