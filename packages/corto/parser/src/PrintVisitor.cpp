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
    parser_BinaryExpressionNode node)
{
/* $begin(corto/parser/PrintVisitor/visitBinaryExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "binary expression\n");
    
    _this->level++;
    parser_PrintVisitor_visitExpressionNode(_this, node->left);
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "operator: %s\n", node->_operator);
    parser_PrintVisitor_visitExpressionNode(_this, node->right);
    _this->level--;

    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitCommaExpressionNode_v(
    parser_PrintVisitor _this,
    parser_CommaExpressionNode node)
{
/* $begin(corto/parser/PrintVisitor/visitCommaExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "comma expression\n");
    _this->level++;
    parser_BaseVisitor_visitCommaExpressionNode_v(_this, node);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitConditionalExpressionNode_v(
    parser_PrintVisitor _this,
    parser_ConditionalExpressionNode node)
{
/* $begin(corto/parser/PrintVisitor/visitConditionalExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "conditional expression\n");
    _this->level++;
    parser_BaseVisitor_visitConditionalExpressionNode_v(_this, node);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitExpressionNode_v(
    parser_PrintVisitor _this,
    parser_ExpressionNode node)
{
/* $begin(corto/parser/PrintVisitor/visitExpressionNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "expression\n");
    _this->level++;
    parser_BaseVisitor_visitExpressionNode_v(_this, node);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitProgramNode_v(
    parser_PrintVisitor _this,
    parser_ProgramNode node)
{
/* $begin(corto/parser/PrintVisitor/visitProgramNode) */
    corto_buffer_append(THIS_BUFFER, "program\n");
    _this->level++;
    parser_BaseVisitor_visitProgramNode_v(_this, node);
    _this->level--;
    return NULL;
/* $end */
}

corto_object _parser_PrintVisitor_visitStatementNode_v(
    parser_PrintVisitor _this,
    parser_StatementNode node)
{
/* $begin(corto/parser/PrintVisitor/visitStatementNode) */
    _appendIndentation(_this);
    corto_buffer_append(THIS_BUFFER, "statement\n");
    _this->level++;
    parser_BaseVisitor_visitStatementNode_v(_this, node);
    _this->level--;
    return NULL;
/* $end */
}
