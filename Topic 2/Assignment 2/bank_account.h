/*
 * Name        : bank_account.h
 * Author      : David Dalton
 * Description : Bank Account class header file
 */
 
#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::stringstream;
using std::setfill;
using std::setw;
using std::setprecision;
using std::fixed;

class BankAccount
{
    public:
    /*
     * Constructor, uses default values if none given on creation
     */
     BankAccount(string account_name = "account", long dollars = 0, 
                    int cents = 0, string last_transaction = "none");
     /*
      * Destructor
      *unused
      */
     virtual ~BankAccount();
     /*
      * Mutator
      *sets all values in the recent_transactions array to "none"
      *sets the value of last_transaction to 0, 0 and "none"
      */
     void ClearRecentTransactions();
     /*
      * Mutator
      *sets the value of account_name_ to the input string
      */
     void SetAccountName(string account_name);
     /*
      * Mutator
      *sets the value of dollars_ to the input long value
      */
     void SetDollars(long dollars);
     /*
      * Mutator
      *sets the value of _cents to the input int value
      */
     void SetCents(int cents);
     /*
      * Mutator
      *sets the value of of last_transaction to the input long, int and string
      *values
      */
     void SetLastTransaction(long transaction_dollars, 
                                    int transaction_cents, 
                                    string last_transaction);
     /*
      * Mutator
      *sets the recent_transaction array at a designated location to the input
      *long, int and string value
      */
     void SetRecentTransactions(long transaction_dollars = 0, 
                                int transaction_cents = 0, 
                                string transaction = "");
     /*
      * Mutator
      *adds the input long to the current value of dollars_ and the input int
      *to the current value of the input int then stores the new values back
      *into the dollars_ and cents_
      */
     void DepositAccount(long dollars = 0, int cents = 0);
     /*
      * Mutator
      *subtracts the value of the input long from dollars_ and subtracts the 
      *value of the input int from cents_ then stores the updated values back
      *into dollars_ and cents_
      */
     void WithdrawAccount(long dollars = 0, int cents = 0);
     /*
      * Accessor
      *gets the value of account_name_ and returns it
      */
     string GetAccountName();
     /*
      * Accessor
      *gets the value of dollars_ and returns it
      */
     long GetDollars();
     /*
      * Accessor
      *gets the value of cents_ and returns it
      */
     int GetCents();
     /*
      * Accessor
      *gets the value of last_transaction_ and returns it
      */
     string GetLastTransaction();
     /*
      * Accessor
      *gets the value of recent_transaction_ and the specified index and 
      *returns it
      */
     string GetRecentTransactions(int transaction_id = 0);
     /*
      * Accessor
      *combines the value of dollars_ and cents_ into a string stream with
      *specified characters then returns the string
      */
     string ShowBalance();
    
    private:
     const int kArray_size_ = 10;
     string account_name_;
     long dollars_;
     int cents_;
     string last_transaction_;
     string recent_transactions_[10];
};

#endif