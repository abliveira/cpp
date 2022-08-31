/*
Here are some rules of thumb you may want to consider:
You may not alter the shape I am passing you:
    void draw(const Shape& shape); // Apenas C++
You may alter the shape, but I am retaining ownership of it:
    void draw(Shape& shape); // Apenas C++
Please use a copy of my shape:
    void draw(Shape shape);
Please take ownership of this shape away from me:
    void draw(std::unique_ptr<Shape> shape); // Apenas C++
Let's share this shape:
    void draw(std::shared_ptr<const Shape> shape); // Apenas C++
*/
#include <stdio.h>

// Exemplo
void charFunc(char *ptr) { // A função explicita que é um ponteiro sendo recebido
    printf("\nThe String is : %s\n",ptr);
}

void umafuncao(int& algo) { // A função explicita que é um ponteiro sendo recebido
    printf("\nAlgo: %d\n",algo);
    algo = 30;
}


int main()
{
    // Declare a buffer of type "char"
	char buff[] = "Hello Function"; // "buff" já é um ponteiro para o primeiro caracter
	
	// Passa a string (valor de endereço)
	charFunc(buff);
	
	int algo = 25;
	
	umafuncao(algo);
    printf("\nAlgo: %d\n",algo);
    return 0;
}