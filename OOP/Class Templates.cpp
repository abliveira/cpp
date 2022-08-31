/* 
Referências
    https://www.geeksforgeeks.org/templates-cpp/
    https://www.geeksforgeeks.org/template-specialization-c/

Os Templates são recursos poderosos do C ++, o que nos permite escrever programas genéricos.
Existem duas maneiras de implementar Templates:
- Function Templates
- Class Templates

Semelhante a function templates, podemos usar class templates para criar uma única classe para funcionar
com diferentes tipos de dados. Os class templates são úteis, pois podem tornar o código mais curto
e melhor gerenciável.

A idéia simples é passar o tipo de dados como um parâmetro para que não precisemos escrever o mesmo
código para diferentes tipos de dados.Por exemplo, uma empresa de software pode precisar sort() diferentes
tipos de dados. Em vez de escrever e manter vários códigos, podemos escrever um sort() e passar
tipo de dados como um parâmetro.

Templates are expanded at compiler time. This is like macros. The difference is, that the compiler 
does type checking before template expansion. The idea is simple, source code contains only 
function/class, but compiled code may contain multiple copies of the same function/class. 

*/

#include <iostream>
using namespace std;



// Exemplo 1 ----------------------------------------
// C++ program to demonstrate the use of class templates

// Creating a Class Template Object
// Once we've declared and defined a class template, we can create its objects
// in other classes or functions (such as the main() function) with the following syntax

// className<dataType> classObject;
// For example,

// className<int> classObject;
// className<float> classObject;
// className<string> classObject;

// Class template
template <class T>
class Number {
   private:
    // Variable of type T
    T num;

   public:
    Number(T n) : num(n) {}   // constructor

    T getNum() {
        return num;
    }
};


// Exemplo 2 ----------------------------------------
//support any type for the queue and so that the code in main runs successfully.

// Just as with function templates, you can define more than one generic data type by using a comma-separated list.
template <class T>
class Queue {
	private:
		T *arr;
        int count;
    public:
    	Queue(int size) {
    	    arr = new T[size];
    	    count = 0;
    	}
    	void add(T elem) {
    	    arr[count] = elem;
    	    count++;
    	}
    	void get(int index) {
    	    cout << arr[index]<< endl;
    	}
};


// Exemplo 3 ----------------------------------------
template <class T>
class Pair {
    private:
        T first, second;
    public:
        Pair (T a, T b):
        first(a), second(b) { }
        T bigger();
};

template <class T>
T Pair<T>::bigger() {
    return (first>second ? first : second); // The ternary operator compares the two variables, returning the greater one.
}


// Exemplo 4 ----------------------------------------
// C++ Class Templates With Multiple Parameters
// In C++, we can use multiple template parameters and even use default 
// arguments for those parameters. For example,

// template <class T, class U, class V = int>
// class ClassName {
//   private:
//     T member1;
//     U member2;
//     V member3;
//     ... .. ...
//   public:
//     ... .. ...
// };

template <class T, class U, class V = char>
class ClassTemplate {
   private:
    T var1;
    U var2;
    V var3;

   public:
    ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}  // constructor

    void printVar() {
        cout << "var1 = " << var1 << endl;
        cout << "var2 = " << var2 << endl;
        cout << "var3 = " << var3 << endl;
    }
};

/*
Exemplo 5
C++ Class Templates With Specialization

No caso de templates de classes regulares, a maneira como a classe lida com
diferentes tipos de dados é a mesma: O mesmo código é executado para todos os tipos de dados.
A especialização dos templates permite a definição de uma implementação diferente
de um modelo quando um tipo específico é passado como um argumento de template.

First of all, notice that we precede the class name with template<>, including an empty parameter list. This is because all types are known and no template arguments are required for this specialization, but still, it is the specialization of a class template, and thus it requires to be noted as such.

But more important than this prefix, is the <char> specialization parameter after the class template name. This specialization parameter itself identifies the type for which the template class is being specialized (char).
In the example above, the first class is the generic template, while the second is the specialization.
If necessary, your specialization can indicate a completely different behavior from the behavior of the generic template.
*/

// Como um template de classe regular, a MyClass trata todos os vários tipos de dados da mesma maneira.
template <class T>
class MyClass {
    public:
        MyClass (T x) {
            cout <<x<<" -  not a char"<<endl;
        }
};

// Para especificar um comportamento diferente para o tipo de dados char, criaríamos uma especialização de template.
template < >
class MyClass<char> {
    public:
        MyClass (char x) {
            cout <<x<<" is a char!"<<endl;
        }
};


