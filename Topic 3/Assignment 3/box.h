/**
 * Name: box.h
 * Author: David Dalton
 * Sources:
 */

#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <string>
#include <sstream>
#include "prize.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Box
{
    public:
     /**
     * Default constructor
     * initial values boxNumber (0), boxColor ("NO COLOR"), prizeCapacity (5), 
     * prizeCount(0); in the definition, prizes array must be initialized to 
     * match prizeCapacity
     */
     Box();
    /**
     * Overloaded constructor
     * parameters for boxNumber, boxColor, prizeCapacity; in the definition, 
     * prizes array must be initialized to match prizeCapacity
     */
     Box(unsigned int number,string color,
         unsigned int capacity, unsigned int count = 0);
    /**
     * Deconstructor
     * free memory associated with prizes
     */
     ~Box();
    /**
     * Mutator for boxNumber_
     */
     void setBoxNumber(unsigned int number);
    /**
     * Mutator for boxColor_
     */
     void setBoxColor(string color);
    /**
     * Accessor for boxNumber_
     */
     unsigned int getBoxNumber();
    /**
     * Accessor for boxColor_
     */
     string getBoxColor();
    /**
     * Accessor for prizeCapacity_
     */
     unsigned int getPrizeCapacity();
    /**
     * Accessor for prizeCount_
     */
     unsigned int getPrizeCount();
    /**
     * parameters prize (Prize), return value (bool); place prize in prizes 
     * array if there is space and return true, else return false
     */
     bool addPrize(Prize prize);
    /**
     * parameters index (unsigned int), return value Prize&; return a Prize if 
     * index is valid, else return scratch (data member declared in class 
     * header)
     */
      Prize getPrize(unsigned int index);
    /**
     * parameters index (unsigned int), return value Prize; remove and return 
     * Prize if index is valid, else return scratch (data member declared in 
     * class header)
     */
      Prize removePrize(unsigned int index);
     
    private:
     unsigned int boxNumber_;
     string boxColor_;
     Prize scratch_;
     Prize* prizes_;
     unsigned int prizeCapacity_;
     unsigned int prizeCount_;
};

#endif