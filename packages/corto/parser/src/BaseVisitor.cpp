/* $CORTO_GENERATED
 *
 * BaseVisitor.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/parser/parser.h>

/* $header() */

// typedef corto_object ___ (*NodeHandler)(parser_BaseVisitor, parser_Node);

// struct NodeHandlerMapping {
//     corto_type type;
//     NodeHandler handler;
// };
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
    return parser_BaseVisitor_visitProgramNode(_this, _this->parser->programReturn);
/* $end */
}

corto_object _parser_BaseVisitor_visitBinaryExpressionNode_v(
    parser_BaseVisitor _this,
    parser_BinaryExpressionNode node)
{
/* $begin(corto/parser/BaseVisitor/visitBinaryExpressionNode) */
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitCommaExpressionNode_v(
    parser_BaseVisitor _this,
    parser_CommaExpressionNode node)
{
/* $begin(corto/parser/BaseVisitor/visitCommaExpressionNode) */
    corto_iter i = corto_llIter(node->expressions);
    while (corto_iterHasNext(&i)) {
        parser_ExpressionNode childNode = parser_ExpressionNode(corto_iterNext(&i));
        parser_BaseVisitor_visitExpressionNode(_this, childNode);
    }
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitConditionalExpressionNode_v(
    parser_BaseVisitor _this,
    parser_ConditionalExpressionNode node)
{
/* $begin(corto/parser/BaseVisitor/visitConditionalExpressionNode) */
    parser_BaseVisitor_visitExpressionNode(_this, node->condition);
    parser_BaseVisitor_visitExpressionNode(_this, node->trueValue);
    parser_BaseVisitor_visitExpressionNode(_this, node->falseValue);
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitExpressionNode_v(
    parser_BaseVisitor _this,
    parser_ExpressionNode node)
{
/* $begin(corto/parser/BaseVisitor/visitExpressionNode) */
    corto_object value = NULL;
    if (corto_instanceof(parser_BinaryExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitBinaryExpressionNode(_this, node);

    } else if (corto_instanceof(parser_CommaExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitCommaExpressionNode(_this, node);

    } else if (corto_instanceof(parser_ConditionalExpressionNode_o, node)) {
        value = parser_BaseVisitor_visitConditionalExpressionNode(_this, node);

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
    parser_ExpressionStatementNode node)
{
/* $begin(corto/parser/BaseVisitor/visitExpressionStatementNode) */
    puts(">>> _parser_BaseVisitor_visitExpressionStatementNode_v");
    parser_BaseVisitor_visitExpressionNode(_this, node->expression);
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitProgramNode_v(
    parser_BaseVisitor _this,
    parser_ProgramNode node)
{
/* $begin(corto/parser/BaseVisitor/visitProgramNode) */
    int size = corto_llSize(node->statements);
    printf(" size is : %d\n", size);
    for (int i = 0; i < size; i++) {
        // TODO iterate with iterator
        parser_BaseVisitor_visitStatementNode(_this, corto_llGet(node->statements, i));
    }
    return NULL;
/* $end */
}

corto_object _parser_BaseVisitor_visitStatementNode_v(
    parser_BaseVisitor _this,
    parser_StatementNode node)
{
/* $begin(corto/parser/BaseVisitor/visitStatementNode) */
    if (corto_instanceof(parser_ExpressionStatementNode_o, node)) {
        parser_BaseVisitor_visitExpressionStatementNode(_this, node);
    } else {
        corto_error("unmanaged node type: %s", corto_idof(corto_typeof(node)));
    }
    return NULL;
/* $end */
}
