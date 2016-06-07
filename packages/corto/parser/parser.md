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

## BaseTypeExpressionNode

## BaseVisitor
### construct()
#### Returns
### destruct()
### parser
### visit()
#### Returns
### visitBaseTypeExpressionNode(/corto/parser/BaseTypeExpressionNode node)
#### node
#### Returns
### visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)
#### node
#### Returns
### visitBlockNode(/corto/parser/BlockNode node)
#### node
#### Returns
### visitCallExpressionNode(/corto/parser/CallExpressionNode node)
#### node
#### Returns
### visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)
#### node
#### Returns
### visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)
#### node
#### Returns
### visitElementExpressionNode(/corto/parser/ElementExpressionNode node)
#### node
#### Returns
### visitExpressionNode(/corto/parser/ExpressionNode node)
#### node
#### Returns
### visitExpressionStatementNode(/corto/parser/ExpressionStatementNode node)
#### node
#### Returns
### visitFullCommaExpressionElementNode(/corto/parser/FullCommaExpressionElementNode node)
#### node
#### Returns
### visitFullCommaExpressionNode(/corto/parser/FullCommaExpressionNode node)
#### node
#### Returns
### visitFunctionDeclarationNode(/corto/parser/FunctionDeclarationNode node)
#### node
#### Returns
### visitFunctionParameterNode(/corto/parser/FunctionParameterNode node)
#### node
#### Returns
### visitIdentifierNode(/corto/parser/IdentifierNode node)
#### node
#### Returns
### visitInitializerTypeExpressionNode(/corto/parser/InitializerTypeExpressionNode node)
#### node
#### Returns
### visitLiteralNode(/corto/parser/LiteralNode node)
#### node
#### Returns
### visitMemberExpressionNode(/corto/parser/MemberExpressionNode node)
#### node
#### Returns
### visitObjectDeclarationNameNode(/corto/parser/ObjectDeclarationNameNode node)
#### node
#### Returns
### visitObjectDeclarationNode(/corto/parser/ObjectDeclarationNode node)
#### node
#### Returns
### visitProgramNode(/corto/parser/ProgramNode node)
#### node
#### Returns
### visitScopeNode(/corto/parser/ScopeNode node)
#### node
#### Returns
### visitSimpleTypeExpressionNode(/corto/parser/SimpleTypeExpressionNode node)
#### node
#### Returns
### visitStatementNode(/corto/parser/StatementNode node)
#### node
#### Returns
### visitUnaryExpressionNode(/corto/parser/UnaryExpressionNode node)
#### node
#### Returns

## BinaryExpressionNode
### left
### operator
### right

## BlockNode
### statements

## BooleanLiteralNode
### getValue()
#### Returns
### value

## CallExpressionNode
### arguments
### caller

## CommaExpressionNode
### expressions

## ConditionalExpressionNode
### condition
### falseValue
### trueValue

## ElementExpressionNode
### elements
### owner

## ExpressionList

## ExpressionNode
### isReference
### type_

## ExpressionStatementNode
### expression

## FullCommaExpressionElementList

## FullCommaExpressionElementNode
### key
### value

## FullCommaExpressionNode
### elements

## FunctionDeclarationNode
### block
### name
### parameters
### typeLabel

## FunctionParameterList

## FunctionParameterNode
### name
### typeLabel

## IdentifierNode
### name

## InitializerTypeExpressionNode
### arguments
### type

## IntegerLiteralNode
### getValue()
#### Returns
### value

## LiteralNode
### getValue()
#### Returns

## MemberExpressionNode
### member
### owner

## Node
### column
### line

## ObjectDeclarationNameList

## ObjectDeclarationNameNode
### arguments
### name

## ObjectDeclarationNode
### declarations
### initializer
### scope_
### typeLabel

## PostfixExpressionNode

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
### visitBlockNode(/corto/parser/BlockNode node)
#### node
#### Returns
### visitCallExpressionNode(/corto/parser/CallExpressionNode node)
#### node
#### Returns
### visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)
#### node
#### Returns
### visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)
#### node
#### Returns
### visitElementExpressionNode(/corto/parser/ElementExpressionNode node)
#### node
#### Returns
### visitExpressionNode(/corto/parser/ExpressionNode node)
#### node
#### Returns
### visitFullCommaExpressionElementNode(/corto/parser/FullCommaExpressionElementNode node)
#### node
#### Returns
### visitFullCommaExpressionNode(/corto/parser/FullCommaExpressionNode node)
#### node
#### Returns
### visitFunctionDeclarationNode(/corto/parser/FunctionDeclarationNode node)
#### node
#### Returns
### visitFunctionParameterNode(/corto/parser/FunctionParameterNode node)
#### node
#### Returns
### visitIdentifierNode(/corto/parser/IdentifierNode node)
#### node
#### Returns
### visitInitializerTypeExpressionNode(/corto/parser/InitializerTypeExpressionNode node)
#### node
#### Returns
### visitLiteralNode(/corto/parser/LiteralNode node)
#### node
#### Returns
### visitMemberExpressionNode(/corto/parser/MemberExpressionNode node)
#### node
#### Returns
### visitObjectDeclarationNameNode(/corto/parser/ObjectDeclarationNameNode node)
#### node
#### Returns
### visitObjectDeclarationNode(/corto/parser/ObjectDeclarationNode node)
#### node
#### Returns
### visitProgramNode(/corto/parser/ProgramNode node)
#### node
#### Returns
### visitScopeNode(/corto/parser/ScopeNode node)
#### node
#### Returns
### visitSimpleTypeExpressionNode(/corto/parser/SimpleTypeExpressionNode node)
#### node
#### Returns
### visitStatementNode(/corto/parser/StatementNode node)
#### node
#### Returns
### visitUnaryExpressionNode(/corto/parser/UnaryExpressionNode node)
#### node
#### Returns

## ProgramNode
### statements

## ScopeNode
### isPostScope
### statements

## SimpleParser
### displayRecognitionError(word recognizer,word tokenNames)
#### recognizer
#### tokenNames
### errors

## SimpleTypeExpressionNode
### name

## StatementList

## StatementNode

## UnaryExpressionNode
### expression
### operator

## valueKind
### Nothing
### Ref
### SignedInt
