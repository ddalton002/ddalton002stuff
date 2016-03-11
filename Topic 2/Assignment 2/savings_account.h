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
     SavingAccount(string account_name = "account", long dollars = 0, 
                    int cents = 0, string last_transaction = "none", double interest_rate = 0.0, 
                    long long interest_accumulated_dollars = 0, 
                    int interest_accumulated_cents = 0, 
                    string interest_accumulated_month = "$0.0", 
                    string interest_accumulated_year = "$0.0");
     virtual ~SavingAccount();
     void SetInterestRate(double interest_rate = 0.0);
     void SetInterestAccumulatedDollars(long accumulated_dollars = 0);
     void SetInterestAccumulatedCents(int accumulated_cents = 0);
     void SetDollarsAccumulatedMonthly(long accumulated_dollars = 0);
     void SetCentsAccumulatedMonthly(int accumulated_cents = 0);
     void SetInterestAccumulatedMonth(long accumulated_dollars = 0, int accumulated_cents = 0);
     void SetInterestAccumulatedYear(long accumulated_dollars = 0, 
                                        int accumulated_cents = 0);
     void CalculateInterest();
     double GetInterestRate();
     long GetInterestAccumulatedDollars();
     int GetInterestAccumulatedCents();
     long GetDollarsAccumulatedMonthly();
     int GetCentsAccumulatedMonthly();
     string GetInterestAccumulatedMonth();
     string GetInterestAccumulatedYear();
    
    private:
     double interest_rate;
     long interest_accumulated_dollars_;
     int interest_accumulated_cents_;
     long dollars_accumulated_monthly_;
     int cents_accumulated_monthly_;
     string interest_accumulated_month;
     string interest_accumulated_year;
};

#endif