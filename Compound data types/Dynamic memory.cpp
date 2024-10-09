#include <iostream>
using namespace std;

/*  In C++ memory management, there are two primary regions where memory can be allocated:

    1. Stack:
        - The stack is used for local variables, function calls, and control flow.
        - It is managed automatically by the system in a Last-In-First-Out (LIFO) manner.
        - Characteristics:
            - Fast allocation and deallocation (as variables are pushed/popped).
            - Fixed size: The memory size for variables must be known at compile-time.
            - Automatically freed: When a function completes, its local variables are removed from memory.
            - Limited size: The stack size is typically small (often in the range of 1MB to 8MB) and can vary depending on the system. Allocating too much data may result in a stack overflow.
        - Stack allocation is ideal for small, fixed-size data that is needed temporarily, like local variables inside functions. 

    2. Heap:
        - The heap is used for dynamic memory allocation, where memory can be requested at runtime.
        - It is manually managed by the programmer using `new` to allocate and `delete` to free the memory.
        - Characteristics:
            - Flexible size: Memory can be allocated based on runtime needs.
            - Slower than stack allocation due to more complex memory management.
            - Manual deallocation: The programmer must free the memory explicitly using `delete` or risk memory leaks, which occur when memory is not properly released and remains occupied.
            - Larger memory pool: The heap can allocate large blocks of memory but is subject to system memory limits.
        - Heap allocation is best suited for data whose size is unknown at compile time or when large amounts of memory are required for a longer duration.

*/

int main () {

    // Example of Stack Allocation:

    // These variables are allocated on the stack. The memory is automatically freed 
    // when the function (in this case, main) finishes executing.
    int x = 10;
    float y = 20.5;
    char z = 'A';

    // After this block is executed, the memory allocated for x, y, and z will be released automatically
    // and no explicit memory management (like using 'delete') is needed here.

    cout << "Stack allocated variables:" << endl;
    cout << "x: " << x << ", y: " << y << ", z: " << z << endl;


    // Heap Memory Allocation Example:

    // Memory allocation is done using pointers. The pointer is stored in stack memory.
    // However, the actual memory for the variable pointed to by p is allocated on the heap.
    double* p = NULL; // Pointer is created on the stack, but points to a heap memory location later.
    
    cout << "\nAddress pointed to by p (initially NULL): " << p << endl;
    
    // The new operator dynamically allocates memory from the heap.
    p = new double;

    // The memory reserved on the heap must be manually managed by the programmer.
    *p = 32000; // Assigning a value to the memory location.
    cout << "Address pointed to by p (after allocation): " << p << endl;
    cout << "Value pointed to by p: " << *p << endl;
    
    // Heap memory remains allocated until it is explicitly freed using the 'delete' operator
    // Releasing the allocated heap memory.
    delete p;

    // The pointer still holds the memory address even though the memory it points to is freed.
    cout << "Address pointed to by p (after deletion): " << p << endl;
    // Attempting to access the value after freeing the memory may lead to undefined behavior.
    cout << "Value pointed to by p (after deletion): " << *p << endl;

    // Dynamic Memory Allocation for Arrays:

    // When dynamically allocating an array, the memory is also allocated on the heap.
    int n, i, sum = 0;
    cout << "\nEnter the number of elements: ";
    cin >> n;
    
    // Allocating an array of 'n' integers on the heap.
    int* arr = new int[n];

    // The pointer 'arr' is stored on the stack, but the array it points to resides in heap memory.
    cout << "\nEnter " << n << " integers:" << endl;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "Sum of array elements: " << sum << endl;

    // After using the array, it is important to free the heap memory to prevent memory leaks.
    delete[] arr;

    return 0;
}
