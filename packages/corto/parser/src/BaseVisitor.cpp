/* $CORTO_GENERATED
 *
 * BaseVisitor.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/parser/parser.h>

/* $header() */
/* $end */

corto_int16 _parser_BaseVisitor_construct(
    parser_BaseVisitor _this)
{
/* $begin(corto/parser/BaseVisitor/construct) */
    CORTO_UNUSED(_this);
    return 0;
/* $end */
}

corto_void _parser_BaseVisitor_destruct(
    parser_BaseVisitor _this)
{
/* $begin(corto/parser/BaseVisitor/destruct) */
    CORTO_UNUSED(_this);
/* $end */
}

corto_object _parser_BaseVisitor_visit_v(
    parser_BaseVisitor _this)
{
/* $begin(corto/parser/BaseVisitor/visit) */
    return parser_BaseVisitor_visitProgramNode(_this, _this->parser->programReturn, 0);
/* $end */
}

corto_object _parser_BaseVisitor_visitBaseTypeExpressionNode_v(
    parser_BaseVisitor _this,
    parser_BaseTypeExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitBaseTypeExpressionNode) */
    corto_object value = NULL;
    if (corto_instanceof(parser_SimpleTypeExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitSimpleTypeExpressionNode(_this, node, data);

    } else if (corto_instanceof(parser_InitializerTypeExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitInitializerTypeExpressionNode(_this, node, data);

    } else {
        corto_error("unmanaged node type: %s", corto_idof(corto_typeof(node)));
        goto error;
    }

    return value;

error:
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitBinaryExpressionNode_v(
    parser_BaseVisitor _this,
    parser_BinaryExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitBinaryExpressionNode) */
    parser_BaseVisitor_visitExpressionNode(_this, node->left, data);
    parser_BaseVisitor_visitExpressionNode(_this, node->right, data);
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitBlockNode_v(
    parser_BaseVisitor _this,
    parser_BlockNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitBlockNode) */
    if (node->statements) {
        corto_iter i = corto_llIter(node->statements);
        while (corto_iterHasNext(&i)) {
            parser_StatementNode childNode = parser_StatementNode(corto_iterNext(&i));
            parser_BaseVisitor_visitStatementNode(_this, childNode, data);
        }
    }

    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitCallExpressionNode_v(
    parser_BaseVisitor _this,
    parser_CallExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitCallExpressionNode) */
    parser_BaseVisitor_visitExpressionNode(_this, node->caller, data);
    // TODO arguments
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitCommaExpressionNode_v(
    parser_BaseVisitor _this,
    parser_CommaExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitCommaExpressionNode) */
    corto_iter i = corto_llIter(node->expressions);
    while (corto_iterHasNext(&i)) {
        parser_ExpressionNode childNode = parser_ExpressionNode(corto_iterNext(&i));
        parser_BaseVisitor_visitExpressionNode(_this, childNode, data);
    }
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitConditionalExpressionNode_v(
    parser_BaseVisitor _this,
    parser_ConditionalExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitConditionalExpressionNode) */
    parser_BaseVisitor_visitExpressionNode(_this, node->condition, data);
    parser_BaseVisitor_visitExpressionNode(_this, node->trueValue, data);
    parser_BaseVisitor_visitExpressionNode(_this, node->falseValue, data);
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitElementExpressionNode_v(
    parser_BaseVisitor _this,
    parser_ElementExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitElementExpressionNode) */
    parser_BaseVisitor_visitExpressionNode(_this, node->owner, data);
    // TODO elements
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitExpressionNode_v(
    parser_BaseVisitor _this,
    parser_ExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitExpressionNode) */
    corto_object value = NULL;
    if (corto_instanceof(parser_BinaryExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitBinaryExpressionNode(_this, node, data);

    } else if (corto_instanceof(parser_CommaExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitCommaExpressionNode(_this, node, data);

    } else if (corto_instanceof(parser_ConditionalExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitConditionalExpressionNode(_this, node, data);

    } else if (corto_instanceof(parser_UnaryExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitUnaryExpressionNode(_this, node, data);

    } else if (corto_instanceof(parser_LiteralNode_o, node)) {
        value = parser_BaseVisitor_visitLiteralNode(_this, node, data);

    } else if (corto_instanceof(parser_IdentifierNode_o, node)) {
        value = parser_BaseVisitor_visitIdentifierNode(_this, node, data);

    } else if (corto_instanceof(parser_MemberExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitMemberExpressionNode(_this, node, data);

    } else if (corto_instanceof(parser_CallExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitCallExpressionNode(_this, node, data);

    } else if (corto_instanceof(parser_ElementExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitElementExpressionNode(_this, node, data);

    } else {
        corto_error("unmanaged node type: %s", corto_idof(corto_typeof(node)));
        goto error;
    }

    return value;

error:
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitExpressionStatementNode_v(
    parser_BaseVisitor _this,
    parser_ExpressionStatementNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitExpressionStatementNode) */
    parser_BaseVisitor_visitExpressionNode(_this, node->expression, data);
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitFullCommaExpressionElementNode_v(
    parser_BaseVisitor _this,
    parser_FullCommaExpressionElementNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitFullCommaExpressionElementNode) */
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitFullCommaExpressionNode_v(
    parser_BaseVisitor _this,
    parser_FullCommaExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitFullCommaExpressionNode) */
    corto_iter i = corto_llIter(node->elements);
    while (corto_iterHasNext(&i)) {
        parser_FullCommaExpressionElementNode childNode = parser_FullCommaExpressionElementNode(
            corto_iterNext(&i)
        );
        parser_BaseVisitor_visitFullCommaExpressionElementNode(_this, childNode, data);
    }
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitFunctionDeclarationNode_v(
    parser_BaseVisitor _this,
    parser_FunctionDeclarationNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitFunctionDeclarationNode) */
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitFunctionParameterNode_v(
    parser_BaseVisitor _this,
    parser_FunctionParameterNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitFunctionParameterNode) */
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitIdentifierNode_v(
    parser_BaseVisitor _this,
    parser_IdentifierNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitIdentifierNode) */
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitInitializerTypeExpressionNode_v(
    parser_BaseVisitor _this,
    parser_InitializerTypeExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitInitializerTypeExpressionNode) */
    parser_BaseVisitor_visitBaseTypeExpressionNode(_this, node->type, data);
    if (node->arguments) {
        parser_BaseVisitor_visitFullCommaExpressionNode(_this, node->arguments, data);
    }
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitLiteralNode_v(
    parser_BaseVisitor _this,
    parser_LiteralNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitLiteralNode) */
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitMemberExpressionNode_v(
    parser_BaseVisitor _this,
    parser_MemberExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitMemberExpressionNode) */
    parser_BaseVisitor_visitExpressionNode(_this, node->owner, data);
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitObjectDeclarationNameNode_v(
    parser_BaseVisitor _this,
    parser_ObjectDeclarationNameNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitObjectDeclarationNameNode) */
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitObjectDeclarationNode_v(
    parser_BaseVisitor _this,
    parser_ObjectDeclarationNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitObjectDeclarationNode) */
    if (node->typeLabel) {
        parser_BaseVisitor_visitBaseTypeExpressionNode(_this, node->typeLabel, data);
    }
    {
        corto_iter i = corto_llIter(node->declarations);
        while (corto_iterHasNext(&i)) {
            parser_ObjectDeclarationNameNode childNode = parser_ObjectDeclarationNameNode(corto_iterNext(&i));
            parser_BaseVisitor_visitObjectDeclarationNameNode(_this, childNode, data);
        }
    }
    if (node->initializer) {
        parser_BaseVisitor_visitFullCommaExpressionNode(_this, node->initializer, data);
    }
    if (node->scope_) {
        parser_BaseVisitor_visitScopeNode(_this, node->scope_, data);
    }
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitProgramNode_v(
    parser_BaseVisitor _this,
    parser_ProgramNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitProgramNode) */
    int size = corto_llSize(node->statements);
    for (int i = 0; i < size; i++) {
        // TODO iterate with iterator
        parser_BaseVisitor_visitStatementNode(_this, corto_llGet(node->statements, i), data);
    }
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitScopeNode_v(
    parser_BaseVisitor _this,
    parser_ScopeNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitScopeNode) */
    corto_iter i = corto_llIter(node->statements);
    while (corto_iterHasNext(&i)) {
        parser_StatementNode childNode = parser_StatementNode(corto_iterNext(&i));
        parser_BaseVisitor_visitStatementNode(_this, childNode, data);
    }
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitSimpleTypeExpressionNode_v(
    parser_BaseVisitor _this,
    parser_SimpleTypeExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitSimpleTypeExpressionNode) */
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitStatementNode_v(
    parser_BaseVisitor _this,
    parser_StatementNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitStatementNode) */
    corto_object value = NULL;

    if (corto_instanceof(parser_ExpressionStatementNode_o, node)) {
        value = parser_BaseVisitor_visitExpressionStatementNode(_this, node, data);

    } else if (corto_instanceof(parser_FunctionDeclarationNode_o, node)) {
        value = parser_BaseVisitor_visitFunctionDeclarationNode(_this, node, data);

    } else if (corto_instanceof(parser_BlockNode_o, node)) {
        value = parser_BaseVisitor_visitBlockNode(_this, node, data);

    } else if (corto_instanceof(parser_ObjectDeclarationNode_o, node)) {
        value = parser_BaseVisitor_visitObjectDeclarationNode(_this, node, data);

    } else {
        corto_error("unmanaged node type: %s", corto_idof(corto_typeof(node)));
        goto error;
    }

    return value;

error:
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitUnaryExpressionNode_v(
    parser_BaseVisitor _this,
    parser_UnaryExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/BaseVisitor/visitUnaryExpressionNode) */
    parser_BaseVisitor_visitExpressionNode(_this, node->expression, data);
    return NULL;
/* $end */
}
