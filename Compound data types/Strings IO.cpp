/*
https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
*/

#include <iostream>
using namespace std;

int main()
{
    // Basic Output with end-of-line
    int var = 42;
    cout<<"Hello World: " << var << endl << "Fim" << endl;

    // Basic input
    string fullName;
    cout << "Type your full name: ";
    getline (cin, fullName);
    cout << "Your name is: " << fullName << endl;

    
    int age;
    cout << "Type your full age: ";
    cin>>age;
    // Quando dá enter para enviar o texto, é capturada a string '\n'
    // Isso pode fazer com que outras entradas de texto apresentam problemas
    // Pode se usar uma das opções abaixo para evitar o problemas
    //cin.ignore(INT_MAX,'\n');
    //cin.ignore(2147483647,'\n'); // é o valor da linha de cima
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Your age is: " << age << endl;

    cout << "Type your full name: ";
    getline (cin, fullName);
    cout << "Your name is: " << fullName;

    string name;
    // Write "Hello, world!" and await user response
    cout << "Hello, " << name << "!" << endl;
    cout << "Please press [ENTER] to continue...";
    cin.get();

    return 0;
}
