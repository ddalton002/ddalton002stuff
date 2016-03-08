/*
 * Name        : item.h
 * Author      : David Dalton
 * Description : Class Header File
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
using std::string;
using std::stringstream;
using std::setprecision;
using std::fixed;

/*
 * Class Item.
 */
class Item {
 public:
 /*
  * Constructor
  *takes two parameters, one for each private member variable
  *defaults name_ to "item"
  *defaults value_ to 0
  */
  Item(string name = "item", unsigned int value = 0);
  /*
   *Destructor
   */
  virtual ~Item();
  /*
   * Mutator #1
   *sets the value of name_ to be equal to the input string
   */
  void set_name(string name);
  /*
   * Mutator #2
   *sets the value of value_ to be equal to the input int
   */
  void set_value(unsigned int value);
  /*
   * Acessor #1
   *retrieves the value of name_
   */
  string name();
  /*
   * Acessor #2
   *retrieves the value of value_
   */
  unsigned int value();
  /*
   *string ToString()
   *returns a string containing name_ and value_
   *Format -- name_, $value_
   */
  string ToString();
 private:
  string name_;
  unsigned int value_;
};

#endif