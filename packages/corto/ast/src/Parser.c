/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>
#include "ast__private.h"
#define ast_CHECK_ERRSET(parser) corto_assert(!parser->errSet, "%s:%d:%d: parser did not check error-status set on line %d (%s:%d)", this->filename, this->line, this->column, this->errLine, __FILE__, __LINE__)
/*#define ast_PARSER_DEBUG*/
#define fast_err ast_Parser_reset(this); this->errSet = TRUE; this->errLine = __LINE__;
extern corto_tls ast_PARSER_KEY;
void ast_Parser_error(ast_Parser this, char* fmt, ... ) {
    va_list args;
    char *err = NULL;
    corto_id token;
    int line = this->line;

    if (this->token) {
        if (*this->token == '\n') {
            sprintf(token, "end of line");
            line--;
        } else {
            sprintf(token, "'%s'", this->token);
        }

    } else {
        *token = '\0';
    }

    va_start(args, fmt);
    err = corto_vasprintf(fmt, args);
    va_end(args);
    ast_reportError(this->filename, this->column ? line : line - 1, this->column, err, token);
    corto_dealloc(err);
    this->errors++;
}

void ast_Parser_warning(ast_Parser this, char* fmt, ... ) {
    va_list args;
    char msgbuff[1024];
    corto_id token;
    int line = this->line;

    if (this->token) {
        if (*this->token == '\n') {
            sprintf(token, "end of line");
            line--;
        } else {
            sprintf(token, "'%s'", this->token);
        }

    } else {
        *token = '\0';
    }

    va_start(args, fmt);
    vsprintf(msgbuff, fmt, args);
    va_end(args);
    ast_reportWarning(this->filename, line, this->column, msgbuff, token);
    this->warnings++;
}

/* Generate user-friendly id's for both scoped and unscoped objects */
corto_string ast_Parser_id(corto_object o, corto_id buffer) {
    if (!o) {
        sprintf(buffer, "null");
    } else if (corto_check_attr(o, CORTO_ATTR_NAMED)) {
        if (corto_parentof(o) == corto_lang_o) {
            strcpy(buffer, corto_idof(o));
        } else {
            corto_fullpath(buffer, o);
        }

    } else {
        corto_id tmp;
        corto_string_ser_t serData;
        corto_walk_opt s;
        serData.buffer = CORTO_BUFFER_INIT;
        serData.buffer.buf = tmp;
        serData.buffer.max = sizeof(corto_id)-strlen("<anonymous>");
        serData.compactNotation=TRUE;
        serData.prefixType = TRUE;
        serData.enableColors = FALSE;
        s = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_WALK_TRACE_NEVER);
        corto_walk(&s, o, &serData);
        strcpy(buffer, tmp);
    }

    return buffer;
}

/* Translate result of parser to corto intermediate bytecode */
corto_int16 ast_Parser_toIc(ast_Parser this, corto_stringSeq argv) {
    ic_program program = ic_program__create(NULL, NULL, this->filename);
    corto_int16 ret = 0;

    /* Parse root-block */
    ast_Block_toIc(this->block, program, NULL, FALSE);
    if (this->errors) {
        goto error;
    }

    /* Bind function implementations to function objects */
    if (ast_Parser_finalize(this, program)) {
        goto error;
    }

    /* Print program */
#ifdef IC_TRACING
    extern corto_bool CORTO_DEBUG_ENABLED;
    if (CORTO_DEBUG_ENABLED) {
        corto_string programStr = ic_program_toString(program);
        corto_trace("%s", programStr);
        corto_dealloc(programStr);
    }

#endif
    ic_program_assemble(program);
    ret = ic_program_run(program, 0, argv);
    corto_tls_set(ast_PARSER_KEY, this);
    if (ret) {
        corto_raise();
        ast_Parser_error(this, "");
        goto error;
    }

    /* Free program */
    corto_release(program);
    return 0;
error:
    corto_release(program);
    return -1;
}

/* Use corto_object as returntype as the actual type (ast_Expression) causes macro-expansion */
typedef corto_object ___ (*ast_ExpandAction)(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData);
/* Combine results in new comma expression */
corto_object ast_Parser_combineComma(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    CORTO_UNUSED(this);
    CORTO_UNUSED(userData);
    return ast_Comma_addOrCreate(lvalue, rvalue);
}

/* Combine results as part of conditional expression */
corto_object ast_Parser_combineConditionalExpr(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    corto_operatorKind oper = *(corto_operatorKind*)userData;
    corto_operatorKind combineOper;
    ast_Expression result;

    /* Default combine is AND, except the != operator, which inserts an OR */
    if (lvalue) {
        if (oper == CORTO_COND_NEQ) {
            combineOper = CORTO_COND_OR;
        } else {
            combineOper = CORTO_COND_AND;
        }

        result = ast_Expression(ast_Binary__create(NULL, NULL, lvalue, rvalue, combineOper));
        ast_Parser_collect(this, result);
        /* Fold expression where possible */
        result = ast_Expression_fold(result);
        if (!result) {
            goto error;
        }

    } else {
        result = rvalue;
    }

    return result;
error:
    return NULL;
}

/* Create binary expression with ternary operand */
ast_Expression ast_Parser_createBinaryTernary(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, corto_operatorKind operator) {
    ast_Expression result = NULL;
    CORTO_UNUSED(this);

    /* If the operation is an assignment, the ternary operator has already constructed the binary operation through an lvalue - see
     * the implementation of ast_Parser_Ternary. If the operation is not an assignment, create the binary expression. */
    switch(operator) {
    case CORTO_ASSIGN:
    case CORTO_ASSIGN_ADD:
    case CORTO_ASSIGN_SUB:
    case CORTO_ASSIGN_MUL:
    case CORTO_ASSIGN_DIV:
    case CORTO_ASSIGN_MOD:
    case CORTO_ASSIGN_OR:
    case CORTO_ASSIGN_AND:
        ast_Ternary_setOperator(ast_Ternary(rvalue), operator);
        corto_set_ref(&result, rvalue);
        break;
    default:
        result = ast_Expression(ast_Binary__create(NULL, NULL, lvalue, rvalue, operator));
        ast_Parser_collect(this, result);
        break;
    }

    return result;
}

/* Match parameter */
corto_bool ast_Parser_matchDelegateParameter(
    ast_Parser this,
    corto_string name,
    corto_type t1,
    corto_bool isRef1,
    corto_type t2,
    corto_bool isRef2) {

    if ((t1 != t2) || (isRef1 && !isRef2)) {
        corto_id id1, id3, id4;

        ast_Parser_error(this, "%s %s '%s%s' of procedure doesn't match '%s%s' of delegate '%s'",
            name ? "parameter" : "",
            name ? name : "returntype",
            ast_Parser_id(t1, id1),
            isRef1 ? "&" : "",
            ast_Parser_id(t2, id3),
            isRef2 ? "&" : "",
            ast_Parser_id(t2, id4));
        goto error;
    }

    return TRUE;
error:
    return FALSE;
}

/* Create and validate delegate assignment */
ast_Expression ast_Parser_delegateAssignment(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue) {
    corto_uint32 i;
    ast_Expression instance = NULL;
    ast_Expression functionExpr = NULL;
    corto_id functionName;
    ast_InitializerExpression result = NULL;
    corto_string signature = NULL;
    corto_delegate type = NULL;
    ast_InitializerVariableArray64 variables;
    ast_CallBuilder builder;
    ast_Call tempCall = NULL;

    memset(variables, 0, sizeof(variables));

    /* Validate whether rvalue is an object */
    if ((ast_Node(rvalue)->kind == Ast_StorageExpr) && (ast_Storage(rvalue)->kind == Ast_ObjectStorage)) {
        corto_sig_name(corto_idof(ast_Object(rvalue)->value), functionName);
    } else if ((ast_Node(rvalue)->kind == Ast_StorageExpr) && (ast_Storage(rvalue)->kind == Ast_MemberStorage)) {
        instance = ast_Member(rvalue)->lvalue;
        strcpy(functionName, ast_String(ast_Member(rvalue)->rvalue)->value);
    } else {
        ast_Parser_error(this, "dynamic delegate assignments are not yet supported");
        goto error;
    }

    type = corto_delegate(ast_Expression_getType(lvalue));
    /* Build request-signature */
    signature = corto_sig_open(functionName);
    for (i = 0; i < type->parameters.length; i++) {
        corto_parameter *p = &type->parameters.buffer[i];
        signature = corto_sig_add(signature, p->type, p->passByReference ? CORTO_PARAMETER_FORCEREFERENCE : 0);
    }

    signature = corto_sig_close(signature);
    /* Resolve function */
    corto_ptr_init(&builder, ast_CallBuilder_o);
    ast_CallBuilder__assign(
        &builder,
        signature,
        NULL,
        instance,
        this->scope,
        yparser()->block);
    tempCall = ast_CallBuilder_build(&builder);
    corto_ptr_deinit(&builder, ast_CallBuilder_o);
    if (!tempCall) {
        goto error;
    }

    /* Call::resolveActual will resolve a method that matches the signature of the delegate. However,
     * the overloading algorithm takes into account type compatibility: a uint32 request will match a
     * uint64 parameter. This algorithm assumes that the actual call will do an implicit conversion.
     * Delegates simply pass-through parameters and cannot perform this implicit casting. Therefore their
     * signatures have to match the parameter-types exactly. The only exception to this rule is inheritance.
     */
    /* Validate returntype */
    if (!ast_Parser_matchDelegateParameter(
        this,
        NULL,
        type->returnType,
        type->returnsReference,
        tempCall->returnType,
        tempCall->returnsReference)) {
        goto error;
    }

    /* Validate number of parameters */
    if (type->parameters.length != tempCall->parameters.length) {
        ast_Parser_error(this, "number of procedure parameters(%d) doesn't match delegate (%d)",
            tempCall->parameters.length,
            type->parameters.length);
        goto error;
    }

    /* Validate parameters */
    for (i=0; i<type->parameters.length; i++) {
        corto_parameter *p1, *p2;
        p1 = &type->parameters.buffer[i];
        p2 = &tempCall->parameters.buffer[i];
        if (!ast_Parser_matchDelegateParameter(
            this,
            p1->name,
            p1->type,
            p1->passByReference,
            p2->type,
            p2->passByReference)) {
            goto error;
        }

    }

    functionExpr = tempCall->functionExpr;
    /* If procedure is compatible with delegate type, do a complex assignment */
    corto_set_ref(&variables[0].object, lvalue);
    result = ast_InitializerExpression__create(NULL, NULL, variables, 1, TRUE);
    ast_InitializerExpression_push(result);
    if (instance) {
        ast_InitializerExpression_member(result, "instance");
        ast_InitializerExpression_value(result, instance);
    }

    ast_InitializerExpression_member(result, "procedure");
    ast_InitializerExpression_value(result, functionExpr);
    ast_InitializerExpression_pop(result);
    ast_InitializerExpression_defineObject(result);
    ast_Parser_collect(this, result);
    corto_dealloc(signature);
    corto_release(tempCall);
    return ast_Expression(result);
error:
    if(signature) {
        corto_dealloc(signature);
    }

    return NULL;
}

