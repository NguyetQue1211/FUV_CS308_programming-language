# Loops and Subroutines in C++

## Loops
C++ programming language provides the following type of loops to handle looping requirements
* while loop: Repeats a statement or group of statements while a given condition is true. It tests the condition before executing the loop body.
```
while (condition) {
// The statement in the body of the loop 
// executes upon each iteration
}
```
Before executing an iteration of the loop, the while loop evaluates the condition expression. If true, the loop continues. If false, the loop terminates.
```
#include <cstdio>
#include <cstdint>

bool double_return_overflow(uint8_t& x) {
  const auto original = x;
  x *= 2;
  return original > x;
}
int main() {
  uint8_t x{1}; 
  printf("uint8_t:\n===\n");
  while (!double_return_overflow(x)w) {
    printf("%u ", x);
  }
}
```
* do..while loop: Like a ‘while’ statement, except that it tests the condition at the end of the loop body.
```
do {
  // The statement in the body of the loop
  // executes upon each iteration
} while (condition);
```
Because the condition evaluates at the end of a loop, you guarantee that the loop will execute at least once.
```
#include <cstdio>
#include <cstdint>

bool double_return_overflow(uint8_t& x) { 
  --snip--
}
int main() {
  uint8_t x{ 1 };
  printf("uint8_t:\n===\n");
  do {
printf("%u ", x);
} while (!double_return_overflow(x));
}
```

* for loop: Execute a sequence of statements multiple times and abbreviates the code that manages the loop variable.
The for loop is an iteration statement containing three special expressions: initialization, conditional, and iteration, as described in the sections that follow.
1. The Initialization Expression: is like the initialization of if: it executes only once before the first iteration executes. Any objects declared within the initialization expression have lifetimes bound by the scope of the for loop.
2. The Conditional Expression: evaluates just before each iteration of the loop. If the conditional evaluates to true, the loop continues to execute. If the conditional evaluates to false, the loop terminates (this behavior is exactly like the conditional of the while and do-while loops).Like if and switch statements, for permits you to initialize objects with scope equal to the statement’s.
3. The Iteration Expression: After each iteration of the for loop, the iteration expression evaluates. This happens before the conditional expression evaluates. Note that the iteration expression evaluates after a successful iteration, so the iteration expression won’t execute before the first iteration.
```
for(initialization; conditional; iteration) { 
  // The statement in the body of the loop
  // executes upon each iteration
}
```
- Iterating with an Index: The for loops are excellent at iterating over an array-like object’s constituent elements. You use an auxiliary index variable to iterate over the range of valid indices for the array-like object. You can use this index to interact with each array element in sequence.
- Ranged-Based for Loops: The range-based for loop iterates over a range of values without needing an index variable. A range (or range expression) is an object that the range- based for loop knows how to iterate over. Many C++ objects are valid range expressions, including arrays. 
```
for(range-declaration : range-expression) { 
  // The statement in the body of the loop 
  // executes upon each iteration
}
```

* nested loops: You can use one or more loop inside any another ‘while’, ‘for’ or ‘do..while’ loop.

## Function
### Declaration
A C++ function consist of two parts:
- Declaration: the return type, the name of the function, and parameters (if any)
- Definition: the body of the function (code to be executed)
Example:
```
void myFunction() { // declaration
  // the body of the function (definition)
}
```
Function declaration is required when you define a function in one source file and you call that function in another file. In such case, you should declare the function at the top of the file calling the function.

### Calling a Function
While creating a C++ function, you give a definition of what the function has to do. To use a function, you will have to call or invoke that function.

When a program calls a function, program control is transferred to the called function. A called function performs defined task and when it’s return statement is executed or when its function-ending closing brace is reached, it returns program control back to the main program.

To call a function, you simply need to pass the required parameters along with function name, and if function returns a value, then you can store returned value. 

## Recursive functions
A function that calls by itself is known as Recursive function. They are just a function that is getting invoked repeatedly. Recursion has got a problem-solving tool, where it divides the larger problems into simple tasks and working out individually to follow an individual sequence.

### Syntax of Recursive Function in C++

### 


## References: 

[2]. https://www.tutorialspoint.com/cplusplus/cpp_functions.htm
[3]. https://www.educba.com/recursive-function-in-c-plus-plus/