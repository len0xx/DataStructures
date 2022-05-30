#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "List.hpp"

using namespace std;

const size_t ARR_SIZE = 10;

// Testing the single-linked list data structure
TEST_CASE("List") {
    int f_arr[ARR_SIZE] {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    List<int> fibonacci(f_arr, ARR_SIZE);

    SECTION("Index method") {
        REQUIRE(fibonacci.index(5) == 4);
        REQUIRE(fibonacci.index(34) == 8);
    }

    SECTION("Length of the list equals to the length of the array") {
        REQUIRE(fibonacci.length() == ARR_SIZE);
    }
    
    SECTION("Exists function") {
        REQUIRE(fibonacci.exists(f_arr[9]));
        REQUIRE_FALSE(fibonacci.exists(89));
    }
    
    SECTION("Indexing works") {
        REQUIRE(fibonacci[0] == f_arr[0]);
        REQUIRE(fibonacci[7] == f_arr[7]);
    }
    
    SECTION("Appending the elements") {
        fibonacci.append(89);
        fibonacci.append(144);
        REQUIRE((fibonacci.exists(89) && fibonacci.exists(144)));
        REQUIRE(fibonacci.length() == 12);
    }
    
    SECTION("Removing by Node") {
        fibonacci.append(89);
        fibonacci.append(144);
        auto entry = fibonacci.get(144);
        auto empty_ptr = fibonacci.remove(entry);
        REQUIRE_FALSE(fibonacci.exists(144));
        REQUIRE(empty_ptr == nullptr);
        REQUIRE(fibonacci.length() == 11);
    }
    
    SECTION("Trying to go beyond the length") {
        REQUIRE_THROWS_AS(fibonacci[20], Error);
    }
    
    SECTION("Constructor and destructor") {
        auto ninty = new List<int>(90);
    }
    
    SECTION("Clearing") {
        fibonacci.clear();
        REQUIRE(fibonacci.length() == 0);
    }
}