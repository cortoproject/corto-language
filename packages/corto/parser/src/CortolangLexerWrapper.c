#include "CortolangLexer.h"

#include "CortolangLexerWrapper.h"

#define EOF_STR ("<EOF>")
#define NEWLINE_STR ("<NEWLINE>")


static pANTLR3_COMMON_TOKEN createToken(
    pANTLR3_LEXER lexer,
    ANTLR3_UINT32 type,
    corto_string text)
{
    pANTLR3_COMMON_TOKEN token = lexer->rec->state->tokFactory->newToken(lexer->rec->state->tokFactory);

    token->type = type;
    token->channel = ANTLR3_TOKEN_DEFAULT_CHANNEL;
    token->start = lexer->rec->state->tokenStartCharIndex;
    token->stop = lexer->getCharIndex(lexer) - 1;
    token->line = lexer->rec->state->tokenStartLine;
    token->charPosition = lexer->rec->state->tokenStartCharPositionInLine;
    if (text != NULL) {
        token->textState = ANTLR3_TEXT_STRING;
        token->tokText.text = token->strFactory->newStr8(token->strFactory, (pANTLR3_UINT8)text);
    } else {
        token->textState = ANTLR3_TEXT_NONE;
    }

    token->lineStart = lexer->input->currentLine;
    token->user1 = lexer->rec->state->user1;
    token->user2 = lexer->rec->state->user2;
    token->user3 = lexer->rec->state->user3;
    token->custom = lexer->rec->state->custom;

    return token;
}


static void enqueueToken(pANTLR3_LEXER lexer, pANTLR3_COMMON_TOKEN token)
{
    pCortolangLexer ctx = (pCortolangLexer)lexer->super;
    corto_llAppend(ctx->data.tokenQueue, token);
}


static void handleEOF(pCortolangLexer ctx)
{
    pANTLR3_LEXER pLexer = ctx->pLexer;

    if (ctx->data.lastTokenType != NEWLINE) {
        enqueueToken(pLexer, createToken(pLexer, NEWLINE, NEWLINE_STR));
    }

    while (
        corto_llSize(ctx->data.indentationStack) &&
        corto_llTakeFirst(ctx->data.indentationStack)
    ) {
        enqueueToken(pLexer, createToken(pLexer, DEDENT, NULL));

        // pANTLR3_COMMON_TOKEN newLine = createToken(pLexer, NEWLINE, NEWLINE_STR);
        // enqueueToken(pLexer, newLine);
    }

    // pANTLR3_COMMON_TOKEN eofToken = createToken(pLexer, ANTLR3_TOKEN_EOF, EOF_STR);
    enqueueToken(pLexer, createToken(pLexer, ANTLR3_TOKEN_EOF, EOF_STR));
}


static pANTLR3_COMMON_TOKEN nextToken(pANTLR3_TOKEN_SOURCE toksource)
{
    pANTLR3_LEXER pLexer = (pANTLR3_LEXER)toksource->super;
    pCortolangLexer ctx = (pCortolangLexer)pLexer->super;
    pANTLR3_INT_STREAM istream = pLexer->input->istream;

    if (istream->_LA(istream, 1) == ANTLR3_TOKEN_EOF &&
        corto_llSize(ctx->data.tokenQueue) == 0)
    {
        handleEOF(ctx);
    }

    {
        pANTLR3_COMMON_TOKEN* p = &(ctx->data.bufferedSrcToken);
        while (*p == NULL || (*p)->getChannel(*p) != ANTLR3_TOKEN_DEFAULT_CHANNEL) {
            *p = ctx->data.super.nextToken(toksource);
        }
    }

    pANTLR3_COMMON_TOKEN next;
    if (corto_llSize(ctx->data.tokenQueue)) {
        next = (pANTLR3_COMMON_TOKEN)corto_llTakeFirst(ctx->data.tokenQueue);
    } else {
        next = ctx->data.bufferedSrcToken;
        ctx->data.bufferedSrcToken = NULL;
    }

    ctx->data.lastTokenType = next->getType(next);
    pLexer->emitNew(pLexer, next);

    return next;
}


