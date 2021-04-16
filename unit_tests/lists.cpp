#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stdio.h>
#include <iostream>
#include "../headers/metaclasses.hpp"
#include "../headers/List.hpp"

using namespace std;

const size_t ARR_SIZE = 10;

// Testing the single-linked list data structure
TEST_CASE("List") {
    int f_arr[ARR_SIZE] {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    List<int> fibonacci(f_arr, ARR_SIZE);

    SECTION("Index of the element 5 equals to 4") {
        REQUIRE(fibonacci.index(5) == 4);
    }

    SECTION("Length of the list equals to the length of the array") {
        REQUIRE(fibonacci.length() == ARR_SIZE);
    }
    
    SECTION("Exists function works") {
        REQUIRE(fibonacci.exists(f_arr[9]));
    }
    
    SECTION("Indexing works") {
        REQUIRE(fibonacci[7] == f_arr[7]);
    }
    
    SECTION("Trying to get beyond the length throws an error") {
        REQUIRE_THROWS(fibonacci[20]);
    }
}