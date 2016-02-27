/* $CORTO_GENERATED
 *
 * Uint.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Uint_setup(
    test_Uint this)
{
/* $begin(test/Uint/setup) */

    corto_load("cx/types/uint.cx", 0, NULL);

/* $end */
}

corto_void _test_Uint_tc_o_uint16(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint16) */

    corto_object o = corto_resolve(root_o, "o_uint16");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint16_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint16 v = *(corto_uint16*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint16Max(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint16Max) */

    corto_object o = corto_resolve(root_o, "o_uint16Max");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint16_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint16 v = *(corto_uint16*)o;
    test_assert(v == 65535);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint16Min(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint16Min) */

    corto_object o = corto_resolve(root_o, "o_uint16Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint16_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint16 v = *(corto_uint16*)o;
    test_assert(v == 0);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint32(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint32) */

    corto_object o = corto_resolve(root_o, "o_uint32");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint32 v = *(corto_uint32*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint32Max(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint32Max) */

    corto_object o = corto_resolve(root_o, "o_uint32Max");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint32 v = *(corto_uint32*)o;
    test_assert(v == 4294967295);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint32Min(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint32Min) */

    corto_object o = corto_resolve(root_o, "o_uint32Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint32_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint32 v = *(corto_uint32*)o;
    test_assert(v == 0);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint64(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint64) */

    corto_object o = corto_resolve(root_o, "o_uint64");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint64 v = *(corto_uint64*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint64Max(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint64Max) */

    corto_object o = corto_resolve(root_o, "o_uint64Max");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint64 v = *(corto_uint64*)o;
    test_assert(v == 18446744073709551613u);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint64Min(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint64Min) */

    corto_object o = corto_resolve(root_o, "o_uint64Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint64_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint64 v = *(corto_uint64*)o;
    test_assert(v == 0);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint8(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint8) */

    corto_object o = corto_resolve(root_o, "o_uint8");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint8_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint8 v = *(corto_uint8*)o;
    test_assert(v == 10);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint8Max(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint8Max) */

    corto_object o = corto_resolve(root_o, "o_uint8Max");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint8_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint8 v = *(corto_uint8*)o;
    test_assert(v == 255);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_o_uint8Min(
    test_Uint this)
{
/* $begin(test/Uint/tc_o_uint8Min) */

    corto_object o = corto_resolve(root_o, "o_uint8Min");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_uint8_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_uint8 v = *(corto_uint8*)o;
    test_assert(v == 0);

    corto_release(o);

/* $end */
}

corto_void _test_Uint_tc_t_myUint16(
    test_Uint this)
{
/* $begin(test/Uint/tc_t_myUint16) */

    corto_object t = corto_resolve(root_o, "t_myUint16");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_uint_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_uint v = corto_uint(t);
    test_assert(corto_primitive(v)->kind == CORTO_UINTEGER);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_16);

    corto_release(t);

/* $end */
}

corto_void _test_Uint_tc_t_myUint32(
    test_Uint this)
{
/* $begin(test/Uint/tc_t_myUint32) */

    corto_object t = corto_resolve(root_o, "t_myUint32");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_uint_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_uint v = corto_uint(t);
    test_assert(corto_primitive(v)->kind == CORTO_UINTEGER);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_32);

    corto_release(t);

/* $end */
}

corto_void _test_Uint_tc_t_myUint64(
    test_Uint this)
{
/* $begin(test/Uint/tc_t_myUint64) */

    corto_object t = corto_resolve(root_o, "t_myUint64");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_uint_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_uint v = corto_uint(t);
    test_assert(corto_primitive(v)->kind == CORTO_UINTEGER);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_64);

    corto_release(t);

/* $end */
}

corto_void _test_Uint_tc_t_myUint8(
    test_Uint this)
{
/* $begin(test/Uint/tc_t_myUint8) */

    corto_object t = corto_resolve(root_o, "t_myUint8");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_uint_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_uint v = corto_uint(t);
    test_assert(corto_primitive(v)->kind == CORTO_UINTEGER);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_8);

    corto_release(t);

/* $end */
}
