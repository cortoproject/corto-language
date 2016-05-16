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
    declarativeStatement
    |
    simpleStatement NEWLINE
    |
    compositeStatement
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
    COLON
    (
        simpleStatement NEWLINE
        |
        INDENT statement+ DEDENT
    )
    ;

// ============================================================
// Declaration
// ============================================================

/*

All of the following are legal:
member x, y, z
member x, y, z: int8
member x{int8}, y{int8}, z, w
member x{int8}, y: int6a
member (
    x,
    y{int64},
    z,
): int8, private

*/

declarationExt
    :
    typeLabel declarationNameList initializer? (NEWLINE | scope_)
    ;

declarationNameList
    :
    declarationName ( COMMA declarationName )*
    ;

declarationName
    :
    VALID_NAME anonymousObject?
    ;

initializer
    :
    COLON fullCommaExpression
    ;

scopeOp
    :
    preScopeOperator
    |
    postScopeOperator
    ;

scope_
    :
    scopeOp
    (
        statement
        |
        INDENT statement+ DEDENT
    )
    ;

// ============================================================
// Function Declaration
// ============================================================

functionDeclaration
    :
    typeLabel VALID_NAME LPAREN functionArguments RPAREN
    (
        NEWLINE
        |
        EQUAL conditionalExpression NEWLINE
        |
        block
    )
    ;

functionArguments
    :
    ( functionArgument ( COMMA functionArgument )* )?
    /* TODO add optional trailing comma */
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
    KW_IF expression block ( elseStatement )?
    ;

elseStatement
    :
    KW_ELSE block
    ;

// ============================================================
// Expression
// ============================================================
// They are described from *lower* to *higher* precedence.

expression
    :
    assignmentExpression
    ;

assignmentExpression
    :
    simpleCommaExpression (assignmentOp simpleCommaExpression )?
    ;

simpleCommaExpression
    :
    conditionalExpression
    ( COMMA conditionalExpression )*
    COMMA?
    ;

/*
 * Used in initializers {} and function calls ().
 */
fullCommaExpression
    :
    commaExpressionElem
    ( COMMA commaExpressionElem )*
    COMMA?
    ;

commaExpressionElem
    :
    conditionalExpression
    ( EQUAL conditionalExpression )?
    ;

conditionalExpression
    :
    logicOrExpression ( QMARK logicOrExpression COLON logicOrExpression )?
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
    multExpression ((addOp multExpression) => addOp multExpression )*
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
    |
    anonymousObject
    ;

anonymousObject
    :
    LBRACE fullCommaExpression? RBRACE
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
    LPAREN fullCommaExpression? RPAREN
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
    identifier anonymousObject*
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
