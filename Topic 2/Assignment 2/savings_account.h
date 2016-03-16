/*
 * Name        : savings_account.h
 * Author      : David Dalton
 * Description : Savings Account class header file
 */
 
#ifndef SAVE_H
#define SAVE_H

#include "bank_account.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::setfill;
using std::setw;
using std::setprecision;
using std::fixed;

class SavingAccount : public BankAccount
{
    public:
    /*
     * Constructor
     *uses default values if none given
     */
     SavingAccount(string account_name = "account", long dollars = 0, 
                    int cents = 0, double interest_rate = 0.0, 
                    string last_transaction = "none",
                    string interest_accumulated_month = "$0.0", 
                    string interest_accumulated_year = "$0.0");
     /*
      * Destructor 
      *unused
      */
     virtual ~SavingAccount();
     /*
      * Mutator
      *sets the value of interest_rate_ to the input double
      */
     void SetInterestRate(double interest_rate = 0.0);
     /*
      * Mutator
      *uses stringstream to set the value of interest_accumulated_month_ to the
      *input values, separated by a decimal
      */
     void SetInterestAccumulatedMonth(long accumulated_dollars = 0, 
                                      int accumulated_cents = 0);
     /*
      * Mutator
      *uses stringstream to set the value of interest_accumulated_year_ to the
      *input values, separated by a decimal
      */
     void SetInterestAccumulatedYear(long accumulated_dollars = 0, 
                                        int accumulated_cents = 0);
     /*
      * Mutator
      *gets the interest rate and current value of dollars_ and cents_ and then
      *calculates the amount of interest based off of the interest rate.  Then
      *adds the amount accruded by interest and adds it to the values of
      *dollars_W and cents_
      */
     void CalculateInterest();
     /*
      * Accessor
      *gets the value of interest_rate_ and returns it
      */
     double GetInterestRate();
     /*
      * Accessor
      *gets the value of interest_accumulated_month_ and returns it
      */
     string GetInterestAccumulatedMonth();
     /*
      * Accessor
      *gets the value of interest_accumulated_year_ and returns it
      */
     string GetInterestAccumulatedYear();
    
    private:
     double interest_rate_;
     string interest_accumulated_month_;
     string interest_accumulated_year_;
};

#endif