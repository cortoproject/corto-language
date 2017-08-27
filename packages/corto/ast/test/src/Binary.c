/* $CORTO_GENERATED
 *
 * Binary.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Binary_setup(
    test_Binary this)
{
/* $begin(test/Binary/setup) */

    corto_load("cx/types/binary.cx", 0, NULL);

/* $end */
}

corto_void _test_Binary_tc_o_b16(
    test_Binary this)
{
/* $begin(test/Binary/tc_o_b16) */

    corto_object t = corto_resolve(root_o, "t_b16");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));

    corto_object o = corto_resolve(root_o, "o_b16");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == t);
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint16 v = *(corto_uint16*)o;
    test_assert(v == 0xFFFF);

    corto_release(o);
    corto_release(t);

/* $end */
}

corto_void _test_Binary_tc_o_b32(
    test_Binary this)
{
/* $begin(test/Binary/tc_o_b32) */

    corto_object t = corto_resolve(root_o, "t_b32");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));

    corto_object o = corto_resolve(root_o, "o_b32");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == t);
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint32 v = *(corto_uint32*)o;
    test_assert(v == 0xFFFFFFFF);

    corto_release(o);
    corto_release(t);

/* $end */
}

corto_void _test_Binary_tc_o_b64(
    test_Binary this)
{
/* $begin(test/Binary/tc_o_b64) */

    corto_object t = corto_resolve(root_o, "t_b64");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));

    corto_object o = corto_resolve(root_o, "o_b64");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == t);
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint64 v = *(corto_uint64*)o;
    test_assert(v == 0xFFFFFFFFFFFFFFFF);

    corto_release(o);
    corto_release(t);

/* $end */
}

corto_void _test_Binary_tc_o_b8(
    test_Binary this)
{
/* $begin(test/Binary/tc_o_b8) */

    corto_object t = corto_resolve(root_o, "t_b8");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));

    corto_object o = corto_resolve(root_o, "o_b8");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == t);
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint8 v = *(corto_uint8*)o;
    test_assert(v == 0xFF);

    corto_release(o);
    corto_release(t);

/* $end */
}

corto_void _test_Binary_tc_o_bword(
    test_Binary this)
{
/* $begin(test/Binary/tc_o_bword) */

    corto_object t = corto_resolve(root_o, "t_word");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));

    corto_object o = corto_resolve(root_o, "o_bword");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == t);
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_word v = *(corto_word*)o;
    test_assert(v == 0xFFFFFFFF);

    corto_release(o);
    corto_release(t);

/* $end */
}

corto_void _test_Binary_tc_o_octet(
    test_Binary this)
{
/* $begin(test/Binary/tc_o_octet) */

    corto_object o = corto_resolve(root_o, "o_octet");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_octet_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_octet v = *(corto_octet*)o;
    test_assert(v == 0xFF);

    corto_release(o);

/* $end */
}

corto_void _test_Binary_tc_o_word(
    test_Binary this)
{
/* $begin(test/Binary/tc_o_word) */

    corto_object o = corto_resolve(root_o, "o_word");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_word_o));
    test_assert(corto_checkState(o, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_octet v = *(corto_word*)o;
    test_assert(v == 0xFF);

    corto_release(o);

/* $end */
}

corto_void _test_Binary_tc_t_b16(
    test_Binary this)
{
/* $begin(test/Binary/tc_t_b16) */

    corto_object t = corto_resolve(root_o, "t_b16");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));
    test_assert(corto_checkState(t, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkAttr(t, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_binary v = corto_binary(t);
    test_assert(corto_primitive(v)->kind == CORTO_BINARY);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_16);

    corto_release(t);

/* $end */
}

corto_void _test_Binary_tc_t_b32(
    test_Binary this)
{
/* $begin(test/Binary/tc_t_b32) */

    corto_object t = corto_resolve(root_o, "t_b32");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));
    test_assert(corto_checkState(t, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkAttr(t, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_binary v = corto_binary(t);
    test_assert(corto_primitive(v)->kind == CORTO_BINARY);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_32);

    corto_release(t);

/* $end */
}

corto_void _test_Binary_tc_t_b64(
    test_Binary this)
{
/* $begin(test/Binary/tc_t_b64) */

    corto_object t = corto_resolve(root_o, "t_b64");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));
    test_assert(corto_checkState(t, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkAttr(t, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_binary v = corto_binary(t);
    test_assert(corto_primitive(v)->kind == CORTO_BINARY);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_64);

    corto_release(t);

/* $end */
}

corto_void _test_Binary_tc_t_b8(
    test_Binary this)
{
/* $begin(test/Binary/tc_t_b8) */

    corto_object t = corto_resolve(root_o, "t_b8");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));
    test_assert(corto_checkState(t, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkAttr(t, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_binary v = corto_binary(t);
    test_assert(corto_primitive(v)->kind == CORTO_BINARY);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_8);

    corto_release(t);

/* $end */
}

corto_void _test_Binary_tc_t_bword(
    test_Binary this)
{
/* $begin(test/Binary/tc_t_bword) */

    corto_object t = corto_resolve(root_o, "t_word");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_binary_o));
    test_assert(corto_checkState(t, CORTO_OBJECT_IS_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkAttr(t, CORTO_ATTR_NAMED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_binary v = corto_binary(t);
    test_assert(corto_primitive(v)->kind == CORTO_BINARY);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_WORD);

    corto_release(t);

/* $end */
}
