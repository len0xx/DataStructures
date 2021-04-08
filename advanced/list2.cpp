#include <stdio.h>
#include <iostream>
#include "../headers/metaclasses.hpp"
#include "../headers/BinarySearchTree.hpp"
#include "../advanced/List.hpp"

using namespace std;

const size_t ARR_SIZE = 10;

int main(int argc, char **argv) {

    ComparableList<BinarySearchTree> my_garden;
    my_garden.append(BinarySearchTree(100));
    cout << my_garden[0].minimum() << endl;
    
    // try {
    //     ComparableList<BinarySearchTree> my_garden;
    //     my_garden.append(BinarySearchTree(100));
    //     cout << my_garden[0].minimum() << endl;
    // }
    // catch (...) {
    //     cout << "An error occurred." << endl;
    // }

    return 0;
}