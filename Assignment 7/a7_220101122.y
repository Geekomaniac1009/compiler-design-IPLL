%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int line_no;
int yylex(void);
void yyerror(const char *s);

/* Symbol table structure */
struct symbol {
    char *name;
    char *type;
    int scope;
    int line_no;
    struct symbol *next;
};

/* Symbol table operations */
struct symbol *symbol_table = NULL;
int current_scope = 0;
int current_line = 0;
char current_type[20];

void add_symbol(char *name, char *type, int scope, int line);
void print_symbol_table();
void enter_scope();
void exit_scope();

/* File for reductions */
FILE *reduction_file;
FILE *symbol_table_file;

%}

%union {
    int int_val;
    float float_val;
    char char_val;
    char *str_val;
}

%token <str_val> IDENTIFIER
%token <int_val> INTEGER_CONSTANT
%token <float_val> FLOATING_CONSTANT
%token <char_val> CHARACTER_CONSTANT
%token <str_val> STRING_LITERAL
%token TRUE FALSE

%token RETURN VOID FLOAT INTEGER CHAR FOR CONST WHILE BOOL IF DO ELSE BEGIN_BLOCK END_BLOCK
%token ARROW INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP

%type <str_val> type_specifier

%start translation_unit

%%

primary_expression
    : IDENTIFIER
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> IDENTIFIER (%s)\n", line_no, $1); }
    | INTEGER_CONSTANT
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> INTEGER_CONSTANT (%d)\n", line_no, $1); }
    | FLOATING_CONSTANT
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> FLOATING_CONSTANT (%f)\n", line_no, $1); }
    | CHARACTER_CONSTANT
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> CHARACTER_CONSTANT (%c)\n", line_no, $1); }
    | STRING_LITERAL
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> STRING_LITERAL (%s)\n", line_no, $1); }
    | '(' expression ')'
        { fprintf(reduction_file, "Line %d: Reduce: primary_expression -> ( expression )\n", line_no); }
    ;

postfix_expression
    : primary_expression
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> primary_expression\n", line_no); }
    | postfix_expression '[' expression ']'
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> postfix_expression [ expression ]\n", line_no); }
    | postfix_expression '(' ')'
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> postfix_expression ( )\n", line_no); }
    | postfix_expression '(' argument_expression_list ')'
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> postfix_expression ( argument_expression_list )\n", line_no); }
    | postfix_expression ARROW IDENTIFIER
        { fprintf(reduction_file, "Line %d: Reduce: postfix_expression -> postfix_expression -> IDENTIFIER (%s)\n", line_no, $3); }
    ;

argument_expression_list
    : assignment_expression
        { fprintf(reduction_file, "Line %d: Reduce: argument_expression_list -> assignment_expression\n", line_no); }
    | argument_expression_list ',' assignment_expression
        { fprintf(reduction_file, "Line %d: Reduce: argument_expression_list -> argument_expression_list , assignment_expression\n", line_no); }
    ;

unary_expression
    : postfix_expression
        { fprintf(reduction_file, "Line %d: Reduce: unary_expression -> postfix_expression\n", line_no); }
    | unary_operator unary_expression
        { fprintf(reduction_file, "Line %d: Reduce: unary_expression -> unary_operator unary_expression\n", line_no); }
    ;

unary_operator
    : '&'
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> & (address op) \n", line_no); }
    | '*'
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> * (dereference op) \n", line_no); }
    | '+'
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> + (positive sign op) \n", line_no); }
    | '-'
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> - (neg sign op) \n", line_no); }
    | '!'
        { fprintf(reduction_file, "Line %d: Reduce: unary_operator -> ! (boolean negatn op) \n", line_no); }
    ;

multiplicative_expression
    : unary_expression
        { fprintf(reduction_file, "Line %d: Reduce: multiplicative_expression -> unary_expression\n", line_no); }
    | multiplicative_expression '*' unary_expression
        { fprintf(reduction_file, "Line %d: Reduce: multiplicative_expression -> multiplicative_expression * unary_expression (mult op) \n", line_no); }
    | multiplicative_expression '/' unary_expression
        { fprintf(reduction_file, "Line %d: Reduce: multiplicative_expression -> multiplicative_expression / unary_expression (div op) \n", line_no); }
    | multiplicative_expression '%' unary_expression
        { fprintf(reduction_file, "Line %d: Reduce: multiplicative_expression -> multiplicative_expression %% unary_expression (mod op) \n", line_no); }
    ;

