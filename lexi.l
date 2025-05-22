
%{
#include "parser.tab.h"
#include <stdio.h>
#include "ast.h"
%}

%%
"if"            { return IF; }
"else"          { return ELSE; }
"int"           { return INT; }
"void"          { return VOID; }
"return"        { return RETURN; }

[a-zA-Z_][a-zA-Z0-9_]*   { yylval.str = strdup(yytext); return IDENTIFIER; }
[0-9]+                  { yylval.num = atoi(yytext); return NUMBER; }

"=="            { return EQ; }
"!="            { return NEQ; }
">="            { return GTE; }
"<="            { return LTE; }
">"             { return GT; }
"<"             { return LT; }
"="             { return '='; }

"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }

"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
";"             { return ';'; }
","             { return ','; }

[ \t\n]+        ;
.               { return yytext[0]; }
%%

int yywrap() {
    return 1;
}