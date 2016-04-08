/**
 * Name: prize.h
 * Author: David Dalton
 * Sources:
 */

#ifndef PRIZE_H
#define PRIZE_H

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Prize
{
    public:
    /**
     * Default constructor
     * initial values itemName ("NO NAME"), itemValue (0)
     */
     Prize();
    /**
     * Overloaded constructor
     * parameters for all data members
     */
     Prize(string name, unsigned int value);
    /**
     * Deconstructor
     * empty
     */
     ~Prize();
    /**
     * Mutator for prizeName_
     */
     void setPrizeName(string name);
    /**
     * Mutator for prizeValue_
     */
     void setPrizeValue(unsigned int value);
    /**
     * Accessor for prizeName_
     */
     string getPrizeName();
    /**
     * Accessor for prizeValue_
     */
     unsigned int getPrizeValue();
    /**
     * Overloaded operator
     * returns true if the prizeName and prizeValue of the two Prizes being 
     * compared are equivalent, else return false
     */
     friend bool operator ==(Prize first_prize, Prize second_prize);
     //friend bool operator ==(const Prize &prize1, const Prize &prize2);
     
    private:
     string prizeName_;
     unsigned int prizeValue_;
};

#endif