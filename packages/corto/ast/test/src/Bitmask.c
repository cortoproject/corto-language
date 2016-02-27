/* $CORTO_GENERATED
 *
 * Bitmask.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Bitmask_setup(
    test_Bitmask this)
{
/* $begin(test/Bitmask/setup) */

    corto_load("cx/types/bitmask.cx", 0, NULL);

/* $end */
}

corto_void _test_Bitmask_tc_o_explicit(
    test_Bitmask this)
{
/* $begin(test/Bitmask/tc_o_explicit) */

    corto_object t = corto_resolve(root_o, "Explicit");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_bitmask_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_resolve(root_o, "o_explicitA");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 1);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_explicitB");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 2);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_explicitC");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 4);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Bitmask_tc_o_oneLine(
    test_Bitmask this)
{
/* $begin(test/Bitmask/tc_o_oneLine) */

    corto_object t = corto_resolve(root_o, "OneLine");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_bitmask_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_resolve(root_o, "o_oneLineA");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 1);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_oneLineB");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 2);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_oneLineC");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 4);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Bitmask_tc_o_oneLineFullname(
    test_Bitmask this)
{
/* $begin(test/Bitmask/tc_o_oneLineFullname) */

    corto_object t = corto_resolve(root_o, "OneLine");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_bitmask_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_resolve(root_o, "o_oneLineAFullname");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 1);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_oneLineBFullname");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 2);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_oneLineCFullname");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 4);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Bitmask_tc_o_oneLineFullnameSlash(
    test_Bitmask this)
{
/* $begin(test/Bitmask/tc_o_oneLineFullnameSlash) */

    corto_object t = corto_resolve(root_o, "OneLine");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_bitmask_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_resolve(root_o, "o_oneLineAFullnameSlash");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 1);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_oneLineBFullnameSlash");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 2);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_oneLineCFullnameSlash");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 4);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Bitmask_tc_o_userValues(
    test_Bitmask this)
{
/* $begin(test/Bitmask/tc_o_userValues) */

    corto_object t = corto_resolve(root_o, "UserValues");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_bitmask_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_resolve(root_o, "o_userValuesA");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 1);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_userValuesB");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 2);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_userValuesC");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 4);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_userValuesA_B");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 3);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_userValuesA_C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 5);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_userValuesB_C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 6);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_userValuesA_B_C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(t));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

        corto_constant v = *(corto_constant*)o;
        test_assert(v == 7);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Bitmask_tc_t_Explicit(
    test_Bitmask this)
{
/* $begin(test/Bitmask/tc_t_Explicit) */

    corto_object t = corto_resolve(root_o, "Explicit");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_bitmask_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_lookup(t, "A");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 1);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "B");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 2);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 4);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Bitmask_tc_t_MultiLine(
    test_Bitmask this)
{
/* $begin(test/Bitmask/tc_t_MultiLine) */

    corto_object t = corto_resolve(root_o, "MultiLine");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_bitmask_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_lookup(t, "A");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 1);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "B");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 2);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 4);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Bitmask_tc_t_OneLine(
    test_Bitmask this)
{
/* $begin(test/Bitmask/tc_t_OneLine) */

    corto_object t = corto_resolve(root_o, "OneLine");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_bitmask_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_lookup(t, "A");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 1);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "B");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 2);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 4);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Bitmask_tc_t_UserValues(
    test_Bitmask this)
{
/* $begin(test/Bitmask/tc_t_UserValues) */

    corto_object t = corto_resolve(root_o, "UserValues");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_bitmask_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_lookup(t, "A");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 1);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "B");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 2);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 4);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "A_B");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 3);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "A_C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 5);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "B_C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 6);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "A_B_C");
        test_assert(o != NULL);
        test_assert(corto_typeof(o) == corto_type(corto_constant_o));
        test_assert(corto_checkState(o, CORTO_VALID));
        test_assert(corto_checkState(o, CORTO_DECLARED));
        test_assert(corto_checkState(o, CORTO_DEFINED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
        test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
        test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
        test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
        corto_constant *c = corto_constant(o);
        test_assert((*c) == 7);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}
