/* _meta.cpp
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#include <corto/parser/parser.h>
/* Variable definitions */
corto_package corto_parser_o;
corto_class parser_BaseParser_o;
corto_virtual parser_BaseParser_displayRecognitionError_o;
corto_method parser_BaseParser_parse_o;
corto_method parser_BaseParser_parseFile_o;
corto_member parser_BaseParser_programReturn_o;
corto_member parser_BaseParser_success_o;
corto_class parser_BaseVisitor_o;
corto_method parser_BaseVisitor_construct_o;
corto_method parser_BaseVisitor_destruct_o;
corto_member parser_BaseVisitor_parser_o;
corto_virtual parser_BaseVisitor_visit_o;
corto_class parser_BinaryExpressionNode_o;
corto_member parser_BinaryExpressionNode_left_o;
corto_member parser_BinaryExpressionNode_operator_o;
corto_member parser_BinaryExpressionNode_right_o;
corto_class parser_CommaExpressionNode_o;
corto_member parser_CommaExpressionNode_expressions_o;
corto_class parser_ConditionalExpressionNode_o;
corto_member parser_ConditionalExpressionNode_condition_o;
corto_member parser_ConditionalExpressionNode_falseValue_o;
corto_member parser_ConditionalExpressionNode_trueValue_o;
corto_list parser_ExpressionList_o;
corto_class parser_ExpressionNode_o;
corto_class parser_ExpressionStatementNode_o;
corto_member parser_ExpressionStatementNode_expression_o;
corto_class parser_Node_o;
corto_member parser_Node_column_o;
corto_member parser_Node_line_o;
corto_virtual parser_BaseVisitor_visitExpressionNode_o;
corto_virtual parser_BaseVisitor_visitBinaryExpressionNode_o;
corto_virtual parser_BaseVisitor_visitCommaExpressionNode_o;
corto_virtual parser_BaseVisitor_visitConditionalExpressionNode_o;
corto_class parser_StatementNode_o;
corto_virtual parser_BaseVisitor_visitStatementNode_o;
corto_virtual parser_BaseVisitor_visitExpressionStatementNode_o;
corto_list parser_StatementList_o;
corto_class parser_PrintVisitor_o;
corto_member parser_PrintVisitor_buffer_o;
corto_member parser_PrintVisitor_level_o;
corto_class parser_ProgramNode_o;
corto_member parser_ProgramNode_statements_o;
corto_virtual parser_BaseVisitor_visitProgramNode_o;
corto_method parser_PrintVisitor_construct_o;
corto_method parser_PrintVisitor_destruct_o;
corto_method parser_PrintVisitor_getText_o;
corto_virtual parser_PrintVisitor_visitBinaryExpressionNode_o;
corto_virtual parser_PrintVisitor_visitCommaExpressionNode_o;
corto_virtual parser_PrintVisitor_visitConditionalExpressionNode_o;
corto_virtual parser_PrintVisitor_visitExpressionNode_o;
corto_virtual parser_PrintVisitor_visitProgramNode_o;
corto_virtual parser_PrintVisitor_visitStatementNode_o;
corto_class parser_SimpleParser_o;
corto_method parser_SimpleParser_displayRecognitionError_o;
corto_member parser_SimpleParser_errors_o;
corto_list corto_stringList_o;

