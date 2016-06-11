/* _meta.cpp
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#include <test.h>
/* Variable definitions */
corto_package test_o;
corto_class test_Point_o;
corto_member test_Point_x_o;
corto_member test_Point_y_o;
test_Suite test_TestCortoLanguage_o;
corto_member test_TestCortoLanguage_parser_o;
corto_method test_TestCortoLanguage_setup_o;
corto_method test_TestCortoLanguage_teardown_o;
test_Case test_TestCortoLanguage_test_addExpr_o;
test_Case test_TestCortoLanguage_test_assignmentExpr_o;
test_Case test_TestCortoLanguage_test_atom_o;
test_Case test_TestCortoLanguage_test_badToken_o;
test_Case test_TestCortoLanguage_test_commaExpr_o;
test_Case test_TestCortoLanguage_test_declaration1_o;
test_Case test_TestCortoLanguage_test_declaration2_o;
test_Case test_TestCortoLanguage_test_declaration3_o;
test_Case test_TestCortoLanguage_test_declaration4_o;
test_Case test_TestCortoLanguage_test_elementAccess_o;
test_Case test_TestCortoLanguage_test_functionCall_o;
test_Case test_TestCortoLanguage_test_functionCall2_o;
test_Case test_TestCortoLanguage_test_functionCall3_o;
test_Case test_TestCortoLanguage_test_functionCall4_o;
test_Case test_TestCortoLanguage_test_functionDeclaration1_o;
test_Case test_TestCortoLanguage_test_functionDeclaration2_o;
test_Case test_TestCortoLanguage_test_functionDeclaration3_o;
test_Case test_TestCortoLanguage_test_functionDeclaration4_o;
test_Case test_TestCortoLanguage_test_functionDeclaration5_o;
test_Case test_TestCortoLanguage_test_functionDeclaration6_o;
test_Case test_TestCortoLanguage_test_functionDeclaration7_o;
test_Case test_TestCortoLanguage_test_ifStatement1_o;
test_Case test_TestCortoLanguage_test_ifStatement2_o;
test_Case test_TestCortoLanguage_test_ifStatement3_o;
test_Case test_TestCortoLanguage_test_ifStatement4_o;
test_Case test_TestCortoLanguage_test_ifStatement5_o;
test_Case test_TestCortoLanguage_test_ifStatement6_o;
test_Case test_TestCortoLanguage_test_ifStatement7_o;
test_Case test_TestCortoLanguage_test_logicAndExpr_o;
test_Case test_TestCortoLanguage_test_logicOrExpr_o;
test_Case test_TestCortoLanguage_test_multExpr_o;
test_Case test_TestCortoLanguage_test_observer1_o;
test_Case test_TestCortoLanguage_test_observer2_o;
test_Case test_TestCortoLanguage_test_observer3_o;
test_Case test_TestCortoLanguage_test_observer4_o;
test_Case test_TestCortoLanguage_test_observer5_o;
test_Case test_TestCortoLanguage_test_scope1_o;
test_Case test_TestCortoLanguage_test_scope2_o;
test_Case test_TestCortoLanguage_test_scope3_o;
test_Case test_TestCortoLanguage_test_scope4_o;
test_Case test_TestCortoLanguage_test_scope5_o;
test_Case test_TestCortoLanguage_test_unary_o;
test_Case test_TestCortoLanguage_testWhileStatement1_o;
test_Case test_TestCortoLanguage_testWhileStatement2_o;
test_Case test_TestCortoLanguage_testWhileStatement3_o;
test_Case test_TestCortoLanguage_testWhileStatement4_o;
test_Suite test_TestDeclarationVisitor_o;
test_Case test_TestDeclarationVisitor_testInt8Declaration_o;
test_Case test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o;
test_Case test_TestDeclarationVisitor_testMultipleInt8Declaration_o;
test_Case test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o;
test_Suite test_TestPrintVisitor_o;
test_Case test_TestPrintVisitor_test_addExpression1_o;
test_Case test_TestPrintVisitor_test_bitAndExpression1_o;
test_Case test_TestPrintVisitor_test_bitOrExpression1_o;
test_Case test_TestPrintVisitor_test_bitOrExpression2_o;
test_Case test_TestPrintVisitor_test_callExpression1_o;
test_Case test_TestPrintVisitor_test_callExpression2_o;
test_Case test_TestPrintVisitor_test_comparisonExpression1_o;
test_Case test_TestPrintVisitor_test_comparisonExpression2_o;
test_Case test_TestPrintVisitor_test_ConditionalExpression1_o;
test_Case test_TestPrintVisitor_test_ConditionalExpression2_o;
test_Case test_TestPrintVisitor_test_elementExpression1_o;
test_Case test_TestPrintVisitor_test_elementExpression2_o;
test_Case test_TestPrintVisitor_test_equalityExpression1_o;
test_Case test_TestPrintVisitor_test_equalityExpression2_o;
test_Case test_TestPrintVisitor_test_functionDeclaration1_o;
test_Case test_TestPrintVisitor_test_functionDeclaration2_o;
test_Case test_TestPrintVisitor_test_functionDeclaration3_o;
test_Case test_TestPrintVisitor_test_logicAndExpression1_o;
test_Case test_TestPrintVisitor_test_logicAndExpression2_o;
test_Case test_TestPrintVisitor_test_logicOrExpression1_o;
test_Case test_TestPrintVisitor_test_logicOrExpression2_o;
test_Case test_TestPrintVisitor_test_memberExpression1_o;
test_Case test_TestPrintVisitor_test_memberExpression2_o;
test_Case test_TestPrintVisitor_test_multExpression1_o;
test_Case test_TestPrintVisitor_test_objectDeclaration1_o;
test_Case test_TestPrintVisitor_test_objectDeclaration10_o;
test_Case test_TestPrintVisitor_test_objectDeclaration11_o;
test_Case test_TestPrintVisitor_test_objectDeclaration2_o;
test_Case test_TestPrintVisitor_test_objectDeclaration3_o;
test_Case test_TestPrintVisitor_test_objectDeclaration4_o;
test_Case test_TestPrintVisitor_test_objectDeclaration5_o;
test_Case test_TestPrintVisitor_test_objectDeclaration6_o;
test_Case test_TestPrintVisitor_test_objectDeclaration7_o;
test_Case test_TestPrintVisitor_test_objectDeclaration8_o;
test_Case test_TestPrintVisitor_test_objectDeclaration9_o;
test_Case test_TestPrintVisitor_test_shiftExpression1_o;
test_Case test_TestPrintVisitor_test_unaryExpression1_o;
test_Case test_TestPrintVisitor_test_unaryExpression2_o;
test_Case test_TestPrintVisitor_test_visitorAssignment_o;
test_Case test_TestPrintVisitor_test_visitorAtom_o;
test_Case test_TestPrintVisitor_test_visitorCommaExpression1_o;

