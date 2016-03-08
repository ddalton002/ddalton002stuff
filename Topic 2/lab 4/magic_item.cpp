/*
 * Name        : item.h
 * Author      : David Dalton
 * Description : Class Header File
 */

#include "magic_item.h"

/*
 * Constructor
 *takes four parameters, one for each private member variable and two for the
 *base class
 *defaults name_ to "magicitem"
 *defaults value_ to 0
 *defaults description_ to "no description"
 *defaults mana_required_ to 0
 */
MagicItem::MagicItem(string name, unsigned int value, 
        string description, unsigned int mana_required) 
{
    Item::set_name(name);
    Item::set_value(value);
    desciption_ = description;
    mana_required_ = mana_required;
}
/*
 *Destructor
 */
MagicItem::~MagicItem() 
{
    
}
/*
 * 
 * Mutator #1
 *sets the value of description to the input string
 */
void MagicItem::set_description(string description) 
{
    desciption_ = description;
}
/*
 * Mutator #2
 *sets the value of mana_required_ to the input int
 */
void MagicItem::set_mana_required(unsigned int mana_required) 
{
    mana_required_ = mana_required;
}
/*
 * Accessor #1
 *retrieves the value of description_
 */
string MagicItem::description() 
{
    return desciption_;   
}
/*
 * Accessor #2
 *retrieves the value of mana_required_
 */
unsigned int MagicItem::mana_required()
{
    return mana_required_;
}
/*
 *string ToString()
 *returns a string containing name_, value_, desciption_, and
 *mana_required_
 *(uses Item::ToString in its implementation)
 *Format -- name_, $value_, description_, requires mana_required_ mana
 *EXAMPLE -- hat, $10, made of felt, requires 2 mana
 */
string MagicItem::ToString()
{
    stringstream returned_string;
    string base_string = Item::ToString();
    returned_string << base_string << ", " << desciption_ << ", requires " 
    << mana_required_ << " mana";
    return returned_string.str();
}