/* Callback function for expansion of binary expressions */
corto_object ast_Parser_expandBinary(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    ast_Expression result = NULL;
    corto_type tleft, tright;
    corto_operatorKind operator = *(corto_operatorKind*)userData;

    if (!(tleft = ast_Expression_getType_expr(lvalue, rvalue))) {
        goto error;
    }

    if (!(tright = ast_Expression_getType_expr(rvalue, lvalue))) {
        goto error;
    }

    if (tleft && (tleft->kind == CORTO_COMPOSITE) && (corto_interface(tleft)->kind == CORTO_DELEGATE)) {
        if (*(corto_operatorKind*)userData == CORTO_ASSIGN) {
            rvalue = ast_Parser_delegateAssignment(this, lvalue, rvalue);
            if(!rvalue) {
                goto error;
            }

        } else {
            ast_Parser_error(this, "operators other than assign not valid for delegates");
            goto error;
        }

    }

    /* The way in which following kinds of binary expressions are evaluated is important:
     *  - Ternary expressions takes precedence over anything since they introduce additional binary expressions
     *    which in turn will be determined to be either primitive, composite or collection expressions.
     *  - A binary expression is only composite when both operands are of a composite type. Both of these
     *    types have to be compatible. This is partially to avoid amibiguity with collection expressions
     *    (collections with composite element types) and partially because there are no useful semantics
     *    (defined) for combining both composite and <insert other type> in one expression.
     *  - A binary expression is a collection expression when one of the operands is a collection. Whether
     *    the operation is valid or not is further determined by the binaryCollectionExpr function.
     *  - Remaining types (basically references and primitive types) are handled by a regular binary
     *    expression.
     */
    /* Ternary expression */
    if (ast_Node(rvalue)->kind == Ast_TernaryExpr) {
        result = ast_Parser_createBinaryTernary(this, lvalue, rvalue, operator);
    /* Binary expression with iterator value on the left-hand side */
    } else if (tleft && tleft->kind == CORTO_ITERATOR) {
        result = ast_Expression(ast_Binary__create(NULL, NULL, lvalue, rvalue, operator));
    /* Binary expression with primitive or reference values */
    } else {
        result = ast_Expression(ast_Binary__create(NULL, NULL, lvalue, rvalue, operator));
        /* Fold expression */
        if (result) {
            result = ast_Expression_fold(result);
            if (!result) {
                goto error;
            }

        }

    }

    if (!result) {
        goto error;
    }

    return result;
error:
    return NULL;
}

/* Callback function for expansion of element expressions */
corto_object ast_Parser_expandMember(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    CORTO_UNUSED(userData);
    CORTO_UNUSED(this);
    ast_Expression result = NULL;

    /* Create member expression */
    result = ast_Expression(ast_Member__create(NULL, NULL, lvalue, rvalue));
    if (!result) {
        goto error;
    }

    return result;
error:
    return NULL;
}

/* Callback function for expansion of element expressions */
corto_object ast_Parser_expandElement(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    CORTO_UNUSED(this);
    CORTO_UNUSED(userData);
    ast_Expression result = (ast_Expression)ast_Element__create(NULL, NULL, lvalue, rvalue);
    if (!result) {
        goto error;
    }

    return result;
error:
    return NULL;
}

