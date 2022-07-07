#include <iostream>
using namespace std;

// Funções podem ter o mesmo nome, desde que difiram no tipo e/ou na quantidade de argumentos
// É útil para simplificar o chamado de funções que têm a mesma tarefa, 
// mas lidam tipos e quantidade de argumentos diferentes

// Obs: Esse recurso é exclusivo de C++

void printNumber(int x) {
    cout << "Prints an integer: " << x << endl;
}
void printNumber(float x) {
    cout << "Prints a float: " << x << endl;
}
void printNumber(int x, int y) {
    cout << "Prints a float: " << x << endl;
}

int main() {
    int a = 16;
    float b = 54.541;
    int c = 10;
    printNumber(a);
    printNumber(b);
    printNumber(a, c);
}