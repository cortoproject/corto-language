# /corto/ast
The Corto scripting language parser.
### isOperatorAssignment(operatorKind operator)
Test whether the specified operator results in an assignment.
Operators that result in assignments are: ASSIGN, ASSIGN_ADD, ASSIGN_AND, ASSIGN_DIV, ASSIGN_MOD, ASSIGN_MUL, ASSIGN_OR, ASSIGN_SUB, ASSIGN_UPDATE, ASSIGN_XOR, 
#### operator
#### Returns
### report(string kind,string filename,uint32 line,uint32 column,string error,string token)
#### kind
#### filename
#### line
#### column
#### error
#### token
### reportError(string filename,uint32 line,uint32 column,string error,string token)
#### filename
#### line
#### column
#### error
#### token
### reportWarning(string filename,uint32 line,uint32 column,string error,string token)
#### filename
#### line
#### column
#### error
#### token
### valueKindFromType(type type)
#### type
#### Returns

## Binary
A binary expression.
### construct()
#### Returns
### deref
### fold()
#### Returns
### hasReturnedResource()
#### Returns
### hasSideEffects()
#### Returns
### isScalar
### lvalue
### operator
### resolve(type type)
#### type
#### Returns
### rvalue
### setOperator(operatorKind kind)
#### kind
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## Binding
A temporary type that binds an code block to a function object.
### function
### impl

## Block
A code block.
### addStatement(ast::Node statement)
#### statement
### declare(string id,type type,bool isParameter,bool isReference)
Declare a variable in a code block.
#### id
#### type
#### isParameter
#### isReference
#### Returns
### declareReturnVariable(function function)
#### function
#### Returns
### declareTemplate(string id,type type,bool isParameter,bool isReference)
#### id
#### type
#### isParameter
#### isReference
#### Returns
### function
### isRoot
### locals
### lookup(string id)
#### id
#### Returns
### lookupLocal(string id)
#### id
#### Returns
### parent
### resolve(string id)
#### id
#### Returns
### resolveLocal(string id)
#### id
#### Returns
### setFunction(function function
#### function
### statements
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### toIcBody(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### while

## Boolean
### init()
#### Returns
### serialize(type dstType,word dst)
#### dstType
#### dst
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### value

## Call
### arguments
### construct()
#### Returns
### functionExpr
### hasReturnedResource()
#### Returns
### hasSideEffects()
#### Returns
### instanceExpr
### instanceIsAny
### overloaded
### parameters
### returnsReference
### returnType
### setParameters(function function)
#### function
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## CallBuilder
### arguments
### block
### build()
#### Returns
### buildSignature()
#### Returns
### instance
### name
### overloaded
### scope
### signature

## Cast
### construct()
#### Returns
### hasReturnedResource()
#### Returns
### isReference
### lvalue
### rvalue
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## Character
### init()
#### Returns
### serialize(type dstType,word dst)
#### dstType
#### dst
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### value

## Comma
### addExpression(Expression expr)
#### expr
#### Returns
### addOrCreate(Expression list,Expression expr)
#### list
#### expr
#### Returns
### construct()
#### Returns
### expressions
### hasReturnedResource()
#### Returns
### hasSideEffects()
#### Returns
### init()
#### Returns
### insertOrCreate(Expression list,Expression expr)
#### list
#### expr
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### toList()
#### Returns

## Define
### construct()
#### Returns
### object
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## Deinit
### construct()
#### Returns
### storage
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## DelegateCall
### construct()
#### Returns
### expr

## derefKind
### ByReference
### ByValue

## DynamicInitializer
### assignValue
### construct()
#### Returns
### define()
#### Returns
### frames
### hasReturnedResource()
#### Returns
### pop()
#### Returns
### push()
#### Returns
### value(Expression v)
#### v
#### Returns

## DynamicInitializerFrame
### expr
### keyExpr
### sequenceSize

## Element
### construct()
#### Returns
### lvalue
### rvalue
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## Expression
### cast(type type,bool isReference)
#### type
#### isReference
#### Returns
### cleanList(list{Expression} list)
#### list
### deref
### fold()
#### Returns
### fromList(list{Expression} list)
#### list
#### Returns
### getType()
#### Returns
### getType_expr(Expression target)
#### target
#### Returns
### getType_type(type target)
#### target
#### Returns
### getValue()
#### Returns
### hasReturnedResource()
#### Returns
### hasSideEffects()
#### Returns
### id()
#### Returns
### isReference
### resolve(type type)
#### type
#### Returns
### serialize(type dstType,word dst)
#### dstType
#### dst
#### Returns
### toList()
#### Returns
### type
### unresolved

## FloatingPoint
### init()
#### Returns
### serialize(type dstType,word dst)
#### dstType
#### dst
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### value

## If
### condition
### construct()
#### Returns
### falseBranch
### noWarnUnreachable()
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### trueBranch
### warnUnreachable

