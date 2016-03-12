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
     BankAccount(string account_name = "account", long dollars = 0, 
                    int cents = 0, string last_transaction = "none");
     virtual ~BankAccount();
     void ClearRecentTransactions();
     void SetAccountName(string account_name);
     void SetDollars(long dollars);
     void SetCents(int cents);
     void SetLastTransaction(long transaction_dollars, 
                                    int transaction_cents, 
                                    string last_transaction);
     void SetRecentTransactions(long transaction_dollars = 0, 
                                int transaction_cents = 0, 
                                string transaction = "");
     void DepositAccount(long dollars = 0, int cents = 0);
     void WithdrawAccount(long dollars = 0, int cents = 0);
     string GetAccountName();
     long GetDollars();
     int GetCents();
     string GetLastTransaction();
     string GetRecentTransactions(int transaction_id = 0);
     string ShowBalance();
    
    private:
     const int kArray_size_ = 10;
     string account_name_;
     long dollars_;
     int cents_;
     string last_transaction_;
     string recent_transactions_[];
};

#endif