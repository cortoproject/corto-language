grammar Cortolang;

options {
    language=C;
    output=AST;
    ASTLabelType=pANTLR3_BASE_TREE;
}

tokens {
    INDENT;
    DEDENT;
    NEWLINE;
}

@lexer::includes
{
#include "CustomLexer.h"
}

@lexer::context
{
struct CustomLexer_Data data;
}

@lexer::apifuncs {
LEXER->super = ctx;
}

@parser::includes
{
#include "CustomParser.hpp"
}

@parser::context
{
struct parser_data* parser_data;
}

@parser::apifuncs {
RECOGNIZER->displayRecognitionError = parser_DisplayRecognitionError;
ctx->parser_data = NULL;
PARSER->super = ctx;
}

// ============================================================
// Statement
// ============================================================

program
    :
    statement+
    ;

statement
    :
    (declarativeStatement) =>
    declarativeStatement NEWLINE
    |
    simpleStatement NEWLINE
    |
    compositeStatement NEWLINE
    |
    /* empty statement */
    NEWLINE
    ;

declarativeStatement
    :
    (functionDeclaration) =>
    functionDeclaration
    |
    (declarationExt) =>
    declarationExt
    ;

simpleStatement
    :
    expression
    ;

compositeStatement
    :
    ifStatement
    ;

block
    :
    simpleStatement
    |
    INDENT statement+ DEDENT
    ;

// ============================================================
// Declaration
// ============================================================

declarationExt
    :
    typeLabel validNameList declarationInitializer? ( scopeOp block )?
    ;

declarationInitializer
    :
    COLON initializer
    |
    initializerBraces
    ;

validNameList
    :
    VALID_NAME ( COMMA VALID_NAME )* COMMA?
    ;

scopeOp
    :
    preScopeOperator
    |
    postScopeOperator
    ;

// ============================================================
// Initializer
// ============================================================

initializer
    :
    initializerValue ( COMMA initializerValue )*
    ;

initializerValue
    :
    logicOrExpression
    |
    initializerBraces
    |
    initializerKeyValue
    ;

initializerBraces
    :
    LBRACE initializer RBRACE // TODO this should be an expression instead?
    ;

initializerKeyValue
    :
    initializerKey EQUAL initializerValue
    ;

initializerKey
    :
    VALID_NAME
    ;

// FUNCTION DECLARATION

functionDeclaration
    :
    typeLabel VALID_NAME LPAREN functionArguments RPAREN
    ;

functionArguments
    :
    ( functionArgument ( COMMA functionArgument )* )?
    ;

functionArgument
    :
    typeLabel VALID_NAME
    ;


// ============================================================
// Flow Control
// ============================================================

ifStatement
    :
    KW_IF expression COLON block (NEWLINE elseStatement)?
    ;

elseStatement
    :
    KW_ELSE (
        block
        /* Todo support more types of statements */
    )
    ;

// ============================================================
// Expression
// ============================================================
// They are described from *lower* to *higher* precedence.

expression
    :
    waitExpression
    ;

/* For use in comma-separated lists of expressions e.g. initializers and function arguments */
nonCommaExpression
    :
    assignmentExpressionNoComma
    ;

assignmentExpressionNoComma
    :
    conditionalExpression ( assignmentOp conditionalExpression )?
    ;

waitExpression
    :
    KW_WAIT assignmentExpression ( KW_FOR logicOrExpression )?
    |
    assignmentExpression
    ;

assignmentExpression
    :
    commaExpression ( assignmentOp commaExpression )?
    ;

commaExpression
    :
    conditionalExpression ( COMMA conditionalExpression )*
    ;

conditionalExpression
    :
    logicOrExpression ( QMARK logicOrExpression COLON logicOrExpression)?
    ;

logicOrExpression
    :
    logicAndExpression ( KW_OR logicAndExpression )*
    ;

logicAndExpression
    :
    equalityExpression ( KW_AND equalityExpression )*
    ;

equalityExpression
    :
    comparisonExpression ( eqOp comparisonExpression )*
    ;

comparisonExpression
    :
    shiftExpression ( comparisonOp shiftExpression )*
    ;

bitOrExpression
    :
    bitXorExpression ( PIPE bitXorExpression )*
    ;

bitXorExpression
    :
    bitAndExpression ( CIRCUMFLEX bitAndExpression )*
    ;

bitAndExpression
    :
    shiftExpression ( AMPERSAND shiftExpression )*
    ;

shiftExpression
    :
    addExpression ( shiftOp addExpression )*
    ;

addExpression
    :
    multExpression ( addOp multExpression )*
    ;

multExpression
    :
    unaryExpression ( multOp unaryExpression )*
    ;

unaryExpression
    :
    unaryOp? postfixExpression
    ;

postfixExpression
    :
    atomExpression postfixOperation*
    ;

atomExpression
    :
    literal
    |
    identifier
    |
    LPAREN expression RPAREN
    ;

// ============================================================
// Operators
// ============================================================

assignmentOp
    :
    EQUAL
    | PLUS_EQUAL | MINUS_EQUAL | TIMES_EQUAL | DIV_EQUAL
    ;

eqOp :
    EQUALS
    |
    NOT_EQUALS
    ;

