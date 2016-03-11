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
     CheckingAccount(string account_name = "account", long dollars = 0, int cents = 0, 
                     string last_transaction = "none", string amount_cashed = "$0.0",
                     string amount_kept = "$0.0", 
                     string amount_deposited = "$0.0");
     virtual ~CheckingAccount();
     void SetAmmountCashed(long cashed_dollars = 0, int cashed_cents = 0);
     void SetAmmountKept(long kept_dollars = 0, int kept_cents = 0);
     void SetAmmountDeposited(long deposited_dollars = 0, 
                              int deposited_cents = 0);
     void WriteCheck(int check_number = 0, long check_dollars = 0, 
                        int check_cents = 0);
     string GetAmountedCashed();
     string GetAmountedKept();
     string GetAmountDeposited();
     string CashCheck(long check_dollars = 0, int check_cents = 0, 
                        long check_dollars_deposited = 0,
                        int check_cents_deposited = 0);
    
    private:
     string amount_cashed_;
     string amount_kept_;
     string amount_deposited_;
};

#endif