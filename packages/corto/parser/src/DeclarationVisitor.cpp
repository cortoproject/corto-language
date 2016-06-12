/* $CORTO_GENERATED
 *
 * DeclarationVisitor.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/parser/parser.h>

/* $header() */

struct _VisitorData {
    parser_DeclarationVisitor _this;
    corto_object currentScope;

    // TODO deprecate in favor of corto_typeof(currentObject);
    corto_type currentType;


    corto_object currentObject;
};

struct _FindMemberData
{
    /* DEPRECATED type where we want to find members */
    corto_type type;
    /* Current object that is being initialized */
    corto_object currentObject;
    /* lookForLocation and lookForString are mutually exclusive */
    // TODO rename to lookForPosition
    corto_int32 lookForLocation;
    // TODO rename to lookForName
    corto_string lookForString;
    /* the current member index of the serializer's */
    // TODO rename to serializerIndex
    corto_uint32 count;
    /* position of the current element in the initializer */
    // TODO rename to initializerIndex
    corto_uint32 current;
    corto_iter* argIter;
    // TODO rename to member
    /* member to be found by the serializer; goal of the serializer is to find it */
    corto_member m;
    corto_bool error;
};
static corto_int16 _findMember(corto_serializer s, corto_value* v, void* _data)
{
    _FindMemberData* data = (_FindMemberData*)_data;
    if ((data->lookForLocation >= 0) && ((corto_uint32)data->lookForLocation == data->count)) {
        corto_setref(&data->m, v->is.member.t);
        // data->m = v->is.member.t;
        // data->id = data->count;
        goto found;
    }
    if (data->lookForString && !strcmp(data->lookForString, corto_idof(v->is.member.t))) {
        corto_setref(&data->m, v->is.member.t);
        // data->m = v->is.member.t;
        // data->id = data->count;
        if (data->current >= data->count) {
            goto found;
        }
    }
    data->count++;
    return 0;

found:
    return -1;
}
struct corto_serializer_s _findMemberSerializer(corto_bool findHidden) {
    struct corto_serializer_s s;
    corto_serializerInit(&s);
    s.metaprogram[CORTO_MEMBER] = _findMember;
    s.access = CORTO_LOCAL | CORTO_PRIVATE | CORTO_READONLY;
    if (!findHidden) {
        s.access |= CORTO_HIDDEN;
    }
    s.accessKind = CORTO_NOT;
    s.traceKind = CORTO_SERIALIZER_TRACE_NEVER;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_FOLLOW;
    return s;
}

/* $end */

corto_int16 _parser_DeclarationVisitor_construct(
    parser_DeclarationVisitor _this)
{
/* $begin(corto/parser/DeclarationVisitor/construct) */
    corto_setref(&_this->currentScope, root_o);
    return 0;
/* $end */
}

corto_object _parser_DeclarationVisitor_visit(
    parser_DeclarationVisitor _this)
{
/* $begin(corto/parser/DeclarationVisitor/visit) */
    corto_claim(root_o);
    _VisitorData data = {0};
    data._this = _this;
    data.currentScope = root_o;
    data.currentType = NULL;
    data.currentObject = NULL;
    return parser_BaseVisitor_visitProgramNode(
        _this, parser_BaseVisitor(_this)->parser->programReturn, (corto_word)&data
    );
/* $end */
}

/* $header(corto/parser/DeclarationVisitor/visitFullCommaExpressionElementNode) */

/*
 * returns: the expression node with the value
 */
/* $end */
corto_object _parser_DeclarationVisitor_visitFullCommaExpressionElementNode_v(
    parser_DeclarationVisitor _this,
    parser_FullCommaExpressionElementNode node,
    corto_word data)
{
/* $begin(corto/parser/DeclarationVisitor/visitFullCommaExpressionElementNode) */
    parser_BaseVisitor_visitExpressionNode(_this, node->value, 0);
    return node->value;
/* $end */
}

corto_object _parser_DeclarationVisitor_visitInitializerTypeExpressionNode_v(
    parser_DeclarationVisitor _this,
    parser_InitializerTypeExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/DeclarationVisitor/visitInitializerTypeExpressionNode) */
    return NULL;
/* $end */
}

corto_object _parser_DeclarationVisitor_visitObjectDeclarationNameNode_v(
    parser_DeclarationVisitor _this,
    parser_ObjectDeclarationNameNode node,
    corto_word data)
{
/* $begin(corto/parser/DeclarationVisitor/visitObjectDeclarationNameNode) */
    _VisitorData* _data = (_VisitorData*)data;
    corto_declareChild(
        _data->currentScope,
        node->name,
        _data->currentType
    );
    return NULL;
/* $end */
}

