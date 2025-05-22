#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode* make_node(NodeType type, ASTNode *left, ASTNode *right) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = type;
    node->op = OP_NONE;
    node->left = left;
    node->right = right;
    node->next = NULL;
    node->name = NULL;
    node->value = 0;
    return node;
}

ASTNode* make_expr(OperatorType op, ASTNode *left, ASTNode *right) {
    ASTNode *node = make_node(NODE_EXPR, left, right);
    node->op = op;
    return node;
}

ASTNode* make_assign(ASTNode *left, ASTNode *right) {
    ASTNode *node = make_node(NODE_ASSIGN, left, right);
    node->op = OP_ASSIGN;
    return node;
}

ASTNode* make_var(char *name) {
    ASTNode *node = make_node(NODE_VAR, NULL, NULL);
    node->name = strdup(name);
    return node;
}

ASTNode* make_num(int value) {
    ASTNode *node = make_node(NODE_NUM, NULL, NULL);
    node->value = value;
    return node;
}

ASTNode* make_if(ASTNode *cond, ASTNode *then_branch, ASTNode *else_branch) {
    ASTNode *node = make_node(NODE_IF, cond, then_branch);
    node->next = else_branch;
    return node;
}

ASTNode* make_while(ASTNode *cond, ASTNode *body) {
    return make_node(NODE_WHILE, cond, body);
}

ASTNode* make_return(ASTNode *expr) {
    return make_node(NODE_RETURN, expr, NULL);
}

ASTNode* make_block(ASTNode *stmts) {
    return make_node(NODE_BLOCK, stmts, NULL);
}

void print_ast(ASTNode *node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++) printf("  ");

    switch (node->type) {
        case NODE_FUNCTION:
            printf("Function: %s\n", node->name ? node->name : "(null)");
            print_ast(node->left, indent + 1);   // params
            print_ast(node->right, indent + 1);  // body
            break;

        case NODE_DECL:
            printf("Declaration: %s\n", node->name ? node->name : "(null)");
            break;

        case NODE_BLOCK:
            printf("Block:\n");
            print_ast(node->left, indent + 1);  // print statements inside block
            break;

        case NODE_EXPR:
            switch (node->op) {
                case OP_ADD: printf("Expression: +\n"); break;
                case OP_SUB: printf("Expression: -\n"); break;
                case OP_MUL: printf("Expression: *\n"); break;
                case OP_DIV: printf("Expression: /\n"); break;
                case OP_EQ:  printf("Expression: ==\n"); break;
                case OP_NEQ: printf("Expression: !=\n"); break;
                case OP_GT:  printf("Expression: >\n"); break;
                case OP_LT:  printf("Expression: <\n"); break;
                case OP_GTE: printf("Expression: >=\n"); break;
                case OP_LTE: printf("Expression: <=\n"); break;
                default:     printf("Expression\n"); break;
            }
            print_ast(node->left, indent + 1);
            print_ast(node->right, indent + 1);
            break;

        case NODE_ASSIGN:
            printf("Assignment\n");
            print_ast(node->left, indent + 1);
            print_ast(node->right, indent + 1);
            break;

        case NODE_IF:
            printf("If\n");
            print_ast(node->left, indent + 1);    // condition
            print_ast(node->right, indent + 1);   // then branch
            if (node->next) {
                for (int i = 0; i < indent; i++) printf("  ");
                printf("Else\n");
                print_ast(node->next, indent + 1); // else branch
            }
            break;

        case NODE_WHILE:
            printf("While\n");
            print_ast(node->left, indent + 1);    // condition
            print_ast(node->right, indent + 1);   // body
            break;

        case NODE_RETURN:
            printf("Return\n");
            print_ast(node->left, indent + 1);
            break;

        case NODE_VAR:
            printf("Variable: %s\n", node->name ? node->name : "(null)");
            break;

        case NODE_NUM:
            printf("Number: %d\n", node->value);
            break;

        default:
            printf("Unknown node type\n");
            break;
    }

    // Now print siblings at the same level
    // For IF nodes: don't print node->next again because it is else branch handled above
    if (node->type != NODE_IF) {
        print_ast(node->next, indent);
    }
}
