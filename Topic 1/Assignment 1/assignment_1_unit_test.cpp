/*
 * Name        : lab_3_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #3 Functionality
 * Sources     :
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "assignment_1.h"

TEST_CASE("CountWords(\"\")") {
  SECTION("CountWords(\"\")") {
    CHECK(CountWords("") == 0);
  }

  SECTION("CountWords(\"hello\")") {
    CHECK(CountWords("hello") == 1);
  }
  
 SECTION("CountWords(\"hello,world\")") {
    CHECK(CountWords("hello,world") == 1);
  }
  
  SECTION("CountWords(\"hello world\")") {
    CHECK(CountWords("hello world") == 2);
  }
  
  SECTION("CountWords(\"hello, world\")") {
    CHECK(CountWords("hello, world") == 2);
  }

  SECTION("CountWords(\"testing a large large sentence\")") {
    CHECK(CountWords("testing a large large sentence") == 5);
  }
}

TEST_CASE("CheckAlphabetic(\"\")"){
  SECTION("CheckAlphabetic(\"\")"){
    CHECK(CheckAlphabetic("") == 0);
  }
  SECTION("CheckAlphabetic(\"ABC123\")"){
    CHECK(CheckAlphabetic("ABC123") == 0);
  }
  SECTION("CheckAlphabetic(\"ABC\")"){
    CHECK(CheckAlphabetic("ABC") == 1);
  }
  SECTION("CheckAlphabetic(\"ABCxyz\")"){
    CHECK(CheckAlphabetic("ABCxyz") == 1);
  }
    SECTION("CheckAlphabetic(\"ABC\t\")"){
    CHECK(CheckAlphabetic("ABC\t") == 0);
  }
}

TEST_CASE("EncryptString(\"\", 5)"){
  string s = "";
  SECTION("EncryptString(s, 5)"){
    CHECK(EncryptString(s,5) == 0);
    CHECK(s == "");
  }
  
  s = "Hello World";
  SECTION("EncryptString(s, 5)"){
    CHECK(EncryptString(s, 5) == 0);
  }
}
TEST_CASE("EncryptString(\"HelloWorld\", 5)"){
  string s = "HelloWorld";
  SECTION("EncryptString(s,5)"){
    CHECK(EncryptString(s, 5) == 1);
    CHECK(s == "MjqqtBtwqi");
  }
  SECTION("EncryptString(s, 25)"){
    CHECK(EncryptString(s, 25) == 1);
    CHECK(s == "GdkknVnqkc");
  }
  SECTION("EncryptString(s, 1000000)"){
    CHECK(EncryptString(s, 1000000) == 1);
    CHECK(s == "VszzcKcfzr");
  }
  SECTION("EncryptString(s, -1000000)"){
    CHECK(EncryptString(s, -1000000) == 1);
    CHECK(s == "TqxxaIadxp");
  }
}

TEST_CASE("DecryptString(\"\", 5)"){
  string s = "";
  SECTION("EncryptString(s, 5)"){
    CHECK(EncryptString(s,5) == 0);
    CHECK(s == "");
  }
  
  s = "Hello World";
  SECTION("DecryptString(s, 5)"){
    CHECK(EncryptString(s, 5) == 0);
  }
}
TEST_CASE("DecryptString(\"HelloWorld\", 5)"){
  string s = "MjqqtBtwqi";
  SECTION("DecryptString(s,5)"){
    CHECK(DecryptString(s, 5) == 1);
    CHECK(s == "HelloWorld");
  }
  s = "GdkknVnqkc";
  SECTION("DecryptString(s, 25)"){
    CHECK(DecryptString(s, 25) == 1);
    CHECK(s == "HelloWorld");
  }
  s = "VszzcKcfzr";
  SECTION("DecryptString(s, 1000000)"){
    CHECK(DecryptString(s, 1000000) == 1);
    CHECK(s == "HelloWorld");
  }
  s = "TqxxaIadxp";
  SECTION("DecryptString(s, -1000000)"){
    CHECK(DecryptString(s, -1000000) == 1);
    CHECK(s == "HelloWorld");
  }
}

TEST_CASE("ComputeAverage({0}, 0)"){
  double values[] = {10.5, 20.3, 30.2, 12.5};
  
  SECTION("ComputeAverage(values, 4"){
    CHECK(ComputeAverage(values, 4) == 18.375);
  }
  
  for(int i = 0; i<4; i++)
  {
    values[i] = 0;
  }
  SECTION("ComputeAverage(values, 4)"){
    CHECK(ComputeAverage(values, 4) == 0);
  }
  
  values[0] = 5;
  values[1] = 7;
  values[2] = 11;
  values[3] = 7;
  SECTION("ComputeAverage(values, 4)"){
    CHECK(ComputeAverage(values, 4) == 7.5);
  }
  
  values[0] = -10.5;
  values[1] = -20.3;
  values[2] = -30.2;
  values[3] = -12.5;
  SECTION("ComputeAverage(values, 4"){
    CHECK(ComputeAverage(values, 4) == -18.375);
  }
}

TEST_CASE("FindMinValue(values, 3)"){
  double values[] = {-1.1, 0, 1.1};
  SECTION("FindMinValue(values, 3)"){
    CHECK(FindMinValue(values, 3) == -1.1);
  }
  
  for(int i = 0; i<3; i++)
  {
    values[i] = 0;
  }
  
  SECTION("FindMinValue(values, 3"){
    CHECK(FindMinValue(values, 3) == 0);
  }
  
  values[0] = -3.1;
  values[1] = -3.2;
  values[2] = -3.3;
  SECTION("FindMinValue(values, 3"){
    CHECK(FindMinValue(values, 3) == -3.3);
  }
  
  values[0] = 0;
  values[1] = 1;
  values[2] = 2.2;
  SECTION("FindMinValue(values, 3)"){
    CHECK(FindMinValue(values,3) == 0);
  }
}

TEST_CASE("FindMaxValue({0}, 0)"){
  double values[] = {1.1, 0, -1.1};
  
  SECTION("FindMaxValue(values, 3)"){
    CHECK(FindMaxValue(values, 3) == 1.1);
  }
  
  for(int i = 0; i<3; i++)
  {
    values[i] = 0;
  }
  SECTION("FindMaxValue(values, 3)"){
    CHECK(FindMaxValue(values, 3) == 0);
  }
  
  values[0] = 0;
  values[1] = 1.1;
  values[2] = 2.2;
  SECTION("FindMaxValue(values, 3)"){
    CHECK (FindMaxValue(values, 3) == 2.2);
  }
}