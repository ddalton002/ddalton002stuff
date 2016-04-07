/**
 * Name: prize.h
 * Author: David Dalton
 * Sources:
 */

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
     void set_prize_name();
    /**
     * Mutator for prizeValue_
     */
     void set_prize_value();
    /**
     * Accessor for prizeName_
     */
     string  get_prize_name();
    /**
     * Accessor for prizeValue_
     */
     unsigned int get_prize_value();
    /**
     * Overloaded operator
     * returns true if the prizeName and prizeValue of the two Prizes being 
     * compared are equivalent, else return false
     */
     bool friend overloaded==();
     
    private:
     prizeName_;
     prizeValue_;
};