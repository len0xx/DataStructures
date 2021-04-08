#include <stdio.h>
#include <iostream>
#include "../headers/metaclasses.hpp"
#include "../headers/SimpleString.hpp"

using namespace std;

int main(int argc, char **argv) {

    string aname = "Prokhor";

    SimpleString myname = aname;

    myname.print();
    cout << endl;

    cout << "There are " << myname.length() << " symbols" << endl;

    cout << "The third character is " << myname[2] << endl;
    
    return 0;
}