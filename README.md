# MicroC Compiler - CS348 Course Project, IIT Guwahati

## Overview
This repository contains a comprehensive implementation of a MicroC compiler developed as part of the CS348 Compiler Design course at IIT Guwahati. The project demonstrates the complete pipeline of compiler construction through a series of progressive assignments, each building upon the previous to create a fully functional compiler for the MicroC language (a simplified subset of C).

## Project Structure

The project is organized into five key assignments, each focusing on a different phase of compiler construction:

```
/
├── Assignment4/     # Two-pass Assembler
├── Assignment5/     # Lexical Analysis for MicroC
├── Assignment6/     # Syntax Analysis (Parser) for MicroC
├── Assignment7/     # Toy Calculator Example
└── Assignment8/     # Intermediate Code Generation for MicroC
```

## Technologies Used
- C/C++ for core implementation
- Flex (Fast Lexical Analyzer Generator) for lexical analysis
- Bison/YACC (Yet Another Compiler Compiler) for syntax analysis and parsing

## Assignment Details

### Assignment 4: Two-Pass Assembler
Implementation of a two-pass assembler that demonstrates fundamental concepts of symbol resolution.

**Features:**
- First pass: Builds the symbol table by assigning addresses to all labels
- Second pass: Resolves all symbol references and generates machine code
- Handles literal tables for constants
- Generates comprehensive symbol and literal tables as output

**Usage:**
```bash
cd Assignment4
make
./assembler <input_file>
```

### Assignment 5: Lexical Analyzer for MicroC
A flex-based implementation that tokenizes MicroC source code.

**Features:**
- Recognition of all MicroC tokens (keywords, identifiers, literals, operators)
- Symbol table generation for identifiers
- Error detection for invalid tokens
- Detailed token output with line numbers and token types

**Usage:**
```bash
cd Assignment5
make
./lexer <input_file>
```

### Assignment 6: Syntax Analyzer for MicroC
Extends the lexical analyzer with a Bison/YACC-based parser for syntax analysis.

**Features:**
- Complete grammar definition for MicroC language
- Parse tree construction
- Symbol table management
- Output files containing:
  - Reduction steps during parsing
  - Updated symbol table with type information
  - Syntax error reporting with line numbers

**Usage:**
```bash
cd Assignment6
make
./parser <input_file>
```

### Assignment 7: Toy Calculator
A standalone calculator implementation demonstrating lexical, syntax, and semantic analysis.

**Features:**
- Supports decimal, binary, and hexadecimal number formats
- Basic arithmetic operations
- Variable declarations and assignments
- Type checking and conversion
- Comprehensive error reporting

**Usage:**
```bash
cd Assignment7
make
./calculator
```

### Assignment 5: Intermediate Code Generation
The final phase that generates intermediate code for MicroC programs.

**Features:**
- Three-address code generation
- Control flow handling (if-else, loops)
- Function calls and returns
- Variable scope management
- Code optimization techniques

**Usage:**
```bash
cd Assignment5
make
./compiler <input_file>
```

## MicroC Language Specification

MicroC is a simplified subset of C with the following features:

- Basic data types: int, char, float
- Variable declarations and assignments
- Control structures: if-else, while, for
- Function definitions and calls
- Basic I/O operations
- Arithmetic and logical operations

## Building and Running

### Prerequisites
- GCC compiler (version 5.0 or higher)
- Flex (version 2.6 or higher)
- Bison (version 3.0 or higher)

### Building the Entire Project
```bash
# Clone the repository
git clone https://github.com/Geekomaniac1009/compiler-design-IPLL.git
cd microc-compiler

# Build all assignments
make all
```

### Running Tests
```bash
make test
```

## Sample MicroC Program

```c
/* Sample MicroC program */
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num = 5;
    int result;
    
    result = factorial(num);
    printf("Factorial of %d is: %d\n", num, result);
    
    return 0;
}
```

## Contributors
- [Sanchay Baranwal](https://github.com/Geekomaniac1009)

## License
This project is licensed under the MIT License - see the LICENSE file for details.
