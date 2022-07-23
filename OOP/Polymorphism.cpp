/* 
https://www.geeksforgeeks.org/polymorphism-in-c/?ref=lbp

Polymorphism is considered as one of the important features of Object-Oriented Programming.
In C++, polymorphism is mainly divided into two types:

- Compile-time Polymorphism
    This type of polymorphism is achieved by function overloading or operator overloading.

        - Function Overloading: When there are multiple functions with the same name
        but different parameters, then the functions are said to be overloaded.
        Functions can be overloaded by changing the number of arguments or/and
        changing the type of arguments. (Ver em Functions/Overloading.cpp).

        - Operator Overloading: C++ also provides the option to overload operators.
        For example, we can make use of the addition operator (+) for string class
        to concatenate two strings. We know that the task of this operator is to add
        two operands. So a single operator ‘+’, when placed between integer operands,
        adds them and when placed between string operands, concatenates them.

- Runtime Polymorphism
    This type of polymorphism is achieved by Function Overriding.

        - Function overriding occurs when a derived class has a definition for one of the
        member functions of the base class. That base function is said to be overridden. 


Virtual Functions
https://www.geeksforgeeks.org/virtual-function-cpp/

OBS: Virtual Classes em OOP/Inheritance.cpp

A virtual function is a member function which is declared within a base class 
and is re-defined (overridden) by a derived class. When you refer to a derived 
class object using a pointer or a reference to the base class, you can call a 
virtual function for that object and execute the derived class’s version of the function. 

- Virtual functions ensure that the correct function is called for an object, regardless 
    of the type of reference (or pointer) used for function call.
- They are mainly used to achieve Runtime polymorphism
- Functions are declared with a virtual keyword in base class.
- The resolving of function call is done at runtime.

Rules for Virtual Functions
    Virtual functions cannot be static.
    A virtual function can be a friend function of another class.
    Virtual functions should be accessed using pointer or reference of base class type 
        to achieve runtime polymorphism.
    The prototype of virtual functions should be the same in the base as well as derived class.
    They are always defined in the base class and overridden in a derived class. It is not 
        mandatory for the derived class to override (or re-define the virtual function), in
        that case, the base class version of the function is used.
    A class may have virtual destructor but it cannot have a virtual constructor.

Pure Virtual Function
In some situations you'd want to include a virtual function in a base class so that it may be
redefined in a derived class to suit the objects of that class, but that there is no meaningful
definition you could give for the function in the base class.
The virtual member functions without definition are known as pure virtual functions. They 
basically specify that the derived classes define that function on their own.
The = 0 tells the compiler that the function has no body.
A pure virtual function basically defines, that the derived classes will have that function
defined on their own.
Every derived class inheriting from a class with a pure virtual function must override that
function.
If the pure virtual function is not overridden in the derived class, the code fails to compile
and results in an error when you try to instantiate an object of the derived class.

Abstract Classes
You cannot create objects of the base class with a pure virtual function.
These classes are called abstract. They are classes that can only be used as base classes, 
and thus are allowed to have pure virtual functions.
It can be used to create pointers and take advantage of all its polymorphic abilities.


olhar: 
https://www.geeksforgeeks.org/operator-overloading-c/?ref=lbp
https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-cpp/
https://betterprogramming.pub/inheritance-vs-composition-2fa0cdd2f939
- tem parte sobre composition em polimorfismo


*/ 

#include<iostream>
using namespace std;

#include <bits/stdc++.h> // for C++ program function overriding


// Operator Overloading -------------------------------------------------

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
      
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
        Complex res;
        // Poderia utilizar o ponteiro this aqui
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { 
            cout << real << " + i" << imag << endl;
        }
};




// Function overriding -------------------------------------------------

class base {
    public:
        virtual void print () {
            cout << "print base class" << endl;
        }
        void show () { 
            cout << "show base class" << endl;
        }
};
  
class derived : public base {
    public:
        // print () is already virtual function in derived class,
        // we could also declared as virtual void print () explicitly
        void print () { 
            cout << "print derived class" << endl; 
        }
        void show () {
            cout << "show derived class" << endl;
        }
};


// Example

class Enemy {
    protected: 
        int attackPower;
    public:
        void setAttackPower(int a){
            attackPower = a;
        }
};

class Ninja: public Enemy {
    public:
        void attack() {
            cout << "Ninja! - "<<attackPower<<endl;
        }
};

class Monster: public Enemy {
    public:
        void attack() {
            cout << "Monster! - "<<attackPower<<endl;
        }
};


// Example - Virtual Function

class Vehicle {
    public:
        virtual void accelerate() {
            cout << "accelerate something!"<<endl;
        }
};

class Car: public Vehicle {
    public:
        void accelerate() {
            cout << "accelerate car!"<<endl;
  }
};

class Truck: public Vehicle {
    public:
        void accelerate() {
            cout << "accelerate truck!"<<endl;
        }
};


// Example - Pure Virtual Function
class Fruit {
    public:
        virtual void eat() = 0;
};

class Apple: public Fruit {
    public:
        void eat() {
            cout << "Apple!"<<endl;
        }
};

class Orange: public Fruit {
    public:
        void eat() {
            cout << "Orange!"<<endl;
        }
};

int main() {

    // Operator Overloading -------------------------------------------------
     
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
    // In the above example, the operator ‘+’ is overloaded. 
    // Usually, this operator is used to add two numbers (integers or
    // floating point numbers), but here the operator is made to perform
    // the addition of two imaginary or complex numbers.


    // Function overriding -------------------------------------------------

    base *bptr;
    derived d;
    bptr = &d;
      
    // Virtual function, binded at runtime (Runtime polymorphism)
    bptr->print();
      
    // Non-virtual function, binded at compile time
    bptr->show();
    // We would have achieved the same result by calling the functions directly on the objects.
    // However, it's faster and more efficient to use pointers.

    // Example
    Ninja n;
    Monster m;
    Enemy *e1 = &n;
    Enemy *e2 = &m;

    e1->setAttackPower(20);
    e2->setAttackPower(80);

    n.attack();
    m.attack();

    // Example - Virtual Function
    Car o;
    Truck p;
    Vehicle *e3 = &o;
    Vehicle *e4 = &p;

    // This example serves to demonstrate the concept of polymorphism; 
    // We are using pointers to call the same accelerate() function, and generating different results.
    e3->accelerate();
    e4->accelerate();


    // Example - Pure Virtual Function
    Apple j;
    Orange k;
    Fruit *e5 = &j;
    Fruit *e6 = &k;

    e5->eat();
    e6->eat();

    return 0;
}