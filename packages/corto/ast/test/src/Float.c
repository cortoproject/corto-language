/* $CORTO_GENERATED
 *
 * Float.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Float_setup(
    test_Float this)
{
/* $begin(test/Float/setup) */

    corto_load("cx/types/float.cx", 0, NULL);

/* $end */
}

corto_void _test_Float_tc_o_float32(
    test_Float this)
{
/* $begin(test/Float/tc_o_float32) */

    corto_object o = corto_resolve(root_o, "o_float32");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float32 v = *(corto_float32*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float32e(
    test_Float this)
{
/* $begin(test/Float/tc_o_float32e) */

    corto_object o = corto_resolve(root_o, "o_float32e");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float32 v = *(corto_float32*)o;
    test_assert(v == 100);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float32eMin(
    test_Float this)
{
/* $begin(test/Float/tc_o_float32eMin) */

    corto_object o = corto_resolve(root_o, "o_float32eMin");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float32 v = *(corto_float32*)o;
    test_assert(v == (corto_float32)1e-2);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float32eMinPt(
    test_Float this)
{
/* $begin(test/Float/tc_o_float32eMinPt) */

    corto_object o = corto_resolve(root_o, "o_float32eMinPt");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float32 v = *(corto_float32*)o;
    test_assert(v == (corto_float32)1.05e-2);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float32ePt(
    test_Float this)
{
/* $begin(test/Float/tc_o_float32ePt) */

    corto_object o = corto_resolve(root_o, "o_float32ePt");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float32 v = *(corto_float32*)o;
    test_assert(v == (corto_float32)1.05e2);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float32Min(
    test_Float this)
{
/* $begin(test/Float/tc_o_float32Min) */

    corto_object o = corto_resolve(root_o, "o_float32Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float32 v = *(corto_float32*)o;
    test_assert(v == -10);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float32MinPt(
    test_Float this)
{
/* $begin(test/Float/tc_o_float32MinPt) */

    corto_object o = corto_resolve(root_o, "o_float32MinPt");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float32 v = *(corto_float32*)o;
    test_assert(v == -10.5);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float32Pt(
    test_Float this)
{
/* $begin(test/Float/tc_o_float32Pt) */

    corto_object o = corto_resolve(root_o, "o_float32Pt");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float32 v = *(corto_float32*)o;
    test_assert(v == 10.5);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float64(
    test_Float this)
{
/* $begin(test/Float/tc_o_float64) */

    corto_object o = corto_resolve(root_o, "o_float64");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float64 v = *(corto_float64*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float64e(
    test_Float this)
{
/* $begin(test/Float/tc_o_float64e) */

    corto_object o = corto_resolve(root_o, "o_float64e");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float64 v = *(corto_float64*)o;
    test_assert(v == 1e2);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float64eMin(
    test_Float this)
{
/* $begin(test/Float/tc_o_float64eMin) */

    corto_object o = corto_resolve(root_o, "o_float64eMin");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float64 v = *(corto_float64*)o;
    test_assert(v == 1e-2);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float64eMinPt(
    test_Float this)
{
/* $begin(test/Float/tc_o_float64eMinPt) */

    corto_object o = corto_resolve(root_o, "o_float64eMinPt");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float64 v = *(corto_float64*)o;
    test_assert(v == 1.05e-2);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float64ePt(
    test_Float this)
{
/* $begin(test/Float/tc_o_float64ePt) */

    corto_object o = corto_resolve(root_o, "o_float64ePt");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float64 v = *(corto_float64*)o;
    test_assert(v == 1.05e2);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float64Min(
    test_Float this)
{
/* $begin(test/Float/tc_o_float64Min) */

    corto_object o = corto_resolve(root_o, "o_float64Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float64 v = *(corto_float64*)o;
    test_assert(v == -10);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float64MinPt(
    test_Float this)
{
/* $begin(test/Float/tc_o_float64MinPt) */

    corto_object o = corto_resolve(root_o, "o_float64MinPt");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float64 v = *(corto_float64*)o;
    test_assert(v == -10.5);

    corto_release(o);

/* $end */
}

corto_void _test_Float_tc_o_float64Pt(
    test_Float this)
{
/* $begin(test/Float/tc_o_float64Pt) */

    corto_object o = corto_resolve(root_o, "o_float64Pt");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_float64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_float64 v = *(corto_float64*)o;
    test_assert(v == 10.5);

    corto_release(o);

/* $end */
}
