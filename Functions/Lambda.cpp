/*
   A lambda expression is an anonymous function that can be defined inline, often used for short operations or as arguments to algorithms.
   Syntax: [capture](parameters) -> return_type { body }
   - The capture clause [ ] allows the lambda to access variables from the surrounding scope.
   - Lambdas are useful for custom operations, especially with STL algorithms.
   This file demonstrates basic usage, including parameter passing and variable capture.
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Simple lambda that prints each number
    // Syntax: [capture](parameters) { body }
    // []: capture clause (empty, captures nothing)
    // (int n): parameter list
    // { std::cout << n << " "; }: body of the lambda
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;

    // Lambda that returns the sum of two numbers
    // []: no capture
    // (int a, int b): two parameters
    // { return a + b; }: returns the sum
    auto sum = [](int a, int b) { return a + b; };
    std::cout << "Sum of 3 and 4: " << sum(3, 4) << std::endl;

    // Lambda with capture
    int factor = 2;
    // [factor]: captures 'factor' by value from the surrounding scope
    // (int n): parameter
    // { std::cout << n * factor << " "; }: uses captured variable
    std::cout << "Numbers multiplied by " << factor << ": ";
    std::for_each(numbers.begin(), numbers.end(), [factor](int n) {
        std::cout << n * factor << " ";
    });
    std::cout << std::endl;

    return 0;
}
