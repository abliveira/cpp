/*
https://www.w3schools.com/cpp/cpp_oop.asp

A class in C++ is the building block that leads to Object-Oriented programming. It 
is a user-defined data type, which holds its own data members and member functions,
which can be accessed and used by creating an instance of that class

An Object is an instance of a Class. When a class is defined, no memory is allocated 
but when it is instantiated (i.e. an object is created) memory is allocated.

When working with an object, use the dot member selection operator (.).
When working with a pointer to the object, use the arrow member selection operator (->).

Example:
MyClass obj;
    MyClass *ptr = &obj;
    ptr->myPrint();
*/

#include <iostream>
#include <string>

using namespace std;

// Create a Car class with some attributes
class Car {        // The class

    /*The public keyword is an access specifier, which specifies that members (attributes and methods)
    of the class are accessible from outside the class
    
    If no access specifier is defined, all members of a class are set to private by default. 
    
    */
  public:              // Access specifier
    string brand;   
    string model;
    int year;
};



/* Methods are functions that belongs to the class.
There are two ways to define functions that belongs to a class:
- Inside class definition
- Outside class definition*/

class MyClass1 {        // The class
  private:
    string hello = "Hello World ";
  public:              // Access specifier
    void myMethod() {  // Method/function defined inside the class
      cout << hello << "1!" << endl;
    }
};

/*To define a function outside the class definition, you have to declare it inside the
class and then define it outside of the class. This is done by specifying the name
of the class, followed the scope resolution :: operator, followed by the name of the 
function:*/

class MyClass2 {        // The class
  private:
    string hello = "Hello World ";
  public:              // Access specifier
    void myMethod();   // Method/function declaration
};

// Method/function definition outside the class
void MyClass2::myMethod() {
  cout << hello << "2!" << endl;
}


int main() {
  // Create an object of Car
  Car carObj1;
  carObj1.brand = "BMW";
  carObj1.model = "X5";
  carObj1.year = 1999;

  // Create another object of Car
  Car carObj2;
  carObj2.brand = "Ford";
  carObj2.model = "Mustang";
  carObj2.year = 1969;

  // Print attribute values
  cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  
  
  MyClass1 myObj1;     // Create an object of MyClass
  myObj1.myMethod();  // Call the method
  
  MyClass2 myObj2;     // Create an object of MyClass
  myObj2.myMethod();  // Call the method
  
  
  return 0;
}
