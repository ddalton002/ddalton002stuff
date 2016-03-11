/*
 * Name        : credit_account.cpp
 * Author      : David Dalton
 * Description : CreditAccount function definition
 * Source      : Luke Sathrum, lines x to y
 */
 
#include "credit_account.h"

CreditAccount::CreditAccount(string account_name, long dollars, 
                    int cents, double interest_rate,string last_transaction,
                    long max_balance_dollars, 
                    int max_balance_cents,
                    long interest_accumulated_dollars, 
                    int interest_accumulated_cents, 
                    string interest_accumulated_month, 
                    string interest_accumulated_year) 
{
    BankAccount::SetAccountName(account_name);
    BankAccount::SetDollars(dollars);
    BankAccount::SetCents(cents) ;
    BankAccount::SetLastTransaction(0, 0, last_transaction);
    BankAccount::ClearRecentTransactions();
    max_balance_dollars_ = max_balance_dollars;
    max_balance_cents_ = max_balance_cents;
    interest_rate_ = interest_rate;
    interest_accumulated_dollars_ = interest_accumulated_dollars;
    interest_accumulated_cents_ = interest_accumulated_cents;
    interest_accumulated_month_= interest_accumulated_month;
    interest_accumulated_year_ = interest_accumulated_year;
}
CreditAccount::~CreditAccount() 
{
    
}
void CreditAccount::SetInterestRate(double;
void CreditAccount::SetInterestAccumulatedMonth(long accumulated_dollars =, 
                                        int accumulated_cents) 
{
    
}
void CreditAccount::SetInterestAccumulatedYear(long accumulated_dollars, 
                                        int accumulated_cents) 
{
    
}
void CreditAccount::MakePayment(long payment_dollars, int payment_cents) 
{
    
}
void CreditAccount::CalculateInterest() 
{
    
}
double CreditAccount::GetInterestRate() 
{
    
}
bool CreditAccount::ChargeCard(long transaction_number, long charge_dollars, 
                        int charge_cents) 
{
    
}
string CreditAccount::GetInterestAccumulatedMonth() 
{
    
}
string CreditAccount::GetInterestAccumulatedYear() 
{
    
}
    
    
    private:
     double interest_rate;
     long max_balance_dollars_;
     int max_balance_cents_;
     long interest_accumulated_dollars_;
     int interest_accumulated_cents_;
     string interest_accumulated_month;
     string interest_accumulated_year;