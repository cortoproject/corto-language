/* $CORTO_GENERATED
 *
 * Int.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Int_setup(
    test_Int this)
{
/* $begin(test/Int/setup) */

    corto_load("cx/types/int.cx", 0, NULL);

/* $end */
}

corto_void _test_Int_tc_o_int16(
    test_Int this)
{
/* $begin(test/Int/tc_o_int16) */

    corto_object o = corto_resolve(root_o, "o_int16");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int16_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int16 v = *(corto_int16*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int16Max(
    test_Int this)
{
/* $begin(test/Int/tc_o_int16Max) */

    corto_object o = corto_resolve(root_o, "o_int16Max");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int16_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int16 v = *(corto_int16*)o;
    test_assert(v == 32767);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int16Min(
    test_Int this)
{
/* $begin(test/Int/tc_o_int16Min) */

    corto_object o = corto_resolve(root_o, "o_int16Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int16_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int16 v = *(corto_int16*)o;
    test_assert(v == -32768);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int32(
    test_Int this)
{
/* $begin(test/Int/tc_o_int32) */

    corto_object o = corto_resolve(root_o, "o_int32");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int32_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int32 v = *(corto_int32*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int32Max(
    test_Int this)
{
/* $begin(test/Int/tc_o_int32Max) */

    corto_object o = corto_resolve(root_o, "o_int32Max");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int32_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int32 v = *(corto_int32*)o;
    test_assert(v == 2147483647);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int32Min(
    test_Int this)
{
/* $begin(test/Int/tc_o_int32Min) */

    corto_object o = corto_resolve(root_o, "o_int32Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int32_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int32 v = *(corto_int32*)o;
    test_assert(v == -2147483648);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int64(
    test_Int this)
{
/* $begin(test/Int/tc_o_int64) */

    corto_object o = corto_resolve(root_o, "o_int64");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int64_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int64 v = *(corto_int64*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int64Max(
    test_Int this)
{
/* $begin(test/Int/tc_o_int64Max) */

    corto_object o = corto_resolve(root_o, "o_int64Max");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int64_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int64 v = *(corto_int64*)o;
    test_assert(v == 9223372036854775807);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int64Min(
    test_Int this)
{
/* $begin(test/Int/tc_o_int64Min) */

    corto_object o = corto_resolve(root_o, "o_int64Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int64_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int64 v = *(corto_int64*)o;
    test_assert(v == ((-9223372036854775807) - 1));

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int8(
    test_Int this)
{
/* $begin(test/Int/tc_o_int8) */

    corto_object o = corto_resolve(root_o, "o_int8");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int8_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int8 v = *(corto_int8*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int8Max(
    test_Int this)
{
/* $begin(test/Int/tc_o_int8Max) */

    corto_object o = corto_resolve(root_o, "o_int8Max");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int8_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int8 v = *(corto_int8*)o;
    test_assert(v == 127);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_o_int8Min(
    test_Int this)
{
/* $begin(test/Int/tc_o_int8Min) */

    corto_object o = corto_resolve(root_o, "o_int8Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_int8_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_int8 v = *(corto_int8*)o;
    test_assert(v == -128);

    corto_release(o);

/* $end */
}

corto_void _test_Int_tc_t_myInt16(
    test_Int this)
{
/* $begin(test/Int/tc_t_myInt16) */

    corto_object t = corto_resolve(root_o, "t_myInt16");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_checkState(t, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkAttr(t, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_int v = corto_int(t);
    test_assert(corto_primitive(v)->kind == CORTO_INTEGER);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_16);

    corto_release(t);

/* $end */
}

corto_void _test_Int_tc_t_myInt32(
    test_Int this)
{
/* $begin(test/Int/tc_t_myInt32) */

    corto_object t = corto_resolve(root_o, "t_myInt32");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_checkState(t, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkAttr(t, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_int v = corto_int(t);
    test_assert(corto_primitive(v)->kind == CORTO_INTEGER);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_32);

    corto_release(t);

/* $end */
}

corto_void _test_Int_tc_t_myInt64(
    test_Int this)
{
/* $begin(test/Int/tc_t_myInt64) */

    corto_object t = corto_resolve(root_o, "t_myInt64");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_checkState(t, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkAttr(t, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_int v = corto_int(t);
    test_assert(corto_primitive(v)->kind == CORTO_INTEGER);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_64);

    corto_release(t);

/* $end */
}

corto_void _test_Int_tc_t_myInt8(
    test_Int this)
{
/* $begin(test/Int/tc_t_myInt8) */

    corto_object t = corto_resolve(root_o, "t_myInt8");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_checkState(t, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkAttr(t, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_int v = corto_int(t);
    test_assert(corto_primitive(v)->kind == CORTO_INTEGER);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_8);

    corto_release(t);

/* $end */
}
