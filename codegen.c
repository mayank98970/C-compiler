#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "codegen.h"

int temp_count = 0;
int label_count = 0;
static FILE *tac_out = NULL;
char* new_temp() {
    char *name = (char*)malloc(16);
    sprintf(name, "t%d", temp_count++);
    return name;
}

char* new_label() {
    char *label = (char*)malloc(16);
    sprintf(label, "L%d", label_count++);
    return label;
}

#define MAX_LOOP_DEPTH 100
char *break_stack[MAX_LOOP_DEPTH];
char *continue_stack[MAX_LOOP_DEPTH];
int loop_top = -1;

void push_loop_labels(char *break_label, char *continue_label) {
    if (++loop_top >= MAX_LOOP_DEPTH) {
        fprintf(stderr, "Loop nesting too deep!\n");
        exit(1);
    }
    break_stack[loop_top] = break_label;
    continue_stack[loop_top] = continue_label;
}

void pop_loop_labels() {
    if (loop_top >= 0) loop_top--;
}

char* current_break_label() {
    return loop_top >= 0 ? break_stack[loop_top] : NULL;
}

char* current_continue_label() {
    return loop_top >= 0 ? continue_stack[loop_top] : NULL;
}

char* eval(ASTNode *node) {
    if (!node) return NULL;

    switch (node->type) {
        case NODE_NUM: {
            char *t = new_temp();
            fprintf(tac_out, "%s = %d\n", t, node->value);
            return t;
        }
        case NODE_FLOAT: {
            char *t = new_temp();
            fprintf(tac_out, "%s = %f\n", t, node->float_value);
            return t;
        }
        case NODE_CHAR: {
            char *t = new_temp();
            fprintf(tac_out, "%s = '%c'\n", t, node->char_value);
            return t;
        }
        case NODE_STRING: {
            char *t = new_temp();
            fprintf(tac_out, "%s = \"%s\"\n", t, node->name);
            return t;
        }
        case NODE_VAR: {
            if (node->is_address) {
                char *t = new_temp();
                fprintf(tac_out, "%s = &%s\n", t, node->name);
                return t;
            }
            return node->name;
        }
        case NODE_EXPR: {
            char *left = eval(node->left);
            char *right = eval(node->right);
            char *t = new_temp();

            const char *op;
            switch (node->op) {
                case OP_ADD: op = "+"; break;
                case OP_SUB: op = "-"; break;
                case OP_MUL: op = "*"; break;
                case OP_DIV: op = "/"; break;
                case OP_EQ:  op = "=="; break;
                case OP_NEQ: op = "!="; break;
                case OP_GT:  op = ">"; break;
                case OP_LT:  op = "<"; break;
                case OP_GTE: op = ">="; break;
                case OP_LTE: op = "<="; break;
                default:     op = "??"; break;
            }

            fprintf(tac_out, "%s = %s %s %s\n", t, left, op, right);
            return t;
        }
        case NODE_ASSIGN: {
            char *rhs = eval(node->right);
            fprintf(tac_out, "%s = %s\n", node->left->name, rhs);
            return node->left->name;
        }
        case NODE_CALL: {
            ASTNode *arg = node->left;
            while (arg) {
                char *val = eval(arg);
                if (strcmp(node->name, "scanf") == 0 && arg->type == NODE_VAR && !arg->is_address)
                    fprintf(tac_out, "param &%s\n", val);
                else
                    fprintf(tac_out, "param %s\n", val);
                arg = arg->next;
            }

            char *ret = new_temp();
            fprintf(tac_out, "%s = call %s\n", ret, node->name);
            return ret;
        }

        default:
            return NULL;
    }
}

void gen(ASTNode *node) {
    if (!node) return;

    switch (node->type) {
        case NODE_FUNCTION:
            fprintf(tac_out, "\nFunction %s:\n", node->name);
            gen(node->right);
            break;

        case NODE_BLOCK:
            gen(node->left);
            break;

        case NODE_DECL:
            break;

        case NODE_ASSIGN:
        case NODE_EXPR:
        case NODE_CALL:
            eval(node);
            break;

        case NODE_IF: {
            char *cond = eval(node->left);
            char *else_lbl = new_label();
            char *end_lbl = new_label();

            fprintf(tac_out, "ifFalse %s goto %s\n", cond, else_lbl);
            gen(node->right);
            fprintf(tac_out, "goto %s\n", end_lbl);
            fprintf(tac_out, "%s:\n", else_lbl);
            gen(node->next);
            fprintf(tac_out, "%s:\n", end_lbl);
            break;
        }

        case NODE_WHILE: {
            char *start = new_label();
            char *end = new_label();

            push_loop_labels(end, start);
            fprintf(tac_out, "%s:\n", start);
            char *cond = eval(node->left);
            fprintf(tac_out, "ifFalse %s goto %s\n", cond, end);
            gen(node->right);
            fprintf(tac_out, "goto %s\n", start);
            fprintf(tac_out, "%s:\n", end);
            pop_loop_labels();
            break;
        }

        case NODE_FOR: {
            gen(node->left);
            char *start = new_label();
            char *end = new_label();
            char *cont = new_label();

            push_loop_labels(end, cont);
            fprintf(tac_out, "%s:\n", start);
            char *cond = eval(node->middle);
            fprintf(tac_out, "ifFalse %s goto %s\n", cond, end);
            gen(node->right);
            fprintf(tac_out, "%s:\n", cont);
            gen(node->right->next);
            fprintf(tac_out, "goto %s\n", start);
            fprintf(tac_out, "%s:\n", end);
            pop_loop_labels();
            break;
        }

        case NODE_BREAK:
            fprintf(tac_out, "goto %s\n", current_break_label());
            break;

        case NODE_CONTINUE:
            fprintf(tac_out, "goto %s\n", current_continue_label());
            break;

        case NODE_RETURN: {
            char *retval = eval(node->left);
            fprintf(tac_out, "return %s\n", retval);
            break;
        }

        default:
            break;
    }

    if (node->next)
        gen(node->next);
}

// Entry function with GUI-friendly file output
void generate_code(ASTNode *root, FILE *out) {
    tac_out = out;
    fprintf(tac_out, "# Intermediate Code (TAC)\n");
    gen(root);
    fflush(tac_out);
}
