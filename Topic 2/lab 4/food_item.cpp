/*
 * Name        : item.h
 * Author      : David Dalton
 * Description : Class Header File
 */
 
#include "food_item.h"
 
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
 FoodItem::FoodItem(string name, unsigned int value, unsigned int calories,
                    string unit_of_measure, double units)
{
    Item::set_name(name);
    Item::set_value(value);
    calories_ = calories;
    unit_of_measure_ = unit_of_measure;
    units_ = units;
}
/*
 * 
 *Destructor
 */
FoodItem::~FoodItem() 
{
    
}
/*
 * Mutator #1  *sets the value of calories_ to the input int
 */
void FoodItem::set_calories(unsigned int calories) 
{
    calories_ = calories;
}
/*
 * Mutator #2
 *sets the value of units_of_measure_ to the input string
 */
void FoodItem::set_unit_of_measure(string units_of_measure) 
{
    unit_of_measure_ = units_of_measure;
}
/*
 * Mutator #3
 *sets the value of units_ to the input double
 */
void FoodItem::set_units(double units) 
{
    units_ = units;
}
/*
 * Accessor #1
 *retrieves the value of calories_
 */
unsigned int FoodItem::calories() 
{
    return calories_;
}
/*
 * Accessor #2
 *retrieves the value of units_of_measure_
 */
string FoodItem::unit_of_measure() 
{
    return unit_of_measure_;
}
/*
 * Accessor #3
 *retrieves the value of units_
 */
double FoodItem::units() 
{
    return units_;
}
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
string FoodItem::ToString() 
{
    stringstream returned_string;
    string base_string = Item::ToString();
    returned_string.setf(std::ios::fixed|std::ios::showpoint);
    returned_string.precision(2);
    returned_string << base_string << ", " << units_ << " " 
    << unit_of_measure_ << ", "<< calories_ << " calories";
    return returned_string.str();
}