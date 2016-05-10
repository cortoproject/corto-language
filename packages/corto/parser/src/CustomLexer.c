#include "CortolangLexer.h"

#include "CustomLexer.h"


static pANTLR3_COMMON_TOKEN createToken(pANTLR3_LEXER lexer, ANTLR3_UINT32 type)
{
    pANTLR3_COMMON_TOKEN token;

    /* We could check pointers to token factories and so on, but
    * we are in code that we want to run as fast as possible
    * so we are not checking any errors. So make sure you have installed an input stream before
    * trying to emit a new token.
    */
    token = lexer->rec->state->tokFactory->newToken(lexer->rec->state->tokFactory);

    /* Install the supplied information, and some other bits we already know
    * get added automatically, such as the input stream it is associated with
    * (though it can all be overridden of course)
    */
    token->type         = type;
    token->channel      = lexer->rec->state->channel;
    token->start        = lexer->rec->state->tokenStartCharIndex;
    token->stop         = lexer->getCharIndex(lexer) - 1;
    token->line         = lexer->rec->state->tokenStartLine;
    token->charPosition = lexer->rec->state->tokenStartCharPositionInLine;

    token->textState    = ANTLR3_TEXT_NONE;
    
    token->lineStart    = lexer->input->currentLine;
    token->user1        = lexer->rec->state->user1;
    token->user2        = lexer->rec->state->user2;
    token->user3        = lexer->rec->state->user3;
    token->custom       = lexer->rec->state->custom;

    lexer->rec->state->token        = token;

    return  token;
}


// static pANTLR3_COMMON_TOKEN createIndent(pANTLR3_LEXER lexer)
// {
//     return createToken(lexer, INDENT);
// }


// static pANTLR3_COMMON_TOKEN createDedent(pANTLR3_LEXER lexer)
// {
//     return createToken(lexer, DEDENT);
// }


corto_bool CustomLexer_leadingWhitespaceGuard(pCortolangLexer ctx)
{
    printf("\n\nI'm in line: %d\n", ctx->pLexer->rec->state->tokenStartLine);
    printf("position %d\n\n", ctx->pLexer->rec->state->tokenStartCharPositionInLine);

    // printf("lexer->rec->state->channel; -- %u\n", ctx->pLexer->rec->state->channel);
    // printf("lexer->rec->state->tokenStartCharIndex; -- %ld\n", ctx->pLexer->rec->state->tokenStartCharIndex);
    // printf("lexer->getCharIndex(lexer) - 1; -- %ld\n", ctx->pLexer->getCharIndex(ctx->pLexer) - 1);
    // printf("lexer->rec->state->tokenStartLine; -- %d\n", ctx->pLexer->rec->state->tokenStartLine);
    // printf("lexer->rec->state->tokenStartCharPositionInLine; -- %d\n", ctx->pLexer->rec->state->tokenStartCharPositionInLine);

    // if  (ctx->pLexer->rec->state->text != NULL)
    // {
    //     puts("text is NOT nsull!");
    //     // token->textState        = ANTLR3_TEXT_STRING;
    //     // token->tokText.text     = ctx->pLexer->rec->state->text;
    // }
    // else
    // {
    //     puts("text IS nsull!");
    //     // token->textState    = ANTLR3_TEXT_NONE;
    // }

    // if (ctx->pLexer->rec->state->tokenStartCharPositionInLine == 0) {
    //     puts(" yes this is leading whitespace!");
    // }
    // return ctx->pLexer->rec->state->tokenStartCharPositionInLine == 0;
    return TRUE;
}


void CustomLexer_handleLeadingWhitespace(pCortolangLexer ctx, corto_uint32 spaces)
{

    puts("\nlexer leading whitespaces ^^^\n");
    printf("\n\n Got spaces: %d\n", spaces);

    /* Compare current indentation to previous indentation */
    puts("1");
    corto_ll indentationStack = ctx->data.indentationStack;
    puts("2");

    corto_word lastIndentation = 0;
    printf("list is %p\n", indentationStack);
    // printf("size is %d\n", corto_llSize(indentationStack));
    puts("3");
    if (corto_llSize(indentationStack)) {
        lastIndentation = (corto_word)corto_llLast(indentationStack);
    }
    puts("4");

    if (spaces == lastIndentation) {
        puts("same indentation");
    } else if (spaces > lastIndentation) {
        puts("more indentation");
        corto_llInsert(indentationStack, (void*)lastIndentation);
        ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, INDENT));
    } else {
        puts("less indentation");
        /* TODO check if stack is empty */
        corto_word previousIndentation;
        corto_assert(corto_llSize(indentationStack));
        while (spaces < (previousIndentation = (corto_word)corto_llTakeFirst(indentationStack))) {
            ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, DEDENT));
            ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, NEWLINE));
        }
        if (spaces == previousIndentation) {
            ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, DEDENT));
            ctx->pLexer->emitNew(ctx->pLexer, createToken(ctx->pLexer, NEWLINE));
        } else {
            ctx->data.indentationError = TRUE;
        }
    }

    // ctx->pLexer->emitNew(ctx->pLexer, );
    // EMITNEW(LEADING_WHITESPACE);
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
        goto errorLlNew;
    }

    lexer->data.indentationError = FALSE;

    return lexer;

errorLlNew:
    lexer->free(lexer);
errorCortolangLexerNew:
    return NULL;
}


void CustomLexer_free(pCortolangLexer lexer)
{
    while (corto_llTakeFirst(lexer->data.indentationStack));
    corto_llFree(lexer->data.indentationStack);
    lexer->free(lexer);
}