/* Generic function to "explode" comma-expressions. This results in (ln * rn) expressions */
ast_Expression ast_Parser_explodeComma(ast_Parser this, ast_Expression lvalues, ast_Expression rvalues, ast_ExpandAction action, void *userData) {
    corto_ll lvalueList, rvalueList;
    ast_Expression result = NULL;
    ast_Expression var = NULL;
    corto_uint32 lvalueCount, rvalueCount;

    lvalueList = ast_Expression_toList(lvalues);
    rvalueList = ast_Expression_toList(rvalues);
    lvalueCount = corto_ll_count(lvalueList);
    rvalueCount = corto_ll_count(rvalueList);

    if ((rvalueCount > 1) && (lvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (ast_Expression_hasSideEffects(ast_Expression(corto_ll_get(lvalueList,0)))) {
            if (ast_Node(rvalues)->kind != Ast_InitializerExpr) {
                var = ast_Expression(ast_Temporary__create(NULL, NULL, lvalues->type, lvalues->isReference));
                ast_Parser_addStatement(this, ast_Parser_binaryExpr(this, var, lvalues, CORTO_ASSIGN));
                rvalues = var;
            }

        }

    }

    corto_iter itL = corto_ll_iter(lvalueList);
    while (corto_iter_hasNext(&itL)) {
        ast_Expression l = corto_iter_next(&itL);
        corto_iter itR = corto_ll_iter(rvalueList);
        while (corto_iter_hasNext(&itR)) {
            ast_Expression r = corto_iter_next(&itR);
            ast_Expression e = action(this, var ? var : l, r, userData);
            if (!e) {
                goto error;
            }

            ast_Parser_collect(this, e);
            result = ast_Comma_addOrCreate(result, e);
        }

    }

    /* Clean-up list */
    ast_Expression_cleanList(lvalueList);
    ast_Expression_cleanList(rvalueList);
    return result;
error:
    return NULL;
}

/* Generic function to expand comma-expressions */
ast_Expression ast_Parser_expandComma(ast_Parser this, ast_Expression lvalues, ast_Expression rvalues, ast_ExpandAction action, ast_ExpandAction combine, void *userData) {
    corto_int16 lvalueCount, rvalueCount;
    corto_ll lvalueList, rvalueList;
    corto_iter lIter, rIter;
    corto_type tleft, tright;
    ast_Expression result = NULL, localResult = NULL;
    enum {
        EXPAND_LEFT,
        EXPAND_RIGHT,
        EXPAND_BOTH
    } expandMode = EXPAND_LEFT; /* Expand left, right or both */
    lvalueList = ast_Expression_toList(lvalues);
    rvalueList = ast_Expression_toList(rvalues);
    lvalueCount = corto_ll_count(lvalueList);
    rvalueCount = corto_ll_count(rvalueList);
    /* If there is more than one lvalue assign rvalue to temporary value first. This will assure that rvalue is evaluated
     * only once. */
    if ((lvalueCount > 1) && (rvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (ast_Expression_hasSideEffects(ast_Expression(corto_ll_get(rvalueList,0)))) {
            if (ast_Node(rvalues)->kind != Ast_InitializerExpr) {
                ast_Expression var = ast_Expression(ast_Temporary__create(NULL, NULL, rvalues->type, FALSE));
                ast_Parser_addStatement(this, ast_Parser_binaryExpr(this, var, rvalues, CORTO_ASSIGN));
                rvalues = var;
            }

        }

        expandMode = EXPAND_LEFT;
    } else if ((rvalueCount > 1) && (lvalueCount == 1)) {
        expandMode = EXPAND_RIGHT;
    } else if (lvalueCount == rvalueCount) {
        expandMode = EXPAND_BOTH;
    } else {
        ast_Parser_error(this, "mismatch in expression count of binary operation (left = %d, right = %d)",
                          corto_ll_count(lvalueList), corto_ll_count(rvalueList));
        goto error;
    }

    /* Loop through lvalues */
    lIter = corto_ll_iter(lvalueList);
    rIter = corto_ll_iter(rvalueList);
    ast_Expression lvalue = lvalues;
    while((((expandMode == EXPAND_LEFT)||(expandMode == EXPAND_BOTH)) && corto_iter_hasNext(&lIter)) || ((expandMode == EXPAND_RIGHT) && corto_iter_hasNext(&rIter))) {
        /* If rvalueList is greater than 1, loop through rvalues as well */
        switch(expandMode) {
            case EXPAND_BOTH:
                rvalues = corto_iter_next(&rIter);
            case EXPAND_LEFT:
                lvalue = corto_iter_next(&lIter);
                break;
            case EXPAND_RIGHT:
                rvalues = corto_iter_next(&rIter);
                break;
        }

        /* Instantiate lvalue and rvalue into action-specific object */
        localResult = action(this, lvalue, rvalues, userData);
        if (!localResult) {
            goto error;
        }

        if (!(tleft = ast_Expression_getType_expr(lvalue,rvalues))) {
            goto error;
        }

        if (!(tright = ast_Expression_getType_expr(rvalues,lvalue))) {
            goto error;
        }

        if (localResult) {
            localResult = ast_Expression_fold(localResult);
            if (!localResult) {
                goto error;
            }

        }

        result = combine(this, result, localResult, userData);
    }

    /* Clean-up list */
    ast_Expression_cleanList(lvalueList);
    ast_Expression_cleanList(rvalueList);
    lvalueList = NULL;
    rvalueList = NULL;
    return result;
error:
    return NULL;
}

ast_Expression ast_Parser_resolve(ast_Parser this, const char *id) {
    ast_Expression result = NULL;
    corto_object object = NULL;

    corto_object rvalueType = ast_Parser_getLvalueType(this, FALSE);
    if (rvalueType && corto_check_attr(rvalueType, CORTO_ATTR_NAMED)) {
        object = corto_lookup(rvalueType, id);
    }

    if (!object) {
        object = corto_resolve(this->scope, id);
    }

    corto_iter it = corto_ll_iter(this->imports);
    while (!object && corto_iter_hasNext(&it)) {
        object = corto_lookup(corto_iter_next(&it), id);
    }

    if (object) {
        result = ast_Expression(ast_Object__create(NULL, NULL, object));
        corto_set_str(&ast_Object(result)->originalId, id);
        ast_Parser_collect(this, result);
        corto_release(object);
    } else {
        result = ast_Expression(
            ast_UnresolvedReference__create(NULL, NULL,
                id,
                this->scope,
                this->line,
                this->column));
        ast_Parser_collect(this, result);
    }

    return result;
}

/* Create an observer */
static
ast_Storage ast_Parser_observerCreate(
    ast_Parser this,
    const char *id,
    ast_Expression object,
    corto_eventMask mask,
    ast_Object dispatcherVar)
{
    ast_Storage result = NULL;
    corto_observer observer;
    corto_object observable = NULL;
    corto_object parent;
    corto_object dispatcher = NULL;

    /* If object is zero, this indicates either a template local or an expression during the 1st pass. TODO: how to handle
     * declaring expressions in the 1st pass - possible solution is setting the expression in the 2nd pass but then how can
     * the observer be identified?
     */

    parent = this->scope;
    if (!corto_class_instanceof(corto_type_o, parent)) {
        parent = NULL;
    }

    if (dispatcherVar) {
        dispatcher = ast_Object(dispatcherVar)->value;
    }

    if (object && (ast_Node(object)->kind == Ast_StorageExpr)) {
        switch(ast_Storage(object)->kind) {
        case Ast_ObjectStorage:
            observable = ast_Object(object)->value;
            break;
        case Ast_TemplateStorage:
            /* In case of template ('this') leave observable zero */
            break;
        default:
            break;
        }

    }

    /* If VALUE is not selected, set METAVALUE bit so VALUE won't be added
     * automatically. */
    if (!(mask & CORTO_ON_VALUE)) {
        mask |= CORTO_ON_METAVALUE;
    }

    /* Create observer */
    if (!id) {
        observer = corto_declare(NULL, NULL, corto_observer_o);
        if (!observer) {
            goto error;
        }

        /* Set values of observer - but don't yet define it. It will be defined when
         * the observer is bound to the implementation */
        corto_set_ref(&observer->observable, observable);
        observer->mask = mask;
        corto_set_ref(&observer->dispatcher, dispatcher);
    } else {
        observer = corto_observer__create(
            this->scope, id, mask, observable, NULL, dispatcher, NULL, FALSE, NULL);
        if (!observer){
            goto error;
        }

    }

    /* Create and collect result */
    result = (ast_Storage)ast_Object__create(NULL, NULL, observer);
    ast_Parser_collect(this, result);
    return result;
error:
    fast_err;
    return NULL;
}

/* Declare a delegate type */
static
ast_Storage ast_Parser_declareDelegate(
    ast_Parser this,
    corto_type returnType,
    const char *id,
    corto_bool returnsReference)
{
    corto_delegate delegate;
    corto_parameterseq parameters;
    corto_id name;

    /* Translate from name to arguments */
    parameters = corto_function_stringToParameterSeq(id, this->scope);

    /* Obtain name */
    corto_sig_name(id, name);

    /* Declare and define delegate */
    delegate = corto_declare(this->scope, name, corto_delegate_o);
    if(!delegate) {
        goto error;
    }

    corto_delegate__assign(delegate, corto_type(returnType), returnsReference, parameters);

    if(corto_define(delegate)) {
        goto error;
    }

    return ast_Storage(ast_Object__create(NULL, NULL, delegate));
error:
    return NULL;
}

/* Parse single line internally */
ast_Expression ast_Parser_parseIntern(ast_Parser parser, corto_object scope, corto_int32 *err) {
    ast_Expression result = NULL; /* Resulting ast-expression of 'exr' */

    /* Ensure that corto scripts are parsed with default attributes */
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_DEFAULT);

    if (err) *err = 0;
    parser->pass = 0;

    corto_set_ref(&parser->scope, scope);
    if ( fast_yparse(parser, 1, 1)) {
        goto error;
    }

    if (parser->errors) {
        goto error;
    }

    /* Reset parser-state so 2nd pass starts clean */
    ast_Parser_reset(parser);
    parser->pass = 1;
    corto_set_ref(&parser->scope, scope);
    if (fast_yparse(parser, 1, 1)) {
        goto error;
    }

    /* Find last executed expression */
    if (parser->block) {
        if (corto_ll_count(parser->block->statements)) {
            ast_Node lastNode = corto_ll_last(parser->block->statements);
            /* If node is an expression, store expression in variable so it can be resolved later */
            if (corto_instanceof(corto_type(ast_Expression_o), lastNode) && (lastNode->kind != Ast_CommaExpr)) {
                result = ast_Expression(lastNode);
            }

        }

    }

    corto_set_attr(prevAttr);
    return result;
error:
    corto_set_attr(prevAttr);
    if (err) *err = -1;
    return NULL;
}

void ast_Parser_addStatement(
    ast_Parser this,
    ast_Node statement)
{
    ast_CHECK_ERRSET(this);

    if (statement && corto_instanceof(ast_Expression_o, statement)) {
        statement = ast_Node(ast_Expression_fold(statement));
    }

    /* If a comma expression is encountered in the second pass it could be the result of an expanded
     * comma expression. Only add if the expression has side effects. If it doesn't have side effects
     * it is likely the result of a staged declaration */
    if (statement && (statement->kind == Ast_CommaExpr)) {
        if (this->pass) {
            if (!ast_Expression_hasSideEffects(ast_Expression(statement))) {
                return;
            }

        } else {
            if (safe_ast_Parser_initDeclare(this, statement)) {
                goto error;
            }

            /* Don't add the Comma expression to the AST */
            return;
        }

    }

    /* If statement is an unresolved identifier by itself, it represents a
     * declaration with the default type of a scope */
    if (statement &&
       (statement->kind == Ast_StorageExpr) &&
       (ast_Storage(statement)->kind == Ast_UnresolvedReferenceStorage))
    {
        if (!this->pass && !this->repl) {
            if (safe_ast_Parser_initDeclare(this, statement)) {
                /* This will eventually trigger an unresolved reference error */
                ast_Block_addStatement(this->block, statement);
            }

            /* Don't add node to AST */
            return;
        } else {
            /* Don't add node to AST */
            return;
        }

    }

    if (statement) {
        if (this->block && (ast_Node(this->block->_while) != statement)) {
            if (this->block->_while) {
                ast_Parser_error(this, "invalid statement after while");
                goto error;
            }

            if (!((statement->kind == Ast_LiteralExpr) && (ast_Literal(statement)->kind == Ast_Text))) {
                ast_Block_addStatement(this->block, statement);
                if (corto_instanceof(corto_type(ast_Expression_o), statement)) {
                    if (!ast_Expression_hasSideEffects(ast_Expression(statement))) {
                        /* TODO: ast_Parser_warning(this, "computed value is not used (%s)", corto_idof(corto_typeof(statement))); */
                    }

                }

            } else if (this->pass) {
                /* If statement is a string, insert println function */
                if (!this->repl) {
                    ast_Expression println = ast_Parser_lookup(this, "io::println(string)");
                    ast_Comma args = ast_Comma__create(NULL, NULL);
                    ast_Comma_addExpression(args, ast_Expression(statement));
                    ast_Expression callExpr = ast_Parser_callExpr(this, println, ast_Expression(args));
                    ast_Block_addStatement(this->block, ast_Node(callExpr));
                    ast_Parser_collect(this, args);
                } else {
                    ast_Block_addStatement(this->block, statement);
                }

            }

        }

    }

    return;
error:
    fast_err;
}

corto_string ast_Parser_argumentToString(
    ast_Parser this,
    corto_type type,
    const char *id,
    bool reference)
{
    corto_string str;
    corto_string result;
    ast_CHECK_ERRSET(this);

    if (!corto_class_instanceof(corto_type_o, type)) {
        corto_id id;
        ast_Parser_error(this, "object '%s' used in parameter expression is not a type", ast_Parser_id(type, id));
        goto error;
    }

    if (corto_check_attr(type, CORTO_ATTR_NAMED)) {
        corto_id id;
        if ((corto_parentof(type) == corto_o) || (corto_parentof(type) == corto_lang_o)) {
            str = strdup(corto_idof(type));
        } else {
            str = strdup(ast_Parser_id(type, id));
        }

    } else {
        corto_walk_opt s;
        corto_string_ser_t walkData;
        memset(&walkData, 0, sizeof(walkData));
        s = corto_string_ser(CORTO_LOCAL|CORTO_READONLY|CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_NEVER);
        walkData.buffer = CORTO_BUFFER_INIT;
        walkData.compactNotation = TRUE;
        walkData.prefixType = TRUE;
        if (corto_walk(&s, type, &walkData)) {
            goto error;
        }

        str = corto_buffer_str(&walkData.buffer);
        if (!str) {
            corto_throw("failed to serialize anonymous type to string");
            goto error;
        }

    }

    result = corto_alloc(strlen(str) + 1 + strlen(id) + 1 + 1);
    if (reference) {
        sprintf(result, "%s& %s", str, id);
    } else {
        sprintf(result, "%s %s", str, id);
    }

    corto_dealloc(str);
    return result;
error:
    fast_err;
    return NULL;
}

ast_Node ast_Parser_binaryExpr(
    ast_Parser this,
    ast_Expression lvalues,
    ast_Expression rvalues,
    corto_operatorKind _operator)
{
    ast_Node result = NULL;
    ast_CHECK_ERRSET(this);

    if (lvalues && rvalues && (this->pass || ((this->initializerCount >= 0) &&
        this->initializers[this->initializerCount])))
    {
        ast_ExpandAction combine = ast_Parser_combineComma;

        switch(_operator) {
        case CORTO_ASSIGN_UPDATE: {
            corto_ll exprList = ast_Expression_toList(lvalues);

            /* Begin update (lock objects) */
            result = ast_Node(ast_Update__create(NULL, NULL, exprList, NULL, NULL, Ast_UpdateBegin));
            if (!result) {
                goto error;
            }

            ast_Parser_addStatement(this, ast_Node(result));
            ast_Parser_collect(this, result);
            /* Insert assignment */
            if (!(result = ast_Parser_binaryExpr(this, lvalues, rvalues, CORTO_ASSIGN))) {
                goto error;
            }

            ast_Parser_addStatement(this, ast_Node(result));
            /* End expression (update in reverse order) */
            result = ast_Node(ast_Update__create(NULL, NULL, exprList, NULL, NULL, Ast_UpdateEnd));
            if (!result) {
                goto error;
            }

            break;
        }

        case CORTO_COND_EQ:
        case CORTO_COND_NEQ:
        case CORTO_COND_AND:
        case CORTO_COND_OR:
        case CORTO_COND_GT:
        case CORTO_COND_LT:
        case CORTO_COND_GTEQ:
        case CORTO_COND_LTEQ:
            combine = ast_Parser_combineConditionalExpr;
        /* fallthrough */
        default:
            if (!(result = ast_Node(
                ast_Parser_expandComma(this, lvalues, rvalues, ast_Parser_expandBinary, combine, &_operator)))) {
                goto error;
            }

            break;
        }

    }

    return result;
error:
    fast_err;
    return NULL;
}

int16_t ast_Parser_bind(
    ast_Parser this,
    ast_Storage function,
    ast_Block block)
{
    ast_Binding *binding;
    ast_CHECK_ERRSET(this);

    if (this->pass && function) {
        if (function->kind == Ast_ObjectStorage) {
            binding = corto_calloc(sizeof(ast_Binding));
            corto_set_ref(&binding->function, ast_Object(function)->value);
            corto_set_ref(&binding->impl, block);
            corto_assert(this->bindings != NULL, "initialization failed");
            corto_ll_append(this->bindings, binding);
        }

    }

    return 0;
}

int16_t ast_Parser_bindOneliner(
    ast_Parser this,
    ast_Storage function,
    ast_Block block,
    ast_Expression expr)
{
    ast_CHECK_ERRSET(this);

    if (this->pass) {
        ast_Expression returnLocal;
        corto_id functionName;

        /* Add oneliner to block */
        corto_sig_name(corto_idof(ast_Object(function)->value), functionName);
        returnLocal = ast_Block_lookup(block, functionName);
         if (returnLocal) {
            ast_Expression returnAssign;

            /* In one-liners, a reference returnvalue is always addressed by reference */
            if (!ast_Expression(returnLocal)->type->reference && ast_Expression(returnLocal)->isReference) {
                returnLocal = ast_Parser_unaryExpr(this, returnLocal, CORTO_AND);
            }

            returnAssign = ast_Expression(ast_Parser_binaryExpr(this, returnLocal, expr, CORTO_ASSIGN));
            if (returnAssign) {
                ast_Block_addStatement(block, ast_Node(returnAssign));
            } else {
                goto error;
            }

        } else {
            ast_Parser_error(this, "invalid assignment to function with no returntype");
            goto error;
        }

        /* Bind function */
        ast_Parser_bind(this, function, block);
    }

    return 0;
error:
    fast_err;
    return -1;
}

void ast_Parser_blockPop(
    ast_Parser this)
{
    ast_CHECK_ERRSET(this);

    this->blockCount--;

    /* Blocks are parsed only in 2nd pass */
    if (this->pass) {
        if (this->block) {
            corto_set_ref(&this->block, this->block->parent);
        } else {
            /* Got confused by earlier errors */
            ast_Parser_error(this, "unable to continue parsing due to previous errors");
            this->abort = TRUE;
        }

    }

    this->blockPreset = FALSE;
}

ast_Block ast_Parser_blockPush(
    ast_Parser this,
    bool presetBlock)
{
    ast_CHECK_ERRSET(this);

    if (!this->blockPreset || presetBlock) {
        this->blockCount++;
    }

    /* Blocks are parsed only in 2nd pass */
    if (this->pass) {
        ast_Block newBlock;
        newBlock = NULL;
        if (!this->blockPreset || presetBlock) {
            newBlock = ast_Block__create(NULL, NULL, this->block);
            ast_Parser_collect(this, newBlock);
            corto_set_ref(&this->block, newBlock);
        }

        this->blockPreset = presetBlock;
        return newBlock;
    } else {
        this->blockPreset = presetBlock;
        return NULL;
    }

}

ast_Expression ast_Parser_callExpr(
    ast_Parser this,
    ast_Expression function,
    ast_Expression arguments)
{
    ast_Expression result = NULL;

    if (function && this->pass) {
        corto_object o = NULL;
        ast_ExpressionList functions = function ? ast_Expression_toList(function) : NULL;
        ast_ExpressionList args = arguments ? ast_Expression_toList(arguments) : NULL;

        if (functions) {
            corto_iter it = corto_ll_iter(functions);
            while (corto_iter_hasNext(&it)) {
                ast_Expression f = corto_iter_next(&it);
                ast_Expression expr;
                if ((ast_Node(f)->kind == Ast_StorageExpr) && (ast_Storage(f)->kind == Ast_ObjectStorage)) {
                    o = ast_Object(f)->value;
                }

                /* If function is a type, insert cast */
                if (o && corto_instanceof(corto_type(corto_type_o), o)) {
                    corto_ll exprs = ast_Expression_toList(arguments);
                    if (corto_ll_count(exprs) != 1) {
                        ast_Parser_error(this, "invalid number of parameters for cast (expected 1)");
                        ast_Expression_cleanList(exprs);
                        goto error;
                    }

                    expr = ast_Parser_castExpr(this, o, corto_ll_get(exprs, 0));
                    ast_Expression_cleanList(exprs);
                    ast_Parser_collect(this, expr);
                } else {
                    expr = ast_Expression(ast_createCallFromExpr(f, arguments));
                }

                if (!expr) {
                    goto error;
                }

                result = ast_Comma_addOrCreate(result, expr);
            }

        }

        /* Cleanup initializer arguments */
        if (args) {
            corto_iter it = corto_ll_iter(args);
            while (corto_iter_hasNext(&it)) {
                ast_Expression a = corto_iter_next(&it);
                if (ast_Node(a)->kind == Ast_InitializerExpr) {
                    ast_Expression var = ast_Initializer(a)->variables[0].object;
                    if (var && (ast_Storage(var)->kind == Ast_TemporaryStorage)) {
                        ast_Deinit deinit = ast_Deinit__create(NULL, NULL, ast_Storage(var));
                        result = ast_Comma_addOrCreate(result, ast_Expression(deinit));
                        ast_Parser_collect(this, deinit);
                    }

                }

            }

        }

        ast_Expression_cleanList(functions);
        ast_Expression_cleanList(args);
    }

    return result;
error:
    fast_err;
    return NULL;
}

ast_Expression ast_Parser_castExpr(
    ast_Parser this,
    corto_type lvalue,
    ast_Expression rvalue)
{
    ast_Expression result = NULL;

    if (this->pass) {
        corto_type rvalueType;
        corto_bool castRequired = TRUE;

        rvalueType = ast_Expression_getType(rvalue);

        if (lvalue == rvalueType) {
            corto_id id;
            ast_Parser_warning(this, "casting to value of the same type (%s)", ast_Parser_id(lvalue, id));
            castRequired = FALSE;
        } else {
            if (rvalueType) {
                if ((lvalue->kind == CORTO_COMPOSITE) && (rvalueType->kind == CORTO_COMPOSITE)) {
                    if (corto_type_castable(lvalue, rvalueType)) {
                        corto_id id1, id2;
                        castRequired = FALSE;
                        ast_Parser_warning(this, "upcasting from '%s' to '%s' does not require an explicit cast",
                                ast_Parser_id(rvalueType, id1), ast_Parser_id(lvalue, id2));
                    }

                } else if (ast_Node(rvalue)->kind == Ast_LiteralExpr) {
                    result = ast_Expression_cast(rvalue, lvalue, FALSE);
                    castRequired = FALSE;
                }

            } else {
                corto_set_ref(&rvalue->type, lvalue);
                castRequired = FALSE;
            }

        }

        if (castRequired) {
            result = ast_Expression(ast_Cast__create(NULL, NULL, lvalue, rvalue, FALSE));
            if (!result) {
                goto error;
            }

            ast_Parser_collect(this, result);
        } else if (!result) {
            result = rvalue;
        }

    }

    return result;
error:
    fast_err;
    return NULL;
}

void ast_Parser_collect(
    ast_Parser this,
    corto_object o)
{
    /* 1st pass & 2nd pass are equal */

    corto_assert(this->collected != NULL, "initialization failed");
    corto_ll_insert(this->collected, o);

}

void ast_Parser_collectHeap(
    ast_Parser this,
    uintptr_t addr)
{
    ast_CHECK_ERRSET(this);

    /* 1st pass & 2nd pass are equal */
    corto_assert(this->heapCollected != NULL, "initialization failed");
    corto_ll_insert(this->heapCollected, (void*)addr);

}

int16_t ast_Parser_construct(
    ast_Parser this)
{
    CORTO_UNUSED(this);
    ast_Parser_reset(this);
    corto_tls_set(ast_PARSER_KEY, this);
    return 0;
}

ast_Storage ast_Parser_declaration(
    ast_Parser this,
    corto_type type,
    const char *id,
    bool isReference)
{
    ast_Storage result = NULL;
    ast_CHECK_ERRSET(this);

    if (!this->block) {
        goto error;
    }

    /* If block is not root or local-keyword is used, declare local */
    if (this->blockCount || this->isLocal) {
        if (this->pass) {
            corto_assert(this->block != NULL, "no valid code-block set in parser context.");
            /* If the variable is declared in the global scope, verify that its name doesn't clash with an object */
            if (!this->block->parent) {
                corto_object o;
                if ((o = corto_resolve(this->scope, id))) {
                    ast_Parser_error(this, "object '%s' is redeclared as a variable", id);
                    corto_release(o);
                    goto error;
                }

            }

            /* Redundant reference specifier if the type is also a reference */
            if (type->reference && isReference) {
                corto_id id;
                ast_Parser_error(yparser(), "redundant '&' in declaration of '%s', type '%s' is already a reference type",
                    id, ast_Parser_id(type, id));
                goto error;
            }

            result = ast_Storage(ast_Block_declareVar(this->block, id, type, FALSE, isReference));
            this->variables[this->variableCount] = result;
            this->variableCount++;
        } else {
            /* Variables are declared in 2nd pass */
            this->variables[this->variableCount] = NULL;
            this->variableCount++;
        }

    } else {
        corto_object o = NULL;
        corto_assert(this->block != NULL, "no valid code-block set in parser context.");
        if (!this->pass) {
            o = corto_declare(this->scope, id, type);
            if (!o) {
                corto_raise();
                ast_Parser_error(this, "cannot declare '%s'",
                    id);
                goto error;
            }

        } else {
            o = corto(CORTO_LOOKUP, {.parent = this->scope, .id = id});
            corto_assert(o != NULL, "object '%s' disappeared in 2nd pass", id);
            corto_release(o);
        }

        if (o) {
            result = ast_Storage(ast_Object__create(NULL, NULL, o));
            ast_Parser_collect(this, result);
            this->variables[this->variableCount] = result;
            this->variableCount++;
        }

    }

    return result;
error:
    fast_err;
    return NULL;
}

ast_Storage ast_Parser_declareFunction(
    ast_Parser this,
    corto_type returnType,
    const char *id,
    corto_type kind,
    bool returnsReference)
{
    corto_function function;
    corto_object o;
    ast_Storage result = NULL;
    corto_int32 distance;
    ast_CHECK_ERRSET(this);

    if (!this->pass) {
        corto_id functionName;

        /* Obtain name of function */
        corto_sig_name(id, functionName);

        /* Resolve identifier first to verify whether it is not already in use as non-function object */
        if ((o = corto_lookup(this->scope, functionName))) {
            if (!corto_instanceof(corto_function_o, o)) {
                corto_id id2;
                // todo changed here
                ast_Parser_error(this, "cannot redeclare '%s' of type '%s' as function",
                    id, ast_Parser_id(corto_typeof(o), id2));
                goto error;
            }

            corto_release(o);
        } else {
            /* corto_lookup might have raised an error about an ambiguous lookup */
            corto_catch();
        }

        /* This could be an implementation after a forward declaration so try to resolve
         * function first. */
        if (!((function = corto_lookup_function(this->scope, id, &distance, NULL)) && !distance)) {
            if (!kind) {
                kind = corto_typeof(this->scope)->options.defaultProcedureType;
                if (!kind) {
                    kind = corto_type(corto_function_o);
                }

            } else {
                if (!corto_instanceof(corto_procedure_o, kind) &&
                    !corto_interface_baseof(kind, corto_delegate_o))
                {
                    ast_Parser_error(
                        this, "'%s' is not a valid procedure or delegate type",
                        corto_fullpath(NULL, kind));
                    goto error;
                }

                /* Check whether declaration is a delegate */
                if(corto_interface_baseof(kind, corto_delegate_o)) {
                    result = ast_Parser_declareDelegate(
                        this,
                        returnType,
                        id,
                        returnsReference);
                }

            }

            if (!result) {
                if (!corto_class_instanceof(corto_type_o, returnType)) {
                    corto_id id;
                    ast_Parser_error(this, "object '%s' specified as returntype is not a type.", ast_Parser_id(returnType, id));
                    goto error;
                }

                function = corto(CORTO_DECLARE|CORTO_FORCE_TYPE, {
                    .parent = this->scope, .id = id, .type = kind
                });
                if (!function) {
                    corto_raise();
                    ast_Parser_error(this, "");
                    goto error;
                }

                corto_set_ref(&function->returnType, returnType);
                function->returnsReference = returnsReference;
                if (!corto(CORTO_DEFINE, {.object = function})) {
                    goto error;
                }

            }

        } else {
            if (strcmp(id, corto_idof(function))) {
                ast_Parser_error(this, "overloaded function '%s' conflicts with '%s'",
                    id, corto_idof(function));
                goto error;
            }

            corto_release(function);
        }

        if (!result) {
            result = ast_Storage(ast_Object__create(NULL, NULL, function));
            ast_Parser_collect(this, result);
        }

    } else {
        if(!kind || (corto_interface(kind)->kind == CORTO_PROCEDURE)) {
            corto_id query;
            const char *ptr;
            char *bptr, ch;
            /* If there are references in the function id, transform them into forced references so that the correct function
             * is resolved */
            ptr = id;
            bptr = query;
            while ((ch = *ptr)) {
                *bptr = ch;
                if (ch == '&') {
                    bptr++;
                    *bptr = '&'; /* && will enforce selection of a function that accepts a reference */
                }

                bptr++;
                ptr++;
            }

            *bptr = '\0';
            corto_object function = corto_lookup(this->scope, query);
            corto_assert(function != NULL,
                "object '%s' should still be in '%s' in 2nd pass",
                query, corto_fullpath(NULL, this->scope));
            result = ast_Storage(ast_Object__create(NULL, NULL, function));
            ast_Parser_collect(this, result);
            corto_release(function);
        }

    }

    return result;
error:
    fast_err;
    return NULL;
}

ast_Block ast_Parser_declareFunctionParams(
    ast_Parser this,
    ast_Storage function)
{
    corto_function function_o;
    corto_parameter *param;
    ast_Block result = NULL;
    unsigned int i;
    ast_CHECK_ERRSET(this);

    if (this->pass && function) {
        result = ast_Parser_blockPush(this, TRUE);

        function_o = ast_Object(function)->value;
        ast_Block_setFunction(result, function_o);

        /* If function is a method, include 'this' pointer */
        if (corto_procedure(corto_typeof(function_o))->hasThis) {
            corto_object parent;

            if (!corto_instanceof(corto_type(corto_interface_o), corto_parentof(function_o))) {
                parent = corto_typeof(corto_parentof(function_o));
            } else {
                parent = corto_parentof(function_o);
            }

            if (!corto_instanceof(corto_type(corto_interface_o), parent)) {
                corto_id id;
                ast_Parser_error(this, "parent of '%s' is not an interface nor of an interface type",
                    ast_Parser_id(function_o, id));
                goto error;
            }

            ast_Block_declareVar(result, "this", parent, TRUE, FALSE);
            /* If this-type of method has a base, include super */
            if (corto_interface(parent)->base) {
                ast_Block_declareVar(result, "super", corto_type(corto_interface(parent)->base), TRUE, FALSE);
            }

        }

        for(i=0; i<function_o->parameters.length; i++) {
            param = &function_o->parameters.buffer[i];
            ast_Block_declareVar(result, param->name, param->type, TRUE, param->passByReference);
        }

        /* If function has a returntype, include name of function */
        if (function_o->returnType && ((function_o->returnType->kind != CORTO_VOID) || function_o->returnType->reference)) {
            ast_Block_declareReturnVariable(result, function_o);
        }

    }

    return result;
error:
    return NULL;
}

int16_t ast_Parser_defineObject(
    ast_Parser this)
{
    ast_CHECK_ERRSET(this);

    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_defineObject(this->initializers[this->initializerCount])) {
            goto error;
        }

        corto_set_ref(&this->initializers[this->initializerCount], NULL);
        this->initializerCount--;
    }

    return 0;
