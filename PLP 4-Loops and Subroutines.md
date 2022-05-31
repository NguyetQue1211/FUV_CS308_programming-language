# Loops and Subroutines in C++

## Loops
C++ programming language provides the following type of loops to handle looping requirements
### while loop
Repeats a statement or group of statements while a given condition is true. It tests the condition before executing the loop body.
```
while (condition) {
// The statement in the body of the loop 
// executes upon each iteration
}
```
Before executing an iteration of the loop, the while loop evaluates the condition expression. If true, the loop continues. If false, the loop terminates.

**Example**

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
### do..while loop: 
Like a ‘while’ statement, except that it tests the condition at the end of the loop body.
```
do {
  // The statement in the body of the loop
  // executes upon each iteration
} while (condition);
```
Because the condition evaluates at the end of a loop, you guarantee that the loop will execute at least once.

**Example**
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

### for loop: 
Execute a sequence of statements multiple times and abbreviates the code that manages the loop variable.
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

### nested loops: 
You can use one or more loop inside any another ‘while’, ‘for’ or ‘do..while’ loop.

## Function

A function is a block of code that performs a specific task.

Suppose we need to create a program to create a circle and color it. We can create two functions to solve this problem:

a function to draw the circle
a function to color the circle
Dividing a complex problem into smaller chunks makes our program easy to understand and reusable.

There are two types of function:

- Standard Library Functions: Predefined in C++
- User-defined Function: Created by users


### Function Declarations

The syntax to declare a function is:

```
returnType functionName (parameter1, parameter2,...) {
    // function body   
}
```
Here's an example of a function declaration.
```
// function declaration
void greet() {
    cout << "Hello World";
}
```
Here,

- the name of the function is greet()
- the return type of the function is void
- the empty parentheses mean it doesn't have any parameters
- the function body is written inside {}

### Calling a function 

In the above program, we have declared a function named greet(). To use the greet() function, we need to call it.

Here's how we can call the above greet() function.

```
int main() {
     
    // calling a function   
    greet(); 

}
```

**Example**
```
#include <iostream>
using namespace std;

// declaring a function
void greet() {
    cout << "Hello there!";
}

int main() {

    // calling the function
    greet();

    return 0;
}

//output: Hello there!
```

### Function Parameter
As mentioned above, a function can be declared with parameters (arguments). A parameter is a value that is passed when declaring a function.

**Example**

```
void printNum(int num) {
    cout << num;
}
```
Here, the int variable num is the function parameter.
We pass a value to the function parameter while calling the function.

**Example**

```
int main() {
    int n = 7;
    
    // calling the function
    // n is passed to the function as argument
    printNum(n);
    
    return 0;
}
```

### Return statement 

In the above programs, we have used void in the function declaration. For example,

```
void displayNumber() {
    // code
}
```

This means the function is not returning any value.

It's also possible to return a value from a function. For this, we need to specify the returnType of the function during function declaration.

Then, the return statement can be used to return a value from a function.

**Example**

```
int add (int a, int b) {
   return (a + b);
}
```

Here, we have the data type int instead of void. This means that the function returns an int value.

The code return (a + b); returns the sum of the two parameters as the function value.

The return statement denotes that the function has ended. Any code after return inside the function is not executed.

### Function Prototype

In C++, the code of function declaration should be before the function call. However, if we want to define a function after the function call, we need to use the function prototype.

**Example**

```
// function prototype
void add(int, int);

int main() {
    // calling the function before declaration.
    add(5, 3);
    return 0;
}

// function definition
void add(int a, int b) {
    cout << (a + b);
}
```
In the above code, the function prototype is:

```
void add(int, int);
```
This provides the compiler with information about the function name and its parameters. That's why we can use the code to call a function before the function has been defined.

The syntax of a function prototype is:

```
returnType functionName(dataType1, dataType2, ...);
```

### Recursive functions

A function that calls by itself is known as Recursive function. They are just a function that is getting invoked repeatedly. Recursion has got a problem-solving tool, where it divides the larger problems into simple tasks and working out individually to follow an individual sequence.

```
void recurse()
{
    ... .. ...
    recurse();
    ... .. ...
}

int main()
{
    ... .. ...
    recurse();
    ... .. ...
}
```

The recursion continues until some condition is met.

To prevent infinite recursion, if...else statement (or similar approach) can be used where one branch makes the recursive call and the other doesn't.

**Example** Factorial of a Number Using Recursion
```
// Factorial of n = 1*2*3*...*n

#include <iostream>
using namespace std;

int factorial(int);

int main() {
    int n, result;

    cout << "Enter a non-negative number: ";
    cin >> n;

    result = factorial(n);
    cout << "Factorial of " << n << " = " << result;
    return 0;
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

// output: 
// Enter a non-negative number: 4
// Factorial of 4 = 24
```

## Pass by 
In C++, we can pass parameters to a function either by pointers or by reference. In both cases, we get the same result. So, what is the difference between Passing by Pointer and Passing by Reference in C++?

Lets first understand what Passing by Pointer and Passing by Reference in C++ mean:
1) Passing by Pointer: Here, the memory location of the variables is passed to the parameters in the function, and then the operations are performed.

```
#include <iostream>
using namespace std;
 
void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}
 
// Driver Code
int main()
{
    int a = 45, b = 35;
    cout << "Before Swap\n";
    cout << "a = " << a << " b = " << b << "\n";
 
    swap(&a, &b);
 
    cout << "After Swap with pass by pointer\n";
    cout << "a = " << a << " b = " << b << "\n";
}
```

```
//output
Before Swap
a = 45 b = 35
After Swap with pass by pointer
a = 35 b = 45
```

2) Passing by Reference: It allows a function to modify a variable without having to create a copy of it. We have to declare reference variables. The memory location of the passed variable and parameter is the same and therefore, any change to the parameter reflects in the variable as well

```
#include <iostream>
using namespace std;
void swap(int& x, int& y)
{
    int z = x;
    x = y;
    y = z;
}
 
int main()
{
    int a = 45, b = 35;
    cout << "Before Swap\n";
    cout << "a = " << a << " b = " << b << "\n";
 
    swap(a, b);
 
    cout << "After Swap with pass by reference\n";
    cout << "a = " << a << " b = " << b << "\n";
}
```

```
//output
Before Swap
a = 45 b = 35
After Swap with pass by reference
a = 35 b = 45
```

**Difference Between Reference Variable and Pointer Variable**

A reference is the same object, just with a different name and a reference must refer to an object. Since references can’t be NULL, they are safer to use. 

- A pointer can be re-assigned while a reference cannot, and must be assigned at initialization only.
- The pointer can be assigned NULL directly, whereas the reference cannot.
- Pointers can iterate over an array, we can use increment/decrement operators to go to the next/previous item that a pointer is pointing to.
- A pointer is a variable that holds a memory address. A reference has the same memory address as the item it references.
- A pointer to a class/struct uses ‘->’ (arrow operator) to access its members whereas a reference uses a ‘.’ (dot operator)
- A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.

## References: 
[0]. C++ Crash Course by JOSH LOSPINOSO

[1]. [C++ Functions from tutorialspoint.com](https://www.tutorialspoint.com/cplusplus/cpp_functions.htm)

[2]. [C++ Functions from programz.com](https://www.programiz.com/cpp-programming/function)

[3]. [C++ Recursion](https://www.programiz.com/cpp-programming/recursion)

[4]. [Passing By Pointer Vs Passing By Reference in C++](https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/)