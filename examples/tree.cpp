#include <stdio.h>
#include <iostream>
#include "BinarySearchTree.hpp"

using namespace std;

int main(int argc, char **argv) {

    // Initialize a tree with the root element of 820
    BinarySearchTree theTree{820};

    // Just a number to check its presence
    int anEntry = 384;


    // Add some elements to the tree
    theTree.append(521);
    theTree.append(1280);
    theTree.append(3772);
    theTree.append(1687);
    theTree.append(622);
    theTree.append(81);
    theTree.append(anEntry);


    // Check if some numbers are present in the tree or not
    if (theTree.exists(anEntry))
        cout << "An entry is present in the tree" << endl;
    else
        cout << "An entry was not found!" << endl;

    if (theTree.exists(180))
        cout << "The number 180 is present in the tree" << endl;
    else
        cout << "The number 180 was not found!" << endl;


    // Basic methods usage
    cout << "The smallest tree node is " << theTree.minimum() << endl;
    cout << "The largest tree node is " << theTree.maximum() << endl;
    
    cout << "There are " << theTree.length() << " nodes currently in this tree" << endl;

    return 0;
}