/*
 * Name        : money.cpp
 * Author      : David Dalton
 * Description : 
 */
 
#include "money.h"
using std::cout;
using std::endl;


/*
 * Constructor #1.
 * Sets dollars and cents to the supplied values. Defaults to 0
 * @param int dollars - The value to set dollars_ to
 * @param int cents - The value to set cents_ to
 */
/*
Money(int dollars, int cents)

/*
 * Overload of + operator. This is a friend function.
 * @param Money amount1 - The first object to add
 * @param Money amount2 - The second object to add
 * @return Money - The two objects added together
 *
friend const Money operator +(const Money& amount1, const Money& amount2)
*/

// The Constructor, Accessors and Mutators have been defined for you
Money::Money(int dollars, int cents)
      : dollars_(dollars),
        cents_(cents) {
}

int Money::dollars() const {
    return dollars_;
}

int Money::cents() const {
    return cents_;
}

void Money::set_dollars(int dollars) {
  dollars_ = dollars;
}

void Money::set_cents(int cents) {
  cents_ = cents;
}

// This function definition provided as an example and is FULLY COMPLETE
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

// REST OF CLASS FUNCTION DEFINITIONS GO HERE

/*
 * Overload of binary - operator. This is a friend function.
 * @param Money amount1 - The object to subtract from
 * @param Money amount2 - The object to be subtracted
 * @return Money - The result of the subtraction
 */

const Money operator -(const Money& amount1, const Money& amount2) 
{
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  //Subtracts object 2 all cents from object 1 all cents
  int sum_all_cents = all_cents1 - all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) 
  {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

/*
 * Overload of == operator. This is a friend function.
 * @param Money amount1 - The first object to compare
 * @param Money amount2 - The second object to compare
 * @return bool - True if the objects have the same values, otherwise false
 */
bool operator ==(const Money &amount1, const Money &amount2)
{
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Compares the two values.  If they are equal returns true, otherwise
  // returns false
  if(all_cents1 == all_cents2)
  {
    return true;
  } else
  {
  return false;
  }
}

/*
 * Overload of unary - operator. This is a friend function.
 * @param Money amount - The object to negate
 * @return Money - The result of the negation of the two member variables
 */
const Money operator -(const Money &amount)
{
  //Gets the dollars and cents of an object and makes them negative
  return Money(-amount.dollars_, -amount.cents_);
}

/*
 * Overload of << operator.
 * Outputs the money values to the output stream.
 * Should be in the form $x.xx
 * @uses setw()
 * @uses setfill()
 * @param ostream &out - The ostream object to output to
 * @param Money amount - The Money object to output from.
 * @return ostream& - The ostream object to allow for chaining of <<
 */
ostream& operator <<(ostream &out, const Money &amount)
{
  int absolute_cents = abs(amount.cents_);
  if ((amount.dollars_ == 0) && (amount.cents_ < 0))
  {
    out << "$-" << setw(1) << setfill('0') << amount.dollars_ << '.' 
      << setfill('0') << setw(2) << absolute_cents;
  } else
  {
  out << '$' << setw(1) << setfill('0') << amount.dollars_ << '.' 
      << setfill('0') << setw(2) << absolute_cents;
  }
  return out;
}