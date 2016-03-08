/*
 * Name        : food_item.h
 * Author      : David Dalton
 * Description : Derived Class Header File
 */

#ifndef FOOD_H
#define FOOD_H

#include "item.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
using std::string;
using std::stringstream;
using std::setprecision;
using std::fixed;
using std::setfill;
using std::setw;

/*
 * Class Item.
 */
class FoodItem : public Item {
 public:
 /*
  * Constructor
  *takes five parameters, one for each private member variable and two for the 
  *base class
  *defaults name_ to "fooditem"
  *defaults value_ to 0
  *defaults calories_ to 0
  *defaults unit_of_measure_ to "nounits"
  *defaults units_ to 0
  */
  FoodItem(string name = "fooditem", unsigned int value = 0, 
            unsigned int calories = 0, string unit_of_measure = "nounits",  
            double units = 0);
  /*
   *Destructor
   */
  virtual ~FoodItem();
  /*
   * Accessors #1
   *sets the value of calories_ to the input int
   */
  void set_calories(unsigned int calories);
  /*
   * Mutator #2
   *sets the value of units_of_measure_ to the input string
   */
  void set_unit_of_measure(string units_of_measure);
  /*
   * Mutator #3
   *sets the value of units_ to the input double
   */
  void set_units(double units);
  /*
   * Acessor #1
   *retrieves the value of calories_
   */
  unsigned int calories();
  /*
   * Acessor #2
   *retrieves the value of units_of_measure_
   */
  string unit_of_measure();
  /*
   * Acessor #3
   *retrieves the value of units_
   */
  double units();
  /*
   *string ToString()
   *returns a string containing name_, value_, units_, unit_of_measure_,
   *and calories_
   *(uses Item::ToString in its implementation)
   *units_ formatted to exactly two decimal places
   *Format -- name_, $value_, units_ unit_of_measure_, calories_
   *calories
   *EXAMPLE -- cookie, $1, 2.50 cookie(s), 250 calories
   */
  string ToString();
 private:
  unsigned int calories_;
  string unit_of_measure_;
  double units_;
};

#endif