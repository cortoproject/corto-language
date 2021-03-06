/* This is a managed file. Do not delete this comment. */

#include <corto/ast/ast.h>

#include "ast__private.h"

ast_Parser yparser(void);
void ast_Parser_error(ast_Parser this, char* fmt, ...);
void ast_Parser_warning(ast_Parser this, char* fmt, ...);

/* Create if statement based on ternary operator expressions */
ast_If ast_Ternary_createIf(ast_Expression condition, ast_Node ifTrue, ast_Node ifFalse) {
    ast_Block trueBlock;
    ast_Block falseBlock;
    ast_If falseIf;
    ast_If result;
    
    if (corto_instanceof(corto_type(ast_Block_o), ifTrue)) {
        trueBlock = ast_Block__create(NULL, NULL, yparser()->block);
        falseBlock = ast_Block__create(NULL, NULL, yparser()->block);
        ast_Block_addStatement(trueBlock, ast_Node(ifTrue));
        ast_Block_addStatement(falseBlock, ast_Node(ifFalse));
        ast_Parser_collect(yparser(), trueBlock);
        ast_Parser_collect(yparser(), falseBlock);
    } else {
        trueBlock = ast_Block(ifTrue);
        falseBlock = ast_Block(ifFalse);
    }
    
    falseIf = ast_If__create(NULL, NULL, NULL, falseBlock, NULL);
    result = ast_If__create(NULL, NULL, condition, trueBlock, falseIf);
    
    /* Because a ternary operator always has a true and false branch it there is not much use
     * in reporting unreachable code. If a ternary operator has a compile-time resolvable
     * condition, it is probably intended. */
    ast_If_noWarnUnreachable(result);

    ast_Parser_collect(yparser(), falseIf);
    
    return result;
}



int16_t ast_Ternary_construct(
    ast_Ternary this)
{
    ast_Node trueBranch=NULL, falseBranch=NULL;
    ast_Expression trueExpr, falseExpr;
    corto_type resultType = ast_Expression_getType(this->result);

    ast_Node(this)->kind = Ast_TernaryExpr;
    
    /* Create true statement */
    trueBranch = ast_Node(ast_Parser_blockPush(yparser(), FALSE));
    trueExpr = ast_Expression(ast_Parser_binaryExpr(yparser(), this->result, this->ifTrue, CORTO_ASSIGN));
    ast_Block_addStatement(ast_Block(trueBranch), ast_Node(trueExpr));
    ast_Parser_blockPop(yparser());
    
    /* Create false statement */
    falseBranch = ast_Node(ast_Parser_blockPush(yparser(), FALSE));
    falseExpr = ast_Expression(ast_Parser_binaryExpr(yparser(), this->result, this->ifFalse, CORTO_ASSIGN));
    ast_Block_addStatement(ast_Block(falseBranch), ast_Node(falseExpr));
    ast_Parser_blockPop(yparser());

    /* Store both expressions in this */
    corto_set_ref(&this->ifTrueExpr, trueExpr);
    corto_set_ref(&this->ifFalseExpr, falseExpr);
    
    /* Create condition */
    this->ifstmt = ast_Ternary_createIf(this->condition, trueBranch, falseBranch);
    corto_set_ref(&ast_Expression(this)->type, resultType);

    return 0;
}

bool ast_Ternary_hasReturnedResource(
    ast_Ternary this)
{
    return ast_Expression_hasReturnedResource(this->condition) ||
           ast_Expression_hasReturnedResource(this->ifTrue) ||
           ast_Expression_hasReturnedResource(this->ifFalse);
}

bool ast_Ternary_hasSideEffects(
    ast_Ternary this)
{
    return ast_Expression_hasSideEffects(this->condition) ||
           ast_Expression_hasSideEffects(this->ifTrue) ||
           ast_Expression_hasSideEffects(this->ifFalse);
}

void ast_Ternary_setOperator(
    ast_Ternary this,
    corto_operatorKind kind)
{

    if (this->ifTrueExpr && corto_instanceof(corto_type(ast_Binary_o), this->ifTrueExpr)) {
        ast_Binary_setOperator(ast_Binary(this->ifTrueExpr), kind);
    }
    if (this->ifFalseExpr && corto_instanceof(corto_type(ast_Binary_o), this->ifFalseExpr)) {
        ast_Binary_setOperator(ast_Binary(this->ifFalseExpr), kind);
    }

}

corto_ic_node ast_Ternary_toIc(
    ast_Ternary this,
    corto_ic_program program,
    corto_ic_storage storage,
    bool stored)
{
    ast_If_toIc(this->ifstmt, program, storage, stored);
    return ast_Node_toIc(ast_Node(this->result), program, storage, stored);
}

