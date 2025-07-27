%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
%}

%%

"if"            { return IF; }
"else"          { return ELSE; }
"int"           { return INT; }
"float"         { return FLOAT; }
"char"          { return CHAR; }
"void"          { return VOID; }
"return"        { return RETURN; }
"while"         { return WHILE; }
"for"           { return FOR; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"printf"        { return PRINTF; }
"scanf"         { return SCANF; }

"&"             { return '&'; }

\"([^\\\"]|\\.)*\"  {
    yylval.str = strdup(yytext);  // Keep quotes for parser handling if needed
    return STRING;
}

'([^\\']|\\.)' {
    char c;
    if (yytext[1] == '\\') {
        switch (yytext[2]) {
            case 'n': c = '\n'; break;
            case 't': c = '\t'; break;
            case 'r': c = '\r'; break;
            case '\\': c = '\\'; break;
            case '\'': c = '\''; break;
            default: c = yytext[2]; break;
        }
    } else {
        c = yytext[1];
    }
    yylval.cval = c;
    return CHAR_LITERAL;
}

[0-9]*\.[0-9]+  { yylval.fnum = atof(yytext); return FLOAT_LITERAL; }
[0-9]+          { yylval.num = atoi(yytext); return NUMBER; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = strdup(yytext);
    return IDENTIFIER;
}

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

[\t\r\n ]+      { /* skip whitespace */ }

"//".*          { /* skip single-line comment */ }
"/*"([^*]|\*+[^*/])*\*+"/"  { /* skip multi-line comment */ }

. {
    fprintf(stderr, "Unknown character: %s\n", yytext);
    return 0;
}

%%

int yywrap() { return 1; }