/* $header(corto/parser/DeclarationVisitor/visitObjectDeclarationNode) */
static int _declareObjectsFromList(void* o, void* data) {
    parser_ObjectDeclarationNameNode node = parser_ObjectDeclarationNameNode(o);
    _VisitorData* _data = (_VisitorData*)data;
    corto_object newObject = corto_declareChild(
        _data->currentScope,
        node->name,
        _data->currentType
    );
    if (!newObject) {
        // TODO add parser errors
        corto_error("cannot declare %s", node->name);
        goto error;
    }
    corto_assert(newObject != NULL);
    corto_assert(corto_checkState(newObject, CORTO_DECLARED));
    corto_assert(!corto_checkState(newObject, CORTO_DEFINED));
    corto_setref(&node->o, newObject);
error:
    return -1;
}

struct _applyInitializerValueToPrimitiveData
{
    parser_ExpressionNode expr;
    corto_type type;
};
static int _applyInitializerValueToPrimitive(parser_ObjectDeclarationNameNode node, _applyInitializerValueToPrimitiveData* data)
{
    corto_assert(node && node->o);
    corto_assert(data->expr && data->expr->type_ && data->type);
    void* value = (void*)parser_ExpressionNode_getValue(data->expr);
    corto_convert(data->expr->type_, value, data->type, node->o);
    return -1;
}
static int _runInitializerOnDeclareObjects_primitive(parser_DeclarationVisitor _this, corto_ll objectDeclarationNameNodes, corto_ll elements, corto_type type)
{
    parser_FullCommaExpressionElementNode valueNode = NULL;
    _applyInitializerValueToPrimitiveData data = {0};
    if (corto_llSize(elements) > 1) {
        corto_error("cannot initializer with more than one value");
        goto error;
    }
    valueNode = parser_FullCommaExpressionElementNode(
        corto_llGet(elements, 0)
    );
    data = {valueNode->value, type};
    corto_llWalk(objectDeclarationNameNodes, (corto_walkAction)_applyInitializerValueToPrimitive, &data);
error:
    return -1;
}
struct _FindMembersData
{
    parser_DeclarationVisitor _this;
    corto_ll members;
    corto_int32 memberPosition;
    corto_type type;
};
static int _findMembers(void* o, void* _data)
{
    parser_FullCommaExpressionElementNode node = parser_FullCommaExpressionElementNode(o);
    _FindMembersData* data = (_FindMembersData*)_data;
    parser_DeclarationVisitor _this = data->_this;
    CORTO_UNUSED(_this);
    corto_ll members = data->members;

    struct corto_serializer_s serializer = _findMemberSerializer(FALSE);
    _FindMemberData findMemberData = {0};
    if (node->key) {
        // TODO set look for name
    } else {
        findMemberData.lookForLocation = data->memberPosition;
    }
    corto_metaWalk(&serializer, data->type, (void*)&findMemberData);
    // Put the member in the list, 'steal' the reference ownership from findMemberData
    corto_llAppend(members, findMemberData.m);

    data->memberPosition++;
    return -1;
}

struct _setArgumentsToObjectData
{
    parser_DeclarationVisitor _this;
    corto_ll members;
    corto_ll elements;
};
static int _setArgumentsToObject(void* _node, void* _data)
{
    parser_ObjectDeclarationNameNode node = parser_ObjectDeclarationNameNode(_node);
    _setArgumentsToObjectData* data = (_setArgumentsToObjectData*)_data;
    corto_assert(node != NULL);
    corto_assert(data->_this != NULL);
    corto_assert(data->members != NULL);
    corto_object o = node->o;
    if (!o) {
        goto next;
    }

    {
        corto_iter iMembers = corto_llIter(data->members);
        corto_iter iElements = corto_llIter(data->elements);
        while (corto_iterHasNext(&iMembers)) {
            corto_assert(corto_iterHasNext(&iMembers) == corto_iterHasNext(&iElements));
            corto_member member = corto_member(corto_iterNext(&iMembers));
            parser_FullCommaExpressionElementNode element = parser_FullCommaExpressionElementNode(
                corto_iterNext(&iElements)
            );
            // TODO handle non-primitive values
            void* target = CORTO_OFFSET(o, member->offset);
            corto_convert(
                element->value->type_,
                (void*)parser_ExpressionNode_getValue(element->value),
                member->type,
                target
            );
        }
    }

next:
    return -1;
}

