/*
As with the built-in data types, we can make class objects constant.

const MyClass obj;

All const variables must be initialized when they're created. In the case of classes,
this initialization is done via constructors. If a class is not initialized using a
parameterized constructor, a public default constructor must be provided - if no
public default constructor is provided, a compiler error will occur.

Once a const class object has been initialized via the constructor, you cannot
modify the object's member variables. This includes both directly making changes
to public member variables and calling member functions that set the value of
member variables.

Obs: When you've used const to declare an object, you can't change its data
members during the object's lifetime.

Only non-const objects can call non-const functions.
Hence, for a constant object to work you need a constant function.
*/

#include <iostream>
using namespace std;

/*
To specify a function as a const member, the const keyword must follow the function prototype, outside of its parameters' closing parenthesis. For const member functions that are defined outside of the class definition, the const keyword must be used on both the function prototype and definition. For example:

Attempting to call a regular function from a constant object results in an error.
In addition, a compiler error is generated when any const member function attempts to change a member variable or to call a non-const member function.
Defining constant objects and functions ensures that corresponding data members cannot be unexpectedly modified.

*/


// Exemplo 1 ----------------------------------------

class MyClass
{
  public:
    void myPrint() const;
};

void MyClass::myPrint() const {
  cout <<"Hello"<<endl;
}
// Now the myPrint() function is a constant member function. As such, it can be called by our constant object:



// Exemplo 2 ----------------------------------------

class Number
{
    private:
        int num;
    public:
        Number(int n) {
            num = n;
        }
        //complete the method
        int square() const {
           return num*num;
        }
};



// Member Initializers ------------------------------------------------

/*
This class has two member variables, regVar and constVar. 
It also has a constructor that takes two parameters, which are used to initialize the member variables.
Running this code returns an error, because one of its member variables is a constant, which cannot be assigned a value after declaration.

class MyClass {
  public:
   MyClass(int a, int b) {
    regVar = a;
    constVar = b;
   }
  private:
    int regVar;
    const int constVar;
};

Note that in the syntax, the initialization list follows the constructor parameters. The list begins with a colon (:), and then lists each variable to be initialized, along with the value for that variable, with a comma to separate them.
Use the syntax variable(value) to assign values.

PS: The initialization list eliminates the need to place explicit assignments in the constructor body. Also, the initialization list does not end with a semicolon.

*/

// Example 3 ----------------------------------------

class MyClass2 {
    public:
        MyClass2(int a, int b):regVar(a), constVar(b)
        {
        }
    private:
        int regVar;
        const int constVar;
};



// Example 4 ----------------------------------------

// The member initialization list may be used for regular variables, and must be used for constant variables.
// Even in cases in which member variables are not constant, it makes good sense to use the member initializer syntax.

// #include <iostream>
// using namespace std;

class TV {
    public:
        TV(int h, int w): height(h), width(w) {};
        void area() {
            cout <<height*width;
        }
    private:
        int height;
        int width;
};



int main() {
    
    // Exemplo 1 ----------------------------------------
    
    const MyClass obj;
    obj.myPrint();
    
    
    // Exemplo 2 -----------------------------------------
    
    int x;
    cout << "Type a number to get its square: ";
    cin >> x;
    const Number myNum(x);  // A variável x precisa ser definida no momento da criação do objeto, pois será constante e não poderá ser modificada depois
    cout << myNum.square() << endl;;
    
    
    // Exemplo 3
    
    MyClass2 MyC2obj (5, 5);
    
    
    // Exemplo 4 -----------------------------------------
    int height;
    int width;
    cout << "Type the height: ";
    cin >> height;
    cout << "Type the width: ";
    cin >> width;
    TV Tvobj (height, width);
    Tvobj.area();  

}