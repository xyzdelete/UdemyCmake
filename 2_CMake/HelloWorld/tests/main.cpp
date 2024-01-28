#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include <my_lib.h>

TEST_CASE("Factorials are computed", "[Factorial]")
{
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(10) == 3'628'800);
}