error:
    fast_err;
    return -1;
}

int16_t ast_Parser_defineScope(
    ast_Parser this)
{
    ast_CHECK_ERRSET(this);

    if (!this->pass) {
        if (!this->scope) {
            goto error;
        }

        if (corto_instanceof(corto_type_o, this->scope) ||
            corto_instanceof(corto_package_o, this->scope))
        {
            if (!corto(CORTO_DEFINE, {.object = this->scope})) {
                corto_id id;
                ast_Parser_error(this, "cannot define '%s'\n",
                    ast_Parser_id(this->scope, id));
                goto error;
            }

        } else {
            ast_Define defineExpr = ast_Define__create(NULL, NULL, ast_Expression(ast_Object__create(NULL, NULL, this->scope)));
            ast_Parser_addStatement(this, ast_Node(defineExpr));
            ast_Parser_collect(this, defineExpr);
        }

    }

    return 0;
error:
    fast_err;
    return -1;
}

int16_t ast_Parser_defineVariable(
    ast_Parser this,
    ast_Storage object)
{
    corto_int16 result = 0;
    CORTO_UNUSED(this);
    ast_CHECK_ERRSET(this);

    if ((ast_Node(object)->kind == Ast_StorageExpr) && (ast_Storage(object)->kind == Ast_ObjectStorage)) {
        if (!corto(CORTO_DEFINE, {.object = ast_Object(object)->value})) {
            corto_id id1;
            ast_Parser_error(this, "failed to define '%s'",
                    ast_Parser_id(ast_Object(object)->value, id1));
            goto error;
        }

    } else {
        ast_Define defineStmt;
        defineStmt = ast_Define__create(NULL, NULL, (ast_Expression)object);
        ast_Parser_collect(this, defineStmt);
        ast_Parser_addStatement(this, ast_Node(defineStmt));
    }

    return result;
error:
    fast_err;
    return -1;
}

