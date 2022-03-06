## Names, Types and Binding

### Naming 
#### Rules

Identifiers in C++ can be composed of letters, digits, and the underscore character. 

The language imposes no limit on name length. Identifiers must begin with either a letter or an underscore. 

Identifiers are case-sensitive; upper- and lowercase letters are distinct.

### Convention

About naming convention, there are some community's standard: 

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

#### Reserved words
Keywords (also known as reserved words) have special meaning to the C++ compiler and are always written or typed in short(lower) cases. here are keywords in C++: asm, double, new, auto, else, operator, template, break,	enum, private, this,
case, extern, protected, throw, catch, float, public, try, continue, if, signed, virtual, default, inline, sizedof, void
delete, int, static, volatile, do, long, struct, while,..

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

### Typing

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


#### C++ is statically typed. Languages check the types and look for type errors during runtime.

#### C++ is a strongly typed. however, C++ allow some implicit conversions between types, making it “not quite as strong as it could be”-typed

#### C++ has both implicit and explicit conversion. 

A type cast is basically a conversion from one type to another. There are two types of type conversion:

1. Implicit Type Conversion Also known as ‘automatic type conversion’.

2. Explicit Type Conversion: This process is also called type casting and it is user-defined. Here the user can typecast the result to make it of a particular data type. In C++, it can be done by two ways:

- Converting by assignment: This is done by explicitly defining the required type in front of the expression in parenthesis. This can be also considered as forceful casting.
- Conversion using Cast operator: A Cast operator is an unary operator which forces one data type to be converted into another data type.
C++ supports four types of casting:
* Static Cast
* Dynamic Cast
* Const Cast
* Reinterpret Cast

#### Mutable and Immutable data
##### Mutable
##### Immutable
### Discussion 
If C++ is a strongly typed language, then why does it allow these type of implicit conversions?

### Reference: 

[1].[Naming convention ](https://www.geeksforgeeks.org/naming-convention-in-c/)

[2].[Type Conversion in C++](https://www.geeksforgeeks.org/type-conversion-in-c/)

[3]. C++ Primer, Fifth Edition

[4]. https://www.youtube.com/watch?v=ngvJ2Z3VBpk