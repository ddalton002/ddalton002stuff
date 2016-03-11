/*
 * Name        : bank_account.cpp
 * Author      : David Dalton
 * Description : BankAccount function definition
 * Source      : Luke Sathrum, lines x to y
 */
 
#include "bank_account.h"
 
BankAccount::BankAccount(string account_name, long dollars, int cents, 
            string last_transaction) 
{
    account_name_ = account_name;
    dollars_ = dollars;
    cents_ = cents;
    //last_transaction_ = last_transaction;
    SetLastTransaction(0,0, last_transaction);
    ClearRecentTransactions();
}
BankAccount::~BankAccount() 
{
    
}
void BankAccount::ClearRecentTransactions()
{
    for(int i=0;i<kArray_size_;i++)
    {
    recent_transactions_[i] = "";
    }
}
void BankAccount::SetAccountName(string account_name) 
{
    account_name_ = account_name;
}
void BankAccount::SetDollars(long dollars) 
{
    dollars_ = dollars;
}
void BankAccount::SetCents(int cents) 
{
    cents_ = cents;
}
void BankAccount::SetLastTransaction(long transaction_dollars, 
                                    int transaction_cents, 
                                    string last_transaction) 
{
    stringstream transaction;
    transaction << "$" << transaction_dollars << transaction_cents 
                        << ". Transaction type: " << transaction;
    last_transaction_ = transaction.str();
}
void BankAccount::SetRecentTransactions(long transaction_dollars, 
                            int transaction_cents, string transaction) 
{
    string storage_array[kArray_size_];
    stringstream transaction_record;
    int transaction_length = (kArray_size_ - 1);
    for(int i = 0; i<transaction_length; i++)
    {
        storage_array[(i+1)] = recent_transactions_[i];
    }
    transaction_record << "$" << transaction_dollars << transaction_cents 
                        << ". Transaction type: " << transaction;
    storage_array[0] = transaction_record.str();
    for(int i = 0;i<kArray_size_;i++)
    {
        recent_transactions_[i] = storage_array[i];
    }
    
}
void BankAccount::DepositAccount(long dollars, int cents) 
{
    long current_dollars = GetDollars();
    int current_cents = GetCents();
    // Get all the cents of current balance
    long all_cents1 = current_cents + current_dollars * 100;
    // Get all the cents of deposited amount
    long all_cents2 = cents + dollars * 100;
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
    SetDollars(final_dollars);
    SetCents(final_cents);
    SetLastTransaction(final_dollars, final_cents, "Deposit");
    SetRecentTransactions(final_dollars, final_cents, "Deposit");
    
}
void BankAccount::WithdrawAccount(long dollars, int cents) 
{
    long current_dollars = GetDollars();
    int current_cents = GetCents();
    // Get all the cents of current balance
    long all_cents1 = current_cents + current_dollars * 100;
    // Get all the cents of withdrawn amount
    long all_cents2 = cents + dollars * 100;
    //Subtracts object 2 all cents from object 1 all cents
    long sum_all_cents = all_cents1 - all_cents2;
    // Handle the fact that money can be negative
    long abs_all_cents = abs(sum_all_cents);
    long final_dollars = abs_all_cents / 100;
    int final_cents = abs_all_cents % 100;
    // If the result of the operation was negative, negate final dollars and cents
    if (sum_all_cents < 0) 
    {
      final_dollars = -final_dollars;
      final_cents = -final_cents;
    }
    SetDollars(final_dollars);
    SetCents(final_cents);
    SetLastTransaction(final_dollars, final_cents, "Withdrawl");
    SetRecentTransactions(final_dollars, final_cents, "Withdrawl");
}
string BankAccount::GetAccountName() 
{
    return account_name_;
}
long BankAccount::GetDollars() 
{
    return dollars_;
}
int BankAccount::GetCents() 
{
    return cents_;
}
string BankAccount::GetLastTransaction() 
{
    return last_transaction_;
}
string BankAccount::GetRecentTransactions() 
{
    return recent_transactions_[];
}
string BankAccount::ShowBalance() 
{
    /*
    *Gets the absolute value of the objects cents value and stores it into a 
    *variable.  It then gets the value of the objects dollars_ and cents_
    *variables and checks to see if they are equal to and less than 0.  If
    *they are then they send them to an output stream with a negative character
    *otherwise it sends it to the output stream without the negative character
    *then returns the output stream
    */
    stringstream balance;
    long dollars = GetDollars();
    int cents = GetCents();
    int absolute_cents = abs(cents);
    if((dollars == 0) && (cents < 0))
    {
      balance << "Your balance is: $-" << setw(1) << setfill('0') << dollars<< "." 
        << setfill('0') << setw(2) << absolute_cents;
    } else
    {
      balance << "Your balance is: $" << setw(1) << setfill('0') << dollars << "." 
        << setfill('0') << setw(2) << cents;
    }
    return balance.str();
}