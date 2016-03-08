/*
 * Name        : magic_item.h
 * Author      : David Dalton
 * Description : Derived Class Header File
 */

#ifndef MAGIC_H
#define MAGIC_H

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
class MagicItem : public Item {
 public:
 /*
  * Constructor
  *takes four parameters, one for each private member variable and two for the
  *base class
  *defaults name_ to "magicitem"
  *defaults value_ to 0
  *defaults description_ to "no description"
  *defaults mana_required_ to 0
  */
  MagicItem(string name = "magicitem", unsigned int value = 0, 
        string description = "no description", unsigned int mana_required = 0);
  /*
   *Destructor
   */
  virtual ~MagicItem();
  /*
   * Mutator #1
   *sets the value of description to the input string
   */
  void set_description(string description);
  /*
   * Mutator #2
   *sets the value of mana_required_ to the input int
   */
  void set_mana_required(unsigned int mana_required);
  /*
   * Acessor #1
   *retrieves the value of description_
   */
  string description();
  /*
   * Acessor #2
   *retrieves the value of mana_required_
   */
  unsigned int mana_required();
  /*
   *string ToString()
   *returns a string containing name_, value_, desciption_, and
   *mana_required_
   *(uses Item::ToString in its implementation)
   *Format -- name_, $value_, description_, requires mana_required_ mana
   *EXAMPLE -- hat, $10, made of felt, requires 2 mana
   */
  string ToString();
 private:
  string desciption_;
  unsigned int mana_required_;
};

#endif