static int _runInitializerOnDeclareObjects_composite(
    parser_DeclarationVisitor _this,
    corto_ll objectDeclarationNameNodes,
    corto_ll elements,
    corto_type type)
{
    corto_ll members = corto_llNew();

    _FindMembersData findMembersData = {0};
    findMembersData._this = _this;
    findMembersData.members = members;
    findMembersData.memberPosition = 0;
    findMembersData.type = type;

    corto_llWalk(elements, _findMembers, &findMembersData);
    corto_assert(corto_llSize(members) == corto_llSize(elements));

    _setArgumentsToObjectData setArgumentsToObjectData = {0};
    setArgumentsToObjectData._this = _this;
    setArgumentsToObjectData.members = members;
    setArgumentsToObjectData.elements = elements;
    corto_llWalk(objectDeclarationNameNodes, _setArgumentsToObject, (void*)&setArgumentsToObjectData);

    {
        corto_iter i = corto_llIter(members);
        while (corto_iterHasNext(&i)) {
            corto_release(corto_iterNext(&i));
        }
    }
    corto_llClear(members);
    return 0;
}

static int _runInitializerOnDeclareObject_perKind(
    parser_DeclarationVisitor _this,
    corto_ll objectDeclarationNameNodes,
    corto_ll elements,
    corto_type type)
{
    int r;
    switch (type->kind) {
    case CORTO_PRIMITIVE:
        r = _runInitializerOnDeclareObjects_primitive(_this, objectDeclarationNameNodes, elements, type);
        break;
    case CORTO_COMPOSITE:
        r = _runInitializerOnDeclareObjects_composite(_this, objectDeclarationNameNodes, elements, type);
        break;
    default:
        {
            r = 0;
            corto_string s = NULL;
            corto_convert(corto_typeKind_o, &type->kind, corto_string_o, &s);
            corto_error("unhandled kind: %s", s);
        }
    }
    return r;
}

struct _runInitializerArgumentToObjectData
{
    parser_DeclarationVisitor _this;
    corto_ll objectDeclarationNameNodes;
};
static int _defineObjects(parser_ObjectDeclarationNameNode node, void* data) {
    corto_define(node->o);
    return -1;
}
/* $end */
corto_object _parser_DeclarationVisitor_visitObjectDeclarationNode_v(
    parser_DeclarationVisitor _this,
    parser_ObjectDeclarationNode node,
    corto_word data)
{
/* $begin(corto/parser/DeclarationVisitor/visitObjectDeclarationNode) */
    corto_type type = NULL;
    _VisitorData* _data = (_VisitorData*)data;
    if (node->typeLabel) {
        type = corto_type(
            parser_BaseVisitor_visitBaseTypeExpressionNode(_this, node->typeLabel, data)
        );
        // TODO work types that are anonymous objects
    } else {
        // TODO get default type
    }

    corto_setref(&_data->currentType, type);

    corto_llWalk(node->declarations, _declareObjectsFromList, _data);

    if (node->initializer) {
        parser_BaseVisitor_visitFullCommaExpressionNode(_this, node->initializer, 0);
        _runInitializerOnDeclareObject_perKind(
            _this,
            node->declarations,
            node->initializer->elements,
            _data->currentType
        );
    }
    
    if (node->initializer || node->scope_) {
        corto_llWalk(node->declarations, (corto_walkAction)_defineObjects, NULL);
    }

    corto_setref(&_data->currentType, NULL);

    return NULL;
/* $end */
}

/* $header(corto/parser/DeclarationVisitor/visitSimpleTypeExpressionNode) */
/*
 * returns: corto_type
 */
/* $end */
corto_object _parser_DeclarationVisitor_visitSimpleTypeExpressionNode_v(
    parser_DeclarationVisitor _this,
    parser_SimpleTypeExpressionNode node,
    corto_word data)
{
/* $begin(corto/parser/DeclarationVisitor/visitSimpleTypeExpressionNode) */
    _VisitorData* _data = (_VisitorData*)data;
    corto_object type = corto_resolve(_data->currentScope, node->name);
    if (type) {
        corto_setref(&parser_BaseTypeExpressionNode(node)->type_, type);
        corto_setref(&_data->currentType, type);
        corto_release(type);
    } else {
        // TODO parser error
        corto_error("cannot find type %s", node->name);
    }
    return type;
/* $end */
}