## Init
### construct()
#### Returns
### storage
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## Initializer
### construct()
#### Returns
### currentType()
#### Returns
### define()
#### Returns
### fp
### frames
### initFrame()
#### Returns
### member(string name)
#### name
#### Returns
### next()
#### Returns
### pop()
#### Returns
### popKey()
#### Returns
### push()
#### Returns
### pushKey()
#### Returns
### type()
#### Returns
### value(Expression v)
#### v
#### Returns
### valueKey(Expression key)
#### key
#### Returns
### variableCount
### variables

## InitializerExpression
### assignValue
### construct()
#### Returns
### define()
#### Returns
### hasReturnedResource()
#### Returns
### insert(Expression variable)
#### variable
#### Returns
### member(string name)
#### name
#### Returns
### operations
### pop()
#### Returns
### push()
#### Returns
### value(Expression v)
#### v
#### Returns

## InitializerFrame
### isKey
### location
### member
### type

## InitializerKind
### InitDynamic
### InitExpression
### InitStatic

## InitializerVariable
### key
### object
### offset

## InitOper
### expr
### kind
### name

## InitOperKind
### InitOpDefine
### InitOpMember
### InitOpPop
### InitOpPush
### InitOpValue

## Integer
### init()
#### Returns
### serialize(type dstType,word dst)
#### dstType
#### dst
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### value

## Literal
### getValue()
#### Returns
### init()
#### Returns
### kind

## Local
### construct()
#### Returns
### kind
### name
### reference
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### type

## LocalKind
### LocalDefault
### LocalParameter
### LocalReturn

## Lvalue
### expr
### isAssignment

## Member
### construct()
#### Returns
### hasSideEffects()
#### Returns
### lvalue
### member
### rvalue
### superMember
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## New
### attributes
### construct()
#### Returns
### hasSideEffects()
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### type

## Node
### column
### init()
#### Returns
### kind
### line
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## nodeKind
### BinaryExpr
### CallExpr
### CastExpr
### CommaExpr
### DeclarationExpr
### DeclareExpr
### DefineExpr
### DeinitExpr
### IfExpr
### InitExpr
### InitializerExpr
### LiteralExpr
### MethodExpr
### NewExpr
### PostfixExpr
### StorageExpr
### TernaryExpr
### UnaryExpr
### UpdateExpr
### WaitExpr
### WhileExpr

## Null
### init()
#### Returns
### serialize(type dstType,word dst)
#### dstType
#### dst
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## Object
### construct()
#### Returns
### getValue()
#### Returns
### id()
#### Returns
### serialize(type dstType,word dst)
#### dstType
#### dst
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### value

## Parser
### abort
### addStatement(ast::Node statement)
#### statement
### argumentToString(type type,string id,bool reference)
#### type
#### id
#### reference
#### Returns
### binaryExpr(ast::Expression lvalues,ast::Expression rvalues,operatorKind operator)
#### lvalues
#### rvalues
#### operator
#### Returns
### bind(ast::Storage function,ast::Block block)
#### function
#### block
#### Returns
### bindings
### bindOneliner(ast::Storage function,ast::Block block,ast::Expression expr)
#### function
#### block
#### expr
#### Returns
### block
### blockCount
### blockPop()
### blockPreset
### blockPush(bool presetBlock)
#### presetBlock
#### Returns
### callExpr(ast::Expression function,ast::Expression arguments)
#### function
#### arguments
#### Returns
### castExpr(type lvalue,ast::Expression rvalue)
#### lvalue
#### rvalue
#### Returns
### collect(object o)
#### o
### collected
### collectHeap(word addr)
#### addr
### column
### complexType
### complexTypeSp
### construct()
#### Returns
### declaration(type type,string id,bool isReference)
#### type
#### id
#### isReference
#### Returns
### declareFunction(type returnType,string id,type kind,bool returnsReference)
#### returnType
#### id
#### kind
#### returnsReference
#### Returns
### declareFunctionParams(Storage function)
#### function
#### Returns
### define()
#### Returns
### defineScope()
#### Returns
### defineVariable(Storage object)
#### object
#### Returns
### destruct()
### elementExpr(ast::Expression lvalue,ast::Expression rvalue)
#### lvalue
#### rvalue
#### Returns
### errLine
### errors
### errSet
### filename
### finalize(ic::program program)
#### program
#### Returns
### foreach(string loopId,ast::Expression collection)
#### loopId
#### collection
#### Returns
### getComplexType()
#### Returns
### getLvalue(bool assignment)
#### assignment
#### Returns
### getLvalueType(bool assignment)
#### assignment
#### Returns
### heapCollected
### ifStatement(ast::Expression condition,ast::Block trueBranch,ast::If falseBranch)
#### condition
#### trueBranch
#### falseBranch
#### Returns
### initAnonymousId
### initDeclare(Expression ids)
#### ids
#### Returns
### initDynamic
### initializerCount
### initializers
### initKeyValuePop()
#### Returns
### initKeyValuePush()
#### Returns
### initKeyValueSet(ast::Expression expr)
#### expr
#### Returns
### initMember(string member)
#### member
#### Returns
### initPop()
#### Returns
### initPush()
#### Returns
### initPushExpression()
#### Returns
### initPushIdentifier(Expression type)
#### type
#### Returns
### initPushStatic()
#### Returns
### initValue(Expression expr)
#### expr
#### Returns
### isAbortSet()
#### Returns
### isErrSet()
#### Returns
### isLocal
### line
### lookup(string id)
#### id
#### Returns
### lvalue
### lvalueSp
### memberExpr(ast::Expression lvalue,ast::Expression rvalue)
#### lvalue
#### rvalue
#### Returns
### observerDeclaration(string id,ast::Expression object,eventMask mask,ast::Object dispatcher)
#### id
#### object
#### mask
#### dispatcher
#### Returns
### observerPush()
### parse(sequence{string} argv)
#### argv
#### Returns
### parseExpression(string expr,ast::Block block,object scope,uint32 line,uint32 column)
#### expr
#### block
#### scope
#### line
#### column
#### Returns
### parseLine(string expr,object scope,word value)
#### expr
#### scope
#### value
#### Returns
### parseSingleExpr
### parseType(string expr,object scope)
#### expr
#### scope
#### Returns
### pass
### popComplexType()
### popLvalue()
### popScope(object previous)
#### previous
### postfixExpr(ast::Expression lvalue,operatorKind operator)
#### lvalue
#### operator
#### Returns
### preprocessed
### pushComplexType(ast::Expression lvalue)
#### lvalue
### pushLvalue(ast::Expression lvalue,bool isAssignment)
#### lvalue
#### isAssignment
### pushPackage(string name)
#### name
#### Returns
### pushReturnAsLvalue(function function)
#### function
### pushScope()
#### Returns
### repl
### reset()
### scope
### singleExpr
### source
### ternaryExpr(ast::Expression cond,ast::Expression iftrue,ast::Expression iffalse)
#### cond
#### iftrue
#### iffalse
#### Returns
### token
### unaryExpr(ast::Expression lvalue,operatorKind operator)
#### lvalue
#### operator
#### Returns
### updateStatement(ast::Expression expr,ast::Block block)
#### expr
#### block
#### Returns
### variableCount
### variablePushed
### variables
### variablesInitialized
### waitExpr(ast::Expression expr,ast::Expression timeout)
#### expr
#### timeout
#### Returns
### warnings
### whileStatement(ast::Expression condition,ast::Block trueBranch,bool isUntil)
#### condition
#### trueBranch
#### isUntil
#### Returns

