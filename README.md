# DataStructures
Basic data structures written in C++

## Examples

### Single-linked list

```c++
#include <iostream>
#include <string>
#include "headers/List.hpp"

int main(int argc, char **argv) {

    List<std::string> languagesIKnow;

    languagesIKnow.append("JavaScript");
    languagesIKnow.append("PHP");
    languagesIKnow.append("C/C++");
    languagesIKnow.append("Assembly");
    languagesIKnow.append("Python");

    std::cout << "I can write programs in these programming languages:" << std::endl;
    for (int k = 0; k < languagesIKnow.length(); ++k)
        std::cout << k + 1 << ". " << languagesIKnow[k] << std::endl;

    if (languagesIKnow.exists("Rust"))
        std::cout << "I can also write programs in Rust" << std::endl;
    else
        std::cout << "But I can't write programs in Rust :(" << std::endl;

    return 0;
}
```
### Binary Search Tree

```c++
#include <iostream>
#include <string>
#include "headers/BinarySearchTree.hpp"

int main(int argc, char **argv) {

    BinarySearchTree tree {261};

    tree.append(102);
    tree.append(821);
    tree.append(42);
    tree.append(573);
    tree.append(171);
    tree.append(290);
    tree.append(81);
    tree.append(200);
    tree.append(527);
    tree.append(301);

    std::cout << "The smallest value of the tree is: " << tree.minimum() << std::endl;

    std::cout << "The largest value of the tree is: " << tree.maximum() << std::endl;

    std::cout << "There are " << tree.length() << " nodes in the tree" << std::endl;

    if (tree.exists(10)) {
        std::cout << "10 is present in the tree" << std::endl;
    } else {
        std::cout << "10 is not present in the tree" << std::endl;
    }

    return 0;
}
```
### LIFO Stack (based on the linked list)

```c++
#include <iostream>
#include <string>
#include "headers/Stack.hpp"

int main(int argc, char **argv) {

    Stack<std::string> taskManager {};

    taskManager.insert("svhost.exe");
    taskManager.insert("exporer.exe");
    taskManager.insert("VSCode.exe");
    taskManager.insert("Terminal.exe");
    taskManager.insert("Brave.exe");
    taskManager.insert("iTunes.exe");

    std::cout << "There are currently " << taskManager.length() << " proccesses running" << std::endl;

    std::cout << "Most recently opened program was: " << *(taskManager.pop()) << std::endl;

    std::cout << "Now there is one less: " << taskManager.length() << std::endl;

    return 0;
}
```

Go to [examples](https://github.com/len0xx/DataStructures.cpp/tree/main/examples) folder to check more examples of how to use these data structures
