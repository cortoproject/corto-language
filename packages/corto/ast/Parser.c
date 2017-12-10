/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

void ast_Parser_addStatement(
    ast_Parser this,
    ast_Node statement)
{
    /* Insert implementation */
}

corto_string ast_Parser_argumentToString(
    ast_Parser this,
    corto_type type,
    corto_string id,
    bool reference)
{
    /* Insert implementation */
}

ast_Node ast_Parser_binaryExpr(
    ast_Parser this,
    ast_Expression lvalues,
    ast_Expression rvalues,
    corto_operatorKind _operator)
{
    /* Insert implementation */
}

int16_t ast_Parser_bind(
    ast_Parser this,
    ast_Storage function,
    ast_Block block)
{
    /* Insert implementation */
}

int16_t ast_Parser_bindOneliner(
    ast_Parser this,
    ast_Storage function,
    ast_Block block,
    ast_Expression expr)
{
    /* Insert implementation */
}

void ast_Parser_blockPop(
    ast_Parser this)
{
    /* Insert implementation */
}

ast_Block ast_Parser_blockPush(
    ast_Parser this,
    bool presetBlock)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_callExpr(
    ast_Parser this,
    ast_Expression function,
    ast_Expression arguments)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_castExpr(
    ast_Parser this,
    corto_type lvalue,
    ast_Expression rvalue)
{
    /* Insert implementation */
}

void ast_Parser_collect(
    ast_Parser this,
    corto_object o)
{
    /* Insert implementation */
}

void ast_Parser_collectHeap(
    ast_Parser this,
    uintptr_t addr)
{
    /* Insert implementation */
}

int16_t ast_Parser_construct(
    ast_Parser this)
{
    /* Insert implementation */
}

ast_Storage ast_Parser_declaration(
    ast_Parser this,
    corto_type type,
    corto_string id,
    bool isReference)
{
    /* Insert implementation */
}

ast_Storage ast_Parser_declareFunction(
    ast_Parser this,
    corto_type returnType,
    corto_string id,
    corto_type kind,
    bool returnsReference)
{
    /* Insert implementation */
}

ast_Block ast_Parser_declareFunctionParams(
    ast_Parser this,
    ast_Storage function)
{
    /* Insert implementation */
}

int16_t ast_Parser_defineObject(
    ast_Parser this)
{
    /* Insert implementation */
}

int16_t ast_Parser_defineScope(
    ast_Parser this)
{
    /* Insert implementation */
}

int16_t ast_Parser_defineVariable(
    ast_Parser this,
    ast_Storage object)
{
    /* Insert implementation */
}

void ast_Parser_destruct(
    ast_Parser this)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_elementExpr(
    ast_Parser this,
    ast_Expression lvalue,
    ast_Expression rvalue)
{
    /* Insert implementation */
}

int16_t ast_Parser_finalize(
    ast_Parser this,
    ic_program program)
{
    /* Insert implementation */
}

int16_t ast_Parser_foreach(
    ast_Parser this,
    corto_string loopId,
    ast_Expression collection)
{
    /* Insert implementation */
}

corto_type ast_Parser_getComplexType(
    ast_Parser this)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_getLvalue(
    ast_Parser this,
    bool assignment)
{
    /* Insert implementation */
}

corto_type ast_Parser_getLvalueType(
    ast_Parser this,
    bool assignment)
{
    /* Insert implementation */
}

ast_Node ast_Parser_ifStatement(
    ast_Parser this,
    ast_Expression condition,
    ast_Block trueBranch,
    ast_If falseBranch)
{
    /* Insert implementation */
}

int16_t ast_Parser_import(
    ast_Parser this,
    corto_string name)
{
    /* Insert implementation */
}

int16_t ast_Parser_initDeclare(
    ast_Parser this,
    ast_Expression ids)
{
    /* Insert implementation */
}

int16_t ast_Parser_initKeyValuePop(
    ast_Parser this)
{
    /* Insert implementation */
}

int16_t ast_Parser_initKeyValuePush(
    ast_Parser this)
{
    /* Insert implementation */
}

int16_t ast_Parser_initKeyValueSet(
    ast_Parser this,
    ast_Expression expr)
{
    /* Insert implementation */
}

