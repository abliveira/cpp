/*https://www.w3schools.com/cpp/cpp_constructors.asp

A constructor in C++ is a special method that is automatically called when an object of a 
class is created.

To create a constructor, use the same name as the class, followed by parentheses ().
It can be declared outside the class. In this case, use the name of the class followed
by :: and the name of the constructor and it's arguments.

A constructor:
1- Is an automatic function of a class.
2- It will be executed upon creating an object of that class.
3- It does not have type.
4- It does not return any value.
5- It has the same name as the class.
6- It is always public
7- It might have input like a function.
8- We can have several constructors by overloading. 

Destructors
A destructor function is called automatically when the object goes out of scope: 
(1) the function ends 
(2) the program ends 
(3) a block containing local variables ends 
(4) a delete operator is called  
They are declared in the same way of constructors, but using ~ befores its name.

Destructors can be very useful for releasing resources before coming out of the program. 
This can include closing files, releasing memory, and so on.
A destructor can't return a value or take any parameters

Constructor e Destructor -----------------------------------------------------------
Ao herdar classes, o construtor e o destruidor da classe base não são herdados.
No entanto, eles são chamados quando um objeto da classe derivada é criado/excluído.
Primeiramente é chamado o construtor da classe BASE e então o construtor da classe DERIVADA.
No final, é chamado o destruidor da classe DERIVADA e então o destruidor da classe BASE.

*/

#include <iostream>
using namespace std;


// Example - Implementation of Constructor and Destructor inside the class

class MyClass1 {     // The class
  public:           // Access specifier
    MyClass1() {     // Constructor
      cout << "Hello World!" << endl;
    }
    // De modo inverso, é possível criar um Destructor que rodará quando a Objeto for destruído
    ~MyClass1() {
      cout<<"Destructor executed";
    }
};


/*
Constructors can also take parameters (just like regular functions), which can be 
useful for setting initial values for attributes.
When we call the constructor (by creating  an object of the class), 
we pass parameters to the constructor, which will set the 
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
    ~Car2();
};

// Constructor definition outside the class
Car2::Car2(string x, string y, int z) {
  brand = x;
  model = y;
  year = z;
}

Car2::~Car2(){
}


// Example - Constructor and Destructor inheritance

class Mother {
    public:
        Mother() {
            cout <<"Mother ctor"<<endl;
        }
        ~Mother() {
            cout <<"Mother dtor"<<endl;
        }
};

class Daughter: public Mother {
    public:
        Daughter() {
            cout <<"Daughter ctor"<<endl;
        }
        ~Daughter() {
            cout <<"Daughter dtor"<<endl;
        }
};


int main() {
    
  // Example
  // Create an object of MyClass (this will call the constructor and destructor)
  MyClass1 myObj1;    


  // Example
  // Create Car objects and call the constructor with different values
  Car carObj1("BMW", "X5", 1999);
  Car carObj2("Ford", "Mustang", 1969);

  cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";

  
  // Example
  // Create Car objects of a class with a constructor outside the class
  Car2 carObj3("BMW", "X5", 1999);
  Car2 carObj4("Ford", "Mustang", 1969);

  cout << carObj3.brand << " " << carObj3.model << " " << carObj3.year << "\n";
  cout << carObj4.brand << " " << carObj4.model << " " << carObj4.year << "\n";
  cout << endl;


  // Example - Constructor and Destructor inheritance

  Daughter m; // Chama o Constructor da classe base e também da herdada 
  cout << endl;

  return 0;
}
