/* $CORTO_GENERATED
 *
 * IntegerLiteralNode.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/parser/parser.h>

corto_int16 _parser_IntegerLiteralNode_construct(
    parser_IntegerLiteralNode _this)
{
/* $begin(corto/parser/IntegerLiteralNode/construct) */
    parser_ExpressionNode(_this)->type_ = corto_type(corto_uint64_o);
    return 0;
/* $end */
}

corto_word _parser_IntegerLiteralNode_getValue(
    parser_IntegerLiteralNode _this)
{
/* $begin(corto/parser/IntegerLiteralNode/getValue) */
    return (corto_word)&_this->value;
/* $end */
}
