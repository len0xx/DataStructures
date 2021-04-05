#include <stdio.h>
#include <iostream>
#ifndef METACLASSES
#include "metaclasses.hpp"
#endif

#ifndef LIST
#include "List.hpp"
#endif

using namespace std;

int main(int argc, char **argv) {
    List<int> fibonacci{};

    fibonacci.Append(1);
    fibonacci.Append(1);
    fibonacci.Append(2);
    fibonacci.Append(3);
    fibonacci.Append(5);
    fibonacci.Append(8);
    fibonacci.Append(13);
    fibonacci.Append(21);

    // for (auto i = 0; i < fibonacci.Length(); ++i) {
    //     cout << fibonacci[i] << endl;
    // }

    fibonacci.Clear();

    for (auto i = 0; i < 10; ++i) {
        fibonacci.Append(i * i);
    }

    List<int> fib {fibonacci};

    for (auto i = 0; i < fib.Length(); ++i) {
        cout << fib[i] << endl;
    }

    return 0;
}