/*

Standard predefined macros

Note: This code can be compiled with both C or C++ compilers, but not all predefined macros will be available for each standard.

References:
    https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170
    https://riptutorial.com/cplusplus/example/4867/predefined-macros

*/


#include <stdio.h>

void example() {

    // __func__ is the the name of the current function
    printf("Function name: %s\n", __func__);
}

int main() {

    // __cplusplus is defined if the code is being compiled as C++
    // Its value is the standard version the compiler is fully conformant with, i.e. 199711L for C++98 and C++03, 201103L for C++11 and 201402L for C++14 standard
    #ifdef __cplusplus
        printf("__cplusplus is defined as: %ld\n", __cplusplus);
    #else
        printf("__cplusplus is not defined\n");
    #endif

    // __DATE__ contains date (in "Mmm dd yyyy" format) of the file compilation, where Mmm is formatted as if obtained by a call to std::asctime()
    printf("Compilation date: %s\n", __DATE__);

    // __TIME__ contains time (in "hh:mm:ss" format) of the file compilation.
    printf("Compilation time: %s\n", __TIME__);

    // __FILE__ is a string that hold the current source file
    printf("Current source file: %s\n", __FILE__);

    // __LINE__ is a integer that hold the current line number in the source file
    printf("Current line number: %d\n", __LINE__);

    // Call the example function to demonstrate __func__
    example();

    // __STDC__ is defined as 1 when compiled as C with standard compliance
    #ifdef __STDC__
        printf("__STDC__ is defined as: %d\n", __STDC__);
    #else
        printf("__STDC__ is not defined\n");
    #endif

    // __STDC_HOSTED__ Defined as 1 if the implementation is a hosted implementation, one that supports the entire required standard library. Otherwise, defined as 0.
    #ifdef __STDC_HOSTED__
        printf("__STDC_HOSTED__ is defined as: %d\n", __STDC_HOSTED__);
    #else
        printf("__STDC_HOSTED__ is not defined\n");
    #endif

    // __STDC_NO_ATOMICS__ Defined as 1 if the implementation doesn't support optional standard atomics. The MSVC implementation defines it as 1 when compiled as C and one of the /std C11 or C17 options is specified.
    #ifdef __STDC_NO_ATOMICS__
        printf("__STDC_NO_ATOMICS__ is defined as: %d\n", __STDC_NO_ATOMICS__);
    #else
        printf("__STDC_NO_ATOMICS__ is not defined\n");
    #endif

    // __STDC_NO_COMPLEX__ is defined as 1 if complex numbers are not supported. The MSVC implementation defines it as 1 when compiled as C and one of the /std C11 or C17 options is specified.
    #ifdef __STDC_NO_COMPLEX__
        printf("__STDC_NO_COMPLEX__ is defined as: %d\n", __STDC_NO_COMPLEX__);
    #else
        printf("__STDC_NO_COMPLEX__ is not defined\n");
    #endif

    // __STDCPP_THREADS__ Defined as 1 if and only if a program can have more than one thread of execution, and compiled as C++. Otherwise, undefined.
    #ifdef __STDCPP_THREADS__
        printf("__STDCPP_THREADS__ is defined as: %d\n", __STDCPP_THREADS__);
    #else
        printf("__STDCPP_THREADS__ is not defined\n");
    #endif

    // __STDC_NO_THREADS__ Defined as 1 if the implementation doesn't support optional standard threads. The MSVC implementation defines it as 1 when compiled as C and one of the /std C11 or C17 options is specified
    #ifdef __STDC_NO_THREADS__
        printf("__STDC_NO_THREADS__ is defined as: %d\n", __STDC_NO_THREADS__);
    #else
        printf("__STDC_NO_THREADS__ is not defined\n");
    #endif

    // __STDC_NO_VLA__ is defined as 1 if variable length arrays are not supported. The MSVC implementation defines it as 1 when compiled as C and one of the /std C11 or C17 options is specified.
    #ifdef __STDC_NO_VLA__
        printf("__STDC_NO_VLA__ is defined as: %d\n", __STDC_NO_VLA__);
    #else
        printf("__STDC_NO_VLA__ is not defined\n");
    #endif

    // __STDC_VERSION__ is defined to indicate the version of the C standard. Defined when compiled as C and one of the /std C11 or C17 options is specified. It expands to 201112L for /std:c11, and 201710L for /std:c17.
    #ifdef __STDC_VERSION__
        printf("__STDC_VERSION__ is defined as: %ld\n", __STDC_VERSION__);
    #else
        printf("__STDC_VERSION__ is not defined\n");
    #endif

    // When /std:c17 or later is specified, this macro expands to a size_t literal that has the value of the alignment guaranteed by a call to alignment-unaware operator new. Larger alignments are passed to an alignment-aware overload, such as operator new(std::size_t, std::align_val_t). For more information, see /Zc:alignedNew (C++17 over-aligned allocation).
    #ifdef __STDCPP_DEFAULT_NEW_ALIGNMENT__
        printf("__STDCPP_DEFAULT_NEW_ALIGNMENT__ is defined as: %zu\n", __STDCPP_DEFAULT_NEW_ALIGNMENT__);
    #else
        printf("__STDCPP_DEFAULT_NEW_ALIGNMENT__ is not defined\n");
    #endif

    return 0;
}
