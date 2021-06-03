#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include "../headers/metaclasses.hpp"
#include "../headers/Dictionary.hpp"

using namespace std;

// Testing the dictionary data structure
TEST_CASE("Dictionary") {
    Dictionary<string> capitals {};
    capitals.append("Japan", "Tokyo");
    capitals.append("USA", "Washington DC");
    capitals.append("Great Britain", "London");
    capitals.append("Canada", "Ottawa");
    capitals.append("Sweden", "Stockholm");

    SECTION("Append method") {
        REQUIRE_NOTHROW(capitals.append("Russia", "Moscow"));
    }

    SECTION("Indexing") {
        REQUIRE(capitals["USA"] == "Washington DC");
        REQUIRE(capitals["Sweden"] == "Stockholm");
    }

    SECTION("Length method") {
        REQUIRE(capitals.length() == 5);
    }

    SECTION("Remove method") {
        auto entry = capitals.get("Tokyo");
        REQUIRE_NOTHROW(capitals.remove(entry));
    }

    SECTION("Non-existing index throws an error") {
        REQUIRE_THROWS(capitals["Poland"]);
    }
}