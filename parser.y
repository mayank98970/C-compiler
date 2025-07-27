%code requires {
    #include "ast.h"
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "optimize.h" 
#include "ast.h"
#include "semantic.h"
#include "codegen.h"
#include "targetgen.h"

extern int yylex();
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }

ASTNode *root;
%}

%union {
    int num;
    float fnum;
    char cval;
    char *str;
    ASTNode *node;
}

%token <str> IDENTIFIER STRING
%token <num> NUMBER
%token <fnum> FLOAT_LITERAL
%token <cval> CHAR_LITERAL

%token IF ELSE INT VOID FLOAT CHAR RETURN WHILE FOR BREAK CONTINUE SCANF PRINTF
%token EQ NEQ GT LT GTE LTE

%type <node> program functions function compound_stmt stmts stmt
%type <node> decl_stmt expr_stmt if_stmt while_stmt for_stmt return_stmt
%type <node> expression assignment_expression logical_expression
%type <node> args arg_list params param_list param type enter_scope_marker
%type <node> for_init for_cond for_incr

%left '+' '-'
%left '*' '/'
%nonassoc EQ NEQ GT LT GTE LTE
%right '='
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program:
    functions { root = $1; }
;

functions:
    functions function {
        ASTNode *last = $1;
        while (last->next) last = last->next;
        last->next = $2;
        $$ = $1;
    }
  | function { $$ = $1; }
;

function:
    type IDENTIFIER '(' params ')' enter_scope_marker compound_stmt {
        $$ = make_node(NODE_FUNCTION, $4, $7);
        $$->name = $2;
    }
;

enter_scope_marker:
    /* empty */ { enter_scope(); $$ = NULL; }
;

type:
    INT    { $$ = make_type_node(TYPE_INT); }
  | VOID   { $$ = make_type_node(TYPE_VOID); }
  | FLOAT  { $$ = make_type_node(TYPE_FLOAT); }
  | CHAR   { $$ = make_type_node(TYPE_CHAR); }
;

params:
    /* empty */ { $$ = NULL; }
  | param_list { $$ = $1; }
;

param_list:
    param_list ',' param {
        ASTNode *last = $1;
        while (last->next) last = last->next;
        last->next = $3;
        $$ = $1;
    }
  | param { $$ = $1; }
;

param:
    type IDENTIFIER {
        $$ = make_node(NODE_DECL, NULL, NULL);
        $$->name = $2;
        $$->data_type = $1->data_type;
        insert_symbol($2, SYMBOL_VARIABLE, $1->data_type, $$);
    }
;

compound_stmt:
    '{' { enter_scope(); } stmts '}' {
        $$ = make_block($3);
        exit_scope();
    }
;

stmts:
    /* empty */ { $$ = NULL; }
  | stmt stmts {
        $$ = $1;
        ASTNode *last = $1;
        while (last && last->next) last = last->next;
        if (last) last->next = $2;
        else $$ = $2;
    }
;

stmt:
    decl_stmt      { $$ = $1; }
  | expr_stmt      { $$ = $1; }
  | if_stmt        { $$ = $1; }
  | while_stmt     { $$ = $1; }
  | for_stmt       { $$ = $1; }
  | return_stmt    { $$ = $1; }
  | compound_stmt  { $$ = $1; }
  | BREAK ';'      { $$ = make_node(NODE_BREAK, NULL, NULL); }
  | CONTINUE ';'   { $$ = make_node(NODE_CONTINUE, NULL, NULL); }

  | PRINTF '(' STRING args ')' ';' {
        ASTNode *str = make_string($3);
        if ($4) str->next = $4;
        $$ = make_call("printf", str);
    }

  | SCANF '(' STRING ',' arg_list ')' ';' {
        ASTNode *str = make_string($3);
        str->next = $5;
        $$ = make_call("scanf", str);
    }
;

decl_stmt:
    type IDENTIFIER ';' {
        $$ = make_node(NODE_DECL, NULL, NULL);
        $$->name = $2;
        $$->data_type = $1->data_type;
        insert_symbol($2, SYMBOL_VARIABLE, $1->data_type, $$);
    }
  | type IDENTIFIER '=' assignment_expression ';' {
        ASTNode *decl = make_node(NODE_DECL, NULL, NULL);
        decl->name = $2;
        decl->data_type = $1->data_type;
        insert_symbol($2, SYMBOL_VARIABLE, $1->data_type, decl);
        ASTNode *assign = make_assign(make_var($2), $4);
        decl->next = assign;
        $$ = decl;
    }
