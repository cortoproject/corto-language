/* $CORTO_GENERATED
 *
 * BooleanLiteralNode.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/parser/parser.h>

corto_int16 _parser_BooleanLiteralNode_construct(
    parser_BooleanLiteralNode _this)
{
/* $begin(corto/parser/BooleanLiteralNode/construct) */
    parser_ExpressionNode(_this)->type_ = corto_type(corto_bool_o);
    return 0;
/* $end */
}

corto_word _parser_BooleanLiteralNode_getValue(
    parser_BooleanLiteralNode _this)
{
/* $begin(corto/parser/BooleanLiteralNode/getValue) */
    return (corto_word)&_this->value;
/* $end */
}
