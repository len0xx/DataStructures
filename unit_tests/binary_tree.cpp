#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "../headers/metaclasses.hpp"
#include "../headers/BinarySearchTree.hpp"

using namespace std;
using BinaryTree = BinarySearchTree;

// Testing the binary tree data structure
TEST_CASE("Binary tree") {
    BinaryTree theTree = 685;
    const size_t N = 20;
    int numbers[N] = {
        263, 781, 981, 100,
        44, 803, 109, 646,
        1299, 450, 415, 19,
        370, 2887, 901, 1874,
        89, 621, 772, 1682
    };
    for (int i = 0; i < N; ++i) {
        theTree.append(numbers[i]);
    }

    SECTION("Exists method") {
        REQUIRE(theTree.exists(numbers[10]));
    }

    SECTION("Search method") {
        REQUIRE(theTree.search(numbers[5])->value == 803);
    }

    SECTION("Append method") {
        REQUIRE_NOTHROW(theTree.append(7281));
    }

    SECTION("Length method") {
        REQUIRE(theTree.length() == N + 1);
    }

    SECTION("Minimum method") {
        REQUIRE(theTree.minimum() == 19);
    }

    SECTION("Maximum method") {
        REQUIRE(theTree.maximum() == 2887);
    }

    SECTION("Trying to append the existing element throws an error") {
        REQUIRE_THROWS(theTree.append(numbers[0]));
    }

    SECTION("Remove method") {
        auto entry = theTree.search(numbers[16]);
        REQUIRE(theTree.remove(entry));
    }

    SECTION("Children of the root element are: 263 and 781") {
        auto root = theTree.search(685);
        REQUIRE(root->left->value == 263);
        REQUIRE(root->right->value == 781);
    }
}