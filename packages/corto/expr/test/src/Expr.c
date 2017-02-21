/* $CORTO_GENERATED
 *
 * Expr.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Expr_tc_cast(
    test_Expr this)
{
/* $begin(test/Expr/tc_cast) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32(10 + 20.5)");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

/* $end */
}

corto_void _test_Expr_tc_castString(
    test_Expr this)
{
/* $begin(test/Expr/tc_castString) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "string(10) + string(20)");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_string_o);
    test_assert(e.function->parameters.length == 0);

    corto_string result = 0;
    corto_call(e.function, &result);
    test_assertstr(result, "1020");

/* $end */
}

corto_void _test_Expr_tc_composite(
    test_Expr this)
{
/* $begin(test/Expr/tc_composite) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "test/Point{10,20}.x + test/Point{30,40}.y");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 50);

/* $end */
}

corto_void _test_Expr_tc_primitive(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitive) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "10");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_uint64_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint64 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 10);

/* $end */
}

corto_void _test_Expr_tc_primitiveBinary(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitiveBinary) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "10 + 20");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_uint64_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint64 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

/* $end */
}

corto_void _test_Expr_tc_primitiveBinaryMixedType(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitiveBinaryMixedType) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "10 + 20.5");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float64_o);
    test_assert(e.function->parameters.length == 0);

    corto_float64 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 10 + 20.5);


/* $end */
}

corto_void _test_Expr_tc_primitiveParentheses(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitiveParentheses) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "10 + (20 * 2)");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_uint64_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint64 result = 0;
    corto_callb(e.function, &result, NULL);
    test_assertint(result, 50);

/* $end */
}

corto_void _test_Expr_tc_stringConcat(
    test_Expr this)
{
/* $begin(test/Expr/tc_stringConcat) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "\"Hello \" + \"World\"");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_string_o);
    test_assert(e.function->parameters.length == 0);

    corto_string result = 0;
    corto_call(e.function, &result);
    test_assertstr(result, "Hello World");

/* $end */
}
