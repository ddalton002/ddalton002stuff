/*
 * Name        : item.h
 * Author      : David Dalton
 * Description : Class Header File
 */

#include "item.h"

/*
 * Constructor
 *takes two parameters, one for each private member variable
 *defaults name_ to "item"
 *defaults value_ to 0
 */
Item::Item(string name, unsigned int value) 
{
    
    name_ = name;
    value_ = value;
}
/*
 *Destructor
 */
Item::~Item() 
{
    
}
/*
 * Mutator #1
 *sets the value of name_ to be equal to the input string
 */
void Item::set_name(string name) 
{
    name_ = name;
}
/*
 * Mutator #2
 *sets the value of value_ to be equal to the input int
 */
void Item::set_value(unsigned int value) 
{
    value_ = value;
}
/*
 * Accessor #1
 *retrieves the value of name_
 */ 
string Item::name() 
{
    return name_;
}
/*
 * Accessor #2
 *retrieves the value of value_
 */
unsigned int Item::value() 
{
    return value_;
}
/*
 *string ToString()
 *returns a string containing name_ and value_
 *Format -- name_, $value_
 */
string Item::ToString() 
{
    stringstream returned_string;
    returned_string << name_ << ", $" << value_;
    return returned_string.str();
}