/*
 * Name        : lab_5_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #3 Functionality
 * Sources     :
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>
#include <iostream>
#include <string>
#include "lab_5.h"
using std::string;

TEST_CASE("Hello Function") {
  string cout_output;
  std::streambuf* oldCout = cout.rdbuf();
  std::ostringstream captureCout;
  cout.rdbuf(captureCout.rdbuf());
  Hello();
  cout.rdbuf(oldCout);
  cout_output = captureCout.str();
  SECTION("Hello()") {
    CHECK(cout_output == "Hello world!");
  }
  captureCout.str("");
}

TEST_CASE("Print Message Function") {
  string cout_output;
  std::streambuf* oldCout = cout.rdbuf();
  std::ostringstream captureCout;
  cout.rdbuf(captureCout.rdbuf());
  PrintMessage("Hello again!");
  cout.rdbuf(oldCout);
  cout_output = captureCout.str();
  SECTION("PrintMessage(\"Hello again!\")") {
    CHECK(cout_output == "Hello again!");
  }
  captureCout.str("");
}

TEST_CASE("Get Answer Function") {
  SECTION("GetAnswer()") {
    CHECK(GetAnswer() == 42);
  }
}

TEST_CASE("Find the Larger Integer") {
  SECTION("FindLarger(-1, 1)") {
    CHECK(FindLarger(-1, 1) == 1);
  }

  SECTION("FindLarger(1, -1)") {
    CHECK(FindLarger(1, -1) == 1);
  }

  SECTION("FindLarger(1, 1)") {
    CHECK(FindLarger(1, 1) == 1);
  }
}

TEST_CASE("Build A Message") {
  SECTION("BuildMessage(\"hello\")") {
    CHECK(BuildMessage("hello") == "Message: hello");
  }

  SECTION("BuildMessage(\"hello\", true)") {
    CHECK(BuildMessage("hello", true) == "Message: HELLO");
  }

  SECTION("BuildMessage(\"HELLO\", false)") {
    CHECK(BuildMessage("HELLO", false) == "Message: HELLO");
  }

  SECTION("BuildMessage(\"HELLO\", true)") {
    CHECK(BuildMessage("HELLO", true) == "Message: HELLO");
  }

  SECTION("BuildMessage()") {
    CHECK(BuildMessage() == "Message: empty");
  }
}
