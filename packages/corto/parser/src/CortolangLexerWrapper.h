#ifndef PARSER_CORTOLANG_LEXER_WRAPPER_H
#define PARSER_CORTOLANG_LEXER_WRAPPER_H

#include <corto/corto.h>
#ifdef __cplusplus
extern "C" {
#endif

#include <corto/parser/parser.h>

/*
 * This class represents a wrapper around CortolangLexer. See it as a "subclass".
 */
typedef struct CortolangLexer_Ctx_struct CortolangLexer, * pCortolangLexer;


void parser_lw_handleLeadingWhitespace(pCortolangLexer ctx, corto_word spaces);

pCortolangLexer parser_lw_new(pANTLR3_INPUT_STREAM input);

corto_bool parser_lw_nestingWhitespaceGuard(pCortolangLexer ctx);
void parser_lw_increaseNesting(pCortolangLexer ctx);
void parser_lw_decreaseNesting(pCortolangLexer ctx);

struct parser_lw_data {
    /*
     * This is a list wherein each element is a corto_word representing the
     * number of spaces for each indentation level. When appending, it is not
     * necessary to allocate additional memory.
     * Use corto_llInsert and corto_llTakeFirst.
     */
    corto_ll indentationStack;

    /*
     * Used to indicate that there was an error when processing leading
     * whitespace.
     */
    corto_bool indentationError;

    /*
     * Handles context-sensitive lexing of implicit line joining such as
     *  the case where newline is ignored in cases like this:
     *  a = [3,
     *       4]
     */
    corto_int32 implicitLineJoiningLevel;

    /*
     * Represents a queue of tokens to be used by nextToken when the queue is
     * non-empty; otherwise use default implementation.
     * Use corto_llAppend and corto_llTakeFirst.
     */
    corto_ll tokenQueue;

    /*
     * Last token in the default channel, used by nextToken.
     */
    pANTLR3_COMMON_TOKEN bufferedSrcToken;

    /*
     * Type of last token, be from source or emmited.
     */
    ANTLR3_UINT32 lastTokenType;

    /*
     * super methods
     */
    struct {
        /* lexer->free */
        void (*free)(pCortolangLexer lexer);

        /* lexer->rec->state->tokSource->nextToken     =  nextToken; */
        pANTLR3_COMMON_TOKEN (*nextToken)(pANTLR3_TOKEN_SOURCE toksource);

    } super;
};

#ifdef __cplusplus
}
#endif
#endif
