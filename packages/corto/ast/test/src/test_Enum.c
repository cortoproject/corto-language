/* $CORTO_GENERATED
 *
 * test_Enum.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Enum_setup(test_Enum this) {
/* $begin(test/Enum/setup) */

    corto_load("cx/types/enum.cx", 0, NULL);

/* $end */
}

corto_void _test_Enum_tc_o_color(test_Enum this) {
/* $begin(test/Enum/tc_o_color) */

    corto_object t = corto_resolve(root_o, "Color");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_enum_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_resolve(root_o, "o_colorRed");
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
        test_assert(v == 0);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_colorGreen");
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
        corto_object o = corto_resolve(root_o, "o_colorBlue");
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

    corto_release(t);

/* $end */
}

corto_void _test_Enum_tc_o_colorFullname(test_Enum this) {
/* $begin(test/Enum/tc_o_colorFullname) */

    corto_object t = corto_resolve(root_o, "Color");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_enum_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_resolve(root_o, "o_colorRedFullname");
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
        test_assert(v == 0);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_colorGreenFullname");
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
        corto_object o = corto_resolve(root_o, "o_colorBlueFullname");
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

    corto_release(t);

/* $end */
}

corto_void _test_Enum_tc_o_temperature(test_Enum this) {
/* $begin(test/Enum/tc_o_temperature) */

    corto_object t = corto_resolve(root_o, "Temperature");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_enum_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_resolve(root_o, "o_temperatureCold");
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
        test_assert(v == 40);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_temperatureModerate");
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
        test_assert(v == 65);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_temperatureHot");
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
        test_assert(v == 90);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Enum_tc_o_transportation(test_Enum this) {
/* $begin(test/Enum/tc_o_transportation) */

    corto_object t = corto_resolve(root_o, "Transportation");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_enum_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_resolve(root_o, "o_transportationByCar");
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
        test_assert(v == 0);
        corto_release(o);
    }

    {
        corto_object o = corto_resolve(root_o, "o_transportationByBus");
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
        corto_object o = corto_resolve(root_o, "o_transportationByPlane");
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

    corto_release(t);

/* $end */
}

corto_void _test_Enum_tc_t_Color(test_Enum this) {
/* $begin(test/Enum/tc_t_Color) */

    corto_object t = corto_resolve(root_o, "Color");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_enum_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_lookup(t, "Red");
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
        test_assert((*c) == 0);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "Green");
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
        corto_object o = corto_lookup(t, "Blue");
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

    corto_release(t);

/* $end */
}

corto_void _test_Enum_tc_t_Temperature(test_Enum this) {
/* $begin(test/Enum/tc_t_Temperature) */

    corto_object t = corto_resolve(root_o, "Temperature");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_enum_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_lookup(t, "Cold");
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
        test_assert((*c) == 40);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "Moderate");
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
        test_assert((*c) == 65);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "Hot");
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
        test_assert((*c) == 90);
        corto_release(o);
    }

    corto_release(t);

/* $end */
}

corto_void _test_Enum_tc_t_Transportation(test_Enum this) {
/* $begin(test/Enum/tc_t_Transportation) */

    corto_object t = corto_resolve(root_o, "Transportation");
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_enum_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));

    {
        corto_object o = corto_lookup(t, "ByCar");
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
        test_assert((*c) == 0);
        corto_release(o);
    }

    {
        corto_object o = corto_lookup(t, "ByBus");
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
        corto_object o = corto_lookup(t, "ByPlane");
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

    corto_release(t);

/* $end */
}
