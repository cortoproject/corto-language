/* $CORTO_GENERATED
 *
 * PrintVisitor.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/parser/parser.h>

/* $header() */

#define THIS_BUFFER ((corto_buffer*)_this->buffer)

static void _appendIndentation(parser_PrintVisitor _this) {
    corto_uint32 level = _this->level;
    while (level--) {
        corto_buffer_append(THIS_BUFFER, "|   ");
    }
}

/* $end */

corto_int16 _parser_PrintVisitor_construct(
    parser_PrintVisitor _this)
{
/* $begin(corto/parser/PrintVisitor/construct) */
    _this->buffer = (corto_word)corto_calloc(sizeof(corto_buffer));
    return parser_BaseVisitor_construct(_this);
/* $end */
}

corto_void _parser_PrintVisitor_destruct(
    parser_PrintVisitor _this)
{
/* $begin(corto/parser/PrintVisitor/destruct) */
    corto_dealloc((void*)_this->buffer);
    parser_BaseVisitor_destruct(_this);
/* $end */
}

corto_string _parser_PrintVisitor_getText(
    parser_PrintVisitor _this)
{
/* $begin(corto/parser/PrintVisitor/getText) */
    return corto_buffer_str(THIS_BUFFER);
/* $end */
}

corto_object _parser_PrintVisitor_visitBinaryExpressionNode_v(
    parser_PrintVisitor _this,
    parser_BinaryExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitBinaryExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "binary expression\n");
    _this->level++;
    parser_PrintVisitor_visitExpressionNode(_this, node->left, 0);

    /* TODO error check */
    {
        corto_string operatorName = NULL;
        corto_int16 r = corto_convert(
            corto_operatorKind_o,
            &node->_operator,
            corto_string_o,
            &operatorName
        );
        if (r) {
            operatorName = NULL;
        }
        _appendIndentation(_this);
        corto_buffer_append(THIS_BUFFER, "operator: %s\n", operatorName);
        if (operatorName) {
            corto_dealloc(operatorName);
        }
    }

    parser_PrintVisitor_visitExpressionNode(_this, node->right, 0);
    _this->level--;

    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitBlockNode_v(
    parser_PrintVisitor _this,
    parser_BlockNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitBlockNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "block\n");
    parser_BaseVisitor_visitBlockNode_v(_this, node, 0);
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitCallExpressionNode_v(
    parser_PrintVisitor _this,
    parser_CallExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitCallExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "call\n");

    _this->level++;
    parser_BaseVisitor_visitExpressionNode_v(_this, node->caller, 0);
    // _appendIndentation(_this);
    parser_BaseVisitor_visitFullCommaExpressionNode(_this, node->arguments, 0);
    _this->level--;

    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitCommaExpressionNode_v(
    parser_PrintVisitor _this,
    parser_CommaExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitCommaExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "comma expression\n");
    _this->level++;
    parser_BaseVisitor_visitCommaExpressionNode_v(_this, node, 0);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitConditionalExpressionNode_v(
    parser_PrintVisitor _this,
    parser_ConditionalExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitConditionalExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "conditional expression\n");
    _this->level++;
    parser_BaseVisitor_visitConditionalExpressionNode_v(_this, node, 0);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitElementExpressionNode_v(
    parser_PrintVisitor _this,
    parser_ElementExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitElementExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "element expression\n");
    _this->level++;
    parser_BaseVisitor_visitExpressionNode_v(_this, node->owner, 0);
    parser_PrintVisitor_visitFullCommaExpressionNode(_this, node->elements, 0);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitExpressionNode_v(
    parser_PrintVisitor _this,
    parser_ExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitExpressionNode) */
    parser_BaseVisitor_visitExpressionNode_v(_this, node, 0);
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitFullCommaExpressionElementNode_v(
    parser_PrintVisitor _this,
    parser_FullCommaExpressionElementNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitFullCommaExpressionElementNode) */
    if (node->key) {
        _appendIndentation(_this);
        corto_buffer_append(THIS_BUFFER, "key-value\n");
        _this->level++;
        parser_BaseVisitor_visitExpressionNode_v(_this, node->key, 0);
    }
    parser_BaseVisitor_visitExpressionNode_v(_this, node->value, 0);
    if (node->key) {
        _this->level--;
    }
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitFullCommaExpressionNode_v(
    parser_PrintVisitor _this,
    parser_FullCommaExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitFullCommaExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "full comma expression\n");
    _this->level++;
    parser_BaseVisitor_visitFullCommaExpressionNode_v(_this, node, 0);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitFunctionDeclarationNode_v(
    parser_PrintVisitor _this,
    parser_FunctionDeclarationNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitFunctionDeclarationNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "function declaration: %s\n", node->name);
    _this->level++;
    if (node->typeLabel) {
        parser_BaseVisitor_visitBaseTypeExpressionNode(_this, node->typeLabel, 0);
    }
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "%s\n", node->name);
    printf("parameters: %p\n", node->parameters);
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "parameters\n");
    _this->level++;
    {
        puts("parser_PrintVisitor_visitFunctionDeclarationNode (before getting corto_llIter)");
        corto_iter i = corto_llIter(node->parameters);
        puts("parser_PrintVisitor_visitFunctionDeclarationNode (before while)");
        while (printf("while condition\n"), corto_iterHasNext(&i)) {
            puts("parser_PrintVisitor_visitFunctionDeclarationNode (before iterNext)");
            void *iterNext = corto_iterNext(&i);
            printf("iterNext: %p\n", iterNext);
            parser_FunctionParameterNode childNode = parser_FunctionParameterNode(iterNext);
            puts("parser_PrintVisitor_visitFunctionDeclarationNode (before visiting childNode)");
            parser_BaseVisitor_visitFunctionParameterNode(_this, childNode, 0);
            puts("parser_PrintVisitor_visitFunctionDeclarationNode (after visiting childNode)");
        }
    }
    _this->level--;

    parser_PrintVisitor_visitFullCommaExpressionNode(_this, node->parameters, 0);
    if (node->block) {
        parser_BaseVisitor_visitBlockNode_v(_this, node->block, 0);
    }
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitFunctionParameterNode_v(
    parser_PrintVisitor _this,
    parser_FunctionParameterNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitFunctionParameterNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "parameter\n");
    _this->level++;
    parser_BaseVisitor_visitBaseTypeExpressionNode(_this, node->typeLabel, 0);
    corto_buffer_append(THIS_BUFFER, "name: %s\n", node->name);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitIdentifierNode_v(
    parser_PrintVisitor _this,
    parser_IdentifierNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitIdentifierNode) */
     _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "identifier: %s\n", node->name);
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitInitializerTypeExpressionNode_v(
    parser_PrintVisitor _this,
    parser_InitializerTypeExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitInitializerTypeExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "initializer type expression node\n");
    _this->level++;
    parser_BaseVisitor_visitInitializerTypeExpressionNode_v(_this, node, 0);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitLiteralNode_v(
    parser_PrintVisitor _this,
    parser_LiteralNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitLiteralNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "literal\n");
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitMemberExpressionNode_v(
    parser_PrintVisitor _this,
    parser_MemberExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitMemberExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "member expression\n");
    _this->level++;
    parser_BaseVisitor_visitExpressionNode_v(_this, node->owner, 0);
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "member: %s\n", node->member);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitObjectDeclarationNameNode_v(
    parser_PrintVisitor _this,
    parser_ObjectDeclarationNameNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitObjectDeclarationNameNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "name: %s\n", node->name);
    _this->level++;
    if (node->arguments) {
        parser_BaseVisitor_visitFullCommaExpressionNode(_this, node->arguments, 0);
    }
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitObjectDeclarationNode_v(
    parser_PrintVisitor _this,
    parser_ObjectDeclarationNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitObjectDeclarationNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "object declaration\n");
    _this->level++;
    parser_BaseVisitor_visitObjectDeclarationNode_v(_this, node, 0);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitProgramNode_v(
    parser_PrintVisitor _this,
    parser_ProgramNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitProgramNode) */
    corto_buffer_append(THIS_BUFFER, "program\n");
    _this->level++;
    parser_BaseVisitor_visitProgramNode_v(_this, node, 0);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitScopeNode_v(
    parser_PrintVisitor _this,
    parser_ScopeNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitScopeNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "scope (post scope? %d)\n", node->isPostScope);
    _this->level++;
    parser_BaseVisitor_visitScopeNode_v(_this, node, 0);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitSimpleTypeExpressionNode_v(
    parser_PrintVisitor _this,
    parser_SimpleTypeExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitSimpleTypeExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "type: %s\n", node->name);
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitStatementNode_v(
    parser_PrintVisitor _this,
    parser_StatementNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitStatementNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "statement\n");
    _this->level++;
    parser_BaseVisitor_visitStatementNode_v(_this, node, 0);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitUnaryExpressionNode_v(
    parser_PrintVisitor _this,
    parser_UnaryExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/PrintVisitor/visitUnaryExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "unary expression\n");
    _this->level++;

    {
        corto_string operatorName = NULL;
        corto_int16 r = corto_convert(
            corto_operatorKind_o,
            &node->_operator,
            corto_string_o,
            &operatorName
        );
        if (r) {
            operatorName = NULL;
        }
        _appendIndentation(_this);
        corto_buffer_append(THIS_BUFFER, "operator: %s\n", operatorName);
        if (operatorName) {
            corto_dealloc(operatorName);
        }
    }

    parser_BaseVisitor_visitUnaryExpressionNode_v(_this, node, 0);
    _this->level--;
    return NULL;
/* $end */
}
