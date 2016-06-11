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
### type_

## BaseVisitor
### construct()
#### Returns
### destruct()
### parser
### visit()
#### Returns
### visitBaseTypeExpressionNode(/corto/parser/BaseTypeExpressionNode node,word data)
#### node
#### data
#### Returns
### visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node,word data)
#### node
#### data
#### Returns
### visitBlockNode(/corto/parser/BlockNode node,word data)
#### node
#### data
#### Returns
### visitCallExpressionNode(/corto/parser/CallExpressionNode node,word data)
#### node
#### data
#### Returns
### visitCommaExpressionNode(/corto/parser/CommaExpressionNode node,word data)
#### node
#### data
#### Returns
### visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node,word data)
#### node
#### data
#### Returns
### visitElementExpressionNode(/corto/parser/ElementExpressionNode node,word data)
#### node
#### data
#### Returns
### visitExpressionNode(/corto/parser/ExpressionNode node,word data)
#### node
#### data
#### Returns
### visitExpressionStatementNode(/corto/parser/ExpressionStatementNode node,word data)
#### node
#### data
#### Returns
### visitFullCommaExpressionElementNode(/corto/parser/FullCommaExpressionElementNode node,word data)
#### node
#### data
#### Returns
### visitFullCommaExpressionNode(/corto/parser/FullCommaExpressionNode node,word data)
#### node
#### data
#### Returns
### visitFunctionDeclarationNode(/corto/parser/FunctionDeclarationNode node,word data)
#### node
#### data
#### Returns
### visitFunctionParameterNode(/corto/parser/FunctionParameterNode node,word data)
#### node
#### data
#### Returns
### visitIdentifierNode(/corto/parser/IdentifierNode node,word data)
#### node
#### data
#### Returns
### visitInitializerTypeExpressionNode(/corto/parser/InitializerTypeExpressionNode node,word data)
#### node
#### data
#### Returns
### visitLiteralNode(/corto/parser/LiteralNode node,word data)
#### node
#### data
#### Returns
### visitMemberExpressionNode(/corto/parser/MemberExpressionNode node,word data)
#### node
#### data
#### Returns
### visitObjectDeclarationNameNode(/corto/parser/ObjectDeclarationNameNode node,word data)
#### node
#### data
#### Returns
### visitObjectDeclarationNode(/corto/parser/ObjectDeclarationNode node,word data)
#### node
#### data
#### Returns
### visitProgramNode(/corto/parser/ProgramNode node,word data)
#### node
#### data
#### Returns
### visitScopeNode(/corto/parser/ScopeNode node,word data)
#### node
#### data
#### Returns
### visitSimpleTypeExpressionNode(/corto/parser/SimpleTypeExpressionNode node,word data)
#### node
#### data
#### Returns
### visitStatementNode(/corto/parser/StatementNode node,word data)
#### node
#### data
#### Returns
### visitUnaryExpressionNode(/corto/parser/UnaryExpressionNode node,word data)
#### node
#### data
#### Returns

## BinaryExpressionNode
### left
### operator
### right

## BlockNode
### statements

## BooleanLiteralNode
### construct()
#### Returns
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

## DeclarationVisitor
### construct()
#### Returns
### currentScope
### currentType
### visit()
#### Returns
### visitFullCommaExpressionElementNode(/corto/parser/FullCommaExpressionElementNode node,word data)
#### node
#### data
#### Returns
### visitFullCommaExpressionNode(/corto/parser/FullCommaExpressionNode node,word data)
#### node
#### data
#### Returns
### visitInitializerTypeExpressionNode(/corto/parser/InitializerTypeExpressionNode node,word data)
#### node
#### data
#### Returns
### visitObjectDeclarationNameNode(/corto/parser/ObjectDeclarationNameNode node,word data)
#### node
#### data
#### Returns
### visitObjectDeclarationNode(/corto/parser/ObjectDeclarationNode node,word data)
#### node
#### data
#### Returns
### visitSimpleTypeExpressionNode(/corto/parser/SimpleTypeExpressionNode node,word data)
#### node
#### data
#### Returns

## ElementExpressionNode
### elements
### owner

## ExpressionList

## ExpressionNode
### getValue()
#### Returns
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

## InitializerCommaExpressionNode

## InitializerTypeExpressionNode
### arguments
### type

## IntegerLiteralNode
### construct()
#### Returns
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
### o

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
### visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node,word data)
#### node
#### data
#### Returns
### visitBlockNode(/corto/parser/BlockNode node,word data)
#### node
#### data
#### Returns
### visitCallExpressionNode(/corto/parser/CallExpressionNode node,word data)
#### node
#### data
#### Returns
### visitCommaExpressionNode(/corto/parser/CommaExpressionNode node,word data)
#### node
#### data
#### Returns
### visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node,word data)
#### node
#### data
#### Returns
### visitElementExpressionNode(/corto/parser/ElementExpressionNode node,word data)
#### node
#### data
#### Returns
### visitExpressionNode(/corto/parser/ExpressionNode node,word data)
#### node
#### data
#### Returns
### visitFullCommaExpressionElementNode(/corto/parser/FullCommaExpressionElementNode node,word data)
#### node
#### data
#### Returns
### visitFullCommaExpressionNode(/corto/parser/FullCommaExpressionNode node,word data)
#### node
#### data
#### Returns
### visitFunctionDeclarationNode(/corto/parser/FunctionDeclarationNode node,word data)
#### node
#### data
#### Returns
### visitFunctionParameterNode(/corto/parser/FunctionParameterNode node,word data)
#### node
#### data
#### Returns
### visitIdentifierNode(/corto/parser/IdentifierNode node,word data)
#### node
#### data
#### Returns
### visitInitializerTypeExpressionNode(/corto/parser/InitializerTypeExpressionNode node,word data)
#### node
#### data
#### Returns
### visitLiteralNode(/corto/parser/LiteralNode node,word data)
#### node
#### data
#### Returns
### visitMemberExpressionNode(/corto/parser/MemberExpressionNode node,word data)
#### node
#### data
#### Returns
### visitObjectDeclarationNameNode(/corto/parser/ObjectDeclarationNameNode node,word data)
#### node
#### data
#### Returns
### visitObjectDeclarationNode(/corto/parser/ObjectDeclarationNode node,word data)
#### node
#### data
#### Returns
### visitProgramNode(/corto/parser/ProgramNode node,word data)
#### node
#### data
#### Returns
### visitScopeNode(/corto/parser/ScopeNode node,word data)
#### node
#### data
#### Returns
### visitSimpleTypeExpressionNode(/corto/parser/SimpleTypeExpressionNode node,word data)
#### node
#### data
#### Returns
### visitStatementNode(/corto/parser/StatementNode node,word data)
#### node
#### data
#### Returns
### visitUnaryExpressionNode(/corto/parser/UnaryExpressionNode node,word data)
#### node
#### data
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
