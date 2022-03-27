# Selection Control Structures in C++

## Boolean Types
- Boolean types have two states: true and false. The sole Boolean type is bool. Integer types and the bool types convert readily: the true state converts to 1, and false converts to 0. Any non-zero integer converts to true, and 0 con- verts to false.
- To initialize Boolean types, we use two Boolean literals, true and false.

## Conditional statements
Conditional statements allow you to make decisions in your programs. These decisions rest on Boolean expressions, which evaluate to true or false. For example, you can use comparison operators, such as “greater than” or “not equal to,” to build Boolean expressions.
- An ```if``` statement contains a Boolean expression and one or more nested statements. Depending on whether the Boolean evaluates to true or false, the program decides which nested statement to execute. There are several forms of if statements, but the basic usage follows:

```
if (boolean expression) {
    statement1;
    statement2;
    statement3;
    --snip--;
```
If the Boolean expression is true, all the statements in the compound statement execute; otherwise, none of them do.

- You can elaborate the ```if``` statement using ```else if``` and ```else``` statements. These optional additions allow you to describe more complicated branching behavior,


```
if (boolean expression 1) {
    statement1;
} else if (boolean expression 2) {
    statement2;
} else {
    statement3;
}
```

First, boolean expression 1 is evaluated. If boolean expression 1 is true, statement1 is evaluated, and the if statement stops executing. If boolean expression 1 is false, boolean expression 2 is evaluated. If true, statement2 is evaluated. Otherwise, statement3 is evaluated. Note that statement1, statement2, and statement3 are mutually exclusive and together they cover all possible outcomes of the if statement. Only one of the three will be evaluated.

You can include any number of else if clauses or omit them entirely. As with the initial if statement, the Boolean expression for each else if clause is evaluated in order. When one of these Boolean expressions evaluates to true, evaluation stops and the corresponding statement executes. If no else if evaluates to true, the else clause’s statement3 always executes. (As with the else if clauses, the else is optional.)

## Short-circuiting in C++
In C++ short-circuiting occurs while evaluating ‘&&’ (AND) and ‘||'(OR) logical operators. While evaluating ‘&&’ operator if the left-hand side of ‘&&’ gives false, then the expression will always yield false irrespective of the value of the right-hand side of ‘&&’, so checking right-hand side of ‘&&’ makes no sense. So, in this situation evaluation of the right-hand side is avoided by the compiler. Similarly, in the case of logical OR ‘||’ operation when the left-hand side gives ‘true’, the result of the expression will always be true irrespective of the value of the right-hand side.

```
#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 1, c = 1;
 
    if (a == b || c++) {
        cout << "Value of 'c' will"
             << "  not increment due"
             << " to short-circuit"
             << endl;
    }
    else {
        cout << "Value of 'c' "
             << " is incremented as there"
             << " is no short-circuit"
             << endl;
    }
}
```

## Dangling else

The dangling else is a problem in programming of parser generators in which an optional else clause in an if–then(–else) statement results in nested conditionals being ambiguous. Formally, the reference context-free grammar of the language is ambiguous, meaning there is more than one correct parse tree.

C++ has chosen to resolve the Dangling-Else ambiguity uses the following rule: An else keyword always associates with the nearest preceeding if keyword that does NOT cause a syntax error

The C++ compiler read this program as follow: 
```
int num = 10;
if (num < 100)
    if (num > 20)
        num++;
    else
        num += 2;
```
It will associate the else keyword with the second if keyword

By using ```{ }``` the program now can be written as: 
```
int num = 10;
if (num < 100){}
    if (num > 20)
        num++;
} else {}
    num += 2;
}
```
Associating the else with the second if will now result in a syntax error

## C++ Switch Statements
Use the switch statement to select one of many code blocks to be executed.
```
switch(expression) {
  case x:
    // code block
    break;
  case y:
    // code block
    break;
  default:
    // code block
}
```
This is how it works:
- The switch expression is evaluated once
- The value of the expression is compared with the values of each case
- If there is a match, the associated block of code is executed
- The break and default keywords are optional, and will be described later in this chapter
### The break Keyword
When C++ reaches a break keyword, it breaks out of the switch block.
This will stop the execution of more code and case testing inside the block.
When a match is found, and the job is done, it's time for a break. There is no need for more testing.
### The default Keyword
The default keyword specifies some code to run if there is no case match:
### use “continue” to have all of the conditions evaluated
You can use keyword "continue" to make all the conditions evaluated

```
#include <iostream>

using namespace std;

int main()
{
    int num = 3;
    switch(num)
    {
        case 1: 
            cout << "num is 1";
            break;
        case 2:
            cout << "num is 2";
            break;
        case 3:
            cout << "num is 3";
            break;
        default: 
            cout << "no matched values";
            break;
     }
    return 0;
}
```

```
#include <iostream>

using namespace std;

int main()
{
    int i=1;
    while(true) {
    cout << "inside while " << i << "\n";
    switch( i )
    {
        case 1: 
        case 2:
        case 3:
            cout << " inside switch " << i << "\n";
            i++;
            continue;
        default: 
            cout << "inside default\n";
            break;
     }
     cout << "Bottom of while " << i << endl;
     break;
    
        
    }

    return 0;
}
```

## references: 
[0]. C++ Crash Course by JOSH LOSPINOSO

[1]. [Short-circuiting in C++](https://www.geeksforgeeks.org/short-circuiting-in-c-and-linux/)

[2]. [Dangling else](https://en.wikipedia.org/wiki/Dangling_else)

[3]. [C++ Switch](https://www.w3schools.com/cpp/cpp_switch.asp)