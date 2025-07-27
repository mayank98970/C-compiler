#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// -------------------------------
// Node Constructors
// -------------------------------

ASTNode* make_node(NodeType type, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->op = OP_NONE;
    node->left = left;
    node->right = right;
    node->middle = NULL;
    node->next = NULL;
    node->name = NULL;
    node->value = 0;
    node->float_value = 0.0f;
    node->char_value = '\0';
    node->data_type = TYPE_UNKNOWN;
    node->place = NULL;
    node->is_address = 0;
    return node;
}

ASTNode* make_type_node(Type type) {
    ASTNode *node = make_node(NODE_DECL, NULL, NULL);
    node->data_type = type;
    return node;
}

ASTNode* make_expr(OperatorType op, ASTNode *left, ASTNode *right) {
    ASTNode *node = make_node(NODE_EXPR, left, right);
    node->op = op;
    if (left && right) {
        if (left->data_type == TYPE_INT && right->data_type == TYPE_INT)
            node->data_type = TYPE_INT;
        else if (left->data_type == TYPE_FLOAT || right->data_type == TYPE_FLOAT)
            node->data_type = TYPE_FLOAT;
    }
    return node;
}

ASTNode* make_assign(ASTNode *left, ASTNode *right) {
    ASTNode *node = make_node(NODE_ASSIGN, left, right);
    node->op = OP_ASSIGN;
    if (right) node->data_type = right->data_type;
    return node;
}

ASTNode* make_address_of(ASTNode* var) {
    ASTNode* node = make_node(NODE_ADDR, var, NULL);
    return node;
}

// -------------------------------
// Literals and Variables
// -------------------------------

ASTNode* make_var(char *name) {
    ASTNode *node = make_node(NODE_VAR, NULL, NULL);
    node->name = strdup(name);
    return node;
}

ASTNode* make_num(int value) {
    ASTNode *node = make_node(NODE_NUM, NULL, NULL);
    node->value = value;
    node->data_type = TYPE_INT;
    return node;
}

ASTNode* make_float(float value) {
    ASTNode *node = make_node(NODE_FLOAT, NULL, NULL);
    node->float_value = value;
    node->data_type = TYPE_FLOAT;
    return node;
}

ASTNode* make_char(char value) {
    ASTNode *node = make_node(NODE_CHAR, NULL, NULL);
    node->char_value = value;
    node->data_type = TYPE_CHAR;
    return node;
}

ASTNode* make_string(char *str) {
    ASTNode *node = make_node(NODE_STRING, NULL, NULL);
    node->name = strdup(str);
    node->data_type = TYPE_STRING;
    return node;
}

// -------------------------------
// Control Flow & Other
// -------------------------------

ASTNode* make_if(ASTNode *cond, ASTNode *then_branch, ASTNode *else_branch) {
    ASTNode *node = make_node(NODE_IF, cond, then_branch);
    node->next = else_branch;
    return node;
}

ASTNode* make_while(ASTNode *cond, ASTNode *body) {
    return make_node(NODE_WHILE, cond, body);
}

ASTNode* make_for(ASTNode *init, ASTNode *cond, ASTNode *incr, ASTNode *body) {
    ASTNode *block = make_block(body);
    ASTNode *while_loop = make_while(cond, block);

    if (body) {
        ASTNode *last = body;
        while (last->next) last = last->next;
        last->next = incr;
    } else {
        block->left = incr;
    }

    init->next = while_loop;
    return make_block(init);
}

ASTNode* make_return(ASTNode *expr) {
    ASTNode *node = make_node(NODE_RETURN, expr, NULL);
    if (expr) node->data_type = expr->data_type;
    return node;
}

ASTNode* make_block(ASTNode *stmts) {
    return make_node(NODE_BLOCK, stmts, NULL);
}

ASTNode* make_break() {
    return make_node(NODE_BREAK, NULL, NULL);
}

ASTNode* make_continue() {
    return make_node(NODE_CONTINUE, NULL, NULL);
}

ASTNode* make_call(char *name, ASTNode *args) {
    ASTNode *node = make_node(NODE_CALL, args, NULL);
    node->name = strdup(name);
    return node;
}

// -------------------------------
// Debug Printer
// -------------------------------

void print_ast(ASTNode *node, int indent) {
    while (node) {
        for (int i = 0; i < indent; i++) printf("  ");

        switch (node->type) {
            case NODE_FUNCTION:
                printf("Function: %s\n", node->name ? node->name : "(null)");
                print_ast(node->left, indent + 1);
                print_ast(node->right, indent + 1);
                break;

            case NODE_DECL:
                printf("Declaration: %s (type=%d)\n", node->name ? node->name : "(null)", node->data_type);
                break;

            case NODE_BLOCK:
                printf("Block:\n");
                print_ast(node->left, indent + 1);
                break;

            case NODE_EXPR:
                printf("Expression: ");
                switch (node->op) {
                    case OP_ADD: printf("+\n"); break;
                    case OP_SUB: printf("-\n"); break;
                    case OP_MUL: printf("*\n"); break;
                    case OP_DIV: printf("/\n"); break;
                    case OP_EQ:  printf("==\n"); break;
                    case OP_NEQ: printf("!=\n"); break;
                    case OP_GT:  printf(">\n"); break;
                    case OP_LT:  printf("<\n"); break;
                    case OP_GTE: printf(">=\n"); break;
                    case OP_LTE: printf("<=\n"); break;
                    default:     printf("(unknown)\n"); break;
                }
                print_ast(node->left, indent + 1);
                print_ast(node->right, indent + 1);
                break;

            case NODE_ASSIGN:
                printf("Assignment:\n");
                print_ast(node->left, indent + 1);
                print_ast(node->right, indent + 1);
                break;

            case NODE_IF:
                printf("If:\n");
                print_ast(node->left, indent + 1);
                print_ast(node->right, indent + 1);
                if (node->next) {
                    for (int i = 0; i < indent; i++) printf("  ");
                    printf("Else:\n");
                    print_ast(node->next, indent + 1);
                }
                break;

            case NODE_WHILE:
                printf("While:\n");
                print_ast(node->left, indent + 1);
                print_ast(node->right, indent + 1);
                break;

            case NODE_RETURN:
                printf("Return:\n");
                print_ast(node->left, indent + 1);
                break;

            case NODE_VAR:
                printf("Variable: %s\n", node->name ? node->name : "(null)");
                break;

            case NODE_NUM:
                printf("Number: %d\n", node->value);
                break;

            case NODE_FLOAT:
                printf("Float: %f\n", node->float_value);
                break;

            case NODE_CHAR:
                printf("Char: '%c'\n", node->char_value);
                break;

            case NODE_STRING:
                printf("String: \"%s\"\n", node->name ? node->name : "(null)");
                break;

            case NODE_BREAK:
                printf("Break\n");
                break;

            case NODE_CONTINUE:
                printf("Continue\n");
                break;

            case NODE_CALL:
                printf("Function Call: %s\n", node->name);
                print_ast(node->left, indent + 1);
                break;

            default:
                printf("Unknown node type\n");
                break;
        }

        if (node->type != NODE_IF)
            node = node->next;
        else
            break;
    }
}
