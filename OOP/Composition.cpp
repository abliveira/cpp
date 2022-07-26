/*
https://www.geeksforgeeks.org/object-composition-delegation-in-c-with-examples/

In C++, object composition involves using classes as member variables in other classes.

In object-oriented programming languages, object composition is used for objects that have
a “has-a” relationship with each other. Therefore, the complex object is called the whole
or a parent object whereas a simpler object is often referred to as a child object.

In general, composition serves to keep each individual class relatively simple,
straightforward, and focused on performing one task. It also enables each sub-object
to be self-contained, allowing for reusability (we can use the Birthday class within
various other classes).

Composition is in contrast to inheritance, it enables the creation of complex types by
combining objects (components) of other types, rather than inheriting from a base or parent
class. To put it simply, composition contains instances of other classes that implement the
desired functionality.

The main difference between inheritance and composition is in the relationship between objects.

Inheritance: “is a.” E.g. The car is a vehicle.
Composition: “has a.” E.g. The car has a steering wheel.
Inheritance is known as the tightest form of coupling in object-oriented programming. Changing
a base class can cause unwanted side effects on its subclasses or even all over the codebase.

Composition is a far looser coupling. Combining with Dependency Injection (here), it brings
more flexibility and also allows us to change runtime behavior.

When building a class combining various components, it’s more natural to use composition than
to try to find commonality between them and create a class tree.

This approach accommodates future requirement changes, that may require a complete restructuring
of the class tree in the inheritance approach, more easily. We can simply add a new component to
the composited class rather than modifying the superclass to adapt changes.

They’re different in purpose too.

Inheritance: To design a class on what it is.
Composition: To design a class on what it does.


Syntax:

class A {
    // body of a class
};

class B {
    A objA;
    public:
   B(arg-list) : objA(arg-list1);
};

*/

#include <iostream>
using namespace std;


// Example 1 ------------------------------------------------------

class Birthday {
    public:
        Birthday(int m, int d, int y) : month(m), day(d), year(y)
        {}
        void printDate() {
            cout<<month<<"/"<<day <<"/"<<year<<endl;
        }
    private:
        int month;
        int day;
        int year;
};

class Person {
    public:
        Person(string n, Birthday b) : name(n), bd(b)
        {}
        void printInfo() {
            cout << name << endl;
            bd.printDate();
        }
    private:
        string name;
        Birthday bd;
};


// Example 2 ------------------------------------------------------

class Engine {
    public:
        Engine(int p): power(p) {};
        void start() {
            cout <<"Engine ON ("<<power<<" horsepower)";
        }
    private:
        int power;
};
class Car {
    public:
        Car(Engine x, string c, int y): e(x), color(c), year(y) {};
        void start() {
            cout <<"Starting"<<endl;
            e.start();
        }
    private:
        Engine e;
        string color;
        int year;
};


int main() {

    // Example 1

    Birthday bd(2, 21, 1985);
    Person p("David", bd);
    p.printInfo();
    cout << endl;

    // Example 2

    int power;
    string color;
    int year;
    cout << "Type between spaces the power, color and year of the car: ";
    cin >> power >> color >> year;

    Engine e(power);
    Car carObj(power, color, year);
    carObj.start();
}