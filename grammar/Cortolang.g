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

program :
    statement+
    ;

statement :
    scopeStatement NEWLINE
    |
    functionDeclaration NEWLINE
    |
    expression NEWLINE
    ;


// SCOPES

scopeStatement :
    scopeExpression ((scopeOperator | preScopeOperator) suite)?
    ;

scopeExpression :
    definitionOrDeclaration
    ;

suite :
    statement
    |
    INDENT statement+ DEDENT
    ; 

// DECLARATION AND DEFINITION

definitionOrDeclaration :
    declaration (
        COLON initializer
        |
        LBRACE initializer RBRACE 
    )?
    ;

declaration :
    typeLabel VALID_NAME (COMMA VALID_NAME)*
    // |
    /* This rule is ambiguous with a statement-level comma expression */
    // { /* check if we're inside a type's scope */ 1 }?
    // defaultTypeDeclaration { puts("\n\nDEFAULT TYPE DECLARATION\n\n"); }
    ;

// defaultTypeDeclaration :
//     VALID_NAME (COMMA VALID_NAME)*
//     ;

typeLabel :
    identifier
    |
    anonymousTypeLabel
    ;

anonymousTypeLabel :
    identifier initializerBraces+
    ;

compileTimeConstant :
    identifier
    |
    literal
    ;

initializer :
    initializerValue ( COMMA initializerValue )*
    ;

initializerValue :
    logicOrExpression
    |
    initializerBraces
    |
    initializerKeyValue
    ;

initializerBraces :
    LBRACE initializer RBRACE // TODO this should be an expression instead?
    ;

initializerKeyValue :
    initializerKey EQUAL initializerValue
    ;

initializerKey :
    VALID_NAME
    ;


// FUNCTION DECLARATION

functionDeclaration :
    typeLabel VALID_NAME LPAREN RPAREN
    ;


functionArguments :
    (functionArgument (COMMA functionArgument))?
    ;

functionArgument :
    typeLabel VALID_NAME
    ;


// EXPRESSIONS
// They are described from *lower* to *higher* precedence.

expression :
    assignmentExpression
    ;

assignmentExpression :
    commaExpression ( assignmentOp commaExpression )?
    ;

commaExpression :
    conditionalExpression ( COMMA conditionalExpression )*
    ;

conditionalExpression :
    initializerExpression ( QMARK conditionalExpression COLON QMARK )?
    ;

initializerExpression :
    initializerBraces
    |
    logicOrExpression
    ;

logicOrExpression :
    logicAndExpression ( LOGIC_OR logicAndExpression )*
    ;

logicAndExpression :
    equalityExpression ( LOGIC_AND equalityExpression )*
    ;


equalityExpression :
    shiftExpression ( eqOp shiftExpression )*
    ;

// comparison (boolean_expr)
// bitwise or
// bitwise xor
// bitwise and

shiftExpression :
    addExpression ( shiftOp addExpression )*
    ;

addExpression :
    multExpression ( addOp multExpression )*
    ;

multExpression :
    unaryExpression ( multOp unaryExpression )*
    ;

/* TODO other kinds of operators, e.g. bitwise */

unaryExpression :
    unaryOp? atomExpression
    ;

atomExpression :
    literal
    |
    identifier
    |
    LPAREN expression RPAREN
    ;

// OPERATOR GROUPS

assignmentOp :
    EQUAL
    ;

eqOp :
    EQUALS
    |
    NOT_EQUALS
    ;

shiftOp :
    LSHIFT
    |
    RSHIFT
    ;

addOp :
    PLUS
    |
    MINUS
    ;

multOp :
    ASTERISK
    |
    SLASH
    ;

unaryOp :
    TILDE
    |
    MINUS
    |
    PLUS
    ;


// IDENTIFIER

constant :
    VALID_NAME
    |
    GID
    |
    literal
    ;

identifier :
    VALID_NAME
    |
    GID
    ;

// LITERALS

literal :
    BOOLEAN
    |
    CHARACTER
    |
    INTEGER
    |
    STRING
    ;

// Other

scopeOperator : DOUBLE_COLON ;
preScopeOperator : TRIPLE_COLON ;

// LEXER

WHITESPACE :
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

GT : '>' ;
LT : '<' ;
GEQ : '>=' ;
LEQ : '<=' ;

QMARK : '?' ;
COLON : ':' ;
COMMA : ',' ;

TILDE : '~' ;
MINUS : '-' ;
PLUS : '+' ;
ASTERISK : '*';
SLASH : '/' ;
EQUAL : '=' ;
AMPERSAND : '&';

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
