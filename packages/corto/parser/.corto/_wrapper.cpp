/* _wrapper.cpp
 *
 * This file contains wrapper functions for /corto/parser.
 */

#include <corto/parser/parser.h>
#include <corto/parser/_meta.h>

void _parser_BaseParser_displayRecognitionError(
    parser_BaseParser _this,
    corto_word recognizer,
    corto_word tokenNames) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "displayRecognitionError(word recognizer,word tokenNames)");
    }
    corto_assert(_methodId, "virtual 'displayRecognitionError(word recognizer,word tokenNames)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::displayRecognitionError(word recognizer,word tokenNames)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), NULL, _this, recognizer, tokenNames);
}

void __parser_BaseParser_displayRecognitionError_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _parser_BaseParser_displayRecognitionError_v(
        parser_BaseParser(*(parser_BaseParser**)args),
        *(corto_word*)((intptr_t)args + sizeof(parser_BaseParser*)),
        *(corto_word*)((intptr_t)args + sizeof(parser_BaseParser*) + sizeof(corto_word)));
}

void __parser_BaseParser_parse(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _parser_BaseParser_parse(
        parser_BaseParser(*(parser_BaseParser**)args),
        *(corto_string*)((intptr_t)args + sizeof(parser_BaseParser*)));
}

void __parser_BaseParser_parseFile(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_int16*)result = _parser_BaseParser_parseFile(
        parser_BaseParser(*(parser_BaseParser**)args),
        *(corto_string*)((intptr_t)args + sizeof(parser_BaseParser*)));
}

void __parser_BaseVisitor_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _parser_BaseVisitor_construct(
        parser_BaseVisitor(*(parser_BaseVisitor**)args));
}

void __parser_BaseVisitor_destruct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _parser_BaseVisitor_destruct(
        parser_BaseVisitor(*(parser_BaseVisitor**)args));
}

corto_object _parser_BaseVisitor_visit(
    parser_BaseVisitor _this) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visit()");
    }
    corto_assert(_methodId, "virtual 'visit()' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visit()@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this);
    
    return _result;
}

void __parser_BaseVisitor_visit_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_object*)result = _parser_BaseVisitor_visit_v(
        parser_BaseVisitor(*(parser_BaseVisitor**)args));
}

corto_object _parser_BaseVisitor_visitBinaryExpressionNode(
    parser_BaseVisitor _this,
    parser_BinaryExpressionNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)");
    }
    corto_assert(_methodId, "virtual 'visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_BaseVisitor_visitBinaryExpressionNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_BaseVisitor_visitBinaryExpressionNode_v(
        parser_BaseVisitor(*(parser_BaseVisitor**)args),
        parser_BinaryExpressionNode(*(parser_BinaryExpressionNode*)((intptr_t)args + sizeof(parser_BaseVisitor*))));
}

corto_object _parser_BaseVisitor_visitCommaExpressionNode(
    parser_BaseVisitor _this,
    parser_CommaExpressionNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)");
    }
    corto_assert(_methodId, "virtual 'visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_BaseVisitor_visitCommaExpressionNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_BaseVisitor_visitCommaExpressionNode_v(
        parser_BaseVisitor(*(parser_BaseVisitor**)args),
        parser_CommaExpressionNode(*(parser_CommaExpressionNode*)((intptr_t)args + sizeof(parser_BaseVisitor*))));
}

corto_object _parser_BaseVisitor_visitConditionalExpressionNode(
    parser_BaseVisitor _this,
    parser_ConditionalExpressionNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)");
    }
    corto_assert(_methodId, "virtual 'visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_BaseVisitor_visitConditionalExpressionNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_BaseVisitor_visitConditionalExpressionNode_v(
        parser_BaseVisitor(*(parser_BaseVisitor**)args),
        parser_ConditionalExpressionNode(*(parser_ConditionalExpressionNode*)((intptr_t)args + sizeof(parser_BaseVisitor*))));
}

