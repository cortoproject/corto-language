lexer grammar CLBasicLexer;

options {
    language=C;
}

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

ID : ID_PIECE ;

GID : '/'? ID_PIECE ('/' ID_PIECE)* ;

fragment
ID_PIECE : (('a'..'z') | ('A'..'Z'))+ ;