// Exemplo 6
// Following is a simple example of a template Array class. 

template <typename T> class Array {
private:
    T* ptr;
    int size;
  
public:
    Array(T arr[], int s);
    void print();
};
  
template <typename T> Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
  
template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}


// Exemplo 7
// Example 2: Simple Calculator Using Class Templates
// This program uses a class template to perform addition, subtraction, multiplication and division of two variables num1 and num2.
// The variables can be of any type, though we have only used int and float types in this example.

template <class T>
class Calculator {
   private:
    T num1, num2;

   public:
    Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    void displayResult() {
        cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
        cout << num1 << " + " << num2 << " = " << add() << endl;
        cout << num1 << " - " << num2 << " = " << subtract() << endl;
        cout << num1 << " * " << num2 << " = " << multiply() << endl;
        cout << num1 << " / " << num2 << " = " << divide() << endl;
    }

    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
    T multiply() { return num1 * num2; }
    T divide() { return num1 / num2; }
};


// Exemplo 8  ----------------------------------------

// Below is the program to implement Bubble Sort using templates in C++: 
// CPP code for bubble sort
// using template function
  
// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T> void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}


int main() {

    // Exemplo 1 ----------------------------------------

    // A specific syntax is required in case you define your member functions outside of your class - for example in a separate source file.
    // You need to specify the generic type in angle brackets after the class name.
    // create object with int type
    Number<int> numberInt(7);

    // create object with double type
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;  // Output: Number = 7
    cout << "double Number = " << numberDouble.getNum() << endl;    // Output: Number = 7.7

    cout << endl;


    // Exemplo 2 ----------------------------------------

	Queue<string> q(4);
	q.add("James");
	q.add("Andy");
	q.add("Amy");
	q.get(2);
	
	Queue <int> n(2);
	n.add(42);
	n.add(33);
	n.get(1);

    cout << endl;


    // Exemplo 3 ----------------------------------------

    Pair <int> obj(11, 22);
    cout << obj.bigger() << endl;

    cout << endl;
    

    // Exemplo 4 ----------------------------------------

    // In this program, we have created a class template, named ClassTemplate, 
    // with three parameters, with one of them being a default parameter.

    // create object with int, double and char types
    ClassTemplate<int, double> obj1(7, 7.7, 'c');
    cout << "obj1 values: " << endl;
    obj1.printVar();

    // create object with int, double and bool types
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    cout << "obj2 values: " << endl;
    obj2.printVar();

    // Output
    // obj1 values: 
    // var1 = 7
    // var2 = 7.7
    // var3 = c

    // obj2 values: 
    // var1 = 8.8
    // var2 = a
    // var3 = 0
    
    cout << endl;


    // Exemplo 5 ----------------------------------------

    MyClass<int> ob1(42);
    MyClass<double> ob2(5.47);
    MyClass<char> ob3('s');
    // Como você pode ver, o template genérico funcionou para o int e o double.
    // No entanto, nossa especialização de template foi invocada para o tipo de dados do char.

    cout << endl;
    

    // Exemplo 6 ----------------------------------------

    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    cout << endl;


    // Exemplo 7  ----------------------------------------
    Calculator<int> intCalc(2, 1);
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << "Float results:" << endl;
    floatCalc.displayResult();

    // In the above program, we have declared a class template Calculator.

    // The class contains two private members of type T: num1 & num2, and a constructor to initialize the members.

    // We also have add(), subtract(), multiply(), and divide() functions that have the return type T. We also have a void function displayResult() that prints out the results of the other functions.

    // In main(), we have created two objects of Calculator: one for int data type and another for float data type.

    // Calculator<int> intCalc(2, 1);
    // Calculator<float> floatCalc(2.4, 1.2);
    // This prompts the compiler to create two class definitions for the respective data types during compilation.

    cout << endl;


    // Exemplo 8  ----------------------------------------

    int d[5] = { 10, 50, 30, 40, 20 };
    int num = sizeof(d) / sizeof(d[0]);
  
    // calls template function
    bubbleSort<int>(d, num);
  
    cout << "Sorted array : ";
    for (int i = 0; i < num; i++)
        cout << d[i] << " ";
    cout << endl;
  
    // Output
    //  Sorted array : 10 20 30 40 50 
    // Class Templates like function templates, class templates are useful when a class defines something that is independent of the data type. Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc. 

    return 0;
}