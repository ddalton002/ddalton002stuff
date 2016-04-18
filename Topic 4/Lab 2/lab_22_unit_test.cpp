/*
 * Name        : lab_22_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #22 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "lab_22.h"



TEST_CASE("Factorial") {
  SECTION("Factorial(0)") {
    CHECK(Factorial(0) == 1);
  }

  SECTION("Factorial(1)") {
    CHECK(Factorial(1) == 1);
  }

  SECTION("Factorial(2)") {
    CHECK(Factorial(2) == 2);
  }

  SECTION("Factorial(5)") {
    CHECK(Factorial(5) == 120);
  }
}

TEST_CASE("Fibonacci") {
  SECTION("Fibonacci(0)") {
    CHECK(Fibonacci(0) == 0);
  }

  SECTION("Fibonacci(1)") {
    CHECK(Fibonacci(1) == 1);
  }

  SECTION("Fibonacci(2)") {
    CHECK(Fibonacci(2) == 1);
  }

  SECTION("Fibonacci(3)") {
    CHECK(Fibonacci(3) == 2);
  }

  SECTION("Fibonacci(15)") {
    CHECK(Fibonacci(15) == 610);
  }
}

TEST_CASE("Palindrome") {
  SECTION("WordIsPalindrome(\"\")") {
    CHECK(WordIsPalindrome("") == true);
  }

  SECTION("WordIsPalindrome(\"a\")") {
    CHECK(WordIsPalindrome("a") == true);
  }

  SECTION("WordIsPalindrome(\"racecar\")") {
    CHECK(WordIsPalindrome("racecar") == true);
  }

  SECTION("WordIsPalindrome(\"sitonapotatopanotis\")") {
    CHECK(WordIsPalindrome("sitonapotatopanotis") == true);
  }

  SECTION("WordIsPalindrome(\"baseball\")") {
    CHECK(WordIsPalindrome("baseball") == false);
  }
}

TEST_CASE("Array Forwards") {
  int numbers[5] = { 5, 10, 15, 20, 25 };
  SECTION("ArrayForwardsAsString(numbers, 0, 5)") {
    CHECK(ArrayForwardsAsString(numbers, 0, 5) == "5 10 15 20 25 ");
  }

  SECTION("ArrayForwardsAsString(numbers, 3, 5)") {
    CHECK(ArrayForwardsAsString(numbers, 3, 5) == "20 25 ");
  }

  SECTION("ArrayForwardsAsString(numbers, 5, 5)") {
    CHECK(ArrayForwardsAsString(numbers, 5, 5) == "");
  }
}

TEST_CASE("Array Backwards") {
  int numbers[5] = { 5, 10, 15, 20, 25 };
  SECTION("ArrayBackwardsAsString(numbers, 4, 5)") {
    CHECK(ArrayBackwardsAsString(numbers, 4, 5) == "25 20 15 10 5 ");
  }

  SECTION("ArrayBackwardsAsString(numbers, 1, 5)") {
    CHECK(ArrayBackwardsAsString(numbers, 1, 5) == "10 5 ");
  }

  SECTION("ArrayBackwardsAsString(numbers, -1, 5)") {
    CHECK(ArrayBackwardsAsString(numbers, -1, 5) == "");
  }
}
