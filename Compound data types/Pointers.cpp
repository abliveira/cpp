#include <iostream>
using namespace std;

/* Toda variável possui um endereço de memória, onde o seu valor é armazenado
  Um ponteiro é uma variável capaz de armazenar um endereço de memória de outra variável
  Assim como outras variáveis, um ponteiro tem nome e um tipo definido, do qual o ponteiro aponta */

int main() {

  int var = 10;
  
  // Valor da variável
  cout << var << endl;
  
  // O endereço de memória de uma variável pode ser acessado com o operador & (address-of operator)
  cout << &var << endl;

  // Uma variável ponteiro é declarada com um asterisco. O tipo deve ser o mesmo da variável a ser apontada
  int *p;

  // Para associar o ponteiro como uma variável, deve-se usar o endereço de memória dela
  p = &var;

  // Imprime o endereço de memória da variável
  cout << p << endl;

  /* O valor da variável a qual o ponteiro aponta pode ser acessado e manipulado com o operador *,
    que após a declaração do ponteiro, funciona como contents-of (or dereference) operator*/

  // Imprime o valor da variável apontada pelo ponteiro
  cout << *p << endl;

  // O operador contents-of também permite manipular o valor da variável através do ponteiro
  *p = 20;

  // Imprime o novo valor da variável apontada por p
  cout << *p << endl;

  // Imprime o novo valor da variável
  cout << var << endl;
  
  // Em suma, var == *p (valor) e p == &var (endereço)

  return 0;
}
