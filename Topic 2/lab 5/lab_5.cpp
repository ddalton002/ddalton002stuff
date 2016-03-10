//NOT USED FOR LAB IN FINAL VERSION!!!

/*
 * Name        : lab_5.cpp
 * Author      : David Dalton
 * Description : A template program
 */
 
#include "lab_5.h"
 
/*
 * Constructor
 * @param Type newContents - An initial value to give
 */
template<typename Type>
Box<Type>::Box(Type newContents)
{
    contents_ = newContents;
}
/*
 * Accessor
 * @return Type - The value of contents_
 */
template<typename Type>
Type Box<Type>::getContents() 
{
    return contents_;
}
/*
 * Mutator
 * @param Type value - A value to set contents_ to
 */
template<typename Type>
void Box<Type>::setContents(Type newContents) 
{
    contents_ = newContents;
}
/*
* Overload of << operator.
* Outputs the contents to the output stream
* @param ostream &out - The ostream object to output to
* @param Box contents - The Box object to output from.
* @return ostream& - The ostream object to allow for chaining of <<


template<typename Type>
ostream& operator <<(ostream &out, Box<Type> &contents) 
{
    out << contents.contents_;
    return out;
}
*/
/*
Create a template function

 * Function Name: Sum
 * Return the "sum" of the values in the array. Your initial sum 	should be set
 * to "zero" in your algorithm. To do this use T().
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @return T - The sum of the values in the array
 */


