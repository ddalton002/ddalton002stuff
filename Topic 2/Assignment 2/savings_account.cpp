/*
 * Name        : savings_account.cpp
 * Author      : David Dalton
 * Description : SavingsAccount function definition
 * Source      : Luke Sathrum, lines x to y
 */
 
#include "savings_account.h"

SavingAccount::SavingAccount(string account_name, long dollars, 
                    int cents, string last_transaction, double interest_rate, 
                    long long interest_accumulated_dollars, 
                    int interest_accumulated_cents, 
                    string interest_accumulated_month, 
                    string interest_accumulated_year) 
{
    BankAccount::SetAccountName(account_name);
    BankAccount::SetDollars(dollars);
    BankAccount::SetCents(cents) ;
    BankAccount::SetLastTransaction(0, 0, last_transaction);
    BankAccount::ClearRecentTransactions();
    interest_rate_ = interest_rate;
    interest_accumulated_dollars_ = interest_accumulated_dollars;
    interest_accumulated_cents_ = interest_accumulated_cents;
    interest_accumulated_month_ = interest_accumulated_month;
    interest_accumulated_years_ = interest_accumulated_years;
}
SavingAccount::~SavingAccount() 
{
    
}
void SavingAccount::SetInterestRate(double interest_rate) 
{
    interest_rate_ = interest_rate;
}
void SetInterestAccumulatedDollars(long accumulated_dollars) 
{
    interest_accumulated_dollars_ = accumulated_dollars;
}
void SetInterestAccumulatedCents(int accumulated_cents) 
{
    interest_accumulated_cents_ = accumulated_cents;
}
void SetDollarsAccumulatedMonthly(long accumulated_dollars) 
{
    dollars_accumulated_monthly_ = accumulated_dollars;
}
void SetCentsAccumulatedMonthly(int accumulated_cents) 
{
    cents_accumulated_monthly_ = accumulated_cents;
}
void SavingAccount::SetInterestAccumulatedMonth(long accumulated_dollars, 
                                        int accumulated_cents) 
{
    stringstream interest;
    for(int i=0;i<interest_accumulated_month_.length();i++)
    {
        if(interest_accumulated_month_[i] != ('$' || '-'))
        {
          interest << interest_accumulated_month_[i];  
        } 
    }
    double current_interest = atol(interest.str());
    long current_dollars = total_interest;
    int current_cents = ((total_interest - whole) *100);
    accumulated_dollars = accumulated_dollars + current_dollars;
    accumulated_cents = accumulated_cents + current_cents;
    interest << '$' << setw(1) << setfill('0') << accumulated_dollars << "." 
      << setfill('0') << setw(2) << accumulated_cents;
    interest_accumulated_month_ = interest.str();
}
void SavingAccount::SetInterestAccumulatedYear(long accumulated_dollars, 
                                        int accumulated_cents) 
{
    stringstream interest;
    for(int i=0;i<interest_accumulated_year_.length();i++)
    {
        if(interest_accumulated_year_[i] != ('$' || '-'))
        {
          interest << interest_accumulated_year_[i];  
        } 
    }
    double current_interest = atol(interest.str());
    long current_dollars = total_interest;
    int current_cents = ((total_interest - whole) *100);
    accumulated_dollars = accumulated_dollars + current_dollars;
    accumulated_cents = accumulated_cents + current_cents;
    interest << '$' << setw(1) << setfill('0') << accumulated_dollars << "." 
      << setfill('0') << setw(2) << accumulated_cents;
    interest_accumulated_year_ = interest.str();
}
void SavingAccount::CalculateInterest() 
{
    long dollars = BankAccount::GetDollars();
    int cents = BankAccount::GetCents();
    double interest_rate = GetInterestRate();
    string interest_month_generated = GetInterestAccumulatedMonth();
    string interest_year_generated = GetInterestAccumulatedYear();
    
    stringstream interest_month;
    for(int i=0;i<interest_accumulated_month_.length();i++)
    {
        if(interest_accumulated_month_[i] != ('$' || '-'))
        {
          interest_month << interest_accumulated_month_[i];  
        } 
    }
    double monthly_interest = atol(interest_month.str());
    long monthly_dollars = total_interest;
    int monthly_cents = ((total_interest - whole) *100);
    
    stringstream interest_year;
    for(int i=0;i<interest_accumulated_year_.length();i++)
    {
        if(interest_accumulated_year_[i] != ('$' || '-'))
        {
          interest_year << interest_accumulated_year_[i];  
        } 
    }
    double yearly_interest = atol(interest_yearstr());
    long yearly_dollars = total_interest;
    int yearly_cents = ((total_interest - whole) *100);
    
    
}
double SavingAccount::GetInterestRate() 
{
    return interest_rate_;
}
long GetInterestAccumulatedDollars() 
{
    return interest_accumulated_dollars_;
}
int GetInterestAccumulatedCents() 
{
    return interest_accumulated_cents_;
}
long GetDollarsAccumulatedMonthly() 
{
    return dollars_accumulated_monthly_;
}
int GetCentsAccumulatedMonthly() 
{
    return cents_accumulated_monthly_;
}
string SavingAccount::GetInterestAccumulatedMonth() 
{
    return interest_accumulated_month_;
}
string SavingAccount::GetInterestAccumulatedYear() 
{
    return interest_accumulated_year_;
}
    
    private:
     double interest_rate_;
     long interest_accumulated_dollars_;
     int interest_accumulated_cents_;
     long dollars_accumulated_monthly_;
     int dollars_accumulated_monthly_;
     string interest_accumulated_month_;
     string interest_accumulated_year_;