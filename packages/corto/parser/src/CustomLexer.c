#include "CortolangLexer.h"

#include "CustomLexer.h"

static char eofString[] = "<EOF>";
static char newLineString[] = "<NEWLINE>";

static pANTLR3_COMMON_TOKEN createToken(
    pANTLR3_LEXER lexer,
    ANTLR3_UINT32 type,
    corto_string text)
{
    pANTLR3_COMMON_TOKEN token = lexer->rec->state->tokFactory->newToken(lexer->rec->state->tokFactory);

    token->type = type;
    token->channel = lexer->rec->state->channel;
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

    lexer->rec->state->token = token;

    return token;
}


static void CustomLexer_free(pCortolangLexer lexer)
{
    while (corto_llTakeFirst(lexer->data.indentationStack));
    corto_llFree(lexer->data.indentationStack);

    while (corto_llTakeFirst(lexer->data.tokenQueue));
    corto_llFree(lexer->data.tokenQueue);

    /* Call to super method */
    lexer->data.super.free(lexer);
}


static void emitNew(pANTLR3_LEXER lexer, pANTLR3_COMMON_TOKEN token)
{
    pCortolangLexer ctx = (pCortolangLexer)lexer->super;
    ctx->data.super.emitNew(lexer, token);
    corto_llAppend(ctx->data.tokenQueue, token);
}


static void handleEOF(pCortolangLexer ctx)
{
    pANTLR3_LEXER pLexer = ctx->pLexer;
    /* Remove any previous EOF */
    // corto_iter i = corto_llIter(ctx->data.tokenQueue);
    // while (corto_iterHasNext(&i)) {
    //     puts("-------------------------------------- this was unexpected");
    //     pANTLR3_COMMON_TOKEN token = (pANTLR3_COMMON_TOKEN)corto_iterNext(&i);
    //     if (token->getType(token) == ANTLR3_TOKEN_EOF) {
    //         corto_llIterRemove(&i);
    //     }
    // }

    /* Finish previous statement */
    if (ctx->data.lastToken->getType(ctx->data.lastToken) != NEWLINE) {
        pANTLR3_COMMON_TOKEN newLine = createToken(pLexer, NEWLINE, newLineString);
        emitNew(pLexer, newLine); /* Set text as "\n" */
    }

    while (
        corto_llSize(ctx->data.indentationStack) &&
        corto_llTakeFirst(ctx->data.indentationStack)
    ) {
        pANTLR3_COMMON_TOKEN dedent = createToken(pLexer, DEDENT, NULL);
        emitNew(pLexer, dedent);

        pANTLR3_COMMON_TOKEN newLine = createToken(pLexer, NEWLINE, newLineString);
        emitNew(pLexer, newLine);
    }

    pANTLR3_COMMON_TOKEN eofToken = createToken(pLexer, EOF, eofString); /* TODO set right value here */
    emitNew(pLexer, eofToken);
}


static pANTLR3_COMMON_TOKEN nextToken(pANTLR3_TOKEN_SOURCE toksource)
{
    pANTLR3_LEXER pLexer = (pANTLR3_LEXER)toksource->super;
    pCortolangLexer ctx = (pCortolangLexer)pLexer->super;
    pANTLR3_INT_STREAM istream = pLexer->input->istream;

    if (istream->_LA(istream, 1) == ANTLR3_TOKEN_EOF) {
        handleEOF(ctx);
    }

    pANTLR3_COMMON_TOKEN nextInSource = ctx->data.super.nextToken(toksource);
    if (nextInSource->getChannel(nextInSource) == ANTLR3_TOKEN_DEFAULT_CHANNEL) {
        ctx->data.lastToken = nextInSource;
    }

    pANTLR3_COMMON_TOKEN next;
    if (corto_llSize(ctx->data.tokenQueue)) {
        next = (pANTLR3_COMMON_TOKEN)corto_llTakeFirst(ctx->data.tokenQueue);
    } else {
        next = nextInSource;
    }

    return next;
}


void CustomLexer_handleLeadingWhitespace(pCortolangLexer ctx, corto_word currentSpaces)
{

    corto_ll indentationStack = ctx->data.indentationStack;

    corto_word lastIndentation = 0;
    if (corto_llSize(indentationStack)) {
        lastIndentation = (corto_word)corto_llLast(indentationStack);
    }

    if (currentSpaces == lastIndentation) {
        // puts("same indentation");
        ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, NEWLINE, NULL));
    } else if (currentSpaces > lastIndentation) {
        // puts("more indentation");
        corto_llInsert(indentationStack, (void*)currentSpaces);
        ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, INDENT, NULL));
    } else {

        ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, NEWLINE, NULL));

        corto_word previousSpaces = 0;
        while (corto_llSize(indentationStack)) {
            previousSpaces = (corto_word)corto_llTakeFirst(indentationStack);
            if (currentSpaces >= previousSpaces) {
                break;
            }
            ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, DEDENT, NULL));
            ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, NEWLINE, NULL));
        }

        ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, DEDENT, NULL));
        ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, NEWLINE, NULL));

        corto_bool indentationError =
            (corto_llSize(indentationStack) == 0 && currentSpaces != 0) ||
            (currentSpaces > previousSpaces);

        if (indentationError) {
            ctx->data.indentationError = TRUE;
        }
    }

    ctx->pLexer->rec->state->channel = HIDDEN; 
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
    lexer->data.lastToken = NULL;

    /* Override methods */
    lexer->data.super.free = lexer->free;
    lexer->free = CustomLexer_free;

    lexer->data.super.emitNew = lexer->pLexer->emitNew;
    lexer->pLexer->emitNew = emitNew;

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
