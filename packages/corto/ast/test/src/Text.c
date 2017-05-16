/* $CORTO_GENERATED
 *
 * Text.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Text_setup(
    test_Text this)
{
/* $begin(test/Text/setup) */

    corto_load("cx/types/text.cx", 0, NULL);

/* $end */
}

corto_void _test_Text_tc_o_alphanum(
    test_Text this)
{
/* $begin(test/Text/tc_o_alphanum) */

    corto_object o = corto_resolve(root_o, "o_alphanum");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_string_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_string v = *(corto_string*)o;
    test_assert(!strcmp(v, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890"));

    corto_release(o);

/* $end */
}

corto_void _test_Text_tc_o_empty(
    test_Text this)
{
/* $begin(test/Text/tc_o_empty) */

    corto_object o = corto_resolve(root_o, "o_empty");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_string_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_string v = *(corto_string*)o;
    test_assert(!strcmp(v, ""));

    corto_release(o);

/* $end */
}

corto_void _test_Text_tc_o_newline(
    test_Text this)
{
/* $begin(test/Text/tc_o_newline) */

    corto_object o = corto_resolve(root_o, "o_newline");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_string_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_string v = *(corto_string*)o;
    test_assert(!strcmp(v, "\n"));

    corto_release(o);

/* $end */
}

corto_void _test_Text_tc_o_null(
    test_Text this)
{
/* $begin(test/Text/tc_o_null) */

    corto_object o = corto_resolve(root_o, "o_null");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_string_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_string v = *(corto_string*)o;
    test_assert(!v);

    corto_release(o);

/* $end */
}

corto_void _test_Text_tc_o_quote(
    test_Text this)
{
/* $begin(test/Text/tc_o_quote) */

    corto_object o = corto_resolve(root_o, "o_quote");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_string_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_string v = *(corto_string*)o;
    test_assert(!strcmp(v, "\""));

    corto_release(o);

/* $end */
}

corto_void _test_Text_tc_o_slash(
    test_Text this)
{
/* $begin(test/Text/tc_o_slash) */

    corto_object o = corto_resolve(root_o, "o_slash");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_string_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_string v = *(corto_string*)o;
    test_assert(!strcmp(v, "\\"));

    corto_release(o);

/* $end */
}

corto_void _test_Text_tc_o_specialchars(
    test_Text this)
{
/* $begin(test/Text/tc_o_specialchars) */

    corto_object o = corto_resolve(root_o, "o_specialchars");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_string_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_string v = *(corto_string*)o;
    test_assert(!strcmp(v, "`~!@#$%^&*()-_=+\\|[]{};:'\",.<>/?"));

    corto_release(o);

/* $end */
}
