#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "ast.h"

Scope *scope_stack = NULL;
int semantic_error_count = 0;

void enter_scope() {
    Scope *new_scope = (Scope *)malloc(sizeof(Scope));
    new_scope->symbols = NULL;
    new_scope->next = scope_stack;
    scope_stack = new_scope;
}

void exit_scope() {
    if (!scope_stack) return;
    Symbol *curr = scope_stack->symbols;
    while (curr) {
        Symbol *next = curr->next;
        free(curr->name);
        free(curr);
        curr = next;
    }
    Scope *old = scope_stack;
    scope_stack = scope_stack->next;
    free(old);
}

void insert_symbol(const char *name, SymbolType sym_type, Type data_type, ASTNode *decl) {
    if (!scope_stack) return;
    if (lookup_symbol_in_current_scope(name)) {
        fprintf(stderr, "Semantic Error: Symbol '%s' already declared in this scope.\n", name);
        semantic_error_count++;
        return;
    }

    Symbol *s = (Symbol *)malloc(sizeof(Symbol));
    s->name = strdup(name);
    s->sym_type = sym_type;
    s->data_type = data_type;
    s->declaration = decl;
    s->next = scope_stack->symbols;
    scope_stack->symbols = s;
}

Symbol* lookup_symbol(const char *name) {
    for (Scope *s = scope_stack; s; s = s->next) {
        for (Symbol *sym = s->symbols; sym; sym = sym->next) {
            if (strcmp(sym->name, name) == 0) return sym;
        }
    }
    return NULL;
}

Symbol* lookup_symbol_in_current_scope(const char *name) {
    if (!scope_stack) return NULL;
    for (Symbol *sym = scope_stack->symbols; sym; sym = sym->next) {
        if (strcmp(sym->name, name) == 0) return sym;
    }
    return NULL;
}

Type infer_expression_type(ASTNode *node) {
    if (!node) return TYPE_UNKNOWN;

    switch (node->type) {
        case NODE_NUM:    return TYPE_INT;
        case NODE_FLOAT:  return TYPE_FLOAT;
        case NODE_CHAR:   return TYPE_CHAR;
        case NODE_STRING: return TYPE_STRING;
        case NODE_VAR: {
            if (!node->name) return TYPE_UNKNOWN;
            Symbol *sym = lookup_symbol(node->name);
            return sym ? sym->data_type : TYPE_UNKNOWN;
        }
        case NODE_EXPR: {
            Type lt = infer_expression_type(node->left);
            Type rt = infer_expression_type(node->right);
            if (lt == rt) return lt;
            if ((lt == TYPE_INT && rt == TYPE_FLOAT) || (lt == TYPE_FLOAT && rt == TYPE_INT))
                return TYPE_FLOAT;
            fprintf(stderr, "Type Error: Mismatched types in expression (%d, %d)\n", lt, rt);
            semantic_error_count++;
            return TYPE_UNKNOWN;
        }
        default:
            return TYPE_UNKNOWN;
    }
}

void check_variable_declared(const char *name) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->sym_type != SYMBOL_VARIABLE) {
        fprintf(stderr, "Semantic Error: Variable '%s' not declared.\n", name);
        semantic_error_count++;
    }
}

void check_function_declared(const char *name) {
    Symbol *s = lookup_symbol(name);
    if (!s || s->sym_type != SYMBOL_FUNCTION) {
        fprintf(stderr, "Semantic Error: Function '%s' not declared.\n", name);
        semantic_error_count++;
    }
}

void analyze_node(ASTNode *node) {
    while (node) {
        switch (node->type) {
            case NODE_FUNCTION:
                insert_symbol(node->name, SYMBOL_FUNCTION, TYPE_VOID, node);
                enter_scope();
                analyze_node(node->left);   // parameters
                analyze_node(node->right);  // body
                exit_scope();
                break;

            case NODE_DECL:
                insert_symbol(node->name, SYMBOL_VARIABLE, node->data_type, node);
                break;

            case NODE_ASSIGN:
                if (node->left && node->left->name)
                    check_variable_declared(node->left->name);
                if (node->right)
                    analyze_node(node->right);
                node->data_type = infer_expression_type(node->right);

                if (node->left && node->left->name) {
                    Symbol *sym = lookup_symbol(node->left->name);
                    if (sym && sym->data_type != TYPE_UNKNOWN && node->data_type != sym->data_type) {
                        fprintf(stderr, "Type Error: Cannot assign type %d to variable '%s' of type %d.\n",
                                node->data_type, node->left->name, sym->data_type);
                        semantic_error_count++;
                    }
                }
                break;

            case NODE_VAR:
                if (node->name)
                    check_variable_declared(node->name);
                node->data_type = infer_expression_type(node);
                break;

            case NODE_NUM:    node->data_type = TYPE_INT; break;
            case NODE_FLOAT:  node->data_type = TYPE_FLOAT; break;
            case NODE_CHAR:   node->data_type = TYPE_CHAR; break;
            case NODE_STRING: node->data_type = TYPE_STRING; break;

            case NODE_EXPR:
                analyze_node(node->left);
                analyze_node(node->right);
                node->data_type = infer_expression_type(node);
                break;

            case NODE_IF:
                analyze_node(node->left);   // condition
                analyze_node(node->right);  // then
                if (node->next)
                    analyze_node(node->next); // else
                break;

            case NODE_WHILE:
                analyze_node(node->left);   // condition
                analyze_node(node->right);  // body
                break;

            case NODE_FOR:
                analyze_node(node->left);     // init
                analyze_node(node->middle);   // condition
                analyze_node(node->right);    // body
                break;

            case NODE_RETURN:
                analyze_node(node->left);
                break;

            case NODE_BLOCK:
                enter_scope();
                analyze_node(node->left);
                exit_scope();
                break;

            case NODE_CALL:
                check_function_declared(node->name);
                analyze_node(node->left);   // arguments
                break;

            case NODE_CONTINUE:
            case NODE_BREAK:
                break;

            default:
                break;
        }

        if (node->type != NODE_IF)  // skip .next for if-else (already handled)
            node = node->next;
        else
            break;
    }
}

void perform_semantic_analysis(ASTNode *root) {
    insert_symbol("printf", SYMBOL_FUNCTION, TYPE_INT, NULL);
    insert_symbol("scanf", SYMBOL_FUNCTION, TYPE_INT, NULL);

    enter_scope();  // global scope
    analyze_node(root);
    exit_scope();

    if (semantic_error_count > 0) {
        fprintf(stderr, "\nTotal Semantic Errors: %d\n", semantic_error_count);
        exit(1);
    }
}