comparisonOp:
    GREATER_THAN | LESS_THAN | GREATER_THAN_EQUAL | LESS_THAN_EQUAL
    ;

shiftOp
    :
    LSHIFT
    |
    RSHIFT
    ;

addOp
    :
    PLUS
    |
    MINUS
    ;

multOp
    :
    ASTERISK
    |
    SLASH
    ;

unaryOp
    :
    TILDE
    |
    MINUS
    |
    PLUS
    ;

postfixOperation
    :
    functionCall
    |
    memberAccess
    ;

memberAccess
    :
    DOT VALID_NAME
    ;

functionCall
    :
    LPAREN argumentList RPAREN
    ;

argumentList
    :
    (nonCommaExpression ( COMMA nonCommaExpression )* COMMA? )?
    ;

postScopeOperator : DOUBLE_COLON ;
preScopeOperator : TRIPLE_COLON ;

// ============================================================
// Identifiers, Types, Names
// ============================================================

constant
    :
    VALID_NAME
    |
    GID
    |
    literal
    ;

identifier
    :
    VALID_NAME
    |
    GID
    ;

typeLabel
    :
    identifier
    |
    anonymousTypeLabel
    ;

anonymousTypeLabel
    :
    identifier initializerBraces+
    ;

literal
    :
    booleanLiteral
    |
    CHARACTER
    |
    INTEGER
    |
    STRING
    ;

booleanLiteral
    :
    KW_TRUE
    |
    KW_FALSE
    ;

anonymousObject
    :
    initializerBraces
    ;

// ============================================================
// Lexer tokens
// ============================================================

IMPLICIT_LINE_WHITESPACE
    :
    {CustomLexer_implicitLineWhitespaceGuard(ctx)}?=>
    (' ' | '\n')+
    { $channel=HIDDEN; }
    ;

LEADING_WHITESPACE
@init {
corto_word spaces = 0;
}
    :
    // TODO maybe optimize to not count spaces in the lexer but after the lexer
    // {CustomLexer_leadingWhitespaceGuard(ctx)}?
    '\n' ( ' ' { spaces++; } )*
    {CustomLexer_handleLeadingWhitespace(ctx, spaces);}
    {!(ctx->data.indentationError)}?
    ;

WHITESPACE
    :
    (
        ' '+
    ) { $channel = HIDDEN; }
    ;

// Keywords

KW_TRUE : 'true' ;
KW_FALSE : 'false' ;

KW_WAIT : 'wait' ;
KW_FOR : 'for' ;
KW_IF : 'if' ;
KW_ELSE : 'else' ;
KW_WHILE : 'while' ;

KW_AND : 'and' ;
KW_OR : 'or' ;

// Two-or-more character symbols

EQUALS : '==' ;
NOT_EQUALS : '!=' ;

RSHIFT : '<<' ;
LSHIFT : '>>' ;

GREATER_THAN_EQUAL : '>=' ;
LESS_THAN_EQUAL : '<=' ;

PLUS_EQUAL : '+=' ;
MINUS_EQUAL : '-=' ;
TIMES_EQUAL : '*=' ;
DIV_EQUAL : '/=' ;
LSHIFT_EQUALS : '<<=' ;
RSHIFT_EQUALS : '>>=' ;
BITAND_EQUALS : '&=' ;
BITXOR_EQUALS : '^=' ;
BITOR_EQUALS : '|=' ;
DOUBLE_COLON : '::' ;
TRIPLE_COLON : ':::' ;

// Identifiers

VALID_NAME :
    LETTER_UNDERSCORE (LETTER_UNDERSCORE | DIGIT)*
    ;

GID
    :
    '/'? VALID_NAME ('/' VALID_NAME)*
    ;

// Literals

INTEGER :
    '0'
    |
    ('1'..'9') ('0'..'9')*
    ;

CHARACTER :
    '\'' (ESC|~('\\'|'\n'|'"'))* '\''
    ;

STRING :
    '"' (ESC|~('\\'|'\n'|'"'))* '"'
    ;

fragment
ESC : '\\' . ;

fragment
LETTER_UNDERSCORE
    :
    ('a'..'z')
    |
    ('A'..'Z')
    |
    ('_')
    ;

fragment
DIGIT
    :
    ('0'..'9')
    ;

// Single-character operators

LPAREN : '(' {CustomLexer_increaseBracketStack(ctx);} ;
RPAREN : ')' {CustomLexer_decreaseBracketStack(ctx);} ;
LBRACK : '[' {CustomLexer_increaseBracketStack(ctx);} ;
RBRACK : ']' {CustomLexer_decreaseBracketStack(ctx);} ;
LBRACE : '{' {CustomLexer_increaseBracketStack(ctx);} ;
RBRACE : '}' {CustomLexer_decreaseBracketStack(ctx);} ; 

QMARK : '?' ;
COLON : ':' ;
COMMA : ',' ;
GREATER_THAN : '>' ;
LESS_THAN : '<' ;
TILDE : '~' ;
PLUS : '+' ;
MINUS : '-' ;
ASTERISK : '*' ;
SLASH : '/' ;
EQUAL : '=' ;
AMPERSAND : '&' ;
PIPE : '|' ;
CIRCUMFLEX : '^' ;
DOT : '.' ;
