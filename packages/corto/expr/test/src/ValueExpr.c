/* $CORTO_GENERATED
 *
 * ValueExpr.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_ValueExpr_tc_compositeArg(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_compositeArg) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;
    test_Point p = {10, 20};

    ret = corto_expr_comp(&e, NULL, "test/Point({%a.x, %a.y})", "test/Point");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)test_Point_o);
    test_assert(e.function->returnsReference == FALSE);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assert(e.function->parameters.buffer[0].type == corto_type(test_Point_o));

    ret = corto_expr_run(&e, &result, &p);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(test_Point_o));
    test_assert(result.kind == CORTO_VALUE);
    test_assert(corto_value_ptrof(&result) != NULL);
    test_Point *ptr = corto_value_ptrof(&result);
    test_assertint(ptr->x, 10);
    test_assertint(ptr->y, 20);

    corto_value_free(&result);
    corto_expr_free(&e);

/* $end */
}

corto_void _test_ValueExpr_tc_compositeLiteral(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_compositeLiteral) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    ret = corto_expr_comp(&e, NULL, "test/Point({10, 20})");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)test_Point_o);
    test_assert(e.function->returnsReference == FALSE);
    test_assert(e.function->parameters.length == 0);

    ret = corto_expr_run(&e, &result);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(test_Point_o));
    test_assert(result.kind == CORTO_VALUE);
    test_assert(corto_value_ptrof(&result) != NULL);
    test_Point *ptr = corto_value_ptrof(&result);
    test_assertint(ptr->x, 10);
    test_assertint(ptr->y, 20);

    corto_value_free(&result);
    corto_expr_free(&e);

/* $end */
}

corto_void _test_ValueExpr_tc_compositeObject(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_compositeObject) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    test_Point *a = corto_createChild(root_o, "a", test_Point_o);
    test_assert(a != NULL);
    a->x = 10;
    a->y = 20;

    ret = corto_expr_comp(&e, NULL, "a");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)test_Point_o);
    test_assert(e.function->returnsReference == TRUE);
    test_assert(e.function->parameters.length == 0);

    ret = corto_expr_run(&e, &result);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(test_Point_o));
    test_assert(result.kind == CORTO_OBJECT);
    test_assert(corto_value_objectof(&result) == a);
    test_Point *ptr = corto_value_ptrof(&result);
    test_assertint(ptr->x, 10);
    test_assertint(ptr->y, 20);

    corto_value_free(&result);
    corto_expr_free(&e);

/* $end */
}

corto_void _test_ValueExpr_tc_compositeVar(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_compositeVar) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    ret = corto_expr_comp(&e, NULL, "test/Point a = {10, 20}; test/Point({a.x, a.y})");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)test_Point_o);
    test_assert(e.function->returnsReference == FALSE);
    test_assert(e.function->parameters.length == 0);

    ret = corto_expr_run(&e, &result);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(test_Point_o));
    test_assert(result.kind == CORTO_VALUE);
    test_assert(corto_value_ptrof(&result) != NULL);
    test_Point *ptr = corto_value_ptrof(&result);
    test_assertint(ptr->x, 10);
    test_assertint(ptr->y, 20);

    corto_value_free(&result);
    corto_expr_free(&e);

/* $end */
}

corto_void _test_ValueExpr_tc_primitiveArg(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_primitiveArg) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    ret = corto_expr_comp(&e, NULL, "%a", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));

    ret = corto_expr_run(&e, &result, 10);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(corto_int32_o));
    test_assert(result.kind == CORTO_VALUE);
    test_assert(corto_value_ptrof(&result) != NULL);
    test_assertint(*(corto_int32*)corto_value_ptrof(&result), 10);

    corto_value_free(&result);
    corto_expr_free(&e);

/* $end */
}

corto_void _test_ValueExpr_tc_primitiveLiteral(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_primitiveLiteral) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    ret = corto_expr_comp(&e, NULL, "10");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_uint64_o);
    test_assert(e.function->parameters.length == 0);

    ret = corto_expr_run(&e, &result, 10);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(corto_uint64_o));
    test_assert(result.kind == CORTO_VALUE);
    test_assert(corto_value_ptrof(&result) != NULL);
    test_assertint(*(corto_int32*)corto_value_ptrof(&result), 10);

    corto_value_free(&result);
    corto_expr_free(&e);

