#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <stdio.h>
#include <iostream>
#include "../headers/metaclasses.hpp"
#include "List.hpp"

using namespace std;

TEST_CASE("Default List") {
    List<uint64_t> M;
    M.append(1827);
    M.append(623);
    M.append(185);
    M.append(845);
    M.append(43);
    M.append(98612);
    M.append(5422);

    SECTION("Basic object methods") {
        REQUIRE(M.length() == 7);

        REQUIRE_NOTHROW(M.remove(M.get(845)));

        REQUIRE(M.get_head()->value == 1827);

        REQUIRE(M[2] == 185);

        REQUIRE(M.exists(5422));

        REQUIRE_FALSE(M.exists(-63728));

        REQUIRE(M.index(623) == 1);

        REQUIRE_THROWS_AS(M.remove(M.get(1000)), Error);

        REQUIRE_NOTHROW(M.clear());
    }
}

TEST_CASE("Advanced List") {
    List<uint64_t> M;
    M.append(1827);
    M.append(623);
    M.append(185);
    M.append(845);
    M.append(43);
    M.append(98612);
    M.append(5422);

    List<uint64_t> N;
    N.append(6251);
    N.append(93);
    N.append(6890);
    N.append(1029);
    N.append(728);
    N.append(1);
    N.append(58920);

    SECTION("Addition") {
        List<uint64_t> P;

        P = M + N;

        REQUIRE(P.length() == M.length() + N.length());

        REQUIRE(P[0] == 1827);
        REQUIRE(P[12] == 1);

        REQUIRE(P.exists(M[3]));
        REQUIRE(P.exists(N[6]));
        REQUIRE_FALSE(P.exists(-2438791));
    }

    SECTION("Other operators") {
        REQUIRE_THROWS_AS(M - N, runtime_error);
        REQUIRE_THROWS_AS(M * N, runtime_error);
        REQUIRE_THROWS_AS(M / N, runtime_error);
    }
}