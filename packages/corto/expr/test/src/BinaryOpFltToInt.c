/* $CORTO_GENERATED
 *
 * BinaryOpFltToInt.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_BinaryOpFltToInt_tc_OM(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_OM) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    test_PointFlt *b = corto_createChild(root_o, "b", test_PointFlt_o);
    *a = 10;
    b->x = 20.5;
    
    ret = corto_expr_comp(&e, NULL, "a + b.x");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10.0 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_OO(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_OO) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    corto_float32 *b = corto_createChild(root_o, "b", corto_float32_o);
    *a = 10;
    *b = 20.5;
    
    ret = corto_expr_comp(&e, NULL, "a + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10.0 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_OR(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_OR) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    *a = 10;
    
    ret = corto_expr_comp(&e, NULL, "float32 b = 20.5; a + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10.0 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_OV(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_OV) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    *a = 10;
    
    ret = corto_expr_comp(&e, NULL, "a + 20.5");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float64_o);
    test_assert(e.function->parameters.length == 0);

    corto_float64 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10.0 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_RM(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_RM) */
    corto_int16 ret;
    corto_expr e;

    test_PointFlt *b = corto_createChild(root_o, "b", test_PointFlt_o);
    b->x = 20.5;
    
    ret = corto_expr_comp(&e, NULL, "int32 a = 10; a + b.x");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10.0 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_RO(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_RO) */
    corto_int16 ret;
    corto_expr e;

    corto_float32 *b = corto_createChild(root_o, "b", corto_float32_o);
    *b = 20.5;
    
    ret = corto_expr_comp(&e, NULL, "int32 a = 10; a + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10.0 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_RR(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_RR) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "float32 a = 10; float32 b = 20.5; a + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10.0 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_RV(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_RV) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32 a = 10; a + 20.5");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float64_o);
    test_assert(e.function->parameters.length == 0);

    corto_float64 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10.0 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_VM(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_VM) */
    corto_int16 ret;
    corto_expr e;

    test_PointFlt *b = corto_createChild(root_o, "b", test_PointFlt_o);
    b->x = 20.5;
    
    ret = corto_expr_comp(&e, NULL, "10 + b.x");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10.0 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_VO(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_VO) */
    corto_int16 ret;
    corto_expr e;

    corto_float32 *b = corto_createChild(root_o, "b", corto_float32_o);
    *b = 20.5;
    
    ret = corto_expr_comp(&e, NULL, "10 + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_VR(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_VR) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "float32 b = 20.5; 10 + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOpFltToInt_tc_VV(
    test_BinaryOpFltToInt this)
{
/* $begin(test/BinaryOpFltToInt/tc_VV) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "10 + 20.5");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float64_o);
    test_assert(e.function->parameters.length == 0);

    corto_float64 result = 0;
    corto_call(e.function, &result);
    test_assertflt(result, 10 + 20.5);

    corto_expr_free(&e);
/* $end */
}