additive_expression
    : multiplicative_expression
        { fprintf(reduction_file, "Line %d: Reduce: additive_expression -> multiplicative_expression\n", line_no); }
    | additive_expression '+' multiplicative_expression
        { fprintf(reduction_file, "Line %d: Reduce: additive_expression -> additive_expression + multiplicative_expression (addn op) \n", line_no); }
    | additive_expression '-' multiplicative_expression
        { fprintf(reduction_file, "Line %d: Reduce: additive_expression -> additive_expression - multiplicative_expression (sub op) \n", line_no); }
    ;

relational_expression
    : additive_expression
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> additive_expression\n", line_no); }
    | relational_expression '<' additive_expression
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> relational_expression < additive_expression (lt op) \n", line_no); }
    | relational_expression '>' additive_expression
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> relational_expression > additive_expression (gt op) \n", line_no); }
    | relational_expression LE_OP additive_expression
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> relational_expression <= additive_expression (lte op) \n", line_no); }
    | relational_expression GE_OP additive_expression
        { fprintf(reduction_file, "Line %d: Reduce: relational_expression -> relational_expression >= additive_expression (gte op) \n", line_no); }
    ;

equality_expression
    : relational_expression
        { fprintf(reduction_file, "Line %d: Reduce: equality_expression -> relational_expression\n", line_no); }
    | equality_expression EQ_OP relational_expression
        { fprintf(reduction_file, "Line %d: Reduce: equality_expression -> equality_expression == relational_expression\n", line_no); }
    | equality_expression NE_OP relational_expression
        { fprintf(reduction_file, "Line %d: Reduce: equality_expression -> equality_expression != relational_expression\n", line_no); }
    ;

logical_AND_expression
    : equality_expression
        { fprintf(reduction_file, "Line %d: Reduce: logical_AND_expression -> equality_expression\n", line_no); }
    | logical_AND_expression AND_OP equality_expression
        { fprintf(reduction_file, "Line %d: Reduce: logical_AND_expression -> logical_AND_expression && equality_expression\n", line_no); }
    ;

logical_OR_expression
    : logical_AND_expression
        { fprintf(reduction_file, "Line %d: Reduce: logical_OR_expression -> logical_AND_expression\n", line_no); }
    | logical_OR_expression OR_OP logical_AND_expression
        { fprintf(reduction_file, "Line %d: Reduce: logical_OR_expression -> logical_OR_expression || logical_AND_expression\n", line_no); }
    ;

conditional_expression
    : logical_OR_expression
        { fprintf(reduction_file, "Line %d: Reduce: conditional_expression -> logical_OR_expression\n", line_no); }
    | logical_OR_expression '?' expression ':' conditional_expression
        { fprintf(reduction_file, "Line %d: Reduce: conditional_expression -> logical_OR_expression ? expression : conditional_expression (ternary op) \n", line_no); }
    ;

assignment_expression
    : conditional_expression
        { fprintf(reduction_file, "Line %d: Reduce: assignment_expression -> conditional_expression\n", line_no); }
    | unary_expression '=' assignment_expression
        { fprintf(reduction_file, "Line %d: Reduce: assignment_expression -> unary_expression = assignment_expression\n", line_no); }
    ;

expression
    : assignment_expression
        { fprintf(reduction_file, "Line %d: Reduce: expression -> assignment_expression\n", line_no); }
    ;

declaration
    : type_specifier init_declarator ';'
        { 
            fprintf(reduction_file, "Line %d: Reduce: declaration -> type_specifier init_declarator ;\n", line_no);
            strcpy(current_type, "");
        }
    ;

init_declarator
    : declarator
        { fprintf(reduction_file, "Line %d: Reduce: init_declarator -> declarator\n", line_no); }
    | declarator '=' initializer
        { fprintf(reduction_file, "Line %d: Reduce: init_declarator -> declarator = initializer\n", line_no); }
    ;

type_specifier
    : VOID
        { 
            fprintf(reduction_file, "Line %d: Reduce: type_specifier -> void\n", line_no);
            strcpy(current_type, "void");
            $$ = strdup("void");
        }
    | CHAR
        { 
            fprintf(reduction_file, "Line %d: Reduce: type_specifier -> char\n", line_no);
            strcpy(current_type, "char");
            $$ = strdup("char");
        }
    | INTEGER
        { 
            fprintf(reduction_file, "Line %d: Reduce: type_specifier -> integer\n", line_no);
            strcpy(current_type, "integer");
            $$ = strdup("integer");
        }
    ;

declarator
    : pointer direct_declarator
        { 
            fprintf(reduction_file, "Line %d: Reduce: declarator -> pointer direct_declarator\n", line_no);
            // Add pointer prefix to current_type
            char temp[30];
            strcpy(temp, "pointer to ");
            strcat(temp, current_type);
            strcpy(current_type, temp);
        }
    | direct_declarator
        { fprintf(reduction_file, "Line %d: Reduce: declarator -> direct_declarator\n", line_no); }
    ;

