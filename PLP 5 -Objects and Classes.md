# Objects and Classes

The major goal of C++ programming is to bring object orientation to the C programming language, and classes, also known as user-defined types, are the key component of C++ that facilitates object-oriented programming.

A class specifies an object's form by combining data representation and methods for modifying that data into a single package. Members of a class are the data and methods that make up the class.

## C++ Class Definitions

When you design a class, you are essentially creating a blueprint for a data type. This doesn't describe any data, but it does define what the class name signifies, that is, what a class object will be made up of and what actions can be done on it.

A class definition begins with the keyword class, then the class name, and finally the class body, which is contained by a pair of curly brackets. A semicolon or a series of declarations must come after a class definition. For example: 

```
class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};
```

The access properties of the members of the class that follows it are determined by the keyword public. Anywhere inside the scope of the class object, a public member can be accessed from outside the class. You may also make a class's members private or protected, which we'll cover in a later section.

## Define C++ Objects

The blueprints for things are provided by classes, therefore an object is essentially constructed from a class. Objects of a class are declared in the same way as variables of fundamental types are declared.

```
MyClass class205;
MyClass class307;
```

## Accessing the Data Members

The direct member access operator can be used to access the public data members of a class's objects (.). Let's have a look at the following example to see what we're talking about:

```
class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15; 
  myObj.myString = "Some text";

  // Print attribute values
  cout << myObj.myNum << "\n";
  cout << myObj.myString;
  return 0;
}
```

## References: 
[1]. [Tutorialspoint.com](tutorialspoint.com/cplusplus/cpp_classes_objects.htm#)
[2]. [w3school.com](https://www.w3schools.com/cpp/cpp_classes.asp)