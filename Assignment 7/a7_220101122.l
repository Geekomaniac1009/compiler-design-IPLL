%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int line_no = 1;
%}

/* Regular definitions */
digit       [0-9]
nonzero     [1-9]
letter      [a-zA-Z]
id_nondigit {letter}
identifier  {id_nondigit}({id_nondigit}|{digit})*
integer     {nonzero}{digit}*|0
fractional   {digit}*\.{digit}+|{digit}+\.{digit}*
exponent    [eE][+-]?{digit}+
float       {fractional}{exponent}?|{digit}+{exponent}
c_char      [^'\\\n]|\\['"?\\abfnrtv]
s_char      [^"\\\n]|\\['"?\\abfnrtv]
whitespace  [ \t]+

%%

"return"    { return RETURN; }
"void"      { return VOID; }
"float"     { return FLOAT; }
"integer"   { return INTEGER; }
"char"      { return CHAR; }
"for"       { return FOR; }
"const"     { return CONST; }
"while"     { return WHILE; }
"bool"      { return BOOL; }
"if"        { return IF; }
"do"        { return DO; }
"else"      { return ELSE; }
"begin"     { return BEGIN_BLOCK; }
"end"       { return END_BLOCK; }
"true"      { return TRUE; }
"false"     { return FALSE; }

{identifier}    { 
    yylval.str_val = strdup(yytext);
    return IDENTIFIER;
}

{integer}       { 
    yylval.int_val = atoi(yytext);
    return INTEGER_CONSTANT;
}

{float}         { 
    yylval.float_val = atof(yytext);
    return FLOATING_CONSTANT;
}

\'{c_char}\'    { 
    yylval.char_val = yytext[1];  
    return CHARACTER_CONSTANT;
}

\"{s_char}*\"   { 
    yylval.str_val = strdup(yytext);
    return STRING_LITERAL;
}

"["         { return '['; }
"]"         { return ']'; }
"("         { return '('; }
")"         { return ')'; }
"->"        { return ARROW; }
"++"        { return INC_OP; }
"--"        { return DEC_OP; }
"&"         { return '&'; }
"*"         { return '*'; }
"+"         { return '+'; }
"-"         { return '-'; }
"!"         { return '!'; }
"/"         { return '/'; }
"%"         { return '%'; }
"<<"        { return LEFT_OP; }
">>"        { return RIGHT_OP; }
"<"         { return '<'; }
">"         { return '>'; }
"<="        { return LE_OP; }
">="        { return GE_OP; }
"=="        { return EQ_OP; }
"!="        { return NE_OP; }
"^"         { return '^'; }
"|"         { return '|'; }
"&&"        { return AND_OP; }
"||"        { return OR_OP; }
"?"         { return '?'; }
":"         { return ':'; }
";"         { return ';'; }
"="         { return '='; }
","         { return ','; }

{whitespace}    { /* ignore whitespace */ }
\n              { line_no++; }

"/*"            { 
    char c, prev = 0;
    while((c = input()) != 0) {
        if(c == '/' && prev == '*')
            break;
        if(c == '\n')
            line_no++;
        prev = c;
    }
}

"//"            { 
    char c;
    while((c = input()) != '\n' && c != 0);
    if(c == '\n')
        line_no++;
}

.               { /* ignore any other characters */ }
%%

int yywrap() {
    return 1;
}