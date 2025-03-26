%{ 
#include <stdio.h>
#include <string.h>
#define KEYWORD            1
#define ID                 2
#define INT_CONST          3
#define FLOAT_CONST        4
#define CHAR_CONST         5
#define STRING             6
#define PUNC               7
#define SINGLE_COMMENT     8
#define MULTI_COMMENT      9

// File pointers
FILE *token_file;
char input_filename[100] = "test.mc"; // Default filename

// Forward declarations
void process_token(int token, const char* text);
void table_init();
void insert_symbol(const char *name);
void insert_literal(const char *value, const char *type);
void write_sym_tab();
void write_lit_tab();
%} 

/* KEYWORDS */
KEYWORD     		"return"|"void"|"float"|"int"|"char"|"for"|"const"|"while"|"bool"|"if"|"do"|"else"|"begin"|"end"  

/* IDENTIFIERS */
ID 			[_a-zA-Z][_a-zA-Z0-9]*

/* INTEGERS */
INT_CONST   		[+-]?(0|[1-9][0-9]*)

/* FLOATING-POINT CONSTANT */
FLOAT_CONST  [+-]?([0-9]*[.][0-9]+([eE][+-]?[0-9]+)?|[0-9]+[eE][+-]?[0-9]+)

/* ESCAPE CHARACTERS */
ESC_SEQ  		\\[abfnrtv'\"\\?]

/* CHARACTER CONSTANT */
CHAR_CONST		'([^\\'\n]|{ESC_SEQ})+'
			
/* STRING LITERALS */
STRING			\"([^\\\"\n]|{ESC_SEQ})*\"

/* PUNCTUATIONS */
PUNC    		(\[|\]|\(|\)|->|&|\*|\+|-|\/|%|!|\?|<=|>=|==|!=|&&|\|\||=|:|;|,)

/* WHITESPACES */
WS			[ \t\n]

/* SINGLE COMMENT */
SINGLE_COMMENT		[/][/].*
 
/* MULTI COMMENT */
MULTI_COMMENT 		[/][*][^*]*[*]+([^/*][^*]*[*]+)*[/]

%%
{KEYWORD}      		{ process_token(KEYWORD, yytext); }
{ID}		    	{ process_token(ID, yytext); }
{INT_CONST}	    	{ process_token(INT_CONST, yytext); }
{FLOAT_CONST}        { process_token(FLOAT_CONST, yytext); }
{CHAR_CONST}  		{ process_token(CHAR_CONST, yytext); }
{STRING}	    	{ process_token(STRING, yytext); }
{PUNC}		    	{ process_token(PUNC, yytext); }
{SINGLE_COMMENT}   	{ process_token(SINGLE_COMMENT, yytext); }
{MULTI_COMMENT} 	{ process_token(MULTI_COMMENT, yytext); }
{WS}	            { /* ignore whitespace */ }
.                   { fprintf(token_file, "<UNDEFINED SYMBOL, %s>\n", yytext); }
%%

#define MAX_FILENAME 100
#define TABLE_SIZE 1000

// Symbol Table Structure
typedef struct {
    char name[50];
    char type[20];
} Symbol;

// Literal Table Structure
typedef struct {
    char value[50];
    char type[20];
} Literal;

Symbol sym_tab[TABLE_SIZE];
Literal lit_tab[TABLE_SIZE];
int symbol_count = 0;
int literal_count = 0;

// Initialize Tables
void table_init() {
    symbol_count = 0;
    literal_count = 0;
}

// Insert into Symbol Table (Identifiers Only)
void insert_symbol(const char *name) { 
    const char* type = "IDENTIFIER";
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(sym_tab[i].name, name) == 0) {
            return;
        }
    }
    strcpy(sym_tab[symbol_count].name, name);
    strcpy(sym_tab[symbol_count].type, type);
    symbol_count++;
}

