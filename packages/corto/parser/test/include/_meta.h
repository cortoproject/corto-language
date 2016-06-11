/* _meta.h
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#ifndef TEST_META_H
#define TEST_META_H

#include <corto/corto.h>
#include <_interface.h>

#ifdef __cplusplus
extern "C" {
#endif

TEST_EXPORT extern corto_package test_o;
TEST_EXPORT extern corto_class test_Point_o;
TEST_EXPORT extern corto_member test_Point_x_o;
TEST_EXPORT extern corto_member test_Point_y_o;
TEST_EXPORT extern test_Suite test_TestCortoLanguage_o;
TEST_EXPORT extern corto_member test_TestCortoLanguage_parser_o;
TEST_EXPORT extern corto_method test_TestCortoLanguage_setup_o;
TEST_EXPORT extern corto_method test_TestCortoLanguage_teardown_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_addExpr_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_assignmentExpr_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_atom_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_badToken_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_commaExpr_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_declaration1_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_declaration2_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_declaration3_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_declaration4_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_elementAccess_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionCall_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionCall2_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionCall3_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionCall4_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionDeclaration1_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionDeclaration2_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionDeclaration3_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionDeclaration4_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionDeclaration5_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionDeclaration6_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_functionDeclaration7_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_ifStatement1_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_ifStatement2_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_ifStatement3_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_ifStatement4_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_ifStatement5_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_ifStatement6_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_ifStatement7_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_logicAndExpr_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_logicOrExpr_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_multExpr_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_observer1_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_observer2_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_observer3_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_observer4_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_observer5_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_scope1_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_scope2_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_scope3_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_scope4_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_scope5_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_test_unary_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_testWhileStatement1_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_testWhileStatement2_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_testWhileStatement3_o;
TEST_EXPORT extern test_Case test_TestCortoLanguage_testWhileStatement4_o;
TEST_EXPORT extern test_Suite test_TestDeclarationVisitor_o;
TEST_EXPORT extern test_Case test_TestDeclarationVisitor_testInt8Declaration_o;
TEST_EXPORT extern test_Case test_TestDeclarationVisitor_testInt8DeclarationAndDefinition_o;
TEST_EXPORT extern test_Case test_TestDeclarationVisitor_testMultipleInt8Declaration_o;
TEST_EXPORT extern test_Case test_TestDeclarationVisitor_testMultipleInt8DeclarationAndDefinition_o;
TEST_EXPORT extern test_Suite test_TestPrintVisitor_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_addExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_bitAndExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_bitOrExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_bitOrExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_callExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_callExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_comparisonExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_comparisonExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_ConditionalExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_ConditionalExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_elementExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_elementExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_equalityExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_equalityExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_functionDeclaration1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_functionDeclaration2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_functionDeclaration3_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_logicAndExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_logicAndExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_logicOrExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_logicOrExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_memberExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_memberExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_multExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration10_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration11_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration3_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration4_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration5_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration6_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration7_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration8_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_objectDeclaration9_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_shiftExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_unaryExpression1_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_unaryExpression2_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_visitorAssignment_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_visitorAtom_o;
TEST_EXPORT extern test_Case test_TestPrintVisitor_test_visitorCommaExpression1_o;

#ifdef __cplusplus
}
#endif
#endif

