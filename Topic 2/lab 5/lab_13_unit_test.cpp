/*
 * Programming Challenge 21 - UNIT TEST
 */

#include "lab_5.h"

/*
 * Programming Challenge 13
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

 #include <iostream>
 using std::ostringstream;

TEST_CASE ("Box<int> class functionality", "[Box]") {
	Box<int> intBox(99);

	CHECK(intBox.getContents() == 99);

	intBox.setContents(42);
	CHECK(intBox.getContents() == 42);

	ostringstream ss;
	ss << intBox;
	CHECK(ss.str() == "42");
}

TEST_CASE ("Box<bool> class functionality", "[Box]") {
	Box<bool> boolBox(false);

	CHECK(boolBox.getContents() == false);

	boolBox.setContents(true);
	CHECK(boolBox.getContents() == true);

	ostringstream ss;
	ss << boolBox;
	CHECK(ss.str() == "1");
}

TEST_CASE ("Box<float> class functionality", "[Box]") {
	Box<float> floatBox(1.23f);

	CHECK(floatBox.getContents() == 1.23f);

	floatBox.setContents(3.21f);
	CHECK(floatBox.getContents() == 3.21f);

	ostringstream ss;
	ss << floatBox;
	CHECK(ss.str() == "3.21");
}

TEST_CASE ("Box<string> class functionality", "[Box]") {
	Box<string> stringBox("hello");

	CHECK(stringBox.getContents() == "hello");

	stringBox.setContents("goodbye");
	CHECK(stringBox.getContents() == "goodbye");

	ostringstream ss;
	ss << stringBox;
	CHECK(ss.str() == "goodbye");
}

TEST_CASE("Sum()") {
  SECTION("Integers. Array: { 3, 5, 7, 9, 11 }") {
    int int_values[] = { 3, 5, 7, 9, 11 };
    CHECK(Sum(int_values, 5) == 35);
    CHECK(Sum(int_values, 1) == 3);
    CHECK(Sum(int_values, 0) == 0);
  }

  SECTION("Doubles. Array: { 3.1, 5.2, 7.3, 9.4, 11.5 }") {
    double double_values[] = { 3.1, 5.2, 7.3, 9.4, 11.5 };
    CHECK(Sum(double_values, 5) == 36.5);
    CHECK(Sum(double_values, 1) == 3.10);
    CHECK(Sum(double_values, 0) == 0.0);
  }

  SECTION("Strings. Array: { \"A\", \"B\", \"C\", \"D\", \"E\" }") {
    string string_values[] = { "A", "B", "C", "D", "E" };
    CHECK(Sum(string_values, 5) == "ABCDE");
    CHECK(Sum(string_values, 1) == "A");
    CHECK(Sum(string_values, 0) == "");
  }
}