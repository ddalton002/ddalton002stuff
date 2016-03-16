/*
 * Name        : checking_account.h
 * Author      : David Dalton
 * Description : Checking Account class header file
 */
 
#ifndef CHECK_H
#define CHECK_H

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

class CheckingAccount : public BankAccount
{
    public:
    /*
     * Constructor
     *uses default values if none given
     */
     CheckingAccount(string account_name = "account", long dollars = 0, 
                     int cents = 0, string last_transaction = "none", 
                     string amount_kept = "$0.0");
     /*
      * Destructor 
      *unused
      */
     virtual ~CheckingAccount();
     /*
      * Mutator
      *sets the values of ammount kept to the input long and int
      */
     void SetAmountKept(long kept_dollars = 0, int kept_cents = 0);
     /*
      * Mutator
      *deducts the input long and int from the current value of dollars_ and
      *cents_, then stores the deducted values and the inputed check_number
      *into the transaction record variable
      */
     void WriteCheck(int check_number = 0, long check_dollars = 0, 
                        int check_cents = 0);
     /*
      * Mutator
      *adds the specified deposit amounts to the values of dollars_ and cents_
      *and then adds the values to the transaction record variable
      */
     void CashCheck(long check_dollars = 0, int check_cents = 0, 
                        long check_dollars_deposited = 0,
                        int check_cents_deposited = 0);
     /*
      * Accessor
      *gets the value of ammount_kept and returns it
      */
     string GetAmountedKept();
    
    private:
     string amount_kept_;
};

#endif