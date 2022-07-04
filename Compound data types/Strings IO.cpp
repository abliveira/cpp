/*
https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/

The <iostream> header defines the standard stream objects that input and output data.

A namespace is a declarative region that provides a scope to the identifiers (names of elements) inside it.
In our code, the line using namespace std; tells the compiler to use the std (standard) namespace:

The std namespace includes features of the C++ Standard Library

Este comando serve para definir um "espaço de nomes", ou namespace. Um namespace permite a definição de estruturas, estruturas, classes, funções, constantes, etc, que estarão vinculadas a ele. Isso evita duplicidade com, por exemplo, outras implementações com nomes semelhantes. Por definição, a linguagem C++ utiliza o namespace std para definir todas as funções da biblioteca padrão.

Se não utilizarmos o comando using..., será necessário especificar explicitamente o namespace utilizado, como por exemplo:

#include <iostream>

int main()
{
	std::cout << "Exemplo de saída na tela" << std::endl;

	...
}

*/

#include <iostream>
// #include <string> // for string class
using namespace std;

int main()
{

    // Input and Output Functions -------------------------------------------------------------------------

    // Basic Output with end-of-line
    int var = 42;
    cout<<"Hello World: " << var << endl << "Fim" << endl;

    // Basic input
    string fullName;
    cout << "Type your full name: ";
    getline (cin, fullName); // This function is used to store a stream of characters as entered by the user in the object memory.
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
    

    cout << endl;

    // Declaring string
    string str;
  
    // Taking string input using getline()
    cout << "Please type a string:";
    getline(cin, str);
  
    // Displaying string
    cout << "The initial string is : ";
    cout << str << endl;
  
    // Inserting a character
    // push_back()	This function is used to input a character at the end of the string.
    str.push_back('s');
  
    // Displaying string
    cout << "The string after push_back operation is : ";
    cout << str << endl;
  
    // Deleting a character
    // pop_back()	Introduced from C++11(for strings), this function is used to delete the last character from the string. 
    str.pop_back();
  
    // Displaying string
    cout << "The string after pop_back operation is : ";
    cout << str << endl;

    

    // Capacity Functions -------------------------------------------------------------------------





//     capacity()	This function returns the capacity allocated to the string, which can be equal to or more than the size of the string. Additional space is allocated so that when the new characters are added to the string, the operations can be done efficiently.
// resize()	This function changes the size of the string, the size can be increased or decreased.
// length()	This function finds the length of the string.
// shrink_to_fit()	This function decreases the capacity of the string and makes it equal to the minimum capacity of the string. This operation is useful to save additional memory if we are sure that no further addition of characters has to be made.


    cout << endl;

    // Initializing string
    string str2 = "geeksforgeeks is for geeks";
  
    // Displaying string
    cout << "The initial string is : ";
    cout << str2 << endl;
  
    // Resizing string using resize()
    str2.resize(13);
  
    // Displaying string
    cout << "The string after resize operation is : ";
    cout << str2 << endl;
  
    // Displaying capacity of string
    cout << "The capacity of string is : ";
    cout << str2.capacity() << endl;
  
    // Displaying length of the string
    cout << "The length of the string is :" << str2.length() << endl;
  
    // Decreasing the capacity of string
    // using shrink_to_fit()
    str2.shrink_to_fit();
  
    // Displaying string
    cout << "The new capacity after shrinking is : ";
    cout << str2.capacity() << endl;


    cout << "Please press [ENTER] to continue...";
    cin.get();
    

    // Iterator Functions -------------------------------------------------------------------------






//     Function	Definition
// begin()	This function returns an iterator to the beginning of the string.
// end()	This function returns an iterator to the end of the string.
// rbegin()	This function returns a reverse iterator pointing at the end of the string.
// rend()	This function returns a reverse iterator pointing at beginning of the string.


	// Initializing string`
	string str3 = "geeksforgeeks";

	// Declaring iterator
	std::string::iterator it;

	// Declaring reverse iterator
	std::string::reverse_iterator it1;

	// Displaying string
	cout << "The string using forward iterators is : ";
	for (it = str3.begin(); it != str3.end(); it++)
		cout << *it;
	cout << endl;

	// Displaying reverse string
	cout << "The reverse string using reverse iterators is "
			": ";
	for (it1 = str3.rbegin(); it1 != str3.rend(); it1++)
		cout << *it1;
	cout << endl;




    // Manipulating Functions -------------------------------------------------

//     copy(“char array”, len, pos) 	This function copies the substring in the target character array mentioned in its arguments. It takes 3 arguments, target char array, length to be copied, and starting position in the string to start copying.
// swap()	This function swaps one string with other.


// Initializing 1st string
    string str4 = "geeksforgeeks is for geeks";
  
    // Declaring 2nd string
    string str5 = "geeksforgeeks rocks";
  
    // Declaring character array
    char ch[80];
  
    // using copy() to copy elements into char array
    // copies "geeksforgeeks"
    str4.copy(ch, 13, 0);
  
    // Displaying char array
    cout << "The new copied character array is : ";
    cout << ch << endl;
  
    // Displaying strings before swapping
    cout << "The 1st string before swapping is : ";
    cout << str4 << endl;
    cout << "The 2nd string before swapping is : ";
    cout << str5 << endl;
  
    // using swap() to swap string content
    str4.swap(str5);
  
    // Displaying strings after swapping
    cout << "The 1st string after swapping is : ";
    cout << str4 << endl;
    cout << "The 2nd string after swapping is : ";
    cout << str5 << endl;

    return 0;
}
