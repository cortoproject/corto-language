/* $CORTO_GENERATED
 *
 * ArgExpr.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_ArgExpr_tc_assign(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_assign) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32 a; a = %a", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));
    test_assert(!corto_lookup(NULL, "a"));

    corto_int32 result = 0;
    corto_call(e.function, &result, 10);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_assignExplicitVar(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_assignExplicitVar) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "var int32 a; a = %a", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));
    test_assert(!corto_lookup(NULL, "a"));

    corto_int32 result = 0;
    corto_call(e.function, &result, 10);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_assignMixedType(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_assignMixedType) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32 a; a = %a", "float32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_float32_o));
    test_assert(!corto_lookup(NULL, "a"));

    corto_int32 result = 0;
    corto_call(e.function, &result, 10.5);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_assignObject(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_assignObject) */
    corto_int16 ret;
    corto_expr e;
    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    
    ret = corto_expr_comp(&e, NULL, "/a = %a", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));

    corto_int32 result = 0;
    corto_call(e.function, &result, 10);
    test_assertint(result, 10);
    test_assertint(*a, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_assignObjectMixedType(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_assignObjectMixedType) */
    corto_int16 ret;
    corto_expr e;
    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    
    ret = corto_expr_comp(&e, NULL, "/a = %a", "float32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_float32_o));

    corto_int32 result = 0;
    corto_call(e.function, &result, 10.5);
    test_assertint(result, 10);
    test_assertint(*a, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_cast(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_cast) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "int32(%a + %b)", "int32", "float32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));
    test_assert(e.function->parameters.buffer[1].type == corto_type(corto_float32_o));

    corto_uint64 result = 0;
    corto_int32 a = 10;
    corto_float32 b = 20.5;
    void *args[] = {&a, &b};
    corto_callb(e.function, &result, args);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_castString(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_castString) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "string(%a) + string(%b)", "int32", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_string_o);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));
    test_assert(e.function->parameters.buffer[1].type == corto_type(corto_int32_o));

    corto_string result = 0;
    corto_call(e.function, &result, 10, 20);
    test_assertstr(result, "1020");

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_composite(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_composite) */
    corto_int16 ret;
    corto_expr e;
    corto_expr_opt opt = {.returnType = corto_type(test_Point_o)};
    
    ret = corto_expr_comp(&e, &opt, "{%a.x + %b.x, %a.y + %b.y}", "test/Point", "test/Point");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)test_Point_o);
    test_assert(e.function->returnsReference == FALSE);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[0].type == corto_type(test_Point_o));
    test_assert(e.function->parameters.buffer[1].type == corto_type(test_Point_o));

    test_Point p1 = {10, 20}, p2 = {30, 40}, result = {0, 0};
    corto_call(e.function, &result, &p1, &p2);
    test_assertint(result.x, 40);
    test_assertint(result.y, 60);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_compositeCast(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_compositeCast) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "test/Point({%a.x + %b.x, %a.y + %b.y})", "test/Point", "test/Point");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)test_Point_o);
    test_assert(e.function->returnsReference == FALSE);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[0].type == corto_type(test_Point_o));
    test_assert(e.function->parameters.buffer[1].type == corto_type(test_Point_o));

    test_Point p1 = {10, 20}, p2 = {30, 40}, result = {0, 0};
    corto_call(e.function, &result, &p1, &p2);
    test_assertint(result.x, 40);
    test_assertint(result.y, 60);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_cond(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_cond) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%a == %b", "int32", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_bool_o);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[1].type == corto_type(corto_int32_o));

    corto_bool result = FALSE;
    corto_call(e.function, &result, 10, 10);
    test_assertint(result, TRUE);

    corto_call(e.function, &result, 10, 20);
    test_assertint(result, FALSE);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_div(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_div) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%a / %b", "int32", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float64_o);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));
    test_assert(e.function->parameters.buffer[1].type == corto_type(corto_int32_o));

    corto_float64 result = 0;
    corto_call(e.function, &result, 10, 2);
    test_assertflt(result, 10 / 2);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitive(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitive) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%arg", "int64");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int64_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_arg");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int64_o));

    corto_uint64 result = 0;
    corto_call(e.function, &result, 10);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitive16(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitive16) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%arg", "int16");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int16_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_arg");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int16_o));

    corto_int16 result = 0;
    corto_call(e.function, &result, 10);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitive32(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitive32) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%arg", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_arg");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));

    corto_int32 result = 0;
    corto_call(e.function, &result, 10);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitive8(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitive8) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%arg", "int8");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int8_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_arg");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int8_o));

    corto_int8 result = 0;
    corto_call(e.function, &result, 10);
    test_assertint(result, 10);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitiveBinary(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitiveBinary) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%a + %b", "int32", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));
    test_assert(e.function->parameters.buffer[1].type == corto_type(corto_int32_o));

    corto_uint64 result = 0;
    corto_call(e.function, &result, 10, 20);
    test_assertint(result, 30);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitiveBinaryMixedType(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitiveBinaryMixedType) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%a + %b", "int32", "float32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));
    test_assert(e.function->parameters.buffer[1].type == corto_type(corto_float32_o));

    corto_float32 result = 0;
    corto_call(e.function, &result, 10, 20.5);
    test_assertflt(result, 30.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitiveBool(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitiveBool) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%arg", "bool");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_bool_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_arg");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_bool_o));

    corto_int16 result = 0;
    corto_call(e.function, &result, TRUE);
    test_assertint(result, TRUE);

    corto_call(e.function, &result, FALSE);
    test_assertint(result, FALSE);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitiveDbl(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitiveDbl) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%arg", "float64");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float64_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_arg");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_float64_o));

    corto_float64 result = 0;
    corto_call(e.function, &result, 10.5);
    
    test_assertflt(result, 10.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitiveFlt(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitiveFlt) */
    corto_int16 ret;
    corto_expr e;

    ret = corto_expr_comp(&e, NULL, "%arg", "float32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_float32_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_arg");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_float32_o));

    corto_float32 result = 0;
    corto_call(e.function, &result, 10.5);
    test_assertflt(result, 10.5);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitiveNot(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitiveNot) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "!%arg", "bool");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_bool_o);
    test_assert(e.function->parameters.length == 1);
    test_assertstr(e.function->parameters.buffer[0].name, "_arg");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_bool_o));

    corto_int16 result = 0;
    corto_call(e.function, &result, TRUE);
    test_assertint(result, FALSE);

    corto_call(e.function, &result, FALSE);
    test_assertint(result, TRUE);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_primitiveParentheses(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_primitiveParentheses) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%a + (%b * 2)", "int32", "int32");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_int32_o);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_int32_o));
    test_assert(e.function->parameters.buffer[1].type == corto_type(corto_int32_o));

    corto_int32 result = 0;
    corto_call(e.function, &result, 10, 20);
    test_assertint(result, 50);

    corto_expr_free(&e);

/* $end */
}

corto_void _test_ArgExpr_tc_stringConcat(
    test_ArgExpr this)
{
/* $begin(test/ArgExpr/tc_stringConcat) */
    corto_int16 ret;
    corto_expr e;
    
    ret = corto_expr_comp(&e, NULL, "%a + %b", "string", "string");
    test_assert(ret == 0);
    test_assert(e.function != NULL);
    test_assert(e.function->returnType != NULL);
    test_assert(e.function->returnType == (corto_type)corto_string_o);
    test_assert(e.function->parameters.length == 2);
    test_assertstr(e.function->parameters.buffer[0].name, "_a");
    test_assertstr(e.function->parameters.buffer[1].name, "_b");
    test_assert(e.function->parameters.buffer[0].type == corto_type(corto_string_o));
    test_assert(e.function->parameters.buffer[1].type == corto_type(corto_string_o));

    corto_string result = NULL;
    corto_call(e.function, &result, "Hello ", "World");
    test_assertstr(result, "Hello World");

    corto_expr_free(&e);

/* $end */
}
