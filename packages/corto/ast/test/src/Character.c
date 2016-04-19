/* $CORTO_GENERATED
 *
 * Character.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Character_setup(
    test_Character this)
{
/* $begin(test/Character/setup) */

    corto_load("cx/types/character.cx", 0, NULL);

/* $end */
}

corto_void _test_Character_tc_o_charAlpha(
    test_Character this)
{
/* $begin(test/Character/tc_o_charAlpha) */

    corto_object o = corto_resolve(root_o, "o_charAlpha");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_char_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_char v = *(corto_char*)o;
    test_assert(v == 'a');

    corto_release(o);

/* $end */
}

corto_void _test_Character_tc_o_charNewline(
    test_Character this)
{
/* $begin(test/Character/tc_o_charNewline) */

    corto_object o = corto_resolve(root_o, "o_charNewline");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_char_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_char v = *(corto_char*)o;
    test_assert(v == '\n');

    corto_release(o);

/* $end */
}

corto_void _test_Character_tc_o_charNull(
    test_Character this)
{
/* $begin(test/Character/tc_o_charNull) */

    corto_object o = corto_resolve(root_o, "o_charNull");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_char_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_char v = *(corto_char*)o;
    test_assert(v == 0);

    corto_release(o);

/* $end */
}

corto_void _test_Character_tc_o_charNum(
    test_Character this)
{
/* $begin(test/Character/tc_o_charNum) */

    corto_object o = corto_resolve(root_o, "o_charNum");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_char_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_char v = *(corto_char*)o;
    test_assert(v == '0');

    corto_release(o);

/* $end */
}

corto_void _test_Character_tc_o_charQuote(
    test_Character this)
{
/* $begin(test/Character/tc_o_charQuote) */

    corto_object o = corto_resolve(root_o, "o_charQuote");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_char_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_char v = *(corto_char*)o;
    test_assert(v == '\'');

    corto_release(o);

/* $end */
}

corto_void _test_Character_tc_o_charSlash(
    test_Character this)
{
/* $begin(test/Character/tc_o_charSlash) */

    corto_object o = corto_resolve(root_o, "o_charSlash");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(corto_char_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));

    corto_char v = *(corto_char*)o;
    test_assert(v == '\\');

    corto_release(o);

/* $end */
}

corto_void _test_Character_tc_t_mychar(
    test_Character this)
{
/* $begin(test/Character/tc_t_mychar) */

    corto_object t = corto_resolve(root_o, "t_mychar");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_character_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    corto_character v = corto_character(t);
    test_assert(corto_primitive(v)->kind == CORTO_CHARACTER);
    test_assert(corto_primitive(v)->width == CORTO_WIDTH_8);

    corto_release(t);

/* $end */
}