direct_declarator
    : IDENTIFIER
        { 
            fprintf(reduction_file, "Line %d: Reduce: direct_declarator -> IDENTIFIER (%s)\n", line_no, $1);
            add_symbol($1, current_type, current_scope, line_no);
        }
    | IDENTIFIER '[' INTEGER_CONSTANT ']'
        { 
            fprintf(reduction_file, "Line %d: Reduce: direct_declarator -> IDENTIFIER [ INTEGER_CONSTANT ]\n", line_no);
            char array_type[50];
            sprintf(array_type, "array[%d] of %s", $3, current_type);
            add_symbol($1, array_type, current_scope, line_no);
        }
    | IDENTIFIER '(' parameter_list ')'
        { 
            fprintf(reduction_file, "Line %d: Reduce: direct_declarator -> IDENTIFIER ( parameter_list )\n", line_no);
            char func_type[50];
            sprintf(func_type, "function returning %s", current_type);
            add_symbol($1, func_type, current_scope, line_no);
        }
    | IDENTIFIER '(' ')'
        { 
            fprintf(reduction_file, "Line %d: Reduce: direct_declarator -> IDENTIFIER ( )\n", line_no);
            char func_type[50];
            sprintf(func_type, "function returning %s", current_type);
            add_symbol($1, func_type, current_scope, line_no);
        }
    ;

pointer
    : '*'
        { fprintf(reduction_file, "Line %d: Reduce: pointer -> *\n", line_no); }
    ;

parameter_list
    : parameter_declaration
        { fprintf(reduction_file, "Line %d: Reduce: parameter_list -> parameter_declaration\n", line_no); }
    | parameter_list ',' parameter_declaration
        { fprintf(reduction_file, "Line %d: Reduce: parameter_list -> parameter_list , parameter_declaration\n", line_no); }
    ;

parameter_declaration
    : type_specifier pointer IDENTIFIER
        { 
            fprintf(reduction_file, "Line %d: Reduce: parameter_declaration -> type_specifier pointer IDENTIFIER (%s)\n", line_no, $3);
            char param_type[50];
            sprintf(param_type, "pointer to %s", $1);
            add_symbol($3, param_type, current_scope + 1, line_no);
        }
    | type_specifier IDENTIFIER
        { 
            fprintf(reduction_file, "Line %d: Reduce: parameter_declaration -> type_specifier IDENTIFIER (%s)\n", line_no, $2);
            add_symbol($2, $1, current_scope + 1, line_no);
        }
    | type_specifier pointer
        { fprintf(reduction_file, "Line %d: Reduce: parameter_declaration -> type_specifier pointer\n", line_no); }
    | type_specifier
        { fprintf(reduction_file, "Line %d: Reduce: parameter_declaration -> type_specifier\n", line_no); }
    ;

initializer
    : assignment_expression
        { fprintf(reduction_file, "Line %d: Reduce: initializer -> assignment_expression\n", line_no); }
    ;

statement
    : compound_statement
        { fprintf(reduction_file, "Line %d: Reduce: statement -> compound_statement\n", line_no); }
    | expression_statement
        { fprintf(reduction_file, "Line %d: Reduce: statement -> expression_statement\n", line_no); }
    | selection_statement
        { fprintf(reduction_file, "Line %d: Reduce: statement -> selection_statement\n", line_no); }
    | iteration_statement
        { fprintf(reduction_file, "Line %d: Reduce: statement -> iteration_statement\n", line_no); }
    | jump_statement
        { fprintf(reduction_file, "Line %d: Reduce: statement -> jump_statement\n", line_no); }
    ;

compound_statement
    : BEGIN_BLOCK { enter_scope(); } block_item_list_opt END_BLOCK
        { 
            fprintf(reduction_file, "Line %d: Reduce: compound_statement -> begin block_item_list end\n", line_no);
            exit_scope();
        }
    ;

block_item_list_opt
    : block_item_list
        { fprintf(reduction_file, "Line %d: Reduce: block_item_list_opt -> block_item_list\n", line_no); }
    | /* empty */
        { fprintf(reduction_file, "Line %d: Reduce: block_item_list_opt -> empty\n", line_no); }
    ;

block_item_list
    : block_item
        { fprintf(reduction_file, "Line %d: Reduce: block_item_list -> block_item\n", line_no); }
    | block_item_list block_item
        { fprintf(reduction_file, "Line %d: Reduce: block_item_list -> block_item_list block_item\n", line_no); }
    ;