corto_object _parser_BaseVisitor_visitExpressionNode(
    parser_BaseVisitor _this,
    parser_ExpressionNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitExpressionNode(/corto/parser/ExpressionNode node)");
    }
    corto_assert(_methodId, "virtual 'visitExpressionNode(/corto/parser/ExpressionNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitExpressionNode(/corto/parser/ExpressionNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_BaseVisitor_visitExpressionNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_BaseVisitor_visitExpressionNode_v(
        parser_BaseVisitor(*(parser_BaseVisitor**)args),
        parser_ExpressionNode(*(parser_ExpressionNode*)((intptr_t)args + sizeof(parser_BaseVisitor*))));
}

corto_object _parser_BaseVisitor_visitExpressionStatementNode(
    parser_BaseVisitor _this,
    parser_ExpressionStatementNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitExpressionStatementNode(/corto/parser/ExpressionStatementNode node)");
    }
    corto_assert(_methodId, "virtual 'visitExpressionStatementNode(/corto/parser/ExpressionStatementNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitExpressionStatementNode(/corto/parser/ExpressionStatementNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_BaseVisitor_visitExpressionStatementNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_BaseVisitor_visitExpressionStatementNode_v(
        parser_BaseVisitor(*(parser_BaseVisitor**)args),
        parser_ExpressionStatementNode(*(parser_ExpressionStatementNode*)((intptr_t)args + sizeof(parser_BaseVisitor*))));
}

corto_object _parser_BaseVisitor_visitProgramNode(
    parser_BaseVisitor _this,
    parser_ProgramNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitProgramNode(/corto/parser/ProgramNode node)");
    }
    corto_assert(_methodId, "virtual 'visitProgramNode(/corto/parser/ProgramNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitProgramNode(/corto/parser/ProgramNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_BaseVisitor_visitProgramNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_BaseVisitor_visitProgramNode_v(
        parser_BaseVisitor(*(parser_BaseVisitor**)args),
        parser_ProgramNode(*(parser_ProgramNode*)((intptr_t)args + sizeof(parser_BaseVisitor*))));
}

corto_object _parser_BaseVisitor_visitStatementNode(
    parser_BaseVisitor _this,
    parser_StatementNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitStatementNode(/corto/parser/StatementNode node)");
    }
    corto_assert(_methodId, "virtual 'visitStatementNode(/corto/parser/StatementNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitStatementNode(/corto/parser/StatementNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_BaseVisitor_visitStatementNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_BaseVisitor_visitStatementNode_v(
        parser_BaseVisitor(*(parser_BaseVisitor**)args),
        parser_StatementNode(*(parser_StatementNode*)((intptr_t)args + sizeof(parser_BaseVisitor*))));
}

void __parser_PrintVisitor_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _parser_PrintVisitor_construct(
        parser_PrintVisitor(*(parser_PrintVisitor**)args));
}

void __parser_PrintVisitor_destruct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _parser_PrintVisitor_destruct(
        parser_PrintVisitor(*(parser_PrintVisitor**)args));
}

void __parser_PrintVisitor_getText(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_string*)result = _parser_PrintVisitor_getText(
        parser_PrintVisitor(*(parser_PrintVisitor**)args));
}

corto_object _parser_PrintVisitor_visitBinaryExpressionNode(
    parser_PrintVisitor _this,
    parser_BinaryExpressionNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)");
    }
    corto_assert(_methodId, "virtual 'visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitBinaryExpressionNode(/corto/parser/BinaryExpressionNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_PrintVisitor_visitBinaryExpressionNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_PrintVisitor_visitBinaryExpressionNode_v(
        parser_PrintVisitor(*(parser_PrintVisitor**)args),
        parser_BinaryExpressionNode(*(parser_BinaryExpressionNode*)((intptr_t)args + sizeof(parser_PrintVisitor*))));
}

