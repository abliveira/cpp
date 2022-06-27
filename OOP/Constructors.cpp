/*https://www.w3schools.com/cpp/cpp_constructors.asp

A constructor in C++ is a special method that is automatically called when an object of a 
class is created.

To create a constructor, use the same name as the class, followed by parentheses ():
Note: The constructor has the same name as the class, it is always public, and it does 
not have any return value.

Construct 

1- A constructor is an automatic function of a class.
2- A constructor will be executed upon creating an object of that class.
3- A constructor does not have type.
4- A constructor does not return any value.
5- A constructor has the same name as the class.
6- A constructor might have input like a function.
7- We can have several constructors by overloading. 

A destructor function is called automatically when the object goes out of scope: 
(1) the function ends 
(2) the program ends 
(3) a block containing local variables ends 
(4) a delete operator is called  

*/

#include <iostream>

using namespace std;

class MyClass1 {     // The class
  public:           // Access specifier
    MyClass1() {     // Constructor
      cout << "Hello World!" << endl;
    }
    // De modo inverso, é possível criar um Destructor que rodará quando a Objeto for destruído
    ~MyClass1()
          {
              cout<<"Destructor executed";
          }
};



/*
Constructors can also take parameters (just like regular functions), which can be 
useful for setting initial values for attributes.

The following class have brand, model and year attributes, and a constructor with 
different parameters. Inside the constructor we set the attributes equal to the 
constructor parameters (brand=x, etc). When we call the constructor (by creating 
an object of the class), we pass parameters to the constructor, which will set the 
value of the corresponding attributes to the same:
*/

class Car {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car(string x, string y, int z) { // Constructor with parameters
      brand = x;
      model = y;
      year = z;
    }
};



/* Just like functions, constructors can also be defined outside the class. 
First, declare the constructor inside the class, and then define it outside 
of the class by specifying the name of the class, followed by the scope 
resolution :: operator, followed by the name of the constructor (which is 
the same as the class):
*/

class Car2 {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car2(string x, string y, int z); // Constructor declaration
};

// Constructor definition outside the class
Car2::Car2(string x, string y, int z) {
  brand = x;
  model = y;
  year = z;
}



int main() {
    
  MyClass1 myObj1;    // Create an object of MyClass (this will call the constructor)
  
  
  
  // Create Car objects and call the constructor with different values
  Car carObj1("BMW", "X5", 1999);
  Car carObj2("Ford", "Mustang", 1969);

  // Print values
  cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  
  
  
  Car2 carObj3("BMW", "X5", 1999);
  Car2 carObj4("Ford", "Mustang", 1969);

  // Print values
  cout << carObj3.brand << " " << carObj3.model << " " << carObj3.year << "\n";
  cout << carObj4.brand << " " << carObj4.model << " " << carObj4.year << "\n";
  
  return 0;
}
