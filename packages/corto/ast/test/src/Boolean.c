/* $CORTO_GENERATED
 *
 * Boolean.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Boolean_setup(
    test_Boolean this)
{
/* $begin(test/Boolean/setup) */

    corto_load("cx/types/boolean.cx", 0, NULL);

/* $end */
}

corto_void _test_Boolean_tc_o_boolFalse(
    test_Boolean this)
{
/* $begin(test/Boolean/tc_o_boolFalse) */

    corto_object o = corto_resolve(root_o, "o_boolFalse");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_bool_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_bool v = *(corto_bool*)o;
    test_assert(v == FALSE);

    corto_release(o);

/* $end */
}

corto_void _test_Boolean_tc_o_boolTrue(
    test_Boolean this)
{
/* $begin(test/Boolean/tc_o_boolTrue) */

    corto_object o = corto_resolve(root_o, "o_boolTrue");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_bool_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_bool v = *(corto_bool*)o;
    test_assert(v == TRUE);

    corto_release(o);

/* $end */
}

corto_void _test_Boolean_tc_o_myboolFalse(
    test_Boolean this)
{
/* $begin(test/Boolean/tc_o_myboolFalse) */

    corto_object t = corto_resolve(root_o, "t_mybool");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_boolean_o));

    corto_object o = corto_resolve(root_o, "o_myboolFalse");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == t);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_bool v = *(corto_bool*)o;
    test_assert(v == FALSE);

    corto_release(o);
    corto_release(t);

/* $end */
}

corto_void _test_Boolean_tc_o_myboolTrue(
    test_Boolean this)
{
/* $begin(test/Boolean/tc_o_myboolTrue) */

    corto_object t = corto_resolve(root_o, "t_mybool");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_boolean_o));

    corto_object o = corto_resolve(root_o, "o_myboolTrue");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == t);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_bool v = *(corto_bool*)o;
    test_assert(v == TRUE);

    corto_release(o);
    corto_release(t);

/* $end */
}

corto_void _test_Boolean_tc_t_mybool(
    test_Boolean this)
{
/* $begin(test/Boolean/tc_t_mybool) */

    corto_object t = corto_resolve(root_o, "t_mybool");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_boolean_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_boolean v = corto_boolean(t);
    test_assert(corto_primitive(v)->kind == CORTO_BOOLEAN);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_8);

    corto_release(t);

/* $end */
}
