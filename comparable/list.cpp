#include <stdio.h>
#include <iostream>
#include "../headers/metaclasses.hpp"
#include "../comparable/List.hpp"

// ! The code written in this file is not supported in C++ standart yet (at least for now)
// ! So, make sure your compiler does support Concepts
// ! For example if you are using GCC (G++), use the flag '-fconcepts' like this:
// ! g++ -fconcepts list.cpp -o list 

// ! If this code does not compile on your machine, it means your machine does not support Concepts in C++.

using namespace std;
using IntList = ComparableList<int>;

const size_t ARR_SIZE = 10;

int main(int argc, char **argv) {

    // Create the basic C-style array of 10 integers
    int f_arr[ARR_SIZE] {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

    // Construct a linked list from the previously declared array
    IntList fibonacci(f_arr, ARR_SIZE);

    // Copy the existing list into a new one
    IntList fib {fibonacci};

    // Append two more numbers to the list
    fib.append(89);
    fib.append(144);

    cout << "Index of 5: " << fib.index(5) << endl;
    cout << "The largest element is: " << fib.max() << endl;

    return 0;
}