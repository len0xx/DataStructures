# DataStructures
Basic data structures written in C++

## Examples

### Single-linked list

```c++
#include <stdio.h>
#include <iostream>
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

Go to [examples](https://github.com/len0xx/DataStructures.cpp/tree/main/examples) folder to check more examples of how to use these data structures
