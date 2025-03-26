# Lexical Analyzer

A simple lexical analyzer implementation using Flex to process `.mc` files.

## Files

- `a6it_220101122.l` - First lexical analyzer implementation
- `a6nit_220101122.l` - Second lexical analyzer implementation
- `test.mc` - Sample input file for testing

## What Each File Does

- `a6it_220101122.l`: Flex file for lexical analysis with direct token processing in main
- `a6nit_220101122.l`: Flex file for lexical analysis using a process_token function
- `test.mc`: Example .mc code for testing the lexical analyzers

## Output Files

- `tokens.txt`: List of tokens found in the input file
- `sym_tab.txt`: Symbol table containing identifiers
- `lit_tab.txt`: Literal table containing constants and strings

## How to Run

```bash
# Compile the first analyzer
flex a6it_220101122.l
gcc lex.yy.c -o a6it_220101122 -lfl

# Run with input file
./a6it_220101122 test.mc

# Compile the second analyzer
flex a6nit_220101122.l
gcc lex.yy.c -o a6nit_220101122 -lfl

# Run with input file
./a6nit_220101122 test.mc

# Or use the Makefile
make a6it_220101122
make a6nit_220101122
./a6it_220101122 test.mc
./a6nit_220101122 test.mc

# Clean up
make clean
```