/* Load objects in object store. */
int test_load(void) {
    corto_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    test_o = corto_package(corto_declareChild(root_o, "test", corto_package_o));
    if (!test_o) {
        corto_error("test_load: failed to declare 'test_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_o, CORTO_DEFINED)) {
        test_o->url = NULL;
        if (corto_define(test_o)) {
            corto_error("test_load: failed to define 'test_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_Point_o = corto_class(corto_declareChild(test_o, "Point", corto_class_o));
    if (!test_Point_o) {
        corto_error("test_load: failed to declare 'test_Point_o' (%s)", corto_lasterr());
        goto error;
    }

    test_Point_x_o = corto_member(corto_declareChild(test_Point_o, "x", corto_member_o));
    if (!test_Point_x_o) {
        corto_error("test_load: failed to declare 'test_Point_x_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_Point_x_o, CORTO_DEFINED)) {
        test_Point_x_o->type = corto_type(corto_resolve(NULL, "int32"));
        test_Point_x_o->modifiers = 0x0;
        test_Point_x_o->state = 0x6;
        test_Point_x_o->weak = FALSE;
        test_Point_x_o->id = 0;
        if (corto_define(test_Point_x_o)) {
            corto_error("test_load: failed to define 'test_Point_x_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_Point_y_o = corto_member(corto_declareChild(test_Point_o, "y", corto_member_o));
    if (!test_Point_y_o) {
        corto_error("test_load: failed to declare 'test_Point_y_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_Point_y_o, CORTO_DEFINED)) {
        test_Point_y_o->type = corto_type(corto_resolve(NULL, "int32"));
        test_Point_y_o->modifiers = 0x0;
        test_Point_y_o->state = 0x6;
        test_Point_y_o->weak = FALSE;
        test_Point_y_o->id = 1;
        if (corto_define(test_Point_y_o)) {
            corto_error("test_load: failed to define 'test_Point_y_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(test_Point_o, CORTO_DEFINED)) {
        ((corto_type)test_Point_o)->kind = CORTO_COMPOSITE;
        ((corto_type)test_Point_o)->reference = TRUE;
        ((corto_type)test_Point_o)->parentType = NULL;
        ((corto_type)test_Point_o)->parentState = 0x6;
        ((corto_type)test_Point_o)->defaultType = NULL;
        ((corto_type)test_Point_o)->defaultProcedureType = NULL;
        ((corto_interface)test_Point_o)->base = NULL;
        ((corto_struct)test_Point_o)->baseAccess = 0x0;
        test_Point_o->implements.length = 0;
        test_Point_o->implements.buffer = NULL;
        if (corto_define(test_Point_o)) {
            corto_error("test_load: failed to define 'test_Point_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Point_o)->size != sizeof(struct test_Point_s)) {
        corto_error("test_load: calculated size '%d' of type 'test_Point_o' doesn't match C-type size '%d'", corto_type(test_Point_o)->size, sizeof(struct test_Point_s));
    }

    test_TestCortoLanguage_o = test_Suite(corto_declareChild(test_o, "TestCortoLanguage", test_Suite_o));
    if (!test_TestCortoLanguage_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_o' (%s)", corto_lasterr());
        goto error;
    }

    test_TestCortoLanguage_parser_o = corto_member(corto_declareChild(test_TestCortoLanguage_o, "parser", corto_member_o));
    if (!test_TestCortoLanguage_parser_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_parser_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_parser_o, CORTO_DEFINED)) {
        test_TestCortoLanguage_parser_o->type = corto_type(corto_resolve(NULL, "/corto/parser/SimpleParser"));
        test_TestCortoLanguage_parser_o->modifiers = 0x0;
        test_TestCortoLanguage_parser_o->state = 0x6;
        test_TestCortoLanguage_parser_o->weak = FALSE;
        test_TestCortoLanguage_parser_o->id = 0;
        if (corto_define(test_TestCortoLanguage_parser_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_parser_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_setup_o = corto_method(corto_declareChild(test_TestCortoLanguage_o, "setup()", corto_method_o));
    if (!test_TestCortoLanguage_setup_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_setup_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_setup_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_setup_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_setup_o)->returnsReference = FALSE;
        test_TestCortoLanguage_setup_o->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_setup_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_setup(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_setup_o)->fptr = (corto_word)_test_TestCortoLanguage_setup;
        if (corto_define(test_TestCortoLanguage_setup_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_setup_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_teardown_o = corto_method(corto_declareChild(test_TestCortoLanguage_o, "teardown()", corto_method_o));
    if (!test_TestCortoLanguage_teardown_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_teardown_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_teardown_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_teardown_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_teardown_o)->returnsReference = FALSE;
        test_TestCortoLanguage_teardown_o->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_teardown_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_teardown(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_teardown_o)->fptr = (corto_word)_test_TestCortoLanguage_teardown;
        if (corto_define(test_TestCortoLanguage_teardown_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_teardown_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(test_TestCortoLanguage_o, CORTO_DEFINED)) {
        ((corto_type)test_TestCortoLanguage_o)->kind = CORTO_COMPOSITE;
        ((corto_type)test_TestCortoLanguage_o)->reference = TRUE;
        ((corto_type)test_TestCortoLanguage_o)->parentType = NULL;
        ((corto_type)test_TestCortoLanguage_o)->parentState = 0x6;
        ((corto_type)test_TestCortoLanguage_o)->defaultType = NULL;
        ((corto_type)test_TestCortoLanguage_o)->defaultProcedureType = NULL;
        ((corto_interface)test_TestCortoLanguage_o)->base = corto_interface(corto_resolve(NULL, "/corto/test/SuiteData"));
        ((corto_struct)test_TestCortoLanguage_o)->baseAccess = 0x0;
        ((corto_class)test_TestCortoLanguage_o)->implements.length = 0;
        ((corto_class)test_TestCortoLanguage_o)->implements.buffer = NULL;
        if (corto_define(test_TestCortoLanguage_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_TestCortoLanguage_o)->size != sizeof(struct test_TestCortoLanguage_s)) {
        corto_error("test_load: calculated size '%d' of type 'test_TestCortoLanguage_o' doesn't match C-type size '%d'", corto_type(test_TestCortoLanguage_o)->size, sizeof(struct test_TestCortoLanguage_s));
    }

    test_TestCortoLanguage_test_addExpr_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_addExpr()", test_Case_o));
    if (!test_TestCortoLanguage_test_addExpr_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_addExpr_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_addExpr_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_addExpr_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_addExpr_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_addExpr_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_addExpr_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_addExpr(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_addExpr_o)->fptr = (corto_word)_test_TestCortoLanguage_test_addExpr;
        if (corto_define(test_TestCortoLanguage_test_addExpr_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_addExpr_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_assignmentExpr_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_assignmentExpr()", test_Case_o));
    if (!test_TestCortoLanguage_test_assignmentExpr_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_assignmentExpr_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_assignmentExpr_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_assignmentExpr_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_assignmentExpr_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_assignmentExpr_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_assignmentExpr_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_assignmentExpr(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_assignmentExpr_o)->fptr = (corto_word)_test_TestCortoLanguage_test_assignmentExpr;
        if (corto_define(test_TestCortoLanguage_test_assignmentExpr_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_assignmentExpr_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_atom_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_atom()", test_Case_o));
    if (!test_TestCortoLanguage_test_atom_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_atom_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_atom_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_atom_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_atom_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_atom_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_atom_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_atom(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_atom_o)->fptr = (corto_word)_test_TestCortoLanguage_test_atom;
        if (corto_define(test_TestCortoLanguage_test_atom_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_atom_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_badToken_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_badToken()", test_Case_o));
    if (!test_TestCortoLanguage_test_badToken_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_badToken_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_badToken_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_badToken_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_badToken_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_badToken_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_badToken_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_badToken(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_badToken_o)->fptr = (corto_word)_test_TestCortoLanguage_test_badToken;
        if (corto_define(test_TestCortoLanguage_test_badToken_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_badToken_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_commaExpr_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_commaExpr()", test_Case_o));
    if (!test_TestCortoLanguage_test_commaExpr_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_commaExpr_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_commaExpr_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_commaExpr_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_commaExpr_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_commaExpr_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_commaExpr_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_commaExpr(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_commaExpr_o)->fptr = (corto_word)_test_TestCortoLanguage_test_commaExpr;
        if (corto_define(test_TestCortoLanguage_test_commaExpr_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_commaExpr_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_declaration1_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_declaration1()", test_Case_o));
    if (!test_TestCortoLanguage_test_declaration1_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_declaration1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_declaration1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_declaration1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_declaration1_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_declaration1_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_declaration1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_declaration1(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_declaration1_o)->fptr = (corto_word)_test_TestCortoLanguage_test_declaration1;
        if (corto_define(test_TestCortoLanguage_test_declaration1_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_declaration1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_declaration2_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_declaration2()", test_Case_o));
    if (!test_TestCortoLanguage_test_declaration2_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_declaration2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_declaration2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_declaration2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_declaration2_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_declaration2_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_declaration2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_declaration2(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_declaration2_o)->fptr = (corto_word)_test_TestCortoLanguage_test_declaration2;
        if (corto_define(test_TestCortoLanguage_test_declaration2_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_declaration2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_declaration3_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_declaration3()", test_Case_o));
    if (!test_TestCortoLanguage_test_declaration3_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_declaration3_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_declaration3_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_declaration3_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_declaration3_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_declaration3_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_declaration3_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_declaration3(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_declaration3_o)->fptr = (corto_word)_test_TestCortoLanguage_test_declaration3;
        if (corto_define(test_TestCortoLanguage_test_declaration3_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_declaration3_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_declaration4_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_declaration4()", test_Case_o));
    if (!test_TestCortoLanguage_test_declaration4_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_declaration4_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_declaration4_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_declaration4_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_declaration4_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_declaration4_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_declaration4_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_declaration4(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_declaration4_o)->fptr = (corto_word)_test_TestCortoLanguage_test_declaration4;
        if (corto_define(test_TestCortoLanguage_test_declaration4_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_declaration4_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_elementAccess_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_elementAccess()", test_Case_o));
    if (!test_TestCortoLanguage_test_elementAccess_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_elementAccess_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_elementAccess_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_elementAccess_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_elementAccess_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_elementAccess_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_elementAccess_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_elementAccess(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_elementAccess_o)->fptr = (corto_word)_test_TestCortoLanguage_test_elementAccess;
        if (corto_define(test_TestCortoLanguage_test_elementAccess_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_elementAccess_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionCall_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionCall()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionCall_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionCall_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionCall_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionCall_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionCall_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionCall_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionCall_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionCall(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionCall_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionCall;
        if (corto_define(test_TestCortoLanguage_test_functionCall_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionCall_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionCall2_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionCall2()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionCall2_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionCall2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionCall2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionCall2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionCall2_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionCall2_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionCall2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionCall2(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionCall2_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionCall2;
        if (corto_define(test_TestCortoLanguage_test_functionCall2_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionCall2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionCall3_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionCall3()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionCall3_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionCall3_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionCall3_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionCall3_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionCall3_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionCall3_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionCall3_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionCall3(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionCall3_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionCall3;
        if (corto_define(test_TestCortoLanguage_test_functionCall3_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionCall3_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionCall4_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionCall4()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionCall4_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionCall4_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionCall4_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionCall4_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionCall4_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionCall4_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionCall4_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionCall4(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionCall4_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionCall4;
        if (corto_define(test_TestCortoLanguage_test_functionCall4_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionCall4_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionDeclaration1_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionDeclaration1()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionDeclaration1_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionDeclaration1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionDeclaration1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration1_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionDeclaration1_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionDeclaration1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionDeclaration1(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionDeclaration1_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionDeclaration1;
        if (corto_define(test_TestCortoLanguage_test_functionDeclaration1_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionDeclaration1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionDeclaration2_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionDeclaration2()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionDeclaration2_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionDeclaration2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionDeclaration2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration2_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionDeclaration2_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionDeclaration2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionDeclaration2(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionDeclaration2_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionDeclaration2;
        if (corto_define(test_TestCortoLanguage_test_functionDeclaration2_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionDeclaration2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionDeclaration3_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionDeclaration3()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionDeclaration3_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionDeclaration3_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionDeclaration3_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration3_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration3_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionDeclaration3_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionDeclaration3_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionDeclaration3(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionDeclaration3_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionDeclaration3;
        if (corto_define(test_TestCortoLanguage_test_functionDeclaration3_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionDeclaration3_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionDeclaration4_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionDeclaration4()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionDeclaration4_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionDeclaration4_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionDeclaration4_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration4_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration4_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionDeclaration4_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionDeclaration4_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionDeclaration4(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionDeclaration4_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionDeclaration4;
        if (corto_define(test_TestCortoLanguage_test_functionDeclaration4_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionDeclaration4_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionDeclaration5_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionDeclaration5()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionDeclaration5_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionDeclaration5_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionDeclaration5_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration5_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration5_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionDeclaration5_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionDeclaration5_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionDeclaration5(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionDeclaration5_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionDeclaration5;
        if (corto_define(test_TestCortoLanguage_test_functionDeclaration5_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionDeclaration5_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionDeclaration6_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionDeclaration6()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionDeclaration6_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionDeclaration6_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionDeclaration6_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration6_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration6_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionDeclaration6_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionDeclaration6_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionDeclaration6(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionDeclaration6_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionDeclaration6;
        if (corto_define(test_TestCortoLanguage_test_functionDeclaration6_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionDeclaration6_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_functionDeclaration7_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_functionDeclaration7()", test_Case_o));
    if (!test_TestCortoLanguage_test_functionDeclaration7_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_functionDeclaration7_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_functionDeclaration7_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration7_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_functionDeclaration7_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_functionDeclaration7_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_functionDeclaration7_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_functionDeclaration7(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_functionDeclaration7_o)->fptr = (corto_word)_test_TestCortoLanguage_test_functionDeclaration7;
        if (corto_define(test_TestCortoLanguage_test_functionDeclaration7_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionDeclaration7_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_ifStatement1_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_ifStatement1()", test_Case_o));
    if (!test_TestCortoLanguage_test_ifStatement1_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_ifStatement1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_ifStatement1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_ifStatement1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_ifStatement1_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_ifStatement1_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_ifStatement1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_ifStatement1(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_ifStatement1_o)->fptr = (corto_word)_test_TestCortoLanguage_test_ifStatement1;
        if (corto_define(test_TestCortoLanguage_test_ifStatement1_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_ifStatement1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_ifStatement2_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_ifStatement2()", test_Case_o));
    if (!test_TestCortoLanguage_test_ifStatement2_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_ifStatement2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_ifStatement2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_ifStatement2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_ifStatement2_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_ifStatement2_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_ifStatement2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_ifStatement2(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_ifStatement2_o)->fptr = (corto_word)_test_TestCortoLanguage_test_ifStatement2;
        if (corto_define(test_TestCortoLanguage_test_ifStatement2_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_ifStatement2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_ifStatement3_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_ifStatement3()", test_Case_o));
    if (!test_TestCortoLanguage_test_ifStatement3_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_ifStatement3_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_ifStatement3_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_ifStatement3_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_ifStatement3_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_ifStatement3_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_ifStatement3_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_ifStatement3(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_ifStatement3_o)->fptr = (corto_word)_test_TestCortoLanguage_test_ifStatement3;
        if (corto_define(test_TestCortoLanguage_test_ifStatement3_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_ifStatement3_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_ifStatement4_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_ifStatement4()", test_Case_o));
    if (!test_TestCortoLanguage_test_ifStatement4_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_ifStatement4_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_ifStatement4_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_ifStatement4_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_ifStatement4_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_ifStatement4_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_ifStatement4_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_ifStatement4(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_ifStatement4_o)->fptr = (corto_word)_test_TestCortoLanguage_test_ifStatement4;
        if (corto_define(test_TestCortoLanguage_test_ifStatement4_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_ifStatement4_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_ifStatement5_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_ifStatement5()", test_Case_o));
    if (!test_TestCortoLanguage_test_ifStatement5_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_ifStatement5_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_ifStatement5_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_ifStatement5_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_ifStatement5_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_ifStatement5_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_ifStatement5_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_ifStatement5(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_ifStatement5_o)->fptr = (corto_word)_test_TestCortoLanguage_test_ifStatement5;
        if (corto_define(test_TestCortoLanguage_test_ifStatement5_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_ifStatement5_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_ifStatement6_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_ifStatement6()", test_Case_o));
    if (!test_TestCortoLanguage_test_ifStatement6_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_ifStatement6_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_ifStatement6_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_ifStatement6_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_ifStatement6_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_ifStatement6_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_ifStatement6_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_ifStatement6(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_ifStatement6_o)->fptr = (corto_word)_test_TestCortoLanguage_test_ifStatement6;
        if (corto_define(test_TestCortoLanguage_test_ifStatement6_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_ifStatement6_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_ifStatement7_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_ifStatement7()", test_Case_o));
    if (!test_TestCortoLanguage_test_ifStatement7_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_ifStatement7_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_ifStatement7_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_ifStatement7_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_ifStatement7_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_ifStatement7_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_ifStatement7_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_ifStatement7(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_ifStatement7_o)->fptr = (corto_word)_test_TestCortoLanguage_test_ifStatement7;
        if (corto_define(test_TestCortoLanguage_test_ifStatement7_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_ifStatement7_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_logicAndExpr_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_logicAndExpr()", test_Case_o));
    if (!test_TestCortoLanguage_test_logicAndExpr_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_logicAndExpr_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_logicAndExpr_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_logicAndExpr_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_logicAndExpr_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_logicAndExpr_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_logicAndExpr_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_logicAndExpr(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_logicAndExpr_o)->fptr = (corto_word)_test_TestCortoLanguage_test_logicAndExpr;
        if (corto_define(test_TestCortoLanguage_test_logicAndExpr_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_logicAndExpr_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_logicOrExpr_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_logicOrExpr()", test_Case_o));
    if (!test_TestCortoLanguage_test_logicOrExpr_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_logicOrExpr_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_logicOrExpr_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_logicOrExpr_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_logicOrExpr_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_logicOrExpr_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_logicOrExpr_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_logicOrExpr(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_logicOrExpr_o)->fptr = (corto_word)_test_TestCortoLanguage_test_logicOrExpr;
        if (corto_define(test_TestCortoLanguage_test_logicOrExpr_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_logicOrExpr_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_multExpr_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_multExpr()", test_Case_o));
    if (!test_TestCortoLanguage_test_multExpr_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_multExpr_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_multExpr_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_multExpr_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_multExpr_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_multExpr_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_multExpr_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_multExpr(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_multExpr_o)->fptr = (corto_word)_test_TestCortoLanguage_test_multExpr;
        if (corto_define(test_TestCortoLanguage_test_multExpr_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_multExpr_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_observer1_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_observer1()", test_Case_o));
    if (!test_TestCortoLanguage_test_observer1_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_observer1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_observer1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_observer1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_observer1_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_observer1_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_observer1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_observer1(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_observer1_o)->fptr = (corto_word)_test_TestCortoLanguage_test_observer1;
        if (corto_define(test_TestCortoLanguage_test_observer1_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_observer1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_observer2_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_observer2()", test_Case_o));
    if (!test_TestCortoLanguage_test_observer2_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_observer2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_observer2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_observer2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_observer2_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_observer2_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_observer2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_observer2(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_observer2_o)->fptr = (corto_word)_test_TestCortoLanguage_test_observer2;
        if (corto_define(test_TestCortoLanguage_test_observer2_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_observer2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_observer3_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_observer3()", test_Case_o));
    if (!test_TestCortoLanguage_test_observer3_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_observer3_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_observer3_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_observer3_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_observer3_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_observer3_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_observer3_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_observer3(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_observer3_o)->fptr = (corto_word)_test_TestCortoLanguage_test_observer3;
        if (corto_define(test_TestCortoLanguage_test_observer3_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_observer3_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_observer4_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_observer4()", test_Case_o));
    if (!test_TestCortoLanguage_test_observer4_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_observer4_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_observer4_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_observer4_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_observer4_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_observer4_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_observer4_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_observer4(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_observer4_o)->fptr = (corto_word)_test_TestCortoLanguage_test_observer4;
        if (corto_define(test_TestCortoLanguage_test_observer4_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_observer4_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_observer5_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_observer5()", test_Case_o));
    if (!test_TestCortoLanguage_test_observer5_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_observer5_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_observer5_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_observer5_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_observer5_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_observer5_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_observer5_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_observer5(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_observer5_o)->fptr = (corto_word)_test_TestCortoLanguage_test_observer5;
        if (corto_define(test_TestCortoLanguage_test_observer5_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_observer5_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_scope1_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_scope1()", test_Case_o));
    if (!test_TestCortoLanguage_test_scope1_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_scope1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_scope1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_scope1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_scope1_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_scope1_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_scope1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_scope1(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_scope1_o)->fptr = (corto_word)_test_TestCortoLanguage_test_scope1;
        if (corto_define(test_TestCortoLanguage_test_scope1_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_scope1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_scope2_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_scope2()", test_Case_o));
    if (!test_TestCortoLanguage_test_scope2_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_scope2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_scope2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_scope2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_scope2_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_scope2_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_scope2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_scope2(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_scope2_o)->fptr = (corto_word)_test_TestCortoLanguage_test_scope2;
        if (corto_define(test_TestCortoLanguage_test_scope2_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_scope2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_scope3_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_scope3()", test_Case_o));
    if (!test_TestCortoLanguage_test_scope3_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_scope3_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_scope3_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_scope3_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_scope3_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_scope3_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_scope3_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_scope3(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_scope3_o)->fptr = (corto_word)_test_TestCortoLanguage_test_scope3;
        if (corto_define(test_TestCortoLanguage_test_scope3_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_scope3_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_scope4_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_scope4()", test_Case_o));
    if (!test_TestCortoLanguage_test_scope4_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_scope4_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_scope4_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_scope4_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_scope4_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_scope4_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_scope4_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_scope4(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_scope4_o)->fptr = (corto_word)_test_TestCortoLanguage_test_scope4;
        if (corto_define(test_TestCortoLanguage_test_scope4_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_scope4_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_scope5_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_scope5()", test_Case_o));
    if (!test_TestCortoLanguage_test_scope5_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_scope5_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_scope5_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_scope5_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_scope5_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_scope5_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_scope5_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_scope5(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_scope5_o)->fptr = (corto_word)_test_TestCortoLanguage_test_scope5;
        if (corto_define(test_TestCortoLanguage_test_scope5_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_scope5_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_unary_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_unary()", test_Case_o));
    if (!test_TestCortoLanguage_test_unary_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_unary_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_unary_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_unary_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_unary_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_unary_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_unary_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_test_unary(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_test_unary_o)->fptr = (corto_word)_test_TestCortoLanguage_test_unary;
        if (corto_define(test_TestCortoLanguage_test_unary_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_unary_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_testWhileStatement1_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "testWhileStatement1()", test_Case_o));
    if (!test_TestCortoLanguage_testWhileStatement1_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_testWhileStatement1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_testWhileStatement1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_testWhileStatement1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_testWhileStatement1_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_testWhileStatement1_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_testWhileStatement1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_testWhileStatement1(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_testWhileStatement1_o)->fptr = (corto_word)_test_TestCortoLanguage_testWhileStatement1;
        if (corto_define(test_TestCortoLanguage_testWhileStatement1_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_testWhileStatement1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_testWhileStatement2_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "testWhileStatement2()", test_Case_o));
    if (!test_TestCortoLanguage_testWhileStatement2_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_testWhileStatement2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_testWhileStatement2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_testWhileStatement2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_testWhileStatement2_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_testWhileStatement2_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_testWhileStatement2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_testWhileStatement2(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_testWhileStatement2_o)->fptr = (corto_word)_test_TestCortoLanguage_testWhileStatement2;
        if (corto_define(test_TestCortoLanguage_testWhileStatement2_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_testWhileStatement2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_testWhileStatement3_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "testWhileStatement3()", test_Case_o));
    if (!test_TestCortoLanguage_testWhileStatement3_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_testWhileStatement3_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_testWhileStatement3_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_testWhileStatement3_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_testWhileStatement3_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_testWhileStatement3_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_testWhileStatement3_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_testWhileStatement3(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_testWhileStatement3_o)->fptr = (corto_word)_test_TestCortoLanguage_testWhileStatement3;
        if (corto_define(test_TestCortoLanguage_testWhileStatement3_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_testWhileStatement3_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_testWhileStatement4_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "testWhileStatement4()", test_Case_o));
    if (!test_TestCortoLanguage_testWhileStatement4_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_testWhileStatement4_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_testWhileStatement4_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_testWhileStatement4_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_testWhileStatement4_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_testWhileStatement4_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_testWhileStatement4_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestCortoLanguage_testWhileStatement4(
    test_TestCortoLanguage _this);
        corto_function(test_TestCortoLanguage_testWhileStatement4_o)->fptr = (corto_word)_test_TestCortoLanguage_testWhileStatement4;
        if (corto_define(test_TestCortoLanguage_testWhileStatement4_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_testWhileStatement4_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestDeclarationVisitor_o = test_Suite(corto_declareChild(test_o, "TestDeclarationVisitor", test_Suite_o));
    if (!test_TestDeclarationVisitor_o) {
        corto_error("test_load: failed to declare 'test_TestDeclarationVisitor_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestDeclarationVisitor_o, CORTO_DEFINED)) {
        ((corto_type)test_TestDeclarationVisitor_o)->kind = CORTO_COMPOSITE;
        ((corto_type)test_TestDeclarationVisitor_o)->reference = TRUE;
        ((corto_type)test_TestDeclarationVisitor_o)->parentType = NULL;
        ((corto_type)test_TestDeclarationVisitor_o)->parentState = 0x6;
        ((corto_type)test_TestDeclarationVisitor_o)->defaultType = NULL;
        ((corto_type)test_TestDeclarationVisitor_o)->defaultProcedureType = NULL;
        ((corto_interface)test_TestDeclarationVisitor_o)->base = corto_interface(corto_resolve(NULL, "/corto/test/SuiteData"));
        ((corto_struct)test_TestDeclarationVisitor_o)->baseAccess = 0x0;
        ((corto_class)test_TestDeclarationVisitor_o)->implements.length = 0;
        ((corto_class)test_TestDeclarationVisitor_o)->implements.buffer = NULL;
        if (corto_define(test_TestDeclarationVisitor_o)) {
            corto_error("test_load: failed to define 'test_TestDeclarationVisitor_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_TestDeclarationVisitor_o)->size != sizeof(struct test_TestDeclarationVisitor_s)) {
        corto_error("test_load: calculated size '%d' of type 'test_TestDeclarationVisitor_o' doesn't match C-type size '%d'", corto_type(test_TestDeclarationVisitor_o)->size, sizeof(struct test_TestDeclarationVisitor_s));
    }

    test_TestDeclarationVisitor_testInt8Declaration_o = test_Case(corto_declareChild(test_TestDeclarationVisitor_o, "testInt8Declaration()", test_Case_o));
    if (!test_TestDeclarationVisitor_testInt8Declaration_o) {
        corto_error("test_load: failed to declare 'test_TestDeclarationVisitor_testInt8Declaration_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestDeclarationVisitor_testInt8Declaration_o, CORTO_DEFINED)) {
        ((corto_function)test_TestDeclarationVisitor_testInt8Declaration_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestDeclarationVisitor_testInt8Declaration_o)->returnsReference = FALSE;
        ((corto_method)test_TestDeclarationVisitor_testInt8Declaration_o)->_virtual = FALSE;
        
        corto_function(test_TestDeclarationVisitor_testInt8Declaration_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestDeclarationVisitor_testInt8Declaration(
    test_TestDeclarationVisitor _this);
        corto_function(test_TestDeclarationVisitor_testInt8Declaration_o)->fptr = (corto_word)_test_TestDeclarationVisitor_testInt8Declaration;
        if (corto_define(test_TestDeclarationVisitor_testInt8Declaration_o)) {
            corto_error("test_load: failed to define 'test_TestDeclarationVisitor_testInt8Declaration_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o = test_Case(corto_declareChild(test_TestDeclarationVisitor_o, "testInt8DeclarationAndDefinition()", test_Case_o));
    if (!test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o) {
        corto_error("test_load: failed to declare 'test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o, CORTO_DEFINED)) {
        ((corto_function)test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o)->returnsReference = FALSE;
        ((corto_method)test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o)->_virtual = FALSE;
        
        corto_function(test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestDeclarationVisitor_testInt8DeclarationAndDefinition(
    test_TestDeclarationVisitor _this);
        corto_function(test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o)->fptr = (corto_word)_test_TestDeclarationVisitor_testInt8DeclarationAndDefinition;
        if (corto_define(test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o)) {
            corto_error("test_load: failed to define 'test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestDeclarationVisitor_testMultipleInt8Declaration_o = test_Case(corto_declareChild(test_TestDeclarationVisitor_o, "testMultipleInt8Declaration()", test_Case_o));
    if (!test_TestDeclarationVisitor_testMultipleInt8Declaration_o) {
        corto_error("test_load: failed to declare 'test_TestDeclarationVisitor_testMultipleInt8Declaration_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestDeclarationVisitor_testMultipleInt8Declaration_o, CORTO_DEFINED)) {
        ((corto_function)test_TestDeclarationVisitor_testMultipleInt8Declaration_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestDeclarationVisitor_testMultipleInt8Declaration_o)->returnsReference = FALSE;
        ((corto_method)test_TestDeclarationVisitor_testMultipleInt8Declaration_o)->_virtual = FALSE;
        
        corto_function(test_TestDeclarationVisitor_testMultipleInt8Declaration_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestDeclarationVisitor_testMultipleInt8Declaration(
    test_TestDeclarationVisitor _this);
        corto_function(test_TestDeclarationVisitor_testMultipleInt8Declaration_o)->fptr = (corto_word)_test_TestDeclarationVisitor_testMultipleInt8Declaration;
        if (corto_define(test_TestDeclarationVisitor_testMultipleInt8Declaration_o)) {
            corto_error("test_load: failed to define 'test_TestDeclarationVisitor_testMultipleInt8Declaration_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o = test_Case(corto_declareChild(test_TestDeclarationVisitor_o, "testMultipleInt8DeclarationAndDefinition()", test_Case_o));
    if (!test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o) {
        corto_error("test_load: failed to declare 'test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o, CORTO_DEFINED)) {
        ((corto_function)test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o)->returnsReference = FALSE;
        ((corto_method)test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o)->_virtual = FALSE;
        
        corto_function(test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition(
    test_TestDeclarationVisitor _this);
        corto_function(test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o)->fptr = (corto_word)_test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition;
        if (corto_define(test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o)) {
            corto_error("test_load: failed to define 'test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_o = test_Suite(corto_declareChild(test_o, "TestPrintVisitor", test_Suite_o));
    if (!test_TestPrintVisitor_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_o, CORTO_DEFINED)) {
        ((corto_type)test_TestPrintVisitor_o)->kind = CORTO_COMPOSITE;
        ((corto_type)test_TestPrintVisitor_o)->reference = TRUE;
        ((corto_type)test_TestPrintVisitor_o)->parentType = NULL;
        ((corto_type)test_TestPrintVisitor_o)->parentState = 0x6;
        ((corto_type)test_TestPrintVisitor_o)->defaultType = NULL;
        ((corto_type)test_TestPrintVisitor_o)->defaultProcedureType = NULL;
        ((corto_interface)test_TestPrintVisitor_o)->base = corto_interface(corto_resolve(NULL, "/corto/test/SuiteData"));
        ((corto_struct)test_TestPrintVisitor_o)->baseAccess = 0x0;
        ((corto_class)test_TestPrintVisitor_o)->implements.length = 0;
        ((corto_class)test_TestPrintVisitor_o)->implements.buffer = NULL;
        if (corto_define(test_TestPrintVisitor_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_TestPrintVisitor_o)->size != sizeof(struct test_TestPrintVisitor_s)) {
        corto_error("test_load: calculated size '%d' of type 'test_TestPrintVisitor_o' doesn't match C-type size '%d'", corto_type(test_TestPrintVisitor_o)->size, sizeof(struct test_TestPrintVisitor_s));
    }

    test_TestPrintVisitor_test_addExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_addExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_addExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_addExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_addExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_addExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_addExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_addExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_addExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_addExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_addExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_addExpression1;
        if (corto_define(test_TestPrintVisitor_test_addExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_addExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_bitAndExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_bitAndExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_bitAndExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_bitAndExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_bitAndExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_bitAndExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_bitAndExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_bitAndExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_bitAndExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_bitAndExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_bitAndExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_bitAndExpression1;
        if (corto_define(test_TestPrintVisitor_test_bitAndExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_bitAndExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_bitOrExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_bitOrExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_bitOrExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_bitOrExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_bitOrExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_bitOrExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_bitOrExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_bitOrExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_bitOrExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_bitOrExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_bitOrExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_bitOrExpression1;
        if (corto_define(test_TestPrintVisitor_test_bitOrExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_bitOrExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_bitOrExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_bitOrExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_bitOrExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_bitOrExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_bitOrExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_bitOrExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_bitOrExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_bitOrExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_bitOrExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_bitOrExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_bitOrExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_bitOrExpression2;
        if (corto_define(test_TestPrintVisitor_test_bitOrExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_bitOrExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_callExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_callExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_callExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_callExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_callExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_callExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_callExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_callExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_callExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_callExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_callExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_callExpression1;
        if (corto_define(test_TestPrintVisitor_test_callExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_callExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_callExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_callExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_callExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_callExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_callExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_callExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_callExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_callExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_callExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_callExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_callExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_callExpression2;
        if (corto_define(test_TestPrintVisitor_test_callExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_callExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_comparisonExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_comparisonExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_comparisonExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_comparisonExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_comparisonExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_comparisonExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_comparisonExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_comparisonExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_comparisonExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_comparisonExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_comparisonExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_comparisonExpression1;
        if (corto_define(test_TestPrintVisitor_test_comparisonExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_comparisonExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_comparisonExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_comparisonExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_comparisonExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_comparisonExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_comparisonExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_comparisonExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_comparisonExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_comparisonExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_comparisonExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_comparisonExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_comparisonExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_comparisonExpression2;
        if (corto_define(test_TestPrintVisitor_test_comparisonExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_comparisonExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_ConditionalExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_ConditionalExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_ConditionalExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_ConditionalExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_ConditionalExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_ConditionalExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_ConditionalExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_ConditionalExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_ConditionalExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_ConditionalExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_ConditionalExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_ConditionalExpression1;
        if (corto_define(test_TestPrintVisitor_test_ConditionalExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_ConditionalExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_ConditionalExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_ConditionalExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_ConditionalExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_ConditionalExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_ConditionalExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_ConditionalExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_ConditionalExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_ConditionalExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_ConditionalExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_ConditionalExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_ConditionalExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_ConditionalExpression2;
        if (corto_define(test_TestPrintVisitor_test_ConditionalExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_ConditionalExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_elementExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_elementExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_elementExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_elementExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_elementExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_elementExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_elementExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_elementExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_elementExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_elementExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_elementExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_elementExpression1;
        if (corto_define(test_TestPrintVisitor_test_elementExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_elementExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_elementExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_elementExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_elementExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_elementExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_elementExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_elementExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_elementExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_elementExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_elementExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_elementExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_elementExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_elementExpression2;
        if (corto_define(test_TestPrintVisitor_test_elementExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_elementExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_equalityExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_equalityExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_equalityExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_equalityExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_equalityExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_equalityExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_equalityExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_equalityExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_equalityExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_equalityExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_equalityExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_equalityExpression1;
        if (corto_define(test_TestPrintVisitor_test_equalityExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_equalityExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_equalityExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_equalityExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_equalityExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_equalityExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_equalityExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_equalityExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_equalityExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_equalityExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_equalityExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_equalityExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_equalityExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_equalityExpression2;
        if (corto_define(test_TestPrintVisitor_test_equalityExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_equalityExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_functionDeclaration1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_functionDeclaration1()", test_Case_o));
    if (!test_TestPrintVisitor_test_functionDeclaration1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_functionDeclaration1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_functionDeclaration1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_functionDeclaration1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_functionDeclaration1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_functionDeclaration1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_functionDeclaration1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_functionDeclaration1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_functionDeclaration1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_functionDeclaration1;
        if (corto_define(test_TestPrintVisitor_test_functionDeclaration1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_functionDeclaration1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_functionDeclaration2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_functionDeclaration2()", test_Case_o));
    if (!test_TestPrintVisitor_test_functionDeclaration2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_functionDeclaration2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_functionDeclaration2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_functionDeclaration2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_functionDeclaration2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_functionDeclaration2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_functionDeclaration2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_functionDeclaration2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_functionDeclaration2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_functionDeclaration2;
        if (corto_define(test_TestPrintVisitor_test_functionDeclaration2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_functionDeclaration2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_functionDeclaration3_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_functionDeclaration3()", test_Case_o));
    if (!test_TestPrintVisitor_test_functionDeclaration3_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_functionDeclaration3_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_functionDeclaration3_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_functionDeclaration3_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_functionDeclaration3_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_functionDeclaration3_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_functionDeclaration3_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_functionDeclaration3(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_functionDeclaration3_o)->fptr = (corto_word)_test_TestPrintVisitor_test_functionDeclaration3;
        if (corto_define(test_TestPrintVisitor_test_functionDeclaration3_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_functionDeclaration3_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_logicAndExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_logicAndExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_logicAndExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_logicAndExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_logicAndExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_logicAndExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_logicAndExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_logicAndExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_logicAndExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_logicAndExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_logicAndExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_logicAndExpression1;
        if (corto_define(test_TestPrintVisitor_test_logicAndExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_logicAndExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_logicAndExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_logicAndExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_logicAndExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_logicAndExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_logicAndExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_logicAndExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_logicAndExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_logicAndExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_logicAndExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_logicAndExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_logicAndExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_logicAndExpression2;
        if (corto_define(test_TestPrintVisitor_test_logicAndExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_logicAndExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_logicOrExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_logicOrExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_logicOrExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_logicOrExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_logicOrExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_logicOrExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_logicOrExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_logicOrExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_logicOrExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_logicOrExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_logicOrExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_logicOrExpression1;
        if (corto_define(test_TestPrintVisitor_test_logicOrExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_logicOrExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_logicOrExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_logicOrExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_logicOrExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_logicOrExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_logicOrExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_logicOrExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_logicOrExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_logicOrExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_logicOrExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_logicOrExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_logicOrExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_logicOrExpression2;
        if (corto_define(test_TestPrintVisitor_test_logicOrExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_logicOrExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_memberExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_memberExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_memberExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_memberExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_memberExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_memberExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_memberExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_memberExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_memberExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_memberExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_memberExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_memberExpression1;
        if (corto_define(test_TestPrintVisitor_test_memberExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_memberExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_memberExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_memberExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_memberExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_memberExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_memberExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_memberExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_memberExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_memberExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_memberExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_memberExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_memberExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_memberExpression2;
        if (corto_define(test_TestPrintVisitor_test_memberExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_memberExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_multExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_multExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_multExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_multExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_multExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_multExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_multExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_multExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_multExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_multExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_multExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_multExpression1;
        if (corto_define(test_TestPrintVisitor_test_multExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_multExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration1()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration1;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration10_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration10()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration10_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration10_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration10_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration10_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration10_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration10_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration10_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration10(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration10_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration10;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration10_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration10_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration11_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration11()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration11_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration11_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration11_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration11_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration11_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration11_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration11_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration11(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration11_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration11;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration11_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration11_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration2()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration2;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration3_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration3()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration3_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration3_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration3_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration3_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration3_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration3_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration3_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration3(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration3_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration3;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration3_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration3_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration4_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration4()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration4_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration4_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration4_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration4_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration4_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration4_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration4_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration4(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration4_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration4;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration4_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration4_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration5_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration5()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration5_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration5_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration5_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration5_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration5_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration5_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration5_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration5(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration5_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration5;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration5_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration5_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration6_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration6()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration6_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration6_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration6_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration6_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration6_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration6_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration6_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration6(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration6_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration6;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration6_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration6_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration7_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration7()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration7_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration7_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration7_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration7_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration7_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration7_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration7_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration7(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration7_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration7;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration7_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration7_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration8_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration8()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration8_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration8_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration8_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration8_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration8_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration8_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration8_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration8(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration8_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration8;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration8_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration8_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_objectDeclaration9_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_objectDeclaration9()", test_Case_o));
    if (!test_TestPrintVisitor_test_objectDeclaration9_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_objectDeclaration9_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_objectDeclaration9_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration9_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_objectDeclaration9_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_objectDeclaration9_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_objectDeclaration9_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_objectDeclaration9(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_objectDeclaration9_o)->fptr = (corto_word)_test_TestPrintVisitor_test_objectDeclaration9;
        if (corto_define(test_TestPrintVisitor_test_objectDeclaration9_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_objectDeclaration9_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_shiftExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_shiftExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_shiftExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_shiftExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_shiftExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_shiftExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_shiftExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_shiftExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_shiftExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_shiftExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_shiftExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_shiftExpression1;
        if (corto_define(test_TestPrintVisitor_test_shiftExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_shiftExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_unaryExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_unaryExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_unaryExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_unaryExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_unaryExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_unaryExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_unaryExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_unaryExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_unaryExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_unaryExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_unaryExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_unaryExpression1;
        if (corto_define(test_TestPrintVisitor_test_unaryExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_unaryExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_unaryExpression2_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_unaryExpression2()", test_Case_o));
    if (!test_TestPrintVisitor_test_unaryExpression2_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_unaryExpression2_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_unaryExpression2_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_unaryExpression2_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_unaryExpression2_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_unaryExpression2_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_unaryExpression2_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_unaryExpression2(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_unaryExpression2_o)->fptr = (corto_word)_test_TestPrintVisitor_test_unaryExpression2;
        if (corto_define(test_TestPrintVisitor_test_unaryExpression2_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_unaryExpression2_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_visitorAssignment_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_visitorAssignment()", test_Case_o));
    if (!test_TestPrintVisitor_test_visitorAssignment_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_visitorAssignment_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_visitorAssignment_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_visitorAssignment_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_visitorAssignment_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_visitorAssignment_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_visitorAssignment_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_visitorAssignment(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_visitorAssignment_o)->fptr = (corto_word)_test_TestPrintVisitor_test_visitorAssignment;
        if (corto_define(test_TestPrintVisitor_test_visitorAssignment_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_visitorAssignment_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_visitorAtom_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_visitorAtom()", test_Case_o));
    if (!test_TestPrintVisitor_test_visitorAtom_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_visitorAtom_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_visitorAtom_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_visitorAtom_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_visitorAtom_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_visitorAtom_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_visitorAtom_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_visitorAtom(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_visitorAtom_o)->fptr = (corto_word)_test_TestPrintVisitor_test_visitorAtom;
        if (corto_define(test_TestPrintVisitor_test_visitorAtom_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_visitorAtom_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestPrintVisitor_test_visitorCommaExpression1_o = test_Case(corto_declareChild(test_TestPrintVisitor_o, "test_visitorCommaExpression1()", test_Case_o));
    if (!test_TestPrintVisitor_test_visitorCommaExpression1_o) {
        corto_error("test_load: failed to declare 'test_TestPrintVisitor_test_visitorCommaExpression1_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestPrintVisitor_test_visitorCommaExpression1_o, CORTO_DEFINED)) {
        ((corto_function)test_TestPrintVisitor_test_visitorCommaExpression1_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestPrintVisitor_test_visitorCommaExpression1_o)->returnsReference = FALSE;
        ((corto_method)test_TestPrintVisitor_test_visitorCommaExpression1_o)->_virtual = FALSE;
        
        corto_function(test_TestPrintVisitor_test_visitorCommaExpression1_o)->kind = CORTO_PROCEDURE_CDECL;
        corto_void _test_TestPrintVisitor_test_visitorCommaExpression1(
    test_TestPrintVisitor _this);
        corto_function(test_TestPrintVisitor_test_visitorCommaExpression1_o)->fptr = (corto_word)_test_TestPrintVisitor_test_visitorCommaExpression1;
        if (corto_define(test_TestPrintVisitor_test_visitorCommaExpression1_o)) {
            corto_error("test_load: failed to define 'test_TestPrintVisitor_test_visitorCommaExpression1_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (_a_) {
        corto_release(_a_);
    }

    return 0;
error:
    if (_a_) {
        corto_release(_a_);
    }

    return -1;
}
