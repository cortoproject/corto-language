/* $CORTO_GENERATED
 *
 * BinaryOp.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_BinaryOp_tc_OM(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_OM) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *a = corto_create(root_o, "a", corto_int32_o);
    test_Point *b = corto_create(root_o, "b", test_Point_o);
    *a = 10;
    b->x = 20;
    
    ret = corto_expr_comp(&e, NULL, "a + b.x");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_OO(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_OO) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *a = corto_create(root_o, "a", corto_int32_o);
    corto_int32 *b = corto_create(root_o, "b", corto_int32_o);
    *a = 10;
    *b = 20;
    
    ret = corto_expr_comp(&e, NULL, "a + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_OR(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_OR) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *a = corto_create(root_o, "a", corto_int32_o);
    *a = 10;
    
    ret = corto_expr_comp(&e, NULL, "int32 b = 20; a + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_OV(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_OV) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *a = corto_create(root_o, "a", corto_int32_o);
    *a = 10;
    
    ret = corto_expr_comp(&e, NULL, "a + 20");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_RM(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_RM) */
    corto_int16 ret;
    corto_expr e;

    test_Point *b = corto_create(root_o, "b", test_Point_o);
    b->x = 20;
    
    ret = corto_expr_comp(&e, NULL, "int32 a = 10; a + b.x");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_RO(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_RO) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *b = corto_create(root_o, "b", corto_int32_o);
    *b = 20;
    
    ret = corto_expr_comp(&e, NULL, "int32 a = 10; a + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_RR(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_RR) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32 a = 10; int32 b = 20; a + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_RV(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_RV) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32 a = 10; a + 20");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_VM(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_VM) */
    corto_int16 ret;
    corto_expr e;

    test_Point *b = corto_create(root_o, "b", test_Point_o);
    b->x = 20;
    
    ret = corto_expr_comp(&e, NULL, "10 + b.x");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_VO(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_VO) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *b = corto_create(root_o, "b", corto_int32_o);
    *b = 20;
    
    ret = corto_expr_comp(&e, NULL, "10 + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_VR(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_VR) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32 b = 20; 10 + b");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_BinaryOp_tc_VV(
    test_BinaryOp this)
{
/* $begin(test/BinaryOp/tc_VV) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "10 + 20");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_uint64_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint64 result = 0;
    corto_call(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);
/* $end */
}
