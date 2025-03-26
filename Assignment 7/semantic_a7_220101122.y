%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum for data types
typedef enum {
    TYPE_VOID,
    TYPE_CHAR,
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_BOOL,
    TYPE_ERROR
} DataType;

// Union to store different types of values
typedef union {
    int int_val;
    float float_val;
    char char_val;
    int bool_val;
} Value;

// Symbol table entry structure with value storage
typedef struct SymbolTableEntry {
    char* name;
    DataType type;
    int is_array;
    int array_size;
    Value value;
    struct SymbolTableEntry* next;
} SymbolTableEntry;

// Scope structure
typedef struct Scope {
    SymbolTableEntry* symbols;
    struct Scope* parent;
} Scope;

// Global variables
Scope* current_scope = NULL;
int yylex(void);
void yyerror(const char* s);

// Function prototypes
Scope* create_scope(Scope* parent);
void enter_scope();
void exit_scope();
SymbolTableEntry* find_symbol(const char* name);
void add_symbol(const char* name, DataType type, int is_array, int array_size);
DataType get_arithmetic_result_type(DataType type1, DataType type2);
int is_type_compatible(DataType expected, DataType actual);
void type_error(const char* message);
void update_symbol_value(const char* name, Value val, DataType type);

%}

%union {
    int int_val;
    float float_val;
    char char_val;
    char* str_val;
    DataType type_val;
    struct {
        DataType type;
        Value val;
    } expr_val;
}

%token <str_val> IDENTIFIER STRING_LITERAL
%token <int_val> INTEGER_CONSTANT
%token <float_val> FLOATING_CONSTANT
%token <char_val> CHARACTER_CONSTANT

%token RETURN VOID FLOAT INTEGER CHAR BOOL
%token FOR CONST IF ELSE WHILE DO
%token BEGIN_TOKEN END_TOKEN

%type <expr_val> expression assignment_expression 
%type <expr_val> unary_expression multiplicative_expression 
%type <expr_val> additive_expression relational_expression 
%type <expr_val> equality_expression logical_and_expression 
%type <expr_val> logical_or_expression conditional_expression
%type <type_val> type_specifier

%%

// Top-level parsing rules with semantic analysis
translation_unit
    : function_definition
    | declaration
    ;

function_definition
    : type_specifier IDENTIFIER '(' ')' compound_statement
    {
        // Semantic analysis: function declaration
        add_symbol($2, $1, 0, 0);
    }
    ;

declaration
    : type_specifier IDENTIFIER ';'
    {
        // Add variable to symbol table
        add_symbol($2, $1, 0, 0);
    }
    | type_specifier IDENTIFIER '=' assignment_expression ';'
    {
        // Type checking for initialization
        if (!is_type_compatible($1, $4)) {
            type_error("Type mismatch in initialization");
        }
        add_symbol($2, $1, 0, 0);
    }
    ;

// Arithmetic operations with value propagation
assignment_expression
    : conditional_expression { $$ = $1; }
    | unary_expression '=' assignment_expression
    {
        // Type checking and value assignment
        if (!is_type_compatible($1.type, $3.type)) {
            type_error("Type mismatch in assignment");
        }
        
        // Update symbol table with new value
        update_symbol_value($1.str_val, $3.val, $3.type);
        
        $$.type = $1.type;
        $$.val = $3.val;
    }
    ;

