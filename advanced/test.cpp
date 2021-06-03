#include <stdio.h>
#include <iostream>
#include "../headers/metaclasses.hpp"
#include "List.hpp"

using namespace std;

int main() {
    List<int> M;
    List<int> N;

    M.append(10);
    M.append(20);
    M.append(30);

    N.append(100);
    N.append(200);
    N.append(300);

    auto P = N + M;

    cout << P.length() << endl;
}