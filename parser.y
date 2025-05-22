%code requires {
    #include "ast.h"
}

%union {
    int num;
    char *str;
    ASTNode *node;
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode *root;
extern int yylex();
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }
%}

%token <str> IDENTIFIER
%token <num> NUMBER
%token IF ELSE INT RETURN VOID WHILE
%token EQ NEQ GT LT GTE LTE
%type <node> program functions function type params param_list param
%type <node> compound_stmt stmts stmt decl_stmt expr_stmt if_stmt while_stmt return_stmt expression

%left '+' '-'
%left '*' '/'
%left EQ NEQ GT LT GTE LTE
%right '='

%%

program:
    functions { root = $1; print_ast(root, 0); }
    ;

functions:
    functions function { $$ = $1; $1->next = $2; }
    | function { $$ = $1; }
    ;

function:
    type IDENTIFIER '(' params ')' compound_stmt {
        $$ = make_node(NODE_FUNCTION, $4, $6);
        $$->name = $2;
    }
    ;

type:
    INT { $$ = NULL; }
    | VOID { $$ = NULL; }
    ;

params:
    /* empty */ { $$ = NULL; }
    | param_list { $$ = $1; }
    ;

param_list:
    param_list ',' param { $$ = $1; $1->next = $3; }
    | param { $$ = $1; }
    ;

param:
    type IDENTIFIER {
        $$ = make_node(NODE_DECL, NULL, NULL);
        $$->name = $2;
    }
    ;

compound_stmt:
    '{' stmts '}' { $$ = make_block($2); }
    ;

// *** FIXED stmts rule ***
stmts:
    stmts stmt {
        $$ = $1;
        if ($1) {
            ASTNode *last = $1;
            while (last->next) last = last->next;
            last->next = $2;
        } else {
            $$ = $2;
        }
    }
    | stmt { $$ = $1; }
    | /* empty */ { $$ = NULL; }
    ;

stmt:
    expr_stmt { $$ = $1; }
    | decl_stmt { $$ = $1; }
    | if_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | return_stmt { $$ = $1; }
    | compound_stmt { $$ = $1; }
    ;

decl_stmt:
    type IDENTIFIER ';' {
        $$ = make_node(NODE_DECL, NULL, NULL);
        $$->name = $2;
    }
    ;

expr_stmt:
    expression ';' { $$ = $1; }
    ;

if_stmt:
    IF '(' expression ')' stmt ELSE stmt {
        $$ = make_if($3, $5, $7);
    }
    | IF '(' expression ')' stmt {
        $$ = make_if($3, $5, NULL);
    }
    ;

while_stmt:
    WHILE '(' expression ')' stmt {
        $$ = make_while($3, $5);
    }
    ;

return_stmt:
    RETURN expression ';' {
        $$ = make_return($2);
    }
    ;

expression:
    IDENTIFIER '=' expression {
        $$ = make_assign(make_var($1), $3);
    }
    | expression '+' expression { $$ = make_expr(OP_ADD, $1, $3); }
    | expression '-' expression { $$ = make_expr(OP_SUB, $1, $3); }
    | expression '*' expression { $$ = make_expr(OP_MUL, $1, $3); }
    | expression '/' expression { $$ = make_expr(OP_DIV, $1, $3); }
    | expression EQ expression  { $$ = make_expr(OP_EQ,  $1, $3); }
    | expression NEQ expression { $$ = make_expr(OP_NEQ, $1, $3); }
    | expression GT expression  { $$ = make_expr(OP_GT,  $1, $3); }
    | expression LT expression  { $$ = make_expr(OP_LT,  $1, $3); }
    | expression GTE expression { $$ = make_expr(OP_GTE, $1, $3); }
    | expression LTE expression { $$ = make_expr(OP_LTE, $1, $3); }
    | '(' expression ')' { $$ = $2; }
    | IDENTIFIER { $$ = make_var($1); }
    | NUMBER { $$ = make_num($1); }
    ;

%%

int main() {
    printf("Parsing...\n");
    yyparse();
    return 0;
}
