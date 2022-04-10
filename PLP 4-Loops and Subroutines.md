# Loops and Subroutines in C++

## Loops
C++ programming language provides the following type of loops to handle looping requirements
* while loop: Repeats a statement or group of statements while a given condition is true. It tests the condition before executing the loop body.
* for loop: Execute a sequence of statements multiple times and abbreviates the code that manages the loop variable.
* do..while loop: Like a ‘while’ statement, except that it tests the condition at the end of the loop body.
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