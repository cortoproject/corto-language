/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : Cortolang.g
 *     -                            On : 2016-05-06 11:15:09
 *     -                for the parser : CortolangParserParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser 
CortolangParser

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pCortolangParser, which is returned from a call to CortolangParserNew().
 *
 * The methods in pCortolangParser are  as follows:
 *
 *  - 
 CortolangParser_program_return
      pCortolangParser->program(pCortolangParser)
 *  - 
 CortolangParser_statement_return
      pCortolangParser->statement(pCortolangParser)
 *  - 
 CortolangParser_scopeStatement_return
      pCortolangParser->scopeStatement(pCortolangParser)
 *  - 
 CortolangParser_scopeExpression_return
      pCortolangParser->scopeExpression(pCortolangParser)
 *  - 
 CortolangParser_suite_return
      pCortolangParser->suite(pCortolangParser)
 *  - 
 CortolangParser_definitionOrDeclaration_return
      pCortolangParser->definitionOrDeclaration(pCortolangParser)
 *  - 
 CortolangParser_declaration_return
      pCortolangParser->declaration(pCortolangParser)
 *  - 
 CortolangParser_typeLabel_return
      pCortolangParser->typeLabel(pCortolangParser)
 *  - 
 CortolangParser_anonymousTypeLabel_return
      pCortolangParser->anonymousTypeLabel(pCortolangParser)
 *  - 
 CortolangParser_compileTimeConstant_return
      pCortolangParser->compileTimeConstant(pCortolangParser)
 *  - 
 CortolangParser_initializer_return
      pCortolangParser->initializer(pCortolangParser)
 *  - 
 CortolangParser_initializerValue_return
      pCortolangParser->initializerValue(pCortolangParser)
 *  - 
 CortolangParser_initializerBraces_return
      pCortolangParser->initializerBraces(pCortolangParser)
 *  - 
 CortolangParser_initializerKeyValue_return
      pCortolangParser->initializerKeyValue(pCortolangParser)
 *  - 
 CortolangParser_initializerKey_return
      pCortolangParser->initializerKey(pCortolangParser)
 *  - 
 CortolangParser_functionDeclaration_return
      pCortolangParser->functionDeclaration(pCortolangParser)
 *  - 
 CortolangParser_functionArguments_return
      pCortolangParser->functionArguments(pCortolangParser)
 *  - 
 CortolangParser_functionArgument_return
      pCortolangParser->functionArgument(pCortolangParser)
 *  - 
 CortolangParser_expression_return
      pCortolangParser->expression(pCortolangParser)
 *  - 
 CortolangParser_assignmentExpression_return
      pCortolangParser->assignmentExpression(pCortolangParser)
 *  - 
 CortolangParser_commaExpression_return
      pCortolangParser->commaExpression(pCortolangParser)
 *  - 
 CortolangParser_conditionalExpression_return
      pCortolangParser->conditionalExpression(pCortolangParser)
 *  - 
 CortolangParser_initializerExpression_return
      pCortolangParser->initializerExpression(pCortolangParser)
 *  - 
 CortolangParser_logicOrExpression_return
      pCortolangParser->logicOrExpression(pCortolangParser)
 *  - 
 CortolangParser_logicAndExpression_return
      pCortolangParser->logicAndExpression(pCortolangParser)
 *  - 
 CortolangParser_equalityExpression_return
      pCortolangParser->equalityExpression(pCortolangParser)
 *  - 
 CortolangParser_shiftExpression_return
      pCortolangParser->shiftExpression(pCortolangParser)
 *  - 
 CortolangParser_addExpression_return
      pCortolangParser->addExpression(pCortolangParser)
 *  - 
 CortolangParser_multExpression_return
      pCortolangParser->multExpression(pCortolangParser)
 *  - 
 CortolangParser_unaryExpression_return
      pCortolangParser->unaryExpression(pCortolangParser)
 *  - 
 CortolangParser_atomExpression_return
      pCortolangParser->atomExpression(pCortolangParser)
 *  - 
 CortolangParser_assignmentOp_return
      pCortolangParser->assignmentOp(pCortolangParser)
 *  - 
 CortolangParser_eqOp_return
      pCortolangParser->eqOp(pCortolangParser)
 *  - 
 CortolangParser_shiftOp_return
      pCortolangParser->shiftOp(pCortolangParser)
 *  - 
 CortolangParser_addOp_return
      pCortolangParser->addOp(pCortolangParser)
 *  - 
 CortolangParser_multOp_return
      pCortolangParser->multOp(pCortolangParser)
 *  - 
 CortolangParser_unaryOp_return
      pCortolangParser->unaryOp(pCortolangParser)
 *  - 
 CortolangParser_constant_return
      pCortolangParser->constant(pCortolangParser)
 *  - 
 CortolangParser_identifier_return
      pCortolangParser->identifier(pCortolangParser)
 *  - 
 CortolangParser_literal_return
      pCortolangParser->literal(pCortolangParser)
 *  - 
 CortolangParser_scopeOperator_return
      pCortolangParser->scopeOperator(pCortolangParser)
 *  - 
 CortolangParser_preScopeOperator_return
      pCortolangParser->preScopeOperator(pCortolangParser)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_CortolangParser_H