int16_t ast_Parser_initMember(
    ast_Parser this,
    corto_string member)
{
    /* Insert implementation */
}

int16_t ast_Parser_initPop(
    ast_Parser this)
{
    /* Insert implementation */
}

int16_t ast_Parser_initPush(
    ast_Parser this)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_initPushExpression(
    ast_Parser this)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_initPushIdentifier(
    ast_Parser this,
    ast_Expression type)
{
    /* Insert implementation */
}

int16_t ast_Parser_initPushStatic(
    ast_Parser this)
{
    /* Insert implementation */
}

int16_t ast_Parser_initValue(
    ast_Parser this,
    ast_Expression expr)
{
    /* Insert implementation */
}

bool ast_Parser_isAbortSet(
    ast_Parser this)
{
    /* Insert implementation */
}

bool ast_Parser_isErrSet(
    ast_Parser this)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_lookup(
    ast_Parser this,
    corto_string id)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_memberExpr(
    ast_Parser this,
    ast_Expression lvalue,
    ast_Expression rvalue)
{
    /* Insert implementation */
}

ast_Storage ast_Parser_observerDeclaration(
    ast_Parser this,
    corto_string id,
    ast_Expression object,
    corto_eventMask mask,
    ast_Object dispatcher)
{
    /* Insert implementation */
}

void ast_Parser_observerPush(
    ast_Parser this)
{
    /* Insert implementation */
}

uint32_t ast_Parser_parse(
    ast_Parser this,
    corto_stringSeq argv)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_parseExpression(
    ast_Parser this,
    corto_string expr,
    ast_Block block,
    corto_object scope,
    uint32_t line,
    uint32_t column)
{
    /* Insert implementation */
}

int16_t ast_Parser_parseFunction(
    corto_function f,
    corto_string expr,
    bool inverse)
{
    /* Insert implementation */
}

int16_t ast_Parser_parseLine(
    corto_string expr,
    corto_object scope,
    uintptr_t value)
{
    /* Insert implementation */
}

corto_type ast_Parser_parseType(
    corto_string expr,
    corto_object scope)
{
    /* Insert implementation */
}

void ast_Parser_popComplexType(
    ast_Parser this)
{
    /* Insert implementation */
}

void ast_Parser_popLvalue(
    ast_Parser this)
{
    /* Insert implementation */
}

void ast_Parser_popScope(
    ast_Parser this,
    corto_object previous)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_postfixExpr(
    ast_Parser this,
    ast_Expression lvalue,
    corto_operatorKind _operator)
{
    /* Insert implementation */
}

void ast_Parser_pushComplexType(
    ast_Parser this,
    ast_Expression lvalue)
{
    /* Insert implementation */
}

void ast_Parser_pushLvalue(
    ast_Parser this,
    ast_Expression lvalue,
    bool isAssignment)
{
    /* Insert implementation */
}

int16_t ast_Parser_pushPackage(
    ast_Parser this,
    corto_string name)
{
    /* Insert implementation */
}

void ast_Parser_pushReturnAsLvalue(
    ast_Parser this,
    corto_function function)
{
    /* Insert implementation */
}

corto_object ast_Parser_pushScope(
    ast_Parser this)
{
    /* Insert implementation */
}

void ast_Parser_reset(
    ast_Parser this)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_ternaryExpr(
    ast_Parser this,
    ast_Expression cond,
    ast_Expression iftrue,
    ast_Expression iffalse)
{
    /* Insert implementation */
}

ast_Expression ast_Parser_unaryExpr(
    ast_Parser this,
    ast_Expression lvalue,
    corto_operatorKind _operator)
{
    /* Insert implementation */
}

ast_Node ast_Parser_updateStatement(
    ast_Parser this,
    ast_Expression expr,
    ast_Block block)
{
    /* Insert implementation */
}

ast_Node ast_Parser_whileStatement(
    ast_Parser this,
    ast_Expression condition,
    ast_Block trueBranch,
    bool isUntil)
{
    /* Insert implementation */
}

int16_t ast_Parser_with(
    ast_Parser this)
{
    /* Insert implementation */
}

