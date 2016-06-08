/* $CORTO_GENERATED
 *
 * DeclarationVisitor.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/parser/parser.h>

corto_int16 _parser_DeclarationVisitor_construct(
    parser_DeclarationVisitor _this)
{
/* $begin(corto/parser/DeclarationVisitor/construct) */
    corto_setref(&_this->currentScope, root_o);
    return 0;
/* $end */
}

corto_object _parser_DeclarationVisitor_visit(
    parser_DeclarationVisitor _this)
{
/* $begin(corto/parser/DeclarationVisitor/visit) */
    return parser_BaseVisitor_visit_v(_this);
/* $end */
}

corto_object _parser_DeclarationVisitor_visitObjectDeclarationNameNode_v(
    parser_DeclarationVisitor _this,
    parser_ObjectDeclarationNameNode node)
{
/* $begin(corto/parser/DeclarationVisitor/visitObjectDeclarationNameNode) */
    corto_declareChild(
        _this->currentScope,
        node->name,
        _this->currentType
    );
    // TODO set arguments; but on "second" pass?
    return NULL;
/* $end */
}

corto_object _parser_DeclarationVisitor_visitObjectDeclarationNode_v(
    parser_DeclarationVisitor _this,
    parser_ObjectDeclarationNode node)
{
/* $begin(corto/parser/DeclarationVisitor/visitObjectDeclarationNode) */
    corto_type type = NULL;
    if (node->typeLabel) {
        parser_BaseVisitor_visitBaseTypeExpressionNode(_this, node->typeLabel);
        type = node->typeLabel->type_;
        // TODO work types that are anonymous objects
    } else {
        // TODO get default type
    }
    corto_setref(&_this->currentType, type);
    {
        corto_iter i = corto_llIter(node->declarations);
        while (corto_iterHasNext(&i)) {
            parser_ObjectDeclarationNameNode child =
                parser_ObjectDeclarationNameNode(corto_iterNext(&i));
            parser_DeclarationVisitor_visitObjectDeclarationNameNode(_this, child);
        }
    }
    return NULL;
/* $end */
}

corto_object _parser_DeclarationVisitor_visitSimpleTypeExpressionNode_v(
    parser_DeclarationVisitor _this,
    parser_SimpleTypeExpressionNode node)
{
/* $begin(corto/parser/DeclarationVisitor/visitSimpleTypeExpressionNode) */
    corto_object type = corto_resolve(NULL, node->name);
    if (type) {
        corto_setref(&parser_BaseTypeExpressionNode(node)->type_, type);
    }
    return NULL;
/* $end */
}
