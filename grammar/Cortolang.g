grammar Cortolang;

options {
    language=C;
    output=AST;
    ASTLabelType=pANTLR3_BASE_TREE;
}

@parser::includes
{
#include "cortolangParserCustom.hpp"
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

program
    :
    statement+
    ;

statement
    :
    (declarativeStatement) =>
    declarativeStatement
    |
    simpleStatement
    ;

declarativeStatement
    :
    (functionDeclaration) =>
    functionDeclaration NEWLINE
    |
    (declarationExt) =>
    declarationExt NEWLINE
    ;

simpleStatement
    :
    expression NEWLINE
    ;

// Declaration

declarationExt
    :
    typeLabel validNameList declarationInitializer? (scopeOp scopeBlock)?
    ;

declarationInitializer
    :
    COLON initializer
    |
    initializerBraces
    ;

validNameList
    :
    VALID_NAME (COMMA VALID_NAME)* COMMA?
    ;

scopeBlock
    :
    simpleStatement
    |
    INDENT statement+ DEDENT
    ;

scopeOp
    :
    preScopeOperator
    |
    postScopeOperator
    ;

// Initializer

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
    (functionArgument (COMMA functionArgument)*)?
    ;

functionArgument
    :
    typeLabel VALID_NAME
    ;


// EXPRESSIONS
// They are described from *lower* to *higher* precedence.

expression
    :
    waitExpression
    ;

waitExpression
    :
    KW_WAIT assignmentExpression (KW_FOR logicOrExpression)?
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
    logicOrExpression ( QMARK logicOrExpression COLON QMARK )?
    ;

logicOrExpression
    :
    logicAndExpression ( LOGIC_OR logicAndExpression )*
    ;

logicAndExpression
    :
    equalityExpression ( LOGIC_AND equalityExpression )*
    ;

equalityExpression
    :
    comparisonExpression ( eqOp comparisonExpression )*
    ;

comparisonExpression
    :
    shiftExpression ( comparisonOp shiftExpression)*
    ;

bitOrExpression
    :
    bitXorExpression (PIPE bitXorExpression)*
    ;

bitXorExpression
    :
    bitAndExpression (CIRCUMFLEX bitAndExpression)*
    ;

bitAndExpression
    :
    shiftExpression (AMPERSAND shiftExpression)*
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
    atomExpression postfixOperation+
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
    memberAccess
    |
    methodCall
    ;

memberAccess
    :
    VALID_NAME
    ;

methodCall
    :
    VALID_NAME LPAREN RPAREN // TODO ADD PARAMETERS
    ;

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
    BOOLEAN
    |
    CHARACTER
    |
    INTEGER
    |
    STRING
    ;

anonymousObject
    :
    initializerBraces
    ;

// Other

postScopeOperator : DOUBLE_COLON ;
preScopeOperator : TRIPLE_COLON ;

// LEXER

WHITESPACE
    :
    (
        ' '+
        // |
        // ( ' ' | '\n' )+
    ) { $channel = HIDDEN; }
    ;

INDENT : 'INDENT' ;
DEDENT : 'DEDENT' ;

BOOLEAN : 'true' | 'false' ;

KW_WAIT : 'wait' ;
KW_FOR : 'for' ;

LOGIC_AND : 'and' ;
LOGIC_OR : 'or' ;

LPAREN : '(' ;
RPAREN : ')' ;
LBRACK : '[' ;
RBRACK : ']' ;
LBRACE : '{' ;
RBRACE : '}' ;

EQUALS : '==' ;
NOT_EQUALS : '!=' ;

RSHIFT : '<<' ;
LSHIFT : '>>' ;

GREATER_THAN : '>' ;
LESS_THAN : '<' ;
GREATER_THAN_EQUAL : '>=' ;
LESS_THAN_EQUAL : '<=' ;

QMARK : '?' ;
COLON : ':' ;
COMMA : ',' ;

TILDE : '~' ;
MINUS : '-' ;
PLUS : '+' ;
ASTERISK : '*' ;
SLASH : '/' ;
EQUAL : '=' ;
AMPERSAND : '&' ;
PLUS_EQUAL : '+=' ;
MINUS_EQUAL : '-=' ;
TIMES_EQUAL : '*=' ;
DIV_EQUAL : '/=' ;

PIPE : '|';

CIRCUMFLEX : '^';

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

NEWLINE : '\n' ;

DOUBLE_COLON : '::' ;

TRIPLE_COLON : ':::' ;

fragment
ESC : '\\' . ;

VALID_NAME :
    LETTER_UNDERSCORE (LETTER_UNDERSCORE | DIGIT)*
    ;

GID : '/' VALID_NAME ('/' VALID_NAME)* ;

fragment
LETTER_UNDERSCORE :
    ('a'..'z')
    |
    ('A'..'Z')
    |
    ('_')
    ;

fragment
DIGIT :
    ('0'..'9')
    ;
