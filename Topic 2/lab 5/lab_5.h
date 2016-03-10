/*
 * Name        : lab_5.h
 * Author      : David Dalton
 * Description : Class Template Header File and function definition
 */
 
#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::setfill;
using std::setw;


/*
Define a "header only" template class name Box with:
- one data member -- contents (data type template)
- overloaded constructor -- one parameter newContents to be assigned to contents
- getter (getContents) and setter (setContents)
- friend overloaded operator <<
*/

template<typename Type>
class Box 
{   public:
    /*
     * Constructor
     * @param Type newContents - An initial value to give
     */
     Box(Type newContents);
    /*
     * Accessor
     * @return T - The value of contents_
     */
     Type getContents();
    /*
     * Mutator
     * @param T value - A value to set contents_ to
     */
     void setContents(Type newContents);
    /*
    * Overload of << operator.
    * Outputs the contents to the output stream then retrieves
    * the stream and returns it
    * @param ostream &out - The ostream object to output to
    * @param Box contents - The Box object to output from.
    * @return ostream& - The ostream object to allow for chaining of <<
    */
    friend ostream& operator <<(ostream& out, const Box<Type> &contents) 
    {
        out << contents.contents_;
    return out;
    }
     
    
     
    private:
     Type contents_;
     
    
};

/*
 * Constructor
 * Creates an instance of the class and sets the value of contents_ to the 
 * input value, newContents
 * @param Type newContents - An initial value to give
 */

template<typename Type>
Box<Type>::Box(Type newContents)
{
    contents_ = newContents;
}
/*
 * Accessor
 * retrieves the value of contents_ and returns it
 * @return Type - The value of contents_
 */
template<typename Type>
Type Box<Type>::getContents() 
{
    return contents_;
}
/*
 * Mutator
 * Sets the value of contents_ to the input value, newContents
 * @param Type value - A value to set contents_ to
 */
template<typename Type>
void Box<Type>::setContents(Type newContents) 
{
    contents_ = newContents;
}

/*
 * Function Name: Sum
 * Returns the "sum" of the values in the array.
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @return T - The sum of the values in the array
 */

template<typename Type>
Type Sum(Type input_array[], unsigned int array_size)
{
    Type sum = Type();
    for(int i=0;i<array_size;i++)
    {
        sum += input_array[i];
    }
    return sum;
}


#endif