void ast_Parser_destruct(
    ast_Parser this)
{
    corto_iter iter;

    if (this->heapCollected) {
        iter = corto_ll_iter(this->heapCollected);
        while(corto_iter_hasNext(&iter)) {
            corto_dealloc(corto_iter_next(&iter));
        }

        corto_ll_clear(this->heapCollected);
    }

    corto_set_ref(&this->scope, NULL);
    memset(this->variables, 0, sizeof(this->variables));
}

ast_Expression ast_Parser_elementExpr(
    ast_Parser this,
    ast_Expression lvalue,
    ast_Expression rvalue)
{
    ast_Expression result = NULL;

    /* Expand element expression with comma-expressions */
    if (this->pass) {
        ast_Expression expr = ast_Expression_resolve(lvalue, NULL);
        if (!expr) {
            goto error;
        }

        corto_type t = ast_Expression_getType(expr);
        /* If the left value is a composite type then translate element expression to members */
        if (t) {
            if (t->kind == CORTO_COMPOSITE) {
                if (!(result = ast_Parser_explodeComma(this, expr, rvalue, ast_Parser_expandMember, NULL))) {
                    goto error;
                }

            } else {
                if (!(result = ast_Parser_explodeComma(this, lvalue, rvalue, ast_Parser_expandElement, NULL))) {
                    goto error;
                }

            }

        } else {
            ast_Parser_error(this, "cannot resolve element, left-hand of expression has no type");
            goto error;
        }

    }

    return result;
error:
    fast_err;
    return NULL;
}

int16_t ast_Parser_finalize(
    ast_Parser this,
    ic_program program)
{
    ic_scope scope = NULL;
    ic_storage returnValue = NULL;
    ast_Binding *binding;
    corto_iter bindingIter;

    /* Parse functions */
    if (this->bindings) {
        bindingIter = corto_ll_iter(this->bindings);
        while(corto_iter_hasNext(&bindingIter)) {
            ic_op ret;
            binding = corto_iter_next(&bindingIter);
            ic_program_pushFunction(program, binding->function);
            scope = (ic_scope)ast_Block_toIc(binding->impl, program, NULL, FALSE);
            if (this->errors) {
                goto error;
            }

            if (binding->function->returnType && ((binding->function->returnType->kind != CORTO_VOID) || (binding->function->returnType->reference))) {
                corto_id name;
                corto_sig_name(corto_idof(binding->function), name);
                returnValue = ic_scope_lookupStorage(scope, name, TRUE);
                ret = IC_1_OP(this->line, ic_ret, returnValue, IC_DEREF_VALUE, FALSE);
                if (binding->function->returnsReference || binding->function->returnType->reference) {
                    ((ic_storage)returnValue)->isReference = TRUE;
                    ((ic_op)ret)->s1Deref = IC_DEREF_ADDRESS;
                }else {
                    ((ic_op)ret)->s1Deref = IC_DEREF_VALUE;
                }

            } else {
                ret = IC_1_OP(this->line, ic_stop, NULL, IC_DEREF_VALUE, FALSE);
            }

            ic_scope_add(scope, ic_node(ret));
            ic_program_popScope(program);
            corto_release(binding->function);
            corto_release(binding->impl);
            corto_dealloc(binding);
        }

        corto_ll_clear(this->bindings);
    }

    return 0;
error:
    return -1;
}

int16_t ast_Parser_foreach(
    ast_Parser this,
    const char *loopId,
    ast_Expression collection)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(loopId);
    CORTO_UNUSED(collection);
    return 0;
}

corto_type ast_Parser_getComplexType(
    ast_Parser this)
{
    corto_type result = NULL;

    if (this->complexTypeSp > 0) {
        result = this->complexType[this->complexTypeSp-1];
        if (result && (result->kind != CORTO_COMPOSITE)) {
            result = NULL;
        }

    }

    return result;
}

ast_Expression ast_Parser_getLvalue(
    ast_Parser this,
    bool assignment)
{
    ast_Expression result = NULL;

    if (this->lvalueSp > 0) {
        result = this->lvalue[this->lvalueSp-1].expr;
        if (assignment) {
            if (!this->lvalue[this->lvalueSp-1].isAssignment) {
                result = NULL;
            }

        }

    }

    return result;
}

corto_type ast_Parser_getLvalueType(
    ast_Parser this,
    bool assignment)
{
    corto_type result = NULL;

    /* Check if the parser set an lvalue */
    if ((this->lvalueSp > 0) && this->lvalue[this->lvalueSp-1].expr) {
        result = ast_Expression_getType(this->lvalue[this->lvalueSp-1].expr);
    }

    /* If no lvalue is set, check if there is an active initializer */
    if (!result) {
        if ((this->initializerCount >= 0) && (this->initializers[this->initializerCount])) {
            result = ast_Initializer_currentType(this->initializers[this->initializerCount]);
        }

    }

    if (assignment) {
        if (!this->lvalue[this->lvalueSp-1].isAssignment) {
            result = NULL;
        }

    }

    return result;
}

ast_Node ast_Parser_ifStatement(
    ast_Parser this,
    ast_Expression condition,
    ast_Block trueBranch,
    ast_If falseBranch)
{
    ast_Node result = NULL;

    if (this->pass) {
        result = ast_Node(ast_If__create(NULL, NULL, condition, trueBranch, falseBranch));
        if (!result) {
            goto error;
        }

        ast_Parser_collect(this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
}

int16_t ast_Parser_import(
    ast_Parser this,
    const char *name)
{

    corto_object import = corto_lookup(NULL, name);
    if (!import) {
        ast_Parser_error(this, "unresolved import '%s'", name);
        goto error;
    }

    corto_objectList__append(this->imports, import);
    return 0;
error:
    return -1;
}

int16_t ast_Parser_initDeclare(
    ast_Parser this,
    ast_Expression ids)
{
    ast_ExpressionList expressions;

    if (!ids) {
        ast_Parser_error(this, "invalid initializer");
        goto error;
    }

    expressions = ast_Expression_toList(ids);
    /* Comma expression is encountered in the first pass. If this expression
     * contains out of UnresolvedReference nodes, declare objects */
    corto_iter it = corto_ll_iter(expressions);
    while (corto_iter_hasNext(&it)) {
        ast_Expression s = corto_iter_next(&it);
        if (ast_Node(s)->kind == Ast_StorageExpr) {
            corto_string id = NULL;
            corto_object oldScope = NULL, scope = NULL;
            corto_type type;
            /* Resolve unresolved reference */
            if (ast_Storage(s)->kind == Ast_UnresolvedReferenceStorage) {
                ast_UnresolvedReference ref = ast_UnresolvedReference(s);
                id = ref->ref;
                scope = ref->scope;
            /* An object/variable could've been accidentally resolved in what should
             * have been a declaration. In that case, take the object name as
             * input for the declaration */
            } else if (ast_Storage(s)->kind == Ast_ObjectStorage) {
                corto_object o = ast_Object(s)->value;
                if (o && corto_check_attr(o, CORTO_ATTR_NAMED)) {
                    id = ast_Object(s)->originalId;
                }

            } else if (ast_Storage(s)->kind == Ast_LocalStorage) {
                id = ast_Local(s)->name;
            } else {
                ast_Parser_error(this, "invalid usage of comma expression");
                goto error;
            }

            /* Temporarily set scope to scope of unresolved ref */
            if (scope) {
                corto_set_ref(&oldScope, this->scope);
                corto_set_ref(&this->scope, scope);
            }

            /* Obtain default type from scope */
            if (scope) {
                type = corto_typeof(scope)->options.defaultType;
            } else {
                type = corto_typeof(this->scope)->options.defaultType;
            }

            if (!type && this->pass) {
                ast_Parser_error(this,
                  "unresolved identifier '%s'", id);
                goto error;
            }

            /* Declare object */
            if (!ast_Parser_declaration(this, type, id, FALSE)) {
                goto error;
            }

            if (scope) {
                corto_set_ref(&this->scope, oldScope);
                corto_set_ref(&oldScope, NULL);
            }

        } else {
            ast_Parser_error(this, "invalid usage of comma expression");
            goto error;
        }

    }

    ast_Expression_cleanList(expressions);
    return 0;
error:
    fast_err;
    return -1;
}

int16_t ast_Parser_initKeyValuePop(
    ast_Parser this)
{
    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_popKey(this->initializers[this->initializerCount])) {
            goto error;
        }

    }

    return 0;
error:
    return -1;
}

int16_t ast_Parser_initKeyValuePush(
    ast_Parser this)
{
    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_pushKey(this->initializers[this->initializerCount])) {
            goto error;
        }

    }

    return 0;
error:
    return -1;
}

int16_t ast_Parser_initKeyValueSet(
    ast_Parser this,
    ast_Expression expr)
{
    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_valueKey(this->initializers[this->initializerCount], expr)) {
            goto error;
        }

    }

    return 0;
error:
    return -1;
}

int16_t ast_Parser_initMember(
    ast_Parser this,
    const char *member)
{
    ast_CHECK_ERRSET(this);

    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_member(this->initializers[this->initializerCount], member)) {
            goto error;
        }

    }

    return 0;
error:
    fast_err;
    return -1;
}

int16_t ast_Parser_initPop(
    ast_Parser this)
{
    ast_CHECK_ERRSET(this);

    /* Primitive values are not pushed/pop'd */
    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_pop(this->initializers[this->initializerCount])) {
            goto error;
        }

    }

    return 0;
error:
    fast_err;
    return -1;
}

int16_t ast_Parser_initPush(
    ast_Parser this)
{
    ast_CHECK_ERRSET(this);

    if (!this->variablePushed) {
        if ((this->initializerCount>=0) && this->initializers[this->initializerCount]) {
            if (ast_Initializer_push(this->initializers[this->initializerCount])) {
                ast_Parser_error(this, "invalid initializer scope");
                goto error;
            }

        }

    } else {
        this->variablePushed = FALSE;
    }

    return 0;
error:
    fast_err;
    return -1;
}

