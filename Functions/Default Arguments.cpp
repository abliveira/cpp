#include <iostream>    // cout
using namespace std; 
  
// Uma função pode conter valores padrões para os seus argumentos,
// caso não sejam fornecidos todos valores para os argumentos quando a função é chamada

// Obs: Esse recurso é exclusivo de C++

// Se definido um argumento padrão, todos os subsequentes também devem ter valores padrões
int sum(int x = 0, int y = 0, int z = 0, int w = 0) { 
    return (x + y + z + w); 
} 
  
// O preenchimento dos valores é sempre feito da esquerda para a direita
int main() { 
    cout << sum() << endl; 
    cout << sum(1) << endl;
    cout << sum(1,2) << endl;
    cout << sum(1,2,3) << endl; 
    cout << sum(1,2,3,4) << endl;
    return 0; 
}
