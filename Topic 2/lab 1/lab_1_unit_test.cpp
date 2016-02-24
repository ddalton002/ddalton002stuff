/*
 * Name        : lab_9_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #9 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "lab_1.h"

TEST_CASE("Creating a Spaceship") {
  Spaceship enterprise;

  enterprise.set_name("USS Enterprise-D");
  SECTION("set_name(\"USS Enterprise-D\")/name()") {
    CHECK(enterprise.name() == "USS Enterprise-D");
  }

  enterprise.set_top_speed(9.6);
  SECTION("set_top_speed(9.6)/top_speed()") {
    CHECK(enterprise.top_speed() >= 9.59);
    CHECK(enterprise.top_speed() <= 9.61);
  }

  enterprise.set_fuel_source("Plasma");
  SECTION("set_fuel_source(\"Plasma\")/fuel_source()") {
    CHECK(enterprise.fuel_source() == "Plasma");
  }

  enterprise.set_crew_capacity(5000);
  SECTION("set_crew_capacity(5000)/crew_capacity()") {
    CHECK(enterprise.crew_capacity() == 5000);
  }

  SECTION("ToString") {
    CHECK(enterprise.ToString() == "USS Enterprise-D\n"
                                   "Top Speed:     Warp 9.60\n"
                                   "Fuel Source:   Plasma\n"
                                   "Crew Capacity: 5000");
  }
}
