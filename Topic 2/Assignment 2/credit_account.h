/*
 * Name        : credit_account.h
 * Author      : David Dalton
 * Description : Credit Account class header file
 */
 
#ifndef CREDIT_H
#define CREDIT_H

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

class CreditAccount : public BankAccount
{
    public:
     CreditAccount(string account_name = "account", long dollars = 0, 
                    int cents = 0, double interest_rate = 0.0,string last_transaction = "none",
                    long max_balance_dollars = 0, 
                    int max_balance_cents = 0,
                    long interest_accumulated_dollars = 0, 
                    int interest_accumulated_cents = 0, 
                    string interest_accumulated_month = "$0.0", 
                    string interest_accumulated_year = "$0.0");
     virtual ~CreditAccount();
     void SetInterestRate(double = 0.0);
     void SetInterestAccumulatedMonth(long accumulated_dollars = 0, 
                                        int accumulated_cents = 0);
     void SetInterestAccumulatedYear(long accumulated_dollars = 0, 
                                        int accumulated_cents = 0);
     void MakePayment(long payment_dollars = 0, int payment_cents = 0);
     void CalculateInterest();
     double GetInterestRate();
     bool ChargeCard(long transaction_number = 0, long charge_dollars = 0, 
                        int charge_cents = 0);
     string GetInterestAccumulatedMonth();
     string GetInterestAccumulatedYear();
    
    
    private:
     double interest_rate;
     long max_balance_dollars_;
     int max_balance_cents_;
     long interest_accumulated_dollars_;
     int interest_accumulated_cents_;
     string interest_accumulated_month;
     string interest_accumulated_year;
};

#endif