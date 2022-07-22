/*
Every object in C++ has access to its own address through an important
pointer called this pointer. The this pointer is an implicit parameter
to all member functions. Therefore, inside a member function, this may
be used to refer to the invoking object.

Friend functions do not have a this pointer, because friends are not
members of a class. Only member functions have a this pointer.

To understand ‘this’ pointer, it is important to know how objects look at
functions and data members of a class.
- Each object gets its own copy of the data member.
- All-access the same function definition as present in the code segment.
Meaning each object gets its own copy of data members and all objects share a
single copy of member functions.

So, to  proper access and updated data members are accessed, the compiler 
supplies an implicit pointer along with the names of the functions as ‘this’.

The ‘this’ pointer is passed as a hidden argument to all nonstatic member function 
calls and is available as a local variable within the body of all nonstatic 
functions. ‘this’ pointer is not available in static member functions as 
static member functions can be called without any object (with class name).

For a class X, the type of this pointer is ‘X* ‘. Also, if a member function 
of X is declared as const, then the type of this pointer is ‘const X *’

You may be wondering why it's necessary to use the this keyword,
when you have the option of directly specifying the variable.
The this keyword has an important role in operator overloading.

Following are the situations where ‘this’ pointer is used:
1) When local variable’s name is same as member’s name
*/

#include <iostream>
using namespace std;


// Exemplo 1 -------------------------------------------

class MyClass {
    public:
        MyClass(int a) : var(a)
        { }
        void printInfo() {
            cout << var <<endl;
            cout << this->var <<endl;
            cout << (*this).var <<endl; 
        }
    private:
        int var;
};


// Exemplo 2 -------------------------------------------
// When local variable’s name is same as member’s name


/* local variable is same as a member's name */
class Test2 {
    private:
        int x = 10;
    public:
        void setX (int x) {
            // The 'this' pointer is used to retrieve the object's x
            // hidden by the local variable 'x'
            cout << "x = " << x << endl; // Output: 20
            cout << "this x = " << this->x << endl; // Output: 10
            this->x = x;
        }
        void print() {
            cout << "x = " << x << endl; // Output: 20
        }
};


// Exemplo 3 -------------------------------------------

class Test3 {
    private:
        int x;
        int y;
    public:
        Test3(int x = 0, int y = 0) { 
            this->x = x; 
            this->y = y; 
        }
        Test3 &setX(int a) { 
            x = a; 
            return *this; 
        }
        Test3 &setY(int b) { 
            y = b; 
            return *this; 
        }
        void print() { 
            cout << "x = " << x << " y = " << y << endl;
        }
};
  

int main() {

    // Exemplo 1 -------------------------------------------

    MyClass obj(42);
    obj.printInfo();


    // Exemplo 2 -------------------------------------------

    Test2 obj2;
    int x = 20;
    obj2.setX(x);
    obj2.print();


    // Exemplo 3 -------------------------------------------

    Test3 obj3(5, 5);
    // Chained function calls.  All calls modify the same object
    // as the same object is returned by reference
    obj3.setX(10).setY(20);

    obj3.print();

    return 0;
}