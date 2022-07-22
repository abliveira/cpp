/*
https://www.geeksforgeeks.org/friend-class-function-cpp/

A friend class can access private and protected members of other class
in which it is declared as friend. It is sometimes useful to allow a particular
class to access private members of other class. For example, a LinkedList class
may be allowed to access private members of Node. 

Apesar de ser um recurso disponível em C++, de certa forma vai contra os princípios de
orientação a objetos e deve evitar de ser usada, tanto que não existe em Java.

A friend function can be: 
a) A member of another class 
b) A global function 
 
A friend function is a special function in C++ which in-spite of not being member 
function of a class has privilege to access private and protected data of a class.
A friend function is a non member function or ordinary function of a class, which 
is declared as a friend using the keyword “friend” inside the class. By declaring 
a function as a friend, all the access permissions are given to the function.
The keyword “friend” is placed only in the function declaration of the friend 
function and not in the function definition.
When friend function is called neither name of object nor dot operator is used. 
However it may accept the object as argument whose value it want to access.
Friend function can be declared in any section of the class i.e. public or private 
or protected.

Following are some important points about friend functions and classes: 
1) Friends should be used only for limited purpose. too many functions or external 
classes are declared as friends of a class with protected or private data, it 
lessens the value of encapsulation of separate classes in object-oriented programming.
2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a 
friend of A automatically.
3) Friendship is not inherited
4) The concept of friends is not there in Java. 
A simple and complete C++ program to demonstrate friend Class 

*/

// Example 1:

// In this example, class B is declared as a friend inside the class A.
// Therefore, B is a friend of class A. 
// Class B can access the private members of class A.

#include<iostream>
using namespace std;

class A {
	int x;
		public:
			
	A() {
		x=10;
	}
	friend class B; //friend class
};

class B {
	public:
		void display(A &t) {
			cout<<endl<<"The value of x="<<t.x;
		}
};



// Example 2: Find the largest of two numbers using Friend Function

class Largest {
	int a,b,m;
	public:
		void set_data();
		friend void find_max(Largest);	
};

void Largest::set_data() {
	cout<<"Enter the First No:";
	cin>>a;
	cout<<"Enter the Second No:";
	cin>>b;
}

void find_max(Largest t) {
	if(t.a>t.b)
		t.m=t.a;
	else
		t.m=t.b;
		
		cout<<"Maximum Number is\t"<<t.m;
}


// Example 3

// The function someFunc() is defined as a regular function outside the class
// It takes an object of type MyClass as its parameter, and is able to access
// the private data members of that object.

class MyClass {
    public:
        MyClass() {
            regVar = 0;
        }
    private:
        int regVar;
    friend void someFunc(MyClass &obj);
};

void someFunc(MyClass &obj) {
    obj.regVar = 42;
    cout << obj.regVar;
}
// The someFunc() function changes the private member of the object and prints
// its value. To make its members accessible, the class has to declare the
// function as a friend in its definition. You cannot "make" a function a friend
// to a class without the class "giving away" its friendship to that function.

// Note that when passing an object to the function, we need to pass it by reference,
//  using the & operator.


// Example 4
class Point {
    public:
        Point(int a, int b): x(a), y(b) {};
        void print() {
            cout << x << ", " << y;
        }
    private:
        int x;
        int y;
    
    friend void shift(Point &p, int step);
};
void shift(Point &p, int step) {
    p.x += step;
    p.y += step;
}

int main() {

    // Example 1:

	A _a;
	B _b;
	_b.display(_a);


    // Example 2:
	Largest l;
	l.set_data();
	find_max(l);


    // Example 4:
    int x, y;
    cin>>x>>y;
    Point p(x, y);

    int step;
    cin>>step;
    shift(p, step);
    
    p.print();

	return 0;
}