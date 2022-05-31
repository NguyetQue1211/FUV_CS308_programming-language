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

## C++ Class Member Functions

Member functions are functions that are declared inside the class definition and deal with the class's data members. Member functions can be defined either inside or outside of the class declaration.

If the member function is defined within the class definition, it may be defined directly; however, if it is defined outside of the class, we must use the scope resolution:: operator in conjunction with the class name :: the function name.

```
class Cube
{
    public:
    int side;
    /*
        Declaring function getVolume 
        with no argument and return type int.
    */
    int getVolume();     
};
```
If we define the function inside a class, we don't need to declare it first; instead, we may define it immediately.

```
class Cube
{
    public:
    int side;
    int getVolume()
    {
        return side*side*side;      //returns volume of cube
    }
};
```

If we want to define the member function outside of the class definition, we must first declare it inside the class definition and then define it outside of it.

```
class Cube
{
    public:
    int side;
    int getVolume();
}

// member function defined outside class definition
int Cube :: getVolume()
{
    return side*side*side;
}
```
## Calling Class Member Function in C++

Using the dot operator, we can access the public member functions through the class object, just like we can access a data member in the class (.).

A basic code example is shown below, in which we create a Cube object and call the member method getVolume():
```
int main()
{
    Cube C1;
    C1.side = 4;    // setting side value
    cout<< "Volume of cube C1 = "<< C1.getVolume();
}
```
## Constructor
In C++, a constructor is a particular member function of a class whose job is to initialize the class's object; it's unique since it has the same name as the class. Because it produces the value of data members during object initialization, it is termed a constructor. When an object is formed, the compiler calls the constructor. A constructor has no return type since it defines the value of a data member.

```
class scaler {
  public:
    scaler() { //constructor
      // constructor body
    }
};
```
* According to our program's design, a constructor can be made public, private, or protected. Because public methods are available from anywhere, constructors are frequently made public, allowing us to build the class's object from anywhere in the code.
* In C++, a constructor cannot be inherited. A derived class can, however, invoke the constructor of the base class. 
* Constructor functions are not inherited and cannot be accessed by their addresses.
* The constructor in C++ cannot be virtual. 

### Types of Constructors in C++
There are 4 types of constructors in C++:
* Default Constructors
* Parameterized Constructors
* Copy Constructors
* Dynamic Constructors

## Destructor

When an object is destroyed, the destructor member function is invoked immediately. When an object passes out of scope, i.e. when a function finishes, the local objects generated within it are likewise destroyed, the destructor is invoked automatically by the compiler. The destructor has the same name as the class, but it has a tilde(~) before it. A destructor doesn't have a return type and doesn't take any parameters.

```
class scaler {
  public:
    scaler(); //constructor
    ~scaler(); //destructor
};
```
* A destructor deallocates memory occupied by the object when it’s deleted.
* A destructor cannot be overloaded
* A destructor is always called in the reverse order of the constructor. 
* A destructor can be written anywhere in the class definition.


## Interfaces in C++ (Abstract Classes)

An interface explains a C++ class's behavior or capabilities without committing to a specific implementation of that class.

Abstract classes are used to implement C++ interfaces. These abstract classes should not be confused with data abstraction, which is a notion that separates implementation details from connected data.

An abstract class (also known as an ABC) is used to provide a suitable foundation class from which further classes can be derived. Abstract classes are solely used as a user interface and cannot be utilized to create objects. A compilation error occurs when an object of an abstract class is attempted to be instantiated.

Classes that can be used to instantiate objects are called concrete classes.

```
// Abstract class
abstract class Animal {
  // Abstract method (does not have a body)
  public abstract void animalSound();
  // Regular method
  public void sleep() {
    System.out.println("Zzz");
  }
}

// Subclass (inherit from Animal)
class Pig extends Animal {
  public void animalSound() {
    // The body of animalSound() is provided here
    System.out.println("The pig says: wee wee");
  }
}

class Main {
  public static void main(String[] args) {
    Pig myPig = new Pig(); // Create a Pig object
    myPig.animalSound();
    myPig.sleep();
  }
}
```

## References: 
[1]. [Tutorialspoint.com](tutorialspoint.com/cplusplus/cpp_classes_objects.htm#)

[2]. [w3school.com](https://www.w3schools.com/cpp/cpp_classes.asp)

[3]. [Constructor and Destructor](https://www.scaler.com/topics/constructor-and-destructor-in-cpp/) 