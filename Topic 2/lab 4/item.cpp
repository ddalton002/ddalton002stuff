/*
BASE Class Name: Item
Filenames: item.h/item.cpp
Private Members:
string name_
--holds the name of the item
unsigned int value_
--holds the value of the item
Public Members:
Constructor
--two parameters, one for each private member variable
--defaults name_ to "item"
--defaults value_ to 0
Destructor
--does nothing
--must be virtual (add virtual keyword before the destructor)
Accessors and Mutators for the 2 private varaibles
--use the naming scheme we have been using all semester
string ToString()
--returns a string containing name_ and value_
Format -- name_, $value_
*/