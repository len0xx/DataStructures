#include <stdio.h>
#include <iostream>
#include "../headers/metaclasses.hpp"
#include "../headers/List.hpp"

using namespace std;

const size_t ARR_SIZE = 10;

int main(int argc, char **argv) {

    // Create the basic C-style array of 10 integers
    int f_arr[ARR_SIZE] {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

    // Construct a linked list from the previously declared array
    List<int> fibonacci(f_arr, ARR_SIZE);

    // Copy the existing list into a new one
    List<int> fib {fibonacci};

    // Append two more numbers to the list
    fib.append(89);
    fib.append(144);

    // Print all of its elements to the screen
    // for (auto i = 0; i < fib.Length(); ++i)
    //     cout << fib[i] << endl;

    cout << "Index of 5: " << fib.index(5) << endl;

    return 0;
}