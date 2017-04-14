/* _api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_AST__API_H
#define CORTO_AST__API_H

#include <corto/corto.h>
#include <corto/ast/_project.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /corto/ast/Binary */
CORTO_AST_EXPORT ast_Binary _ast_BinaryCreate(ast_Expression lvalue, ast_Expression rvalue, corto_operatorKind _operator);
#define ast_BinaryCreate(lvalue, rvalue, _operator) _ast_BinaryCreate(ast_Expression(lvalue), ast_Expression(rvalue), _operator)
#define ast_BinaryCreate_auto(_id, lvalue, rvalue, _operator) ast_Binary _id = ast_BinaryCreate(lvalue, rvalue, _operator); (void)_id
CORTO_AST_EXPORT ast_Binary _ast_BinaryCreateChild(corto_object _parent, corto_string _id, ast_Expression lvalue, ast_Expression rvalue, corto_operatorKind _operator);
#define ast_BinaryCreateChild(_parent, _id, lvalue, rvalue, _operator) _ast_BinaryCreateChild(_parent, _id, ast_Expression(lvalue), ast_Expression(rvalue), _operator)
#define ast_BinaryCreateChild_auto(_parent, _id, lvalue, rvalue, _operator) ast_Binary _id = ast_BinaryCreateChild(_parent, #_id, lvalue, rvalue, _operator); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_BinaryUpdate(ast_Binary _this, ast_Expression lvalue, ast_Expression rvalue, corto_operatorKind _operator);
#define ast_BinaryUpdate(_this, lvalue, rvalue, _operator) _ast_BinaryUpdate(ast_Binary(_this), ast_Expression(lvalue), ast_Expression(rvalue), _operator)

