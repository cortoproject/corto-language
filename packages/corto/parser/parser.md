# /corto/parser
Antlr3-based parser for Corto


## BaseParser
### displayRecognitionError(word recognizer,word tokenNames)
#### recognizer
#### tokenNames
### parse(string text)
#### text
#### Returns
### parseFile(string filename)
#### filename
#### Returns
### programReturn
### success

## BaseVisitor
### construct()
#### Returns
### destruct()
### parser
### visit()
#### Returns
### visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)
#### node
#### Returns
### visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)
#### node
#### Returns
### visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)
#### node
#### Returns
### visitExpressionNode(/corto/parser/ExpressionNode node)
#### node
#### Returns
### visitExpressionStatementNode(/corto/parser/ExpressionStatementNode node)
#### node
#### Returns
### visitProgramNode(/corto/parser/ProgramNode node)
#### node
#### Returns
### visitStatementNode(/corto/parser/StatementNode node)
#### node
#### Returns

## BinaryExpressionNode
### left
### operator
### right

## CommaExpressionNode
### expressions

## ConditionalExpressionNode
### condition
### falseValue
### trueValue

## ExpressionList

## ExpressionNode

## ExpressionStatementNode
### expression

## Node
### column
### line

## PrintVisitor
### buffer
### construct()
#### Returns
### destruct()
### getText()
#### Returns
### level
### visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)
#### node
#### Returns
### visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)
#### node
#### Returns
### visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)
#### node
#### Returns
### visitExpressionNode(/corto/parser/ExpressionNode node)
#### node
#### Returns
### visitProgramNode(/corto/parser/ProgramNode node)
#### node
#### Returns
### visitStatementNode(/corto/parser/StatementNode node)
#### node
#### Returns

## ProgramNode
### statements

## SimpleParser
### displayRecognitionError(word recognizer,word tokenNames)
#### recognizer
#### tokenNames
### errors

## StatementList

## StatementNode