ast_Expression ast_Parser_initPushExpression(
    ast_Parser this)
{
    ast_Initializer initializer = NULL;

    this->initializerCount++;

    if (this->pass) {
        ast_InitializerVariableArray64 variables;

        memset(variables, 0, sizeof(variables));

        /* Create initializer */
        initializer = ast_Initializer(ast_InitializerExpression__create(NULL, NULL, variables, 1, TRUE));
        corto_set_ref(&this->initializers[this->initializerCount], initializer);
        ast_Parser_collect(this, initializer);
        this->variablePushed = TRUE;
    }

    return ast_Expression(initializer);
}

ast_Expression ast_Parser_initPushIdentifier(
    ast_Parser this,
    ast_Expression type)
{
    corto_object o;
    corto_type t;
    corto_bool isDynamic = TRUE;
    corto_bool forceStatic = FALSE;
    ast_InitializerVariableArray64 variables;
    memset(variables, 0, sizeof(variables));

    CORTO_UNUSED(this);
    CORTO_UNUSED(type);

    type = ast_Expression_resolve(type, NULL);
    if (!type) {
        goto error;
    }

    o = corto_type(ast_Object(type)->value);
    if (!corto_instanceof(corto_type(corto_type_o), o)) {
        corto_id id;
        ast_Parser_error(this, "invalid expression, '%s' is not a type", ast_Parser_id(o, id));
        goto error;
    }

    t = o;
    if (this->initializerCount >= 0) {
        ast_Initializer initializer = this->initializers[this->initializerCount];
        if (initializer) {
            if (!corto_instanceof(corto_type(ast_DynamicInitializer_o), initializer) &&
                !corto_instanceof(corto_type(ast_InitializerExpression_o), initializer)) {
                isDynamic = FALSE; /* A previous initializer is static, so this initializer will be static as well */
            }

        } else if (this->pass) {
            isDynamic = FALSE; /* If initializer is NULL and parser is in second pass initializer must be static */
        }

    }

    this->initializerCount++;
    /* The first pass will always create a static initializer when t is a type. This is required for declarations with anonymous
     * types. The parser can't determine upfront whether an anonymous object will be used in a declaration so this is determined
     * afterwards. */
    if (corto_instanceof(corto_type(corto_interface_o), t) && corto_interface_baseof(corto_interface(t), corto_interface(corto_type_o))) {
        forceStatic = TRUE;
    }

    /* Static initializers are executed during first pass */
    if ((!this->pass && !isDynamic) || forceStatic) {
        corto_object o;
        o = corto_declare(NULL, NULL, t);
        corto_set_ref(&variables[0].object, ast_Expression(ast_Object__create(NULL, NULL, o)));
        this->initializers[this->initializerCount] = ast_Initializer(ast_StaticInitializer__create(NULL, NULL, variables, 1));
        this->variablePushed = TRUE;
    } else if (this->pass && isDynamic && !forceStatic) {
        ast_Expression newExpr, assignExpr, var, refVar;
        corto_type type_o = corto_type(ast_Object(type)->value);
        refVar = var = ast_Expression(ast_Temporary__create(NULL, NULL, ast_Object(type)->value, TRUE));
        newExpr = ast_Expression(ast_New__create(NULL, NULL, ast_Object(type)->value,0));
        ast_Parser_collect(this, newExpr);
        if (!type_o->reference) {
            refVar = ast_Parser_unaryExpr(this, var, CORTO_AND);
            ast_Parser_collect(yparser(), refVar);
        }

        assignExpr = ast_Expression(ast_Binary__create(NULL, NULL, refVar, newExpr, CORTO_ASSIGN));
        ast_Parser_collect(this, assignExpr);
        ast_Parser_addStatement(this, ast_Node(assignExpr));
        corto_set_ref(&variables[0].object, var);
        this->initializers[this->initializerCount] = ast_Initializer(ast_DynamicInitializer__create(NULL, NULL, variables, 1, FALSE));
        this->variablePushed = TRUE;
    } else {
        corto_set_ref(&this->initializers[this->initializerCount], NULL);
        this->variablePushed = TRUE;
    }

    return variables[0].object;
error:
    fast_err;
    return NULL;
}

int16_t ast_Parser_initPushStatic(
    ast_Parser this)
{
    corto_bool isLocal = this->isLocal;
    ast_InitializerVariableArray64 variables;
    ast_Initializer initializer;
    corto_uint32 i;

    this->initializerCount++;

    if (!isLocal && this->variableCount) {
        if (!this->variables[0]) {
            goto error;
        }

        if (ast_Storage(this->variables[0])->kind != Ast_ObjectStorage) {
            isLocal = TRUE;
        }

    }

    /* Initializers are invalid for local variables - use assignments for these. */
    if (isLocal) {
        ast_Parser_error(this, "usage of initializer invalid for local variables (use assignment instead)");
        goto error;
    }

    if (!this->variableCount) {
        ast_Parser_error(this, "invalid initializer");
        goto error;
    }

    memset(variables, 0, sizeof(variables));
    /* Copy variables from parser to initializer structure */
    for(i=0; i<this->variableCount; i++) {
        corto_set_ref(&variables[i].object, ast_Expression(this->variables[i]));
        variables[i].key = 0;
        variables[i].offset = 0;
    }

    if (!this->pass) {
        /* Create initializer */
        initializer = ast_Initializer(ast_StaticInitializer__create(NULL, NULL, variables, this->variableCount));
        corto_set_ref(&this->initializers[this->initializerCount], initializer);
        ast_Parser_collect(this, initializer);
    } else {
        /* Create dummy initializer */
        initializer = ast_Initializer__create(NULL, NULL, variables, this->variableCount);
        corto_set_ref(&this->initializers[this->initializerCount], initializer);
        ast_Parser_collect(this, initializer);
    }

    return 0;
error:
    return -1;
}

int16_t ast_Parser_initValue(
    ast_Parser this,
    ast_Expression expr)
{
    ast_CHECK_ERRSET(this);

    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_value(this->initializers[this->initializerCount], expr)) {
            goto error;
        }

    }

    return 0;
error:
    fast_err;
    return -1;
}

bool ast_Parser_isAbortSet(
    ast_Parser this)
{
    corto_bool result = this->abort;
    this->abort = FALSE;
    return result;
}

bool ast_Parser_isErrSet(
    ast_Parser this)
{
    corto_bool result = this->errSet;
    this->errSet = FALSE;
    return result;
}

ast_Expression ast_Parser_lookup(
    ast_Parser this,
    const char *id)
{
    ast_Expression result = NULL;
    ast_CHECK_ERRSET(this);

    if (this->pass) {
        /* If complexType is set, this resolve is ran within a [] expression */
        corto_type complexType = ast_Parser_getComplexType(this);
        if (complexType) {
            if (corto_interface_resolveMember(corto_interface(complexType), id)) {
                result = ast_Expression(ast_String__create(NULL, NULL, id));
            }

        }

        if (this->block && !result) {
            result = ast_Expression(ast_Block_resolve(this->block, id));
        }

    }

    if (!result) {
        result = ast_Parser_resolve(this, id);
    }

    return result;
}

ast_Expression ast_Parser_memberExpr(
    ast_Parser this,
    ast_Expression lvalue,
    ast_Expression rvalue)
{
    ast_Expression result = NULL;

    if (this->pass) {
        ast_Expression expr = ast_Expression_resolve(lvalue, NULL);
        if (!expr) {
            goto error;
        }

        corto_type t = ast_Expression_getType(expr);
        if (t) {
            if (!(result = ast_Parser_explodeComma(this, expr, rvalue, ast_Parser_expandMember, NULL))) {
                goto error;
            }

        } else {
            ast_Parser_error(this, "cannot resolve member, left-hand of expression has no type");
            goto error;
        }

    }

    return result;
error:
    fast_err;
    return NULL;
}

ast_Storage ast_Parser_observerDeclaration(
    ast_Parser this,
    const char *id,
    ast_Expression object,
    corto_eventMask mask,
    ast_Object dispatcher)
{
    CORTO_UNUSED(object);
    CORTO_UNUSED(mask);
    ast_CHECK_ERRSET(this);

    ast_Storage result = NULL;
    corto_bool isTemplate = corto_class_instanceof(corto_type_o, this->scope);

    if (!(mask & CORTO_ON_SCOPE)) {
        mask |= CORTO_ON_SELF;
    }

    /* Observers come in two flavors. The first is the 'ordinary' observer. This observer is created and defined in the 2nd phase. The
     * second flavor is the template observer. This observer is attached to a class and is instantiated for each instance of that class.
     * Because this observer must be bound to the class when the class is defined (or rather: before any objects are created with that
     * class) these observers are created in the first pass and then the implementation is bound to it in the 2nd pass.
     */
    if (!this->pass) {
        /* If observer is a template observer (it is defined within the scope of a type) create it in the first pass */
        if (isTemplate) {
            result = ast_Parser_observerCreate(this, id, object, mask, dispatcher);
            if (!result) {
                ast_Parser_error(this, "failed to create template observer");
                goto error;
            }

        }

    } else {
        ast_Block block;
        corto_observer observer;
        corto_uint32 i;
        block = ast_Parser_blockPush(this, TRUE); /* Push new block on stack */
        result = ast_Parser_observerCreate(this, id, object, mask, dispatcher);
        if (!result) {
            ast_Parser_error(this, "failed to create observer");
            goto error;
        }

        observer = ast_Object(result)->value;
        /* Declare this */
        if (!ast_Block_resolve(block, "this")) {
            ast_Block_declareVar(block, "this", corto_object_o, TRUE, FALSE);
        }

        /* Loop parameters of observable, insert locals */
        for(i=0; i<corto_function(observer)->parameters.length; i++) {
            corto_parameter *p = &corto_function(observer)->parameters.buffer[i];
            ast_Block_declareVar(block, p->name, p->type, TRUE, TRUE); /* Observable parameter are references */
        }

        /* Bind observer and block */
        ast_Parser_bind(this, result, block);
        ast_Block_setFunction(block, corto_function(observer));
    }

    return result;
error:
    fast_err;
    return NULL;
}

void ast_Parser_observerPush(
    ast_Parser this)
{
    ast_CHECK_ERRSET(this);

    /* Observer-implementations are parsed in the 2nd pass */
    if (this->pass) {
        if (corto_class_instanceof(corto_type_o, this->scope)) {
            ast_Block block;
            block = ast_Parser_blockPush(this, TRUE);
            ast_Block_declareTemplate(block, "this", this->scope, TRUE, FALSE);
        }

    }

}

uint32_t ast_Parser_parse(
    ast_Parser this,
    corto_stringSeq argv)
{
    ast_CHECK_ERRSET(this);
    corto_int32 err = 0;

    ast_Parser_parseIntern(this, NULL, &err);
    if (err) {
        goto error;
    }

    /* Parse to corto intermediate code */
    if ( ast_Parser_toIc(this, argv)) {
        corto_error("%s: parsed with errors (%d errors, %d warnings)", this->filename, this->errors, this->warnings);
        goto error;
    }

    return 0;
error:
    fast_err;
    return -1;
}