/* $end */
}

corto_void _test_ValueExpr_tc_primitiveObject(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_primitiveObject) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    test_assert(a != NULL);
    *a = 10;

    ret = corto_expr_comp(&e, NULL, "a");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->returnsReference == TRUE);
    test_assert(e.function->parameters.length == 0);

    ret = corto_expr_run(&e, &result);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(corto_int32_o));
    test_assert(result.kind == CORTO_OBJECT);
    test_assert(corto_value_objectof(&result) == a);
    test_assertint(*(corto_int32*)corto_value_ptrof(&result), 10);

    corto_value_free(&result);
    corto_expr_free(&e);
    test_assert(corto_delete(a) == 0);

/* $end */
}

corto_void _test_ValueExpr_tc_primitiveVar(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_primitiveVar) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    ret = corto_expr_comp(&e, NULL, "int32 a = 10; a");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    ret = corto_expr_run(&e, &result);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(corto_int32_o));
    test_assert(result.kind == CORTO_VALUE);
    test_assert(corto_value_ptrof(&result) != NULL);
    test_assertint(*(corto_int32*)corto_value_ptrof(&result), 10);

    corto_value_free(&result);
    corto_expr_free(&e);

/* $end */
}

corto_void _test_ValueExpr_tc_referenceArg(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_referenceArg) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    test_PointRef a = corto_createChild(root_o, "a", test_PointRef_o);
    test_assert(a != NULL);
    a->x = 10;
    a->y = 20;

    ret = corto_expr_comp(&e, NULL, "%a", "/test/PointRef");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)test_PointRef_o);
    test_assert(e.function->returnsReference == TRUE);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assert(e.function->parameters.buffer[0].type == corto_type(test_PointRef_o));

    ret = corto_expr_run(&e, &result, a);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(test_PointRef_o));
    test_assert(result.kind == CORTO_OBJECT);
    test_assert(corto_value_objectof(&result) == a);

    corto_value_free(&result);
    corto_expr_free(&e);
    test_assert(corto_delete(a) == 0);

/* $end */
}

corto_void _test_ValueExpr_tc_referenceObject(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_referenceObject) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    test_PointRef a = corto_createChild(root_o, "a", test_PointRef_o);
    test_assert(a != NULL);
    a->x = 10;
    a->y = 20;

    ret = corto_expr_comp(&e, NULL, "a");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)test_PointRef_o);
    test_assert(e.function->returnsReference == TRUE);
    test_assert(e.function->parameters.length == 0);

    ret = corto_expr_run(&e, &result);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(test_PointRef_o));
    test_assert(result.kind == CORTO_OBJECT);
    test_assert(corto_value_objectof(&result) == a);

    corto_value_free(&result);
    corto_expr_free(&e);
    test_assert(corto_delete(a) == 0);

/* $end */
}

corto_void _test_ValueExpr_tc_referenceVar(
    test_ValueExpr this)
{
/* $begin(test/ValueExpr/tc_referenceVar) */
    corto_value result = corto_value_empty();
    corto_expr e;
    corto_int16 ret;

    ret = corto_expr_comp(&e, NULL, "test/PointRef a = test/PointRef{10, 20}; a");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType == (corto_type)test_PointRef_o);
    test_assert(e.function->returnsReference == TRUE);
    test_assert(e.function->parameters.length == 0);

    ret = corto_expr_run(&e, &result);
    test_assert(ret == 0);
    test_assert(corto_value_typeof(&result) == corto_type(test_PointRef_o));
    test_assert(result.kind == CORTO_OBJECT);
    test_assert(corto_value_objectof(&result) != NULL);
    test_PointRef o = corto_value_objectof(&result);
    test_assertint(o->x, 10);
    test_assertint(o->y, 20);

    corto_value_free(&result);
    corto_expr_free(&e);

/* $end */
}
