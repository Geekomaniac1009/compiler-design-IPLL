// Sample MiniC program for lexical analysis testing

/* 
   This is a multi-line comment
   for testing the lexical analyzer
*/

int main() {
    // Variable declarations
    int x = 10;
    float y = 3.14;
    char c = 'a';
    char str[] = "Hello, world!";
    
    // Arithmetic operations
    int sum = x + 20;
    float product = x * y;
    
    // Conditional statements
    if (x > 5) 
	begin
        	x = x - 1;
	end
    else 
	begin
        	x = x + 1;
        end
    
    while (x > 0) 
	begin
        	x = x - 1;
        end
    
    for (int i = 0; i < 10; i = i + 1) 
	begin
	        sum = sum + i;
     	end
    
    // Special characters and escape sequences
    char newline = '\n';
    char tab = '\t';
    
    // Constants
    const int MAX_SIZE = 100;
    float PI = 3.14159e0;
    int negative = -42;
    
    // Testing various punctuators
    int array[10];
    int *ptr = &array[0];
    
    // Testing operators
    bool isEqual = (x == y);
    bool isNotEqual = (x != y);
    bool logicalAnd = (x > 0 && y > 0);
    bool logicalOr = (x > 0 || y > 0);
    
    return 0;
}
