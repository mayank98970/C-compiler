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

    Symbol *sym = scope_stack->symbols;
    while (sym) {
        Symbol *next = sym->next;
        free(sym->name);
        free(sym);
        sym = next;
    }

    Scope *prev = scope_stack;
    scope_stack = scope_stack->next;
    free(prev);
}


void insert_symbol(const char *name, SymbolType sym_type, Type data_type, ASTNode *decl) {
    if (lookup_symbol_in_current_scope(name)) {
        fprintf(stderr, "Semantic Error: Symbol '%s' already declared in this scope.\n", name);
        semantic_error_count++;
        return;
    }

    Symbol *sym = (Symbol *)malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->sym_type = sym_type;
    sym->data_type = data_type;
    sym->declaration = decl;
    sym->next = scope_stack->symbols;
    scope_stack->symbols = sym;
}

Symbol* lookup_symbol(const char *name) {
    for (Scope *scope = scope_stack; scope != NULL; scope = scope->next) {
        for (Symbol *sym = scope->symbols; sym != NULL; sym = sym->next) {
            if (strcmp(sym->name, name) == 0)
                return sym;
        }
    }
    return NULL;
}

Symbol* lookup_symbol_in_current_scope(const char *name) {
    if (!scope_stack) return NULL;

    for (Symbol *sym = scope_stack->symbols; sym != NULL; sym = sym->next) {
        if (strcmp(sym->name, name) == 0)
            return sym;
    }
    return NULL;
}


Type get_symbol_type(const char *name) {
    Symbol *sym = lookup_symbol(name);
    if (sym) return sym->data_type;
    return TYPE_UNKNOWN;
}


void check_variable_declared(const char *name) {
    Symbol *sym = lookup_symbol(name);
    if (!sym || sym->sym_type != SYMBOL_VARIABLE) {
        fprintf(stderr, "Semantic Error: Variable '%s' not declared before use.\n", name);
        semantic_error_count++;
    }
}

void check_function_declared(const char *name) {
    Symbol *sym = lookup_symbol(name);
    if (!sym || sym->sym_type != SYMBOL_FUNCTION) {
        fprintf(stderr, "Semantic Error: Function '%s' not declared.\n", name);
        semantic_error_count++;
    }
}



void perform_semantic_analysis(ASTNode *node) {
    while (node) {
        switch (node->type) {
            case NODE_FUNCTION:
                insert_symbol(node->name, SYMBOL_FUNCTION, TYPE_VOID, node); // TODO: pass correct return type
                enter_scope();
                perform_semantic_analysis(node->left);   // parameters
                perform_semantic_analysis(node->right);  // body
                exit_scope();
                break;

            case NODE_BLOCK:
                enter_scope();
                perform_semantic_analysis(node->left);
                exit_scope();
                break;

            case NODE_DECL:
                insert_symbol(node->name, SYMBOL_VARIABLE, node->data_type, node);
                break;

            case NODE_ASSIGN:
                check_variable_declared(node->left->name);
                perform_semantic_analysis(node->right);
                break;

            case NODE_VAR:
                check_variable_declared(node->name);
                break;

            case NODE_CALL:
                check_function_declared(node->name);
                perform_semantic_analysis(node->left); // arguments
                break;

            case NODE_EXPR:
                perform_semantic_analysis(node->left);
                perform_semantic_analysis(node->right);
                break;

            case NODE_IF:
                perform_semantic_analysis(node->left);   // condition
                perform_semantic_analysis(node->right);  // then
                if (node->next)
                    perform_semantic_analysis(node->next); // else
                break;

            case NODE_WHILE:
                perform_semantic_analysis(node->left);   // condition
                perform_semantic_analysis(node->right);  // body
                break;

            case NODE_RETURN:
                perform_semantic_analysis(node->left);
                break;

            default:
                break;
        }

        if (node->type != NODE_IF)
            node = node->next;
        else
            break;
    }

    if (semantic_error_count > 0) {
        fprintf(stderr, "\nTotal Semantic Errors: %d\n", semantic_error_count);
        exit(1);
    }
}


void free_symbol_table() {
    while (scope_stack) exit_scope();
}
