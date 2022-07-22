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


    return 0;
}