#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"

typedef enum {
    SYMBOL_VARIABLE,
    SYMBOL_FUNCTION
} SymbolType;


typedef struct Symbol {
    char *name;
    SymbolType sym_type;       
    Type data_type;             
    ASTNode *declaration;      
    struct Symbol *next;
} Symbol;



typedef struct Scope {
    Symbol *symbols;
    struct Scope *next;
} Scope;

extern Scope *scope_stack;
extern int semantic_error_count;


void enter_scope();            
void exit_scope();              

void insert_symbol(const char *name, SymbolType sym_type, Type data_type, ASTNode *decl);
Symbol* lookup_symbol(const char *name);
Symbol* lookup_symbol_in_current_scope(const char *name);


void check_variable_declared(const char *name);
void check_function_declared(const char *name);


Type infer_expression_type(ASTNode *node);


void perform_semantic_analysis(ASTNode *root);
void free_symbol_table(); 

#endif // SEMANTIC_H