;

expr_stmt:
    expression ';' { $$ = $1; }
;

if_stmt:
    IF '(' expression ')' stmt %prec LOWER_THAN_ELSE {
        $$ = make_if($3, $5, NULL);
    }
  | IF '(' expression ')' stmt ELSE stmt {
        $$ = make_if($3, $5, $7);
    }
;

while_stmt:
    WHILE '(' expression ')' stmt {
        $$ = make_while($3, $5);
    }
;

for_stmt:
    FOR '(' for_init for_cond for_incr ')' stmt {
        ASTNode *init = $3;
        ASTNode *cond = $4;
        ASTNode *incr = $5;
        ASTNode *body = make_block($7);

        ASTNode *last = body->left;
        if (last) {
            while (last->next) last = last->next;
            last->next = incr;
        } else {
            body->left = incr;
        }

        ASTNode *while_node = make_while(cond, body);
        if (init) init->next = while_node;
        $$ = init ? make_block(init) : while_node;
    }
;

for_init:
    decl_stmt { $$ = $1; }
  | expr_stmt { $$ = $1; }
;

for_cond:
    expr_stmt { $$ = $1; }
;

for_incr:
    expression { $$ = $1; }
;

return_stmt:
    RETURN expression ';' { $$ = make_return($2); }
;

expression:
    assignment_expression { $$ = $1; }
;

assignment_expression:
    IDENTIFIER '=' assignment_expression {
        $$ = make_assign(make_var($1), $3);
    }
  | logical_expression { $$ = $1; }
;

logical_expression:
    logical_expression '+' logical_expression {
        $$ = make_expr(OP_ADD, $1, $3);
    }
  | logical_expression '-' logical_expression {
        $$ = make_expr(OP_SUB, $1, $3);
    }
  | logical_expression '*' logical_expression {
        $$ = make_expr(OP_MUL, $1, $3);
    }
  | logical_expression '/' logical_expression {
        $$ = make_expr(OP_DIV, $1, $3);
    }
  | logical_expression EQ logical_expression {
        $$ = make_expr(OP_EQ, $1, $3);
    }
  | logical_expression NEQ logical_expression {
        $$ = make_expr(OP_NEQ, $1, $3);
    }
  | logical_expression GT logical_expression {
        $$ = make_expr(OP_GT, $1, $3);
    }
  | logical_expression LT logical_expression {
        $$ = make_expr(OP_LT, $1, $3);
    }
  | logical_expression GTE logical_expression {
        $$ = make_expr(OP_GTE, $1, $3);
    }
  | logical_expression LTE logical_expression {
        $$ = make_expr(OP_LTE, $1, $3);
    }
  | '&' IDENTIFIER {
        ASTNode *var = make_var($2);
        var->is_address = 1;  // ➕ You'll need to handle this in codegen
        $$ = var;
    }
  | '(' logical_expression ')' { $$ = $2; }
  | IDENTIFIER '(' args ')' { $$ = make_call($1, $3); }
  | IDENTIFIER { $$ = make_var($1); }
  | NUMBER { $$ = make_num($1); }
  | FLOAT_LITERAL { $$ = make_float($1); }
  | CHAR_LITERAL { $$ = make_char($1); }
  | STRING { $$ = make_string($1); }
;

args:
    /* empty */ { $$ = NULL; }
  | arg_list { $$ = $1; }
;

arg_list:
    arg_list ',' assignment_expression {
        ASTNode *last = $1;
        while (last->next) last = last->next;
        last->next = $3;
        $$ = $1;
    }
  | assignment_expression { $$ = $1; }
;

%%
int main() {
    printf("Parsing...\n");

    if (yyparse() == 0) {
        printf("Parsing complete.\n");

        if (root) {
            print_ast(root, 0);

            perform_semantic_analysis(root);

            // Generate TAC to output.tac
            FILE *out = fopen("output.tac", "w");
            if (!out) {
                fprintf(stderr, "Could not open output.tac for writing\n");
                return 1;
            }
            generate_code(root, out);  // ✅ generate TAC
            fclose(out);
            optimize_tac("output.tac", "output_opt.tac");

            // Generate target assembly code from TAC
            generate_target_code("output.tac", "target.asm");
        } else {
            printf("No AST generated.\n");
        }
    } else {
        fprintf(stderr, "Syntax Error in input\n");
    }

    return 0;
}
