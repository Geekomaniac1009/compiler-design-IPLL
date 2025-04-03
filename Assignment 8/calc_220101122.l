%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int yylex(void);
void yyerror(const char *s);
%}

/* Regular definitions */
digit       [0-9]
nonzero     [1-9]
bin_digit   [01]
binary      {bin_digit}+
hex_digit   [0-9a-fA-F]
whitespace  [\t]+
integer     {nonzero}{digit}*|0
hex         {hex_digit}+

%%

"expr"         { return EXPR; }
"bintodec"     { return BINTODEC; }
"bintohex"     { return BINTOHEX; }
"hextobin"     { return HEXTOBIN; }
"hextodec"     { return HEXTODEC; }

{hex}           { 
    yylval.sval = strdup(yytext); 
    return HEXADECIMAL; 
}


"+"            { return PLUS; }
"-"            { return MINUS; }
"*"            { return MULTIPLY; }
"/"            { return DIVIDE; }
"**"           { return POWER; }
"("            { return LPAREN; }
")"            { return RPAREN; }

{whitespace}    {/* ignore whitespace */}

.              { yyerror("Invalid character"); }

%%

int yywrap() {
    return 1;
}