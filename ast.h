#ifndef AST_H
#define AST_H


typedef enum {
    TYPE_UNKNOWN,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_VOID
} Type;


typedef enum {
    NODE_FUNCTION,
    NODE_DECL,
    NODE_BLOCK,
    NODE_EXPR,
    NODE_ASSIGN,
    NODE_IF,
    NODE_WHILE,
    NODE_FOR,
    NODE_RETURN,
    NODE_VAR,
    NODE_NUM,
    NODE_FLOAT,
    NODE_CHAR,
    NODE_STRING,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_CALL,
    NODE_ADDR     
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
    OperatorType op;

    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *middle;
    struct ASTNode *next;

    char *name;
    int value;
    float float_value;
    char char_value;

    Type data_type;
    
    int is_address;    
    char *place;      
} ASTNode;


ASTNode* make_node(NodeType type, ASTNode *left, ASTNode *right);
ASTNode* make_expr(OperatorType op, ASTNode *left, ASTNode *right);
ASTNode* make_assign(ASTNode *left, ASTNode *right);

ASTNode* make_var(char *name);
ASTNode* make_num(int value);
ASTNode* make_float(float value);
ASTNode* make_char(char value);
ASTNode* make_string(char *str);

ASTNode* make_if(ASTNode *cond, ASTNode *then_branch, ASTNode *else_branch);
ASTNode* make_while(ASTNode *cond, ASTNode *body);
ASTNode* make_for(ASTNode *init, ASTNode *cond, ASTNode *incr, ASTNode *body);
ASTNode* make_return(ASTNode *expr);
ASTNode* make_block(ASTNode *stmts);

ASTNode* make_break();
ASTNode* make_continue();
ASTNode* make_call(char *name, ASTNode *args);
ASTNode* make_addr(ASTNode *var);   
ASTNode* make_type_node(Type type);


void print_ast(ASTNode *node, int indent);

#endif 
