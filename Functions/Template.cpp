/*
Utilizando Function Overloading (Functions/Overloading.cpp),
é possível ter várias funções semelhantes apenas diferenciando o 
tipo dos argumentos.

With function templates, the basic idea is to avoid the necessity of
specifying an exact type for each variable. Instead, C +  +  provides u
with the capability of defining functions using placeholder types,
called template type parameters.

To define a function template, use the keyword template, followed by
the template type definition:
template <class T> 
The compiler automatically calls the function for the corresponding type.

Template functions can save a lot of time, because they are written only
once, and work with different types.
Template functions reduce code maintenance, because duplicate code is reduced
significantly.types.
*/

#include <iostream>
using namespace std;

template <class T>
T sum(T a, T b) {
    return a + b;
}

// for 2 different data types we need a code like this:
template <class U, class V>
    U sumAll(U a, V b){ //you can use U sum too return a + b; 
    return a + b;
}
// The output converts to an integer, because we specified the function template's
// return type to be of the same type as the first parameter (T), which is an integer.

template <class X, class Y>
X smaller(X a, Y b) {
  return (a < b ? a : b);
}
// The ternary operator checks the a<b condition and returns the corresponding result.
// The expression (a < b ? a : b) is equivalent to the expression if a is smaller than b,
// return a, else, return b.

int main () {
    int x = 7;
    int y = 15;
    cout << sum(x, y) << endl;

    float m = 7;
    float n = 15;
    cout << sum(m, n) << endl;

    int o = 7;
    float p = 15;
    cout << sumAll(o, p) << endl;

    int q = 72;
    double r = 15.34;
    cout << smaller(q, r) << endl;
}