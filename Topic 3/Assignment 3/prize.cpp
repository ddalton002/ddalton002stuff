/**
 * Name: prize.h
 * Author: David Dalton
 * Sources:
 */
 
#include "prize.h"

    /**
     * Default constructor
     * initial values itemName ("NO NAME"), itemValue (0)
     */
    Prize::Prize() 
    {
        prizeName_ = "NO NAME";
        prizeValue_ = 0;
    }
    /**
     * Overloaded constructor
     * parameters for all data members
     */
    Prize::Prize(string name, unsigned int value) 
    {
        prizeName_ = name;
        prizeValue_ = value;
    }
    /**
     * Deconstructor
     * empty
     */
    Prize::~Prize() 
    {
        
    }
    /**
     * Mutator for prizeName_
     */
    void Prize::setPrizeName(string name) 
    {
        prizeName_ = name;
    }
    /**
     * Mutator for prizeValue_
     */
    void Prize::setPrizeValue(unsigned int value) 
    {
        prizeValue_ = value;
    }
    /**
     * Accessor for prizeName_
     */
    string Prize::getPrizeName() 
    {
        return prizeName_;
    }
    /**
     * Accessor for prizeValue_
     */
    unsigned int Prize::getPrizeValue() 
    {
        return prizeValue_;
    }
    /**
     * Overloaded operator
     * returns true if the prizeName and prizeValue of the two Prizes being 
     * compared are equivalent, else return false
     */
    
    bool operator ==(Prize first_prize, Prize second_prize) 
    {
        
        if (first_prize.getPrizeName() == second_prize.getPrizeName() &&
        first_prize.getPrizeValue() == second_prize.getPrizeValue())
        {
            return true;
        } else 
        {
            return false;
        }
    }