/* Load objects in object store. */
int parser_load(void) {
    corto_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    corto_parser_o = corto_package(corto_declareChild(corto_o, "parser", corto_package_o));
    if (!corto_parser_o) {
        corto_error("parser_load: failed to declare 'corto_parser_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(corto_parser_o, CORTO_DEFINED)) {
        corto_parser_o->url = NULL;
        if (corto_define(corto_parser_o)) {
            corto_error("parser_load: failed to define 'corto_parser_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BaseParser_o = corto_class(corto_declareChild(corto_parser_o, "BaseParser", corto_class_o));
    if (!parser_BaseParser_o) {
        corto_error("parser_load: failed to declare 'parser_BaseParser_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_BaseParser_displayRecognitionError_o = corto_virtual(corto_declareChild(parser_BaseParser_o, "displayRecognitionError(word recognizer,word tokenNames)", corto_virtual_o));
    if (!parser_BaseParser_displayRecognitionError_o) {
        corto_error("parser_load: failed to declare 'parser_BaseParser_displayRecognitionError_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseParser_displayRecognitionError_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseParser_displayRecognitionError_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)parser_BaseParser_displayRecognitionError_o)->returnsReference = FALSE;
        ((corto_method)parser_BaseParser_displayRecognitionError_o)->_virtual = TRUE;
        
        corto_function(parser_BaseParser_displayRecognitionError_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseParser_displayRecognitionError_v(corto_function f, void *args, void *result);
        corto_function(parser_BaseParser_displayRecognitionError_o)->impl = (corto_word)__parser_BaseParser_displayRecognitionError_v;
        if (corto_define(parser_BaseParser_displayRecognitionError_o)) {
            corto_error("parser_load: failed to define 'parser_BaseParser_displayRecognitionError_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BaseParser_parse_o = corto_method(corto_declareChild(parser_BaseParser_o, "parse(string text)", corto_method_o));
    if (!parser_BaseParser_parse_o) {
        corto_error("parser_load: failed to declare 'parser_BaseParser_parse_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseParser_parse_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseParser_parse_o)->returnType = corto_type(corto_resolve(NULL, "int16"));
        ((corto_function)parser_BaseParser_parse_o)->returnsReference = FALSE;
        parser_BaseParser_parse_o->_virtual = FALSE;
        
        corto_function(parser_BaseParser_parse_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseParser_parse(corto_function f, void *args, void *result);
        corto_function(parser_BaseParser_parse_o)->impl = (corto_word)__parser_BaseParser_parse;
        if (corto_define(parser_BaseParser_parse_o)) {
            corto_error("parser_load: failed to define 'parser_BaseParser_parse_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BaseParser_parseFile_o = corto_method(corto_declareChild(parser_BaseParser_o, "parseFile(string filename)", corto_method_o));
    if (!parser_BaseParser_parseFile_o) {
        corto_error("parser_load: failed to declare 'parser_BaseParser_parseFile_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseParser_parseFile_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseParser_parseFile_o)->returnType = corto_type(corto_resolve(NULL, "int16"));
        ((corto_function)parser_BaseParser_parseFile_o)->returnsReference = FALSE;
        parser_BaseParser_parseFile_o->_virtual = FALSE;
        
        corto_function(parser_BaseParser_parseFile_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseParser_parseFile(corto_function f, void *args, void *result);
        corto_function(parser_BaseParser_parseFile_o)->impl = (corto_word)__parser_BaseParser_parseFile;
        if (corto_define(parser_BaseParser_parseFile_o)) {
            corto_error("parser_load: failed to define 'parser_BaseParser_parseFile_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BaseParser_programReturn_o = corto_member(corto_declareChild(parser_BaseParser_o, "programReturn", corto_member_o));
    if (!parser_BaseParser_programReturn_o) {
        corto_error("parser_load: failed to declare 'parser_BaseParser_programReturn_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_BaseParser_success_o = corto_member(corto_declareChild(parser_BaseParser_o, "success", corto_member_o));
    if (!parser_BaseParser_success_o) {
        corto_error("parser_load: failed to declare 'parser_BaseParser_success_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseParser_success_o, CORTO_DEFINED)) {
        parser_BaseParser_success_o->type = corto_type(corto_resolve(NULL, "bool"));
        parser_BaseParser_success_o->modifiers = 0x4;
        parser_BaseParser_success_o->state = 0x6;
        parser_BaseParser_success_o->weak = FALSE;
        parser_BaseParser_success_o->id = 0;
        if (corto_define(parser_BaseParser_success_o)) {
            corto_error("parser_load: failed to define 'parser_BaseParser_success_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BaseVisitor_o = corto_class(corto_declareChild(corto_parser_o, "BaseVisitor", corto_class_o));
    if (!parser_BaseVisitor_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_BaseVisitor_construct_o = corto_method(corto_declareChild(parser_BaseVisitor_o, "construct()", corto_method_o));
    if (!parser_BaseVisitor_construct_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_construct_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_construct_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_construct_o)->returnType = corto_type(corto_resolve(NULL, "int16"));
        ((corto_function)parser_BaseVisitor_construct_o)->returnsReference = FALSE;
        parser_BaseVisitor_construct_o->_virtual = FALSE;
        
        corto_function(parser_BaseVisitor_construct_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_construct(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_construct_o)->impl = (corto_word)__parser_BaseVisitor_construct;
        if (corto_define(parser_BaseVisitor_construct_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_construct_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BaseVisitor_destruct_o = corto_method(corto_declareChild(parser_BaseVisitor_o, "destruct()", corto_method_o));
    if (!parser_BaseVisitor_destruct_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_destruct_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_destruct_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_destruct_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)parser_BaseVisitor_destruct_o)->returnsReference = FALSE;
        parser_BaseVisitor_destruct_o->_virtual = FALSE;
        
        corto_function(parser_BaseVisitor_destruct_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_destruct(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_destruct_o)->impl = (corto_word)__parser_BaseVisitor_destruct;
        if (corto_define(parser_BaseVisitor_destruct_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_destruct_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BaseVisitor_parser_o = corto_member(corto_declareChild(parser_BaseVisitor_o, "parser", corto_member_o));
    if (!parser_BaseVisitor_parser_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_parser_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_BaseVisitor_visit_o = corto_virtual(corto_declareChild(parser_BaseVisitor_o, "visit()", corto_virtual_o));
    if (!parser_BaseVisitor_visit_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_visit_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_visit_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_visit_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_BaseVisitor_visit_o)->returnsReference = FALSE;
        ((corto_method)parser_BaseVisitor_visit_o)->_virtual = TRUE;
        
        corto_function(parser_BaseVisitor_visit_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_visit_v(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_visit_o)->impl = (corto_word)__parser_BaseVisitor_visit_v;
        if (corto_define(parser_BaseVisitor_visit_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_visit_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BinaryExpressionNode_o = corto_class(corto_declareChild(corto_parser_o, "BinaryExpressionNode", corto_class_o));
    if (!parser_BinaryExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_BinaryExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_BinaryExpressionNode_left_o = corto_member(corto_declareChild(parser_BinaryExpressionNode_o, "left", corto_member_o));
    if (!parser_BinaryExpressionNode_left_o) {
        corto_error("parser_load: failed to declare 'parser_BinaryExpressionNode_left_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_BinaryExpressionNode_operator_o = corto_member(corto_declareChild(parser_BinaryExpressionNode_o, "operator", corto_member_o));
    if (!parser_BinaryExpressionNode_operator_o) {
        corto_error("parser_load: failed to declare 'parser_BinaryExpressionNode_operator_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BinaryExpressionNode_operator_o, CORTO_DEFINED)) {
        parser_BinaryExpressionNode_operator_o->type = corto_type(corto_resolve(NULL, "string"));
        parser_BinaryExpressionNode_operator_o->modifiers = 0x0;
        parser_BinaryExpressionNode_operator_o->state = 0x6;
        parser_BinaryExpressionNode_operator_o->weak = FALSE;
        parser_BinaryExpressionNode_operator_o->id = 1;
        if (corto_define(parser_BinaryExpressionNode_operator_o)) {
            corto_error("parser_load: failed to define 'parser_BinaryExpressionNode_operator_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BinaryExpressionNode_right_o = corto_member(corto_declareChild(parser_BinaryExpressionNode_o, "right", corto_member_o));
    if (!parser_BinaryExpressionNode_right_o) {
        corto_error("parser_load: failed to declare 'parser_BinaryExpressionNode_right_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_CommaExpressionNode_o = corto_class(corto_declareChild(corto_parser_o, "CommaExpressionNode", corto_class_o));
    if (!parser_CommaExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_CommaExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_CommaExpressionNode_expressions_o = corto_member(corto_declareChild(parser_CommaExpressionNode_o, "expressions", corto_member_o));
    if (!parser_CommaExpressionNode_expressions_o) {
        corto_error("parser_load: failed to declare 'parser_CommaExpressionNode_expressions_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_ConditionalExpressionNode_o = corto_class(corto_declareChild(corto_parser_o, "ConditionalExpressionNode", corto_class_o));
    if (!parser_ConditionalExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_ConditionalExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_ConditionalExpressionNode_condition_o = corto_member(corto_declareChild(parser_ConditionalExpressionNode_o, "condition", corto_member_o));
    if (!parser_ConditionalExpressionNode_condition_o) {
        corto_error("parser_load: failed to declare 'parser_ConditionalExpressionNode_condition_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_ConditionalExpressionNode_falseValue_o = corto_member(corto_declareChild(parser_ConditionalExpressionNode_o, "falseValue", corto_member_o));
    if (!parser_ConditionalExpressionNode_falseValue_o) {
        corto_error("parser_load: failed to declare 'parser_ConditionalExpressionNode_falseValue_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_ConditionalExpressionNode_trueValue_o = corto_member(corto_declareChild(parser_ConditionalExpressionNode_o, "trueValue", corto_member_o));
    if (!parser_ConditionalExpressionNode_trueValue_o) {
        corto_error("parser_load: failed to declare 'parser_ConditionalExpressionNode_trueValue_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_ExpressionList_o = corto_list(corto_declareChild(corto_parser_o, "ExpressionList", corto_list_o));
    if (!parser_ExpressionList_o) {
        corto_error("parser_load: failed to declare 'parser_ExpressionList_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_ExpressionNode_o = corto_class(corto_declareChild(corto_parser_o, "ExpressionNode", corto_class_o));
    if (!parser_ExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_ExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_ExpressionList_o, CORTO_DEFINED)) {
        ((corto_collection)parser_ExpressionList_o)->elementType = corto_type(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        ((corto_collection)parser_ExpressionList_o)->max = 0;
        if (corto_define(parser_ExpressionList_o)) {
            corto_error("parser_load: failed to define 'parser_ExpressionList_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_ExpressionList_o)->size != sizeof(parser_ExpressionList)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_ExpressionList_o' doesn't match C-type size '%d'", corto_type(parser_ExpressionList_o)->size, sizeof(parser_ExpressionList));
    }

    if (!corto_checkState(parser_CommaExpressionNode_expressions_o, CORTO_DEFINED)) {
        parser_CommaExpressionNode_expressions_o->type = corto_type(corto_resolve(NULL, "/corto/parser/ExpressionList"));
        parser_CommaExpressionNode_expressions_o->modifiers = 0x0;
        parser_CommaExpressionNode_expressions_o->state = 0x6;
        parser_CommaExpressionNode_expressions_o->weak = FALSE;
        parser_CommaExpressionNode_expressions_o->id = 0;
        if (corto_define(parser_CommaExpressionNode_expressions_o)) {
            corto_error("parser_load: failed to define 'parser_CommaExpressionNode_expressions_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_ExpressionStatementNode_o = corto_class(corto_declareChild(corto_parser_o, "ExpressionStatementNode", corto_class_o));
    if (!parser_ExpressionStatementNode_o) {
        corto_error("parser_load: failed to declare 'parser_ExpressionStatementNode_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_ExpressionStatementNode_expression_o = corto_member(corto_declareChild(parser_ExpressionStatementNode_o, "expression", corto_member_o));
    if (!parser_ExpressionStatementNode_expression_o) {
        corto_error("parser_load: failed to declare 'parser_ExpressionStatementNode_expression_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_Node_o = corto_class(corto_declareChild(corto_parser_o, "Node", corto_class_o));
    if (!parser_Node_o) {
        corto_error("parser_load: failed to declare 'parser_Node_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_Node_column_o = corto_member(corto_declareChild(parser_Node_o, "column", corto_member_o));
    if (!parser_Node_column_o) {
        corto_error("parser_load: failed to declare 'parser_Node_column_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_Node_column_o, CORTO_DEFINED)) {
        parser_Node_column_o->type = corto_type(corto_resolve(NULL, "uint32"));
        parser_Node_column_o->modifiers = 0x0;
        parser_Node_column_o->state = 0x6;
        parser_Node_column_o->weak = FALSE;
        parser_Node_column_o->id = 1;
        if (corto_define(parser_Node_column_o)) {
            corto_error("parser_load: failed to define 'parser_Node_column_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_Node_line_o = corto_member(corto_declareChild(parser_Node_o, "line", corto_member_o));
    if (!parser_Node_line_o) {
        corto_error("parser_load: failed to declare 'parser_Node_line_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_Node_line_o, CORTO_DEFINED)) {
        parser_Node_line_o->type = corto_type(corto_resolve(NULL, "uint32"));
        parser_Node_line_o->modifiers = 0x0;
        parser_Node_line_o->state = 0x6;
        parser_Node_line_o->weak = FALSE;
        parser_Node_line_o->id = 0;
        if (corto_define(parser_Node_line_o)) {
            corto_error("parser_load: failed to define 'parser_Node_line_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_Node_o, CORTO_DEFINED)) {
        ((corto_type)parser_Node_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_Node_o)->reference = TRUE;
        ((corto_type)parser_Node_o)->parentType = NULL;
        ((corto_type)parser_Node_o)->parentState = 0x6;
        ((corto_type)parser_Node_o)->defaultType = NULL;
        ((corto_type)parser_Node_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_Node_o)->base = NULL;
        ((corto_struct)parser_Node_o)->baseAccess = 0x0;
        parser_Node_o->implements.length = 0;
        parser_Node_o->implements.buffer = NULL;
        if (corto_define(parser_Node_o)) {
            corto_error("parser_load: failed to define 'parser_Node_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_Node_o)->size != sizeof(struct parser_Node_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_Node_o' doesn't match C-type size '%d'", corto_type(parser_Node_o)->size, sizeof(struct parser_Node_s));
    }

    if (!corto_checkState(parser_ExpressionNode_o, CORTO_DEFINED)) {
        ((corto_type)parser_ExpressionNode_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_ExpressionNode_o)->reference = TRUE;
        ((corto_type)parser_ExpressionNode_o)->parentType = NULL;
        ((corto_type)parser_ExpressionNode_o)->parentState = 0x6;
        ((corto_type)parser_ExpressionNode_o)->defaultType = NULL;
        ((corto_type)parser_ExpressionNode_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_ExpressionNode_o)->base = corto_interface(corto_resolve(NULL, "/corto/parser/Node"));
        ((corto_struct)parser_ExpressionNode_o)->baseAccess = 0x0;
        parser_ExpressionNode_o->implements.length = 0;
        parser_ExpressionNode_o->implements.buffer = NULL;
        if (corto_define(parser_ExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_ExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_ExpressionNode_o)->size != sizeof(struct parser_ExpressionNode_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_ExpressionNode_o' doesn't match C-type size '%d'", corto_type(parser_ExpressionNode_o)->size, sizeof(struct parser_ExpressionNode_s));
    }

    parser_BaseVisitor_visitExpressionNode_o = corto_virtual(corto_declareChild(parser_BaseVisitor_o, "visitExpressionNode(/corto/parser/ExpressionNode node)", corto_virtual_o));
    if (!parser_BaseVisitor_visitExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_visitExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_visitExpressionNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_visitExpressionNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_BaseVisitor_visitExpressionNode_o)->returnsReference = FALSE;
        ((corto_method)parser_BaseVisitor_visitExpressionNode_o)->_virtual = TRUE;
        
        corto_function(parser_BaseVisitor_visitExpressionNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_visitExpressionNode_v(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_visitExpressionNode_o)->impl = (corto_word)__parser_BaseVisitor_visitExpressionNode_v;
        if (corto_define(parser_BaseVisitor_visitExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_visitExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_BinaryExpressionNode_left_o, CORTO_DEFINED)) {
        parser_BinaryExpressionNode_left_o->type = corto_type(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        parser_BinaryExpressionNode_left_o->modifiers = 0x0;
        parser_BinaryExpressionNode_left_o->state = 0x6;
        parser_BinaryExpressionNode_left_o->weak = FALSE;
        parser_BinaryExpressionNode_left_o->id = 0;
        if (corto_define(parser_BinaryExpressionNode_left_o)) {
            corto_error("parser_load: failed to define 'parser_BinaryExpressionNode_left_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_BinaryExpressionNode_right_o, CORTO_DEFINED)) {
        parser_BinaryExpressionNode_right_o->type = corto_type(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        parser_BinaryExpressionNode_right_o->modifiers = 0x0;
        parser_BinaryExpressionNode_right_o->state = 0x6;
        parser_BinaryExpressionNode_right_o->weak = FALSE;
        parser_BinaryExpressionNode_right_o->id = 2;
        if (corto_define(parser_BinaryExpressionNode_right_o)) {
            corto_error("parser_load: failed to define 'parser_BinaryExpressionNode_right_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_BinaryExpressionNode_o, CORTO_DEFINED)) {
        ((corto_type)parser_BinaryExpressionNode_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_BinaryExpressionNode_o)->reference = TRUE;
        ((corto_type)parser_BinaryExpressionNode_o)->parentType = NULL;
        ((corto_type)parser_BinaryExpressionNode_o)->parentState = 0x6;
        ((corto_type)parser_BinaryExpressionNode_o)->defaultType = NULL;
        ((corto_type)parser_BinaryExpressionNode_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_BinaryExpressionNode_o)->base = corto_interface(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        ((corto_struct)parser_BinaryExpressionNode_o)->baseAccess = 0x0;
        parser_BinaryExpressionNode_o->implements.length = 0;
        parser_BinaryExpressionNode_o->implements.buffer = NULL;
        if (corto_define(parser_BinaryExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_BinaryExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_BinaryExpressionNode_o)->size != sizeof(struct parser_BinaryExpressionNode_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_BinaryExpressionNode_o' doesn't match C-type size '%d'", corto_type(parser_BinaryExpressionNode_o)->size, sizeof(struct parser_BinaryExpressionNode_s));
    }

    parser_BaseVisitor_visitBinaryExpressionNode_o = corto_virtual(corto_declareChild(parser_BaseVisitor_o, "visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)", corto_virtual_o));
    if (!parser_BaseVisitor_visitBinaryExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_visitBinaryExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_visitBinaryExpressionNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_visitBinaryExpressionNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_BaseVisitor_visitBinaryExpressionNode_o)->returnsReference = FALSE;
        ((corto_method)parser_BaseVisitor_visitBinaryExpressionNode_o)->_virtual = TRUE;
        
        corto_function(parser_BaseVisitor_visitBinaryExpressionNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_visitBinaryExpressionNode_v(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_visitBinaryExpressionNode_o)->impl = (corto_word)__parser_BaseVisitor_visitBinaryExpressionNode_v;
        if (corto_define(parser_BaseVisitor_visitBinaryExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_visitBinaryExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_CommaExpressionNode_o, CORTO_DEFINED)) {
        ((corto_type)parser_CommaExpressionNode_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_CommaExpressionNode_o)->reference = TRUE;
        ((corto_type)parser_CommaExpressionNode_o)->parentType = NULL;
        ((corto_type)parser_CommaExpressionNode_o)->parentState = 0x6;
        ((corto_type)parser_CommaExpressionNode_o)->defaultType = NULL;
        ((corto_type)parser_CommaExpressionNode_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_CommaExpressionNode_o)->base = corto_interface(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        ((corto_struct)parser_CommaExpressionNode_o)->baseAccess = 0x0;
        parser_CommaExpressionNode_o->implements.length = 0;
        parser_CommaExpressionNode_o->implements.buffer = NULL;
        if (corto_define(parser_CommaExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_CommaExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_CommaExpressionNode_o)->size != sizeof(struct parser_CommaExpressionNode_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_CommaExpressionNode_o' doesn't match C-type size '%d'", corto_type(parser_CommaExpressionNode_o)->size, sizeof(struct parser_CommaExpressionNode_s));
    }

    parser_BaseVisitor_visitCommaExpressionNode_o = corto_virtual(corto_declareChild(parser_BaseVisitor_o, "visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)", corto_virtual_o));
    if (!parser_BaseVisitor_visitCommaExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_visitCommaExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_visitCommaExpressionNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_visitCommaExpressionNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_BaseVisitor_visitCommaExpressionNode_o)->returnsReference = FALSE;
        ((corto_method)parser_BaseVisitor_visitCommaExpressionNode_o)->_virtual = TRUE;
        
        corto_function(parser_BaseVisitor_visitCommaExpressionNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_visitCommaExpressionNode_v(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_visitCommaExpressionNode_o)->impl = (corto_word)__parser_BaseVisitor_visitCommaExpressionNode_v;
        if (corto_define(parser_BaseVisitor_visitCommaExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_visitCommaExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_ConditionalExpressionNode_condition_o, CORTO_DEFINED)) {
        parser_ConditionalExpressionNode_condition_o->type = corto_type(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        parser_ConditionalExpressionNode_condition_o->modifiers = 0x0;
        parser_ConditionalExpressionNode_condition_o->state = 0x6;
        parser_ConditionalExpressionNode_condition_o->weak = FALSE;
        parser_ConditionalExpressionNode_condition_o->id = 0;
        if (corto_define(parser_ConditionalExpressionNode_condition_o)) {
            corto_error("parser_load: failed to define 'parser_ConditionalExpressionNode_condition_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_ConditionalExpressionNode_falseValue_o, CORTO_DEFINED)) {
        parser_ConditionalExpressionNode_falseValue_o->type = corto_type(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        parser_ConditionalExpressionNode_falseValue_o->modifiers = 0x0;
        parser_ConditionalExpressionNode_falseValue_o->state = 0x6;
        parser_ConditionalExpressionNode_falseValue_o->weak = FALSE;
        parser_ConditionalExpressionNode_falseValue_o->id = 2;
        if (corto_define(parser_ConditionalExpressionNode_falseValue_o)) {
            corto_error("parser_load: failed to define 'parser_ConditionalExpressionNode_falseValue_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_ConditionalExpressionNode_trueValue_o, CORTO_DEFINED)) {
        parser_ConditionalExpressionNode_trueValue_o->type = corto_type(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        parser_ConditionalExpressionNode_trueValue_o->modifiers = 0x0;
        parser_ConditionalExpressionNode_trueValue_o->state = 0x6;
        parser_ConditionalExpressionNode_trueValue_o->weak = FALSE;
        parser_ConditionalExpressionNode_trueValue_o->id = 1;
        if (corto_define(parser_ConditionalExpressionNode_trueValue_o)) {
            corto_error("parser_load: failed to define 'parser_ConditionalExpressionNode_trueValue_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_ConditionalExpressionNode_o, CORTO_DEFINED)) {
        ((corto_type)parser_ConditionalExpressionNode_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_ConditionalExpressionNode_o)->reference = TRUE;
        ((corto_type)parser_ConditionalExpressionNode_o)->parentType = NULL;
        ((corto_type)parser_ConditionalExpressionNode_o)->parentState = 0x6;
        ((corto_type)parser_ConditionalExpressionNode_o)->defaultType = NULL;
        ((corto_type)parser_ConditionalExpressionNode_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_ConditionalExpressionNode_o)->base = corto_interface(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        ((corto_struct)parser_ConditionalExpressionNode_o)->baseAccess = 0x0;
        parser_ConditionalExpressionNode_o->implements.length = 0;
        parser_ConditionalExpressionNode_o->implements.buffer = NULL;
        if (corto_define(parser_ConditionalExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_ConditionalExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_ConditionalExpressionNode_o)->size != sizeof(struct parser_ConditionalExpressionNode_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_ConditionalExpressionNode_o' doesn't match C-type size '%d'", corto_type(parser_ConditionalExpressionNode_o)->size, sizeof(struct parser_ConditionalExpressionNode_s));
    }

    parser_BaseVisitor_visitConditionalExpressionNode_o = corto_virtual(corto_declareChild(parser_BaseVisitor_o, "visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)", corto_virtual_o));
    if (!parser_BaseVisitor_visitConditionalExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_visitConditionalExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_visitConditionalExpressionNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_visitConditionalExpressionNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_BaseVisitor_visitConditionalExpressionNode_o)->returnsReference = FALSE;
        ((corto_method)parser_BaseVisitor_visitConditionalExpressionNode_o)->_virtual = TRUE;
        
        corto_function(parser_BaseVisitor_visitConditionalExpressionNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_visitConditionalExpressionNode_v(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_visitConditionalExpressionNode_o)->impl = (corto_word)__parser_BaseVisitor_visitConditionalExpressionNode_v;
        if (corto_define(parser_BaseVisitor_visitConditionalExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_visitConditionalExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_ExpressionStatementNode_expression_o, CORTO_DEFINED)) {
        parser_ExpressionStatementNode_expression_o->type = corto_type(corto_resolve(NULL, "/corto/parser/ExpressionNode"));
        parser_ExpressionStatementNode_expression_o->modifiers = 0x0;
        parser_ExpressionStatementNode_expression_o->state = 0x6;
        parser_ExpressionStatementNode_expression_o->weak = FALSE;
        parser_ExpressionStatementNode_expression_o->id = 0;
        if (corto_define(parser_ExpressionStatementNode_expression_o)) {
            corto_error("parser_load: failed to define 'parser_ExpressionStatementNode_expression_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_StatementNode_o = corto_class(corto_declareChild(corto_parser_o, "StatementNode", corto_class_o));
    if (!parser_StatementNode_o) {
        corto_error("parser_load: failed to declare 'parser_StatementNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_StatementNode_o, CORTO_DEFINED)) {
        ((corto_type)parser_StatementNode_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_StatementNode_o)->reference = TRUE;
        ((corto_type)parser_StatementNode_o)->parentType = NULL;
        ((corto_type)parser_StatementNode_o)->parentState = 0x6;
        ((corto_type)parser_StatementNode_o)->defaultType = NULL;
        ((corto_type)parser_StatementNode_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_StatementNode_o)->base = corto_interface(corto_resolve(NULL, "/corto/parser/Node"));
        ((corto_struct)parser_StatementNode_o)->baseAccess = 0x0;
        parser_StatementNode_o->implements.length = 0;
        parser_StatementNode_o->implements.buffer = NULL;
        if (corto_define(parser_StatementNode_o)) {
            corto_error("parser_load: failed to define 'parser_StatementNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_StatementNode_o)->size != sizeof(struct parser_StatementNode_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_StatementNode_o' doesn't match C-type size '%d'", corto_type(parser_StatementNode_o)->size, sizeof(struct parser_StatementNode_s));
    }

    parser_BaseVisitor_visitStatementNode_o = corto_virtual(corto_declareChild(parser_BaseVisitor_o, "visitStatementNode(/corto/parser/StatementNode node)", corto_virtual_o));
    if (!parser_BaseVisitor_visitStatementNode_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_visitStatementNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_visitStatementNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_visitStatementNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_BaseVisitor_visitStatementNode_o)->returnsReference = FALSE;
        ((corto_method)parser_BaseVisitor_visitStatementNode_o)->_virtual = TRUE;
        
        corto_function(parser_BaseVisitor_visitStatementNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_visitStatementNode_v(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_visitStatementNode_o)->impl = (corto_word)__parser_BaseVisitor_visitStatementNode_v;
        if (corto_define(parser_BaseVisitor_visitStatementNode_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_visitStatementNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_ExpressionStatementNode_o, CORTO_DEFINED)) {
        ((corto_type)parser_ExpressionStatementNode_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_ExpressionStatementNode_o)->reference = TRUE;
        ((corto_type)parser_ExpressionStatementNode_o)->parentType = NULL;
        ((corto_type)parser_ExpressionStatementNode_o)->parentState = 0x6;
        ((corto_type)parser_ExpressionStatementNode_o)->defaultType = NULL;
        ((corto_type)parser_ExpressionStatementNode_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_ExpressionStatementNode_o)->base = corto_interface(corto_resolve(NULL, "/corto/parser/StatementNode"));
        ((corto_struct)parser_ExpressionStatementNode_o)->baseAccess = 0x0;
        parser_ExpressionStatementNode_o->implements.length = 0;
        parser_ExpressionStatementNode_o->implements.buffer = NULL;
        if (corto_define(parser_ExpressionStatementNode_o)) {
            corto_error("parser_load: failed to define 'parser_ExpressionStatementNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_ExpressionStatementNode_o)->size != sizeof(struct parser_ExpressionStatementNode_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_ExpressionStatementNode_o' doesn't match C-type size '%d'", corto_type(parser_ExpressionStatementNode_o)->size, sizeof(struct parser_ExpressionStatementNode_s));
    }

    parser_BaseVisitor_visitExpressionStatementNode_o = corto_virtual(corto_declareChild(parser_BaseVisitor_o, "visitExpressionStatementNode(/corto/parser/ExpressionStatementNode node)", corto_virtual_o));
    if (!parser_BaseVisitor_visitExpressionStatementNode_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_visitExpressionStatementNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_visitExpressionStatementNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_visitExpressionStatementNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_BaseVisitor_visitExpressionStatementNode_o)->returnsReference = FALSE;
        ((corto_method)parser_BaseVisitor_visitExpressionStatementNode_o)->_virtual = TRUE;
        
        corto_function(parser_BaseVisitor_visitExpressionStatementNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_visitExpressionStatementNode_v(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_visitExpressionStatementNode_o)->impl = (corto_word)__parser_BaseVisitor_visitExpressionStatementNode_v;
        if (corto_define(parser_BaseVisitor_visitExpressionStatementNode_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_visitExpressionStatementNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_StatementList_o = corto_list(corto_declareChild(corto_parser_o, "StatementList", corto_list_o));
    if (!parser_StatementList_o) {
        corto_error("parser_load: failed to declare 'parser_StatementList_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_StatementList_o, CORTO_DEFINED)) {
        ((corto_collection)parser_StatementList_o)->elementType = corto_type(corto_resolve(NULL, "/corto/parser/StatementNode"));
        ((corto_collection)parser_StatementList_o)->max = 0;
        if (corto_define(parser_StatementList_o)) {
            corto_error("parser_load: failed to define 'parser_StatementList_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_StatementList_o)->size != sizeof(parser_StatementList)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_StatementList_o' doesn't match C-type size '%d'", corto_type(parser_StatementList_o)->size, sizeof(parser_StatementList));
    }

    parser_PrintVisitor_o = corto_class(corto_declareChild(corto_parser_o, "PrintVisitor", corto_class_o));
    if (!parser_PrintVisitor_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_PrintVisitor_buffer_o = corto_member(corto_declareChild(parser_PrintVisitor_o, "buffer", corto_member_o));
    if (!parser_PrintVisitor_buffer_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_buffer_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_buffer_o, CORTO_DEFINED)) {
        parser_PrintVisitor_buffer_o->type = corto_type(corto_resolve(NULL, "word"));
        parser_PrintVisitor_buffer_o->modifiers = 0x2;
        parser_PrintVisitor_buffer_o->state = 0x6;
        parser_PrintVisitor_buffer_o->weak = FALSE;
        parser_PrintVisitor_buffer_o->id = 0;
        if (corto_define(parser_PrintVisitor_buffer_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_buffer_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_PrintVisitor_level_o = corto_member(corto_declareChild(parser_PrintVisitor_o, "level", corto_member_o));
    if (!parser_PrintVisitor_level_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_level_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_level_o, CORTO_DEFINED)) {
        parser_PrintVisitor_level_o->type = corto_type(corto_resolve(NULL, "uint32"));
        parser_PrintVisitor_level_o->modifiers = 0x2;
        parser_PrintVisitor_level_o->state = 0x6;
        parser_PrintVisitor_level_o->weak = FALSE;
        parser_PrintVisitor_level_o->id = 1;
        if (corto_define(parser_PrintVisitor_level_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_level_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_ProgramNode_o = corto_class(corto_declareChild(corto_parser_o, "ProgramNode", corto_class_o));
    if (!parser_ProgramNode_o) {
        corto_error("parser_load: failed to declare 'parser_ProgramNode_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_ProgramNode_statements_o = corto_member(corto_declareChild(parser_ProgramNode_o, "statements", corto_member_o));
    if (!parser_ProgramNode_statements_o) {
        corto_error("parser_load: failed to declare 'parser_ProgramNode_statements_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_ProgramNode_statements_o, CORTO_DEFINED)) {
        parser_ProgramNode_statements_o->type = corto_type(corto_resolve(NULL, "/corto/parser/StatementList"));
        parser_ProgramNode_statements_o->modifiers = 0x0;
        parser_ProgramNode_statements_o->state = 0x6;
        parser_ProgramNode_statements_o->weak = FALSE;
        parser_ProgramNode_statements_o->id = 0;
        if (corto_define(parser_ProgramNode_statements_o)) {
            corto_error("parser_load: failed to define 'parser_ProgramNode_statements_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_ProgramNode_o, CORTO_DEFINED)) {
        ((corto_type)parser_ProgramNode_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_ProgramNode_o)->reference = TRUE;
        ((corto_type)parser_ProgramNode_o)->parentType = NULL;
        ((corto_type)parser_ProgramNode_o)->parentState = 0x6;
        ((corto_type)parser_ProgramNode_o)->defaultType = NULL;
        ((corto_type)parser_ProgramNode_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_ProgramNode_o)->base = corto_interface(corto_resolve(NULL, "/corto/parser/Node"));
        ((corto_struct)parser_ProgramNode_o)->baseAccess = 0x0;
        parser_ProgramNode_o->implements.length = 0;
        parser_ProgramNode_o->implements.buffer = NULL;
        if (corto_define(parser_ProgramNode_o)) {
            corto_error("parser_load: failed to define 'parser_ProgramNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_ProgramNode_o)->size != sizeof(struct parser_ProgramNode_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_ProgramNode_o' doesn't match C-type size '%d'", corto_type(parser_ProgramNode_o)->size, sizeof(struct parser_ProgramNode_s));
    }

    if (!corto_checkState(parser_BaseParser_programReturn_o, CORTO_DEFINED)) {
        parser_BaseParser_programReturn_o->type = corto_type(corto_resolve(NULL, "/corto/parser/ProgramNode"));
        parser_BaseParser_programReturn_o->modifiers = 0x4;
        parser_BaseParser_programReturn_o->state = 0x6;
        parser_BaseParser_programReturn_o->weak = FALSE;
        parser_BaseParser_programReturn_o->id = 1;
        if (corto_define(parser_BaseParser_programReturn_o)) {
            corto_error("parser_load: failed to define 'parser_BaseParser_programReturn_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_BaseParser_o, CORTO_DEFINED)) {
        ((corto_type)parser_BaseParser_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_BaseParser_o)->reference = TRUE;
        ((corto_type)parser_BaseParser_o)->parentType = NULL;
        ((corto_type)parser_BaseParser_o)->parentState = 0x6;
        ((corto_type)parser_BaseParser_o)->defaultType = NULL;
        ((corto_type)parser_BaseParser_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_BaseParser_o)->base = NULL;
        ((corto_struct)parser_BaseParser_o)->baseAccess = 0x0;
        parser_BaseParser_o->implements.length = 0;
        parser_BaseParser_o->implements.buffer = NULL;
        if (corto_define(parser_BaseParser_o)) {
            corto_error("parser_load: failed to define 'parser_BaseParser_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_BaseParser_o)->size != sizeof(struct parser_BaseParser_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_BaseParser_o' doesn't match C-type size '%d'", corto_type(parser_BaseParser_o)->size, sizeof(struct parser_BaseParser_s));
    }

    if (!corto_checkState(parser_BaseVisitor_parser_o, CORTO_DEFINED)) {
        parser_BaseVisitor_parser_o->type = corto_type(corto_resolve(NULL, "/corto/parser/BaseParser"));
        parser_BaseVisitor_parser_o->modifiers = 0x0;
        parser_BaseVisitor_parser_o->state = 0x6;
        parser_BaseVisitor_parser_o->weak = FALSE;
        parser_BaseVisitor_parser_o->id = 0;
        if (corto_define(parser_BaseVisitor_parser_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_parser_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_BaseVisitor_visitProgramNode_o = corto_virtual(corto_declareChild(parser_BaseVisitor_o, "visitProgramNode(/corto/parser/ProgramNode node)", corto_virtual_o));
    if (!parser_BaseVisitor_visitProgramNode_o) {
        corto_error("parser_load: failed to declare 'parser_BaseVisitor_visitProgramNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_BaseVisitor_visitProgramNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_BaseVisitor_visitProgramNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_BaseVisitor_visitProgramNode_o)->returnsReference = FALSE;
        ((corto_method)parser_BaseVisitor_visitProgramNode_o)->_virtual = TRUE;
        
        corto_function(parser_BaseVisitor_visitProgramNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_BaseVisitor_visitProgramNode_v(corto_function f, void *args, void *result);
        corto_function(parser_BaseVisitor_visitProgramNode_o)->impl = (corto_word)__parser_BaseVisitor_visitProgramNode_v;
        if (corto_define(parser_BaseVisitor_visitProgramNode_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_visitProgramNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_BaseVisitor_o, CORTO_DEFINED)) {
        ((corto_type)parser_BaseVisitor_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_BaseVisitor_o)->reference = TRUE;
        ((corto_type)parser_BaseVisitor_o)->parentType = NULL;
        ((corto_type)parser_BaseVisitor_o)->parentState = 0x6;
        ((corto_type)parser_BaseVisitor_o)->defaultType = NULL;
        ((corto_type)parser_BaseVisitor_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_BaseVisitor_o)->base = NULL;
        ((corto_struct)parser_BaseVisitor_o)->baseAccess = 0x0;
        parser_BaseVisitor_o->implements.length = 0;
        parser_BaseVisitor_o->implements.buffer = NULL;
        if (corto_define(parser_BaseVisitor_o)) {
            corto_error("parser_load: failed to define 'parser_BaseVisitor_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_BaseVisitor_o)->size != sizeof(struct parser_BaseVisitor_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_BaseVisitor_o' doesn't match C-type size '%d'", corto_type(parser_BaseVisitor_o)->size, sizeof(struct parser_BaseVisitor_s));
    }

    parser_PrintVisitor_construct_o = corto_method(corto_declareChild(parser_PrintVisitor_o, "construct()", corto_method_o));
    if (!parser_PrintVisitor_construct_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_construct_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_construct_o, CORTO_DEFINED)) {
        ((corto_function)parser_PrintVisitor_construct_o)->returnType = corto_type(corto_resolve(NULL, "int16"));
        ((corto_function)parser_PrintVisitor_construct_o)->returnsReference = FALSE;
        parser_PrintVisitor_construct_o->_virtual = FALSE;
        
        corto_function(parser_PrintVisitor_construct_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_PrintVisitor_construct(corto_function f, void *args, void *result);
        corto_function(parser_PrintVisitor_construct_o)->impl = (corto_word)__parser_PrintVisitor_construct;
        if (corto_define(parser_PrintVisitor_construct_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_construct_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_PrintVisitor_destruct_o = corto_method(corto_declareChild(parser_PrintVisitor_o, "destruct()", corto_method_o));
    if (!parser_PrintVisitor_destruct_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_destruct_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_destruct_o, CORTO_DEFINED)) {
        ((corto_function)parser_PrintVisitor_destruct_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)parser_PrintVisitor_destruct_o)->returnsReference = FALSE;
        parser_PrintVisitor_destruct_o->_virtual = FALSE;
        
        corto_function(parser_PrintVisitor_destruct_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_PrintVisitor_destruct(corto_function f, void *args, void *result);
        corto_function(parser_PrintVisitor_destruct_o)->impl = (corto_word)__parser_PrintVisitor_destruct;
        if (corto_define(parser_PrintVisitor_destruct_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_destruct_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_PrintVisitor_getText_o = corto_method(corto_declareChild(parser_PrintVisitor_o, "getText()", corto_method_o));
    if (!parser_PrintVisitor_getText_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_getText_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_getText_o, CORTO_DEFINED)) {
        ((corto_function)parser_PrintVisitor_getText_o)->returnType = corto_type(corto_resolve(NULL, "string"));
        ((corto_function)parser_PrintVisitor_getText_o)->returnsReference = FALSE;
        parser_PrintVisitor_getText_o->_virtual = FALSE;
        
        corto_function(parser_PrintVisitor_getText_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_PrintVisitor_getText(corto_function f, void *args, void *result);
        corto_function(parser_PrintVisitor_getText_o)->impl = (corto_word)__parser_PrintVisitor_getText;
        if (corto_define(parser_PrintVisitor_getText_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_getText_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_PrintVisitor_visitBinaryExpressionNode_o = corto_virtual(corto_declareChild(parser_PrintVisitor_o, "visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)", corto_virtual_o));
    if (!parser_PrintVisitor_visitBinaryExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_visitBinaryExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_visitBinaryExpressionNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_PrintVisitor_visitBinaryExpressionNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_PrintVisitor_visitBinaryExpressionNode_o)->returnsReference = FALSE;
        ((corto_method)parser_PrintVisitor_visitBinaryExpressionNode_o)->_virtual = TRUE;
        
        corto_function(parser_PrintVisitor_visitBinaryExpressionNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_PrintVisitor_visitBinaryExpressionNode_v(corto_function f, void *args, void *result);
        corto_function(parser_PrintVisitor_visitBinaryExpressionNode_o)->impl = (corto_word)__parser_PrintVisitor_visitBinaryExpressionNode_v;
        if (corto_define(parser_PrintVisitor_visitBinaryExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_visitBinaryExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_PrintVisitor_visitCommaExpressionNode_o = corto_virtual(corto_declareChild(parser_PrintVisitor_o, "visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)", corto_virtual_o));
    if (!parser_PrintVisitor_visitCommaExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_visitCommaExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_visitCommaExpressionNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_PrintVisitor_visitCommaExpressionNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_PrintVisitor_visitCommaExpressionNode_o)->returnsReference = FALSE;
        ((corto_method)parser_PrintVisitor_visitCommaExpressionNode_o)->_virtual = TRUE;
        
        corto_function(parser_PrintVisitor_visitCommaExpressionNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_PrintVisitor_visitCommaExpressionNode_v(corto_function f, void *args, void *result);
        corto_function(parser_PrintVisitor_visitCommaExpressionNode_o)->impl = (corto_word)__parser_PrintVisitor_visitCommaExpressionNode_v;
        if (corto_define(parser_PrintVisitor_visitCommaExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_visitCommaExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_PrintVisitor_visitConditionalExpressionNode_o = corto_virtual(corto_declareChild(parser_PrintVisitor_o, "visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)", corto_virtual_o));
    if (!parser_PrintVisitor_visitConditionalExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_visitConditionalExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_visitConditionalExpressionNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_PrintVisitor_visitConditionalExpressionNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_PrintVisitor_visitConditionalExpressionNode_o)->returnsReference = FALSE;
        ((corto_method)parser_PrintVisitor_visitConditionalExpressionNode_o)->_virtual = TRUE;
        
        corto_function(parser_PrintVisitor_visitConditionalExpressionNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_PrintVisitor_visitConditionalExpressionNode_v(corto_function f, void *args, void *result);
        corto_function(parser_PrintVisitor_visitConditionalExpressionNode_o)->impl = (corto_word)__parser_PrintVisitor_visitConditionalExpressionNode_v;
        if (corto_define(parser_PrintVisitor_visitConditionalExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_visitConditionalExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_PrintVisitor_visitExpressionNode_o = corto_virtual(corto_declareChild(parser_PrintVisitor_o, "visitExpressionNode(/corto/parser/ExpressionNode node)", corto_virtual_o));
    if (!parser_PrintVisitor_visitExpressionNode_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_visitExpressionNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_visitExpressionNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_PrintVisitor_visitExpressionNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_PrintVisitor_visitExpressionNode_o)->returnsReference = FALSE;
        ((corto_method)parser_PrintVisitor_visitExpressionNode_o)->_virtual = TRUE;
        
        corto_function(parser_PrintVisitor_visitExpressionNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_PrintVisitor_visitExpressionNode_v(corto_function f, void *args, void *result);
        corto_function(parser_PrintVisitor_visitExpressionNode_o)->impl = (corto_word)__parser_PrintVisitor_visitExpressionNode_v;
        if (corto_define(parser_PrintVisitor_visitExpressionNode_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_visitExpressionNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_PrintVisitor_visitProgramNode_o = corto_virtual(corto_declareChild(parser_PrintVisitor_o, "visitProgramNode(/corto/parser/ProgramNode node)", corto_virtual_o));
    if (!parser_PrintVisitor_visitProgramNode_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_visitProgramNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_visitProgramNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_PrintVisitor_visitProgramNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_PrintVisitor_visitProgramNode_o)->returnsReference = FALSE;
        ((corto_method)parser_PrintVisitor_visitProgramNode_o)->_virtual = TRUE;
        
        corto_function(parser_PrintVisitor_visitProgramNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_PrintVisitor_visitProgramNode_v(corto_function f, void *args, void *result);
        corto_function(parser_PrintVisitor_visitProgramNode_o)->impl = (corto_word)__parser_PrintVisitor_visitProgramNode_v;
        if (corto_define(parser_PrintVisitor_visitProgramNode_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_visitProgramNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_PrintVisitor_visitStatementNode_o = corto_virtual(corto_declareChild(parser_PrintVisitor_o, "visitStatementNode(/corto/parser/StatementNode node)", corto_virtual_o));
    if (!parser_PrintVisitor_visitStatementNode_o) {
        corto_error("parser_load: failed to declare 'parser_PrintVisitor_visitStatementNode_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_PrintVisitor_visitStatementNode_o, CORTO_DEFINED)) {
        ((corto_function)parser_PrintVisitor_visitStatementNode_o)->returnType = corto_type(corto_resolve(NULL, "object"));
        ((corto_function)parser_PrintVisitor_visitStatementNode_o)->returnsReference = FALSE;
        ((corto_method)parser_PrintVisitor_visitStatementNode_o)->_virtual = TRUE;
        
        corto_function(parser_PrintVisitor_visitStatementNode_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_PrintVisitor_visitStatementNode_v(corto_function f, void *args, void *result);
        corto_function(parser_PrintVisitor_visitStatementNode_o)->impl = (corto_word)__parser_PrintVisitor_visitStatementNode_v;
        if (corto_define(parser_PrintVisitor_visitStatementNode_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_visitStatementNode_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_PrintVisitor_o, CORTO_DEFINED)) {
        ((corto_type)parser_PrintVisitor_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_PrintVisitor_o)->reference = TRUE;
        ((corto_type)parser_PrintVisitor_o)->parentType = NULL;
        ((corto_type)parser_PrintVisitor_o)->parentState = 0x6;
        ((corto_type)parser_PrintVisitor_o)->defaultType = NULL;
        ((corto_type)parser_PrintVisitor_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_PrintVisitor_o)->base = corto_interface(corto_resolve(NULL, "/corto/parser/BaseVisitor"));
        ((corto_struct)parser_PrintVisitor_o)->baseAccess = 0x0;
        parser_PrintVisitor_o->implements.length = 0;
        parser_PrintVisitor_o->implements.buffer = NULL;
        if (corto_define(parser_PrintVisitor_o)) {
            corto_error("parser_load: failed to define 'parser_PrintVisitor_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_PrintVisitor_o)->size != sizeof(struct parser_PrintVisitor_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_PrintVisitor_o' doesn't match C-type size '%d'", corto_type(parser_PrintVisitor_o)->size, sizeof(struct parser_PrintVisitor_s));
    }

    parser_SimpleParser_o = corto_class(corto_declareChild(corto_parser_o, "SimpleParser", corto_class_o));
    if (!parser_SimpleParser_o) {
        corto_error("parser_load: failed to declare 'parser_SimpleParser_o' (%s)", corto_lasterr());
        goto error;
    }

    parser_SimpleParser_displayRecognitionError_o = corto_method(corto_declareChild(parser_SimpleParser_o, "displayRecognitionError(word recognizer,word tokenNames)", corto_method_o));
    if (!parser_SimpleParser_displayRecognitionError_o) {
        corto_error("parser_load: failed to declare 'parser_SimpleParser_displayRecognitionError_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(parser_SimpleParser_displayRecognitionError_o, CORTO_DEFINED)) {
        ((corto_function)parser_SimpleParser_displayRecognitionError_o)->returnType = corto_type(corto_resolve(NULL, "void"));
        ((corto_function)parser_SimpleParser_displayRecognitionError_o)->returnsReference = FALSE;
        parser_SimpleParser_displayRecognitionError_o->_virtual = FALSE;
        
        corto_function(parser_SimpleParser_displayRecognitionError_o)->kind = CORTO_PROCEDURE_CDECL;
        void __parser_SimpleParser_displayRecognitionError(corto_function f, void *args, void *result);
        corto_function(parser_SimpleParser_displayRecognitionError_o)->impl = (corto_word)__parser_SimpleParser_displayRecognitionError;
        if (corto_define(parser_SimpleParser_displayRecognitionError_o)) {
            corto_error("parser_load: failed to define 'parser_SimpleParser_displayRecognitionError_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    parser_SimpleParser_errors_o = corto_member(corto_declareChild(parser_SimpleParser_o, "errors", corto_member_o));
    if (!parser_SimpleParser_errors_o) {
        corto_error("parser_load: failed to declare 'parser_SimpleParser_errors_o' (%s)", corto_lasterr());
        goto error;
    }

    corto_stringList_o = corto_list(corto_declare(corto_list_o));
    if (!corto_stringList_o) {
        corto_error("parser_load: failed to declare 'corto_stringList_o' (%s)", corto_lasterr());
        goto error;
    }

    if (!corto_checkState(corto_stringList_o, CORTO_DEFINED)) {
        ((corto_collection)corto_stringList_o)->elementType = corto_type(corto_resolve(NULL, "string"));
        ((corto_collection)corto_stringList_o)->max = 0;
        if (corto_define(corto_stringList_o)) {
            corto_error("parser_load: failed to define 'corto_stringList_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(corto_stringList_o)->size != sizeof(corto_stringList)) {
        corto_error("parser_load: calculated size '%d' of type 'corto_stringList_o' doesn't match C-type size '%d'", corto_type(corto_stringList_o)->size, sizeof(corto_stringList));
    }

    if (!corto_checkState(parser_SimpleParser_errors_o, CORTO_DEFINED)) {
        parser_SimpleParser_errors_o->type = corto_type(corto_resolve(NULL, "list{string,0}"));
        parser_SimpleParser_errors_o->modifiers = 0x10;
        parser_SimpleParser_errors_o->state = 0x6;
        parser_SimpleParser_errors_o->weak = FALSE;
        parser_SimpleParser_errors_o->id = 0;
        if (corto_define(parser_SimpleParser_errors_o)) {
            corto_error("parser_load: failed to define 'parser_SimpleParser_errors_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (!corto_checkState(parser_SimpleParser_o, CORTO_DEFINED)) {
        ((corto_type)parser_SimpleParser_o)->kind = CORTO_COMPOSITE;
        ((corto_type)parser_SimpleParser_o)->reference = TRUE;
        ((corto_type)parser_SimpleParser_o)->parentType = NULL;
        ((corto_type)parser_SimpleParser_o)->parentState = 0x6;
        ((corto_type)parser_SimpleParser_o)->defaultType = NULL;
        ((corto_type)parser_SimpleParser_o)->defaultProcedureType = NULL;
        ((corto_interface)parser_SimpleParser_o)->base = corto_interface(corto_resolve(NULL, "/corto/parser/BaseParser"));
        ((corto_struct)parser_SimpleParser_o)->baseAccess = 0x0;
        parser_SimpleParser_o->implements.length = 0;
        parser_SimpleParser_o->implements.buffer = NULL;
        if (corto_define(parser_SimpleParser_o)) {
            corto_error("parser_load: failed to define 'parser_SimpleParser_o' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(parser_SimpleParser_o)->size != sizeof(struct parser_SimpleParser_s)) {
        corto_error("parser_load: calculated size '%d' of type 'parser_SimpleParser_o' doesn't match C-type size '%d'", corto_type(parser_SimpleParser_o)->size, sizeof(struct parser_SimpleParser_s));
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