#define _CortolangParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#include "cortolangParserCustom.hpp"


#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct CortolangParser_Ctx_struct CortolangParser, * pCortolangParser;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif
typedef struct CortolangParser_program_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_program_return;



typedef struct CortolangParser_statement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_statement_return;



typedef struct CortolangParser_scopeStatement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_scopeStatement_return;



typedef struct CortolangParser_scopeExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_scopeExpression_return;



typedef struct CortolangParser_suite_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_suite_return;



typedef struct CortolangParser_definitionOrDeclaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_definitionOrDeclaration_return;



typedef struct CortolangParser_declaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_declaration_return;



typedef struct CortolangParser_typeLabel_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_typeLabel_return;



typedef struct CortolangParser_anonymousTypeLabel_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_anonymousTypeLabel_return;



typedef struct CortolangParser_compileTimeConstant_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_compileTimeConstant_return;



typedef struct CortolangParser_initializer_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_initializer_return;



typedef struct CortolangParser_initializerValue_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_initializerValue_return;



typedef struct CortolangParser_initializerBraces_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_initializerBraces_return;



typedef struct CortolangParser_initializerKeyValue_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_initializerKeyValue_return;



typedef struct CortolangParser_initializerKey_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_initializerKey_return;



typedef struct CortolangParser_functionDeclaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_functionDeclaration_return;



typedef struct CortolangParser_functionArguments_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_functionArguments_return;



typedef struct CortolangParser_functionArgument_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_functionArgument_return;



typedef struct CortolangParser_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_expression_return;



typedef struct CortolangParser_assignmentExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_assignmentExpression_return;



typedef struct CortolangParser_commaExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_commaExpression_return;



typedef struct CortolangParser_conditionalExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_conditionalExpression_return;



typedef struct CortolangParser_initializerExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_initializerExpression_return;



typedef struct CortolangParser_logicOrExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_logicOrExpression_return;



typedef struct CortolangParser_logicAndExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_logicAndExpression_return;



typedef struct CortolangParser_equalityExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_equalityExpression_return;



typedef struct CortolangParser_shiftExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_shiftExpression_return;



typedef struct CortolangParser_addExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_addExpression_return;



typedef struct CortolangParser_multExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_multExpression_return;



typedef struct CortolangParser_unaryExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_unaryExpression_return;



typedef struct CortolangParser_atomExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_atomExpression_return;



typedef struct CortolangParser_assignmentOp_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_assignmentOp_return;



typedef struct CortolangParser_eqOp_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_eqOp_return;



typedef struct CortolangParser_shiftOp_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_shiftOp_return;



typedef struct CortolangParser_addOp_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_addOp_return;



typedef struct CortolangParser_multOp_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_multOp_return;



typedef struct CortolangParser_unaryOp_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_unaryOp_return;



typedef struct CortolangParser_constant_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_constant_return;



typedef struct CortolangParser_identifier_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_identifier_return;



typedef struct CortolangParser_literal_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_literal_return;



