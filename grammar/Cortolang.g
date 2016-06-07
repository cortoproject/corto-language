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
#include "CortolangLexerWrapper.h"
}

@lexer::context
{
struct parser_lw_data data;
}

@lexer::apifuncs {
LEXER->super = ctx;
}

@parser::includes
{
#include "CortolangParserWrapper.h"

#define CHARS(text) ((char*)text->chars)
}

@parser::context
{
struct parser_data* parser_data;
}

@parser::apifuncs {
RECOGNIZER->displayRecognitionError = parser_pw_displayRecognitionError;
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
    {
        node = $declarativeStatement.node;
    }
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
returns [ parser_StatementNode ___ node ]
@init
{
    node = NULL;
}
    :
    (functionDeclaration) =>
    functionDeclaration
    {
        node = $functionDeclaration.node;
    }
    |
    (declarationExt) =>
    declarationExt
    {
        node = $declarationExt.node;
    }
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
returns [ parser_StatementNode ___ node ]
@init
{
    parser_BlockNode _node = parser_BlockNodeCreate(0, 0, corto_llNew());
    node = NULL;
}
    :
    COLON
    (
        (
            s1=statement
            {
                corto_llAppend(_node->statements, $s1.node);
            }
        )
        |
        INDENT
        (
            s2=statement
            {
                corto_llAppend(_node->statements, $s2.node);
            }
        )+
        DEDENT
    )
    {
        node = parser_StatementNode(_node);
    }
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
returns [ parser_StatementNode ___ node ]
@init {
    parser_ObjectDeclarationNode _node = parser_ObjectDeclarationNodeDeclare();
    tl = NULL;
    node = parser_StatementNode(_node);
    ini = NULL;
}
    :

    (
        (typeLabel declarationNameList) =>
        tl=typeLabel
    )?
    dnl=declarationNameList
    ini=initializer?
    (
        NEWLINE
        |
        s=scope_
        {
            _node->scope_ = $s.node;
        }
    )
    {
        _node->typeLabel = $tl.node;
        _node->declarations = $dnl.nodes;
        _node->initializer = $ini.node ? $ini.node : NULL;
        corto_define(_node);
    }
    ;


declarationNameList
returns [ corto_ll ___ nodes ]
@init
{
    nodes = corto_llNew();
}
    :
    (
        e1=declarationName
        {
            corto_llAppend(nodes, $e1.node);
        }
    )
    (
        COMMA
        e2=declarationName
        {
            corto_llAppend(nodes, $e2.node);
        }
    )*
    ;


declarationName
returns [ parser_ObjectDeclarationNameNode ___ node ]
@init
{
    node = NULL;
    fce = NULL;
}
    :
    VALID_NAME
    (
        LBRACE
        fce=fullCommaExpression
        RBRACE
    )?
    {
        node = parser_ObjectDeclarationNameNodeCreate(
            0, 0, CHARS($VALID_NAME.text), $fce.node
        );
    }
    ;


initializer
returns [ parser_FullCommaExpressionNode ___ node ]
@init
{
    node = NULL;
}
    :
    COLON
    (
        fullCommaExpression
        {
            node = $fullCommaExpression.node;
        }
    )
    ;


scopeOp
returns [ corto_bool ___ isPostScope ]
@init {
    isPostScope = TRUE;
}
    :
    TRIPLE_COLON
    {
        isPostScope = FALSE;
    }
    |
    DOUBLE_COLON
    ;


scope_
returns [ parser_ScopeNode ___ node ]
@init
{
    node = parser_ScopeNodeDeclare();
}
    :
    scopeOp
    (
        (
            s1=statement
            {
                corto_llAppend(node->statements, $s1.node);
            }
        )
        |
        INDENT
        (
            s2=statement
            {
                corto_llAppend(node->statements, $s2.node);
            }
        )+
        DEDENT
    )
    {
        node->isPostScope = $scopeOp.isPostScope;
        corto_define(node);
    }
    ;


// ============================================================
// Function Declaration
// ============================================================


functionDeclaration
returns [ parser_StatementNode ___ node ]
@init
{
    node = NULL;
    e = NULL;
    b = NULL;
}
    :
    tl=typeLabel
    name=VALID_NAME
    LPAREN
    params=functionParameters
    RPAREN
    (
        NEWLINE
        |
        EQUAL e=conditionalExpression NEWLINE
        |
        b=block
    )
    {
        parser_FunctionDeclarationNode _node = parser_FunctionDeclarationNodeCreate(
            0, 0, $tl.node, CHARS($name.text), $params.parameters, NULL
        );
        if ($e.node) {
            // TODO create block from single expression
            _node->block = parser_pw_createBlockFromExpression($e.node);
        } else {
            _node->block = parser_BlockNode($b.node);
        }
        node = parser_StatementNode(_node);
    }
    ;


functionParameters
returns [ corto_ll ___ parameters ]
@init
{
    parameters = corto_llNew();
}
    :
    (
        (
            p1=functionParameter
            {
                corto_llAppend(parameters, $p1.node);
            }
        )
        (
            COMMA
            p2=functionParameter
            {
                corto_llAppend(parameters, $p2.node);
            }
        )*
    )?
    /* TODO add optional trailing comma */
    ;


functionParameter
returns [ parser_FunctionParameterNode ___ node ]
@init
{
    node = NULL;
}
    :
    typeLabel
    VALID_NAME
    {
        node = parser_FunctionParameterNodeCreate(
            0, 0, $typeLabel.node, CHARS($VALID_NAME.text)
        );
        corto_claim(node);
    }
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
            op=assignmentOp
        )
        e2=simpleCommaExpression
        {
            node = parser_pw_createBinaryExpression(node, $op.kind, $e2.node);
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
returns [ parser_FullCommaExpressionNode ___ node ]
@init {
    node = parser_FullCommaExpressionNodeDeclare();
    node->elements = corto_llNew();
}
    :
    (
        (
            e1=commaExpressionElem
            {
                corto_llAppend(node->elements, $e1.node);
            }
        )
        (
            COMMA
            e2=commaExpressionElem
            {
                corto_llAppend(node->elements, $e2.node);
            }
        )*
        COMMA?
    )?
    {
        corto_define(node);
    }
    ;


commaExpressionElem
returns [ parser_FullCommaExpressionElementNode ___ node ]
@init {
    node = NULL;
    e1 = NULL;
    e2 = NULL;
}
    :
    (
        e1=conditionalExpression
    )
    (
        EQUAL
        e2=conditionalExpression
    )?
    {
        if ($e2.node) {
            node = parser_FullCommaExpressionElementNodeCreate(
                0, 0, $e1.node, $e2.node
            );
        } else {
            node = parser_FullCommaExpressionElementNodeCreate(
                0, 0, NULL, $e1.node
            );
        }
    }
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
            node = parser_pw_createBinaryExpression(node, CORTO_COND_OR, $e2.node);
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
            node = parser_pw_createBinaryExpression(node, CORTO_COND_AND, $e2.node);
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
        op=eqOp
        e2=comparisonExpression
        {
            node = parser_pw_createBinaryExpression(node, $op.kind, $e2.node);
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
        op=comparisonOp
        e2=bitOrExpression
        {
            node = parser_pw_createBinaryExpression(node, $op.kind, $e2.node);
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
            node = parser_pw_createBinaryExpression(node, CORTO_OR, $e2.node);
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
        HAT
        e2=bitAndExpression
        {
            node = parser_pw_createBinaryExpression(node, CORTO_XOR, $e2.node);
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
            node = parser_pw_createBinaryExpression(node, CORTO_AND, $e2.node);
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
        op=shiftOp
        e2=addExpression
        {
            node = parser_pw_createBinaryExpression(node, $op.kind, $e2.node);
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
        op=addOp
        e2=multExpression
        {
            node = parser_pw_createBinaryExpression(node, $op.kind, $e2.node);
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
        op=multOp
        e2=unaryExpression
        {
            node = parser_pw_createBinaryExpression(node, $op.kind, $e2.node);
        }
    )*
    ;


unaryExpression
returns [ parser_ExpressionNode ___ node ]
@init
{
    node = NULL;
    op = (corto_operatorKind)0; /* 0 is CORTO_ASSIGN, which doesn't otherwise make sense here */
    e = NULL;
}
    :
    op=unaryOp? e=postfixExpression
    {
        if ($op.kind) {
            parser_UnaryExpressionNode _node = parser_UnaryExpressionNodeCreate(
                0, 0, $op.kind, $e.node
            );
            node = parser_ExpressionNode(_node);
        } else {
            node = $e.node;
        }
    }
    ;


postfixExpression
returns [ parser_ExpressionNode ___ node ]
@init
{
    node = NULL;
}
    :
    (
        e=atomExpression
        {
            node = $e.node;
        }
    )
    (
        postfixOperation [ node ]
        {
            node = $postfixOperation.node;
        }
    )*
    ;


atomExpression
returns [ parser_ExpressionNode ___ node ]
@init
{
    node = NULL;
}
    :
    literal
    {
        node = parser_ExpressionNode($literal.node);
    }
    |
    identifier
    {
        parser_IdentifierNode _node = parser_IdentifierNodeCreate(0, 0, CHARS($identifier.text));
        node = parser_ExpressionNode(_node);
    }
    |
    LPAREN e=expression RPAREN
    {
        node = $e.node;
    }
    |
    anonymousObject
    ;

anonymousObject
    :
    LBRACE fullCommaExpression RBRACE
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
returns [ corto_operatorKind ___ ___ kind ]
@init
{
    kind = CORTO_ASSIGN;
}
    :
    EQUAL
    { kind = CORTO_ASSIGN; }
    |
    PLUS_EQUAL
    { kind = CORTO_ASSIGN_ADD; }
    |
    MINUS_EQUAL
    { kind = CORTO_ASSIGN_SUB; }
    |
    TIMES_EQUAL
    { kind = CORTO_ASSIGN_MUL; }
    |
    DIV_EQUAL
    { kind = CORTO_ASSIGN_DIV; }
    |
    MOD_EQUAL
    { kind = CORTO_ASSIGN_MOD; }
    |
    HAT_EQUAL
    { kind = CORTO_ASSIGN_XOR; }
    |
    PIPE_EQUAL
    { kind = CORTO_ASSIGN_OR; }
    |
    AMP_EQUAL
    { kind = CORTO_ASSIGN_AND; }
    |
    COLON_EQUAL
    { kind = CORTO_ASSIGN_UPDATE; }
    ;


eqOp
returns [ corto_operatorKind ___ kind ]
@init
{
    kind = (corto_operatorKind)0;
}
    :
    EQUALS
    { kind = CORTO_COND_EQ; }
    |
    NOT_EQUALS
    { kind = CORTO_COND_NEQ; }
    ;


comparisonOp
returns [ corto_operatorKind ___ kind ]
@init
{
    kind = (corto_operatorKind)0;
}
    :
    GREATER_THAN
    { kind = CORTO_COND_GT; }
    |
    LESS_THAN
    { kind = CORTO_COND_LT; }
    |
    GREATER_THAN_EQUAL
    { kind = CORTO_COND_GTEQ; }
    |
    LESS_THAN_EQUAL
    { kind = CORTO_COND_LTEQ; }
    ;


shiftOp
returns [ corto_operatorKind ___ kind ]
@init
{
    kind = (corto_operatorKind)0;
}
    :
    LSHIFT
    { kind = CORTO_SHIFT_LEFT; }
    |
    RSHIFT
    { kind = CORTO_SHIFT_RIGHT; }
    ;


addOp
returns [ corto_operatorKind ___ kind ]
@init
{
    kind = (corto_operatorKind)0;
}
    :
    PLUS
    { kind = CORTO_ADD; }
    |
    MINUS
    { kind = CORTO_SUB; }
    ;


multOp
returns [ corto_operatorKind ___ kind ]
@init
{
    kind = (corto_operatorKind)0;
}
    :
    ASTERISK
    { kind = CORTO_MUL; }
    |
    SLASH
    { kind = CORTO_DIV; }
    ;


unaryOp
returns [ corto_operatorKind ___ kind ]
@init
{
    kind = (corto_operatorKind)0;
}
    :
    TILDE
    { kind = CORTO_NOT; }
    |
    MINUS
    { kind = CORTO_SUB; }
    // |
    // PLUS
    // /* What operator goes here? */
    // /* Still, we probably *do* validate that the expression is numeric */
    // { kind = (corto_operatorKind)0; }
    |
    EMARK
    { kind = CORTO_COND_NOT; }
    |
    KW_NOT
    { kind = CORTO_COND_NOT; }
    ;

postfixOperation [ parser_ExpressionNode ___ _node ]
returns [ parser_ExpressionNode ___ node ]
@init
{
    node = NULL;
}
    :
    functionCall [ _node ]
    {
        node = $functionCall.node;
    }
    |
    memberAccess [ _node ]
    {
        node = $memberAccess.node;
    }
    |
    elementAccess [ _node ]
    {
        node = $elementAccess.node;
    }
    ;


functionCall [ parser_ExpressionNode ___ _node ]
returns [ parser_ExpressionNode ___ node ]
@init
{
    node = NULL;
}
    :
    LPAREN
    e=fullCommaExpression
    RPAREN
    {
        node = parser_pw_createCallExpression(_node, $e.node);
    }
    ;


memberAccess [ parser_ExpressionNode ___ _node ]
returns [ parser_ExpressionNode ___ node ]
@init
{
    node = NULL;
}
    :
    DOT VALID_NAME
    {
        node = parser_pw_createMemberExpression(_node, CHARS($VALID_NAME.text));
    }
    ;


elementAccess  [ parser_ExpressionNode ___ _node ]
returns [ parser_ExpressionNode ___ node ]
@init
{
    node = NULL;
}
    :
    LBRACK fullCommaExpression RBRACK
    {
        node = parser_pw_createElementExpression(_node, $fullCommaExpression.node);
    }
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
returns [ parser_BaseTypeExpressionNode ___ node ]
@init
{
    parser_SimpleTypeExpressionNode ste = NULL;
    parser_InitializerTypeExpressionNode ite = NULL;
    node = NULL;
}
    :
    (
        identifier
        {

            ste = parser_SimpleTypeExpressionNodeCreate(0, 0, CHARS($identifier.text));
            node = parser_BaseTypeExpressionNode(ste);
        }
    )
    (
        LBRACE
        fullCommaExpression
        RBRACE
        {
            ite = parser_InitializerTypeExpressionNodeCreate(
                0, 0, node, $fullCommaExpression.node
            );
            node = parser_BaseTypeExpressionNode(ite);
        }
    )*
    ;


literal
returns [ parser_LiteralNode ___ node ]
@init
{
    node = NULL;
}
    :
    booleanLiteral
    { node = $booleanLiteral.node; }
    |
    CHARACTER
    |
    integerLiteral
    { node = $integerLiteral.node; }
    |
    STRING
    ;


booleanLiteral
returns [ parser_LiteralNode ___ node ]
@init
{
    node = NULL;
    parser_BooleanLiteralNode _node = parser_BooleanLiteralNodeCreate(0, 0, TRUE);
}
    :
    (
        KW_TRUE
        { _node = parser_BooleanLiteralNodeCreate(0, 0, TRUE); }
        |
        KW_FALSE
        { _node = parser_BooleanLiteralNodeCreate(0, 0, FALSE); }
    )
    {
        node = parser_LiteralNode(_node);
    }
    ;


integerLiteral
returns [ parser_LiteralNode ___ node ]
@init
{
    node = NULL;
}
    :
    INTEGER
    {
        node = parser_pw_createIntegerLiteralNode(CHARS($INTEGER.text));
    }
    ;


// ============================================================
// Lexer tokens
// ============================================================

IMPLICIT_LINE_WHITESPACE
    :
    {parser_lw_nestingWhitespaceGuard(ctx)}?=>
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
    { parser_lw_handleLeadingWhitespace(ctx, spaces); }
    { !(ctx->data.indentationError) }?
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

RSHIFT : '>>' ;
LSHIFT : '<<' ;

GREATER_THAN_EQUAL : '>=' ;
LESS_THAN_EQUAL : '<=' ;

PLUS_EQUAL : '+=' ;
MINUS_EQUAL : '-=' ;
TIMES_EQUAL : '*=' ;
DIV_EQUAL : '/=' ;
MOD_EQUAL : '%=' ;
HAT_EQUAL : '^=' ;
PIPE_EQUAL : '|=' ;
AMP_EQUAL : '&=' ;
COLON_EQUAL : ':=' ;

LSHIFT_EQUALS : '<<=' ;
RSHIFT_EQUALS : '>>=' ;
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

INTEGER
    :
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

LPAREN : '(' {parser_lw_increaseNesting(ctx);} ;
RPAREN : ')' {parser_lw_decreaseNesting(ctx);} ;
LBRACK : '[' {parser_lw_increaseNesting(ctx);} ;
RBRACK : ']' {parser_lw_decreaseNesting(ctx);} ;
LBRACE : '{' {parser_lw_increaseNesting(ctx);} ;
RBRACE : '}' {parser_lw_decreaseNesting(ctx);} ;

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
HAT : '^' ;
DOT : '.' ;
