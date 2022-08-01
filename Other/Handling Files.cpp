/*

The ability to read and write to files in C++ requires the standard C++ library called fstream.
Three new data types are defined in fstream:
- ofstream: Output file stream that creates and writes information to files.
- ifstream: Input file stream that reads information from files.
- fstream: General file stream, with both ofstream and ifstream capabilities
  that allow it to create, read, and write information to files.

To perform file processing in C++, header files <iostream> and <fstream> must be included in the C++ source file.
#include <iostream>
#include <fstream>

These classes are derived directly or indirectly from the classes istream and ostream. 
We have already used objects whose types were these classes: cin is an object of class 
istream and cout is an object of class ostream.

*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

    // A file must be opened before you can read from it or write to it.
    // Either the ofstream or fstream object may be used to open a file for writing.
    // If the specified file does not exist, the open function will create it automatically.
    // You also have the option of specifying a path for your file in the open function, 
    //  since it can be in a location other than that of your project.
    ofstream MyFile;
    MyFile.open("test.txt");

    // You can also provide the path to your file using the ofstream objects constructor, instead of calling the open function:
    //  ofstream MyFile("test.txt");

    // The is_open() member function checks whether the file is open and ready to be accessed.
    // Under certain circumstances, such as when you don't have file permissions, the open function can fail.
    if (MyFile.is_open()) {
        MyFile << "This is awesome! \n";
    }
    else {
        cout << "Something went wrong";
    }

    // When you've finished working with a file, close it using the member function close()
    MyFile.close();


    // File Opening Modes
    // An optional second parameter of the open function defines the mode in which the file is opened. 
    // This list shows the supported modes.contentImageAll these flags can be combined using the bitwise operator OR (|).
    // For example, to open a file in write mode and truncate it, in case it already exists, use the following syntax:
    // ofstream outfile;
    // outfile.open("file.dat", ios::out | ios::trunc );


    // Reading from a File
    
    ofstream MyFile1("test2.txt");
    MyFile1 << "This is awesome 2! \n";
    MyFile1.close();

    // You can read information from a file using an ifstream or fstream object.
    // The getline function reads characters from an input stream and places them into a string.
    // Our while loop uses the getline function to read the file line by line.
    string line;
    ifstream MyFile2("test.txt");
    while ( getline (MyFile2, line) ) {
        cout << line << '\n';
    }
    MyFile2.close();
    
    return 0;
}