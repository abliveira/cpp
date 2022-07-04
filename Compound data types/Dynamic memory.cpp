#include <iostream>
using namespace std;

/*  Na linguagem C++, a memória é dividida em duas partes:
        Stack: Espaço de memória de programa definido no momento da compilação
        Heap: Espaço de memória de programa não utilizado que é usado para alocar variáveis dinamicamente
            na memória durante o tempo de execução do programa
    Quando não se sabe ao certo quanto de memória será usado durante a execução do programa, como a dependência
        de entrada pelo usuário, pode-se reservar dinamicamente a memória */

int main () {

    // A alocação de memória é feita com ponteiros. O ponteiro é armazenado na memória stack
    // Como ainda não há um valor, pode-se inicializá-lo com NULL
    double* p  = NULL;
    
    cout << "Endereço apontado por p: " << p << endl;
    
    // O operador new é usado para requisitar memória referente a um tipo de dado
    p  = new double;
    
    // Pode-se então atribuir um valor a memória reservada utilizando o ponteiro
    *p = 32000;
    cout << "Endereço apontado por p: " << p << endl;
    cout << "Valor apontado por p: " << *p << endl;
    
    // Quando não for mais necessária, a memória alocada pode ser liberada com o operador delete
    // No entanto, delete libera a memória alocada para a variável, mas não exclui o ponteiro em si
    //  pois o ponteiro é armazenado na stack
    delete p;
    
    // O ponteiro no entanto, ainda guarda o valor até ser novamente usado
    cout << "Endereço apontado por p: " << p << endl;
    cout << "Valor apontado por p: " << *p << endl;
    
    // A memória também pode ser alocada para arrays
    int *a = NULL;
    a = new int[20];
    delete [] a;
    
    return 0;
}
