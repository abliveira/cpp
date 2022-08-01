#include <iostream>     // cout
#include <cstdlib>      // rand() e srand()
#include <ctime>        // time()
using namespace std;

int main () {
    
    // A funcao rand() pode ser usada para gerar números pseudo-randômicos
    cout << rand() << endl;
    cout << rand() << endl;
    
    // Para delimitar a faixa de possíveis valores de saída, somar o valor mínimo e usar módulo para o máximo
    cout << 1 + (rand() % 6) << endl;
    cout << 1 + (rand() % 9) << endl;
    
    // A função rand() sempre resulta nos mesmos valores, uma vez que é pseudo-randômica. 
    // Cada vez que rand é chamada, ela muda os valores de saída. Mas a sequência a cada vez que o programa roda é igual
    cout << "This value is 6: " << (1 + rand() % 6) << endl;
    cout << "And this one is 2: " << (1 + rand() % 6) << endl;
    
    // A função srand() permite melhor embaralhar os resultados, ao receber uma seed. Deve ser chamada antes de rand()
    srand(2);
    cout << 1 + (rand()) << endl;
    
    // No entanto, os valores ainda são previsíveis
    cout << "This value is 2: " << (1 + rand() % 6) << endl;
    
    //  Para gerar valores realmente aleatórios, pode-se usar a biblioteca ctime para input da seed
    //  time() retorna o tempo desde 00:00:00 UTC, January 1, 1970 (Unix timestamp). Assim, toda seed será única
    srand(time(0));
    cout << 1 + (rand()) << endl;
}
