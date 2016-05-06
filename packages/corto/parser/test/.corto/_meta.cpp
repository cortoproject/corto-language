/* _meta.cpp
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#include <test.h>
/* Variable definitions */
corto_package test_o;
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
test_Case test_TestCortoLanguage_test_functionDeclaration1_o;
test_Case test_TestCortoLanguage_test_functionDeclaration2_o;
test_Case test_TestCortoLanguage_test_functionDeclaration3_o;
test_Case test_TestCortoLanguage_test_logicAndExpr_o;
test_Case test_TestCortoLanguage_test_logicOrExpr_o;
test_Case test_TestCortoLanguage_test_multExpr_o;
test_Case test_TestCortoLanguage_test_scope1_o;
test_Case test_TestCortoLanguage_test_scope2_o;
test_Case test_TestCortoLanguage_test_scope3_o;
test_Case test_TestCortoLanguage_test_unary_o;
test_Case test_TestCortoLanguage_test_waitExpr_o;

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
        void __test_TestCortoLanguage_setup(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_setup_o)->impl = (corto_word)__test_TestCortoLanguage_setup;
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
        void __test_TestCortoLanguage_teardown(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_teardown_o)->impl = (corto_word)__test_TestCortoLanguage_teardown;
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
        void __test_TestCortoLanguage_test_addExpr(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_addExpr_o)->impl = (corto_word)__test_TestCortoLanguage_test_addExpr;
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
        void __test_TestCortoLanguage_test_assignmentExpr(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_assignmentExpr_o)->impl = (corto_word)__test_TestCortoLanguage_test_assignmentExpr;
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
        void __test_TestCortoLanguage_test_atom(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_atom_o)->impl = (corto_word)__test_TestCortoLanguage_test_atom;
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
        void __test_TestCortoLanguage_test_badToken(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_badToken_o)->impl = (corto_word)__test_TestCortoLanguage_test_badToken;
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
        void __test_TestCortoLanguage_test_commaExpr(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_commaExpr_o)->impl = (corto_word)__test_TestCortoLanguage_test_commaExpr;
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
        void __test_TestCortoLanguage_test_declaration1(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_declaration1_o)->impl = (corto_word)__test_TestCortoLanguage_test_declaration1;
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
        void __test_TestCortoLanguage_test_declaration2(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_declaration2_o)->impl = (corto_word)__test_TestCortoLanguage_test_declaration2;
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
        void __test_TestCortoLanguage_test_declaration3(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_declaration3_o)->impl = (corto_word)__test_TestCortoLanguage_test_declaration3;
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
        void __test_TestCortoLanguage_test_declaration4(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_declaration4_o)->impl = (corto_word)__test_TestCortoLanguage_test_declaration4;
        if (corto_define(test_TestCortoLanguage_test_declaration4_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_declaration4_o' (%s)", corto_lasterr());
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
        void __test_TestCortoLanguage_test_functionDeclaration1(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_functionDeclaration1_o)->impl = (corto_word)__test_TestCortoLanguage_test_functionDeclaration1;
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
        void __test_TestCortoLanguage_test_functionDeclaration2(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_functionDeclaration2_o)->impl = (corto_word)__test_TestCortoLanguage_test_functionDeclaration2;
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
        void __test_TestCortoLanguage_test_functionDeclaration3(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_functionDeclaration3_o)->impl = (corto_word)__test_TestCortoLanguage_test_functionDeclaration3;
        if (corto_define(test_TestCortoLanguage_test_functionDeclaration3_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_functionDeclaration3_o' (%s)", corto_lasterr());
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
        void __test_TestCortoLanguage_test_logicAndExpr(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_logicAndExpr_o)->impl = (corto_word)__test_TestCortoLanguage_test_logicAndExpr;
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
        void __test_TestCortoLanguage_test_logicOrExpr(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_logicOrExpr_o)->impl = (corto_word)__test_TestCortoLanguage_test_logicOrExpr;
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
        void __test_TestCortoLanguage_test_multExpr(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_multExpr_o)->impl = (corto_word)__test_TestCortoLanguage_test_multExpr;
        if (corto_define(test_TestCortoLanguage_test_multExpr_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_multExpr_o' (%s)", corto_lasterr());
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
        void __test_TestCortoLanguage_test_scope1(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_scope1_o)->impl = (corto_word)__test_TestCortoLanguage_test_scope1;
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
        void __test_TestCortoLanguage_test_scope2(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_scope2_o)->impl = (corto_word)__test_TestCortoLanguage_test_scope2;
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
        void __test_TestCortoLanguage_test_scope3(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_scope3_o)->impl = (corto_word)__test_TestCortoLanguage_test_scope3;
        if (corto_define(test_TestCortoLanguage_test_scope3_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_scope3_o' (%s)", corto_lasterr());
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
        void __test_TestCortoLanguage_test_unary(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_unary_o)->impl = (corto_word)__test_TestCortoLanguage_test_unary;
        if (corto_define(test_TestCortoLanguage_test_unary_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_unary_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    test_TestCortoLanguage_test_waitExpr_o = test_Case(corto_declareChild(test_TestCortoLanguage_o, "test_waitExpr()", test_Case_o));
    if (!test_TestCortoLanguage_test_waitExpr_o) {
        corto_error("test_load: failed to declare 'test_TestCortoLanguage_test_waitExpr_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(test_TestCortoLanguage_test_waitExpr_o, CORTO_DEFINED)) {
        ((corto_function)test_TestCortoLanguage_test_waitExpr_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)test_TestCortoLanguage_test_waitExpr_o)->returnsReference = FALSE;
        ((corto_method)test_TestCortoLanguage_test_waitExpr_o)->_virtual = FALSE;
        
        corto_function(test_TestCortoLanguage_test_waitExpr_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_TestCortoLanguage_test_waitExpr(corto_function f, void *args, void *result);
        corto_function(test_TestCortoLanguage_test_waitExpr_o)->impl = (corto_word)__test_TestCortoLanguage_test_waitExpr;
        if (corto_define(test_TestCortoLanguage_test_waitExpr_o)) {
            corto_error("test_load: failed to define 'test_TestCortoLanguage_test_waitExpr_o' (%s)", corto_lasterr());
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
