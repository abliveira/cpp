/*
https://www.geeksforgeeks.org/operator-overloading-c

In C++, we can make operators work for user-defined classes. We can provide the
operators with a special meaning for a data type, this ability is known as operator
overloading.
Operator overloading is a compile-time polymorphism. It is an idea of giving special
meaning to an existing operator in C++ without changing its original meaning.
For example, we can overload an operator ‘+’ in a class like String so that we can
concatenate two strings by just using +. Other example classes where arithmetic 
operators may be overloaded are Complex Numbers, Fractional Numbers, Big Integer, etc.

Consider the example:

class A {
};

main() {
    A a1,a2,a3;
    a3 = a1 + a2;
}

We have 3 variables “a1”, “a2” and “a3” of type “class A”. Here we are trying to add two
objects “a1” and “a2”, which are of user-defined type i.e. of type “class A” using the “+”
operator. This is not allowed, because the addition operator “+” is predefined to operate
only on built-in data types.
In order to make the operator “+” to add two class objects, it's necessary to redefine the
meaning of the “+” operator such that it adds two class objects.
So the main idea behind “Operator overloading” is to use c++ operators with class variables
or class objects. Redefining the meaning of operators really does not change their original
meaning; instead, they have been given additional meaning along with their existing ones.

Operators that can be overloaded
    Binary Arithmetic        +, -, *, /, %
    Unary Arithmetic        +, -, ++, —
    Assignment        =, +=,*=, /=,-=, %=
    Bit- wise         & , | , << , >> , ~ , ^
    De-referencing        (->)
    Dynamic memory allocation and De-allocation        New, delete 
    Subscript        [ ]
    Function call        ()
    Logical         &,  | |, !
    Relational        >, < , = =, <=, >=

There are some operators that cannot be overloaded:
    Scope resolution operator   ::
    Member selection operator                               
    Member selection through    *                               
    Pointer to member variable
    Ternary or conditional operator    ?:
    Sizeof operator     sizeof()
    typeid
    Class member access operators (.(dot), .* (pointer to member operator))

*/


#include<iostream>
using namespace std;

 
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;   imag = i;
    }
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() {
        cout << real << " + i" << imag << '\n'; // Output: "12 + i9"
    }
};


// Exemplo 2)
// The importance and implicit use of class member access operators and why can’t be overloaded

class ComplexNumber{
    private:
    int real;
    int imaginary;
    public:
        ComplexNumber(int real, int imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }
        void print(){
            cout << real << " + i" << imaginary << endl;
        }
        ComplexNumber operator+ (ComplexNumber c2){
            ComplexNumber c3(0,0);
            c3.real = this->real+c2.real;
            c3.imaginary = this->imaginary + c2.imaginary;
            return c3;
        }
};


// Exemplo 3) Conversion Operator: We can also write conversion operators that can be used to convert one type to another type. 
 
class Fraction {
private:
    int num, den;
public:
    Fraction(int n, int d) { num = n; den = d; }
 
    // Conversion operator: return float value of fraction
    operator float() const {
        return float(num) / float(den);
    }
};


// Exemplo 4) Any constructor that can be called with a single argument works as a conversion constructor, 
// which means it can also be used for implicit conversion to the class being constructed. 

class Point {
private:
    int x, y;
public:
    Point(int i = 0, int j = 0) {
        x = i;  y = j;
    }
    void print() {
        cout << "x = " << x << ", y = " << y << '\n';
    }
};


int main() {

    // Exemplo 1
    cout << "1)" << endl;
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();


    // Exemplo 2
    cout << endl << "2)" << endl;
    ComplexNumber c11(3,5);
    ComplexNumber c22(2,4);
    ComplexNumber c33 = c11 + c22;
    c33.print();
    // The statement ComplexNumber c33 = c11 + c22; is internally translated as ComplexNumber c33 = c11.operator+ (c22); in order to invoke the operator function. The argument c11 is implicitly passed using the ‘.’ operator. The next statement also makes use of the dot operator to access the member function print and pass c33 as an argument. Thus, in order to ensure a reliable and non-ambiguous system of accessing class members, the predefined mechanism using class member access operators is absolutely essential. Besides, these operators also work on names and not values and there is no provision (syntactically) to overload them.


    // Exemplo 3
    cout << endl << "3)" << endl;
    Fraction f(2, 5);
    float val = f;
    cout << val << '\n';
    // Overloaded conversion operators must be a member method. Other operators can either be the member method or the global method.


    // Exemplo 4

    cout << endl << "4)" << endl;
    Point t(20, 20);
    t.print();
    t = 30;   // Member x of t becomes 30
    t.print();
    
    return 0;
}