corto_object _parser_PrintVisitor_visitCommaExpressionNode(
    parser_PrintVisitor _this,
    parser_CommaExpressionNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)");
    }
    corto_assert(_methodId, "virtual 'visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitCommaExpressionNode(/corto/parser/CommaExpressionNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_PrintVisitor_visitCommaExpressionNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_PrintVisitor_visitCommaExpressionNode_v(
        parser_PrintVisitor(*(parser_PrintVisitor**)args),
        parser_CommaExpressionNode(*(parser_CommaExpressionNode*)((intptr_t)args + sizeof(parser_PrintVisitor*))));
}

corto_object _parser_PrintVisitor_visitConditionalExpressionNode(
    parser_PrintVisitor _this,
    parser_ConditionalExpressionNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)");
    }
    corto_assert(_methodId, "virtual 'visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitConditionalExpressionNode(/corto/parser/ConditionalExpressionNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_PrintVisitor_visitConditionalExpressionNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_PrintVisitor_visitConditionalExpressionNode_v(
        parser_PrintVisitor(*(parser_PrintVisitor**)args),
        parser_ConditionalExpressionNode(*(parser_ConditionalExpressionNode*)((intptr_t)args + sizeof(parser_PrintVisitor*))));
}

corto_object _parser_PrintVisitor_visitExpressionNode(
    parser_PrintVisitor _this,
    parser_ExpressionNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitExpressionNode(/corto/parser/ExpressionNode node)");
    }
    corto_assert(_methodId, "virtual 'visitExpressionNode(/corto/parser/ExpressionNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitExpressionNode(/corto/parser/ExpressionNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_PrintVisitor_visitExpressionNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_PrintVisitor_visitExpressionNode_v(
        parser_PrintVisitor(*(parser_PrintVisitor**)args),
        parser_ExpressionNode(*(parser_ExpressionNode*)((intptr_t)args + sizeof(parser_PrintVisitor*))));
}

corto_object _parser_PrintVisitor_visitProgramNode(
    parser_PrintVisitor _this,
    parser_ProgramNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitProgramNode(/corto/parser/ProgramNode node)");
    }
    corto_assert(_methodId, "virtual 'visitProgramNode(/corto/parser/ProgramNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitProgramNode(/corto/parser/ProgramNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_PrintVisitor_visitProgramNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_PrintVisitor_visitProgramNode_v(
        parser_PrintVisitor(*(parser_PrintVisitor**)args),
        parser_ProgramNode(*(parser_ProgramNode*)((intptr_t)args + sizeof(parser_PrintVisitor*))));
}

corto_object _parser_PrintVisitor_visitStatementNode(
    parser_PrintVisitor _this,
    parser_StatementNode node) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_object _result;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "visitStatementNode(/corto/parser/StatementNode node)");
    }
    corto_assert(_methodId, "virtual 'visitStatementNode(/corto/parser/StatementNode node)' not found in '%s'%s%s", corto_fullpath(NULL, _abstract), corto_lasterr()?": ":"", corto_lasterr());

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::visitStatementNode(/corto/parser/StatementNode node)@%d'", corto_idof(_this), _methodId);

    corto_call(corto_function(_method), &_result, _this, node);
    
    return _result;
}

void __parser_PrintVisitor_visitStatementNode_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_object*)result = _parser_PrintVisitor_visitStatementNode_v(
        parser_PrintVisitor(*(parser_PrintVisitor**)args),
        parser_StatementNode(*(parser_StatementNode*)((intptr_t)args + sizeof(parser_PrintVisitor*))));
}

void __parser_SimpleParser_displayRecognitionError(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _parser_SimpleParser_displayRecognitionError(
        parser_SimpleParser(*(parser_SimpleParser**)args),
        *(corto_word*)((intptr_t)args + sizeof(parser_SimpleParser*)),
        *(corto_word*)((intptr_t)args + sizeof(parser_SimpleParser*) + sizeof(corto_word)));
}