// Insert into Literal Table
void insert_literal(const char *value, const char *type) {
    for (int i = 0; i < literal_count; i++) {
        if (strcmp(lit_tab[i].value, value) == 0) {
            return;
        }
    }
    strcpy(lit_tab[literal_count].value, value);
    strcpy(lit_tab[literal_count].type, type);
    literal_count++;
}

// Write Symbol Table to File
void write_sym_tab() {
    FILE *file = fopen("sym_tab_nit.txt", "w");
    if (!file) {
        perror("Error opening sym_tab_nit.txt");
        return;
    }
    fprintf(file, "+----------------------------------+\n");
    fprintf(file, "| Symbol Table (Identifiers)       |\n");
    fprintf(file, "+----------------------------------+\n");
    for (int i = 0; i < symbol_count; i++) {
        fprintf(file, "%s\t : %s\n", sym_tab[i].name, sym_tab[i].type);
    }
    fclose(file);
}

// Write Literal Table to File
void write_lit_tab() {
    FILE *file = fopen("lit_tab_nit.txt", "w");
    if (!file) {
        perror("Error opening lit_tab_nit.txt");
        return;
    }
    fprintf(file, "+-------------------------------------+\n");
    fprintf(file, "| Literal Table (Constants & Strings) |\n");
    fprintf(file, "+-------------------------------------+\n");
    for (int i = 0; i < literal_count; i++) {
        fprintf(file, "%s\t : %s\n", lit_tab[i].value, lit_tab[i].type);
    }
    fclose(file);
}


// Process tokens
void process_token(int token, const char* text) {
    switch (token) {
        case KEYWORD:
            fprintf(token_file, "<KEYWORD, %d, %s>\n", token, text);
            break;
        case ID:
            fprintf(token_file, "<IDENTIFIER, %d, %s>\n", token, text);
            insert_symbol(text);
            break;
        case INT_CONST:
            fprintf(token_file, "<INTEGER CONST, %d, %s>\n", token, text);
            insert_literal(text, "INTEGER");
            break;
        case FLOAT_CONST:
            fprintf(token_file, "<FLOAT CONST, %d, %s>\n", token, text);
            insert_literal(text, "FLOAT CONST");
            break;
        case CHAR_CONST:
            fprintf(token_file, "<CHAR CONST, %d, %s>\n", token, text);
            insert_literal(text, "CHAR CONST");
            break;
        case STRING:
            fprintf(token_file, "<STRING, %d, %s>\n", token, text);
            insert_literal(text, "STRING");
            break;
        case PUNC:
            fprintf(token_file, "<PUNCTUATOR, %d, %s>\n", token, text);
            break;
        case SINGLE_COMMENT:
            fprintf(token_file, "<SINGLE LINE COMMENT, %d, %s>\n", token, text);
            break;
        case MULTI_COMMENT:
            fprintf(token_file, "<MULTILINE COMMENT, %d, %s>\n", token, text);
            break;
        default:
            fprintf(token_file, "<UNDEFINED TOKEN, %s>\n", text);
    }
}

int main(int argc, char *argv[]) {
    // Check if a filename was provided as a command-line argument
    if (argc > 1) {
        strcpy(input_filename, argv[1]);
    }
    
    // Open the input file
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        fprintf(stderr, "Error: Could not open input file %s\n", input_filename);
        return 1;
    }
    
    // Open output file for tokens
    token_file = fopen("tokens_nit.txt", "w");
    if (!token_file) {
        perror("Error opening tokens_nit.txt");
        fclose(input_file);
        return 1;
    }
    
    // Set the input file for flex
    yyin = input_file;
    
    // Initialize tables
    table_init();
    
    // Process all tokens
    yylex();
    
    // Write Symbol & Literal Tables to Files
    write_sym_tab();
    write_lit_tab();
    
    // Close files
    fclose(input_file);
    fclose(token_file);
    
    printf("Analysis complete...\n");
    
    return 0;
}