/**
 * Name: box.h
 * Author: David Dalton
 * Sources:
 */

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
     Box(unsigned int number,string color,unsigned int capacity);
    /**
     * Deconstructor
     * free memory associated with prizes
     */
     ~Box();
    /**
     * Mutator for boxNumber_
     */
     void set_box_number();
    /**
     * Mutator for boxColor_
     */
     void set_box_color();
    /**
     * Accessor for boxNumber_
     */
     unsigned int get_box_number();
    /**
     * Accessor for boxColor_
     */
     string get_box_color();
    /**
     * Accessor for prizeCapacity_
     */
     unsigned int prize_capacity();
    /**
     * Accessor for prizeCount_
     */
     unsigned in prize_count(prize);
    /**
     * parameters prize (Prize), return value (bool); place prize in prizes 
     * array if there is space and return true, else return false
     */
     bool addPrize(unsigned int index);
    /**
     * parameters index (unsigned int), return value Prize&; return a Prize if 
     * index is valid, else return scratch (data member declared in class 
     * header)
     */
      Prize* getPrize();
    /**
     * parameters index (unsigned int), return value Prize; remove and return 
     * Prize if index is valid, else return scratch (data member declared in 
     * class header)
     */
      removePrize(unsigned int index);
     
    private:
     unsigned in boxNumber_;
     string boxColor_;
     Prize scratch_;
     Prize* prizes_;
     unsigned int prizeCapacity_;
     unsigned int prizeCount_;
};