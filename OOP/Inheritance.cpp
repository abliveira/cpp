/*
https://www.geeksforgeeks.org/inheritance-in-c/?ref=lbp

Inheritance (Herança) é um dos pontos chave de programação orientada a objetos (POO). Ela fornece meios de promover
a extensibilidade do código, a reutilização e uma maior coerência lógica no modelo de implementação.
Inheritance é a capacidade de uma classe de derivar propriedades e características de outra classe.
The new class created is called “derived class” or “child class” and the existing class is known as the “base class”
or “parent class”.
When we say derived class inherits the base class, it means, the derived class inherits all the properties of the
base class, without changing the properties of base class.
- Sub Class: The class that inherits properties from another class is called Subclass or Derived Class. 
- Super Class: The class whose properties are inherited by a subclass is called Base Class or Superclass.

Por exemplo, a classe Carro tem os métodos Motor, Freios e Rodas.
A classe derivada Sedan teria essas classes mais o método PortaMalas.
A classe derivada Pickup teria essas classes mais o método Caçamba.

Tipos de Inheritance -----------------------------------------------------------
1. Single Inheritance: A class is allowed to inherit from only one class. A -> B
2. Multiple Inheritance: A class can inherit from more than one class. A and B -> C
3. Multilevel Inheritance: In this type of inheritance, a derived class is created from another derived class. A -> B -> C
4. Hierarchical Inheritance: In this type of inheritance, more than one subclass is inherited from a single base class. A -> B and C
5. Hybrid (Virtual) Inheritance: Hybrid Inheritance is implemented by combining more than one type of inheritance. 
For example: Combining Hierarchical inheritance and Multiple Inheritance. 
6. A special case of hybrid inheritance: Multipath inheritance: 
A derived class with two base classes and these two base classes have one common base class is called multipath inheritance.
Ambiguity can arise in this type of inheritance which need to be handled by a special operator

Access specifier inheritance -----------------------------------------------------
Se for público, e declarado como:
    - Público, é herdado e continua público
    - Protegido, é herdado e passa a ser protegido
    - Privado, é herdado e passa a ser privado
Se for protegido, e declarado como:
    - Público, é herdado e continua protegido
    - Protegido, é herdado e continua protegido
    - Privado, é herdado e passa a ser privado
Se for público, e declarado como:
    - Público, não é herdado
    - Protegido, não é herdado
    - Privado, não é herdado

Constructor e Destructor -----------------------------------------------------------
Ao herdar classes, o construtor e o destruidor da classe base não são herdados.
No entanto, eles são chamados quando um objeto da classe derivada é criado/excluído.
Primeiramente é chamado o construtor da classe BASE e então o construtor da classe DERIVADA.
No final, é chamado o destruidor da classe DERIVADA e então o destruidor da classe BASE.

*/
 
#include<iostream>
using namespace std;

// C++ Implementation to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object.
class A {
public:
    int x;
 
protected:
    int y;
 
private:
    int z;
};
 
class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};
 
class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};
 
class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};



// Example 1  ---------------------------------------------------------
// define member function without argument within the class
class Person {
    // O que for privado pela Classe base não é acessível pela classe derivada 
    int id;
    char name[100];
   
    // O que for público pela Classe base pode ser especificado pela derivada como público, privado ou protegido
    public:
        void set_p() // Apenas como exemplo, os métodos da classe estão declarado internamente
        {
            cout<<"Enter the Id:";
            cin>>id;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Enter the Name:";
            cin.get(name,100);
        }
   
        void display_p() {
            cout<<endl<<id<<"\t"<<name;
        }
};
 
class Student: private Person // Especifica que o que será herdado será privado, caso já não fosse
{
    char course[50];
    int fee;
     
    public:
        void set_s(); // Apenas como exemplo, os métodos da classe estão declados externamente
        void display_s();
};
 
void Student::set_s() {
    set_p();

    cout<<"Enter the Course Name:";
    fflush(stdin);
    cin.getline(course,50);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout<<"Enter the Course Fee:";
    cin>>fee;
}
 
void Student::display_s() {
    display_p();
    cout<<"\t"<<course<<"\t"<<fee;
}


// Example 2 ---------------------------------------------------------
// C++ program to demonstrate implementation of a sing Inheritance class

class Parent {
public:
    int id_p;
};
 
// Sub class inheriting from Base Class(Parent)
class Child : public Parent {
public:
    int id_c;
};


// Example 3 ---------------------------------------------------------
// C++ program to demonstrate implementation of multiple inheritance

// first base class
class Vehicle {
    public:
        Vehicle() {
            cout << "This is a Vehicle\n"; 
        }
};
 
// second base class
class FourWheeler {
    public:
        FourWheeler()
        {
            cout << "This is a 4 wheeler Vehicle\n";
        }
};
 
// sub class derived from two base classes
class Car : public Vehicle, public FourWheeler {
};


// Example 4
// C++ program to demonstrate implementation of multilevel inheritance
class Garage : public Car {
    public:
        Garage(){
            cout << "This is a garage" << endl;
        }
};


// Example 5 ---------------------------------------------------------

// base class
class Fruit {
public:
    Fruit() { cout << "This is a Fruit\n"; }
};
 
// first sub class
class Banana : public Fruit {
    public:
        Banana(){
            cout << "But a banana" << endl;
        }
};
 
