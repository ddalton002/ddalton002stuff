/*
 * Name        : savings_account.cpp
 * Author      : David Dalton
 * Description : SavingsAccount function definition
 * Source      : Luke Sathrum, lines x to y
 */
 
#include "savings_account.h"

SavingAccount::SavingAccount(string account_name, long dollars, 
                    int cents, double interest_rate, string last_transaction, 
                    string interest_accumulated_month, 
                    string interest_accumulated_year) 
{
    BankAccount::SetAccountName(account_name);
    BankAccount::SetDollars(dollars);
    BankAccount::SetCents(cents) ;
    BankAccount::SetLastTransaction(0, 0, last_transaction);
    BankAccount::ClearRecentTransactions();
    SetInterestRate(interest_rate);
}
SavingAccount::~SavingAccount() 
{
    
}
void SavingAccount::SetInterestRate(double interest_rate) 
{
    if(interest_rate < 0)
    {
        interest_rate = 0;
        interest_rate_ = interest_rate;
    } else 
    {
        interest_rate_ = interest_rate;
    }
}
void SavingAccount::SetInterestAccumulatedMonth(long accumulated_dollars, 
                                        int accumulated_cents) 
{
    stringstream interest;
    int string_length = interest_accumulated_month_.length();
    for(int i=0;i<string_length;i++)
    {
        if(interest_accumulated_month_[i] != ('$' || '-'))
        {
          interest << interest_accumulated_month_[i];  
        } 
    }
    //string interest_string = interest.str();
    double current_interest = stoi(interest.str());
    long current_dollars = current_interest;
    int current_cents = ((current_interest - current_dollars) *100);
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
    int string_length = interest_accumulated_year_.length();
    for(int i=0;i<string_length;i++)
    {
        if(interest_accumulated_year_[i] != ('$' || '-'))
        {
          interest << interest_accumulated_year_[i];  
        } 
    }
    double current_interest = stoi(interest.str());
    long current_dollars = current_interest;
    int current_cents = ((current_interest - current_dollars) *100);
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
    int string_month_length = interest_accumulated_month_.length();
    for(int i=0;i<string_month_length;i++)
    {
        if(interest_accumulated_month_[i] != ('$' || '-'))
        {
          interest_month << interest_accumulated_month_[i];  
        } 
    }
    double monthly_interest = stoi(interest_month.str());
    long monthly_dollars = monthly_interest;
    int monthly_cents = ((monthly_interest - monthly_dollars) *100);
    
    stringstream interest_year;
    int string_year_length = interest_accumulated_year_.length();
    for(int i=0;i<string_year_length;i++)
    {
        if(interest_accumulated_year_[i] != ('$' || '-'))
        {
          interest_year << interest_accumulated_year_[i];  
        } 
    }
    double yearly_interest = stoi(interest_year.str());
    long yearly_dollars = yearly_interest;
    int yearly_cents = ((yearly_interest - yearly_dollars) * 100);
    
    // Get all the cents of object 1
    long all_cents1 = monthly_cents + monthly_dollars * 100;
    // Get all the cents of object 2
    long all_cents2 = yearly_cents + yearly_dollars * 100;
    // Add all the cents together
    long sum_all_cents = all_cents1 + all_cents2;
    // Handle the fact that money can be negative
    long abs_all_cents = abs(sum_all_cents);
    long final_dollars = abs_all_cents / 100;
    int final_cents = abs_all_cents % 100;
    // If the result of the operation was negative, negate final dollars and cents
    if (sum_all_cents < 0) {
      final_dollars = -final_dollars;
      final_cents = -final_cents;
    }
    SetInterestAccumulatedYear(final_dollars, final_cents);
    
    double current_balance = (dollars + (cents / 100));
    double updated_balance = current_balance + (current_balance * interest_rate);
    double gained_balance = updated_balance - current_balance;
    long updated_balance_dollars = updated_balance;
    int updated_balance_cents = ((updated_balance  - updated_balance_dollars) * 100);
    long gained_balance_dollars = gained_balance;
    int gained_balance_cents = ((gained_balance  - gained_balance_dollars) * 100);
    BankAccount::SetDollars(updated_balance_dollars);
    BankAccount::SetCents(updated_balance_cents);
    SetInterestAccumulatedMonth(gained_balance_dollars, gained_balance_cents);
    
}
double SavingAccount::GetInterestRate() 
{
    return interest_rate_;
}
string SavingAccount::GetInterestAccumulatedMonth() 
{
    return interest_accumulated_month_;
}
string SavingAccount::GetInterestAccumulatedYear() 
{
    return interest_accumulated_year_;
}