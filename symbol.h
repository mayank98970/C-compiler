#ifndef SYMBOL_H
#define SYMBOL_H

#include "ast.h"  // Includes Type and ASTNode definitions

// ============================
// SYMBOL TYPES AND STRUCTURES
// ============================

typedef enum {
    SYMBOL_VARIABLE,
    SYMBOL_FUNCTION
} SymbolType;

typedef struct Symbol {
    char *name;                 // Variable or function name
    SymbolType sym_type;        // VARIABLE or FUNCTION
    Type data_type;             // <-- ADDED: int, float, char, string, etc.
    struct ASTNode *declaration;
    struct Symbol *next;
} Symbol;

// Scope for managing nested symbol tables
typedef struct Scope {
    Symbol *symbols;
    struct Scope *next;
} Scope;

// =======================
// GLOBAL DECLARATIONS
// =======================

extern Scope *scope_stack;
extern int semantic_error_count;  // Global count of semantic errors

// =======================
// SCOPE MANAGEMENT
// =======================

void enter_scope();      // Push a new scope
void exit_scope();       // Pop the current scope

// ========================
// SYMBOL TABLE MANAGEMENT
// ========================

void insert_symbol(const char *name, SymbolType type, Type data_type, ASTNode *decl); // <-- updated
Symbol* lookup_symbol(const char *name);         // Look in all scopes
Symbol* lookup_symbol_in_current_scope(const char *name); // Look only in top scope

// =========================
// SEMANTIC CHECK UTILITIES
// =========================

void check_variable_declared(const char *name);
void check_function_declared(const char *name);
Type get_symbol_type(const char *name);          // <-- NEW: Get the data type of a symbol

void perform_semantic_analysis(ASTNode *root);
void free_symbol_table();  // Optional cleanup after parsing

#endif // SYMBOL_H
