/*
 * Name        : assign_3_unit_test.cpp
 * Author      : April Browne
 * Description : Unit test to test Assignment #3 Functionality
 *			 adaped from Boyd Trolinger
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Prize.h"
#include "Box.h"


TEST_CASE("Make default Box"){
  Box b1;

  SECTION("getBoxNumber()"){
	CHECK(b1.getBoxNumber() == 0);
  }
  SECTION("getBoxColor()"){
 	CHECK(b1.getBoxColor() == "NO COLOR");
  }
  SECTION ("getPrizeCapacity()"){
	CHECK(b1.getPrizeCapacity() == 5);
  }
  SECTION ("getPrizeCount()"){
	CHECK(b1.getPrizeCount() == 0);
  }
}

TEST_CASE("Default Box Functions"){
  Box b1;
  b1.setBoxNumber(99);
  b1.setBoxColor("red");

  SECTION("setBoxNumber(99)"){
	CHECK(b1.getBoxNumber() == 99);
  }
  SECTION("setBoxColor(\"red\")"){
	CHECK(b1.getBoxColor() == "red");
  }	
}

TEST_CASE("Constructor Custom Box"){
  Box b2(42, "blue", 3);
  SECTION ("getBoxNumber()"){
 	  CHECK (b2.getBoxNumber() == 42);
  }
  SECTION ("getBoxColor()"){
	  CHECK (b2.getBoxColor() == "blue");
  }
  SECTION ("getPrizeCapacity()"){
	  CHECK (b2.getPrizeCapacity() == 3);
  }
  SECTION ("getPrizeCount()"){
  	CHECK (b2.getPrizeCount() == 0);
  }
}

TEST_CASE ("Test Prizes"){
  Box b2(42, "blue", 3);
  
  SECTION("removePrize(0)"){
 	CHECK (b2.removePrize(0) == Prize());
  } 	
  
  b2.addPrize(Prize("BRONZE PRIZE", 1));
  SECTION("addPrize(\"Bronze\")"){
	CHECK (b2.getPrizeCount() == 1);
  }
  
	b2.addPrize(Prize("SILVER PRIZE", 100));
  SECTION("addPrize(\"Silver\")"){
	CHECK (b2.getPrizeCount() == 2);
  }
  
	b2.addPrize(Prize("GOLD PRIZE", 10000));
  SECTION("addPrize(\"Gold\")"){
	CHECK(b2.getPrizeCount() == 3);
  }

  SECTION("addPrize(\"Diamond\")"){
	CHECK(b2.addPrize(Prize("DIAMOND PRIZE", 999)) == false);
  }
}

TEST_CASE("Test Remove and Add Prizes"){


  SECTION("remove prize and add new prize"){
	  Box b2(42, "blue", 3);
  b2.addPrize(Prize("BRONZE PRIZE", 1));
  b2.addPrize(Prize("SILVER PRIZE", 100));
  b2.addPrize(Prize("GOLD PRIZE", 10000));
  CHECK(b2.removePrize(2) == Prize("GOLD PRIZE", 10000));
  	CHECK(b2.addPrize(Prize("RUBY PRIZE", 9999)) == true);
	CHECK(b2.getPrizeCount() == 3);
		CHECK (b2.getPrizeCapacity() == 3);
  }
  

}

TEST_CASE("Prize default constructor"){
  Prize p1;

  SECTION("getPrizeName()"){
	CHECK(p1.getPrizeName() == "NO NAME");
  }
  SECTION("getPrizeValue()"){
	CHECK(p1.getPrizeValue() == 0);
  }
}

TEST_CASE ("Prize functions"){
  Prize p1;
  SECTION ("setPrizeName(\"FOOD PRIZE\")"){
	  p1.setPrizeName("FOOD PRIZE");
	  CHECK (p1.getPrizeName() == "FOOD PRIZE");
  }
  SECTION ("setPrizeValue(17)"){
	  p1.setPrizeValue(17);
	  CHECK (p1.getPrizeValue() == 17);
  }
}

TEST_CASE ("HAT prize"){
  Prize p2("HAT PRIZE", 50);
    SECTION ("getPrizeName()"){
	  CHECK (p2.getPrizeName() == "HAT PRIZE");
  }
    SECTION ("getPrizeValue()"){
	  CHECK (p2.getPrizeValue() == 50);
  }
}

TEST_CASE ("Prize 1 vs Prize 2"){


  SECTION ("=="){
  Prize p1;
	p1.setPrizeName("FOOD PRIZE");
	p1.setPrizeValue(17);
  Prize p2("HAT PRIZE", 50);
	CHECK ((p1 == p2) == false);
  }


  SECTION ("== again"){
  Prize p1;
	p1.setPrizeName("FOOD PRIZE");
	p1.setPrizeValue(17);
  Prize p2("HAT PRIZE", 50);
  p2.setPrizeValue(1);
	CHECK ((p1 == p2) == false);
  }
}
