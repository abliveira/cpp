/* 
https://www.geeksforgeeks.org/exception-handling-c/

One of the advantages of C++ over C is Exception Handling. 
Exceptions are runtime anomalies or abnormal conditions that a program encounters 
during its execution. There are two types of exceptions: 
a)Synchronous, 
b)Asynchronous (i.e., exceptions which are beyond the program’s control, such as disc failure, keyboard interrupts etc.). 

C++ provides the following specialized keywords for this purpose:
try: Represents a block of code that can throw an exception.
catch: Represents a block of code that is executed when a particular exception is thrown.
throw: Used to throw an exception. Also used to list the exceptions that a function throws but doesn’t handle itself.

Problems that occur during program execution are called exceptions.
In C++ exceptions are responses to anomalies that arise while the program is running, such as an attempt to divide by zero.

Catching Exceptions
A try block identifies a block of code that will activate specific exceptions. 
It's followed by one or more catch blocks. The catch keyword represents a block 
of code that executes when a particular exception is thrown.
Code that could generate an exception is surrounded with the try/catch block.
You can specify what type of exception you want to catch by the exception declaration 
that appears in parentheses following the keyword catch.
*/ 

#include <iostream>
using namespace std;

int main() {

    // The try block throws the exception, and the catch block then handles it.
    // The error code 99, which is an integer, appears in the throw statement, so it results in an exception of type int.
    try {
        int motherAge = 29;
        int sonAge = 36;
        if (sonAge > motherAge) {
            throw 99;
        }
    }
    catch (int x) {
        cout << "Wrong age values - Error " << x << endl;
    }

    // Exemplo prático: Divisão por zero
    try {
        int num1;
        cout <<"Enter the first number: ";
        cin >> num1;
        
        int num2;
        cout <<"Enter the second number: ";
        cin >> num2;
        
        if(num2 == 0) {
            throw 0;
        }
        
        cout << "Result:" << num1 / num2 << endl; 
    }
    catch(int x) {
        cout << "Division by " << x << endl; // Output: Division by 0
    }

    // In our case, we catch exceptions of type integer only. 
    // It's possible to specify that your catch block handles any type of exception thrown in a try block. 
    // To accomplish this, add an ellipsis (...) between the parentheses of catch:
    string menu[] = {"fruits", "chicken", "fish", "cake"};
    try {
        int x;
        cout <<"Enter a number between 0 and 3. Or not: ";
        cin >> x;
        if (x >= 0 && x <= 3){
            cout << menu[x];
        }
        else
            throw 404;
        
    }
    catch(...) {
        cout << "404 - not found" << endl;
        
    }

	try {
        throw 10;
        }
        catch (char *excp) {
            cout << "Caught " << excp;
        }
        catch (...) {
            cout << "Default Exception" << endl;
	}


    // In C++, try/catch blocks can be nested. Also, an exception can be re-thrown using “throw; “. 
    try {
        try {
            throw 20;
        }
        catch (int n) {
            cout << "Handle Partially " << endl;
            throw; // Re-throwing an exception
        }
    }
    catch (int n) {
        cout << "Handle remaining " << endl;
    }

    return 0;
}