grammar Cortolang;

options {
    language=C;
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
returns [ parser_ProgramNode ___ node ]
@init
{
    node = parser_ProgramNodeCreate(0, 0, corto_llNew());
}
    :
    (
        statement
        {
            if ($statement.node) {
                corto_llAppend(node->statements, $statement.node);
            }
        }
    )+
    ;

statement
returns [ parser_StatementNode ___ node ]
@init
{
    node = NULL;
}
    :
    (declarativeStatement) =>
    declarativeStatement
    |
    simpleStatement NEWLINE
    {
        node = $simpleStatement.node;
    }
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
returns [ parser_StatementNode ___ node ]
@init
{
    node = NULL;
}
    :
    e=expression
    {
        // TODO line and column
        parser_ExpressionStatementNode _node = parser_ExpressionStatementNodeCreate(
            0, 0, $e.node
        );
        node = parser_StatementNode(_node);
    }
    |
    breakStatement
    |
    continueStatement
    ;

compositeStatement
    :
    ifStatement
    |
    whileStatement
    |
    observerStatement
    ;

block
    :
    COLON
    (
        statement
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
    KW_IF expression
    (
        block
    )
    (
        ( KW_ELSE ) =>
        ( elseStatement )
    )?
    ;

elseStatement
    :
    KW_ELSE block
    ;

whileStatement
    :
    KW_WHILE expression block
    ;

breakStatement
    :
    KW_BREAK
    ;

continueStatement
    :
    KW_CONTINUE
    ;

// ============================================================
// Expression
// ============================================================
// They are described from *lower* to *higher* precedence.


expression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    assignmentExpression
    {
        node = $assignmentExpression.node;
    }
    ;


assignmentExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=simpleCommaExpression
        {
            node = $e1.node;
        }
    )
    (
        (
            assignmentOp
        )
        e2=simpleCommaExpression
        {
            node = parser_createBinaryExpression($e1.node, "assignmentOp", $e2.node);
        }
    )?
    ;


simpleCommaExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=conditionalExpression
        {
            node = $e1.node;
        }
    )
    (
        COMMA
        e2=conditionalExpression
        {
            // TODO would move this method to CustomParser.cpp
            parser_CommaExpressionNode _node;
            if (!corto_instanceof(parser_CommaExpressionNode_o, node)) {
                _node = parser_CommaExpressionNodeCreate(
                    0, 0, corto_llNew()
                );
                corto_llAppend(_node->expressions, node);
                node = parser_ExpressionNode(_node);
            } else {
                _node = parser_CommaExpressionNode(node);
            }
            corto_llAppend(_node->expressions, $e2.node);
        }
    )*
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
returns [ parser_ExpressionNode ___ node ]
@init {
    node = parser_ExpressionNodeCreate(0, 0);
}
    :
    (
        e1=logicOrExpression
        {
            node = $e1.node;
        }
    )
    (
        QMARK
        e2=logicOrExpression
        COLON
        e3=logicOrExpression
        {
            parser_ConditionalExpressionNode _node = parser_ConditionalExpressionNodeCreate(
                0, 0, node, $e2.node, $e3.node
            );
            node = parser_ExpressionNode(_node);
        }
    )?
    ;


logicOrExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=logicAndExpression
        {
            node = $e1.node;
        }
    )
    (
        KW_OR
        e2=logicAndExpression
        {
            node = parser_createBinaryExpression($e1.node, "KW_OR", $e2.node);
        }
    )*
    ;


logicAndExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=equalityExpression
        {
            node = $e1.node;
        }
    )
    (
        KW_AND
        e2=equalityExpression
        {
            node = parser_createBinaryExpression($e1.node, "KW_AND", $e2.node);
        }
    )*
    ;

equalityExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=comparisonExpression
        {
            node = $e1.node;
        }
    )
    (
        eqOp
        e2=comparisonExpression
        {
            node = parser_createBinaryExpression($e1.node, "eqOp", $e2.node);
        }
    )?
    ;

comparisonExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=bitOrExpression
        {
            node = $e1.node;
        }
    )
    (
        comparisonOp
        e2=bitOrExpression
        {
            node = parser_createBinaryExpression($e1.node, "comparisonOp", $e2.node);
        }
    )?
    ;

bitOrExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=bitXorExpression
        {
            node = $e1.node;
        }
    )
    (
        PIPE
        e2=bitXorExpression
        {
            node = parser_createBinaryExpression($e1.node, "PIPE", $e2.node);
        }
    )*
    ;

bitXorExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=bitAndExpression
        {
            node = $e1.node;
        }
    )
    (
        CIRCUMFLEX
        e2=bitAndExpression
        {
            node = parser_createBinaryExpression($e1.node, "CIRCUMFLEX", $e2.node);
        }
    )*
    ;

bitAndExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=shiftExpression
        {
            node = $e1.node;
        }
    )
    (
        AMPERSAND
        e2=shiftExpression
        {
            node = parser_createBinaryExpression($e1.node, "AMPERSAND", $e2.node);
        }
    )*
    ;

shiftExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=addExpression
        {
            node = $e1.node;
        }
    )
    (
        shiftOp
        e2=addExpression
        {
            node = parser_createBinaryExpression($e1.node, "shiftOp", $e2.node);
        }
    )*
    ;

addExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = parser_ExpressionNodeCreate(0, 0);
}
    :
    (
        e1=multExpression
        {
            node = $e1.node;
        }
    )
    (
        (addOp multExpression) =>
        addOp
        e2=multExpression
        {
            node = parser_createBinaryExpression($e1.node, "addOp", $e2.node);
        }
    )*
    ;

multExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = NULL;
}
    :
    (
        e1=unaryExpression
        {
            node = $e1.node;
        }
    )
    (
        multOp
        e2=unaryExpression
        {
            node = parser_createBinaryExpression($e1.node, "multOp", $e2.node);
        }
    )*
    ;

unaryExpression
returns [ parser_ExpressionNode ___ node ]
@init {
    node = parser_ExpressionNodeCreate(0, 0);
}
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
// Observers
// ============================================================

observerStatement
    :
    KW_ON eventMask expression ( block | NEWLINE )
    ;

eventMask
    :
    eventFlag ( PIPE eventFlag )*
    ;

eventFlag : eventBaseFlag | eventScopeFlag ;

/* TODO we might need more flags */

eventBaseFlag : KW_DECLARE | KW_DEFINE | KW_UPDATE | KW_DESTRUCT ;

eventScopeFlag : KW_SELF | KW_SCOPE | KW_TREE | KW_SYNCHRONIZED ;

// ============================================================
// Operators
// ============================================================

assignmentOp
    :
    EQUAL
    |
    PLUS_EQUAL | MINUS_EQUAL | TIMES_EQUAL | DIV_EQUAL
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
    |
    EMARK
    |
    KW_NOT
    ;

postfixOperation
    :
    functionCall
    |
    memberAccess
    |
    elementAccess
    ;

functionCall
    :
    LPAREN fullCommaExpression? RPAREN
    ;

memberAccess
    :
    DOT VALID_NAME
    ;

elementAccess
    :
    LBRACK fullCommaExpression? RBRACK
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
KW_BREAK : 'break' ;
KW_CONTINUE : 'continue' ;

KW_AND : 'and' ;
KW_OR : 'or' ;
KW_NOT : 'not' ;

KW_DECLARE : 'declare' ;
KW_DEFINE : 'define' ;
KW_UPDATE : 'update' ;
KW_DESTRUCT : 'destruct' ;
KW_SELF : 'self' ;
KW_SCOPE : 'scope' ;
KW_TREE : 'tree' ;
KW_SYNCHRONIZED : 'synchronized' ;
KW_ON : 'on' ;

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
EMARK : '!' ;
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
