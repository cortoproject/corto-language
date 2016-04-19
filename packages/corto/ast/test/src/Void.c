/* $CORTO_GENERATED
 *
 * Void.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Void_setup(
    test_Void this)
{
/* $begin(test/Void/setup) */

    corto_load("cx/types/void.cx", 0, NULL);

/* $end */
}

corto_void _test_Void_tc_object(
    test_Void this)
{
/* $begin(test/Void/tc_object) */

    corto_object o = corto_resolve(root_o, "o_object");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_object_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    corto_release(o);

/* $end */
}

corto_void _test_Void_tc_void(
    test_Void this)
{
/* $begin(test/Void/tc_void) */

    corto_object o = corto_resolve(root_o, "o_void");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    corto_release(o);

/* $end */
}