multiplicative_expression
    : unary_expression { $$ = $1; }
    | multiplicative_expression '*' unary_expression
    {
        // Perform arithmetic and value computation
        $$.type = get_arithmetic_result_type($1.type, $3.type);
        
        // Arithmetic based on types
        if ($$.type == TYPE_FLOAT) {
            float val1 = ($1.type == TYPE_INTEGER) ? 
                (float)$1.val.int_val : $1.val.float_val;
            float val2 = ($3.type == TYPE_INTEGER) ? 
                (float)$3.val.int_val : $3.val.float_val;
            $$.val.float_val = val1 * val2;
        } else if ($$.type == TYPE_INTEGER) {
            $$.val.int_val = $1.val.int_val * $3.val.int_val;
        }
    }
    | multiplicative_expression '/' unary_expression
    {
        // Perform division with type handling
        $$.type = get_arithmetic_result_type($1.type, $3.type);
        
        // Check for division by zero
        if (($3.type == TYPE_INTEGER && $3.val.int_val == 0) ||
            ($3.type == TYPE_FLOAT && $3.val.float_val == 0.0)) {
            type_error("Division by zero");
        }
        
        // Arithmetic based on types
        if ($$.type == TYPE_FLOAT) {
            float val1 = ($1.type == TYPE_INTEGER) ? 
                (float)$1.val.int_val : $1.val.float_val;
            float val2 = ($3.type == TYPE_INTEGER) ? 
                (float)$3.val.int_val : $3.val.float_val;
            $$.val.float_val = val1 / val2;
        } else if ($$.type == TYPE_INTEGER) {
            $$.val.int_val = $1.val.int_val / $3.val.int_val;
        }
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression '+' multiplicative_expression
    {
        // Perform addition with type handling
        $$.type = get_arithmetic_result_type($1.type, $3.type);
        
        // Arithmetic based on types
        if ($$.type == TYPE_FLOAT) {
            float val1 = ($1.type == TYPE_INTEGER) ? 
                (float)$1.val.int_val : $1.val.float_val;
            float val2 = ($3.type == TYPE_INTEGER) ? 
                (float)$3.val.int_val : $3.val.float_val;
            $$.val.float_val = val1 + val2;
        } else if ($$.type == TYPE_INTEGER) {
            $$.val.int_val = $1.val.int_val + $3.val.int_val;
        }
    }
    | additive_expression '-' multiplicative_expression
    {
        // Perform subtraction with type handling
        $$.type = get_arithmetic_result_type($1.type, $3.type);
        
        // Arithmetic based on types
        if ($$.type == TYPE_FLOAT) {
            float val1 = ($1.type == TYPE_INTEGER) ? 
                (float)$1.val.int_val : $1.val.float_val;
            float val2 = ($3.type == TYPE_INTEGER) ? 
                (float)$3.val.int_val : $3.val.float_val;
            $$.val.float_val = val1 - val2;
        } else if ($$.type == TYPE_INTEGER) {
            $$.val.int_val = $1.val.int_val - $3.val.int_val;
        }
    }
    ;

unary_expression
    : IDENTIFIER
    {
        // Retrieve symbol and its value
        SymbolTableEntry* symbol = find_symbol($1);
        if (!symbol) {
            type_error("Undeclared variable");
            $$.type = TYPE_ERROR;
        } else {
            $$.type = symbol->type;
            $$.val = symbol->value;
            $$.str_val = $1;  // Store identifier name for potential assignment
        }
    }
    | INTEGER_CONSTANT 
    { 
        $$.type = TYPE_INTEGER; 
        $$.val.int_val = $1; 
    }
    | FLOATING_CONSTANT 
    { 
        $$.type = TYPE_FLOAT; 
        $$.val.float_val = $1; 
    }
    ;

// Scoping rules
compound_statement
    : BEGIN_TOKEN 
      { enter_scope(); }
      block_item_list 
      END_TOKEN 
      { exit_scope(); }
    ;

block_item_list
    : block_item
    | block_item_list block_item
    ;

block_item
    : declaration
    | statement
    ;

// Other statement rules would be added here
statement
    : compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;

expression_statement
    : ';'
    | expression ';'
    ;

selection_statement
    : IF '(' expression ')' statement
    | IF '(' expression ')' statement ELSE statement
    ;

iteration_statement
    : FOR '(' expression_statement expression_statement expression ')' statement
    ;

jump_statement
    : RETURN ';'
    | RETURN expression ';'
    ;

// New function to update symbol table values
void update_symbol_value(const char* name, Value val, DataType type) {
    SymbolTableEntry* symbol = find_symbol(name);
    if (!symbol) {
        type_error("Cannot assign to undeclared variable");
        return;
    }
    
    // Type checking before update
    if (!is_type_compatible(symbol->type, type)) {
        type_error("Type mismatch in assignment");
        return;
    }
    
    // Update value with type conversion if needed
    switch (symbol->type) {
        case TYPE_INTEGER:
            symbol->value.int_val = (type == TYPE_FLOAT) ? 
                (int)val.float_val : val.int_val;
            break;
        case TYPE_FLOAT:
            symbol->value.float_val = (type == TYPE_INTEGER) ? 
                (float)val.int_val : val.float_val;
            break;
        case TYPE_CHAR:
            symbol->value.char_val = val.char_val;
            break;
        case TYPE_BOOL:
            symbol->value.bool_val = val.bool_val;
            break;
        default:
            type_error("Unsupported type for value update");
    }
}

%%

// Error handling
void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char** argv) {
    // Parse input
    yyparse();
    return 0;
}