ast_Expression ast_Parser_parseExpression(
    ast_Parser this,
    const char *expr,
    ast_Block block,
    corto_object scope,
    uint32_t line,
    uint32_t column)
{
    ast_Expression result = NULL;
    corto_string exprFinalized;

    CORTO_UNUSED(scope);

    if (this->source) {
        corto_dealloc(this->source);
    }

    exprFinalized = corto_alloc(strlen(expr) + 2);
    sprintf(exprFinalized, "%s\n", expr);
    this->source = exprFinalized;
    corto_set_ref(&this->block, block);
    corto_set_ref(&this->scope, scope);
    // Give expression its own block
    ast_Parser_blockPush(this, FALSE);
    if (fast_yparse(this, line, column)) {
        corto_trace("%s: expression '%s' parsed with errors", this->filename, expr);
        ast_Parser_blockPop(this);
        goto error;
    }

    /* Extract expression */
    block = this->block;
    ast_Parser_blockPop(this);
    if (block) {
        /* Block should contain exactly one expression */
        if (block->statements) {
            if (corto_ll_count(block->statements) == 1) {
                ast_Node node;
                node = corto_ll_get(block->statements, 0);
                if (corto_instanceof(corto_type(ast_Expression_o), node)) {
                    result = ast_Expression(node);
                } else {
                    corto_id id; (void)id;
                    corto_trace("%s: '%s' does not resolve to a valid expression (found %s).",
                            this->filename, expr, ast_Parser_id(corto_typeof(node), id));
                    goto error;
                }

            } else {
                corto_trace("%s: expression '%s' is not allowed to contain multiple statements", this->filename, expr);
                goto error;
            }

        } else {
            corto_trace("%s: expression '%s' did not result in a statement", this->filename, expr);
            goto error;
        }

    } else {
        corto_trace("parser error: no block set in parser after parsing expression.");
        goto error;
    }

    return result;
error:
    return NULL;
}

int16_t ast_Parser_parseFunction(
    corto_function f,
    const char *expr,
    bool inverse)
{
    ic_scope icScope; /* Parsed intermediate-code program */
    ic_storage returnValue = NULL; /* Intermediate representation of return value */
    corto_type returnType = NULL; /* Return type */
    ic_op ret = NULL; /* ret or stop instruction */
    ic_program program = NULL;
    ast_Local resultLocal = NULL;
    corto_int32 i, err = 0;

    /* Create parser */
    ast_Parser parser = ast_Parser__create(NULL, NULL, expr, NULL);
    if (!parser) {
        corto_throw("failed to create parser");
        goto error;
    }

    parser->repl = TRUE;
    /* Create block that contains local variables for function arguments */
    ast_Block block = ast_Block__create(NULL, NULL, NULL);
    if (!block) {
        corto_throw("failed to create code block");
        goto error;
    }

    parser->blockCount ++;
    for (i = 0; i < f->parameters.length; i++) {
        corto_parameter *p = &f->parameters.buffer[i];
        if (!ast_Block_declareVar(block, p->name, p->type, TRUE, p->passByReference)) {
            corto_throw("failed to declare parameter '%s'", p->name);
            goto error;
        }

    }

    if (f->returnType) {
        corto_bool isReference = f->returnType->reference || f->returnsReference;
        resultLocal = ast_Block_declareVar(
            block,
            "_",
            f->returnType,
            FALSE,
            isReference);
        if (!resultLocal) {
            corto_throw("failed to create return variable");
            goto error;
        }

        resultLocal->kind = Ast_LocalReturn;
        ast_Expression(resultLocal)->deref = isReference ? Ast_ByReference : Ast_ByValue;
        returnType = f->returnType;
        corto_string prev = parser->source;
        parser->source = corto_asprintf("_ = %s", parser->source);
        corto_dealloc(prev);
    }

    corto_set_ref(&parser->block, block);
    /* Parse expression */
    ast_Expression result = ast_Parser_parseIntern(parser, NULL, &err);
    if (err) {
        goto error;
    }

    /*printf("\n%s:\n", expr);*/
    /*ast_OptimizeExpr_printExpression(result);*/
    /*printf("\n");*/
    if (inverse) {
        result = ast_OptimizeExpr_reorderExpression(result);
        /*printf("#1: "); ast_OptimizeExpr_printExpression(result); printf("\n");*/
        corto_ll elems = ast_OptimizeExpr_reduceExpression(result);
        ast_OptimizeExpr_inverse(elems);
        result = ast_OptimizeExpr_reducedToExpression(elems);
        /*printf("##: "); ast_OptimizeExpr_printExpression(result); printf("\n");*/
    }

    /* Create assignment expression that returns result of expression */
    if (!resultLocal && result && result->type) {
        ast_Binary assignment;
        returnType = corto_type(ast_Expression_getType(result));
        if ((returnType->kind != CORTO_VOID) || (result->deref == Ast_ByReference)) {
            resultLocal = ast_Block_declareVar(parser->block, "_", result->type, FALSE,
                result->isReference);
            if (!resultLocal) {
                corto_throw("failed to create return variable");
                goto error;
            }

            ast_Expression(resultLocal)->deref = result->isReference ? Ast_ByReference : Ast_ByValue;
            resultLocal->kind = Ast_LocalReturn;
            assignment = ast_Binary__create(NULL, NULL, ast_Expression(resultLocal), result, CORTO_ASSIGN);
            corto_ll_replace(parser->block->statements, result, assignment);
        }

        corto_set_ref(&f->returnType, returnType);
        f->returnsReference = result->isReference;
    }

    /* Create program for intermediate code */
    program = ic_program__create(NULL, NULL, parser->filename);
    if (!program) {
        corto_throw("failed to create intermediate code program");
        goto error;
    }

    ic_program_pushScope(program);
    /* Push function, so when assembling, code will be added to a function */
    ic_program_pushFunction(program, f);
    /* Generate intermediate code for AST */
    icScope = (ic_scope)ast_Block_toIc(parser->block, program, NULL, FALSE);
    if (parser->errors) {
        goto error;
    }

    /* If code contains bindings, expression contains nested functions */
    if (parser->bindings && corto_ll_count(parser->bindings)) {
        corto_throw("nested functions are invalid");
        goto error;
    }

    returnValue = ic_scope_lookupStorage(icScope, "_", TRUE);
    if (returnValue) {
        ret = IC_1_OP(parser->line, ic_ret, returnValue, IC_DEREF_VALUE, FALSE);
        if (result->isReference) {
            ((ic_storage)returnValue)->isReference = TRUE;
            ((ic_op)ret)->s1Deref = IC_DEREF_ADDRESS;
        }else {
            ((ic_op)ret)->s1Deref = IC_DEREF_VALUE;
        }

    } else {
        ret = IC_1_OP(parser->line, ic_stop, NULL, IC_DEREF_VALUE, FALSE);
    }

    ic_scope_add(icScope, ic_node(ret));
    /* Pop function */
    ic_program_popScope(program);
#ifdef IC_TRACING
    extern corto_bool CORTO_DEBUG_ENABLED;
    if (CORTO_DEBUG_ENABLED) {
        printf("=====\n%s\n\n", ic_program_toString(program));
    }

#endif
    /* Translate program to vm code */
    ic_program_assemble(program);
    /* Free program */
    corto_delete(program);
    /* Free parser */
    corto_delete(parser);
    return 0;
error:
    if (parser) {
        corto_delete(parser);
    }

    if (program) {
        corto_delete(program);
    }

    return -1;
}

int16_t ast_Parser_parseLine(
    const char *expr,
    corto_object scope,
    uintptr_t value)
{
    ic_scope icScope; /* Parsed intermediate-code program */
    ic_storage returnValue = NULL; /* Intermediate representation of return value */
    corto_type returnType = NULL; /* Return type */
    ic_op ret = NULL; /* ret or stop instruction */
    corto_value *v = (corto_value*)value;
    ic_program program = NULL;
    corto_int32 err = 0;
    ast_Parser parser = ast_Parser__create(NULL, NULL, expr, NULL);
    parser->repl = TRUE;

    ast_Expression result = ast_Parser_parseIntern(parser, scope, &err);
    if (err) {
        goto error;
    }

    if (result && result->type) {
        ast_Local resultLocal;
        ast_Binary assignment;
        returnType = corto_type(ast_Expression_getType(result));
        if ((returnType->kind != CORTO_VOID) || (result->deref == Ast_ByReference)) {
            resultLocal = ast_Block_declareVar(parser->block, "<result>", result->type, FALSE,
                result->isReference);
            ast_Expression(resultLocal)->deref = result->isReference ? Ast_ByReference : Ast_ByValue;
            if (!resultLocal) {
                goto error;
            }

            resultLocal->kind = Ast_LocalReturn;
            assignment = ast_Binary__create(NULL, NULL, ast_Expression(resultLocal), result, CORTO_ASSIGN);
            corto_ll_replace(parser->block->statements, result, assignment);
        }

    }

    program = ic_program__create(NULL, NULL, parser->filename);
    /* Parse root-block */
    icScope = (ic_scope)ast_Block_toIc(parser->block, program, NULL, FALSE);
    if (parser->errors) {
        goto error;
    }

    /* Finalize functions */
    if (ast_Parser_finalize(parser, program)) {
        goto error;
    }

    returnValue = ic_scope_lookupStorage(icScope, "<result>", TRUE);
    if (returnValue) {
        ret = IC_1_OP(parser->line, ic_ret, returnValue, IC_DEREF_VALUE, FALSE);
        if (result->isReference) {
            ((ic_storage)returnValue)->isReference = TRUE;
            ((ic_op)ret)->s1Deref = IC_DEREF_ADDRESS;
        }else {
            ((ic_op)ret)->s1Deref = IC_DEREF_VALUE;
        }

    } else {
        ret = IC_1_OP(parser->line, ic_stop, NULL, IC_DEREF_VALUE, FALSE);
    }

    ic_program_add(program, ic_node(ret));
#ifdef IC_TRACING
    extern corto_bool CORTO_DEBUG_ENABLED;
    if (CORTO_DEBUG_ENABLED) {
        printf("=====\n%s\n\n", ic_program_toString(program));
    }

#endif
    /* Translate program to vm code */
    ic_program_assemble(program);
    if (result) {
        /* Run vm program */
        if (result && result->isReference) {
            corto_object o = NULL;
            if (ic_program_run(program, (corto_word)&o, CORTO_SEQUENCE_EMPTY(corto_stringSeq))) {
                goto error;
            }

            if (v) {
                if (o) {
                    *v = corto_value_object(o, NULL);
                } else {
                    v->is.value.storage = 0;
                    *v = corto_value_value(&v->is.value.storage, corto_object_o);
                }

            }

        } else if (result) {
            if(returnType->kind == CORTO_PRIMITIVE) {
                if (v) {
                    *v = corto_value_value(&v->is.value.storage, returnType);
                    if (ic_program_run(program, (corto_word)&v->is.value.storage, CORTO_SEQUENCE_EMPTY(corto_stringSeq))) {
                        goto error;
                    }

                } else {
                    if (ic_program_run(program, 0, CORTO_SEQUENCE_EMPTY(corto_stringSeq))) {
                        goto error;
                    }

                }

            } else {
                void *ptr = corto_alloc(corto_type_sizeof(returnType));
                if (ic_program_run(program, (corto_word)&ptr, CORTO_SEQUENCE_EMPTY(corto_stringSeq))) {
                    goto error;
                }

                if (v) {
                    if (ptr) {
                        *v = corto_value_value(ptr, returnType);
                    } else {
                        v->is.value.storage = 0;
                        *v = corto_value_value(&v->is.value.storage, corto_object_o);
                    }

                }

            }

        }

    } else {
        if (ic_program_run(program, 0, CORTO_SEQUENCE_EMPTY(corto_stringSeq))) {
            goto error;
        }

        if (v) {
            *v = corto_value_value(NULL, corto_void_o);
        }

    }

    /* Free program */
    corto_delete(program);
    /* Free parser */
    corto_delete(parser);
    return 0;
error:
    if (parser) {
        corto_delete(parser);
    }

    if (program) {
        corto_delete(program);
    }

    return -1;
}

corto_type ast_Parser_parseType(
    const char *expr,
    corto_object scope)
{
    corto_int32 err = 0;
    corto_type result = NULL;
    ast_Parser parser = ast_Parser__create(NULL, NULL, expr, NULL);
    parser->repl = TRUE;

    ast_Expression e = ast_Parser_parseIntern(parser, scope, &err);
    if (!e || err) {
        goto error;
    }

    result = ast_Expression_getType(e);
    corto_delete(parser);
    return result;
error:
    if (parser) {
        corto_delete(parser);
    }

    return NULL;
}

