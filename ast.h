#ifndef AST_H
#define AST_H

typedef enum {
    NODE_FUNCTION,
    NODE_DECL,
    NODE_BLOCK,
    NODE_EXPR,
    NODE_ASSIGN,
    NODE_IF,
    NODE_WHILE,
    NODE_RETURN,
    NODE_VAR,
    NODE_NUM
} NodeType;

typedef enum {
    OP_NONE,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_EQ,
    OP_NEQ,
    OP_GT,
    OP_LT,
    OP_GTE,
    OP_LTE,
    OP_ASSIGN
} OperatorType;

typedef struct ASTNode {
    NodeType type;
    OperatorType op;           // operator type for expressions
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *next;
    char *name;                // variable, function name etc.
    int value;                 // number literal value
} ASTNode;

ASTNode* make_node(NodeType type, ASTNode *left, ASTNode *right);
ASTNode* make_expr(OperatorType op, ASTNode *left, ASTNode *right);
ASTNode* make_assign(ASTNode *left, ASTNode *right);
ASTNode* make_var(char *name);
ASTNode* make_num(int value);
ASTNode* make_if(ASTNode *cond, ASTNode *then_branch, ASTNode *else_branch);
ASTNode* make_while(ASTNode *cond, ASTNode *body);
ASTNode* make_return(ASTNode *expr);
ASTNode* make_block(ASTNode *stmts);
void print_ast(ASTNode *node, int indent);

#endif