// second sub class
class Apple : public Fruit {
    public:
        Apple(){
            cout << "But an apple" << endl;
        }
};


// Example 6 ---------------------------------------------------------
// Demonstrating ambiguity in Multipath Inheritance with scope resolution specifier
 
 /*
In the above example, both ClassB and ClassC inherit ClassA, they both have a single copy of ClassA. 
However Class-D inherits both ClassB and ClassC, therefore Class-D has two copies of ClassA, one from ClassB and another from ClassC. 
If we need to access the data member of ClassA through the object of Class-D, we must specify the path from which a will be accessed,
whether it is from ClassB or ClassC, bcoz compiler can’t differentiate between two copies of ClassA in Class-D.
*/
class ClassA {
    public:
        int a;
};
 
class ClassB : public ClassA {
    public:
        int b;
};
 
class ClassC : public ClassA {
    public:
        int c;
};
 
class ClassD : public ClassB, public ClassC {
    public:
        int d;
};


// Example 7 ---------------------------------------------------------
// demonstrating ambiguity in Multipath Inheritance with virtual base class
// https://www.geeksforgeeks.org/virtual-base-class-in-c/

/*
Virtual base classes in C++ are used as a way of preventing multiple instances of a given class from
appearing in an inheritance hierarchy when using multiple inheritances.
When a class is specified as a virtual base class, it prevents duplication of its data members.
Only one copy of its data members is shared by all the base classes that use the virtual base class.
*/

class ClassX
{
  public:
    int a = 0;
};
 
class ClassW : virtual public ClassX
{
  public:
    int b;
};
 
class ClassY : virtual public ClassX
{
  public:
    int c;
};
 
class ClassZ : public ClassW, public ClassY
{
  public:
    int d;
};


// Example 8 ---------------------------------------------------------
// Constructor and Destructor inheritance
class Mother {
    public:
        Mother() 
        {
            cout <<"Mother ctor"<<endl;
        }
        ~Mother()
        {
            cout <<"Mother dtor"<<endl;
        }
};

class Daughter: public Mother {
    public:
        Daughter()
        {
            cout <<"Daughter ctor"<<endl;
        }
        ~Daughter()
        {
            cout <<"Daughter dtor"<<endl;
        }
};
 
int main() {

    // Example 1 ---------------------------------------------------------

    Student s;
    s.set_s();
    s.display_s();


    // Example 2 - Single -------------------------------------------------

    Child obj1;
    // An object of class child has all data members
    // and member functions of class parent
    obj1.id_c = 7;
    obj1.id_p = 91;
    cout << endl;
    cout << endl;
    cout << "Child id is: " << obj1.id_c << '\n';
    cout << "Parent id is: " << obj1.id_p << '\n' << endl;


    // Example 3 - Multiple ------------------------------------------------

    // Creating object of sub class will
    // invoke the constructor of base classes.
    Car obj;
    cout << endl;


    // Example 4 - Multilevel ---------------------------------------------
    Garage obj2;
    cout << endl;


    // Example 5 - Hierarchical -------------------------------------------
    Banana obj3;
    Apple obj4;
    cout << endl;


    // Example 6 - Multipath using scope ----------------------------------
    ClassD obj5;
 
    // Tentando alterar a variável herdada de duas classes bases
    // obj5.a = 10;     // error: request for member ‘a’ is ambiguous
    // obj5.a = 100;     // error: request for member ‘a’ is ambiguous
 
    // Avoiding ambiguity using the scope resolution operator: 
    // Using the scope resolution operator we can manually specify 
    //  the path from which data member a will be accessed
    obj5.ClassB::a = 10;
    obj5.ClassC::a = 100;
 
    // Não são ambíguas, então não há problema
    obj5.b = 20;
    obj5.c = 30;
    obj5.d = 40;
 
    cout << "a from ClassB  : " << obj5.ClassB::a << endl;
    cout << "a from ClassC  : " << obj5.ClassC::a << endl;
 
    cout << "b : " << obj5.b << endl;
    cout << "c : " << obj5.c << endl;
    cout << "d : " << obj5.d << '\n';


    // Example 7 - Multipath using virtual base class ------------------------

    ClassZ obj7;
    cout << endl;
 
    obj7.a = 10;
    obj7.a = 100;
 
    obj7.b = 20;
    obj7.c = 30;
    obj7.d = 40;
 
    cout << "Example 7:" << endl;
    // Na classe Z, é mantida apenas uma instância da Class base X
    // Portanto, o valor fica com 100
    cout << "Z.a : " << obj7.a << endl;
    cout << "Z.b : " << obj7.b << endl;
    cout << "Z.c : " << obj7.c << endl;
    cout << "Z.d: " << obj7.d << '\n';
    cout << endl;

    // Nas outras classes derivadas Y e W, a múltiplas instâncias de X continuam existindo 
    ClassW obj8;
    ClassY obj9;
    cout << "W.a : " << obj8.a << endl;
    cout << "Y.a : " << obj9.a << endl;
    obj8.a = 25;
    obj9.a = 26;
    cout << "W.a : " << obj8.a << endl;
    cout << "Y.a : " << obj9.a << endl;
    cout << "Z.a : " << obj7.a << endl;


    // Example 8 - Constructor and Destructor inheritance ----------------------------------

    cout << "Example 8:" << endl;
    Daughter m; // Chama o Constructor da classe base e também da herdada 
    return 0;
}
