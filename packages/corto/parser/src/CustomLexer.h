#ifndef PARSER_CUSTOMLEXER_HPP
#define PARSER_CUSTOMLEXER_HPP

#include <corto/corto.h>
#ifdef __cplusplus
extern "C" {
#endif

#include <corto/parser/parser.h>

/*
 * This class represents a wrapper around CortolangLexer. You can see it as
 * a "subclass".
 */

typedef struct CortolangLexer_Ctx_struct CortolangLexer, * pCortolangLexer;

// pANTLR3_COMMON_TOKEN CustomLexer_createIndent(pANTLR3_LEXER lexer);
// pANTLR3_COMMON_TOKEN CustomLexer_createDedent(pANTLR3_LEXER lexer);

corto_bool CustomLexer_leadingWhitespaceGuard(pCortolangLexer ctx);
void CustomLexer_handleLeadingWhitespace(pCortolangLexer ctx, corto_uint32 spaces);

pCortolangLexer CustomLexer_new(pANTLR3_INPUT_STREAM input);
void CustomLexer_free(pCortolangLexer lexer);

struct CustomLexer_Data {
    /*
     * This is a list wherein each element is a corto_word representing the
     * number of spaces for each indentation level. When appending, it is not
     * necessary to allocate additional memory.
     */
    corto_ll indentationStack;
    corto_bool indentationError;
};

#ifdef __cplusplus
}
#endif
#endif

