/*
 * Name        : lab_12_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #12 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "lab_12.h"

TEST_CASE("Make Dynamic Integer Array") {
  SECTION("MakeDynoIntArray(3)") {
    int* my_array = MakeDynoIntArray(3);
    CHECK(my_array != NULL);
  }
}

TEST_CASE("Sum Array Values") {
  int* my_array = MakeDynoIntArray(3);
  unsigned int my_array_size = 3;

  SECTION("Sum({30, 20, 10})") {
    my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;
    CHECK(Sum(my_array, my_array_size) == 60);
  }

  SECTION("Sum({30, 10, 20})") {
    my_array[0] = 30, my_array[1] = 10, my_array[2] = 20;
    CHECK(Sum(my_array, my_array_size) == 60);
  }

  SECTION("Sum({30, 20, 10})") {
    my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;
    CHECK(Sum(my_array, my_array_size) == 60);
  }

  SECTION("Sum({20, 10, 30})") {
    my_array[0] = 20, my_array[1] = 10, my_array[2] = 30;
    CHECK(Sum(my_array, my_array_size) == 60);
  }
}

TEST_CASE("Max Value in Array") {
  int* my_array = MakeDynoIntArray(3);
  unsigned int my_array_size = 3;

  SECTION("Max({30, 20, 10})") {
    my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;
    CHECK(Max(my_array, my_array_size) == 30);
  }

  SECTION("Max({30, 10, 20})") {
    my_array[0] = 30, my_array[1] = 10, my_array[2] = 20;
    CHECK(Max(my_array, my_array_size) == 30);
  }

  SECTION("Max({30, 20, 10})") {
    my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;
    CHECK(Max(my_array, my_array_size) == 30);
  }

  SECTION("Sum({20, 10, 30})") {
    my_array[0] = 20, my_array[1] = 10, my_array[2] = 30;
    CHECK(Sum(my_array, my_array_size) == 60);
  }
}

TEST_CASE("Minimum Value in Array") {
  int* my_array = MakeDynoIntArray(3);
  unsigned int my_array_size = 3;

  SECTION("Min({30, 20, 10})") {
    my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;
    CHECK(Min(my_array, my_array_size) == 10);
  }

  SECTION("Min({30, 10, 20})") {
    my_array[0] = 30, my_array[1] = 10, my_array[2] = 20;
    CHECK(Min(my_array, my_array_size) == 10);
  }

  SECTION("Min({30, 20, 10})") {
    my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;
    CHECK(Min(my_array, my_array_size) == 10);
  }

  SECTION("Min({20, 10, 30})") {
    my_array[0] = 20, my_array[1] = 10, my_array[2] = 30;
    CHECK(Min(my_array, my_array_size) == 10);
  }
}

TEST_CASE("Testing Exception Handling") {
  int* my_array = NULL;
  unsigned int my_array_size = 0;

  SECTION("Sum() EXCEPTION HANDLING") {
    try {
      Sum(my_array, my_array_size);
      CHECK(1 == 0);
    } catch (const char* e) {
      CHECK(!strcmp(e, "NULL ARRAY REFERENCE"));
    }
  }

  SECTION("Max() EXCEPTION HANDLING") {
    try {
      Max(my_array, my_array_size);
      CHECK(1 == 0);
    } catch (const char* e) {
      CHECK(!strcmp(e, "NULL ARRAY REFERENCE"));
    }
  }

  SECTION("Min() EXCEPTION HANDLING") {
    try {
      Min(my_array, my_array_size);
      CHECK(1 == 0);
    } catch (const char* e) {
      CHECK(!strcmp(e, "NULL ARRAY REFERENCE"));
    }
  }
}


