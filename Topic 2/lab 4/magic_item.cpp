/*
DERIVED Class Name: MagicItem (base Item)
Filenames: magic_item.h/magic_item.cpp
Private Members:
string description_
--holds a description of the magic item
unsigned int mana_required_
--holds the amount of mana required to use the magic item
Public Members:
Constructor
--four parameters, one for each private member variable and two for the
base class
--defaults name_ to "magicitem"
--defaults value_ to 0
--defaults description_ to "no description"
--defaults mana_required_ to 0
Destructor
--does nothing
--must be virtual (add virtual keyword before the destructor)
Accessors and Mutators for the 2 private varaibles
--use the naming scheme we have been using all semester
string ToString()
--returns a string containing name_, value_, desciption_, and
mana_required_
(uses Item::ToString in its implementation)
Format -- name_, $value_, description_, requires mana_required_ mana
EXAMPLE -- hat, $10, made of felt, requires 2 mana
*/