block_item
    : declaration
        { fprintf(reduction_file, "Line %d: Reduce: block_item -> declaration\n", line_no); }
    | statement
        { fprintf(reduction_file, "Line %d: Reduce: block_item -> statement\n", line_no); }
    ;

expression_statement
    : expression_opt ';'
        { fprintf(reduction_file, "Line %d: Reduce: expression_statement -> expression_opt ;\n", line_no); }
    ;

selection_statement
    : IF '(' expression ')' statement
        { fprintf(reduction_file, "Line %d: Reduce: selection_statement -> if ( expression ) statement\n", line_no); }
    | IF '(' expression ')' statement ELSE statement
        { fprintf(reduction_file, "Line %d: Reduce: selection_statement -> if ( expression ) statement else statement\n", line_no); }
    ;

iteration_statement
    : FOR '(' expression_opt ';' expression_opt ';' expression_opt ')' statement
        { fprintf(reduction_file, "Line %d: Reduce: iteration_statement -> for ( expression_opt ; expression_opt ; expression_opt ) statement\n", line_no); }
    ;

expression_opt
    : expression
        { fprintf(reduction_file, "Line %d: Reduce: expression_opt -> expression\n", line_no); }
    | /* empty */
        { fprintf(reduction_file, "Line %d: Reduce: expression_opt -> empty\n", line_no); }
    ;

jump_statement
    : RETURN expression_opt ';'
        { fprintf(reduction_file, "Line %d: Reduce: jump_statement -> return expression_opt ;\n", line_no); }
    ;

translation_unit
    : function_definition
        { fprintf(reduction_file, "Line %d: Reduce: translation_unit -> function_definition\n", line_no); }
    | declaration
        { fprintf(reduction_file, "Line %d: Reduce: translation_unit -> declaration\n", line_no); }
    | function_definition translation_unit  /* to account for multiple functions and declarations */
        { fprintf(reduction_file, "Line %d: Reduce: translation_unit -> translation_unit function_definition\n", line_no); }
    | declaration translation_unit 
        { fprintf(reduction_file, "Line %d: Reduce: translation_unit -> translation_unit declaration\n", line_no); }
    ;

function_definition
    : type_specifier function_declarator compound_statement 
        { fprintf(reduction_file, "Line %d: Reduce: function_definition -> type_specifier function_declarator compound_statement\n", line_no); }
    ;

function_declarator
    : IDENTIFIER '(' ')'  /* Avoiding parameter_opt_list to avoid Reduce-Reduce/Shift-Reduce conflicts */
        { fprintf(reduction_file, "Line %d: Reduce: function_declarator -> identifier ( )\n", line_no); }
    | IDENTIFIER '(' parameter_list ')' 
        { fprintf(reduction_file, "Line %d: Reduce: function_declarator -> identifier ( parameter_list )\n", line_no); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, line_no);
}

void add_symbol(char *name, char *type, int scope, int line) {
    struct symbol *new_symbol = (struct symbol*)malloc(sizeof(struct symbol));
    new_symbol->name = strdup(name);
    new_symbol->type = strdup(type);
    new_symbol->scope = scope;
    new_symbol->line_no = line;
    new_symbol->next = symbol_table;
    symbol_table = new_symbol;
    
    // Write to symbol table file
    fprintf(symbol_table_file, "%-20s %-30s %-10d %-10d\n", name, type, scope, line);
}

void print_symbol_table() {
    struct symbol *current = symbol_table;
    while(current != NULL) {
        fprintf(symbol_table_file, "%-20s %-30s %-10d %-10d\n", 
                current->name, current->type, current->scope, current->line_no);
        current = current->next;
    }
}

void enter_scope() {
    current_scope++;
}

void exit_scope() {
    current_scope--;
}

int main() {
    // Open the files for reductions and symbol table
    reduction_file = fopen("reductions_output.txt", "w");
    if (!reduction_file) {
        fprintf(stderr, "Error opening reductions output file\n");
        return 1;
    }
    
    symbol_table_file = fopen("symbol_table_output.txt", "w");
    if (!symbol_table_file) {
        fprintf(stderr, "Error opening symbol table output file\n");
        fclose(reduction_file);
        return 1;
    }
    
    // Write headers for the symbol table file
    fprintf(symbol_table_file, "%-20s %-30s %-10s %-10s\n", "Name", "Type", "Scope", "Line");
    fprintf(symbol_table_file, "--------------------------------------------------------------------------\n");
    
    // Parse the input
    yyparse();
    
    // Close the files
    fclose(reduction_file);
    fclose(symbol_table_file);
    
    printf("Parsing completed successfully. Check reductions_output.txt and symbol_table_output.txt for results.\n");
    
    return 0;
}