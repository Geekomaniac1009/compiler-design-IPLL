%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int yylex(void);
void yyerror(const char *s);

int binaryToDecimal(const char *binary);
char* binaryToHex(const char *binary);
char* hexToBinary(const char *hex);
int hexToDecimal(const char *hex);
double convertNum(const char* hex);
double pow(double a, double b);
%}

%union {
    char *sval;
    double dval;
}


%token <sval> HEXADECIMAL
%token EXPR BINTODEC BINTOHEX HEXTOBIN HEXTODEC
%token PLUS MINUS MULTIPLY DIVIDE POWER
%token LPAREN RPAREN

%type <dval> expression term factor


%left PLUS MINUS
%left MULTIPLY DIVIDE
%right POWER

%start translation_unit;
%%

translation_unit:
    | statement translation_unit 
;

statement:
    EXPR LPAREN expression RPAREN   { printf("Result: %.3f\n", $3); }
    | BINTODEC LPAREN HEXADECIMAL RPAREN { 
        int result = binaryToDecimal($3);
        printf("Result: %d\n", result);
        free($3);
    }
    | BINTOHEX LPAREN HEXADECIMAL RPAREN {
        char *result = binaryToHex($3);
        printf("Result: %s\n", result);
        free($3);
        free(result);
    }
    | HEXTOBIN LPAREN HEXADECIMAL RPAREN {
        char *result = hexToBinary($3);
        printf("Result: %s\n", result);
        free($3);
        free(result);
    }
    | HEXTODEC LPAREN HEXADECIMAL RPAREN {
        int result = hexToDecimal($3);
        printf("Result: %d\n", result);
        free($3);
    }
;

expression:
    expression PLUS term    { $$ = $1 + $3; }
    | expression MINUS term { $$ = $1 - $3; }
    | term                  { $$ = $1; }
;

term:
    term MULTIPLY factor { $$ = $1 * $3; }
    | term DIVIDE factor { 
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } 
        else {
            $$ = $1 / $3; 
        }
    }
    | factor              { $$ = $1; }
;

factor:
    HEXADECIMAL  { 
            double result = convertNum($1);
            $$ = result;
     }
    | MINUS factor        { $$ = -$2; }
    | LPAREN expression RPAREN { $$ = $2; }
    | factor POWER factor { $$ = pow($1, $3); }
;



%%

double convertNum(const char* hex){
    double num = 0;
    //printf("%s\n", hex);
    for(int i= 0; i<strlen(hex); i++){
        if(hex[i] >= '0' && hex[i] <= '9'){
            num *= 10;
            num += (hex[i]-'0');
        }
        else{
            yyerror("Invalid decimal format in expr");
            return -1.0;
        }
    }
    return num;
}

// Binary to Decimal conversion
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    for (int i = 0; i<strlen(binary); i++) {
         decimal *= 2;
        if (binary[i] == '1') {
            decimal++;
        }
        else if(binary[i] != '0'){
            // hex token 
            yyerror("Invalid binary format!");
            return -1;
        }
       
    }
    
    return decimal;
}

// Binary to Hexadecimal conversion
char* binaryToHex(const char *binary) {

    // bin to dec
    int decimal = binaryToDecimal(binary);
    // dec to hex
    char *hex = malloc(10 * sizeof(char));
    sprintf(hex, "%X", decimal);
    
    return hex;
}

// Hexadecimal to Binary conversion
char* hexToBinary(const char *hex) {
    char *binary = malloc(33 * sizeof(char)); // Max 32 bits
    binary[0] = '\0';
    
    for (int i = 0; hex[i]; i++) {
        int value;
        // Convert hex digit to decimal
        if (hex[i] >= '0' && hex[i] <= '9')
            value = hex[i] - '0';
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            value = hex[i] - 'A' + 10;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            value = hex[i] - 'a' + 10;
        else {
            free(binary);
            yyerror("Invalid hexadecimal digit");
            return NULL;
        }
        
        // Convert decimal to 4-bit binary
        char temp[5];
        sprintf(temp, "%04d", value / 8 * 1000 + 
                              (value % 8 / 4) * 100 + 
                              (value % 4 / 2) * 10 + 
                              value % 2);
        strcat(binary, temp);
    }
    
    return binary;
}

double pow(double a, double b){
    int res = 1;
    while(b--){
        res *= a;
    }
    return res;
}
// Hexadecimal to Decimal conversion
int hexToDecimal(const char *hex) {
    return (int)strtol(hex, NULL, 16);
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Calculator started. Enter expressions:\n");
    yyparse();
    return 0;
}