## ParserDeclaration
### name
### storage

## ParserDeclarationSeq

## ParserNew
### attr
### kind
### name
### parent

## PostFix
### construct()
#### Returns
### hasReturnedResource()
#### Returns
### lvalue
### operator
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## SignedInteger
### init()
#### Returns
### serialize(type dstType,word dst)
#### dstType
#### dst
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### value

## StaticCall
### construct()
#### Returns
### function

## StaticInitializer
### construct()
#### Returns
### define()
#### Returns
### frames
### push()
#### Returns
### value(Expression v)
#### v
#### Returns

## StaticInitializerFrame
### keyPtr
### ptr

## Storage
### construct()
#### Returns
### kind

## storageKind
### ElementStorage
### LocalStorage
### MemberStorage
### ObjectStorage
### TemplateStorage
### TemporaryStorage
### UnresolvedReferenceStorage

## String
### block
### construct()
#### Returns
### elements
### getValue()
#### Returns
### init()
#### Returns
### scope
### serialize(type dstType,word dst)
#### dstType
#### dst
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### value

## Template
### construct()
#### Returns

## Temporary
### construct()
#### Returns
### ic
### proxy
### reference
### setProxy(Temporary proxy)
#### proxy
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### type

## Ternary
### condition
### construct()
#### Returns
### hasReturnedResource()
#### Returns
### hasSideEffects()
#### Returns
### ifFalse
### ifFalseExpr
### ifstmt
### ifTrue
### ifTrueExpr
### result
### setOperator(operatorKind kind)
#### kind
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## Unary
### construct()
#### Returns
### hasReturnedResource()
#### Returns
### hasSideEffects()
#### Returns
### lvalue
### operator
### resolve(type type)
#### type
#### Returns
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## UnresolvedReference
### column
### construct()
#### Returns
### error()
### id()
#### Returns
### line
### ref
### resolve(type type)
#### type
#### Returns
### scope
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## Update
### block
### construct()
#### Returns
### exprList
### from
### kind
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## UpdateKind
### UpdateBegin
### UpdateDefault
### UpdateEnd

## valueKind
### Bool
### Char
### Enum
### Float
### Int
### Nothing
### Ref
### SignedInt
### Text

## Wait
### construct()
#### Returns
### exprList
### hasReturnedResource()
#### Returns
### timeout
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns

## While
### condition
### construct()
#### Returns
### isUntil
### toIc(ic::program program,ic::storage storage,bool stored)
#### program
#### storage
#### stored
#### Returns
### trueBranch
