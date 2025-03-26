// Test file for micro C parser
// This file tests all lexical rules

/* 
  Multi-line comment test
  This is a test of the micro C parser
*/

// Testing floating point constants
void testFloats() begin
    // Note: float is not a type_specifier in the grammar provided
    // but including for testing lexer
    integer f1;
    integer f2;
    integer f3;
    
    f1 = 3.14;
    f2 = .123;
    f3 = 2.0e+3;
end

// Function with pointer parameter
void swap(integer *a, integer *b) begin
    integer temp;
    temp = *a;
    *a = *b;
    *b = temp;
end

// Function with parameters
integer add(integer a, integer b) begin
    return a + b;
end

void testOp() begin
    integer m;
    integer n;
    integer p;
    
    m = 5 + 3;
    n = 10 - 4;
    p = 3 * 6;
    m = 15 / 3;
    n = 10 % 3;
    
    // Relational operators
    if (m < n) begin
        p = 1;
    end
    
    if (m > n) begin
        p = 2;
    end
    
    if (m <= n) begin
        p = 3;
    end
    
    if (m >= n) begin
        p = 4;
    end
    
    // Equality operators
    if (m == n) begin
        p = 5;
    end
    
    if (m != n) begin
        p = 6;
    end
    
    // Logical operators
    if (m > 0 && n < 0) begin
    	p = 7;
    end
    
    if (m < 70 || n > 2) begin
    	p = 8;
    end
    
end

// Keywords test
void main() begin
    // Variable declarations
    integer x;
    integer y;
    char c;
    integer arr[10];
    integer *ptr;
    
    // Constants
    x = 42;
    
     // Function call
    printNum(x);
    
    y = 3;
    c = 'A';
    
    // String literals
    // string lit = "This is a string literal";
    
    // Expressions
    x = 5 + 3 * 2;
    y = (x - 1) / 3;
    
    // Pointer operations
    ptr = &x;
    y = *ptr;
   
    
    // Conditional expressions
    integer flag;
    integer i;
    
    i = 67;
    integer j;
    
    // Nested conditional loop
    if (i > 0) begin
       i = 78;
       integer k[20];
       if (i < 70) begin
          integer retires;
          retires = 76;
        end
    end
    for( ; x < 10; x = x + 2) begin
    	integer q;
    	q = x * 2;
    	arr[x] = q;
    end
    return 0;
   
end