void CustomLexer_handleLeadingWhitespace(pCortolangLexer ctx, corto_word currentSpaces)
{
    corto_ll indentationStack = ctx->data.indentationStack;

    corto_word lastIndentation = 0;
    if (corto_llSize(indentationStack)) {
        lastIndentation = (corto_word)corto_llGet(indentationStack, 0);
    }

    if (currentSpaces == lastIndentation) {
        enqueueToken(ctx->pLexer, createToken(ctx->pLexer, NEWLINE, NULL));
    } else if (currentSpaces > lastIndentation) {
        corto_llInsert(indentationStack, (void*)currentSpaces);
        enqueueToken(ctx->pLexer, createToken(ctx->pLexer, INDENT, NULL));
    } else {

        enqueueToken(ctx->pLexer, createToken(ctx->pLexer, NEWLINE, NULL));

        corto_word previousSpaces = 0;
        while (corto_llSize(indentationStack) && (currentSpaces < (corto_word)corto_llGet(indentationStack, 0))) {
            previousSpaces = (corto_word)corto_llTakeFirst(indentationStack);
            enqueueToken(ctx->pLexer, createToken(ctx->pLexer, DEDENT, NULL));
            // enqueueToken(ctx->pLexer, createToken(ctx->pLexer, NEWLINE, NULL));
        }

        corto_bool indentationError =
            (corto_llSize(indentationStack) == 0 && currentSpaces != 0) ||
            (currentSpaces > previousSpaces);

        if (indentationError) {
            ctx->data.indentationError = TRUE;
        }
    }

    ctx->pLexer->rec->state->channel = HIDDEN;
}



static void CustomLexer_free(pCortolangLexer ctx)
{
    while (corto_llTakeFirst(ctx->data.indentationStack));
    corto_llFree(ctx->data.indentationStack);

    while (corto_llTakeFirst(ctx->data.tokenQueue));
    corto_llFree(ctx->data.tokenQueue);

    ctx->data.super.free(ctx);
}


pCortolangLexer CustomLexer_new(pANTLR3_INPUT_STREAM input)
{
    pCortolangLexer lexer = CortolangLexerNew(input);

    if (!lexer) {
        corto_seterr("could not initializer lexer");
        goto errorCortolangLexerNew;
    }

    lexer->data.indentationStack = corto_llNew();
    if (!lexer->data.indentationStack) {
        goto errorNewIndentationStack;
    }

    lexer->data.tokenQueue = corto_llNew();
    if (!lexer->data.tokenQueue) {
        goto errorNewTokenQueue;
    }

    lexer->data.indentationError = FALSE;
    lexer->data.implicitLineJoiningLevel = 0;
    lexer->data.bufferedSrcToken = NULL;

    /* Override methods */
    lexer->data.super.free = lexer->free;
    lexer->free = CustomLexer_free;

    lexer->data.super.nextToken = lexer->pLexer->rec->state->tokSource->nextToken;
    lexer->pLexer->rec->state->tokSource->nextToken = nextToken;

    return lexer;

    corto_llFree(lexer->data.tokenQueue);
errorNewTokenQueue:
    corto_llFree(lexer->data.indentationStack);
errorNewIndentationStack:
    lexer->free(lexer);
errorCortolangLexerNew:
    return NULL;
}


corto_bool CustomLexer_implicitLineWhitespaceGuard(pCortolangLexer ctx)
{
    return ctx->data.implicitLineJoiningLevel > 0;
}


void CustomLexer_increaseBracketStack(pCortolangLexer ctx)
{
    ctx->data.implicitLineJoiningLevel++;
}


void CustomLexer_decreaseBracketStack(pCortolangLexer ctx)
{
    ctx->data.implicitLineJoiningLevel--;
}