void ast_Parser_popComplexType(
    ast_Parser this)
{

    this->complexTypeSp--;
    if (this->complexTypeSp < 0) {
        ast_Parser_error(this, "parser error: complexType stack pointer below zero");
        abort();
    }

}

void ast_Parser_popLvalue(
    ast_Parser this)
{

    this->lvalueSp--;
    if (this->lvalueSp < 0) {
        ast_Parser_error(this, "parser error: lvalue stack pointer below zero");
        abort();
    }

}

void ast_Parser_popScope(
    ast_Parser this,
    corto_object previous)
{
    ast_CHECK_ERRSET(this);

    /* Scope content of types is defined at parse-time. If scope contained objects
     * that set their parentstate to CORTO_VALID, they might not yet be defined. */
    if (corto_instanceof(corto_type(corto_type_o), this->scope)) {
        corto_objectseq objects = corto_scope_claim(this->scope);
        corto_int32 i;
        for (i = 0; i < objects.length; i ++) {
            if (!corto_check_state(objects.buffer[i], CORTO_VALID)) {
                if (!corto(CORTO_DEFINE, {.object = objects.buffer[i]})) {
                    corto_raise();
                    ast_Parser_error(this, "cannot define");
                }

            }

        }

        corto_scope_release(objects);
    }

    /* Restore scope */
    corto_set_ref(&this->scope, previous);
}

ast_Expression ast_Parser_postfixExpr(
    ast_Parser this,
    ast_Expression lvalue,
    corto_operatorKind _operator)
{
    ast_Expression result = NULL;

    if (this->pass) {
        result = ast_Expression(ast_PostFix__create(NULL, NULL, lvalue, _operator));
        if (!result) {
            goto error;
        }

        ast_Parser_collect(this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
}

void ast_Parser_pushComplexType(
    ast_Parser this,
    ast_Expression lvalue)
{

    if (lvalue) {
        corto_set_ref(&this->complexType[this->complexTypeSp], ast_Expression_getType(lvalue));
    } else {
        corto_set_ref(&this->complexType[this->complexTypeSp], NULL);
    }

    this->complexTypeSp++;
}

void ast_Parser_pushLvalue(
    ast_Parser this,
    ast_Expression lvalue,
    bool isAssignment)
{

    corto_set_ref(&this->lvalue[this->lvalueSp].expr, lvalue);
    this->lvalue[this->lvalueSp].isAssignment = isAssignment;
    this->lvalueSp++;

}

int16_t ast_Parser_pushPackage(
    ast_Parser this,
    const char *name)
{
    char ch, *ptr, *bptr;
    corto_id buffer;
    corto_id fullpath;

    if (this->scope && (this->scope != root_o)) {
        ast_Parser_error(this, "#package may only be used in the root scope");
        goto error;
    }

    corto_set_ref(&this->scope, root_o);
    if ((name[0] == ':') && (name[1] == ':')) {
        strcpy(fullpath, name + 2);
    } else if (name[0] == '/') {
        strcpy(fullpath, name + 1);
    } else {
        strcpy(fullpath, name);
    }

    /* Check for package nesting */
    ptr = fullpath;
    bptr = buffer;
    while ((ch = *ptr)) {
        if (((ch == ':') && (ptr[1] == ':')) || (ch == '/')) {
            *bptr = '\0';
            if (ch == ':') {
                ptr++;
            }

            corto_object o = corto_lookup(this->scope, buffer);
            if (!o) {
                /* Declare package */
                ast_Parser_declaration(this, corto_type(corto_package_o), buffer, FALSE);
                /* Push package as scope */
                ast_Parser_pushScope(this);
                /* Define package */
                ast_Parser_defineScope(this);
            } else {
                corto_set_ref(&this->scope, o);
                corto_release(o);
            }

            bptr = buffer;
        } else {
            *bptr = ch;
            bptr++;
        }

        ptr++;
    }

    *bptr = '\0';
    /* Declare package */
    if (!ast_Parser_declaration(
        this,
        corto_type(corto_package_o),
        buffer,
        FALSE))
    {
        goto error;
    }

    /* Push package as scope */
    ast_Parser_pushScope(this);
    /* Define package */
    ast_Parser_defineScope(this);
    return 0;
error:
    return -1;
}

void ast_Parser_pushReturnAsLvalue(
    ast_Parser this,
    corto_function function)
{
    ast_Expression result = NULL;

    if (this->pass) {
        if (function->returnType) {
            corto_id id;
            corto_sig_name(corto_idof(function), id);
            result = ast_Expression(ast_Block_resolve(this->block, id));
            if (!result) {
                ast_Parser_error(this, "parser error: can't find result variable '%s'", id);
                goto error;
            }

        }

    }

    ast_Parser_pushLvalue(this, result, TRUE);
    return;
error:
    fast_err;
}

corto_object ast_Parser_pushScope(
    ast_Parser this)
{
    corto_object oldScope = NULL;
    ast_Expression scope;

    ast_CHECK_ERRSET(this);

    oldScope = this->scope;
    if (!this->variableCount) {
        /* This is the result of a previous error */
        goto error;
    }

    if (!this->variables[0]) {
        goto error;
    }

    scope = ast_Expression_resolve(this->variables[0], NULL);
    if (!scope) {
        goto error;
    }

    if (!corto_instanceof(ast_Object_o, this->variables[0])) {
        ast_Parser_error(this, "invalid scope expression (expected object, got '%s')",
            corto_idof(corto_typeof(this->variables[0])));
        goto error;
    }

    if (this->variables[0]) {
        corto_set_ref(&this->scope, ast_Object(this->variables[0])->value);
        ast_Parser_reset(this);
    } else {
        goto error;
    }

    return oldScope;
error:
    fast_err;
    return NULL;
}

void ast_Parser_reset(
    ast_Parser this)
{

    this->variableCount = 0;
    this->variablesInitialized = FALSE;
    this->isLocal = FALSE;
    this->lvalueSp = 0;
    this->complexTypeSp = 0;
    this->initializerCount = -1;

}

ast_Expression ast_Parser_ternaryExpr(
    ast_Parser this,
    ast_Expression cond,
    ast_Expression iftrue,
    ast_Expression iffalse)
{
    ast_Expression result = NULL;

    if (this->pass) {
        ast_Expression lvalue = ast_Parser_getLvalue(this, TRUE);

        if (!lvalue) {
            lvalue = ast_Expression(ast_Temporary__create(NULL, NULL, iftrue->type, FALSE));
        }

        result = ast_Expression(ast_Ternary__create(NULL, NULL, cond, iftrue, iffalse, lvalue));
        if (!result) {
            goto error;
        }

        ast_Parser_collect(this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
}

ast_Expression ast_Parser_unaryExpr(
    ast_Parser this,
    ast_Expression lvalue,
    corto_operatorKind _operator)
{
    ast_Expression result = NULL;

    if (lvalue && this->pass) {
        if (_operator == CORTO_SUB) {
            corto_type lvalueType = ast_Expression_getType(lvalue);

            if (lvalueType->kind == CORTO_PRIMITIVE) {
                switch(corto_primitive(lvalueType)->kind) {
                case CORTO_INTEGER:
                    if (ast_Node(lvalue)->kind == Ast_LiteralExpr) {
                        result = ast_Expression(ast_Integer__create(NULL, NULL, ast_Integer(lvalue)->value * -1));
                        ast_Parser_collect(this, result);
                        break;
                    }

                    /* no break */
                case CORTO_UINTEGER:
                    if (ast_Node(lvalue)->kind == Ast_LiteralExpr) {
                        result = ast_Expression(ast_SignedInteger__create(NULL, NULL, ast_Integer(lvalue)->value * -1));
                        ast_Parser_collect(this, result);
                        break;
                    }

                    /* no break */
                case CORTO_FLOAT:
                    if (ast_Node(lvalue)->kind == Ast_LiteralExpr) {
                        result = ast_Expression(ast_FloatingPoint__create(NULL, NULL, ast_FloatingPoint(lvalue)->value * -1));
                        ast_Parser_collect(this, result);
                    } else {
                        if (this->pass) {
                            ast_SignedInteger minusOne = ast_SignedInteger__create(NULL, NULL, -1);
                            ast_Parser_collect(this, minusOne);
                            result = ast_Expression(ast_Binary__create(NULL, NULL, lvalue, ast_Expression(minusOne), CORTO_MUL));
                            ast_Parser_collect(this, result);
                        }

                    }

                    break;
                default: {
                    corto_id id;
                    ast_Parser_error(this, "unary operator - not applicable to type '%s'", ast_Parser_id(lvalueType, id));
                    goto error;
                }

                }

            } else {
                corto_id id;
                ast_Parser_error(this, "unary operator - not applicable to non-primitive type '%s'", ast_Parser_id(lvalueType, id));
                goto error;
            }

        } else if (_operator == CORTO_AND) {
            if (ast_Node(lvalue)->kind == Ast_StorageExpr) {
                if (lvalue->isReference) {
                    if (corto_copy((corto_object*)&result, lvalue)) {
                        ast_Parser_error(this, "parser error: failed to take reference (copy failed)");
                    }

                    result->deref = Ast_ByReference;
                    ast_Node(result)->line = this->line;
                    ast_Node(result)->column = this->column;
                    /* Ensure that copies of temporaries point to the same storage */
                    if (ast_Storage(result)->kind == Ast_TemporaryStorage) {
                        safe_ast_Temporary_setProxy(result, lvalue);
                    }

                } else {
                    ast_Parser_error(this, "cannot take reference from non-reference variable");
                    goto error;
                }

            } else {
                lvalue->deref = Ast_ByReference;
                result = lvalue;
            }

        } else {
            if (this->pass) {
                result = ast_Expression(ast_Unary__create(NULL, NULL, lvalue, _operator));
                if (!result) {
                    goto error;
                }

                ast_Parser_collect(this, result);
            }

        }

    }

    return result;
error:
    fast_err;
    return NULL;
}

ast_Node ast_Parser_updateStatement(
    ast_Parser this,
    ast_Expression expr,
    ast_Block block)
{
    ast_Node result = NULL;

    if (this->pass) {
        ast_Block functionBlock;
        ast_Expression from = NULL;
        corto_function function;
        corto_ll exprList;

        if (!expr) { /* Can only happen due to a previous error */
            goto error;
        }

        /* If update is being done from a method or template observer do the update
         * from the corresponding object (set 'from' to this). Search for a function-block */
        functionBlock = this->block;
        while(functionBlock && !(function = functionBlock->function)) {
            functionBlock = functionBlock->parent;
        }

        if (functionBlock) {
            if (corto_instanceof(corto_interface_o, corto_parentof(function))) {
                if (corto_procedure(corto_typeof(function))->hasThis) {
                    from = ast_Parser_lookup(this, "this");
                }

            }

        }

        /* Keep argument expressions */
        exprList = ast_Expression_toList(expr);
        result = ast_Node(ast_Update__create(NULL, NULL, exprList, block, from, Ast_UpdateDefault));
        ast_Parser_collect(this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
}

ast_Node ast_Parser_whileStatement(
    ast_Parser this,
    ast_Expression condition,
    ast_Block trueBranch,
    bool isUntil)
{
    ast_Node result = NULL;

    if (this->pass) {
        if (isUntil && this->block->isRoot) {
            ast_Parser_error(yparser(), "invalid do-while in root block");
            goto error;
        }

        result = ast_Node(ast_While__create(NULL, NULL, condition, trueBranch, isUntil));
        if (!result) {
            goto error;
        }

        ast_Parser_collect(this, result);
        if (isUntil) {
            corto_set_ref(&this->block->_while, result);
        }

    }

    return result;
error:
    fast_err;
    return NULL;
}

int16_t ast_Parser_with(
    ast_Parser this)
{
    ast_Parser_pushScope(yparser());

    if (ast_Parser_defineScope(this)) {
        goto error;
    }

    return 0;
error:
    return -1;
}
