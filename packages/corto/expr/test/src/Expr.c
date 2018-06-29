/* $CORTO_GENERATED
 *
 * Expr.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Expr_tc_assign(
    test_Expr this)
{
/* $begin(test/Expr/tc_assign) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32 a; a = 10");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);
    test_assert(!corto_lookup(NULL, "a"));

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_assignExplicitVar(
    test_Expr this)
{
/* $begin(test/Expr/tc_assignExplicitVar) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "var int32 a; a = 10");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);
    test_assert(!corto_lookup(NULL, "a"));

    corto_int32 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_assignMixedType(
    test_Expr this)
{
/* $begin(test/Expr/tc_assignMixedType) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32 a; a = 10.5");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);
    test_assert(!corto_lookup(NULL, "a"));

    corto_int32 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);

    corto_expr_free(&e);
    
/* $end */
}

corto_void _test_Expr_tc_assignObject(
    test_Expr this)
{
/* $begin(test/Expr/tc_assignObject) */
    corto_int16 ret;
    corto_expr e;
    corto_int32 *a = corto_create(root_o, "a", corto_int32_o);
    
    ret = corto_expr_comp(&e, NULL, "/a = 10");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);
    test_assertint(*a, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_assignObjectMixedType(
    test_Expr this)
{
/* $begin(test/Expr/tc_assignObjectMixedType) */
    corto_int16 ret;
    corto_expr e;
    corto_int32 *a = corto_create(root_o, "a", corto_int32_o);
    
    ret = corto_expr_comp(&e, NULL, "/a = 10.5");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);
    test_assertint(*a, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_cast(
    test_Expr this)
{
/* $begin(test/Expr/tc_cast) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32(10 + 20.5)");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

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
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_string_o);
    test_assert(e.function->parameters.length == 0);

    corto_string result = 0;
    corto_invoke(e.function, &result);
    test_assertstr(result, "1020");

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_composite(
    test_Expr this)
{
/* $begin(test/Expr/tc_composite) */
    corto_int16 ret;
    corto_expr e;
    corto_expr_opt opt = {.return_type = corto_type(test_Point_o)};
    
    ret = corto_expr_comp(&e, &opt, "{10, 20}");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)test_Point_o);
    test_assert(e.function->parameters.length == 0);

    test_Point result = {0, 0};
    corto_invoke(e.function, &result);
    test_assertint(result.x, 10);
    test_assertint(result.y, 20);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_compositeCast(
    test_Expr this)
{
/* $begin(test/Expr/tc_compositeCast) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "test/Point({10, 20})");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)test_Point_o);
    test_assert(e.function->parameters.length == 0);

    test_Point result = {0, 0};
    corto_invoke(e.function, &result);
    test_assertint(result.x, 10);
    test_assertint(result.y, 20);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_cond(
    test_Expr this)
{
/* $begin(test/Expr/tc_cond) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "10 == (5 + 5)");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_bool_o);
    test_assert(e.function->parameters.length == 0);

    corto_bool result = FALSE;
    corto_invoke(e.function, &result);
    test_assertint(result, TRUE);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_div(
    test_Expr this)
{
/* $begin(test/Expr/tc_div) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "10 / 2");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_float64_o);
    test_assert(e.function->parameters.length == 0);

    corto_float64 result = 0;
    corto_invoke(e.function, &result);
    test_assertflt(result, 10 / 2);

    corto_expr_free(&e);

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
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_uint64_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint64 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_primitive16(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitive16) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "uint16(10)");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_uint16_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint16 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_primitive32(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitive32) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "uint32(10)");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_uint32_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint32 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_primitive8(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitive8) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "uint8(10)");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_uint8_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint8 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);

    corto_expr_free(&e);

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
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_uint64_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint64 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 30);

    corto_expr_free(&e);

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
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_float64_o);
    test_assert(e.function->parameters.length == 0);

    corto_float64 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10 + 20.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_primitiveBool(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitiveBool) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "true");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_bool_o);
    test_assert(e.function->parameters.length == 0);

    corto_bool result = 0;
    corto_invoke(e.function, &result);
    test_assertflt(result, TRUE);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_primitiveDbl(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitiveDbl) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "10.5");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_float64_o);
    test_assert(e.function->parameters.length == 0);

    corto_float64 result = 0;
    corto_invoke(e.function, &result);
    test_assertflt(result, 10.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_primitiveFlt(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitiveFlt) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "float32(10.5)");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 0);

    corto_float32 result = 0;
    corto_invoke(e.function, &result);
    test_assertflt(result, (corto_float32)10.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_primitiveNot(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitiveNot) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "!true");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_bool_o);
    test_assert(e.function->parameters.length == 0);

    corto_bool result = 0;
    corto_invoke(e.function, &result);
    test_assertflt(result, FALSE);

    corto_expr_free(&e);
/* $end */
}

corto_void _test_Expr_tc_primitiveObject(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitiveObject) */
    corto_int16 ret;
    corto_expr e;

    corto_int32 *a = corto_create(root_o, "a", corto_int32_o);
    *a = 10;
    
    ret = corto_expr_comp(&e, NULL, "a");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type == (corto_type)corto_int32_o);
    test_assert(e.function->is_reference == TRUE);
    test_assert(e.function->parameters.length == 0);

    corto_int32 *result = NULL;
    corto_invoke(e.function, &result);
    test_assert(result != NULL);
    test_assertint(*(corto_int32*)result, 10);
    corto_release(result);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_Expr_tc_primitiveObjectValue(
    test_Expr this)
{
/* $begin(test/Expr/tc_primitiveObjectValue) */
    corto_int16 ret;
    corto_expr e;

    /* Force returning object value */
    corto_expr_opt opt = {
        .return_type = corto_type(corto_int32_o),
        .is_reference = FALSE
    };

    corto_int32 *a = corto_create(root_o, "a", corto_int32_o);
    *a = 10;
    
    ret = corto_expr_comp(&e, &opt, "a");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->return_type == (corto_type)corto_int32_o);
    test_assert(e.function->is_reference == FALSE);
    test_assert(e.function->parameters.length == 0);

    corto_int32 result = 0;
    corto_invoke(e.function, &result);
    test_assertint(result, 10);

    corto_expr_free(&e);
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
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_uint64_o);
    test_assert(e.function->parameters.length == 0);

    corto_uint64 result = 0;
    corto_invokeb(e.function, &result, NULL);
    test_assertint(result, 50);

    corto_expr_free(&e);

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
    test_assert(e.function->return_type != NULL);
    test_assert(e.function->return_type == (corto_type)corto_string_o);
    test_assert(e.function->parameters.length == 0);

    corto_string result = 0;
    corto_invoke(e.function, &result);
    test_assertstr(result, "Hello World");

    corto_expr_free(&e);

/* $end */
}
