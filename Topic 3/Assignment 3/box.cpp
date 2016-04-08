/**
 * Name: box.h
 * Author: David Dalton
 * Sources:
 */

#include "box.h"
#include "prize.cpp"

    /**
     * Default constructor
     * initial values boxNumber (0), boxColor ("NO COLOR"), prizeCapacity (5), 
     * prizeCount(0); in the definition, prizes array must be initialized to 
     * match prizeCapacity
     */
    Box::Box() 
    {
        boxNumber_ = 0;
        boxColor_ = "NO COLOR";
        prizeCapacity_ = 5;
        prizeCount_ = 0;
        prizes_ = new Prize[prizeCapacity_];
        for(unsigned int i = 0;i < prizeCapacity_; i++)
        {
            prizes_[i] = scratch_;
        }
    }
    /**
     * Overloaded constructor
     * parameters for boxNumber, boxColor, prizeCapacity; in the definition, 
     * prizes array must be initialized to match prizeCapacity
     */
    Box::Box(unsigned int number,string color,
        unsigned int capacity, unsigned int count ) 
    {
        boxNumber_ = number;
        boxColor_ = color;
        prizeCapacity_ = capacity;
        prizeCount_ = count;
        prizes_ = new Prize[prizeCapacity_];
        for(unsigned int i = 0;i < prizeCapacity_; i++)
        {
            prizes_[i] = scratch_;
        }
    }
    /**
     * Deconstructor
     * free memory associated with prizes
     */
    Box::~Box() 
    {
        delete[] prizes_;
    }
    /**
     * Mutator for boxNumber_
     */
    void Box::setBoxNumber(unsigned int number) 
    {
        boxNumber_ = number;
    }
    /**
     * Mutator for boxColor_
     */
    void Box::setBoxColor(string color) 
    {
        boxColor_ = color;
    }
    /**
     * Accessor for boxNumber_
     */
    unsigned int Box::getBoxNumber() 
    {
        return boxNumber_;
    }
    /**
     * Accessor for boxColor_
     */
    string Box::getBoxColor() 
    {
        return boxColor_;
    }
    /**
     * Accessor for prizeCapacity_
     */
    unsigned int Box::getPrizeCapacity() 
    {
        return prizeCapacity_;
    }
    /**
     * Accessor for prizeCount_
     */
    unsigned int Box::getPrizeCount() 
    {
        return prizeCount_;
    }
    /**
     * parameters prize (Prize), return value (bool); place prize in prizes 
     * array if there is space and return true, else return false
     */
    bool Box::addPrize(Prize prize) 
    {
        for(unsigned int i = 0;i < prizeCapacity_; i++)
        {
            if(prizes_[i] == scratch_)
            {
                prizes_[i] = prize;
                prizeCount_ = prizeCount_ + 1;
                return true;
            }
        }
        return false;
    }
    /**
     * parameters index (unsigned int), return value Prize&; return a Prize if 
     * index is valid, else return scratch (data member declared in class 
     * header)
     */
    Prize Box::getPrize(unsigned int index) 
    {
        if(prizes_[index] == scratch_)
        {
            return prizes_[index];
        } else
        {
            return prizes_[index];
            //return scratch_;
        }
    }
    /**
     * parameters index (unsigned int), return value Prize; remove and return 
     * Prize if index is valid, else return scratch (data member declared in 
     * class header)
     */
    Prize Box::removePrize(unsigned int index) 
    {
        if(prizes_[index] == scratch_)
        {
            return scratch_;
        } else
        {
            Prize prize = prizes_[index];
            prizes_[index] = scratch_;
            prizeCount_ = prizeCount_ - 1;
            return prize;
        }
    }