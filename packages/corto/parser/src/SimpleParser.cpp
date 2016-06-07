/* $CORTO_GENERATED
 *
 * SimpleParser.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/parser/parser.h>

/* $header() */
#include "cortolangLexer.h"
#include "cortolangParser.h"
/* $end */

corto_void _parser_SimpleParser_displayRecognitionError(
    parser_SimpleParser _this,
    corto_word recognizer,
    corto_word tokenNames)
{
/* $begin(corto/parser/SimpleParser/displayRecognitionError) */
    parser_BaseParser(_this)->success = FALSE;
    ANTLR3_BASE_RECOGNIZER_struct* _recognizer = (ANTLR3_BASE_RECOGNIZER_struct*)recognizer;
    uint8_t** _tokenNames = (uint8_t**)tokenNames;
    CORTO_UNUSED(_recognizer);
    CORTO_UNUSED(_tokenNames);

    static char* defaultError = "error";
    corto_llInsert(_this->errors, corto_strdup(defaultError));
/* $end */
}
