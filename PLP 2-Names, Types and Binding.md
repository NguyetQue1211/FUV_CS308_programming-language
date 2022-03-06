### 1. C++ Data types

#### Data types in C++ is mainly divided into three types: 

**Primitive Data Types:** These data types are built-in or predefined data types and can be used directly by the user to declare variables. example: int, char , float, bool etc. Primitive data types available in C++ are: 
- Integer
- Character
- Boolean
- Floating Point
- Double Floating Point
- Valueless or Void
- Wide Character

**Derived Data Types:** The data-types that are derived from the primitive or built-in datatypes are referred to as Derived Data Types. These can be of four types namely: 
- Function
- Array
- Pointer
- Reference

**Abstract or User-Defined Data Types:** These data types are defined by user itself. Like, defining a class in C++ or a structure. C++ provides the following user-defined datatypes: 
- Class
- Structure
- Union
- Enumeration
- Typedef defined DataType

### 2. Naming convention 

- The class name should be a noun.
- Use upper case letters as word separators, lower case for the rest of the word in the class name.
- The first character in the class name must be upper case.
- No underscores (‘_’) are permitted in the class name.
- Each method/ function name should begin with a verb.
- The first character of function/ method argument names should be lower case. All words starting after the first letter should be the upper case with class names.
- The variable name should begin with an alphabet.
- Digits may be used in the variable name but only after the alphabet.
- No special symbols can be used in variable names except for the underscore(‘_’).
- No keywords can be used for variable names.
- Pointer variables should be prepended with ‘p’ and place the asterisk ‘*’ close to the variable name instead of pointer type.
- Reference variables should be prepended with ‘r’. This helps to differentiate between the method returning a modifiable object and the same method returning a non-modifiable object.
- Static variables should be prepended with ‘s’.
- The global constants should be all capital letters separated with ‘_’.
- No special character is allowed in the file name except for underscore (‘_’) and dash (‘-‘).

**Examples:** 
```
int length; 
char str[] = "Geeks";
string fullname;
float fValue;
bool is_available();
string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
list<int> mlist1 = {100, 30, 12, 45, 76, 43, 4};
String *pName= new String;
class OdeSolver
```

Add and divide ints and floats: the result will be converted to float.
```
int main()
{
    float a = 2.5;
    int b = 3;
    std::cout << "Result " << a + b << std::endl; 
    std::cout << "Result " << a/b << std::endl; 
    return 0;
}
```


### 3. Type Conversion in C++
A type cast is basically a conversion from one type to another. There are two types of type conversion:

**1. Implicit Type Conversion Also known as ‘automatic type conversion’.**
- Done by the compiler on its own, without any external trigger from the user.
- Generally takes place when in an expression more than one data type is present. In such condition type conversion (type promotion) takes place to avoid lose of data.
- All the data types of the variables are upgraded to the data type of the variable with largest data type

bool -> char -> short int -> int -> 

unsigned int -> long -> unsigned -> 

long long -> float -> double -> long double

- It is possible for implicit conversions to lose information, signs can be lost (when signed is implicitly converted to unsigned), and overflow can occur (when long long is implicitly converted to float).

**2. Explicit Type Conversion: This process is also called type casting and it is user-defined. Here the user can typecast the result to make it of a particular data type.**
In C++, it can be done by two ways:
- Converting by assignment: This is done by explicitly defining the required type in front of the expression in parenthesis. This can be also considered as forceful casting.
Syntax:

```
#include <iostream>
using namespace std;
  
int main()
{
    double x = 1.2;
  
    // Explicit conversion from double to int
    int sum = (int)x + 1;
  
    cout << "Sum = " << sum;
  
    return 0;
}
```

- Conversion using Cast operator: A Cast operator is an unary operator which forces one data type to be converted into another data type.
C++ supports four types of casting:
* Static Cast
* Dynamic Cast
* Const Cast
* Reinterpret Cast
Example:
```
#include <iostream>
using namespace std;
int main()
{
	float f = 3.5;

	// using cast operator
	int b = static_cast<int>(f);

	cout << b;
}

```

### 4. Discussion 

### 5. Reference: 

[Naming convention ](https://www.geeksforgeeks.org/naming-convention-in-c/)

[Type Conversion in C++](https://www.geeksforgeeks.org/type-conversion-in-c/)