CORTO_AST_EXPORT ast_Binary _ast_BinaryDeclare(void);
#define ast_BinaryDeclare() _ast_BinaryDeclare()
#define ast_BinaryDeclare_auto(_id) ast_Binary _id = ast_BinaryDeclare(); (void)_id
CORTO_AST_EXPORT ast_Binary _ast_BinaryDeclareChild(corto_object _parent, corto_string _id);
#define ast_BinaryDeclareChild(_parent, _id) _ast_BinaryDeclareChild(_parent, _id)
#define ast_BinaryDeclareChild_auto(_parent, _id) ast_Binary _id = ast_BinaryDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_BinaryDefine(ast_Binary _this, ast_Expression lvalue, ast_Expression rvalue, corto_operatorKind _operator);
#define ast_BinaryDefine(_this, lvalue, rvalue, _operator) _ast_BinaryDefine(ast_Binary(_this), ast_Expression(lvalue), ast_Expression(rvalue), _operator)
CORTO_AST_EXPORT ast_Binary _ast_BinaryAssign(ast_Binary _this, ast_Expression lvalue, ast_Expression rvalue, corto_operatorKind _operator);
#define ast_Binary__optional_NotSet NULL
#define ast_Binary__optional_Set(lvalue, rvalue, _operator) ast_BinaryAssign((ast_Binary*)corto_calloc(sizeof(ast_Binary)), lvalue, rvalue, _operator)
#define ast_Binary__optional_SetCond(cond, lvalue, rvalue, _operator) cond ? ast_BinaryAssign((ast_Binary*)corto_calloc(sizeof(ast_Binary)), lvalue, rvalue, _operator) : NULL
#define ast_BinaryUnset(_this) _this ? corto_deinitp(_this, ast_Binary_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_BinaryAssign(_this, lvalue, rvalue, _operator) _ast_BinaryAssign(_this, ast_Expression(lvalue), ast_Expression(rvalue), _operator)
#define ast_BinarySet(_this, lvalue, rvalue, _operator) _this = _this ? _this : (ast_Binary*)corto_calloc(sizeof(ast_Binary)); _ast_BinaryAssign(_this, ast_Expression(lvalue), ast_Expression(rvalue), _operator)
CORTO_AST_EXPORT corto_string _ast_BinaryStr(ast_Binary value);
#define ast_BinaryStr(value) _ast_BinaryStr(ast_Binary(value))
CORTO_AST_EXPORT ast_Binary ast_BinaryFromStr(ast_Binary value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_BinaryCompare(ast_Binary dst, ast_Binary src);
#define ast_BinaryCompare(dst, src) _ast_BinaryCompare(ast_Binary(dst), ast_Binary(src))

/* /corto/ast/Binding */
CORTO_AST_EXPORT ast_Binding* _ast_BindingCreate(corto_function function, ast_Block impl);
#define ast_BindingCreate(function, impl) _ast_BindingCreate(corto_function(function), ast_Block(impl))
#define ast_BindingCreate_auto(_id, function, impl) ast_Binding* _id = ast_BindingCreate(function, impl); (void)_id
CORTO_AST_EXPORT ast_Binding* _ast_BindingCreateChild(corto_object _parent, corto_string _id, corto_function function, ast_Block impl);
#define ast_BindingCreateChild(_parent, _id, function, impl) _ast_BindingCreateChild(_parent, _id, corto_function(function), ast_Block(impl))
#define ast_BindingCreateChild_auto(_parent, _id, function, impl) ast_Binding* _id = ast_BindingCreateChild(_parent, #_id, function, impl); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_BindingUpdate(ast_Binding* _this, corto_function function, ast_Block impl);
#define ast_BindingUpdate(_this, function, impl) _ast_BindingUpdate(ast_Binding(_this), corto_function(function), ast_Block(impl))

CORTO_AST_EXPORT ast_Binding* _ast_BindingDeclare(void);
#define ast_BindingDeclare() _ast_BindingDeclare()
#define ast_BindingDeclare_auto(_id) ast_Binding* _id = ast_BindingDeclare(); (void)_id
CORTO_AST_EXPORT ast_Binding* _ast_BindingDeclareChild(corto_object _parent, corto_string _id);
#define ast_BindingDeclareChild(_parent, _id) _ast_BindingDeclareChild(_parent, _id)
#define ast_BindingDeclareChild_auto(_parent, _id) ast_Binding* _id = ast_BindingDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_BindingDefine(ast_Binding* _this, corto_function function, ast_Block impl);
#define ast_BindingDefine(_this, function, impl) _ast_BindingDefine(ast_Binding(_this), corto_function(function), ast_Block(impl))
CORTO_AST_EXPORT ast_Binding* _ast_BindingAssign(ast_Binding* _this, corto_function function, ast_Block impl);
#define ast_Binding__optional_NotSet NULL
#define ast_Binding__optional_Set(function, impl) ast_BindingAssign((ast_Binding*)corto_calloc(sizeof(ast_Binding)), function, impl)
#define ast_Binding__optional_SetCond(cond, function, impl) cond ? ast_BindingAssign((ast_Binding*)corto_calloc(sizeof(ast_Binding)), function, impl) : NULL
#define ast_BindingUnset(_this) _this ? corto_deinitp(_this, ast_Binding_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_BindingAssign(_this, function, impl) _ast_BindingAssign(_this, corto_function(function), ast_Block(impl))
#define ast_BindingSet(_this, function, impl) _this = _this ? _this : (ast_Binding*)corto_calloc(sizeof(ast_Binding)); _ast_BindingAssign(_this, corto_function(function), ast_Block(impl))
CORTO_AST_EXPORT corto_string _ast_BindingStr(ast_Binding* value);
#define ast_BindingStr(value) _ast_BindingStr(value)
CORTO_AST_EXPORT ast_Binding* ast_BindingFromStr(ast_Binding* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_BindingCompare(ast_Binding* dst, ast_Binding* src);

CORTO_AST_EXPORT corto_int16 _ast_BindingInit(ast_Binding* value);
#define ast_BindingInit(value) _ast_BindingInit(value)
CORTO_AST_EXPORT corto_int16 _ast_BindingDeinit(ast_Binding* value);
#define ast_BindingDeinit(value) _ast_BindingDeinit(value)

/* /corto/ast/Block */
CORTO_AST_EXPORT ast_Block _ast_BlockCreate(ast_Block parent);
#define ast_BlockCreate(parent) _ast_BlockCreate(ast_Block(parent))
#define ast_BlockCreate_auto(_id, parent) ast_Block _id = ast_BlockCreate(parent); (void)_id
CORTO_AST_EXPORT ast_Block _ast_BlockCreateChild(corto_object _parent, corto_string _id, ast_Block parent);
#define ast_BlockCreateChild(_parent, _id, parent) _ast_BlockCreateChild(_parent, _id, ast_Block(parent))
#define ast_BlockCreateChild_auto(_parent, _id, parent) ast_Block _id = ast_BlockCreateChild(_parent, #_id, parent); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_BlockUpdate(ast_Block _this, ast_Block parent);
#define ast_BlockUpdate(_this, parent) _ast_BlockUpdate(ast_Block(_this), ast_Block(parent))

CORTO_AST_EXPORT ast_Block _ast_BlockDeclare(void);
#define ast_BlockDeclare() _ast_BlockDeclare()
#define ast_BlockDeclare_auto(_id) ast_Block _id = ast_BlockDeclare(); (void)_id
CORTO_AST_EXPORT ast_Block _ast_BlockDeclareChild(corto_object _parent, corto_string _id);
#define ast_BlockDeclareChild(_parent, _id) _ast_BlockDeclareChild(_parent, _id)
#define ast_BlockDeclareChild_auto(_parent, _id) ast_Block _id = ast_BlockDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_BlockDefine(ast_Block _this, ast_Block parent);
#define ast_BlockDefine(_this, parent) _ast_BlockDefine(ast_Block(_this), ast_Block(parent))
CORTO_AST_EXPORT ast_Block _ast_BlockAssign(ast_Block _this, ast_Block parent);
#define ast_Block__optional_NotSet NULL
#define ast_Block__optional_Set(parent) ast_BlockAssign((ast_Block*)corto_calloc(sizeof(ast_Block)), parent)
#define ast_Block__optional_SetCond(cond, parent) cond ? ast_BlockAssign((ast_Block*)corto_calloc(sizeof(ast_Block)), parent) : NULL
#define ast_BlockUnset(_this) _this ? corto_deinitp(_this, ast_Block_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_BlockAssign(_this, parent) _ast_BlockAssign(_this, ast_Block(parent))
#define ast_BlockSet(_this, parent) _this = _this ? _this : (ast_Block*)corto_calloc(sizeof(ast_Block)); _ast_BlockAssign(_this, ast_Block(parent))
CORTO_AST_EXPORT corto_string _ast_BlockStr(ast_Block value);
#define ast_BlockStr(value) _ast_BlockStr(ast_Block(value))
CORTO_AST_EXPORT ast_Block ast_BlockFromStr(ast_Block value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_BlockCompare(ast_Block dst, ast_Block src);
#define ast_BlockCompare(dst, src) _ast_BlockCompare(ast_Block(dst), ast_Block(src))

/* /corto/ast/Boolean */
CORTO_AST_EXPORT ast_Boolean _ast_BooleanCreate(corto_bool value);
#define ast_BooleanCreate(value) _ast_BooleanCreate(value)
#define ast_BooleanCreate_auto(_id, value) ast_Boolean _id = ast_BooleanCreate(value); (void)_id
CORTO_AST_EXPORT ast_Boolean _ast_BooleanCreateChild(corto_object _parent, corto_string _id, corto_bool value);
#define ast_BooleanCreateChild(_parent, _id, value) _ast_BooleanCreateChild(_parent, _id, value)
#define ast_BooleanCreateChild_auto(_parent, _id, value) ast_Boolean _id = ast_BooleanCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_BooleanUpdate(ast_Boolean _this, corto_bool value);
#define ast_BooleanUpdate(_this, value) _ast_BooleanUpdate(ast_Boolean(_this), value)

CORTO_AST_EXPORT ast_Boolean _ast_BooleanDeclare(void);
#define ast_BooleanDeclare() _ast_BooleanDeclare()
#define ast_BooleanDeclare_auto(_id) ast_Boolean _id = ast_BooleanDeclare(); (void)_id
CORTO_AST_EXPORT ast_Boolean _ast_BooleanDeclareChild(corto_object _parent, corto_string _id);
#define ast_BooleanDeclareChild(_parent, _id) _ast_BooleanDeclareChild(_parent, _id)
#define ast_BooleanDeclareChild_auto(_parent, _id) ast_Boolean _id = ast_BooleanDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_BooleanDefine(ast_Boolean _this, corto_bool value);
#define ast_BooleanDefine(_this, value) _ast_BooleanDefine(ast_Boolean(_this), value)
CORTO_AST_EXPORT ast_Boolean _ast_BooleanAssign(ast_Boolean _this, corto_bool value);
#define ast_Boolean__optional_NotSet NULL
#define ast_Boolean__optional_Set(value) ast_BooleanAssign((ast_Boolean*)corto_calloc(sizeof(ast_Boolean)), value)
#define ast_Boolean__optional_SetCond(cond, value) cond ? ast_BooleanAssign((ast_Boolean*)corto_calloc(sizeof(ast_Boolean)), value) : NULL
#define ast_BooleanUnset(_this) _this ? corto_deinitp(_this, ast_Boolean_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_BooleanAssign(_this, value) _ast_BooleanAssign(_this, value)
#define ast_BooleanSet(_this, value) _this = _this ? _this : (ast_Boolean*)corto_calloc(sizeof(ast_Boolean)); _ast_BooleanAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_BooleanStr(ast_Boolean value);
#define ast_BooleanStr(value) _ast_BooleanStr(ast_Boolean(value))
CORTO_AST_EXPORT ast_Boolean ast_BooleanFromStr(ast_Boolean value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_BooleanCompare(ast_Boolean dst, ast_Boolean src);
#define ast_BooleanCompare(dst, src) _ast_BooleanCompare(ast_Boolean(dst), ast_Boolean(src))

/* /corto/ast/Call */
CORTO_AST_EXPORT ast_Call _ast_CallCreate(ast_Expression instanceExpr, ast_Expression arguments);
#define ast_CallCreate(instanceExpr, arguments) _ast_CallCreate(ast_Expression(instanceExpr), ast_Expression(arguments))
#define ast_CallCreate_auto(_id, instanceExpr, arguments) ast_Call _id = ast_CallCreate(instanceExpr, arguments); (void)_id
CORTO_AST_EXPORT ast_Call _ast_CallCreateChild(corto_object _parent, corto_string _id, ast_Expression instanceExpr, ast_Expression arguments);
#define ast_CallCreateChild(_parent, _id, instanceExpr, arguments) _ast_CallCreateChild(_parent, _id, ast_Expression(instanceExpr), ast_Expression(arguments))
#define ast_CallCreateChild_auto(_parent, _id, instanceExpr, arguments) ast_Call _id = ast_CallCreateChild(_parent, #_id, instanceExpr, arguments); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CallUpdate(ast_Call _this, ast_Expression instanceExpr, ast_Expression arguments);
#define ast_CallUpdate(_this, instanceExpr, arguments) _ast_CallUpdate(ast_Call(_this), ast_Expression(instanceExpr), ast_Expression(arguments))

CORTO_AST_EXPORT ast_Call _ast_CallDeclare(void);
#define ast_CallDeclare() _ast_CallDeclare()
#define ast_CallDeclare_auto(_id) ast_Call _id = ast_CallDeclare(); (void)_id
CORTO_AST_EXPORT ast_Call _ast_CallDeclareChild(corto_object _parent, corto_string _id);
#define ast_CallDeclareChild(_parent, _id) _ast_CallDeclareChild(_parent, _id)
#define ast_CallDeclareChild_auto(_parent, _id) ast_Call _id = ast_CallDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CallDefine(ast_Call _this, ast_Expression instanceExpr, ast_Expression arguments);
#define ast_CallDefine(_this, instanceExpr, arguments) _ast_CallDefine(ast_Call(_this), ast_Expression(instanceExpr), ast_Expression(arguments))
CORTO_AST_EXPORT ast_Call _ast_CallAssign(ast_Call _this, ast_Expression instanceExpr, ast_Expression arguments);
#define ast_Call__optional_NotSet NULL
#define ast_Call__optional_Set(instanceExpr, arguments) ast_CallAssign((ast_Call*)corto_calloc(sizeof(ast_Call)), instanceExpr, arguments)
#define ast_Call__optional_SetCond(cond, instanceExpr, arguments) cond ? ast_CallAssign((ast_Call*)corto_calloc(sizeof(ast_Call)), instanceExpr, arguments) : NULL
#define ast_CallUnset(_this) _this ? corto_deinitp(_this, ast_Call_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_CallAssign(_this, instanceExpr, arguments) _ast_CallAssign(_this, ast_Expression(instanceExpr), ast_Expression(arguments))
#define ast_CallSet(_this, instanceExpr, arguments) _this = _this ? _this : (ast_Call*)corto_calloc(sizeof(ast_Call)); _ast_CallAssign(_this, ast_Expression(instanceExpr), ast_Expression(arguments))
CORTO_AST_EXPORT corto_string _ast_CallStr(ast_Call value);
#define ast_CallStr(value) _ast_CallStr(ast_Call(value))
CORTO_AST_EXPORT ast_Call ast_CallFromStr(ast_Call value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_CallCompare(ast_Call dst, ast_Call src);
#define ast_CallCompare(dst, src) _ast_CallCompare(ast_Call(dst), ast_Call(src))

/* /corto/ast/CallBuilder */
CORTO_AST_EXPORT ast_CallBuilder* _ast_CallBuilderCreate(corto_string name, ast_Expression arguments, ast_Expression instance, corto_object scope, ast_Block block);
#define ast_CallBuilderCreate(name, arguments, instance, scope, block) _ast_CallBuilderCreate(name, ast_Expression(arguments), ast_Expression(instance), scope, ast_Block(block))
#define ast_CallBuilderCreate_auto(_id, name, arguments, instance, scope, block) ast_CallBuilder* _id = ast_CallBuilderCreate(name, arguments, instance, scope, block); (void)_id
CORTO_AST_EXPORT ast_CallBuilder* _ast_CallBuilderCreateChild(corto_object _parent, corto_string _id, corto_string name, ast_Expression arguments, ast_Expression instance, corto_object scope, ast_Block block);
#define ast_CallBuilderCreateChild(_parent, _id, name, arguments, instance, scope, block) _ast_CallBuilderCreateChild(_parent, _id, name, ast_Expression(arguments), ast_Expression(instance), scope, ast_Block(block))
#define ast_CallBuilderCreateChild_auto(_parent, _id, name, arguments, instance, scope, block) ast_CallBuilder* _id = ast_CallBuilderCreateChild(_parent, #_id, name, arguments, instance, scope, block); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CallBuilderUpdate(ast_CallBuilder* _this, corto_string name, ast_Expression arguments, ast_Expression instance, corto_object scope, ast_Block block);
#define ast_CallBuilderUpdate(_this, name, arguments, instance, scope, block) _ast_CallBuilderUpdate(ast_CallBuilder(_this), name, ast_Expression(arguments), ast_Expression(instance), scope, ast_Block(block))

CORTO_AST_EXPORT ast_CallBuilder* _ast_CallBuilderDeclare(void);
#define ast_CallBuilderDeclare() _ast_CallBuilderDeclare()
#define ast_CallBuilderDeclare_auto(_id) ast_CallBuilder* _id = ast_CallBuilderDeclare(); (void)_id
CORTO_AST_EXPORT ast_CallBuilder* _ast_CallBuilderDeclareChild(corto_object _parent, corto_string _id);
#define ast_CallBuilderDeclareChild(_parent, _id) _ast_CallBuilderDeclareChild(_parent, _id)
#define ast_CallBuilderDeclareChild_auto(_parent, _id) ast_CallBuilder* _id = ast_CallBuilderDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CallBuilderDefine(ast_CallBuilder* _this, corto_string name, ast_Expression arguments, ast_Expression instance, corto_object scope, ast_Block block);
#define ast_CallBuilderDefine(_this, name, arguments, instance, scope, block) _ast_CallBuilderDefine(ast_CallBuilder(_this), name, ast_Expression(arguments), ast_Expression(instance), scope, ast_Block(block))
CORTO_AST_EXPORT ast_CallBuilder* _ast_CallBuilderAssign(ast_CallBuilder* _this, corto_string name, ast_Expression arguments, ast_Expression instance, corto_object scope, ast_Block block);
#define ast_CallBuilder__optional_NotSet NULL
#define ast_CallBuilder__optional_Set(name, arguments, instance, scope, block) ast_CallBuilderAssign((ast_CallBuilder*)corto_calloc(sizeof(ast_CallBuilder)), name, arguments, instance, scope, block)
#define ast_CallBuilder__optional_SetCond(cond, name, arguments, instance, scope, block) cond ? ast_CallBuilderAssign((ast_CallBuilder*)corto_calloc(sizeof(ast_CallBuilder)), name, arguments, instance, scope, block) : NULL
#define ast_CallBuilderUnset(_this) _this ? corto_deinitp(_this, ast_CallBuilder_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_CallBuilderAssign(_this, name, arguments, instance, scope, block) _ast_CallBuilderAssign(_this, name, ast_Expression(arguments), ast_Expression(instance), scope, ast_Block(block))
#define ast_CallBuilderSet(_this, name, arguments, instance, scope, block) _this = _this ? _this : (ast_CallBuilder*)corto_calloc(sizeof(ast_CallBuilder)); _ast_CallBuilderAssign(_this, name, ast_Expression(arguments), ast_Expression(instance), scope, ast_Block(block))
CORTO_AST_EXPORT corto_string _ast_CallBuilderStr(ast_CallBuilder* value);
#define ast_CallBuilderStr(value) _ast_CallBuilderStr(value)
CORTO_AST_EXPORT ast_CallBuilder* ast_CallBuilderFromStr(ast_CallBuilder* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_CallBuilderCompare(ast_CallBuilder* dst, ast_CallBuilder* src);

CORTO_AST_EXPORT corto_int16 _ast_CallBuilderInit(ast_CallBuilder* value);
#define ast_CallBuilderInit(value) _ast_CallBuilderInit(value)
CORTO_AST_EXPORT corto_int16 _ast_CallBuilderDeinit(ast_CallBuilder* value);
#define ast_CallBuilderDeinit(value) _ast_CallBuilderDeinit(value)

/* /corto/ast/Cast */
CORTO_AST_EXPORT ast_Cast _ast_CastCreate(corto_type lvalue, ast_Expression rvalue, corto_bool isReference_1);
#define ast_CastCreate(lvalue, rvalue, isReference_1) _ast_CastCreate(corto_type(lvalue), ast_Expression(rvalue), isReference_1)
#define ast_CastCreate_auto(_id, lvalue, rvalue, isReference_1) ast_Cast _id = ast_CastCreate(lvalue, rvalue, isReference_1); (void)_id
CORTO_AST_EXPORT ast_Cast _ast_CastCreateChild(corto_object _parent, corto_string _id, corto_type lvalue, ast_Expression rvalue, corto_bool isReference_1);
#define ast_CastCreateChild(_parent, _id, lvalue, rvalue, isReference_1) _ast_CastCreateChild(_parent, _id, corto_type(lvalue), ast_Expression(rvalue), isReference_1)
#define ast_CastCreateChild_auto(_parent, _id, lvalue, rvalue, isReference_1) ast_Cast _id = ast_CastCreateChild(_parent, #_id, lvalue, rvalue, isReference_1); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CastUpdate(ast_Cast _this, corto_type lvalue, ast_Expression rvalue, corto_bool isReference_1);
#define ast_CastUpdate(_this, lvalue, rvalue, isReference_1) _ast_CastUpdate(ast_Cast(_this), corto_type(lvalue), ast_Expression(rvalue), isReference_1)

CORTO_AST_EXPORT ast_Cast _ast_CastDeclare(void);
#define ast_CastDeclare() _ast_CastDeclare()
#define ast_CastDeclare_auto(_id) ast_Cast _id = ast_CastDeclare(); (void)_id
CORTO_AST_EXPORT ast_Cast _ast_CastDeclareChild(corto_object _parent, corto_string _id);
#define ast_CastDeclareChild(_parent, _id) _ast_CastDeclareChild(_parent, _id)
#define ast_CastDeclareChild_auto(_parent, _id) ast_Cast _id = ast_CastDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CastDefine(ast_Cast _this, corto_type lvalue, ast_Expression rvalue, corto_bool isReference_1);
#define ast_CastDefine(_this, lvalue, rvalue, isReference_1) _ast_CastDefine(ast_Cast(_this), corto_type(lvalue), ast_Expression(rvalue), isReference_1)
CORTO_AST_EXPORT ast_Cast _ast_CastAssign(ast_Cast _this, corto_type lvalue, ast_Expression rvalue, corto_bool isReference_1);
#define ast_Cast__optional_NotSet NULL
#define ast_Cast__optional_Set(lvalue, rvalue, isReference_1) ast_CastAssign((ast_Cast*)corto_calloc(sizeof(ast_Cast)), lvalue, rvalue, isReference_1)
#define ast_Cast__optional_SetCond(cond, lvalue, rvalue, isReference_1) cond ? ast_CastAssign((ast_Cast*)corto_calloc(sizeof(ast_Cast)), lvalue, rvalue, isReference_1) : NULL
#define ast_CastUnset(_this) _this ? corto_deinitp(_this, ast_Cast_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_CastAssign(_this, lvalue, rvalue, isReference_1) _ast_CastAssign(_this, corto_type(lvalue), ast_Expression(rvalue), isReference_1)
#define ast_CastSet(_this, lvalue, rvalue, isReference_1) _this = _this ? _this : (ast_Cast*)corto_calloc(sizeof(ast_Cast)); _ast_CastAssign(_this, corto_type(lvalue), ast_Expression(rvalue), isReference_1)
CORTO_AST_EXPORT corto_string _ast_CastStr(ast_Cast value);
#define ast_CastStr(value) _ast_CastStr(ast_Cast(value))
CORTO_AST_EXPORT ast_Cast ast_CastFromStr(ast_Cast value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_CastCompare(ast_Cast dst, ast_Cast src);
#define ast_CastCompare(dst, src) _ast_CastCompare(ast_Cast(dst), ast_Cast(src))

/* /corto/ast/Character */
CORTO_AST_EXPORT ast_Character _ast_CharacterCreate(corto_char value);
#define ast_CharacterCreate(value) _ast_CharacterCreate(value)
#define ast_CharacterCreate_auto(_id, value) ast_Character _id = ast_CharacterCreate(value); (void)_id
CORTO_AST_EXPORT ast_Character _ast_CharacterCreateChild(corto_object _parent, corto_string _id, corto_char value);
#define ast_CharacterCreateChild(_parent, _id, value) _ast_CharacterCreateChild(_parent, _id, value)
#define ast_CharacterCreateChild_auto(_parent, _id, value) ast_Character _id = ast_CharacterCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CharacterUpdate(ast_Character _this, corto_char value);
#define ast_CharacterUpdate(_this, value) _ast_CharacterUpdate(ast_Character(_this), value)

CORTO_AST_EXPORT ast_Character _ast_CharacterDeclare(void);
#define ast_CharacterDeclare() _ast_CharacterDeclare()
#define ast_CharacterDeclare_auto(_id) ast_Character _id = ast_CharacterDeclare(); (void)_id
CORTO_AST_EXPORT ast_Character _ast_CharacterDeclareChild(corto_object _parent, corto_string _id);
#define ast_CharacterDeclareChild(_parent, _id) _ast_CharacterDeclareChild(_parent, _id)
#define ast_CharacterDeclareChild_auto(_parent, _id) ast_Character _id = ast_CharacterDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CharacterDefine(ast_Character _this, corto_char value);
#define ast_CharacterDefine(_this, value) _ast_CharacterDefine(ast_Character(_this), value)
CORTO_AST_EXPORT ast_Character _ast_CharacterAssign(ast_Character _this, corto_char value);
#define ast_Character__optional_NotSet NULL
#define ast_Character__optional_Set(value) ast_CharacterAssign((ast_Character*)corto_calloc(sizeof(ast_Character)), value)
#define ast_Character__optional_SetCond(cond, value) cond ? ast_CharacterAssign((ast_Character*)corto_calloc(sizeof(ast_Character)), value) : NULL
#define ast_CharacterUnset(_this) _this ? corto_deinitp(_this, ast_Character_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_CharacterAssign(_this, value) _ast_CharacterAssign(_this, value)
#define ast_CharacterSet(_this, value) _this = _this ? _this : (ast_Character*)corto_calloc(sizeof(ast_Character)); _ast_CharacterAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_CharacterStr(ast_Character value);
#define ast_CharacterStr(value) _ast_CharacterStr(ast_Character(value))
CORTO_AST_EXPORT ast_Character ast_CharacterFromStr(ast_Character value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_CharacterCompare(ast_Character dst, ast_Character src);
#define ast_CharacterCompare(dst, src) _ast_CharacterCompare(ast_Character(dst), ast_Character(src))

/* /corto/ast/Comma */
CORTO_AST_EXPORT ast_Comma _ast_CommaCreate(void);
#define ast_CommaCreate() _ast_CommaCreate()
#define ast_CommaCreate_auto(_id) ast_Comma _id = ast_CommaCreate(); (void)_id
CORTO_AST_EXPORT ast_Comma _ast_CommaCreateChild(corto_object _parent, corto_string _id);
#define ast_CommaCreateChild(_parent, _id) _ast_CommaCreateChild(_parent, _id)
#define ast_CommaCreateChild_auto(_parent, _id) ast_Comma _id = ast_CommaCreateChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CommaUpdate(ast_Comma _this);
#define ast_CommaUpdate(_this) _ast_CommaUpdate(ast_Comma(_this))

CORTO_AST_EXPORT ast_Comma _ast_CommaDeclare(void);
#define ast_CommaDeclare() _ast_CommaDeclare()
#define ast_CommaDeclare_auto(_id) ast_Comma _id = ast_CommaDeclare(); (void)_id
CORTO_AST_EXPORT ast_Comma _ast_CommaDeclareChild(corto_object _parent, corto_string _id);
#define ast_CommaDeclareChild(_parent, _id) _ast_CommaDeclareChild(_parent, _id)
#define ast_CommaDeclareChild_auto(_parent, _id) ast_Comma _id = ast_CommaDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_CommaDefine(ast_Comma _this);
#define ast_CommaDefine(_this) _ast_CommaDefine(ast_Comma(_this))
CORTO_AST_EXPORT ast_Comma _ast_CommaAssign(ast_Comma _this);
#define ast_Comma__optional_NotSet NULL
#define ast_Comma__optional_Set() ast_CommaAssign((ast_Comma*)corto_calloc(sizeof(ast_Comma)))
#define ast_Comma__optional_SetCond(cond) cond ? ast_CommaAssign((ast_Comma*)corto_calloc(sizeof(ast_Comma))) : NULL
#define ast_CommaUnset(_this) _this ? corto_deinitp(_this, ast_Comma_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_CommaAssign(_this) _ast_CommaAssign(_this)
#define ast_CommaSet(_this) _this = _this ? _this : (ast_Comma*)corto_calloc(sizeof(ast_Comma)); _ast_CommaAssign(_this)
CORTO_AST_EXPORT corto_string _ast_CommaStr(ast_Comma value);
#define ast_CommaStr(value) _ast_CommaStr(ast_Comma(value))
CORTO_AST_EXPORT ast_Comma ast_CommaFromStr(ast_Comma value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_CommaCompare(ast_Comma dst, ast_Comma src);
#define ast_CommaCompare(dst, src) _ast_CommaCompare(ast_Comma(dst), ast_Comma(src))

/* /corto/ast/Define */
CORTO_AST_EXPORT ast_Define _ast_DefineCreate(ast_Expression object);
#define ast_DefineCreate(object) _ast_DefineCreate(ast_Expression(object))
#define ast_DefineCreate_auto(_id, object) ast_Define _id = ast_DefineCreate(object); (void)_id
CORTO_AST_EXPORT ast_Define _ast_DefineCreateChild(corto_object _parent, corto_string _id, ast_Expression object);
#define ast_DefineCreateChild(_parent, _id, object) _ast_DefineCreateChild(_parent, _id, ast_Expression(object))
#define ast_DefineCreateChild_auto(_parent, _id, object) ast_Define _id = ast_DefineCreateChild(_parent, #_id, object); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DefineUpdate(ast_Define _this, ast_Expression object);
#define ast_DefineUpdate(_this, object) _ast_DefineUpdate(ast_Define(_this), ast_Expression(object))

CORTO_AST_EXPORT ast_Define _ast_DefineDeclare(void);
#define ast_DefineDeclare() _ast_DefineDeclare()
#define ast_DefineDeclare_auto(_id) ast_Define _id = ast_DefineDeclare(); (void)_id
CORTO_AST_EXPORT ast_Define _ast_DefineDeclareChild(corto_object _parent, corto_string _id);
#define ast_DefineDeclareChild(_parent, _id) _ast_DefineDeclareChild(_parent, _id)
#define ast_DefineDeclareChild_auto(_parent, _id) ast_Define _id = ast_DefineDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DefineDefine(ast_Define _this, ast_Expression object);
#define ast_DefineDefine(_this, object) _ast_DefineDefine(ast_Define(_this), ast_Expression(object))
CORTO_AST_EXPORT ast_Define _ast_DefineAssign(ast_Define _this, ast_Expression object);
#define ast_Define__optional_NotSet NULL
#define ast_Define__optional_Set(object) ast_DefineAssign((ast_Define*)corto_calloc(sizeof(ast_Define)), object)
#define ast_Define__optional_SetCond(cond, object) cond ? ast_DefineAssign((ast_Define*)corto_calloc(sizeof(ast_Define)), object) : NULL
#define ast_DefineUnset(_this) _this ? corto_deinitp(_this, ast_Define_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_DefineAssign(_this, object) _ast_DefineAssign(_this, ast_Expression(object))
#define ast_DefineSet(_this, object) _this = _this ? _this : (ast_Define*)corto_calloc(sizeof(ast_Define)); _ast_DefineAssign(_this, ast_Expression(object))
CORTO_AST_EXPORT corto_string _ast_DefineStr(ast_Define value);
#define ast_DefineStr(value) _ast_DefineStr(ast_Define(value))
CORTO_AST_EXPORT ast_Define ast_DefineFromStr(ast_Define value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_DefineCompare(ast_Define dst, ast_Define src);
#define ast_DefineCompare(dst, src) _ast_DefineCompare(ast_Define(dst), ast_Define(src))

/* /corto/ast/Deinit */
CORTO_AST_EXPORT ast_Deinit _ast_DeinitCreate(ast_Storage storage);
#define ast_DeinitCreate(storage) _ast_DeinitCreate(ast_Storage(storage))
#define ast_DeinitCreate_auto(_id, storage) ast_Deinit _id = ast_DeinitCreate(storage); (void)_id
CORTO_AST_EXPORT ast_Deinit _ast_DeinitCreateChild(corto_object _parent, corto_string _id, ast_Storage storage);
#define ast_DeinitCreateChild(_parent, _id, storage) _ast_DeinitCreateChild(_parent, _id, ast_Storage(storage))
#define ast_DeinitCreateChild_auto(_parent, _id, storage) ast_Deinit _id = ast_DeinitCreateChild(_parent, #_id, storage); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DeinitUpdate(ast_Deinit _this, ast_Storage storage);
#define ast_DeinitUpdate(_this, storage) _ast_DeinitUpdate(ast_Deinit(_this), ast_Storage(storage))

CORTO_AST_EXPORT ast_Deinit _ast_DeinitDeclare(void);
#define ast_DeinitDeclare() _ast_DeinitDeclare()
#define ast_DeinitDeclare_auto(_id) ast_Deinit _id = ast_DeinitDeclare(); (void)_id
CORTO_AST_EXPORT ast_Deinit _ast_DeinitDeclareChild(corto_object _parent, corto_string _id);
#define ast_DeinitDeclareChild(_parent, _id) _ast_DeinitDeclareChild(_parent, _id)
#define ast_DeinitDeclareChild_auto(_parent, _id) ast_Deinit _id = ast_DeinitDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DeinitDefine(ast_Deinit _this, ast_Storage storage);
#define ast_DeinitDefine(_this, storage) _ast_DeinitDefine(ast_Deinit(_this), ast_Storage(storage))
CORTO_AST_EXPORT ast_Deinit _ast_DeinitAssign(ast_Deinit _this, ast_Storage storage);
#define ast_Deinit__optional_NotSet NULL
#define ast_Deinit__optional_Set(storage) ast_DeinitAssign((ast_Deinit*)corto_calloc(sizeof(ast_Deinit)), storage)
#define ast_Deinit__optional_SetCond(cond, storage) cond ? ast_DeinitAssign((ast_Deinit*)corto_calloc(sizeof(ast_Deinit)), storage) : NULL
#define ast_DeinitUnset(_this) _this ? corto_deinitp(_this, ast_Deinit_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_DeinitAssign(_this, storage) _ast_DeinitAssign(_this, ast_Storage(storage))
#define ast_DeinitSet(_this, storage) _this = _this ? _this : (ast_Deinit*)corto_calloc(sizeof(ast_Deinit)); _ast_DeinitAssign(_this, ast_Storage(storage))
CORTO_AST_EXPORT corto_string _ast_DeinitStr(ast_Deinit value);
#define ast_DeinitStr(value) _ast_DeinitStr(ast_Deinit(value))
CORTO_AST_EXPORT ast_Deinit ast_DeinitFromStr(ast_Deinit value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_DeinitCompare(ast_Deinit dst, ast_Deinit src);
#define ast_DeinitCompare(dst, src) _ast_DeinitCompare(ast_Deinit(dst), ast_Deinit(src))

/* /corto/ast/DelegateCall */
CORTO_AST_EXPORT ast_DelegateCall _ast_DelegateCallCreate(ast_Expression instanceExpr, ast_Expression arguments, ast_Expression expr);
#define ast_DelegateCallCreate(instanceExpr, arguments, expr) _ast_DelegateCallCreate(ast_Expression(instanceExpr), ast_Expression(arguments), ast_Expression(expr))
#define ast_DelegateCallCreate_auto(_id, instanceExpr, arguments, expr) ast_DelegateCall _id = ast_DelegateCallCreate(instanceExpr, arguments, expr); (void)_id
CORTO_AST_EXPORT ast_DelegateCall _ast_DelegateCallCreateChild(corto_object _parent, corto_string _id, ast_Expression instanceExpr, ast_Expression arguments, ast_Expression expr);
#define ast_DelegateCallCreateChild(_parent, _id, instanceExpr, arguments, expr) _ast_DelegateCallCreateChild(_parent, _id, ast_Expression(instanceExpr), ast_Expression(arguments), ast_Expression(expr))
#define ast_DelegateCallCreateChild_auto(_parent, _id, instanceExpr, arguments, expr) ast_DelegateCall _id = ast_DelegateCallCreateChild(_parent, #_id, instanceExpr, arguments, expr); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DelegateCallUpdate(ast_DelegateCall _this, ast_Expression instanceExpr, ast_Expression arguments, ast_Expression expr);
#define ast_DelegateCallUpdate(_this, instanceExpr, arguments, expr) _ast_DelegateCallUpdate(ast_DelegateCall(_this), ast_Expression(instanceExpr), ast_Expression(arguments), ast_Expression(expr))

CORTO_AST_EXPORT ast_DelegateCall _ast_DelegateCallDeclare(void);
#define ast_DelegateCallDeclare() _ast_DelegateCallDeclare()
#define ast_DelegateCallDeclare_auto(_id) ast_DelegateCall _id = ast_DelegateCallDeclare(); (void)_id
CORTO_AST_EXPORT ast_DelegateCall _ast_DelegateCallDeclareChild(corto_object _parent, corto_string _id);
#define ast_DelegateCallDeclareChild(_parent, _id) _ast_DelegateCallDeclareChild(_parent, _id)
#define ast_DelegateCallDeclareChild_auto(_parent, _id) ast_DelegateCall _id = ast_DelegateCallDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DelegateCallDefine(ast_DelegateCall _this, ast_Expression instanceExpr, ast_Expression arguments, ast_Expression expr);
#define ast_DelegateCallDefine(_this, instanceExpr, arguments, expr) _ast_DelegateCallDefine(ast_DelegateCall(_this), ast_Expression(instanceExpr), ast_Expression(arguments), ast_Expression(expr))
CORTO_AST_EXPORT ast_DelegateCall _ast_DelegateCallAssign(ast_DelegateCall _this, ast_Expression instanceExpr, ast_Expression arguments, ast_Expression expr);
#define ast_DelegateCall__optional_NotSet NULL
#define ast_DelegateCall__optional_Set(instanceExpr, arguments, expr) ast_DelegateCallAssign((ast_DelegateCall*)corto_calloc(sizeof(ast_DelegateCall)), instanceExpr, arguments, expr)
#define ast_DelegateCall__optional_SetCond(cond, instanceExpr, arguments, expr) cond ? ast_DelegateCallAssign((ast_DelegateCall*)corto_calloc(sizeof(ast_DelegateCall)), instanceExpr, arguments, expr) : NULL
#define ast_DelegateCallUnset(_this) _this ? corto_deinitp(_this, ast_DelegateCall_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_DelegateCallAssign(_this, instanceExpr, arguments, expr) _ast_DelegateCallAssign(_this, ast_Expression(instanceExpr), ast_Expression(arguments), ast_Expression(expr))
#define ast_DelegateCallSet(_this, instanceExpr, arguments, expr) _this = _this ? _this : (ast_DelegateCall*)corto_calloc(sizeof(ast_DelegateCall)); _ast_DelegateCallAssign(_this, ast_Expression(instanceExpr), ast_Expression(arguments), ast_Expression(expr))
CORTO_AST_EXPORT corto_string _ast_DelegateCallStr(ast_DelegateCall value);
#define ast_DelegateCallStr(value) _ast_DelegateCallStr(ast_DelegateCall(value))
CORTO_AST_EXPORT ast_DelegateCall ast_DelegateCallFromStr(ast_DelegateCall value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_DelegateCallCompare(ast_DelegateCall dst, ast_DelegateCall src);
#define ast_DelegateCallCompare(dst, src) _ast_DelegateCallCompare(ast_DelegateCall(dst), ast_DelegateCall(src))

/* /corto/ast/derefKind */
CORTO_AST_EXPORT ast_derefKind* _ast_derefKindCreate(ast_derefKind value);
#define ast_derefKindCreate(value) _ast_derefKindCreate(value)
#define ast_derefKindCreate_auto(_id, value) ast_derefKind* _id = ast_derefKindCreate(value); (void)_id
CORTO_AST_EXPORT ast_derefKind* _ast_derefKindCreateChild(corto_object _parent, corto_string _id, ast_derefKind value);
#define ast_derefKindCreateChild(_parent, _id, value) _ast_derefKindCreateChild(_parent, _id, value)
#define ast_derefKindCreateChild_auto(_parent, _id, value) ast_derefKind* _id = ast_derefKindCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_derefKindUpdate(ast_derefKind* _this, ast_derefKind value);
#define ast_derefKindUpdate(_this, value) _ast_derefKindUpdate(ast_derefKind(_this), value)

CORTO_AST_EXPORT ast_derefKind* _ast_derefKindDeclare(void);
#define ast_derefKindDeclare() _ast_derefKindDeclare()
#define ast_derefKindDeclare_auto(_id) ast_derefKind* _id = ast_derefKindDeclare(); (void)_id
CORTO_AST_EXPORT ast_derefKind* _ast_derefKindDeclareChild(corto_object _parent, corto_string _id);
#define ast_derefKindDeclareChild(_parent, _id) _ast_derefKindDeclareChild(_parent, _id)
#define ast_derefKindDeclareChild_auto(_parent, _id) ast_derefKind* _id = ast_derefKindDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_derefKindDefine(ast_derefKind* _this, ast_derefKind value);
#define ast_derefKindDefine(_this, value) _ast_derefKindDefine(ast_derefKind(_this), value)
CORTO_AST_EXPORT ast_derefKind* _ast_derefKindAssign(ast_derefKind* _this, ast_derefKind value);
#define ast_derefKind__optional_NotSet NULL
#define ast_derefKind__optional_Set(value) ast_derefKindAssign((ast_derefKind*)corto_calloc(sizeof(ast_derefKind)), value)
#define ast_derefKind__optional_SetCond(cond, value) cond ? ast_derefKindAssign((ast_derefKind*)corto_calloc(sizeof(ast_derefKind)), value) : NULL
#define ast_derefKindUnset(_this) _this ? corto_deinitp(_this, ast_derefKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_derefKindAssign(_this, value) _ast_derefKindAssign(_this, value)
#define ast_derefKindSet(_this, value) _this = _this ? _this : (ast_derefKind*)corto_calloc(sizeof(ast_derefKind)); _ast_derefKindAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_derefKindStr(ast_derefKind value);
#define ast_derefKindStr(value) _ast_derefKindStr(value)
CORTO_AST_EXPORT ast_derefKind* ast_derefKindFromStr(ast_derefKind* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_derefKindCompare(ast_derefKind dst, ast_derefKind src);

CORTO_AST_EXPORT corto_int16 _ast_derefKindInit(ast_derefKind* value);
#define ast_derefKindInit(value) _ast_derefKindInit(value)
CORTO_AST_EXPORT corto_int16 _ast_derefKindDeinit(ast_derefKind* value);
#define ast_derefKindDeinit(value) _ast_derefKindDeinit(value)

/* /corto/ast/DynamicInitializer */
CORTO_AST_EXPORT ast_DynamicInitializer _ast_DynamicInitializerCreate(ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_DynamicInitializerCreate(variables, variableCount, assignValue) _ast_DynamicInitializerCreate(variables, variableCount, assignValue)
#define ast_DynamicInitializerCreate_auto(_id, variables, variableCount, assignValue) ast_DynamicInitializer _id = ast_DynamicInitializerCreate(variables, variableCount, assignValue); (void)_id
CORTO_AST_EXPORT ast_DynamicInitializer _ast_DynamicInitializerCreateChild(corto_object _parent, corto_string _id, ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_DynamicInitializerCreateChild(_parent, _id, variables, variableCount, assignValue) _ast_DynamicInitializerCreateChild(_parent, _id, variables, variableCount, assignValue)
#define ast_DynamicInitializerCreateChild_auto(_parent, _id, variables, variableCount, assignValue) ast_DynamicInitializer _id = ast_DynamicInitializerCreateChild(_parent, #_id, variables, variableCount, assignValue); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DynamicInitializerUpdate(ast_DynamicInitializer _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_DynamicInitializerUpdate(_this, variables, variableCount, assignValue) _ast_DynamicInitializerUpdate(ast_DynamicInitializer(_this), variables, variableCount, assignValue)

CORTO_AST_EXPORT ast_DynamicInitializer _ast_DynamicInitializerDeclare(void);
#define ast_DynamicInitializerDeclare() _ast_DynamicInitializerDeclare()
#define ast_DynamicInitializerDeclare_auto(_id) ast_DynamicInitializer _id = ast_DynamicInitializerDeclare(); (void)_id
CORTO_AST_EXPORT ast_DynamicInitializer _ast_DynamicInitializerDeclareChild(corto_object _parent, corto_string _id);
#define ast_DynamicInitializerDeclareChild(_parent, _id) _ast_DynamicInitializerDeclareChild(_parent, _id)
#define ast_DynamicInitializerDeclareChild_auto(_parent, _id) ast_DynamicInitializer _id = ast_DynamicInitializerDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DynamicInitializerDefine(ast_DynamicInitializer _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_DynamicInitializerDefine(_this, variables, variableCount, assignValue) _ast_DynamicInitializerDefine(ast_DynamicInitializer(_this), variables, variableCount, assignValue)
CORTO_AST_EXPORT ast_DynamicInitializer _ast_DynamicInitializerAssign(ast_DynamicInitializer _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_DynamicInitializer__optional_NotSet NULL
#define ast_DynamicInitializer__optional_Set(variables, variableCount, assignValue) ast_DynamicInitializerAssign((ast_DynamicInitializer*)corto_calloc(sizeof(ast_DynamicInitializer)), variables, variableCount, assignValue)
#define ast_DynamicInitializer__optional_SetCond(cond, variables, variableCount, assignValue) cond ? ast_DynamicInitializerAssign((ast_DynamicInitializer*)corto_calloc(sizeof(ast_DynamicInitializer)), variables, variableCount, assignValue) : NULL
#define ast_DynamicInitializerUnset(_this) _this ? corto_deinitp(_this, ast_DynamicInitializer_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_DynamicInitializerAssign(_this, variables, variableCount, assignValue) _ast_DynamicInitializerAssign(_this, variables, variableCount, assignValue)
#define ast_DynamicInitializerSet(_this, variables, variableCount, assignValue) _this = _this ? _this : (ast_DynamicInitializer*)corto_calloc(sizeof(ast_DynamicInitializer)); _ast_DynamicInitializerAssign(_this, variables, variableCount, assignValue)
CORTO_AST_EXPORT corto_string _ast_DynamicInitializerStr(ast_DynamicInitializer value);
#define ast_DynamicInitializerStr(value) _ast_DynamicInitializerStr(ast_DynamicInitializer(value))
CORTO_AST_EXPORT ast_DynamicInitializer ast_DynamicInitializerFromStr(ast_DynamicInitializer value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_DynamicInitializerCompare(ast_DynamicInitializer dst, ast_DynamicInitializer src);
#define ast_DynamicInitializerCompare(dst, src) _ast_DynamicInitializerCompare(ast_DynamicInitializer(dst), ast_DynamicInitializer(src))

/* /corto/ast/DynamicInitializerFrame */
CORTO_AST_EXPORT ast_DynamicInitializerFrame* _ast_DynamicInitializerFrameCreate(ast_ExpressionArray64 expr, ast_ExpressionArray64 keyExpr, ast_Integer sequenceSize);
#define ast_DynamicInitializerFrameCreate(expr, keyExpr, sequenceSize) _ast_DynamicInitializerFrameCreate(expr, keyExpr, ast_Integer(sequenceSize))
#define ast_DynamicInitializerFrameCreate_auto(_id, expr, keyExpr, sequenceSize) ast_DynamicInitializerFrame* _id = ast_DynamicInitializerFrameCreate(expr, keyExpr, sequenceSize); (void)_id
CORTO_AST_EXPORT ast_DynamicInitializerFrame* _ast_DynamicInitializerFrameCreateChild(corto_object _parent, corto_string _id, ast_ExpressionArray64 expr, ast_ExpressionArray64 keyExpr, ast_Integer sequenceSize);
#define ast_DynamicInitializerFrameCreateChild(_parent, _id, expr, keyExpr, sequenceSize) _ast_DynamicInitializerFrameCreateChild(_parent, _id, expr, keyExpr, ast_Integer(sequenceSize))
#define ast_DynamicInitializerFrameCreateChild_auto(_parent, _id, expr, keyExpr, sequenceSize) ast_DynamicInitializerFrame* _id = ast_DynamicInitializerFrameCreateChild(_parent, #_id, expr, keyExpr, sequenceSize); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DynamicInitializerFrameUpdate(ast_DynamicInitializerFrame* _this, ast_ExpressionArray64 expr, ast_ExpressionArray64 keyExpr, ast_Integer sequenceSize);
#define ast_DynamicInitializerFrameUpdate(_this, expr, keyExpr, sequenceSize) _ast_DynamicInitializerFrameUpdate(ast_DynamicInitializerFrame(_this), expr, keyExpr, ast_Integer(sequenceSize))

CORTO_AST_EXPORT ast_DynamicInitializerFrame* _ast_DynamicInitializerFrameDeclare(void);
#define ast_DynamicInitializerFrameDeclare() _ast_DynamicInitializerFrameDeclare()
#define ast_DynamicInitializerFrameDeclare_auto(_id) ast_DynamicInitializerFrame* _id = ast_DynamicInitializerFrameDeclare(); (void)_id
CORTO_AST_EXPORT ast_DynamicInitializerFrame* _ast_DynamicInitializerFrameDeclareChild(corto_object _parent, corto_string _id);
#define ast_DynamicInitializerFrameDeclareChild(_parent, _id) _ast_DynamicInitializerFrameDeclareChild(_parent, _id)
#define ast_DynamicInitializerFrameDeclareChild_auto(_parent, _id) ast_DynamicInitializerFrame* _id = ast_DynamicInitializerFrameDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_DynamicInitializerFrameDefine(ast_DynamicInitializerFrame* _this, ast_ExpressionArray64 expr, ast_ExpressionArray64 keyExpr, ast_Integer sequenceSize);
#define ast_DynamicInitializerFrameDefine(_this, expr, keyExpr, sequenceSize) _ast_DynamicInitializerFrameDefine(ast_DynamicInitializerFrame(_this), expr, keyExpr, ast_Integer(sequenceSize))
CORTO_AST_EXPORT ast_DynamicInitializerFrame* _ast_DynamicInitializerFrameAssign(ast_DynamicInitializerFrame* _this, ast_ExpressionArray64 expr, ast_ExpressionArray64 keyExpr, ast_Integer sequenceSize);
#define ast_DynamicInitializerFrame__optional_NotSet NULL
#define ast_DynamicInitializerFrame__optional_Set(expr, keyExpr, sequenceSize) ast_DynamicInitializerFrameAssign((ast_DynamicInitializerFrame*)corto_calloc(sizeof(ast_DynamicInitializerFrame)), expr, keyExpr, sequenceSize)
#define ast_DynamicInitializerFrame__optional_SetCond(cond, expr, keyExpr, sequenceSize) cond ? ast_DynamicInitializerFrameAssign((ast_DynamicInitializerFrame*)corto_calloc(sizeof(ast_DynamicInitializerFrame)), expr, keyExpr, sequenceSize) : NULL
#define ast_DynamicInitializerFrameUnset(_this) _this ? corto_deinitp(_this, ast_DynamicInitializerFrame_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_DynamicInitializerFrameAssign(_this, expr, keyExpr, sequenceSize) _ast_DynamicInitializerFrameAssign(_this, expr, keyExpr, ast_Integer(sequenceSize))
#define ast_DynamicInitializerFrameSet(_this, expr, keyExpr, sequenceSize) _this = _this ? _this : (ast_DynamicInitializerFrame*)corto_calloc(sizeof(ast_DynamicInitializerFrame)); _ast_DynamicInitializerFrameAssign(_this, expr, keyExpr, ast_Integer(sequenceSize))
CORTO_AST_EXPORT corto_string _ast_DynamicInitializerFrameStr(ast_DynamicInitializerFrame* value);
#define ast_DynamicInitializerFrameStr(value) _ast_DynamicInitializerFrameStr(value)
CORTO_AST_EXPORT ast_DynamicInitializerFrame* ast_DynamicInitializerFrameFromStr(ast_DynamicInitializerFrame* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_DynamicInitializerFrameCompare(ast_DynamicInitializerFrame* dst, ast_DynamicInitializerFrame* src);

CORTO_AST_EXPORT corto_int16 _ast_DynamicInitializerFrameInit(ast_DynamicInitializerFrame* value);
#define ast_DynamicInitializerFrameInit(value) _ast_DynamicInitializerFrameInit(value)
CORTO_AST_EXPORT corto_int16 _ast_DynamicInitializerFrameDeinit(ast_DynamicInitializerFrame* value);
#define ast_DynamicInitializerFrameDeinit(value) _ast_DynamicInitializerFrameDeinit(value)

/* /corto/ast/Element */
CORTO_AST_EXPORT ast_Element _ast_ElementCreate(ast_Expression lvalue, ast_Expression rvalue);
#define ast_ElementCreate(lvalue, rvalue) _ast_ElementCreate(ast_Expression(lvalue), ast_Expression(rvalue))
#define ast_ElementCreate_auto(_id, lvalue, rvalue) ast_Element _id = ast_ElementCreate(lvalue, rvalue); (void)_id
CORTO_AST_EXPORT ast_Element _ast_ElementCreateChild(corto_object _parent, corto_string _id, ast_Expression lvalue, ast_Expression rvalue);
#define ast_ElementCreateChild(_parent, _id, lvalue, rvalue) _ast_ElementCreateChild(_parent, _id, ast_Expression(lvalue), ast_Expression(rvalue))
#define ast_ElementCreateChild_auto(_parent, _id, lvalue, rvalue) ast_Element _id = ast_ElementCreateChild(_parent, #_id, lvalue, rvalue); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ElementUpdate(ast_Element _this, ast_Expression lvalue, ast_Expression rvalue);
#define ast_ElementUpdate(_this, lvalue, rvalue) _ast_ElementUpdate(ast_Element(_this), ast_Expression(lvalue), ast_Expression(rvalue))

CORTO_AST_EXPORT ast_Element _ast_ElementDeclare(void);
#define ast_ElementDeclare() _ast_ElementDeclare()
#define ast_ElementDeclare_auto(_id) ast_Element _id = ast_ElementDeclare(); (void)_id
CORTO_AST_EXPORT ast_Element _ast_ElementDeclareChild(corto_object _parent, corto_string _id);
#define ast_ElementDeclareChild(_parent, _id) _ast_ElementDeclareChild(_parent, _id)
#define ast_ElementDeclareChild_auto(_parent, _id) ast_Element _id = ast_ElementDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ElementDefine(ast_Element _this, ast_Expression lvalue, ast_Expression rvalue);
#define ast_ElementDefine(_this, lvalue, rvalue) _ast_ElementDefine(ast_Element(_this), ast_Expression(lvalue), ast_Expression(rvalue))
CORTO_AST_EXPORT ast_Element _ast_ElementAssign(ast_Element _this, ast_Expression lvalue, ast_Expression rvalue);
#define ast_Element__optional_NotSet NULL
#define ast_Element__optional_Set(lvalue, rvalue) ast_ElementAssign((ast_Element*)corto_calloc(sizeof(ast_Element)), lvalue, rvalue)
#define ast_Element__optional_SetCond(cond, lvalue, rvalue) cond ? ast_ElementAssign((ast_Element*)corto_calloc(sizeof(ast_Element)), lvalue, rvalue) : NULL
#define ast_ElementUnset(_this) _this ? corto_deinitp(_this, ast_Element_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_ElementAssign(_this, lvalue, rvalue) _ast_ElementAssign(_this, ast_Expression(lvalue), ast_Expression(rvalue))
#define ast_ElementSet(_this, lvalue, rvalue) _this = _this ? _this : (ast_Element*)corto_calloc(sizeof(ast_Element)); _ast_ElementAssign(_this, ast_Expression(lvalue), ast_Expression(rvalue))
CORTO_AST_EXPORT corto_string _ast_ElementStr(ast_Element value);
#define ast_ElementStr(value) _ast_ElementStr(ast_Element(value))
CORTO_AST_EXPORT ast_Element ast_ElementFromStr(ast_Element value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_ElementCompare(ast_Element dst, ast_Element src);
#define ast_ElementCompare(dst, src) _ast_ElementCompare(ast_Element(dst), ast_Element(src))

/* /corto/ast/Expression */
CORTO_AST_EXPORT ast_Expression _ast_ExpressionCreate(ast_nodeKind kind);
#define ast_ExpressionCreate(kind) _ast_ExpressionCreate(kind)
#define ast_ExpressionCreate_auto(_id, kind) ast_Expression _id = ast_ExpressionCreate(kind); (void)_id
CORTO_AST_EXPORT ast_Expression _ast_ExpressionCreateChild(corto_object _parent, corto_string _id, ast_nodeKind kind);
#define ast_ExpressionCreateChild(_parent, _id, kind) _ast_ExpressionCreateChild(_parent, _id, kind)
#define ast_ExpressionCreateChild_auto(_parent, _id, kind) ast_Expression _id = ast_ExpressionCreateChild(_parent, #_id, kind); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ExpressionUpdate(ast_Expression _this, ast_nodeKind kind);
#define ast_ExpressionUpdate(_this, kind) _ast_ExpressionUpdate(ast_Expression(_this), kind)

CORTO_AST_EXPORT ast_Expression _ast_ExpressionDeclare(void);
#define ast_ExpressionDeclare() _ast_ExpressionDeclare()
#define ast_ExpressionDeclare_auto(_id) ast_Expression _id = ast_ExpressionDeclare(); (void)_id
CORTO_AST_EXPORT ast_Expression _ast_ExpressionDeclareChild(corto_object _parent, corto_string _id);
#define ast_ExpressionDeclareChild(_parent, _id) _ast_ExpressionDeclareChild(_parent, _id)
#define ast_ExpressionDeclareChild_auto(_parent, _id) ast_Expression _id = ast_ExpressionDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ExpressionDefine(ast_Expression _this, ast_nodeKind kind);
#define ast_ExpressionDefine(_this, kind) _ast_ExpressionDefine(ast_Expression(_this), kind)
CORTO_AST_EXPORT ast_Expression _ast_ExpressionAssign(ast_Expression _this, ast_nodeKind kind);
#define ast_Expression__optional_NotSet NULL
#define ast_Expression__optional_Set(kind) ast_ExpressionAssign((ast_Expression*)corto_calloc(sizeof(ast_Expression)), kind)
#define ast_Expression__optional_SetCond(cond, kind) cond ? ast_ExpressionAssign((ast_Expression*)corto_calloc(sizeof(ast_Expression)), kind) : NULL
#define ast_ExpressionUnset(_this) _this ? corto_deinitp(_this, ast_Expression_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_ExpressionAssign(_this, kind) _ast_ExpressionAssign(_this, kind)
#define ast_ExpressionSet(_this, kind) _this = _this ? _this : (ast_Expression*)corto_calloc(sizeof(ast_Expression)); _ast_ExpressionAssign(_this, kind)
CORTO_AST_EXPORT corto_string _ast_ExpressionStr(ast_Expression value);
#define ast_ExpressionStr(value) _ast_ExpressionStr(ast_Expression(value))
CORTO_AST_EXPORT ast_Expression ast_ExpressionFromStr(ast_Expression value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_ExpressionCompare(ast_Expression dst, ast_Expression src);
#define ast_ExpressionCompare(dst, src) _ast_ExpressionCompare(ast_Expression(dst), ast_Expression(src))

/* /corto/ast/FloatingPoint */
CORTO_AST_EXPORT ast_FloatingPoint _ast_FloatingPointCreate(corto_float64 value);
#define ast_FloatingPointCreate(value) _ast_FloatingPointCreate(value)
#define ast_FloatingPointCreate_auto(_id, value) ast_FloatingPoint _id = ast_FloatingPointCreate(value); (void)_id
CORTO_AST_EXPORT ast_FloatingPoint _ast_FloatingPointCreateChild(corto_object _parent, corto_string _id, corto_float64 value);
#define ast_FloatingPointCreateChild(_parent, _id, value) _ast_FloatingPointCreateChild(_parent, _id, value)
#define ast_FloatingPointCreateChild_auto(_parent, _id, value) ast_FloatingPoint _id = ast_FloatingPointCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_FloatingPointUpdate(ast_FloatingPoint _this, corto_float64 value);
#define ast_FloatingPointUpdate(_this, value) _ast_FloatingPointUpdate(ast_FloatingPoint(_this), value)

CORTO_AST_EXPORT ast_FloatingPoint _ast_FloatingPointDeclare(void);
#define ast_FloatingPointDeclare() _ast_FloatingPointDeclare()
#define ast_FloatingPointDeclare_auto(_id) ast_FloatingPoint _id = ast_FloatingPointDeclare(); (void)_id
CORTO_AST_EXPORT ast_FloatingPoint _ast_FloatingPointDeclareChild(corto_object _parent, corto_string _id);
#define ast_FloatingPointDeclareChild(_parent, _id) _ast_FloatingPointDeclareChild(_parent, _id)
#define ast_FloatingPointDeclareChild_auto(_parent, _id) ast_FloatingPoint _id = ast_FloatingPointDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_FloatingPointDefine(ast_FloatingPoint _this, corto_float64 value);
#define ast_FloatingPointDefine(_this, value) _ast_FloatingPointDefine(ast_FloatingPoint(_this), value)
CORTO_AST_EXPORT ast_FloatingPoint _ast_FloatingPointAssign(ast_FloatingPoint _this, corto_float64 value);
#define ast_FloatingPoint__optional_NotSet NULL
#define ast_FloatingPoint__optional_Set(value) ast_FloatingPointAssign((ast_FloatingPoint*)corto_calloc(sizeof(ast_FloatingPoint)), value)
#define ast_FloatingPoint__optional_SetCond(cond, value) cond ? ast_FloatingPointAssign((ast_FloatingPoint*)corto_calloc(sizeof(ast_FloatingPoint)), value) : NULL
#define ast_FloatingPointUnset(_this) _this ? corto_deinitp(_this, ast_FloatingPoint_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_FloatingPointAssign(_this, value) _ast_FloatingPointAssign(_this, value)
#define ast_FloatingPointSet(_this, value) _this = _this ? _this : (ast_FloatingPoint*)corto_calloc(sizeof(ast_FloatingPoint)); _ast_FloatingPointAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_FloatingPointStr(ast_FloatingPoint value);
#define ast_FloatingPointStr(value) _ast_FloatingPointStr(ast_FloatingPoint(value))
CORTO_AST_EXPORT ast_FloatingPoint ast_FloatingPointFromStr(ast_FloatingPoint value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_FloatingPointCompare(ast_FloatingPoint dst, ast_FloatingPoint src);
#define ast_FloatingPointCompare(dst, src) _ast_FloatingPointCompare(ast_FloatingPoint(dst), ast_FloatingPoint(src))

/* /corto/ast/If */
CORTO_AST_EXPORT ast_If _ast_IfCreate(ast_Expression condition, ast_Block trueBranch, ast_If falseBranch);
#define ast_IfCreate(condition, trueBranch, falseBranch) _ast_IfCreate(ast_Expression(condition), ast_Block(trueBranch), ast_If(falseBranch))
#define ast_IfCreate_auto(_id, condition, trueBranch, falseBranch) ast_If _id = ast_IfCreate(condition, trueBranch, falseBranch); (void)_id
CORTO_AST_EXPORT ast_If _ast_IfCreateChild(corto_object _parent, corto_string _id, ast_Expression condition, ast_Block trueBranch, ast_If falseBranch);
#define ast_IfCreateChild(_parent, _id, condition, trueBranch, falseBranch) _ast_IfCreateChild(_parent, _id, ast_Expression(condition), ast_Block(trueBranch), ast_If(falseBranch))
#define ast_IfCreateChild_auto(_parent, _id, condition, trueBranch, falseBranch) ast_If _id = ast_IfCreateChild(_parent, #_id, condition, trueBranch, falseBranch); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_IfUpdate(ast_If _this, ast_Expression condition, ast_Block trueBranch, ast_If falseBranch);
#define ast_IfUpdate(_this, condition, trueBranch, falseBranch) _ast_IfUpdate(ast_If(_this), ast_Expression(condition), ast_Block(trueBranch), ast_If(falseBranch))

CORTO_AST_EXPORT ast_If _ast_IfDeclare(void);
#define ast_IfDeclare() _ast_IfDeclare()
#define ast_IfDeclare_auto(_id) ast_If _id = ast_IfDeclare(); (void)_id
CORTO_AST_EXPORT ast_If _ast_IfDeclareChild(corto_object _parent, corto_string _id);
#define ast_IfDeclareChild(_parent, _id) _ast_IfDeclareChild(_parent, _id)
#define ast_IfDeclareChild_auto(_parent, _id) ast_If _id = ast_IfDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_IfDefine(ast_If _this, ast_Expression condition, ast_Block trueBranch, ast_If falseBranch);
#define ast_IfDefine(_this, condition, trueBranch, falseBranch) _ast_IfDefine(ast_If(_this), ast_Expression(condition), ast_Block(trueBranch), ast_If(falseBranch))
CORTO_AST_EXPORT ast_If _ast_IfAssign(ast_If _this, ast_Expression condition, ast_Block trueBranch, ast_If falseBranch);
#define ast_If__optional_NotSet NULL
#define ast_If__optional_Set(condition, trueBranch, falseBranch) ast_IfAssign((ast_If*)corto_calloc(sizeof(ast_If)), condition, trueBranch, falseBranch)
#define ast_If__optional_SetCond(cond, condition, trueBranch, falseBranch) cond ? ast_IfAssign((ast_If*)corto_calloc(sizeof(ast_If)), condition, trueBranch, falseBranch) : NULL
#define ast_IfUnset(_this) _this ? corto_deinitp(_this, ast_If_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_IfAssign(_this, condition, trueBranch, falseBranch) _ast_IfAssign(_this, ast_Expression(condition), ast_Block(trueBranch), ast_If(falseBranch))
#define ast_IfSet(_this, condition, trueBranch, falseBranch) _this = _this ? _this : (ast_If*)corto_calloc(sizeof(ast_If)); _ast_IfAssign(_this, ast_Expression(condition), ast_Block(trueBranch), ast_If(falseBranch))
CORTO_AST_EXPORT corto_string _ast_IfStr(ast_If value);
#define ast_IfStr(value) _ast_IfStr(ast_If(value))
CORTO_AST_EXPORT ast_If ast_IfFromStr(ast_If value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_IfCompare(ast_If dst, ast_If src);
#define ast_IfCompare(dst, src) _ast_IfCompare(ast_If(dst), ast_If(src))

/* /corto/ast/Init */
CORTO_AST_EXPORT ast_Init _ast_InitCreate(ast_Storage storage);
#define ast_InitCreate(storage) _ast_InitCreate(ast_Storage(storage))
#define ast_InitCreate_auto(_id, storage) ast_Init _id = ast_InitCreate(storage); (void)_id
CORTO_AST_EXPORT ast_Init _ast_InitCreateChild(corto_object _parent, corto_string _id, ast_Storage storage);
#define ast_InitCreateChild(_parent, _id, storage) _ast_InitCreateChild(_parent, _id, ast_Storage(storage))
#define ast_InitCreateChild_auto(_parent, _id, storage) ast_Init _id = ast_InitCreateChild(_parent, #_id, storage); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitUpdate(ast_Init _this, ast_Storage storage);
#define ast_InitUpdate(_this, storage) _ast_InitUpdate(ast_Init(_this), ast_Storage(storage))

CORTO_AST_EXPORT ast_Init _ast_InitDeclare(void);
#define ast_InitDeclare() _ast_InitDeclare()
#define ast_InitDeclare_auto(_id) ast_Init _id = ast_InitDeclare(); (void)_id
CORTO_AST_EXPORT ast_Init _ast_InitDeclareChild(corto_object _parent, corto_string _id);
#define ast_InitDeclareChild(_parent, _id) _ast_InitDeclareChild(_parent, _id)
#define ast_InitDeclareChild_auto(_parent, _id) ast_Init _id = ast_InitDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitDefine(ast_Init _this, ast_Storage storage);
#define ast_InitDefine(_this, storage) _ast_InitDefine(ast_Init(_this), ast_Storage(storage))
CORTO_AST_EXPORT ast_Init _ast_InitAssign(ast_Init _this, ast_Storage storage);
#define ast_Init__optional_NotSet NULL
#define ast_Init__optional_Set(storage) ast_InitAssign((ast_Init*)corto_calloc(sizeof(ast_Init)), storage)
#define ast_Init__optional_SetCond(cond, storage) cond ? ast_InitAssign((ast_Init*)corto_calloc(sizeof(ast_Init)), storage) : NULL
#define ast_InitUnset(_this) _this ? corto_deinitp(_this, ast_Init_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_InitAssign(_this, storage) _ast_InitAssign(_this, ast_Storage(storage))
#define ast_InitSet(_this, storage) _this = _this ? _this : (ast_Init*)corto_calloc(sizeof(ast_Init)); _ast_InitAssign(_this, ast_Storage(storage))
CORTO_AST_EXPORT corto_string _ast_InitStr(ast_Init value);
#define ast_InitStr(value) _ast_InitStr(ast_Init(value))
CORTO_AST_EXPORT ast_Init ast_InitFromStr(ast_Init value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_InitCompare(ast_Init dst, ast_Init src);
#define ast_InitCompare(dst, src) _ast_InitCompare(ast_Init(dst), ast_Init(src))

/* /corto/ast/Initializer */
CORTO_AST_EXPORT ast_Initializer _ast_InitializerCreate(ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_InitializerCreate(variables, variableCount) _ast_InitializerCreate(variables, variableCount)
#define ast_InitializerCreate_auto(_id, variables, variableCount) ast_Initializer _id = ast_InitializerCreate(variables, variableCount); (void)_id
CORTO_AST_EXPORT ast_Initializer _ast_InitializerCreateChild(corto_object _parent, corto_string _id, ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_InitializerCreateChild(_parent, _id, variables, variableCount) _ast_InitializerCreateChild(_parent, _id, variables, variableCount)
#define ast_InitializerCreateChild_auto(_parent, _id, variables, variableCount) ast_Initializer _id = ast_InitializerCreateChild(_parent, #_id, variables, variableCount); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerUpdate(ast_Initializer _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_InitializerUpdate(_this, variables, variableCount) _ast_InitializerUpdate(ast_Initializer(_this), variables, variableCount)

CORTO_AST_EXPORT ast_Initializer _ast_InitializerDeclare(void);
#define ast_InitializerDeclare() _ast_InitializerDeclare()
#define ast_InitializerDeclare_auto(_id) ast_Initializer _id = ast_InitializerDeclare(); (void)_id
CORTO_AST_EXPORT ast_Initializer _ast_InitializerDeclareChild(corto_object _parent, corto_string _id);
#define ast_InitializerDeclareChild(_parent, _id) _ast_InitializerDeclareChild(_parent, _id)
#define ast_InitializerDeclareChild_auto(_parent, _id) ast_Initializer _id = ast_InitializerDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerDefine(ast_Initializer _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_InitializerDefine(_this, variables, variableCount) _ast_InitializerDefine(ast_Initializer(_this), variables, variableCount)
CORTO_AST_EXPORT ast_Initializer _ast_InitializerAssign(ast_Initializer _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_Initializer__optional_NotSet NULL
#define ast_Initializer__optional_Set(variables, variableCount) ast_InitializerAssign((ast_Initializer*)corto_calloc(sizeof(ast_Initializer)), variables, variableCount)
#define ast_Initializer__optional_SetCond(cond, variables, variableCount) cond ? ast_InitializerAssign((ast_Initializer*)corto_calloc(sizeof(ast_Initializer)), variables, variableCount) : NULL
#define ast_InitializerUnset(_this) _this ? corto_deinitp(_this, ast_Initializer_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_InitializerAssign(_this, variables, variableCount) _ast_InitializerAssign(_this, variables, variableCount)
#define ast_InitializerSet(_this, variables, variableCount) _this = _this ? _this : (ast_Initializer*)corto_calloc(sizeof(ast_Initializer)); _ast_InitializerAssign(_this, variables, variableCount)
CORTO_AST_EXPORT corto_string _ast_InitializerStr(ast_Initializer value);
#define ast_InitializerStr(value) _ast_InitializerStr(ast_Initializer(value))
CORTO_AST_EXPORT ast_Initializer ast_InitializerFromStr(ast_Initializer value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_InitializerCompare(ast_Initializer dst, ast_Initializer src);
#define ast_InitializerCompare(dst, src) _ast_InitializerCompare(ast_Initializer(dst), ast_Initializer(src))

/* /corto/ast/InitializerExpression */
CORTO_AST_EXPORT ast_InitializerExpression _ast_InitializerExpressionCreate(ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_InitializerExpressionCreate(variables, variableCount, assignValue) _ast_InitializerExpressionCreate(variables, variableCount, assignValue)
#define ast_InitializerExpressionCreate_auto(_id, variables, variableCount, assignValue) ast_InitializerExpression _id = ast_InitializerExpressionCreate(variables, variableCount, assignValue); (void)_id
CORTO_AST_EXPORT ast_InitializerExpression _ast_InitializerExpressionCreateChild(corto_object _parent, corto_string _id, ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_InitializerExpressionCreateChild(_parent, _id, variables, variableCount, assignValue) _ast_InitializerExpressionCreateChild(_parent, _id, variables, variableCount, assignValue)
#define ast_InitializerExpressionCreateChild_auto(_parent, _id, variables, variableCount, assignValue) ast_InitializerExpression _id = ast_InitializerExpressionCreateChild(_parent, #_id, variables, variableCount, assignValue); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerExpressionUpdate(ast_InitializerExpression _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_InitializerExpressionUpdate(_this, variables, variableCount, assignValue) _ast_InitializerExpressionUpdate(ast_InitializerExpression(_this), variables, variableCount, assignValue)

CORTO_AST_EXPORT ast_InitializerExpression _ast_InitializerExpressionDeclare(void);
#define ast_InitializerExpressionDeclare() _ast_InitializerExpressionDeclare()
#define ast_InitializerExpressionDeclare_auto(_id) ast_InitializerExpression _id = ast_InitializerExpressionDeclare(); (void)_id
CORTO_AST_EXPORT ast_InitializerExpression _ast_InitializerExpressionDeclareChild(corto_object _parent, corto_string _id);
#define ast_InitializerExpressionDeclareChild(_parent, _id) _ast_InitializerExpressionDeclareChild(_parent, _id)
#define ast_InitializerExpressionDeclareChild_auto(_parent, _id) ast_InitializerExpression _id = ast_InitializerExpressionDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerExpressionDefine(ast_InitializerExpression _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_InitializerExpressionDefine(_this, variables, variableCount, assignValue) _ast_InitializerExpressionDefine(ast_InitializerExpression(_this), variables, variableCount, assignValue)
CORTO_AST_EXPORT ast_InitializerExpression _ast_InitializerExpressionAssign(ast_InitializerExpression _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount, corto_bool assignValue);
#define ast_InitializerExpression__optional_NotSet NULL
#define ast_InitializerExpression__optional_Set(variables, variableCount, assignValue) ast_InitializerExpressionAssign((ast_InitializerExpression*)corto_calloc(sizeof(ast_InitializerExpression)), variables, variableCount, assignValue)
#define ast_InitializerExpression__optional_SetCond(cond, variables, variableCount, assignValue) cond ? ast_InitializerExpressionAssign((ast_InitializerExpression*)corto_calloc(sizeof(ast_InitializerExpression)), variables, variableCount, assignValue) : NULL
#define ast_InitializerExpressionUnset(_this) _this ? corto_deinitp(_this, ast_InitializerExpression_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_InitializerExpressionAssign(_this, variables, variableCount, assignValue) _ast_InitializerExpressionAssign(_this, variables, variableCount, assignValue)
#define ast_InitializerExpressionSet(_this, variables, variableCount, assignValue) _this = _this ? _this : (ast_InitializerExpression*)corto_calloc(sizeof(ast_InitializerExpression)); _ast_InitializerExpressionAssign(_this, variables, variableCount, assignValue)
CORTO_AST_EXPORT corto_string _ast_InitializerExpressionStr(ast_InitializerExpression value);
#define ast_InitializerExpressionStr(value) _ast_InitializerExpressionStr(ast_InitializerExpression(value))
CORTO_AST_EXPORT ast_InitializerExpression ast_InitializerExpressionFromStr(ast_InitializerExpression value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_InitializerExpressionCompare(ast_InitializerExpression dst, ast_InitializerExpression src);
#define ast_InitializerExpressionCompare(dst, src) _ast_InitializerExpressionCompare(ast_InitializerExpression(dst), ast_InitializerExpression(src))

/* /corto/ast/InitializerFrame */
CORTO_AST_EXPORT ast_InitializerFrame* _ast_InitializerFrameCreate(corto_uint32 location, corto_type type, corto_bool isKey, corto_member member);
#define ast_InitializerFrameCreate(location, type, isKey, member) _ast_InitializerFrameCreate(location, corto_type(type), isKey, corto_member(member))
#define ast_InitializerFrameCreate_auto(_id, location, type, isKey, member) ast_InitializerFrame* _id = ast_InitializerFrameCreate(location, type, isKey, member); (void)_id
CORTO_AST_EXPORT ast_InitializerFrame* _ast_InitializerFrameCreateChild(corto_object _parent, corto_string _id, corto_uint32 location, corto_type type, corto_bool isKey, corto_member member);
#define ast_InitializerFrameCreateChild(_parent, _id, location, type, isKey, member) _ast_InitializerFrameCreateChild(_parent, _id, location, corto_type(type), isKey, corto_member(member))
#define ast_InitializerFrameCreateChild_auto(_parent, _id, location, type, isKey, member) ast_InitializerFrame* _id = ast_InitializerFrameCreateChild(_parent, #_id, location, type, isKey, member); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerFrameUpdate(ast_InitializerFrame* _this, corto_uint32 location, corto_type type, corto_bool isKey, corto_member member);
#define ast_InitializerFrameUpdate(_this, location, type, isKey, member) _ast_InitializerFrameUpdate(ast_InitializerFrame(_this), location, corto_type(type), isKey, corto_member(member))

CORTO_AST_EXPORT ast_InitializerFrame* _ast_InitializerFrameDeclare(void);
#define ast_InitializerFrameDeclare() _ast_InitializerFrameDeclare()
#define ast_InitializerFrameDeclare_auto(_id) ast_InitializerFrame* _id = ast_InitializerFrameDeclare(); (void)_id
CORTO_AST_EXPORT ast_InitializerFrame* _ast_InitializerFrameDeclareChild(corto_object _parent, corto_string _id);
#define ast_InitializerFrameDeclareChild(_parent, _id) _ast_InitializerFrameDeclareChild(_parent, _id)
#define ast_InitializerFrameDeclareChild_auto(_parent, _id) ast_InitializerFrame* _id = ast_InitializerFrameDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerFrameDefine(ast_InitializerFrame* _this, corto_uint32 location, corto_type type, corto_bool isKey, corto_member member);
#define ast_InitializerFrameDefine(_this, location, type, isKey, member) _ast_InitializerFrameDefine(ast_InitializerFrame(_this), location, corto_type(type), isKey, corto_member(member))
CORTO_AST_EXPORT ast_InitializerFrame* _ast_InitializerFrameAssign(ast_InitializerFrame* _this, corto_uint32 location, corto_type type, corto_bool isKey, corto_member member);
#define ast_InitializerFrame__optional_NotSet NULL
#define ast_InitializerFrame__optional_Set(location, type, isKey, member) ast_InitializerFrameAssign((ast_InitializerFrame*)corto_calloc(sizeof(ast_InitializerFrame)), location, type, isKey, member)
#define ast_InitializerFrame__optional_SetCond(cond, location, type, isKey, member) cond ? ast_InitializerFrameAssign((ast_InitializerFrame*)corto_calloc(sizeof(ast_InitializerFrame)), location, type, isKey, member) : NULL
#define ast_InitializerFrameUnset(_this) _this ? corto_deinitp(_this, ast_InitializerFrame_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_InitializerFrameAssign(_this, location, type, isKey, member) _ast_InitializerFrameAssign(_this, location, corto_type(type), isKey, corto_member(member))
#define ast_InitializerFrameSet(_this, location, type, isKey, member) _this = _this ? _this : (ast_InitializerFrame*)corto_calloc(sizeof(ast_InitializerFrame)); _ast_InitializerFrameAssign(_this, location, corto_type(type), isKey, corto_member(member))
CORTO_AST_EXPORT corto_string _ast_InitializerFrameStr(ast_InitializerFrame* value);
#define ast_InitializerFrameStr(value) _ast_InitializerFrameStr(value)
CORTO_AST_EXPORT ast_InitializerFrame* ast_InitializerFrameFromStr(ast_InitializerFrame* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_InitializerFrameCompare(ast_InitializerFrame* dst, ast_InitializerFrame* src);

CORTO_AST_EXPORT corto_int16 _ast_InitializerFrameInit(ast_InitializerFrame* value);
#define ast_InitializerFrameInit(value) _ast_InitializerFrameInit(value)
CORTO_AST_EXPORT corto_int16 _ast_InitializerFrameDeinit(ast_InitializerFrame* value);
#define ast_InitializerFrameDeinit(value) _ast_InitializerFrameDeinit(value)

/* /corto/ast/InitializerKind */
CORTO_AST_EXPORT ast_InitializerKind* _ast_InitializerKindCreate(ast_InitializerKind value);
#define ast_InitializerKindCreate(value) _ast_InitializerKindCreate(value)
#define ast_InitializerKindCreate_auto(_id, value) ast_InitializerKind* _id = ast_InitializerKindCreate(value); (void)_id
CORTO_AST_EXPORT ast_InitializerKind* _ast_InitializerKindCreateChild(corto_object _parent, corto_string _id, ast_InitializerKind value);
#define ast_InitializerKindCreateChild(_parent, _id, value) _ast_InitializerKindCreateChild(_parent, _id, value)
#define ast_InitializerKindCreateChild_auto(_parent, _id, value) ast_InitializerKind* _id = ast_InitializerKindCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerKindUpdate(ast_InitializerKind* _this, ast_InitializerKind value);
#define ast_InitializerKindUpdate(_this, value) _ast_InitializerKindUpdate(ast_InitializerKind(_this), value)

CORTO_AST_EXPORT ast_InitializerKind* _ast_InitializerKindDeclare(void);
#define ast_InitializerKindDeclare() _ast_InitializerKindDeclare()
#define ast_InitializerKindDeclare_auto(_id) ast_InitializerKind* _id = ast_InitializerKindDeclare(); (void)_id
CORTO_AST_EXPORT ast_InitializerKind* _ast_InitializerKindDeclareChild(corto_object _parent, corto_string _id);
#define ast_InitializerKindDeclareChild(_parent, _id) _ast_InitializerKindDeclareChild(_parent, _id)
#define ast_InitializerKindDeclareChild_auto(_parent, _id) ast_InitializerKind* _id = ast_InitializerKindDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerKindDefine(ast_InitializerKind* _this, ast_InitializerKind value);
#define ast_InitializerKindDefine(_this, value) _ast_InitializerKindDefine(ast_InitializerKind(_this), value)
CORTO_AST_EXPORT ast_InitializerKind* _ast_InitializerKindAssign(ast_InitializerKind* _this, ast_InitializerKind value);
#define ast_InitializerKind__optional_NotSet NULL
#define ast_InitializerKind__optional_Set(value) ast_InitializerKindAssign((ast_InitializerKind*)corto_calloc(sizeof(ast_InitializerKind)), value)
#define ast_InitializerKind__optional_SetCond(cond, value) cond ? ast_InitializerKindAssign((ast_InitializerKind*)corto_calloc(sizeof(ast_InitializerKind)), value) : NULL
#define ast_InitializerKindUnset(_this) _this ? corto_deinitp(_this, ast_InitializerKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_InitializerKindAssign(_this, value) _ast_InitializerKindAssign(_this, value)
#define ast_InitializerKindSet(_this, value) _this = _this ? _this : (ast_InitializerKind*)corto_calloc(sizeof(ast_InitializerKind)); _ast_InitializerKindAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_InitializerKindStr(ast_InitializerKind value);
#define ast_InitializerKindStr(value) _ast_InitializerKindStr(value)
CORTO_AST_EXPORT ast_InitializerKind* ast_InitializerKindFromStr(ast_InitializerKind* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_InitializerKindCompare(ast_InitializerKind dst, ast_InitializerKind src);

CORTO_AST_EXPORT corto_int16 _ast_InitializerKindInit(ast_InitializerKind* value);
#define ast_InitializerKindInit(value) _ast_InitializerKindInit(value)
CORTO_AST_EXPORT corto_int16 _ast_InitializerKindDeinit(ast_InitializerKind* value);
#define ast_InitializerKindDeinit(value) _ast_InitializerKindDeinit(value)

/* /corto/ast/InitializerVariable */
CORTO_AST_EXPORT ast_InitializerVariable* _ast_InitializerVariableCreate(corto_word offset, ast_Expression object, corto_word key);
#define ast_InitializerVariableCreate(offset, object, key) _ast_InitializerVariableCreate(offset, ast_Expression(object), key)
#define ast_InitializerVariableCreate_auto(_id, offset, object, key) ast_InitializerVariable* _id = ast_InitializerVariableCreate(offset, object, key); (void)_id
CORTO_AST_EXPORT ast_InitializerVariable* _ast_InitializerVariableCreateChild(corto_object _parent, corto_string _id, corto_word offset, ast_Expression object, corto_word key);
#define ast_InitializerVariableCreateChild(_parent, _id, offset, object, key) _ast_InitializerVariableCreateChild(_parent, _id, offset, ast_Expression(object), key)
#define ast_InitializerVariableCreateChild_auto(_parent, _id, offset, object, key) ast_InitializerVariable* _id = ast_InitializerVariableCreateChild(_parent, #_id, offset, object, key); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerVariableUpdate(ast_InitializerVariable* _this, corto_word offset, ast_Expression object, corto_word key);
#define ast_InitializerVariableUpdate(_this, offset, object, key) _ast_InitializerVariableUpdate(ast_InitializerVariable(_this), offset, ast_Expression(object), key)

CORTO_AST_EXPORT ast_InitializerVariable* _ast_InitializerVariableDeclare(void);
#define ast_InitializerVariableDeclare() _ast_InitializerVariableDeclare()
#define ast_InitializerVariableDeclare_auto(_id) ast_InitializerVariable* _id = ast_InitializerVariableDeclare(); (void)_id
CORTO_AST_EXPORT ast_InitializerVariable* _ast_InitializerVariableDeclareChild(corto_object _parent, corto_string _id);
#define ast_InitializerVariableDeclareChild(_parent, _id) _ast_InitializerVariableDeclareChild(_parent, _id)
#define ast_InitializerVariableDeclareChild_auto(_parent, _id) ast_InitializerVariable* _id = ast_InitializerVariableDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitializerVariableDefine(ast_InitializerVariable* _this, corto_word offset, ast_Expression object, corto_word key);
#define ast_InitializerVariableDefine(_this, offset, object, key) _ast_InitializerVariableDefine(ast_InitializerVariable(_this), offset, ast_Expression(object), key)
CORTO_AST_EXPORT ast_InitializerVariable* _ast_InitializerVariableAssign(ast_InitializerVariable* _this, corto_word offset, ast_Expression object, corto_word key);
#define ast_InitializerVariable__optional_NotSet NULL
#define ast_InitializerVariable__optional_Set(offset, object, key) ast_InitializerVariableAssign((ast_InitializerVariable*)corto_calloc(sizeof(ast_InitializerVariable)), offset, object, key)
#define ast_InitializerVariable__optional_SetCond(cond, offset, object, key) cond ? ast_InitializerVariableAssign((ast_InitializerVariable*)corto_calloc(sizeof(ast_InitializerVariable)), offset, object, key) : NULL
#define ast_InitializerVariableUnset(_this) _this ? corto_deinitp(_this, ast_InitializerVariable_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_InitializerVariableAssign(_this, offset, object, key) _ast_InitializerVariableAssign(_this, offset, ast_Expression(object), key)
#define ast_InitializerVariableSet(_this, offset, object, key) _this = _this ? _this : (ast_InitializerVariable*)corto_calloc(sizeof(ast_InitializerVariable)); _ast_InitializerVariableAssign(_this, offset, ast_Expression(object), key)
CORTO_AST_EXPORT corto_string _ast_InitializerVariableStr(ast_InitializerVariable* value);
#define ast_InitializerVariableStr(value) _ast_InitializerVariableStr(value)
CORTO_AST_EXPORT ast_InitializerVariable* ast_InitializerVariableFromStr(ast_InitializerVariable* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_InitializerVariableCompare(ast_InitializerVariable* dst, ast_InitializerVariable* src);

CORTO_AST_EXPORT corto_int16 _ast_InitializerVariableInit(ast_InitializerVariable* value);
#define ast_InitializerVariableInit(value) _ast_InitializerVariableInit(value)
CORTO_AST_EXPORT corto_int16 _ast_InitializerVariableDeinit(ast_InitializerVariable* value);
#define ast_InitializerVariableDeinit(value) _ast_InitializerVariableDeinit(value)

/* /corto/ast/InitOper */
CORTO_AST_EXPORT ast_InitOper* _ast_InitOperCreate(ast_InitOperKind kind, ast_Expression expr, corto_string name);
#define ast_InitOperCreate(kind, expr, name) _ast_InitOperCreate(kind, ast_Expression(expr), name)
#define ast_InitOperCreate_auto(_id, kind, expr, name) ast_InitOper* _id = ast_InitOperCreate(kind, expr, name); (void)_id
CORTO_AST_EXPORT ast_InitOper* _ast_InitOperCreateChild(corto_object _parent, corto_string _id, ast_InitOperKind kind, ast_Expression expr, corto_string name);
#define ast_InitOperCreateChild(_parent, _id, kind, expr, name) _ast_InitOperCreateChild(_parent, _id, kind, ast_Expression(expr), name)
#define ast_InitOperCreateChild_auto(_parent, _id, kind, expr, name) ast_InitOper* _id = ast_InitOperCreateChild(_parent, #_id, kind, expr, name); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitOperUpdate(ast_InitOper* _this, ast_InitOperKind kind, ast_Expression expr, corto_string name);
#define ast_InitOperUpdate(_this, kind, expr, name) _ast_InitOperUpdate(ast_InitOper(_this), kind, ast_Expression(expr), name)

CORTO_AST_EXPORT ast_InitOper* _ast_InitOperDeclare(void);
#define ast_InitOperDeclare() _ast_InitOperDeclare()
#define ast_InitOperDeclare_auto(_id) ast_InitOper* _id = ast_InitOperDeclare(); (void)_id
CORTO_AST_EXPORT ast_InitOper* _ast_InitOperDeclareChild(corto_object _parent, corto_string _id);
#define ast_InitOperDeclareChild(_parent, _id) _ast_InitOperDeclareChild(_parent, _id)
#define ast_InitOperDeclareChild_auto(_parent, _id) ast_InitOper* _id = ast_InitOperDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitOperDefine(ast_InitOper* _this, ast_InitOperKind kind, ast_Expression expr, corto_string name);
#define ast_InitOperDefine(_this, kind, expr, name) _ast_InitOperDefine(ast_InitOper(_this), kind, ast_Expression(expr), name)
CORTO_AST_EXPORT ast_InitOper* _ast_InitOperAssign(ast_InitOper* _this, ast_InitOperKind kind, ast_Expression expr, corto_string name);
#define ast_InitOper__optional_NotSet NULL
#define ast_InitOper__optional_Set(kind, expr, name) ast_InitOperAssign((ast_InitOper*)corto_calloc(sizeof(ast_InitOper)), kind, expr, name)
#define ast_InitOper__optional_SetCond(cond, kind, expr, name) cond ? ast_InitOperAssign((ast_InitOper*)corto_calloc(sizeof(ast_InitOper)), kind, expr, name) : NULL
#define ast_InitOperUnset(_this) _this ? corto_deinitp(_this, ast_InitOper_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_InitOperAssign(_this, kind, expr, name) _ast_InitOperAssign(_this, kind, ast_Expression(expr), name)
#define ast_InitOperSet(_this, kind, expr, name) _this = _this ? _this : (ast_InitOper*)corto_calloc(sizeof(ast_InitOper)); _ast_InitOperAssign(_this, kind, ast_Expression(expr), name)
CORTO_AST_EXPORT corto_string _ast_InitOperStr(ast_InitOper* value);
#define ast_InitOperStr(value) _ast_InitOperStr(value)
CORTO_AST_EXPORT ast_InitOper* ast_InitOperFromStr(ast_InitOper* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_InitOperCompare(ast_InitOper* dst, ast_InitOper* src);

CORTO_AST_EXPORT corto_int16 _ast_InitOperInit(ast_InitOper* value);
#define ast_InitOperInit(value) _ast_InitOperInit(value)
CORTO_AST_EXPORT corto_int16 _ast_InitOperDeinit(ast_InitOper* value);
#define ast_InitOperDeinit(value) _ast_InitOperDeinit(value)

/* /corto/ast/InitOperKind */
CORTO_AST_EXPORT ast_InitOperKind* _ast_InitOperKindCreate(ast_InitOperKind value);
#define ast_InitOperKindCreate(value) _ast_InitOperKindCreate(value)
#define ast_InitOperKindCreate_auto(_id, value) ast_InitOperKind* _id = ast_InitOperKindCreate(value); (void)_id
CORTO_AST_EXPORT ast_InitOperKind* _ast_InitOperKindCreateChild(corto_object _parent, corto_string _id, ast_InitOperKind value);
#define ast_InitOperKindCreateChild(_parent, _id, value) _ast_InitOperKindCreateChild(_parent, _id, value)
#define ast_InitOperKindCreateChild_auto(_parent, _id, value) ast_InitOperKind* _id = ast_InitOperKindCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitOperKindUpdate(ast_InitOperKind* _this, ast_InitOperKind value);
#define ast_InitOperKindUpdate(_this, value) _ast_InitOperKindUpdate(ast_InitOperKind(_this), value)

CORTO_AST_EXPORT ast_InitOperKind* _ast_InitOperKindDeclare(void);
#define ast_InitOperKindDeclare() _ast_InitOperKindDeclare()
#define ast_InitOperKindDeclare_auto(_id) ast_InitOperKind* _id = ast_InitOperKindDeclare(); (void)_id
CORTO_AST_EXPORT ast_InitOperKind* _ast_InitOperKindDeclareChild(corto_object _parent, corto_string _id);
#define ast_InitOperKindDeclareChild(_parent, _id) _ast_InitOperKindDeclareChild(_parent, _id)
#define ast_InitOperKindDeclareChild_auto(_parent, _id) ast_InitOperKind* _id = ast_InitOperKindDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_InitOperKindDefine(ast_InitOperKind* _this, ast_InitOperKind value);
#define ast_InitOperKindDefine(_this, value) _ast_InitOperKindDefine(ast_InitOperKind(_this), value)
CORTO_AST_EXPORT ast_InitOperKind* _ast_InitOperKindAssign(ast_InitOperKind* _this, ast_InitOperKind value);
#define ast_InitOperKind__optional_NotSet NULL
#define ast_InitOperKind__optional_Set(value) ast_InitOperKindAssign((ast_InitOperKind*)corto_calloc(sizeof(ast_InitOperKind)), value)
#define ast_InitOperKind__optional_SetCond(cond, value) cond ? ast_InitOperKindAssign((ast_InitOperKind*)corto_calloc(sizeof(ast_InitOperKind)), value) : NULL
#define ast_InitOperKindUnset(_this) _this ? corto_deinitp(_this, ast_InitOperKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_InitOperKindAssign(_this, value) _ast_InitOperKindAssign(_this, value)
#define ast_InitOperKindSet(_this, value) _this = _this ? _this : (ast_InitOperKind*)corto_calloc(sizeof(ast_InitOperKind)); _ast_InitOperKindAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_InitOperKindStr(ast_InitOperKind value);
#define ast_InitOperKindStr(value) _ast_InitOperKindStr(value)
CORTO_AST_EXPORT ast_InitOperKind* ast_InitOperKindFromStr(ast_InitOperKind* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_InitOperKindCompare(ast_InitOperKind dst, ast_InitOperKind src);

CORTO_AST_EXPORT corto_int16 _ast_InitOperKindInit(ast_InitOperKind* value);
#define ast_InitOperKindInit(value) _ast_InitOperKindInit(value)
CORTO_AST_EXPORT corto_int16 _ast_InitOperKindDeinit(ast_InitOperKind* value);
#define ast_InitOperKindDeinit(value) _ast_InitOperKindDeinit(value)

/* /corto/ast/Integer */
CORTO_AST_EXPORT ast_Integer _ast_IntegerCreate(corto_uint64 value);
#define ast_IntegerCreate(value) _ast_IntegerCreate(value)
#define ast_IntegerCreate_auto(_id, value) ast_Integer _id = ast_IntegerCreate(value); (void)_id
CORTO_AST_EXPORT ast_Integer _ast_IntegerCreateChild(corto_object _parent, corto_string _id, corto_uint64 value);
#define ast_IntegerCreateChild(_parent, _id, value) _ast_IntegerCreateChild(_parent, _id, value)
#define ast_IntegerCreateChild_auto(_parent, _id, value) ast_Integer _id = ast_IntegerCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_IntegerUpdate(ast_Integer _this, corto_uint64 value);
#define ast_IntegerUpdate(_this, value) _ast_IntegerUpdate(ast_Integer(_this), value)

CORTO_AST_EXPORT ast_Integer _ast_IntegerDeclare(void);
#define ast_IntegerDeclare() _ast_IntegerDeclare()
#define ast_IntegerDeclare_auto(_id) ast_Integer _id = ast_IntegerDeclare(); (void)_id
CORTO_AST_EXPORT ast_Integer _ast_IntegerDeclareChild(corto_object _parent, corto_string _id);
#define ast_IntegerDeclareChild(_parent, _id) _ast_IntegerDeclareChild(_parent, _id)
#define ast_IntegerDeclareChild_auto(_parent, _id) ast_Integer _id = ast_IntegerDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_IntegerDefine(ast_Integer _this, corto_uint64 value);
#define ast_IntegerDefine(_this, value) _ast_IntegerDefine(ast_Integer(_this), value)
CORTO_AST_EXPORT ast_Integer _ast_IntegerAssign(ast_Integer _this, corto_uint64 value);
#define ast_Integer__optional_NotSet NULL
#define ast_Integer__optional_Set(value) ast_IntegerAssign((ast_Integer*)corto_calloc(sizeof(ast_Integer)), value)
#define ast_Integer__optional_SetCond(cond, value) cond ? ast_IntegerAssign((ast_Integer*)corto_calloc(sizeof(ast_Integer)), value) : NULL
#define ast_IntegerUnset(_this) _this ? corto_deinitp(_this, ast_Integer_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_IntegerAssign(_this, value) _ast_IntegerAssign(_this, value)
#define ast_IntegerSet(_this, value) _this = _this ? _this : (ast_Integer*)corto_calloc(sizeof(ast_Integer)); _ast_IntegerAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_IntegerStr(ast_Integer value);
#define ast_IntegerStr(value) _ast_IntegerStr(ast_Integer(value))
CORTO_AST_EXPORT ast_Integer ast_IntegerFromStr(ast_Integer value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_IntegerCompare(ast_Integer dst, ast_Integer src);
#define ast_IntegerCompare(dst, src) _ast_IntegerCompare(ast_Integer(dst), ast_Integer(src))

/* /corto/ast/Literal */
CORTO_AST_EXPORT ast_Literal _ast_LiteralCreate(ast_valueKind kind_1);
#define ast_LiteralCreate(kind_1) _ast_LiteralCreate(kind_1)
#define ast_LiteralCreate_auto(_id, kind_1) ast_Literal _id = ast_LiteralCreate(kind_1); (void)_id
CORTO_AST_EXPORT ast_Literal _ast_LiteralCreateChild(corto_object _parent, corto_string _id, ast_valueKind kind_1);
#define ast_LiteralCreateChild(_parent, _id, kind_1) _ast_LiteralCreateChild(_parent, _id, kind_1)
#define ast_LiteralCreateChild_auto(_parent, _id, kind_1) ast_Literal _id = ast_LiteralCreateChild(_parent, #_id, kind_1); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_LiteralUpdate(ast_Literal _this, ast_valueKind kind_1);
#define ast_LiteralUpdate(_this, kind_1) _ast_LiteralUpdate(ast_Literal(_this), kind_1)

CORTO_AST_EXPORT ast_Literal _ast_LiteralDeclare(void);
#define ast_LiteralDeclare() _ast_LiteralDeclare()
#define ast_LiteralDeclare_auto(_id) ast_Literal _id = ast_LiteralDeclare(); (void)_id
CORTO_AST_EXPORT ast_Literal _ast_LiteralDeclareChild(corto_object _parent, corto_string _id);
#define ast_LiteralDeclareChild(_parent, _id) _ast_LiteralDeclareChild(_parent, _id)
#define ast_LiteralDeclareChild_auto(_parent, _id) ast_Literal _id = ast_LiteralDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_LiteralDefine(ast_Literal _this, ast_valueKind kind_1);
#define ast_LiteralDefine(_this, kind_1) _ast_LiteralDefine(ast_Literal(_this), kind_1)
CORTO_AST_EXPORT ast_Literal _ast_LiteralAssign(ast_Literal _this, ast_valueKind kind_1);
#define ast_Literal__optional_NotSet NULL
#define ast_Literal__optional_Set(kind_1) ast_LiteralAssign((ast_Literal*)corto_calloc(sizeof(ast_Literal)), kind_1)
#define ast_Literal__optional_SetCond(cond, kind_1) cond ? ast_LiteralAssign((ast_Literal*)corto_calloc(sizeof(ast_Literal)), kind_1) : NULL
#define ast_LiteralUnset(_this) _this ? corto_deinitp(_this, ast_Literal_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_LiteralAssign(_this, kind_1) _ast_LiteralAssign(_this, kind_1)
#define ast_LiteralSet(_this, kind_1) _this = _this ? _this : (ast_Literal*)corto_calloc(sizeof(ast_Literal)); _ast_LiteralAssign(_this, kind_1)
CORTO_AST_EXPORT corto_string _ast_LiteralStr(ast_Literal value);
#define ast_LiteralStr(value) _ast_LiteralStr(ast_Literal(value))
CORTO_AST_EXPORT ast_Literal ast_LiteralFromStr(ast_Literal value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_LiteralCompare(ast_Literal dst, ast_Literal src);
#define ast_LiteralCompare(dst, src) _ast_LiteralCompare(ast_Literal(dst), ast_Literal(src))

/* /corto/ast/Local */
CORTO_AST_EXPORT ast_Local _ast_LocalCreate(corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_LocalCreate(name, type_1, kind_2, reference) _ast_LocalCreate(name, corto_type(type_1), kind_2, reference)
#define ast_LocalCreate_auto(_id, name, type_1, kind_2, reference) ast_Local _id = ast_LocalCreate(name, type_1, kind_2, reference); (void)_id
CORTO_AST_EXPORT ast_Local _ast_LocalCreateChild(corto_object _parent, corto_string _id, corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_LocalCreateChild(_parent, _id, name, type_1, kind_2, reference) _ast_LocalCreateChild(_parent, _id, name, corto_type(type_1), kind_2, reference)
#define ast_LocalCreateChild_auto(_parent, _id, name, type_1, kind_2, reference) ast_Local _id = ast_LocalCreateChild(_parent, #_id, name, type_1, kind_2, reference); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_LocalUpdate(ast_Local _this, corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_LocalUpdate(_this, name, type_1, kind_2, reference) _ast_LocalUpdate(ast_Local(_this), name, corto_type(type_1), kind_2, reference)

CORTO_AST_EXPORT ast_Local _ast_LocalDeclare(void);
#define ast_LocalDeclare() _ast_LocalDeclare()
#define ast_LocalDeclare_auto(_id) ast_Local _id = ast_LocalDeclare(); (void)_id
CORTO_AST_EXPORT ast_Local _ast_LocalDeclareChild(corto_object _parent, corto_string _id);
#define ast_LocalDeclareChild(_parent, _id) _ast_LocalDeclareChild(_parent, _id)
#define ast_LocalDeclareChild_auto(_parent, _id) ast_Local _id = ast_LocalDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_LocalDefine(ast_Local _this, corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_LocalDefine(_this, name, type_1, kind_2, reference) _ast_LocalDefine(ast_Local(_this), name, corto_type(type_1), kind_2, reference)
CORTO_AST_EXPORT ast_Local _ast_LocalAssign(ast_Local _this, corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_Local__optional_NotSet NULL
#define ast_Local__optional_Set(name, type_1, kind_2, reference) ast_LocalAssign((ast_Local*)corto_calloc(sizeof(ast_Local)), name, type_1, kind_2, reference)
#define ast_Local__optional_SetCond(cond, name, type_1, kind_2, reference) cond ? ast_LocalAssign((ast_Local*)corto_calloc(sizeof(ast_Local)), name, type_1, kind_2, reference) : NULL
#define ast_LocalUnset(_this) _this ? corto_deinitp(_this, ast_Local_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_LocalAssign(_this, name, type_1, kind_2, reference) _ast_LocalAssign(_this, name, corto_type(type_1), kind_2, reference)
#define ast_LocalSet(_this, name, type_1, kind_2, reference) _this = _this ? _this : (ast_Local*)corto_calloc(sizeof(ast_Local)); _ast_LocalAssign(_this, name, corto_type(type_1), kind_2, reference)
CORTO_AST_EXPORT corto_string _ast_LocalStr(ast_Local value);
#define ast_LocalStr(value) _ast_LocalStr(ast_Local(value))
CORTO_AST_EXPORT ast_Local ast_LocalFromStr(ast_Local value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_LocalCompare(ast_Local dst, ast_Local src);
#define ast_LocalCompare(dst, src) _ast_LocalCompare(ast_Local(dst), ast_Local(src))

/* /corto/ast/LocalKind */
CORTO_AST_EXPORT ast_LocalKind* _ast_LocalKindCreate(ast_LocalKind value);
#define ast_LocalKindCreate(value) _ast_LocalKindCreate(value)
#define ast_LocalKindCreate_auto(_id, value) ast_LocalKind* _id = ast_LocalKindCreate(value); (void)_id
CORTO_AST_EXPORT ast_LocalKind* _ast_LocalKindCreateChild(corto_object _parent, corto_string _id, ast_LocalKind value);
#define ast_LocalKindCreateChild(_parent, _id, value) _ast_LocalKindCreateChild(_parent, _id, value)
#define ast_LocalKindCreateChild_auto(_parent, _id, value) ast_LocalKind* _id = ast_LocalKindCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_LocalKindUpdate(ast_LocalKind* _this, ast_LocalKind value);
#define ast_LocalKindUpdate(_this, value) _ast_LocalKindUpdate(ast_LocalKind(_this), value)

CORTO_AST_EXPORT ast_LocalKind* _ast_LocalKindDeclare(void);
#define ast_LocalKindDeclare() _ast_LocalKindDeclare()
#define ast_LocalKindDeclare_auto(_id) ast_LocalKind* _id = ast_LocalKindDeclare(); (void)_id
CORTO_AST_EXPORT ast_LocalKind* _ast_LocalKindDeclareChild(corto_object _parent, corto_string _id);
#define ast_LocalKindDeclareChild(_parent, _id) _ast_LocalKindDeclareChild(_parent, _id)
#define ast_LocalKindDeclareChild_auto(_parent, _id) ast_LocalKind* _id = ast_LocalKindDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_LocalKindDefine(ast_LocalKind* _this, ast_LocalKind value);
#define ast_LocalKindDefine(_this, value) _ast_LocalKindDefine(ast_LocalKind(_this), value)
CORTO_AST_EXPORT ast_LocalKind* _ast_LocalKindAssign(ast_LocalKind* _this, ast_LocalKind value);
#define ast_LocalKind__optional_NotSet NULL
#define ast_LocalKind__optional_Set(value) ast_LocalKindAssign((ast_LocalKind*)corto_calloc(sizeof(ast_LocalKind)), value)
#define ast_LocalKind__optional_SetCond(cond, value) cond ? ast_LocalKindAssign((ast_LocalKind*)corto_calloc(sizeof(ast_LocalKind)), value) : NULL
#define ast_LocalKindUnset(_this) _this ? corto_deinitp(_this, ast_LocalKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_LocalKindAssign(_this, value) _ast_LocalKindAssign(_this, value)
#define ast_LocalKindSet(_this, value) _this = _this ? _this : (ast_LocalKind*)corto_calloc(sizeof(ast_LocalKind)); _ast_LocalKindAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_LocalKindStr(ast_LocalKind value);
#define ast_LocalKindStr(value) _ast_LocalKindStr(value)
CORTO_AST_EXPORT ast_LocalKind* ast_LocalKindFromStr(ast_LocalKind* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_LocalKindCompare(ast_LocalKind dst, ast_LocalKind src);

CORTO_AST_EXPORT corto_int16 _ast_LocalKindInit(ast_LocalKind* value);
#define ast_LocalKindInit(value) _ast_LocalKindInit(value)
CORTO_AST_EXPORT corto_int16 _ast_LocalKindDeinit(ast_LocalKind* value);
#define ast_LocalKindDeinit(value) _ast_LocalKindDeinit(value)

/* /corto/ast/Lvalue */
CORTO_AST_EXPORT ast_Lvalue* _ast_LvalueCreate(ast_Expression expr, corto_bool isAssignment);
#define ast_LvalueCreate(expr, isAssignment) _ast_LvalueCreate(ast_Expression(expr), isAssignment)
#define ast_LvalueCreate_auto(_id, expr, isAssignment) ast_Lvalue* _id = ast_LvalueCreate(expr, isAssignment); (void)_id
CORTO_AST_EXPORT ast_Lvalue* _ast_LvalueCreateChild(corto_object _parent, corto_string _id, ast_Expression expr, corto_bool isAssignment);
#define ast_LvalueCreateChild(_parent, _id, expr, isAssignment) _ast_LvalueCreateChild(_parent, _id, ast_Expression(expr), isAssignment)
#define ast_LvalueCreateChild_auto(_parent, _id, expr, isAssignment) ast_Lvalue* _id = ast_LvalueCreateChild(_parent, #_id, expr, isAssignment); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_LvalueUpdate(ast_Lvalue* _this, ast_Expression expr, corto_bool isAssignment);
#define ast_LvalueUpdate(_this, expr, isAssignment) _ast_LvalueUpdate(ast_Lvalue(_this), ast_Expression(expr), isAssignment)

CORTO_AST_EXPORT ast_Lvalue* _ast_LvalueDeclare(void);
#define ast_LvalueDeclare() _ast_LvalueDeclare()
#define ast_LvalueDeclare_auto(_id) ast_Lvalue* _id = ast_LvalueDeclare(); (void)_id
CORTO_AST_EXPORT ast_Lvalue* _ast_LvalueDeclareChild(corto_object _parent, corto_string _id);
#define ast_LvalueDeclareChild(_parent, _id) _ast_LvalueDeclareChild(_parent, _id)
#define ast_LvalueDeclareChild_auto(_parent, _id) ast_Lvalue* _id = ast_LvalueDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_LvalueDefine(ast_Lvalue* _this, ast_Expression expr, corto_bool isAssignment);
#define ast_LvalueDefine(_this, expr, isAssignment) _ast_LvalueDefine(ast_Lvalue(_this), ast_Expression(expr), isAssignment)
CORTO_AST_EXPORT ast_Lvalue* _ast_LvalueAssign(ast_Lvalue* _this, ast_Expression expr, corto_bool isAssignment);
#define ast_Lvalue__optional_NotSet NULL
#define ast_Lvalue__optional_Set(expr, isAssignment) ast_LvalueAssign((ast_Lvalue*)corto_calloc(sizeof(ast_Lvalue)), expr, isAssignment)
#define ast_Lvalue__optional_SetCond(cond, expr, isAssignment) cond ? ast_LvalueAssign((ast_Lvalue*)corto_calloc(sizeof(ast_Lvalue)), expr, isAssignment) : NULL
#define ast_LvalueUnset(_this) _this ? corto_deinitp(_this, ast_Lvalue_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_LvalueAssign(_this, expr, isAssignment) _ast_LvalueAssign(_this, ast_Expression(expr), isAssignment)
#define ast_LvalueSet(_this, expr, isAssignment) _this = _this ? _this : (ast_Lvalue*)corto_calloc(sizeof(ast_Lvalue)); _ast_LvalueAssign(_this, ast_Expression(expr), isAssignment)
CORTO_AST_EXPORT corto_string _ast_LvalueStr(ast_Lvalue* value);
#define ast_LvalueStr(value) _ast_LvalueStr(value)
CORTO_AST_EXPORT ast_Lvalue* ast_LvalueFromStr(ast_Lvalue* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_LvalueCompare(ast_Lvalue* dst, ast_Lvalue* src);

CORTO_AST_EXPORT corto_int16 _ast_LvalueInit(ast_Lvalue* value);
#define ast_LvalueInit(value) _ast_LvalueInit(value)
CORTO_AST_EXPORT corto_int16 _ast_LvalueDeinit(ast_Lvalue* value);
#define ast_LvalueDeinit(value) _ast_LvalueDeinit(value)

/* /corto/ast/Member */
CORTO_AST_EXPORT ast_Member _ast_MemberCreate(ast_Expression lvalue, ast_Expression rvalue);
#define ast_MemberCreate(lvalue, rvalue) _ast_MemberCreate(ast_Expression(lvalue), ast_Expression(rvalue))
#define ast_MemberCreate_auto(_id, lvalue, rvalue) ast_Member _id = ast_MemberCreate(lvalue, rvalue); (void)_id
CORTO_AST_EXPORT ast_Member _ast_MemberCreateChild(corto_object _parent, corto_string _id, ast_Expression lvalue, ast_Expression rvalue);
#define ast_MemberCreateChild(_parent, _id, lvalue, rvalue) _ast_MemberCreateChild(_parent, _id, ast_Expression(lvalue), ast_Expression(rvalue))
#define ast_MemberCreateChild_auto(_parent, _id, lvalue, rvalue) ast_Member _id = ast_MemberCreateChild(_parent, #_id, lvalue, rvalue); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_MemberUpdate(ast_Member _this, ast_Expression lvalue, ast_Expression rvalue);
#define ast_MemberUpdate(_this, lvalue, rvalue) _ast_MemberUpdate(ast_Member(_this), ast_Expression(lvalue), ast_Expression(rvalue))

CORTO_AST_EXPORT ast_Member _ast_MemberDeclare(void);
#define ast_MemberDeclare() _ast_MemberDeclare()
#define ast_MemberDeclare_auto(_id) ast_Member _id = ast_MemberDeclare(); (void)_id
CORTO_AST_EXPORT ast_Member _ast_MemberDeclareChild(corto_object _parent, corto_string _id);
#define ast_MemberDeclareChild(_parent, _id) _ast_MemberDeclareChild(_parent, _id)
#define ast_MemberDeclareChild_auto(_parent, _id) ast_Member _id = ast_MemberDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_MemberDefine(ast_Member _this, ast_Expression lvalue, ast_Expression rvalue);
#define ast_MemberDefine(_this, lvalue, rvalue) _ast_MemberDefine(ast_Member(_this), ast_Expression(lvalue), ast_Expression(rvalue))
CORTO_AST_EXPORT ast_Member _ast_MemberAssign(ast_Member _this, ast_Expression lvalue, ast_Expression rvalue);
#define ast_Member__optional_NotSet NULL
#define ast_Member__optional_Set(lvalue, rvalue) ast_MemberAssign((ast_Member*)corto_calloc(sizeof(ast_Member)), lvalue, rvalue)
#define ast_Member__optional_SetCond(cond, lvalue, rvalue) cond ? ast_MemberAssign((ast_Member*)corto_calloc(sizeof(ast_Member)), lvalue, rvalue) : NULL
#define ast_MemberUnset(_this) _this ? corto_deinitp(_this, ast_Member_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_MemberAssign(_this, lvalue, rvalue) _ast_MemberAssign(_this, ast_Expression(lvalue), ast_Expression(rvalue))
#define ast_MemberSet(_this, lvalue, rvalue) _this = _this ? _this : (ast_Member*)corto_calloc(sizeof(ast_Member)); _ast_MemberAssign(_this, ast_Expression(lvalue), ast_Expression(rvalue))
CORTO_AST_EXPORT corto_string _ast_MemberStr(ast_Member value);
#define ast_MemberStr(value) _ast_MemberStr(ast_Member(value))
CORTO_AST_EXPORT ast_Member ast_MemberFromStr(ast_Member value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_MemberCompare(ast_Member dst, ast_Member src);
#define ast_MemberCompare(dst, src) _ast_MemberCompare(ast_Member(dst), ast_Member(src))

/* /corto/ast/New */
CORTO_AST_EXPORT ast_New _ast_NewCreate(corto_type type_1, ast_Expression attributes);
#define ast_NewCreate(type_1, attributes) _ast_NewCreate(corto_type(type_1), ast_Expression(attributes))
#define ast_NewCreate_auto(_id, type_1, attributes) ast_New _id = ast_NewCreate(type_1, attributes); (void)_id
CORTO_AST_EXPORT ast_New _ast_NewCreateChild(corto_object _parent, corto_string _id, corto_type type_1, ast_Expression attributes);
#define ast_NewCreateChild(_parent, _id, type_1, attributes) _ast_NewCreateChild(_parent, _id, corto_type(type_1), ast_Expression(attributes))
#define ast_NewCreateChild_auto(_parent, _id, type_1, attributes) ast_New _id = ast_NewCreateChild(_parent, #_id, type_1, attributes); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_NewUpdate(ast_New _this, corto_type type_1, ast_Expression attributes);
#define ast_NewUpdate(_this, type_1, attributes) _ast_NewUpdate(ast_New(_this), corto_type(type_1), ast_Expression(attributes))

CORTO_AST_EXPORT ast_New _ast_NewDeclare(void);
#define ast_NewDeclare() _ast_NewDeclare()
#define ast_NewDeclare_auto(_id) ast_New _id = ast_NewDeclare(); (void)_id
CORTO_AST_EXPORT ast_New _ast_NewDeclareChild(corto_object _parent, corto_string _id);
#define ast_NewDeclareChild(_parent, _id) _ast_NewDeclareChild(_parent, _id)
#define ast_NewDeclareChild_auto(_parent, _id) ast_New _id = ast_NewDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_NewDefine(ast_New _this, corto_type type_1, ast_Expression attributes);
#define ast_NewDefine(_this, type_1, attributes) _ast_NewDefine(ast_New(_this), corto_type(type_1), ast_Expression(attributes))
CORTO_AST_EXPORT ast_New _ast_NewAssign(ast_New _this, corto_type type_1, ast_Expression attributes);
#define ast_New__optional_NotSet NULL
#define ast_New__optional_Set(type_1, attributes) ast_NewAssign((ast_New*)corto_calloc(sizeof(ast_New)), type_1, attributes)
#define ast_New__optional_SetCond(cond, type_1, attributes) cond ? ast_NewAssign((ast_New*)corto_calloc(sizeof(ast_New)), type_1, attributes) : NULL
#define ast_NewUnset(_this) _this ? corto_deinitp(_this, ast_New_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_NewAssign(_this, type_1, attributes) _ast_NewAssign(_this, corto_type(type_1), ast_Expression(attributes))
#define ast_NewSet(_this, type_1, attributes) _this = _this ? _this : (ast_New*)corto_calloc(sizeof(ast_New)); _ast_NewAssign(_this, corto_type(type_1), ast_Expression(attributes))
CORTO_AST_EXPORT corto_string _ast_NewStr(ast_New value);
#define ast_NewStr(value) _ast_NewStr(ast_New(value))
CORTO_AST_EXPORT ast_New ast_NewFromStr(ast_New value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_NewCompare(ast_New dst, ast_New src);
#define ast_NewCompare(dst, src) _ast_NewCompare(ast_New(dst), ast_New(src))

/* /corto/ast/Node */
CORTO_AST_EXPORT ast_Node _ast_NodeCreate(ast_nodeKind kind);
#define ast_NodeCreate(kind) _ast_NodeCreate(kind)
#define ast_NodeCreate_auto(_id, kind) ast_Node _id = ast_NodeCreate(kind); (void)_id
CORTO_AST_EXPORT ast_Node _ast_NodeCreateChild(corto_object _parent, corto_string _id, ast_nodeKind kind);
#define ast_NodeCreateChild(_parent, _id, kind) _ast_NodeCreateChild(_parent, _id, kind)
#define ast_NodeCreateChild_auto(_parent, _id, kind) ast_Node _id = ast_NodeCreateChild(_parent, #_id, kind); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_NodeUpdate(ast_Node _this, ast_nodeKind kind);
#define ast_NodeUpdate(_this, kind) _ast_NodeUpdate(ast_Node(_this), kind)

CORTO_AST_EXPORT ast_Node _ast_NodeDeclare(void);
#define ast_NodeDeclare() _ast_NodeDeclare()
#define ast_NodeDeclare_auto(_id) ast_Node _id = ast_NodeDeclare(); (void)_id
CORTO_AST_EXPORT ast_Node _ast_NodeDeclareChild(corto_object _parent, corto_string _id);
#define ast_NodeDeclareChild(_parent, _id) _ast_NodeDeclareChild(_parent, _id)
#define ast_NodeDeclareChild_auto(_parent, _id) ast_Node _id = ast_NodeDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_NodeDefine(ast_Node _this, ast_nodeKind kind);
#define ast_NodeDefine(_this, kind) _ast_NodeDefine(ast_Node(_this), kind)
CORTO_AST_EXPORT ast_Node _ast_NodeAssign(ast_Node _this, ast_nodeKind kind);
#define ast_Node__optional_NotSet NULL
#define ast_Node__optional_Set(kind) ast_NodeAssign((ast_Node*)corto_calloc(sizeof(ast_Node)), kind)
#define ast_Node__optional_SetCond(cond, kind) cond ? ast_NodeAssign((ast_Node*)corto_calloc(sizeof(ast_Node)), kind) : NULL
#define ast_NodeUnset(_this) _this ? corto_deinitp(_this, ast_Node_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_NodeAssign(_this, kind) _ast_NodeAssign(_this, kind)
#define ast_NodeSet(_this, kind) _this = _this ? _this : (ast_Node*)corto_calloc(sizeof(ast_Node)); _ast_NodeAssign(_this, kind)
CORTO_AST_EXPORT corto_string _ast_NodeStr(ast_Node value);
#define ast_NodeStr(value) _ast_NodeStr(ast_Node(value))
CORTO_AST_EXPORT ast_Node ast_NodeFromStr(ast_Node value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_NodeCompare(ast_Node dst, ast_Node src);
#define ast_NodeCompare(dst, src) _ast_NodeCompare(ast_Node(dst), ast_Node(src))

/* /corto/ast/nodeKind */
CORTO_AST_EXPORT ast_nodeKind* _ast_nodeKindCreate(ast_nodeKind value);
#define ast_nodeKindCreate(value) _ast_nodeKindCreate(value)
#define ast_nodeKindCreate_auto(_id, value) ast_nodeKind* _id = ast_nodeKindCreate(value); (void)_id
CORTO_AST_EXPORT ast_nodeKind* _ast_nodeKindCreateChild(corto_object _parent, corto_string _id, ast_nodeKind value);
#define ast_nodeKindCreateChild(_parent, _id, value) _ast_nodeKindCreateChild(_parent, _id, value)
#define ast_nodeKindCreateChild_auto(_parent, _id, value) ast_nodeKind* _id = ast_nodeKindCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_nodeKindUpdate(ast_nodeKind* _this, ast_nodeKind value);
#define ast_nodeKindUpdate(_this, value) _ast_nodeKindUpdate(ast_nodeKind(_this), value)

CORTO_AST_EXPORT ast_nodeKind* _ast_nodeKindDeclare(void);
#define ast_nodeKindDeclare() _ast_nodeKindDeclare()
#define ast_nodeKindDeclare_auto(_id) ast_nodeKind* _id = ast_nodeKindDeclare(); (void)_id
CORTO_AST_EXPORT ast_nodeKind* _ast_nodeKindDeclareChild(corto_object _parent, corto_string _id);
#define ast_nodeKindDeclareChild(_parent, _id) _ast_nodeKindDeclareChild(_parent, _id)
#define ast_nodeKindDeclareChild_auto(_parent, _id) ast_nodeKind* _id = ast_nodeKindDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_nodeKindDefine(ast_nodeKind* _this, ast_nodeKind value);
#define ast_nodeKindDefine(_this, value) _ast_nodeKindDefine(ast_nodeKind(_this), value)
CORTO_AST_EXPORT ast_nodeKind* _ast_nodeKindAssign(ast_nodeKind* _this, ast_nodeKind value);
#define ast_nodeKind__optional_NotSet NULL
#define ast_nodeKind__optional_Set(value) ast_nodeKindAssign((ast_nodeKind*)corto_calloc(sizeof(ast_nodeKind)), value)
#define ast_nodeKind__optional_SetCond(cond, value) cond ? ast_nodeKindAssign((ast_nodeKind*)corto_calloc(sizeof(ast_nodeKind)), value) : NULL
#define ast_nodeKindUnset(_this) _this ? corto_deinitp(_this, ast_nodeKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_nodeKindAssign(_this, value) _ast_nodeKindAssign(_this, value)
#define ast_nodeKindSet(_this, value) _this = _this ? _this : (ast_nodeKind*)corto_calloc(sizeof(ast_nodeKind)); _ast_nodeKindAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_nodeKindStr(ast_nodeKind value);
#define ast_nodeKindStr(value) _ast_nodeKindStr(value)
CORTO_AST_EXPORT ast_nodeKind* ast_nodeKindFromStr(ast_nodeKind* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_nodeKindCompare(ast_nodeKind dst, ast_nodeKind src);

CORTO_AST_EXPORT corto_int16 _ast_nodeKindInit(ast_nodeKind* value);
#define ast_nodeKindInit(value) _ast_nodeKindInit(value)
CORTO_AST_EXPORT corto_int16 _ast_nodeKindDeinit(ast_nodeKind* value);
#define ast_nodeKindDeinit(value) _ast_nodeKindDeinit(value)

/* /corto/ast/Null */
CORTO_AST_EXPORT ast_Null _ast_NullCreate(void);
#define ast_NullCreate() _ast_NullCreate()
#define ast_NullCreate_auto(_id) ast_Null _id = ast_NullCreate(); (void)_id
CORTO_AST_EXPORT ast_Null _ast_NullCreateChild(corto_object _parent, corto_string _id);
#define ast_NullCreateChild(_parent, _id) _ast_NullCreateChild(_parent, _id)
#define ast_NullCreateChild_auto(_parent, _id) ast_Null _id = ast_NullCreateChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_NullUpdate(ast_Null _this);
#define ast_NullUpdate(_this) _ast_NullUpdate(ast_Null(_this))

CORTO_AST_EXPORT ast_Null _ast_NullDeclare(void);
#define ast_NullDeclare() _ast_NullDeclare()
#define ast_NullDeclare_auto(_id) ast_Null _id = ast_NullDeclare(); (void)_id
CORTO_AST_EXPORT ast_Null _ast_NullDeclareChild(corto_object _parent, corto_string _id);
#define ast_NullDeclareChild(_parent, _id) _ast_NullDeclareChild(_parent, _id)
#define ast_NullDeclareChild_auto(_parent, _id) ast_Null _id = ast_NullDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_NullDefine(ast_Null _this);
#define ast_NullDefine(_this) _ast_NullDefine(ast_Null(_this))
CORTO_AST_EXPORT ast_Null _ast_NullAssign(ast_Null _this);
#define ast_Null__optional_NotSet NULL
#define ast_Null__optional_Set() ast_NullAssign((ast_Null*)corto_calloc(sizeof(ast_Null)))
#define ast_Null__optional_SetCond(cond) cond ? ast_NullAssign((ast_Null*)corto_calloc(sizeof(ast_Null))) : NULL
#define ast_NullUnset(_this) _this ? corto_deinitp(_this, ast_Null_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_NullAssign(_this) _ast_NullAssign(_this)
#define ast_NullSet(_this) _this = _this ? _this : (ast_Null*)corto_calloc(sizeof(ast_Null)); _ast_NullAssign(_this)
CORTO_AST_EXPORT corto_string _ast_NullStr(ast_Null value);
#define ast_NullStr(value) _ast_NullStr(ast_Null(value))
CORTO_AST_EXPORT ast_Null ast_NullFromStr(ast_Null value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_NullCompare(ast_Null dst, ast_Null src);
#define ast_NullCompare(dst, src) _ast_NullCompare(ast_Null(dst), ast_Null(src))

/* /corto/ast/Object */
CORTO_AST_EXPORT ast_Object _ast_ObjectCreate(corto_object value);
#define ast_ObjectCreate(value) _ast_ObjectCreate(value)
#define ast_ObjectCreate_auto(_id, value) ast_Object _id = ast_ObjectCreate(value); (void)_id
CORTO_AST_EXPORT ast_Object _ast_ObjectCreateChild(corto_object _parent, corto_string _id, corto_object value);
#define ast_ObjectCreateChild(_parent, _id, value) _ast_ObjectCreateChild(_parent, _id, value)
#define ast_ObjectCreateChild_auto(_parent, _id, value) ast_Object _id = ast_ObjectCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ObjectUpdate(ast_Object _this, corto_object value);
#define ast_ObjectUpdate(_this, value) _ast_ObjectUpdate(ast_Object(_this), value)

CORTO_AST_EXPORT ast_Object _ast_ObjectDeclare(void);
#define ast_ObjectDeclare() _ast_ObjectDeclare()
#define ast_ObjectDeclare_auto(_id) ast_Object _id = ast_ObjectDeclare(); (void)_id
CORTO_AST_EXPORT ast_Object _ast_ObjectDeclareChild(corto_object _parent, corto_string _id);
#define ast_ObjectDeclareChild(_parent, _id) _ast_ObjectDeclareChild(_parent, _id)
#define ast_ObjectDeclareChild_auto(_parent, _id) ast_Object _id = ast_ObjectDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ObjectDefine(ast_Object _this, corto_object value);
#define ast_ObjectDefine(_this, value) _ast_ObjectDefine(ast_Object(_this), value)
CORTO_AST_EXPORT ast_Object _ast_ObjectAssign(ast_Object _this, corto_object value);
#define ast_Object__optional_NotSet NULL
#define ast_Object__optional_Set(value) ast_ObjectAssign((ast_Object*)corto_calloc(sizeof(ast_Object)), value)
#define ast_Object__optional_SetCond(cond, value) cond ? ast_ObjectAssign((ast_Object*)corto_calloc(sizeof(ast_Object)), value) : NULL
#define ast_ObjectUnset(_this) _this ? corto_deinitp(_this, ast_Object_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_ObjectAssign(_this, value) _ast_ObjectAssign(_this, value)
#define ast_ObjectSet(_this, value) _this = _this ? _this : (ast_Object*)corto_calloc(sizeof(ast_Object)); _ast_ObjectAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_ObjectStr(ast_Object value);
#define ast_ObjectStr(value) _ast_ObjectStr(ast_Object(value))
CORTO_AST_EXPORT ast_Object ast_ObjectFromStr(ast_Object value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_ObjectCompare(ast_Object dst, ast_Object src);
#define ast_ObjectCompare(dst, src) _ast_ObjectCompare(ast_Object(dst), ast_Object(src))

/* /corto/ast/Parser */
CORTO_AST_EXPORT ast_Parser _ast_ParserCreate(corto_string source, corto_string filename);
#define ast_ParserCreate(source, filename) _ast_ParserCreate(source, filename)
#define ast_ParserCreate_auto(_id, source, filename) ast_Parser _id = ast_ParserCreate(source, filename); (void)_id
CORTO_AST_EXPORT ast_Parser _ast_ParserCreateChild(corto_object _parent, corto_string _id, corto_string source, corto_string filename);
#define ast_ParserCreateChild(_parent, _id, source, filename) _ast_ParserCreateChild(_parent, _id, source, filename)
#define ast_ParserCreateChild_auto(_parent, _id, source, filename) ast_Parser _id = ast_ParserCreateChild(_parent, #_id, source, filename); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ParserUpdate(ast_Parser _this, corto_string source, corto_string filename);
#define ast_ParserUpdate(_this, source, filename) _ast_ParserUpdate(ast_Parser(_this), source, filename)

CORTO_AST_EXPORT ast_Parser _ast_ParserDeclare(void);
#define ast_ParserDeclare() _ast_ParserDeclare()
#define ast_ParserDeclare_auto(_id) ast_Parser _id = ast_ParserDeclare(); (void)_id
CORTO_AST_EXPORT ast_Parser _ast_ParserDeclareChild(corto_object _parent, corto_string _id);
#define ast_ParserDeclareChild(_parent, _id) _ast_ParserDeclareChild(_parent, _id)
#define ast_ParserDeclareChild_auto(_parent, _id) ast_Parser _id = ast_ParserDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ParserDefine(ast_Parser _this, corto_string source, corto_string filename);
#define ast_ParserDefine(_this, source, filename) _ast_ParserDefine(ast_Parser(_this), source, filename)
CORTO_AST_EXPORT ast_Parser _ast_ParserAssign(ast_Parser _this, corto_string source, corto_string filename);
#define ast_Parser__optional_NotSet NULL
#define ast_Parser__optional_Set(source, filename) ast_ParserAssign((ast_Parser*)corto_calloc(sizeof(ast_Parser)), source, filename)
#define ast_Parser__optional_SetCond(cond, source, filename) cond ? ast_ParserAssign((ast_Parser*)corto_calloc(sizeof(ast_Parser)), source, filename) : NULL
#define ast_ParserUnset(_this) _this ? corto_deinitp(_this, ast_Parser_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_ParserAssign(_this, source, filename) _ast_ParserAssign(_this, source, filename)
#define ast_ParserSet(_this, source, filename) _this = _this ? _this : (ast_Parser*)corto_calloc(sizeof(ast_Parser)); _ast_ParserAssign(_this, source, filename)
CORTO_AST_EXPORT corto_string _ast_ParserStr(ast_Parser value);
#define ast_ParserStr(value) _ast_ParserStr(ast_Parser(value))
CORTO_AST_EXPORT ast_Parser ast_ParserFromStr(ast_Parser value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_ParserCompare(ast_Parser dst, ast_Parser src);
#define ast_ParserCompare(dst, src) _ast_ParserCompare(ast_Parser(dst), ast_Parser(src))

/* /corto/ast/ParserDeclaration */
CORTO_AST_EXPORT ast_ParserDeclaration* _ast_ParserDeclarationCreate(corto_string name, ast_Storage storage);
#define ast_ParserDeclarationCreate(name, storage) _ast_ParserDeclarationCreate(name, ast_Storage(storage))
#define ast_ParserDeclarationCreate_auto(_id, name, storage) ast_ParserDeclaration* _id = ast_ParserDeclarationCreate(name, storage); (void)_id
CORTO_AST_EXPORT ast_ParserDeclaration* _ast_ParserDeclarationCreateChild(corto_object _parent, corto_string _id, corto_string name, ast_Storage storage);
#define ast_ParserDeclarationCreateChild(_parent, _id, name, storage) _ast_ParserDeclarationCreateChild(_parent, _id, name, ast_Storage(storage))
#define ast_ParserDeclarationCreateChild_auto(_parent, _id, name, storage) ast_ParserDeclaration* _id = ast_ParserDeclarationCreateChild(_parent, #_id, name, storage); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ParserDeclarationUpdate(ast_ParserDeclaration* _this, corto_string name, ast_Storage storage);
#define ast_ParserDeclarationUpdate(_this, name, storage) _ast_ParserDeclarationUpdate(ast_ParserDeclaration(_this), name, ast_Storage(storage))

CORTO_AST_EXPORT ast_ParserDeclaration* _ast_ParserDeclarationDeclare(void);
#define ast_ParserDeclarationDeclare() _ast_ParserDeclarationDeclare()
#define ast_ParserDeclarationDeclare_auto(_id) ast_ParserDeclaration* _id = ast_ParserDeclarationDeclare(); (void)_id
CORTO_AST_EXPORT ast_ParserDeclaration* _ast_ParserDeclarationDeclareChild(corto_object _parent, corto_string _id);
#define ast_ParserDeclarationDeclareChild(_parent, _id) _ast_ParserDeclarationDeclareChild(_parent, _id)
#define ast_ParserDeclarationDeclareChild_auto(_parent, _id) ast_ParserDeclaration* _id = ast_ParserDeclarationDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ParserDeclarationDefine(ast_ParserDeclaration* _this, corto_string name, ast_Storage storage);
#define ast_ParserDeclarationDefine(_this, name, storage) _ast_ParserDeclarationDefine(ast_ParserDeclaration(_this), name, ast_Storage(storage))
CORTO_AST_EXPORT ast_ParserDeclaration* _ast_ParserDeclarationAssign(ast_ParserDeclaration* _this, corto_string name, ast_Storage storage);
#define ast_ParserDeclaration__optional_NotSet NULL
#define ast_ParserDeclaration__optional_Set(name, storage) ast_ParserDeclarationAssign((ast_ParserDeclaration*)corto_calloc(sizeof(ast_ParserDeclaration)), name, storage)
#define ast_ParserDeclaration__optional_SetCond(cond, name, storage) cond ? ast_ParserDeclarationAssign((ast_ParserDeclaration*)corto_calloc(sizeof(ast_ParserDeclaration)), name, storage) : NULL
#define ast_ParserDeclarationUnset(_this) _this ? corto_deinitp(_this, ast_ParserDeclaration_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_ParserDeclarationAssign(_this, name, storage) _ast_ParserDeclarationAssign(_this, name, ast_Storage(storage))
#define ast_ParserDeclarationSet(_this, name, storage) _this = _this ? _this : (ast_ParserDeclaration*)corto_calloc(sizeof(ast_ParserDeclaration)); _ast_ParserDeclarationAssign(_this, name, ast_Storage(storage))
CORTO_AST_EXPORT corto_string _ast_ParserDeclarationStr(ast_ParserDeclaration* value);
#define ast_ParserDeclarationStr(value) _ast_ParserDeclarationStr(value)
CORTO_AST_EXPORT ast_ParserDeclaration* ast_ParserDeclarationFromStr(ast_ParserDeclaration* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_ParserDeclarationCompare(ast_ParserDeclaration* dst, ast_ParserDeclaration* src);

CORTO_AST_EXPORT corto_int16 _ast_ParserDeclarationInit(ast_ParserDeclaration* value);
#define ast_ParserDeclarationInit(value) _ast_ParserDeclarationInit(value)
CORTO_AST_EXPORT corto_int16 _ast_ParserDeclarationDeinit(ast_ParserDeclaration* value);
#define ast_ParserDeclarationDeinit(value) _ast_ParserDeclarationDeinit(value)

/* /corto/ast/ParserDeclarationSeq */
CORTO_AST_EXPORT ast_ParserDeclarationSeq* _ast_ParserDeclarationSeqCreate(corto_uint32 length, ast_ParserDeclaration* elements);
#define ast_ParserDeclarationSeqCreate(length, elements) _ast_ParserDeclarationSeqCreate(length, elements)
#define ast_ParserDeclarationSeqCreate_auto(_id, length, elements) ast_ParserDeclarationSeq* _id = ast_ParserDeclarationSeqCreate(length, elements); (void)_id
CORTO_AST_EXPORT ast_ParserDeclarationSeq* _ast_ParserDeclarationSeqCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, ast_ParserDeclaration* elements);
#define ast_ParserDeclarationSeqCreateChild(_parent, _id, length, elements) _ast_ParserDeclarationSeqCreateChild(_parent, _id, length, elements)
#define ast_ParserDeclarationSeqCreateChild_auto(_parent, _id, length, elements) ast_ParserDeclarationSeq* _id = ast_ParserDeclarationSeqCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ParserDeclarationSeqUpdate(ast_ParserDeclarationSeq* _this, corto_uint32 length, ast_ParserDeclaration* elements);
#define ast_ParserDeclarationSeqUpdate(_this, length, elements) _ast_ParserDeclarationSeqUpdate(ast_ParserDeclarationSeq(_this), length, elements)

CORTO_AST_EXPORT ast_ParserDeclarationSeq* _ast_ParserDeclarationSeqDeclare(void);
#define ast_ParserDeclarationSeqDeclare() _ast_ParserDeclarationSeqDeclare()
#define ast_ParserDeclarationSeqDeclare_auto(_id) ast_ParserDeclarationSeq* _id = ast_ParserDeclarationSeqDeclare(); (void)_id
CORTO_AST_EXPORT ast_ParserDeclarationSeq* _ast_ParserDeclarationSeqDeclareChild(corto_object _parent, corto_string _id);
#define ast_ParserDeclarationSeqDeclareChild(_parent, _id) _ast_ParserDeclarationSeqDeclareChild(_parent, _id)
#define ast_ParserDeclarationSeqDeclareChild_auto(_parent, _id) ast_ParserDeclarationSeq* _id = ast_ParserDeclarationSeqDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ParserDeclarationSeqDefine(ast_ParserDeclarationSeq* _this, corto_uint32 length, ast_ParserDeclaration* elements);
#define ast_ParserDeclarationSeqDefine(_this, length, elements) _ast_ParserDeclarationSeqDefine(ast_ParserDeclarationSeq(_this), length, elements)
CORTO_AST_EXPORT ast_ParserDeclarationSeq* _ast_ParserDeclarationSeqAssign(ast_ParserDeclarationSeq* _this, corto_uint32 length, ast_ParserDeclaration* elements);
#define ast_ParserDeclarationSeq__optional_NotSet NULL
#define ast_ParserDeclarationSeq__optional_Set(length, elements) ast_ParserDeclarationSeqAssign((ast_ParserDeclarationSeq*)corto_calloc(sizeof(ast_ParserDeclarationSeq)), length, elements)
#define ast_ParserDeclarationSeq__optional_SetCond(cond, length, elements) cond ? ast_ParserDeclarationSeqAssign((ast_ParserDeclarationSeq*)corto_calloc(sizeof(ast_ParserDeclarationSeq)), length, elements) : NULL
#define ast_ParserDeclarationSeqUnset(_this) _this ? corto_deinitp(_this, ast_ParserDeclarationSeq_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_ParserDeclarationSeqAssign(_this, length, elements) _ast_ParserDeclarationSeqAssign(_this, length, elements)
#define ast_ParserDeclarationSeqSet(_this, length, elements) _this = _this ? _this : (ast_ParserDeclarationSeq*)corto_calloc(sizeof(ast_ParserDeclarationSeq)); _ast_ParserDeclarationSeqAssign(_this, length, elements)
CORTO_AST_EXPORT corto_string _ast_ParserDeclarationSeqStr(ast_ParserDeclarationSeq value);
#define ast_ParserDeclarationSeqStr(value) _ast_ParserDeclarationSeqStr(value)
CORTO_AST_EXPORT ast_ParserDeclarationSeq* ast_ParserDeclarationSeqFromStr(ast_ParserDeclarationSeq* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_ParserDeclarationSeqCompare(ast_ParserDeclarationSeq dst, ast_ParserDeclarationSeq src);

CORTO_AST_EXPORT corto_int16 _ast_ParserDeclarationSeqInit(ast_ParserDeclarationSeq* value);
#define ast_ParserDeclarationSeqInit(value) _ast_ParserDeclarationSeqInit(value)
CORTO_AST_EXPORT corto_int16 _ast_ParserDeclarationSeqDeinit(ast_ParserDeclarationSeq* value);
#define ast_ParserDeclarationSeqDeinit(value) _ast_ParserDeclarationSeqDeinit(value)

/* /corto/ast/ParserNew */
CORTO_AST_EXPORT ast_ParserNew* _ast_ParserNewCreate(ast_nodeKind kind, ast_Expression parent, ast_Expression name, ast_Expression attr);
#define ast_ParserNewCreate(kind, parent, name, attr) _ast_ParserNewCreate(kind, ast_Expression(parent), ast_Expression(name), ast_Expression(attr))
#define ast_ParserNewCreate_auto(_id, kind, parent, name, attr) ast_ParserNew* _id = ast_ParserNewCreate(kind, parent, name, attr); (void)_id
CORTO_AST_EXPORT ast_ParserNew* _ast_ParserNewCreateChild(corto_object _parent, corto_string _id, ast_nodeKind kind, ast_Expression parent, ast_Expression name, ast_Expression attr);
#define ast_ParserNewCreateChild(_parent, _id, kind, parent, name, attr) _ast_ParserNewCreateChild(_parent, _id, kind, ast_Expression(parent), ast_Expression(name), ast_Expression(attr))
#define ast_ParserNewCreateChild_auto(_parent, _id, kind, parent, name, attr) ast_ParserNew* _id = ast_ParserNewCreateChild(_parent, #_id, kind, parent, name, attr); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ParserNewUpdate(ast_ParserNew* _this, ast_nodeKind kind, ast_Expression parent, ast_Expression name, ast_Expression attr);
#define ast_ParserNewUpdate(_this, kind, parent, name, attr) _ast_ParserNewUpdate(ast_ParserNew(_this), kind, ast_Expression(parent), ast_Expression(name), ast_Expression(attr))

CORTO_AST_EXPORT ast_ParserNew* _ast_ParserNewDeclare(void);
#define ast_ParserNewDeclare() _ast_ParserNewDeclare()
#define ast_ParserNewDeclare_auto(_id) ast_ParserNew* _id = ast_ParserNewDeclare(); (void)_id
CORTO_AST_EXPORT ast_ParserNew* _ast_ParserNewDeclareChild(corto_object _parent, corto_string _id);
#define ast_ParserNewDeclareChild(_parent, _id) _ast_ParserNewDeclareChild(_parent, _id)
#define ast_ParserNewDeclareChild_auto(_parent, _id) ast_ParserNew* _id = ast_ParserNewDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_ParserNewDefine(ast_ParserNew* _this, ast_nodeKind kind, ast_Expression parent, ast_Expression name, ast_Expression attr);
#define ast_ParserNewDefine(_this, kind, parent, name, attr) _ast_ParserNewDefine(ast_ParserNew(_this), kind, ast_Expression(parent), ast_Expression(name), ast_Expression(attr))
CORTO_AST_EXPORT ast_ParserNew* _ast_ParserNewAssign(ast_ParserNew* _this, ast_nodeKind kind, ast_Expression parent, ast_Expression name, ast_Expression attr);
#define ast_ParserNew__optional_NotSet NULL
#define ast_ParserNew__optional_Set(kind, parent, name, attr) ast_ParserNewAssign((ast_ParserNew*)corto_calloc(sizeof(ast_ParserNew)), kind, parent, name, attr)
#define ast_ParserNew__optional_SetCond(cond, kind, parent, name, attr) cond ? ast_ParserNewAssign((ast_ParserNew*)corto_calloc(sizeof(ast_ParserNew)), kind, parent, name, attr) : NULL
#define ast_ParserNewUnset(_this) _this ? corto_deinitp(_this, ast_ParserNew_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_ParserNewAssign(_this, kind, parent, name, attr) _ast_ParserNewAssign(_this, kind, ast_Expression(parent), ast_Expression(name), ast_Expression(attr))
#define ast_ParserNewSet(_this, kind, parent, name, attr) _this = _this ? _this : (ast_ParserNew*)corto_calloc(sizeof(ast_ParserNew)); _ast_ParserNewAssign(_this, kind, ast_Expression(parent), ast_Expression(name), ast_Expression(attr))
CORTO_AST_EXPORT corto_string _ast_ParserNewStr(ast_ParserNew* value);
#define ast_ParserNewStr(value) _ast_ParserNewStr(value)
CORTO_AST_EXPORT ast_ParserNew* ast_ParserNewFromStr(ast_ParserNew* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_ParserNewCompare(ast_ParserNew* dst, ast_ParserNew* src);

CORTO_AST_EXPORT corto_int16 _ast_ParserNewInit(ast_ParserNew* value);
#define ast_ParserNewInit(value) _ast_ParserNewInit(value)
CORTO_AST_EXPORT corto_int16 _ast_ParserNewDeinit(ast_ParserNew* value);
#define ast_ParserNewDeinit(value) _ast_ParserNewDeinit(value)

/* /corto/ast/PostFix */
CORTO_AST_EXPORT ast_PostFix _ast_PostFixCreate(ast_Expression lvalue, corto_operatorKind _operator);
#define ast_PostFixCreate(lvalue, _operator) _ast_PostFixCreate(ast_Expression(lvalue), _operator)
#define ast_PostFixCreate_auto(_id, lvalue, _operator) ast_PostFix _id = ast_PostFixCreate(lvalue, _operator); (void)_id
CORTO_AST_EXPORT ast_PostFix _ast_PostFixCreateChild(corto_object _parent, corto_string _id, ast_Expression lvalue, corto_operatorKind _operator);
#define ast_PostFixCreateChild(_parent, _id, lvalue, _operator) _ast_PostFixCreateChild(_parent, _id, ast_Expression(lvalue), _operator)
#define ast_PostFixCreateChild_auto(_parent, _id, lvalue, _operator) ast_PostFix _id = ast_PostFixCreateChild(_parent, #_id, lvalue, _operator); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_PostFixUpdate(ast_PostFix _this, ast_Expression lvalue, corto_operatorKind _operator);
#define ast_PostFixUpdate(_this, lvalue, _operator) _ast_PostFixUpdate(ast_PostFix(_this), ast_Expression(lvalue), _operator)

CORTO_AST_EXPORT ast_PostFix _ast_PostFixDeclare(void);
#define ast_PostFixDeclare() _ast_PostFixDeclare()
#define ast_PostFixDeclare_auto(_id) ast_PostFix _id = ast_PostFixDeclare(); (void)_id
CORTO_AST_EXPORT ast_PostFix _ast_PostFixDeclareChild(corto_object _parent, corto_string _id);
#define ast_PostFixDeclareChild(_parent, _id) _ast_PostFixDeclareChild(_parent, _id)
#define ast_PostFixDeclareChild_auto(_parent, _id) ast_PostFix _id = ast_PostFixDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_PostFixDefine(ast_PostFix _this, ast_Expression lvalue, corto_operatorKind _operator);
#define ast_PostFixDefine(_this, lvalue, _operator) _ast_PostFixDefine(ast_PostFix(_this), ast_Expression(lvalue), _operator)
CORTO_AST_EXPORT ast_PostFix _ast_PostFixAssign(ast_PostFix _this, ast_Expression lvalue, corto_operatorKind _operator);
#define ast_PostFix__optional_NotSet NULL
#define ast_PostFix__optional_Set(lvalue, _operator) ast_PostFixAssign((ast_PostFix*)corto_calloc(sizeof(ast_PostFix)), lvalue, _operator)
#define ast_PostFix__optional_SetCond(cond, lvalue, _operator) cond ? ast_PostFixAssign((ast_PostFix*)corto_calloc(sizeof(ast_PostFix)), lvalue, _operator) : NULL
#define ast_PostFixUnset(_this) _this ? corto_deinitp(_this, ast_PostFix_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_PostFixAssign(_this, lvalue, _operator) _ast_PostFixAssign(_this, ast_Expression(lvalue), _operator)
#define ast_PostFixSet(_this, lvalue, _operator) _this = _this ? _this : (ast_PostFix*)corto_calloc(sizeof(ast_PostFix)); _ast_PostFixAssign(_this, ast_Expression(lvalue), _operator)
CORTO_AST_EXPORT corto_string _ast_PostFixStr(ast_PostFix value);
#define ast_PostFixStr(value) _ast_PostFixStr(ast_PostFix(value))
CORTO_AST_EXPORT ast_PostFix ast_PostFixFromStr(ast_PostFix value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_PostFixCompare(ast_PostFix dst, ast_PostFix src);
#define ast_PostFixCompare(dst, src) _ast_PostFixCompare(ast_PostFix(dst), ast_PostFix(src))

/* /corto/ast/SignedInteger */
CORTO_AST_EXPORT ast_SignedInteger _ast_SignedIntegerCreate(corto_int64 value);
#define ast_SignedIntegerCreate(value) _ast_SignedIntegerCreate(value)
#define ast_SignedIntegerCreate_auto(_id, value) ast_SignedInteger _id = ast_SignedIntegerCreate(value); (void)_id
CORTO_AST_EXPORT ast_SignedInteger _ast_SignedIntegerCreateChild(corto_object _parent, corto_string _id, corto_int64 value);
#define ast_SignedIntegerCreateChild(_parent, _id, value) _ast_SignedIntegerCreateChild(_parent, _id, value)
#define ast_SignedIntegerCreateChild_auto(_parent, _id, value) ast_SignedInteger _id = ast_SignedIntegerCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_SignedIntegerUpdate(ast_SignedInteger _this, corto_int64 value);
#define ast_SignedIntegerUpdate(_this, value) _ast_SignedIntegerUpdate(ast_SignedInteger(_this), value)

CORTO_AST_EXPORT ast_SignedInteger _ast_SignedIntegerDeclare(void);
#define ast_SignedIntegerDeclare() _ast_SignedIntegerDeclare()
#define ast_SignedIntegerDeclare_auto(_id) ast_SignedInteger _id = ast_SignedIntegerDeclare(); (void)_id
CORTO_AST_EXPORT ast_SignedInteger _ast_SignedIntegerDeclareChild(corto_object _parent, corto_string _id);
#define ast_SignedIntegerDeclareChild(_parent, _id) _ast_SignedIntegerDeclareChild(_parent, _id)
#define ast_SignedIntegerDeclareChild_auto(_parent, _id) ast_SignedInteger _id = ast_SignedIntegerDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_SignedIntegerDefine(ast_SignedInteger _this, corto_int64 value);
#define ast_SignedIntegerDefine(_this, value) _ast_SignedIntegerDefine(ast_SignedInteger(_this), value)
CORTO_AST_EXPORT ast_SignedInteger _ast_SignedIntegerAssign(ast_SignedInteger _this, corto_int64 value);
#define ast_SignedInteger__optional_NotSet NULL
#define ast_SignedInteger__optional_Set(value) ast_SignedIntegerAssign((ast_SignedInteger*)corto_calloc(sizeof(ast_SignedInteger)), value)
#define ast_SignedInteger__optional_SetCond(cond, value) cond ? ast_SignedIntegerAssign((ast_SignedInteger*)corto_calloc(sizeof(ast_SignedInteger)), value) : NULL
#define ast_SignedIntegerUnset(_this) _this ? corto_deinitp(_this, ast_SignedInteger_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_SignedIntegerAssign(_this, value) _ast_SignedIntegerAssign(_this, value)
#define ast_SignedIntegerSet(_this, value) _this = _this ? _this : (ast_SignedInteger*)corto_calloc(sizeof(ast_SignedInteger)); _ast_SignedIntegerAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_SignedIntegerStr(ast_SignedInteger value);
#define ast_SignedIntegerStr(value) _ast_SignedIntegerStr(ast_SignedInteger(value))
CORTO_AST_EXPORT ast_SignedInteger ast_SignedIntegerFromStr(ast_SignedInteger value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_SignedIntegerCompare(ast_SignedInteger dst, ast_SignedInteger src);
#define ast_SignedIntegerCompare(dst, src) _ast_SignedIntegerCompare(ast_SignedInteger(dst), ast_SignedInteger(src))

/* /corto/ast/StaticCall */
CORTO_AST_EXPORT ast_StaticCall _ast_StaticCallCreate(ast_Expression instanceExpr, ast_Expression arguments, corto_function function);
#define ast_StaticCallCreate(instanceExpr, arguments, function) _ast_StaticCallCreate(ast_Expression(instanceExpr), ast_Expression(arguments), corto_function(function))
#define ast_StaticCallCreate_auto(_id, instanceExpr, arguments, function) ast_StaticCall _id = ast_StaticCallCreate(instanceExpr, arguments, function); (void)_id
CORTO_AST_EXPORT ast_StaticCall _ast_StaticCallCreateChild(corto_object _parent, corto_string _id, ast_Expression instanceExpr, ast_Expression arguments, corto_function function);
#define ast_StaticCallCreateChild(_parent, _id, instanceExpr, arguments, function) _ast_StaticCallCreateChild(_parent, _id, ast_Expression(instanceExpr), ast_Expression(arguments), corto_function(function))
#define ast_StaticCallCreateChild_auto(_parent, _id, instanceExpr, arguments, function) ast_StaticCall _id = ast_StaticCallCreateChild(_parent, #_id, instanceExpr, arguments, function); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StaticCallUpdate(ast_StaticCall _this, ast_Expression instanceExpr, ast_Expression arguments, corto_function function);
#define ast_StaticCallUpdate(_this, instanceExpr, arguments, function) _ast_StaticCallUpdate(ast_StaticCall(_this), ast_Expression(instanceExpr), ast_Expression(arguments), corto_function(function))

CORTO_AST_EXPORT ast_StaticCall _ast_StaticCallDeclare(void);
#define ast_StaticCallDeclare() _ast_StaticCallDeclare()
#define ast_StaticCallDeclare_auto(_id) ast_StaticCall _id = ast_StaticCallDeclare(); (void)_id
CORTO_AST_EXPORT ast_StaticCall _ast_StaticCallDeclareChild(corto_object _parent, corto_string _id);
#define ast_StaticCallDeclareChild(_parent, _id) _ast_StaticCallDeclareChild(_parent, _id)
#define ast_StaticCallDeclareChild_auto(_parent, _id) ast_StaticCall _id = ast_StaticCallDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StaticCallDefine(ast_StaticCall _this, ast_Expression instanceExpr, ast_Expression arguments, corto_function function);
#define ast_StaticCallDefine(_this, instanceExpr, arguments, function) _ast_StaticCallDefine(ast_StaticCall(_this), ast_Expression(instanceExpr), ast_Expression(arguments), corto_function(function))
CORTO_AST_EXPORT ast_StaticCall _ast_StaticCallAssign(ast_StaticCall _this, ast_Expression instanceExpr, ast_Expression arguments, corto_function function);
#define ast_StaticCall__optional_NotSet NULL
#define ast_StaticCall__optional_Set(instanceExpr, arguments, function) ast_StaticCallAssign((ast_StaticCall*)corto_calloc(sizeof(ast_StaticCall)), instanceExpr, arguments, function)
#define ast_StaticCall__optional_SetCond(cond, instanceExpr, arguments, function) cond ? ast_StaticCallAssign((ast_StaticCall*)corto_calloc(sizeof(ast_StaticCall)), instanceExpr, arguments, function) : NULL
#define ast_StaticCallUnset(_this) _this ? corto_deinitp(_this, ast_StaticCall_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_StaticCallAssign(_this, instanceExpr, arguments, function) _ast_StaticCallAssign(_this, ast_Expression(instanceExpr), ast_Expression(arguments), corto_function(function))
#define ast_StaticCallSet(_this, instanceExpr, arguments, function) _this = _this ? _this : (ast_StaticCall*)corto_calloc(sizeof(ast_StaticCall)); _ast_StaticCallAssign(_this, ast_Expression(instanceExpr), ast_Expression(arguments), corto_function(function))
CORTO_AST_EXPORT corto_string _ast_StaticCallStr(ast_StaticCall value);
#define ast_StaticCallStr(value) _ast_StaticCallStr(ast_StaticCall(value))
CORTO_AST_EXPORT ast_StaticCall ast_StaticCallFromStr(ast_StaticCall value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_StaticCallCompare(ast_StaticCall dst, ast_StaticCall src);
#define ast_StaticCallCompare(dst, src) _ast_StaticCallCompare(ast_StaticCall(dst), ast_StaticCall(src))

/* /corto/ast/StaticInitializer */
CORTO_AST_EXPORT ast_StaticInitializer _ast_StaticInitializerCreate(ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_StaticInitializerCreate(variables, variableCount) _ast_StaticInitializerCreate(variables, variableCount)
#define ast_StaticInitializerCreate_auto(_id, variables, variableCount) ast_StaticInitializer _id = ast_StaticInitializerCreate(variables, variableCount); (void)_id
CORTO_AST_EXPORT ast_StaticInitializer _ast_StaticInitializerCreateChild(corto_object _parent, corto_string _id, ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_StaticInitializerCreateChild(_parent, _id, variables, variableCount) _ast_StaticInitializerCreateChild(_parent, _id, variables, variableCount)
#define ast_StaticInitializerCreateChild_auto(_parent, _id, variables, variableCount) ast_StaticInitializer _id = ast_StaticInitializerCreateChild(_parent, #_id, variables, variableCount); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StaticInitializerUpdate(ast_StaticInitializer _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_StaticInitializerUpdate(_this, variables, variableCount) _ast_StaticInitializerUpdate(ast_StaticInitializer(_this), variables, variableCount)

CORTO_AST_EXPORT ast_StaticInitializer _ast_StaticInitializerDeclare(void);
#define ast_StaticInitializerDeclare() _ast_StaticInitializerDeclare()
#define ast_StaticInitializerDeclare_auto(_id) ast_StaticInitializer _id = ast_StaticInitializerDeclare(); (void)_id
CORTO_AST_EXPORT ast_StaticInitializer _ast_StaticInitializerDeclareChild(corto_object _parent, corto_string _id);
#define ast_StaticInitializerDeclareChild(_parent, _id) _ast_StaticInitializerDeclareChild(_parent, _id)
#define ast_StaticInitializerDeclareChild_auto(_parent, _id) ast_StaticInitializer _id = ast_StaticInitializerDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StaticInitializerDefine(ast_StaticInitializer _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_StaticInitializerDefine(_this, variables, variableCount) _ast_StaticInitializerDefine(ast_StaticInitializer(_this), variables, variableCount)
CORTO_AST_EXPORT ast_StaticInitializer _ast_StaticInitializerAssign(ast_StaticInitializer _this, ast_InitializerVariableArray64 variables, corto_uint8 variableCount);
#define ast_StaticInitializer__optional_NotSet NULL
#define ast_StaticInitializer__optional_Set(variables, variableCount) ast_StaticInitializerAssign((ast_StaticInitializer*)corto_calloc(sizeof(ast_StaticInitializer)), variables, variableCount)
#define ast_StaticInitializer__optional_SetCond(cond, variables, variableCount) cond ? ast_StaticInitializerAssign((ast_StaticInitializer*)corto_calloc(sizeof(ast_StaticInitializer)), variables, variableCount) : NULL
#define ast_StaticInitializerUnset(_this) _this ? corto_deinitp(_this, ast_StaticInitializer_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_StaticInitializerAssign(_this, variables, variableCount) _ast_StaticInitializerAssign(_this, variables, variableCount)
#define ast_StaticInitializerSet(_this, variables, variableCount) _this = _this ? _this : (ast_StaticInitializer*)corto_calloc(sizeof(ast_StaticInitializer)); _ast_StaticInitializerAssign(_this, variables, variableCount)
CORTO_AST_EXPORT corto_string _ast_StaticInitializerStr(ast_StaticInitializer value);
#define ast_StaticInitializerStr(value) _ast_StaticInitializerStr(ast_StaticInitializer(value))
CORTO_AST_EXPORT ast_StaticInitializer ast_StaticInitializerFromStr(ast_StaticInitializer value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_StaticInitializerCompare(ast_StaticInitializer dst, ast_StaticInitializer src);
#define ast_StaticInitializerCompare(dst, src) _ast_StaticInitializerCompare(ast_StaticInitializer(dst), ast_StaticInitializer(src))

/* /corto/ast/StaticInitializerFrame */
CORTO_AST_EXPORT ast_StaticInitializerFrame* _ast_StaticInitializerFrameCreate(corto_wordArray64 ptr, corto_wordArray64 keyPtr);
#define ast_StaticInitializerFrameCreate(ptr, keyPtr) _ast_StaticInitializerFrameCreate(ptr, keyPtr)
#define ast_StaticInitializerFrameCreate_auto(_id, ptr, keyPtr) ast_StaticInitializerFrame* _id = ast_StaticInitializerFrameCreate(ptr, keyPtr); (void)_id
CORTO_AST_EXPORT ast_StaticInitializerFrame* _ast_StaticInitializerFrameCreateChild(corto_object _parent, corto_string _id, corto_wordArray64 ptr, corto_wordArray64 keyPtr);
#define ast_StaticInitializerFrameCreateChild(_parent, _id, ptr, keyPtr) _ast_StaticInitializerFrameCreateChild(_parent, _id, ptr, keyPtr)
#define ast_StaticInitializerFrameCreateChild_auto(_parent, _id, ptr, keyPtr) ast_StaticInitializerFrame* _id = ast_StaticInitializerFrameCreateChild(_parent, #_id, ptr, keyPtr); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StaticInitializerFrameUpdate(ast_StaticInitializerFrame* _this, corto_wordArray64 ptr, corto_wordArray64 keyPtr);
#define ast_StaticInitializerFrameUpdate(_this, ptr, keyPtr) _ast_StaticInitializerFrameUpdate(ast_StaticInitializerFrame(_this), ptr, keyPtr)

CORTO_AST_EXPORT ast_StaticInitializerFrame* _ast_StaticInitializerFrameDeclare(void);
#define ast_StaticInitializerFrameDeclare() _ast_StaticInitializerFrameDeclare()
#define ast_StaticInitializerFrameDeclare_auto(_id) ast_StaticInitializerFrame* _id = ast_StaticInitializerFrameDeclare(); (void)_id
CORTO_AST_EXPORT ast_StaticInitializerFrame* _ast_StaticInitializerFrameDeclareChild(corto_object _parent, corto_string _id);
#define ast_StaticInitializerFrameDeclareChild(_parent, _id) _ast_StaticInitializerFrameDeclareChild(_parent, _id)
#define ast_StaticInitializerFrameDeclareChild_auto(_parent, _id) ast_StaticInitializerFrame* _id = ast_StaticInitializerFrameDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StaticInitializerFrameDefine(ast_StaticInitializerFrame* _this, corto_wordArray64 ptr, corto_wordArray64 keyPtr);
#define ast_StaticInitializerFrameDefine(_this, ptr, keyPtr) _ast_StaticInitializerFrameDefine(ast_StaticInitializerFrame(_this), ptr, keyPtr)
CORTO_AST_EXPORT ast_StaticInitializerFrame* _ast_StaticInitializerFrameAssign(ast_StaticInitializerFrame* _this, corto_wordArray64 ptr, corto_wordArray64 keyPtr);
#define ast_StaticInitializerFrame__optional_NotSet NULL
#define ast_StaticInitializerFrame__optional_Set(ptr, keyPtr) ast_StaticInitializerFrameAssign((ast_StaticInitializerFrame*)corto_calloc(sizeof(ast_StaticInitializerFrame)), ptr, keyPtr)
#define ast_StaticInitializerFrame__optional_SetCond(cond, ptr, keyPtr) cond ? ast_StaticInitializerFrameAssign((ast_StaticInitializerFrame*)corto_calloc(sizeof(ast_StaticInitializerFrame)), ptr, keyPtr) : NULL
#define ast_StaticInitializerFrameUnset(_this) _this ? corto_deinitp(_this, ast_StaticInitializerFrame_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_StaticInitializerFrameAssign(_this, ptr, keyPtr) _ast_StaticInitializerFrameAssign(_this, ptr, keyPtr)
#define ast_StaticInitializerFrameSet(_this, ptr, keyPtr) _this = _this ? _this : (ast_StaticInitializerFrame*)corto_calloc(sizeof(ast_StaticInitializerFrame)); _ast_StaticInitializerFrameAssign(_this, ptr, keyPtr)
CORTO_AST_EXPORT corto_string _ast_StaticInitializerFrameStr(ast_StaticInitializerFrame* value);
#define ast_StaticInitializerFrameStr(value) _ast_StaticInitializerFrameStr(value)
CORTO_AST_EXPORT ast_StaticInitializerFrame* ast_StaticInitializerFrameFromStr(ast_StaticInitializerFrame* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_StaticInitializerFrameCompare(ast_StaticInitializerFrame* dst, ast_StaticInitializerFrame* src);

CORTO_AST_EXPORT corto_int16 _ast_StaticInitializerFrameInit(ast_StaticInitializerFrame* value);
#define ast_StaticInitializerFrameInit(value) _ast_StaticInitializerFrameInit(value)
CORTO_AST_EXPORT corto_int16 _ast_StaticInitializerFrameDeinit(ast_StaticInitializerFrame* value);
#define ast_StaticInitializerFrameDeinit(value) _ast_StaticInitializerFrameDeinit(value)

/* /corto/ast/Storage */
CORTO_AST_EXPORT ast_Storage _ast_StorageCreate(ast_storageKind kind_1);
#define ast_StorageCreate(kind_1) _ast_StorageCreate(kind_1)
#define ast_StorageCreate_auto(_id, kind_1) ast_Storage _id = ast_StorageCreate(kind_1); (void)_id
CORTO_AST_EXPORT ast_Storage _ast_StorageCreateChild(corto_object _parent, corto_string _id, ast_storageKind kind_1);
#define ast_StorageCreateChild(_parent, _id, kind_1) _ast_StorageCreateChild(_parent, _id, kind_1)
#define ast_StorageCreateChild_auto(_parent, _id, kind_1) ast_Storage _id = ast_StorageCreateChild(_parent, #_id, kind_1); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StorageUpdate(ast_Storage _this, ast_storageKind kind_1);
#define ast_StorageUpdate(_this, kind_1) _ast_StorageUpdate(ast_Storage(_this), kind_1)

CORTO_AST_EXPORT ast_Storage _ast_StorageDeclare(void);
#define ast_StorageDeclare() _ast_StorageDeclare()
#define ast_StorageDeclare_auto(_id) ast_Storage _id = ast_StorageDeclare(); (void)_id
CORTO_AST_EXPORT ast_Storage _ast_StorageDeclareChild(corto_object _parent, corto_string _id);
#define ast_StorageDeclareChild(_parent, _id) _ast_StorageDeclareChild(_parent, _id)
#define ast_StorageDeclareChild_auto(_parent, _id) ast_Storage _id = ast_StorageDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StorageDefine(ast_Storage _this, ast_storageKind kind_1);
#define ast_StorageDefine(_this, kind_1) _ast_StorageDefine(ast_Storage(_this), kind_1)
CORTO_AST_EXPORT ast_Storage _ast_StorageAssign(ast_Storage _this, ast_storageKind kind_1);
#define ast_Storage__optional_NotSet NULL
#define ast_Storage__optional_Set(kind_1) ast_StorageAssign((ast_Storage*)corto_calloc(sizeof(ast_Storage)), kind_1)
#define ast_Storage__optional_SetCond(cond, kind_1) cond ? ast_StorageAssign((ast_Storage*)corto_calloc(sizeof(ast_Storage)), kind_1) : NULL
#define ast_StorageUnset(_this) _this ? corto_deinitp(_this, ast_Storage_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_StorageAssign(_this, kind_1) _ast_StorageAssign(_this, kind_1)
#define ast_StorageSet(_this, kind_1) _this = _this ? _this : (ast_Storage*)corto_calloc(sizeof(ast_Storage)); _ast_StorageAssign(_this, kind_1)
CORTO_AST_EXPORT corto_string _ast_StorageStr(ast_Storage value);
#define ast_StorageStr(value) _ast_StorageStr(ast_Storage(value))
CORTO_AST_EXPORT ast_Storage ast_StorageFromStr(ast_Storage value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_StorageCompare(ast_Storage dst, ast_Storage src);
#define ast_StorageCompare(dst, src) _ast_StorageCompare(ast_Storage(dst), ast_Storage(src))

/* /corto/ast/storageKind */
CORTO_AST_EXPORT ast_storageKind* _ast_storageKindCreate(ast_storageKind value);
#define ast_storageKindCreate(value) _ast_storageKindCreate(value)
#define ast_storageKindCreate_auto(_id, value) ast_storageKind* _id = ast_storageKindCreate(value); (void)_id
CORTO_AST_EXPORT ast_storageKind* _ast_storageKindCreateChild(corto_object _parent, corto_string _id, ast_storageKind value);
#define ast_storageKindCreateChild(_parent, _id, value) _ast_storageKindCreateChild(_parent, _id, value)
#define ast_storageKindCreateChild_auto(_parent, _id, value) ast_storageKind* _id = ast_storageKindCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_storageKindUpdate(ast_storageKind* _this, ast_storageKind value);
#define ast_storageKindUpdate(_this, value) _ast_storageKindUpdate(ast_storageKind(_this), value)

CORTO_AST_EXPORT ast_storageKind* _ast_storageKindDeclare(void);
#define ast_storageKindDeclare() _ast_storageKindDeclare()
#define ast_storageKindDeclare_auto(_id) ast_storageKind* _id = ast_storageKindDeclare(); (void)_id
CORTO_AST_EXPORT ast_storageKind* _ast_storageKindDeclareChild(corto_object _parent, corto_string _id);
#define ast_storageKindDeclareChild(_parent, _id) _ast_storageKindDeclareChild(_parent, _id)
#define ast_storageKindDeclareChild_auto(_parent, _id) ast_storageKind* _id = ast_storageKindDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_storageKindDefine(ast_storageKind* _this, ast_storageKind value);
#define ast_storageKindDefine(_this, value) _ast_storageKindDefine(ast_storageKind(_this), value)
CORTO_AST_EXPORT ast_storageKind* _ast_storageKindAssign(ast_storageKind* _this, ast_storageKind value);
#define ast_storageKind__optional_NotSet NULL
#define ast_storageKind__optional_Set(value) ast_storageKindAssign((ast_storageKind*)corto_calloc(sizeof(ast_storageKind)), value)
#define ast_storageKind__optional_SetCond(cond, value) cond ? ast_storageKindAssign((ast_storageKind*)corto_calloc(sizeof(ast_storageKind)), value) : NULL
#define ast_storageKindUnset(_this) _this ? corto_deinitp(_this, ast_storageKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_storageKindAssign(_this, value) _ast_storageKindAssign(_this, value)
#define ast_storageKindSet(_this, value) _this = _this ? _this : (ast_storageKind*)corto_calloc(sizeof(ast_storageKind)); _ast_storageKindAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_storageKindStr(ast_storageKind value);
#define ast_storageKindStr(value) _ast_storageKindStr(value)
CORTO_AST_EXPORT ast_storageKind* ast_storageKindFromStr(ast_storageKind* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_storageKindCompare(ast_storageKind dst, ast_storageKind src);

CORTO_AST_EXPORT corto_int16 _ast_storageKindInit(ast_storageKind* value);
#define ast_storageKindInit(value) _ast_storageKindInit(value)
CORTO_AST_EXPORT corto_int16 _ast_storageKindDeinit(ast_storageKind* value);
#define ast_storageKindDeinit(value) _ast_storageKindDeinit(value)

/* /corto/ast/String */
CORTO_AST_EXPORT ast_String _ast_StringCreate(corto_string value);
#define ast_StringCreate(value) _ast_StringCreate(value)
#define ast_StringCreate_auto(_id, value) ast_String _id = ast_StringCreate(value); (void)_id
CORTO_AST_EXPORT ast_String _ast_StringCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define ast_StringCreateChild(_parent, _id, value) _ast_StringCreateChild(_parent, _id, value)
#define ast_StringCreateChild_auto(_parent, _id, value) ast_String _id = ast_StringCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StringUpdate(ast_String _this, corto_string value);
#define ast_StringUpdate(_this, value) _ast_StringUpdate(ast_String(_this), value)

CORTO_AST_EXPORT ast_String _ast_StringDeclare(void);
#define ast_StringDeclare() _ast_StringDeclare()
#define ast_StringDeclare_auto(_id) ast_String _id = ast_StringDeclare(); (void)_id
CORTO_AST_EXPORT ast_String _ast_StringDeclareChild(corto_object _parent, corto_string _id);
#define ast_StringDeclareChild(_parent, _id) _ast_StringDeclareChild(_parent, _id)
#define ast_StringDeclareChild_auto(_parent, _id) ast_String _id = ast_StringDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_StringDefine(ast_String _this, corto_string value);
#define ast_StringDefine(_this, value) _ast_StringDefine(ast_String(_this), value)
CORTO_AST_EXPORT ast_String _ast_StringAssign(ast_String _this, corto_string value);
#define ast_String__optional_NotSet NULL
#define ast_String__optional_Set(value) ast_StringAssign((ast_String*)corto_calloc(sizeof(ast_String)), value)
#define ast_String__optional_SetCond(cond, value) cond ? ast_StringAssign((ast_String*)corto_calloc(sizeof(ast_String)), value) : NULL
#define ast_StringUnset(_this) _this ? corto_deinitp(_this, ast_String_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_StringAssign(_this, value) _ast_StringAssign(_this, value)
#define ast_StringSet(_this, value) _this = _this ? _this : (ast_String*)corto_calloc(sizeof(ast_String)); _ast_StringAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_StringStr(ast_String value);
#define ast_StringStr(value) _ast_StringStr(ast_String(value))
CORTO_AST_EXPORT ast_String ast_StringFromStr(ast_String value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_StringCompare(ast_String dst, ast_String src);
#define ast_StringCompare(dst, src) _ast_StringCompare(ast_String(dst), ast_String(src))

/* /corto/ast/Template */
CORTO_AST_EXPORT ast_Template _ast_TemplateCreate(corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_TemplateCreate(name, type_1, kind_2, reference) _ast_TemplateCreate(name, corto_type(type_1), kind_2, reference)
#define ast_TemplateCreate_auto(_id, name, type_1, kind_2, reference) ast_Template _id = ast_TemplateCreate(name, type_1, kind_2, reference); (void)_id
CORTO_AST_EXPORT ast_Template _ast_TemplateCreateChild(corto_object _parent, corto_string _id, corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_TemplateCreateChild(_parent, _id, name, type_1, kind_2, reference) _ast_TemplateCreateChild(_parent, _id, name, corto_type(type_1), kind_2, reference)
#define ast_TemplateCreateChild_auto(_parent, _id, name, type_1, kind_2, reference) ast_Template _id = ast_TemplateCreateChild(_parent, #_id, name, type_1, kind_2, reference); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_TemplateUpdate(ast_Template _this, corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_TemplateUpdate(_this, name, type_1, kind_2, reference) _ast_TemplateUpdate(ast_Template(_this), name, corto_type(type_1), kind_2, reference)

CORTO_AST_EXPORT ast_Template _ast_TemplateDeclare(void);
#define ast_TemplateDeclare() _ast_TemplateDeclare()
#define ast_TemplateDeclare_auto(_id) ast_Template _id = ast_TemplateDeclare(); (void)_id
CORTO_AST_EXPORT ast_Template _ast_TemplateDeclareChild(corto_object _parent, corto_string _id);
#define ast_TemplateDeclareChild(_parent, _id) _ast_TemplateDeclareChild(_parent, _id)
#define ast_TemplateDeclareChild_auto(_parent, _id) ast_Template _id = ast_TemplateDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_TemplateDefine(ast_Template _this, corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_TemplateDefine(_this, name, type_1, kind_2, reference) _ast_TemplateDefine(ast_Template(_this), name, corto_type(type_1), kind_2, reference)
CORTO_AST_EXPORT ast_Template _ast_TemplateAssign(ast_Template _this, corto_string name, corto_type type_1, ast_LocalKind kind_2, corto_bool reference);
#define ast_Template__optional_NotSet NULL
#define ast_Template__optional_Set(name, type_1, kind_2, reference) ast_TemplateAssign((ast_Template*)corto_calloc(sizeof(ast_Template)), name, type_1, kind_2, reference)
#define ast_Template__optional_SetCond(cond, name, type_1, kind_2, reference) cond ? ast_TemplateAssign((ast_Template*)corto_calloc(sizeof(ast_Template)), name, type_1, kind_2, reference) : NULL
#define ast_TemplateUnset(_this) _this ? corto_deinitp(_this, ast_Template_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_TemplateAssign(_this, name, type_1, kind_2, reference) _ast_TemplateAssign(_this, name, corto_type(type_1), kind_2, reference)
#define ast_TemplateSet(_this, name, type_1, kind_2, reference) _this = _this ? _this : (ast_Template*)corto_calloc(sizeof(ast_Template)); _ast_TemplateAssign(_this, name, corto_type(type_1), kind_2, reference)
CORTO_AST_EXPORT corto_string _ast_TemplateStr(ast_Template value);
#define ast_TemplateStr(value) _ast_TemplateStr(ast_Template(value))
CORTO_AST_EXPORT ast_Template ast_TemplateFromStr(ast_Template value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_TemplateCompare(ast_Template dst, ast_Template src);
#define ast_TemplateCompare(dst, src) _ast_TemplateCompare(ast_Template(dst), ast_Template(src))

/* /corto/ast/Temporary */
CORTO_AST_EXPORT ast_Temporary _ast_TemporaryCreate(corto_type type_1, corto_bool reference);
#define ast_TemporaryCreate(type_1, reference) _ast_TemporaryCreate(corto_type(type_1), reference)
#define ast_TemporaryCreate_auto(_id, type_1, reference) ast_Temporary _id = ast_TemporaryCreate(type_1, reference); (void)_id
CORTO_AST_EXPORT ast_Temporary _ast_TemporaryCreateChild(corto_object _parent, corto_string _id, corto_type type_1, corto_bool reference);
#define ast_TemporaryCreateChild(_parent, _id, type_1, reference) _ast_TemporaryCreateChild(_parent, _id, corto_type(type_1), reference)
#define ast_TemporaryCreateChild_auto(_parent, _id, type_1, reference) ast_Temporary _id = ast_TemporaryCreateChild(_parent, #_id, type_1, reference); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_TemporaryUpdate(ast_Temporary _this, corto_type type_1, corto_bool reference);
#define ast_TemporaryUpdate(_this, type_1, reference) _ast_TemporaryUpdate(ast_Temporary(_this), corto_type(type_1), reference)

CORTO_AST_EXPORT ast_Temporary _ast_TemporaryDeclare(void);
#define ast_TemporaryDeclare() _ast_TemporaryDeclare()
#define ast_TemporaryDeclare_auto(_id) ast_Temporary _id = ast_TemporaryDeclare(); (void)_id
CORTO_AST_EXPORT ast_Temporary _ast_TemporaryDeclareChild(corto_object _parent, corto_string _id);
#define ast_TemporaryDeclareChild(_parent, _id) _ast_TemporaryDeclareChild(_parent, _id)
#define ast_TemporaryDeclareChild_auto(_parent, _id) ast_Temporary _id = ast_TemporaryDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_TemporaryDefine(ast_Temporary _this, corto_type type_1, corto_bool reference);
#define ast_TemporaryDefine(_this, type_1, reference) _ast_TemporaryDefine(ast_Temporary(_this), corto_type(type_1), reference)
CORTO_AST_EXPORT ast_Temporary _ast_TemporaryAssign(ast_Temporary _this, corto_type type_1, corto_bool reference);
#define ast_Temporary__optional_NotSet NULL
#define ast_Temporary__optional_Set(type_1, reference) ast_TemporaryAssign((ast_Temporary*)corto_calloc(sizeof(ast_Temporary)), type_1, reference)
#define ast_Temporary__optional_SetCond(cond, type_1, reference) cond ? ast_TemporaryAssign((ast_Temporary*)corto_calloc(sizeof(ast_Temporary)), type_1, reference) : NULL
#define ast_TemporaryUnset(_this) _this ? corto_deinitp(_this, ast_Temporary_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_TemporaryAssign(_this, type_1, reference) _ast_TemporaryAssign(_this, corto_type(type_1), reference)
#define ast_TemporarySet(_this, type_1, reference) _this = _this ? _this : (ast_Temporary*)corto_calloc(sizeof(ast_Temporary)); _ast_TemporaryAssign(_this, corto_type(type_1), reference)
CORTO_AST_EXPORT corto_string _ast_TemporaryStr(ast_Temporary value);
#define ast_TemporaryStr(value) _ast_TemporaryStr(ast_Temporary(value))
CORTO_AST_EXPORT ast_Temporary ast_TemporaryFromStr(ast_Temporary value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_TemporaryCompare(ast_Temporary dst, ast_Temporary src);
#define ast_TemporaryCompare(dst, src) _ast_TemporaryCompare(ast_Temporary(dst), ast_Temporary(src))

/* /corto/ast/Ternary */
CORTO_AST_EXPORT ast_Ternary _ast_TernaryCreate(ast_Expression condition, ast_Expression ifTrue, ast_Expression ifFalse, ast_Expression result);
#define ast_TernaryCreate(condition, ifTrue, ifFalse, result) _ast_TernaryCreate(ast_Expression(condition), ast_Expression(ifTrue), ast_Expression(ifFalse), ast_Expression(result))
#define ast_TernaryCreate_auto(_id, condition, ifTrue, ifFalse, result) ast_Ternary _id = ast_TernaryCreate(condition, ifTrue, ifFalse, result); (void)_id
CORTO_AST_EXPORT ast_Ternary _ast_TernaryCreateChild(corto_object _parent, corto_string _id, ast_Expression condition, ast_Expression ifTrue, ast_Expression ifFalse, ast_Expression result);
#define ast_TernaryCreateChild(_parent, _id, condition, ifTrue, ifFalse, result) _ast_TernaryCreateChild(_parent, _id, ast_Expression(condition), ast_Expression(ifTrue), ast_Expression(ifFalse), ast_Expression(result))
#define ast_TernaryCreateChild_auto(_parent, _id, condition, ifTrue, ifFalse, result) ast_Ternary _id = ast_TernaryCreateChild(_parent, #_id, condition, ifTrue, ifFalse, result); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_TernaryUpdate(ast_Ternary _this, ast_Expression condition, ast_Expression ifTrue, ast_Expression ifFalse, ast_Expression result);
#define ast_TernaryUpdate(_this, condition, ifTrue, ifFalse, result) _ast_TernaryUpdate(ast_Ternary(_this), ast_Expression(condition), ast_Expression(ifTrue), ast_Expression(ifFalse), ast_Expression(result))

CORTO_AST_EXPORT ast_Ternary _ast_TernaryDeclare(void);
#define ast_TernaryDeclare() _ast_TernaryDeclare()
#define ast_TernaryDeclare_auto(_id) ast_Ternary _id = ast_TernaryDeclare(); (void)_id
CORTO_AST_EXPORT ast_Ternary _ast_TernaryDeclareChild(corto_object _parent, corto_string _id);
#define ast_TernaryDeclareChild(_parent, _id) _ast_TernaryDeclareChild(_parent, _id)
#define ast_TernaryDeclareChild_auto(_parent, _id) ast_Ternary _id = ast_TernaryDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_TernaryDefine(ast_Ternary _this, ast_Expression condition, ast_Expression ifTrue, ast_Expression ifFalse, ast_Expression result);
#define ast_TernaryDefine(_this, condition, ifTrue, ifFalse, result) _ast_TernaryDefine(ast_Ternary(_this), ast_Expression(condition), ast_Expression(ifTrue), ast_Expression(ifFalse), ast_Expression(result))
CORTO_AST_EXPORT ast_Ternary _ast_TernaryAssign(ast_Ternary _this, ast_Expression condition, ast_Expression ifTrue, ast_Expression ifFalse, ast_Expression result);
#define ast_Ternary__optional_NotSet NULL
#define ast_Ternary__optional_Set(condition, ifTrue, ifFalse, result) ast_TernaryAssign((ast_Ternary*)corto_calloc(sizeof(ast_Ternary)), condition, ifTrue, ifFalse, result)
#define ast_Ternary__optional_SetCond(cond, condition, ifTrue, ifFalse, result) cond ? ast_TernaryAssign((ast_Ternary*)corto_calloc(sizeof(ast_Ternary)), condition, ifTrue, ifFalse, result) : NULL
#define ast_TernaryUnset(_this) _this ? corto_deinitp(_this, ast_Ternary_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_TernaryAssign(_this, condition, ifTrue, ifFalse, result) _ast_TernaryAssign(_this, ast_Expression(condition), ast_Expression(ifTrue), ast_Expression(ifFalse), ast_Expression(result))
#define ast_TernarySet(_this, condition, ifTrue, ifFalse, result) _this = _this ? _this : (ast_Ternary*)corto_calloc(sizeof(ast_Ternary)); _ast_TernaryAssign(_this, ast_Expression(condition), ast_Expression(ifTrue), ast_Expression(ifFalse), ast_Expression(result))
CORTO_AST_EXPORT corto_string _ast_TernaryStr(ast_Ternary value);
#define ast_TernaryStr(value) _ast_TernaryStr(ast_Ternary(value))
CORTO_AST_EXPORT ast_Ternary ast_TernaryFromStr(ast_Ternary value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_TernaryCompare(ast_Ternary dst, ast_Ternary src);
#define ast_TernaryCompare(dst, src) _ast_TernaryCompare(ast_Ternary(dst), ast_Ternary(src))

/* /corto/ast/Unary */
CORTO_AST_EXPORT ast_Unary _ast_UnaryCreate(ast_Expression lvalue, corto_operatorKind _operator);
#define ast_UnaryCreate(lvalue, _operator) _ast_UnaryCreate(ast_Expression(lvalue), _operator)
#define ast_UnaryCreate_auto(_id, lvalue, _operator) ast_Unary _id = ast_UnaryCreate(lvalue, _operator); (void)_id
CORTO_AST_EXPORT ast_Unary _ast_UnaryCreateChild(corto_object _parent, corto_string _id, ast_Expression lvalue, corto_operatorKind _operator);
#define ast_UnaryCreateChild(_parent, _id, lvalue, _operator) _ast_UnaryCreateChild(_parent, _id, ast_Expression(lvalue), _operator)
#define ast_UnaryCreateChild_auto(_parent, _id, lvalue, _operator) ast_Unary _id = ast_UnaryCreateChild(_parent, #_id, lvalue, _operator); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_UnaryUpdate(ast_Unary _this, ast_Expression lvalue, corto_operatorKind _operator);
#define ast_UnaryUpdate(_this, lvalue, _operator) _ast_UnaryUpdate(ast_Unary(_this), ast_Expression(lvalue), _operator)

CORTO_AST_EXPORT ast_Unary _ast_UnaryDeclare(void);
#define ast_UnaryDeclare() _ast_UnaryDeclare()
#define ast_UnaryDeclare_auto(_id) ast_Unary _id = ast_UnaryDeclare(); (void)_id
CORTO_AST_EXPORT ast_Unary _ast_UnaryDeclareChild(corto_object _parent, corto_string _id);
#define ast_UnaryDeclareChild(_parent, _id) _ast_UnaryDeclareChild(_parent, _id)
#define ast_UnaryDeclareChild_auto(_parent, _id) ast_Unary _id = ast_UnaryDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_UnaryDefine(ast_Unary _this, ast_Expression lvalue, corto_operatorKind _operator);
#define ast_UnaryDefine(_this, lvalue, _operator) _ast_UnaryDefine(ast_Unary(_this), ast_Expression(lvalue), _operator)
CORTO_AST_EXPORT ast_Unary _ast_UnaryAssign(ast_Unary _this, ast_Expression lvalue, corto_operatorKind _operator);
#define ast_Unary__optional_NotSet NULL
#define ast_Unary__optional_Set(lvalue, _operator) ast_UnaryAssign((ast_Unary*)corto_calloc(sizeof(ast_Unary)), lvalue, _operator)
#define ast_Unary__optional_SetCond(cond, lvalue, _operator) cond ? ast_UnaryAssign((ast_Unary*)corto_calloc(sizeof(ast_Unary)), lvalue, _operator) : NULL
#define ast_UnaryUnset(_this) _this ? corto_deinitp(_this, ast_Unary_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_UnaryAssign(_this, lvalue, _operator) _ast_UnaryAssign(_this, ast_Expression(lvalue), _operator)
#define ast_UnarySet(_this, lvalue, _operator) _this = _this ? _this : (ast_Unary*)corto_calloc(sizeof(ast_Unary)); _ast_UnaryAssign(_this, ast_Expression(lvalue), _operator)
CORTO_AST_EXPORT corto_string _ast_UnaryStr(ast_Unary value);
#define ast_UnaryStr(value) _ast_UnaryStr(ast_Unary(value))
CORTO_AST_EXPORT ast_Unary ast_UnaryFromStr(ast_Unary value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_UnaryCompare(ast_Unary dst, ast_Unary src);
#define ast_UnaryCompare(dst, src) _ast_UnaryCompare(ast_Unary(dst), ast_Unary(src))

/* /corto/ast/UnresolvedReference */
CORTO_AST_EXPORT ast_UnresolvedReference _ast_UnresolvedReferenceCreate(corto_string ref, corto_object scope, corto_uint32 line_1, corto_uint32 column_1);
#define ast_UnresolvedReferenceCreate(ref, scope, line_1, column_1) _ast_UnresolvedReferenceCreate(ref, scope, line_1, column_1)
#define ast_UnresolvedReferenceCreate_auto(_id, ref, scope, line_1, column_1) ast_UnresolvedReference _id = ast_UnresolvedReferenceCreate(ref, scope, line_1, column_1); (void)_id
CORTO_AST_EXPORT ast_UnresolvedReference _ast_UnresolvedReferenceCreateChild(corto_object _parent, corto_string _id, corto_string ref, corto_object scope, corto_uint32 line_1, corto_uint32 column_1);
#define ast_UnresolvedReferenceCreateChild(_parent, _id, ref, scope, line_1, column_1) _ast_UnresolvedReferenceCreateChild(_parent, _id, ref, scope, line_1, column_1)
#define ast_UnresolvedReferenceCreateChild_auto(_parent, _id, ref, scope, line_1, column_1) ast_UnresolvedReference _id = ast_UnresolvedReferenceCreateChild(_parent, #_id, ref, scope, line_1, column_1); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_UnresolvedReferenceUpdate(ast_UnresolvedReference _this, corto_string ref, corto_object scope, corto_uint32 line_1, corto_uint32 column_1);
#define ast_UnresolvedReferenceUpdate(_this, ref, scope, line_1, column_1) _ast_UnresolvedReferenceUpdate(ast_UnresolvedReference(_this), ref, scope, line_1, column_1)

CORTO_AST_EXPORT ast_UnresolvedReference _ast_UnresolvedReferenceDeclare(void);
#define ast_UnresolvedReferenceDeclare() _ast_UnresolvedReferenceDeclare()
#define ast_UnresolvedReferenceDeclare_auto(_id) ast_UnresolvedReference _id = ast_UnresolvedReferenceDeclare(); (void)_id
CORTO_AST_EXPORT ast_UnresolvedReference _ast_UnresolvedReferenceDeclareChild(corto_object _parent, corto_string _id);
#define ast_UnresolvedReferenceDeclareChild(_parent, _id) _ast_UnresolvedReferenceDeclareChild(_parent, _id)
#define ast_UnresolvedReferenceDeclareChild_auto(_parent, _id) ast_UnresolvedReference _id = ast_UnresolvedReferenceDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_UnresolvedReferenceDefine(ast_UnresolvedReference _this, corto_string ref, corto_object scope, corto_uint32 line_1, corto_uint32 column_1);
#define ast_UnresolvedReferenceDefine(_this, ref, scope, line_1, column_1) _ast_UnresolvedReferenceDefine(ast_UnresolvedReference(_this), ref, scope, line_1, column_1)
CORTO_AST_EXPORT ast_UnresolvedReference _ast_UnresolvedReferenceAssign(ast_UnresolvedReference _this, corto_string ref, corto_object scope, corto_uint32 line_1, corto_uint32 column_1);
#define ast_UnresolvedReference__optional_NotSet NULL
#define ast_UnresolvedReference__optional_Set(ref, scope, line_1, column_1) ast_UnresolvedReferenceAssign((ast_UnresolvedReference*)corto_calloc(sizeof(ast_UnresolvedReference)), ref, scope, line_1, column_1)
#define ast_UnresolvedReference__optional_SetCond(cond, ref, scope, line_1, column_1) cond ? ast_UnresolvedReferenceAssign((ast_UnresolvedReference*)corto_calloc(sizeof(ast_UnresolvedReference)), ref, scope, line_1, column_1) : NULL
#define ast_UnresolvedReferenceUnset(_this) _this ? corto_deinitp(_this, ast_UnresolvedReference_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_UnresolvedReferenceAssign(_this, ref, scope, line_1, column_1) _ast_UnresolvedReferenceAssign(_this, ref, scope, line_1, column_1)
#define ast_UnresolvedReferenceSet(_this, ref, scope, line_1, column_1) _this = _this ? _this : (ast_UnresolvedReference*)corto_calloc(sizeof(ast_UnresolvedReference)); _ast_UnresolvedReferenceAssign(_this, ref, scope, line_1, column_1)
CORTO_AST_EXPORT corto_string _ast_UnresolvedReferenceStr(ast_UnresolvedReference value);
#define ast_UnresolvedReferenceStr(value) _ast_UnresolvedReferenceStr(ast_UnresolvedReference(value))
CORTO_AST_EXPORT ast_UnresolvedReference ast_UnresolvedReferenceFromStr(ast_UnresolvedReference value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_UnresolvedReferenceCompare(ast_UnresolvedReference dst, ast_UnresolvedReference src);
#define ast_UnresolvedReferenceCompare(dst, src) _ast_UnresolvedReferenceCompare(ast_UnresolvedReference(dst), ast_UnresolvedReference(src))

/* /corto/ast/Update */
CORTO_AST_EXPORT ast_Update _ast_UpdateCreate(ast_ExpressionList exprList, ast_Block block, ast_Expression from, ast_UpdateKind kind_1);
#define ast_UpdateCreate(exprList, block, from, kind_1) _ast_UpdateCreate(exprList, ast_Block(block), ast_Expression(from), kind_1)
#define ast_UpdateCreate_auto(_id, exprList, block, from, kind_1) ast_Update _id = ast_UpdateCreate(exprList, block, from, kind_1); (void)_id
CORTO_AST_EXPORT ast_Update _ast_UpdateCreateChild(corto_object _parent, corto_string _id, ast_ExpressionList exprList, ast_Block block, ast_Expression from, ast_UpdateKind kind_1);
#define ast_UpdateCreateChild(_parent, _id, exprList, block, from, kind_1) _ast_UpdateCreateChild(_parent, _id, exprList, ast_Block(block), ast_Expression(from), kind_1)
#define ast_UpdateCreateChild_auto(_parent, _id, exprList, block, from, kind_1) ast_Update _id = ast_UpdateCreateChild(_parent, #_id, exprList, block, from, kind_1); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_UpdateUpdate(ast_Update _this, ast_ExpressionList exprList, ast_Block block, ast_Expression from, ast_UpdateKind kind_1);
#define ast_UpdateUpdate(_this, exprList, block, from, kind_1) _ast_UpdateUpdate(ast_Update(_this), exprList, ast_Block(block), ast_Expression(from), kind_1)

CORTO_AST_EXPORT ast_Update _ast_UpdateDeclare(void);
#define ast_UpdateDeclare() _ast_UpdateDeclare()
#define ast_UpdateDeclare_auto(_id) ast_Update _id = ast_UpdateDeclare(); (void)_id
CORTO_AST_EXPORT ast_Update _ast_UpdateDeclareChild(corto_object _parent, corto_string _id);
#define ast_UpdateDeclareChild(_parent, _id) _ast_UpdateDeclareChild(_parent, _id)
#define ast_UpdateDeclareChild_auto(_parent, _id) ast_Update _id = ast_UpdateDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_UpdateDefine(ast_Update _this, ast_ExpressionList exprList, ast_Block block, ast_Expression from, ast_UpdateKind kind_1);
#define ast_UpdateDefine(_this, exprList, block, from, kind_1) _ast_UpdateDefine(ast_Update(_this), exprList, ast_Block(block), ast_Expression(from), kind_1)
CORTO_AST_EXPORT ast_Update _ast_UpdateAssign(ast_Update _this, ast_ExpressionList exprList, ast_Block block, ast_Expression from, ast_UpdateKind kind_1);
#define ast_Update__optional_NotSet NULL
#define ast_Update__optional_Set(exprList, block, from, kind_1) ast_UpdateAssign((ast_Update*)corto_calloc(sizeof(ast_Update)), exprList, block, from, kind_1)
#define ast_Update__optional_SetCond(cond, exprList, block, from, kind_1) cond ? ast_UpdateAssign((ast_Update*)corto_calloc(sizeof(ast_Update)), exprList, block, from, kind_1) : NULL
#define ast_UpdateUnset(_this) _this ? corto_deinitp(_this, ast_Update_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_UpdateAssign(_this, exprList, block, from, kind_1) _ast_UpdateAssign(_this, exprList, ast_Block(block), ast_Expression(from), kind_1)
#define ast_UpdateSet(_this, exprList, block, from, kind_1) _this = _this ? _this : (ast_Update*)corto_calloc(sizeof(ast_Update)); _ast_UpdateAssign(_this, exprList, ast_Block(block), ast_Expression(from), kind_1)
CORTO_AST_EXPORT corto_string _ast_UpdateStr(ast_Update value);
#define ast_UpdateStr(value) _ast_UpdateStr(ast_Update(value))
CORTO_AST_EXPORT ast_Update ast_UpdateFromStr(ast_Update value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_UpdateCompare(ast_Update dst, ast_Update src);
#define ast_UpdateCompare(dst, src) _ast_UpdateCompare(ast_Update(dst), ast_Update(src))

/* /corto/ast/UpdateKind */
CORTO_AST_EXPORT ast_UpdateKind* _ast_UpdateKindCreate(ast_UpdateKind value);
#define ast_UpdateKindCreate(value) _ast_UpdateKindCreate(value)
#define ast_UpdateKindCreate_auto(_id, value) ast_UpdateKind* _id = ast_UpdateKindCreate(value); (void)_id
CORTO_AST_EXPORT ast_UpdateKind* _ast_UpdateKindCreateChild(corto_object _parent, corto_string _id, ast_UpdateKind value);
#define ast_UpdateKindCreateChild(_parent, _id, value) _ast_UpdateKindCreateChild(_parent, _id, value)
#define ast_UpdateKindCreateChild_auto(_parent, _id, value) ast_UpdateKind* _id = ast_UpdateKindCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_UpdateKindUpdate(ast_UpdateKind* _this, ast_UpdateKind value);
#define ast_UpdateKindUpdate(_this, value) _ast_UpdateKindUpdate(ast_UpdateKind(_this), value)

CORTO_AST_EXPORT ast_UpdateKind* _ast_UpdateKindDeclare(void);
#define ast_UpdateKindDeclare() _ast_UpdateKindDeclare()
#define ast_UpdateKindDeclare_auto(_id) ast_UpdateKind* _id = ast_UpdateKindDeclare(); (void)_id
CORTO_AST_EXPORT ast_UpdateKind* _ast_UpdateKindDeclareChild(corto_object _parent, corto_string _id);
#define ast_UpdateKindDeclareChild(_parent, _id) _ast_UpdateKindDeclareChild(_parent, _id)
#define ast_UpdateKindDeclareChild_auto(_parent, _id) ast_UpdateKind* _id = ast_UpdateKindDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_UpdateKindDefine(ast_UpdateKind* _this, ast_UpdateKind value);
#define ast_UpdateKindDefine(_this, value) _ast_UpdateKindDefine(ast_UpdateKind(_this), value)
CORTO_AST_EXPORT ast_UpdateKind* _ast_UpdateKindAssign(ast_UpdateKind* _this, ast_UpdateKind value);
#define ast_UpdateKind__optional_NotSet NULL
#define ast_UpdateKind__optional_Set(value) ast_UpdateKindAssign((ast_UpdateKind*)corto_calloc(sizeof(ast_UpdateKind)), value)
#define ast_UpdateKind__optional_SetCond(cond, value) cond ? ast_UpdateKindAssign((ast_UpdateKind*)corto_calloc(sizeof(ast_UpdateKind)), value) : NULL
#define ast_UpdateKindUnset(_this) _this ? corto_deinitp(_this, ast_UpdateKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_UpdateKindAssign(_this, value) _ast_UpdateKindAssign(_this, value)
#define ast_UpdateKindSet(_this, value) _this = _this ? _this : (ast_UpdateKind*)corto_calloc(sizeof(ast_UpdateKind)); _ast_UpdateKindAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_UpdateKindStr(ast_UpdateKind value);
#define ast_UpdateKindStr(value) _ast_UpdateKindStr(value)
CORTO_AST_EXPORT ast_UpdateKind* ast_UpdateKindFromStr(ast_UpdateKind* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_UpdateKindCompare(ast_UpdateKind dst, ast_UpdateKind src);

CORTO_AST_EXPORT corto_int16 _ast_UpdateKindInit(ast_UpdateKind* value);
#define ast_UpdateKindInit(value) _ast_UpdateKindInit(value)
CORTO_AST_EXPORT corto_int16 _ast_UpdateKindDeinit(ast_UpdateKind* value);
#define ast_UpdateKindDeinit(value) _ast_UpdateKindDeinit(value)

/* /corto/ast/valueKind */
CORTO_AST_EXPORT ast_valueKind* _ast_valueKindCreate(ast_valueKind value);
#define ast_valueKindCreate(value) _ast_valueKindCreate(value)
#define ast_valueKindCreate_auto(_id, value) ast_valueKind* _id = ast_valueKindCreate(value); (void)_id
CORTO_AST_EXPORT ast_valueKind* _ast_valueKindCreateChild(corto_object _parent, corto_string _id, ast_valueKind value);
#define ast_valueKindCreateChild(_parent, _id, value) _ast_valueKindCreateChild(_parent, _id, value)
#define ast_valueKindCreateChild_auto(_parent, _id, value) ast_valueKind* _id = ast_valueKindCreateChild(_parent, #_id, value); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_valueKindUpdate(ast_valueKind* _this, ast_valueKind value);
#define ast_valueKindUpdate(_this, value) _ast_valueKindUpdate(ast_valueKind(_this), value)

CORTO_AST_EXPORT ast_valueKind* _ast_valueKindDeclare(void);
#define ast_valueKindDeclare() _ast_valueKindDeclare()
#define ast_valueKindDeclare_auto(_id) ast_valueKind* _id = ast_valueKindDeclare(); (void)_id
CORTO_AST_EXPORT ast_valueKind* _ast_valueKindDeclareChild(corto_object _parent, corto_string _id);
#define ast_valueKindDeclareChild(_parent, _id) _ast_valueKindDeclareChild(_parent, _id)
#define ast_valueKindDeclareChild_auto(_parent, _id) ast_valueKind* _id = ast_valueKindDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_valueKindDefine(ast_valueKind* _this, ast_valueKind value);
#define ast_valueKindDefine(_this, value) _ast_valueKindDefine(ast_valueKind(_this), value)
CORTO_AST_EXPORT ast_valueKind* _ast_valueKindAssign(ast_valueKind* _this, ast_valueKind value);
#define ast_valueKind__optional_NotSet NULL
#define ast_valueKind__optional_Set(value) ast_valueKindAssign((ast_valueKind*)corto_calloc(sizeof(ast_valueKind)), value)
#define ast_valueKind__optional_SetCond(cond, value) cond ? ast_valueKindAssign((ast_valueKind*)corto_calloc(sizeof(ast_valueKind)), value) : NULL
#define ast_valueKindUnset(_this) _this ? corto_deinitp(_this, ast_valueKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_valueKindAssign(_this, value) _ast_valueKindAssign(_this, value)
#define ast_valueKindSet(_this, value) _this = _this ? _this : (ast_valueKind*)corto_calloc(sizeof(ast_valueKind)); _ast_valueKindAssign(_this, value)
CORTO_AST_EXPORT corto_string _ast_valueKindStr(ast_valueKind value);
#define ast_valueKindStr(value) _ast_valueKindStr(value)
CORTO_AST_EXPORT ast_valueKind* ast_valueKindFromStr(ast_valueKind* value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind ast_valueKindCompare(ast_valueKind dst, ast_valueKind src);

CORTO_AST_EXPORT corto_int16 _ast_valueKindInit(ast_valueKind* value);
#define ast_valueKindInit(value) _ast_valueKindInit(value)
CORTO_AST_EXPORT corto_int16 _ast_valueKindDeinit(ast_valueKind* value);
#define ast_valueKindDeinit(value) _ast_valueKindDeinit(value)

/* /corto/ast/While */
CORTO_AST_EXPORT ast_While _ast_WhileCreate(ast_Expression condition, ast_Block trueBranch, corto_bool isUntil);
#define ast_WhileCreate(condition, trueBranch, isUntil) _ast_WhileCreate(ast_Expression(condition), ast_Block(trueBranch), isUntil)
#define ast_WhileCreate_auto(_id, condition, trueBranch, isUntil) ast_While _id = ast_WhileCreate(condition, trueBranch, isUntil); (void)_id
CORTO_AST_EXPORT ast_While _ast_WhileCreateChild(corto_object _parent, corto_string _id, ast_Expression condition, ast_Block trueBranch, corto_bool isUntil);
#define ast_WhileCreateChild(_parent, _id, condition, trueBranch, isUntil) _ast_WhileCreateChild(_parent, _id, ast_Expression(condition), ast_Block(trueBranch), isUntil)
#define ast_WhileCreateChild_auto(_parent, _id, condition, trueBranch, isUntil) ast_While _id = ast_WhileCreateChild(_parent, #_id, condition, trueBranch, isUntil); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_WhileUpdate(ast_While _this, ast_Expression condition, ast_Block trueBranch, corto_bool isUntil);
#define ast_WhileUpdate(_this, condition, trueBranch, isUntil) _ast_WhileUpdate(ast_While(_this), ast_Expression(condition), ast_Block(trueBranch), isUntil)

CORTO_AST_EXPORT ast_While _ast_WhileDeclare(void);
#define ast_WhileDeclare() _ast_WhileDeclare()
#define ast_WhileDeclare_auto(_id) ast_While _id = ast_WhileDeclare(); (void)_id
CORTO_AST_EXPORT ast_While _ast_WhileDeclareChild(corto_object _parent, corto_string _id);
#define ast_WhileDeclareChild(_parent, _id) _ast_WhileDeclareChild(_parent, _id)
#define ast_WhileDeclareChild_auto(_parent, _id) ast_While _id = ast_WhileDeclareChild(_parent, #_id); (void)_id
CORTO_AST_EXPORT corto_int16 _ast_WhileDefine(ast_While _this, ast_Expression condition, ast_Block trueBranch, corto_bool isUntil);
#define ast_WhileDefine(_this, condition, trueBranch, isUntil) _ast_WhileDefine(ast_While(_this), ast_Expression(condition), ast_Block(trueBranch), isUntil)
CORTO_AST_EXPORT ast_While _ast_WhileAssign(ast_While _this, ast_Expression condition, ast_Block trueBranch, corto_bool isUntil);
#define ast_While__optional_NotSet NULL
#define ast_While__optional_Set(condition, trueBranch, isUntil) ast_WhileAssign((ast_While*)corto_calloc(sizeof(ast_While)), condition, trueBranch, isUntil)
#define ast_While__optional_SetCond(cond, condition, trueBranch, isUntil) cond ? ast_WhileAssign((ast_While*)corto_calloc(sizeof(ast_While)), condition, trueBranch, isUntil) : NULL
#define ast_WhileUnset(_this) _this ? corto_deinitp(_this, ast_While_o) : 0; corto_dealloc(_this); _this = NULL;
#define ast_WhileAssign(_this, condition, trueBranch, isUntil) _ast_WhileAssign(_this, ast_Expression(condition), ast_Block(trueBranch), isUntil)
#define ast_WhileSet(_this, condition, trueBranch, isUntil) _this = _this ? _this : (ast_While*)corto_calloc(sizeof(ast_While)); _ast_WhileAssign(_this, ast_Expression(condition), ast_Block(trueBranch), isUntil)
CORTO_AST_EXPORT corto_string _ast_WhileStr(ast_While value);
#define ast_WhileStr(value) _ast_WhileStr(ast_While(value))
CORTO_AST_EXPORT ast_While ast_WhileFromStr(ast_While value, corto_string str);
CORTO_AST_EXPORT corto_equalityKind _ast_WhileCompare(ast_While dst, ast_While src);
#define ast_WhileCompare(dst, src) _ast_WhileCompare(ast_While(dst), ast_While(src))


/* list{/corto/ast/Binding,0} */
#define ast_BindingListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    ast_Binding elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = *(ast_Binding*)(corto_word)corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_AST_EXPORT ast_Binding* ast_BindingListInsertAlloc(ast_BindingList list);
CORTO_AST_EXPORT ast_Binding* ast_BindingListInsert(ast_BindingList list, ast_Binding* element);
CORTO_AST_EXPORT ast_Binding* ast_BindingListAppendAlloc(ast_BindingList list);
CORTO_AST_EXPORT ast_Binding* ast_BindingListAppend(ast_BindingList list, ast_Binding* element);
CORTO_AST_EXPORT ast_Binding* ast_BindingListTakeFirst(ast_BindingList list);
CORTO_AST_EXPORT ast_Binding* ast_BindingListLast(ast_BindingList list);
CORTO_AST_EXPORT ast_Binding* ast_BindingListGet(ast_BindingList list, corto_uint32 index);
CORTO_AST_EXPORT corto_uint32 ast_BindingListSize(ast_BindingList list);
CORTO_AST_EXPORT void ast_BindingListClear(ast_BindingList list);

/* list{/corto/ast/Expression,0} */
#define ast_ExpressionListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    ast_Expression elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = (ast_Expression)corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_AST_EXPORT void ast_ExpressionListInsert(ast_ExpressionList list, ast_Expression element);
CORTO_AST_EXPORT void ast_ExpressionListAppend(ast_ExpressionList list, ast_Expression element);
CORTO_AST_EXPORT void ast_ExpressionListRemove(ast_ExpressionList list, ast_Expression element);
CORTO_AST_EXPORT ast_Expression ast_ExpressionListTakeFirst(ast_ExpressionList list);
CORTO_AST_EXPORT ast_Expression ast_ExpressionListLast(ast_ExpressionList list);
CORTO_AST_EXPORT ast_Expression ast_ExpressionListGet(ast_ExpressionList list, corto_uint32 index);
CORTO_AST_EXPORT corto_uint32 ast_ExpressionListSize(ast_ExpressionList list);
CORTO_AST_EXPORT void ast_ExpressionListClear(ast_ExpressionList list);

/* list{/corto/ast/InitOper,0} */
#define ast_InitOperListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    ast_InitOper elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = *(ast_InitOper*)(corto_word)corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_AST_EXPORT ast_InitOper* ast_InitOperListInsertAlloc(ast_InitOperList list);
CORTO_AST_EXPORT ast_InitOper* ast_InitOperListInsert(ast_InitOperList list, ast_InitOper* element);
CORTO_AST_EXPORT ast_InitOper* ast_InitOperListAppendAlloc(ast_InitOperList list);
CORTO_AST_EXPORT ast_InitOper* ast_InitOperListAppend(ast_InitOperList list, ast_InitOper* element);
CORTO_AST_EXPORT ast_InitOper* ast_InitOperListTakeFirst(ast_InitOperList list);
CORTO_AST_EXPORT ast_InitOper* ast_InitOperListLast(ast_InitOperList list);
CORTO_AST_EXPORT ast_InitOper* ast_InitOperListGet(ast_InitOperList list, corto_uint32 index);
CORTO_AST_EXPORT corto_uint32 ast_InitOperListSize(ast_InitOperList list);
CORTO_AST_EXPORT void ast_InitOperListClear(ast_InitOperList list);

/* list{/corto/ast/Local,0} */
#define ast_LocalListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    ast_Local elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = (ast_Local)corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_AST_EXPORT void ast_LocalListInsert(ast_LocalList list, ast_Local element);
CORTO_AST_EXPORT void ast_LocalListAppend(ast_LocalList list, ast_Local element);
CORTO_AST_EXPORT void ast_LocalListRemove(ast_LocalList list, ast_Local element);
CORTO_AST_EXPORT ast_Local ast_LocalListTakeFirst(ast_LocalList list);
CORTO_AST_EXPORT ast_Local ast_LocalListLast(ast_LocalList list);
CORTO_AST_EXPORT ast_Local ast_LocalListGet(ast_LocalList list, corto_uint32 index);
CORTO_AST_EXPORT corto_uint32 ast_LocalListSize(ast_LocalList list);
CORTO_AST_EXPORT void ast_LocalListClear(ast_LocalList list);

/* list{/corto/ast/Node,0} */
#define ast_NodeListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    ast_Node elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = (ast_Node)corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_AST_EXPORT void ast_NodeListInsert(ast_NodeList list, ast_Node element);
CORTO_AST_EXPORT void ast_NodeListAppend(ast_NodeList list, ast_Node element);
CORTO_AST_EXPORT void ast_NodeListRemove(ast_NodeList list, ast_Node element);
CORTO_AST_EXPORT ast_Node ast_NodeListTakeFirst(ast_NodeList list);
CORTO_AST_EXPORT ast_Node ast_NodeListLast(ast_NodeList list);
CORTO_AST_EXPORT ast_Node ast_NodeListGet(ast_NodeList list, corto_uint32 index);
CORTO_AST_EXPORT corto_uint32 ast_NodeListSize(ast_NodeList list);
CORTO_AST_EXPORT void ast_NodeListClear(ast_NodeList list);

/* /corto/ast/ParserDeclarationSeq */
#define ast_ParserDeclarationSeqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    ast_ParserDeclaration elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_AST_EXPORT ast_ParserDeclaration* ast_ParserDeclarationSeqAppend(ast_ParserDeclarationSeq *seq, ast_ParserDeclaration element);
CORTO_AST_EXPORT ast_ParserDeclaration* ast_ParserDeclarationSeqAppendAlloc(ast_ParserDeclarationSeq *seq);
CORTO_AST_EXPORT void ast_ParserDeclarationSeqSize(ast_ParserDeclarationSeq *seq, corto_uint32 length);
CORTO_AST_EXPORT void ast_ParserDeclarationSeqClear(ast_ParserDeclarationSeq *seq);

/* sequence{parameter,0} */
#define corto_parameterSeqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_parameter elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_AST_EXPORT corto_parameter* corto_parameterSeqAppend(corto_parameterSeq *seq, corto_parameter element);
CORTO_AST_EXPORT corto_parameter* corto_parameterSeqAppendAlloc(corto_parameterSeq *seq);
CORTO_AST_EXPORT void corto_parameterSeqSize(corto_parameterSeq *seq, corto_uint32 length);
CORTO_AST_EXPORT void corto_parameterSeqClear(corto_parameterSeq *seq);

/* list{object,0} */
#define corto_objectListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    corto_object elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = (corto_object)corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_AST_EXPORT void corto_objectListInsert(corto_objectList list, corto_object element);
CORTO_AST_EXPORT void corto_objectListAppend(corto_objectList list, corto_object element);
CORTO_AST_EXPORT void corto_objectListRemove(corto_objectList list, corto_object element);
CORTO_AST_EXPORT corto_object corto_objectListTakeFirst(corto_objectList list);
CORTO_AST_EXPORT corto_object corto_objectListLast(corto_objectList list);
CORTO_AST_EXPORT corto_object corto_objectListGet(corto_objectList list, corto_uint32 index);
CORTO_AST_EXPORT corto_uint32 corto_objectListSize(corto_objectList list);
CORTO_AST_EXPORT void corto_objectListClear(corto_objectList list);

/* list{word,0} */
#define corto_wordListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    corto_word elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = (corto_word)(corto_word)corto_iterNext(&elem##_iter), TRUE : FALSE)

CORTO_AST_EXPORT void corto_wordListInsert(corto_wordList list, corto_word element);
CORTO_AST_EXPORT void corto_wordListAppend(corto_wordList list, corto_word element);
CORTO_AST_EXPORT corto_word corto_wordListTakeFirst(corto_wordList list);
CORTO_AST_EXPORT corto_word corto_wordListLast(corto_wordList list);
CORTO_AST_EXPORT corto_word corto_wordListGet(corto_wordList list, corto_uint32 index);
CORTO_AST_EXPORT corto_uint32 corto_wordListSize(corto_wordList list);
CORTO_AST_EXPORT void corto_wordListClear(corto_wordList list);

/* sequence{string,0} */
#define corto_stringSeqForeach(seq, elem) \
    corto_uint32 elem##_iter;\
    corto_string elem;\
    for(elem##_iter = 0; (elem##_iter < (seq).length) ? elem = (seq).buffer[elem##_iter], TRUE : FALSE; elem##_iter++)\

CORTO_AST_EXPORT corto_string* corto_stringSeqAppend(corto_stringSeq *seq, corto_string element);
CORTO_AST_EXPORT corto_string* corto_stringSeqAppendAlloc(corto_stringSeq *seq);
CORTO_AST_EXPORT void corto_stringSeqSize(corto_stringSeq *seq, corto_uint32 length);
CORTO_AST_EXPORT void corto_stringSeqClear(corto_stringSeq *seq);

#ifdef __cplusplus
}
#endif
#endif

