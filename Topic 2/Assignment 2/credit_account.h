/*
 * Name        : credit_account.h
 * Author      : David Dalton
 * Description : Credit Account class header file
 */
 
#ifndef CREDIT_H
#define CREDIT_H

#include "bank_account.h"
#include "savings_account.h"

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

class CreditAccount : public BankAccount
{
    public:
    /*
     * Constructor
     *uses default values if none given
     */
     CreditAccount(string account_name = "account", long dollars = 0, 
                    int cents = 0, double interest_rate = 0.0,
                    long max_balance_dollars = 0, 
                    int max_balance_cents = 0,
                    string last_transaction = "none",
                    string interest_accumulated_month = "$0.0", 
                    string interest_accumulated_year = "$0.0");
     /*
      * Destructor 
      *unused
      */
     virtual ~CreditAccount();
     /*
      * Mutator
      *
      */
     void SetInterestRate(double = 0.0);
     /*
      * Mutator
      *
      */
     void SetMaxBalanceDollars(long max_balance_dollars);
     /*
      * Mutator
      *
      */
     void SetMaxBalanceCents(int max_balance_cents);
     /*
      * Mutator
      *
      */
     void SetInterestAccumulatedMonth(long accumulated_dollars = 0, 
                                        int accumulated_cents = 0);
     /*
      * Mutator
      *
      */
     void SetInterestAccumulatedYear(long accumulated_dollars = 0, 
                                        int accumulated_cents = 0);
     /*
      * Mutator
      *
      */
     void MakePayment(long payment_dollars = 0, int payment_cents = 0);
     /*
      * Mutator
      *
      */
     void ChargeCard(long transaction_number = 0, long charge_dollars = 0, 
                        int charge_cents = 0);
     /*
      * Mutator
      *
      */
     void CalculateInterest();
     /*
      * Accessor
      *
      */
     double GetInterestRate();
     /*
      * Accessor
      *
      */
     long GetMaxBalanceDollars();
     /*
      * Accessor
      *
      */
     int GetMaxBalanceCents();
     /*
      * Accessor
      *calls the GetMaxBalanceDollars() and GetMaxBalanceCents() functions to get
      *the values of their variables.  It then stores the values of those variables
      *and sends them to a stringstream along with default characters.  It then
      *returns the string
      */
     string GetMaxBalance();
     /*
      * Accessor
      *
      */
     string GetInterestAccumulatedMonth();
     /*
      * Accessor
      *
      */
     string GetInterestAccumulatedYear();
    
    
    private:
     double interest_rate_;
     long max_balance_dollars_;
     int max_balance_cents_;
     string interest_accumulated_month_;
     string interest_accumulated_year_;
};

#endif