typedef struct CortolangParser_scopeOperator_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_scopeOperator_return;



typedef struct CortolangParser_preScopeOperator_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    CortolangParser_preScopeOperator_return;




/** Context tracking structure for 
CortolangParser

 */
struct CortolangParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;

     CortolangParser_program_return
     (*program)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_statement_return
     (*statement)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_scopeStatement_return
     (*scopeStatement)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_scopeExpression_return
     (*scopeExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_suite_return
     (*suite)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_definitionOrDeclaration_return
     (*definitionOrDeclaration)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_declaration_return
     (*declaration)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_typeLabel_return
     (*typeLabel)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_anonymousTypeLabel_return
     (*anonymousTypeLabel)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_compileTimeConstant_return
     (*compileTimeConstant)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_initializer_return
     (*initializer)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_initializerValue_return
     (*initializerValue)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_initializerBraces_return
     (*initializerBraces)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_initializerKeyValue_return
     (*initializerKeyValue)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_initializerKey_return
     (*initializerKey)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_functionDeclaration_return
     (*functionDeclaration)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_functionArguments_return
     (*functionArguments)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_functionArgument_return
     (*functionArgument)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_expression_return
     (*expression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_assignmentExpression_return
     (*assignmentExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_commaExpression_return
     (*commaExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_conditionalExpression_return
     (*conditionalExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_initializerExpression_return
     (*initializerExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_logicOrExpression_return
     (*logicOrExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_logicAndExpression_return
     (*logicAndExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_equalityExpression_return
     (*equalityExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_shiftExpression_return
     (*shiftExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_addExpression_return
     (*addExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_multExpression_return
     (*multExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_unaryExpression_return
     (*unaryExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_atomExpression_return
     (*atomExpression)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_assignmentOp_return
     (*assignmentOp)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_eqOp_return
     (*eqOp)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_shiftOp_return
     (*shiftOp)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_addOp_return
     (*addOp)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_multOp_return
     (*multOp)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_unaryOp_return
     (*unaryOp)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_constant_return
     (*constant)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_identifier_return
     (*identifier)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_literal_return
     (*literal)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_scopeOperator_return
     (*scopeOperator)	(struct CortolangParser_Ctx_struct * ctx);

     CortolangParser_preScopeOperator_return
     (*preScopeOperator)	(struct CortolangParser_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct CortolangParser_Ctx_struct * ctx);
    void	    (*free)   (struct CortolangParser_Ctx_struct * ctx);
/* @headerFile.members() */
pANTLR3_BASE_TREE_ADAPTOR	adaptor;
pANTLR3_VECTOR_FACTORY		vectors;
/* End @headerFile.members() */
    struct parser_data* parser_data;

};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pCortolangParser CortolangParserNew         (
pANTLR3_COMMON_TOKEN_STREAM
 instream);
ANTLR3_API pCortolangParser CortolangParserNewSSD      (
pANTLR3_COMMON_TOKEN_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define AMPERSAND      4
#define ASTERISK      5
#define BOOLEAN      6
#define CHARACTER      7
#define COLON      8
#define COMMA      9
#define DEDENT      10
#define DIGIT      11
#define DOUBLE_COLON      12
#define EQUAL      13
#define EQUALS      14
#define ESC      15
#define GEQ      16
#define GID      17
#define GT      18
#define INDENT      19
#define INTEGER      20
#define KW_FOR      21
#define KW_WAIT      22
#define LBRACE      23
#define LBRACK      24
#define LEQ      25
#define LETTER_UNDERSCORE      26
#define LOGIC_AND      27
#define LOGIC_OR      28
#define LPAREN      29
#define LSHIFT      30
#define LT      31
#define MINUS      32
#define NEWLINE      33
#define NOT_EQUALS      34
#define PLUS      35
#define QMARK      36
#define RBRACE      37
#define RBRACK      38
#define RPAREN      39
#define RSHIFT      40
#define SLASH      41
#define STRING      42
#define TILDE      43
#define TRIPLE_COLON      44
#define VALID_NAME      45
#define WHITESPACE      46
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for CortolangParser
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
