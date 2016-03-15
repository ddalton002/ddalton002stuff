/*
 * Name        : bank_account.cpp
 * Author      : David Dalton
 * Description : BankAccount function definition
 * Source      : Luke Sathrum, modified portions of money lab and item lab
 */
 
#include "bank_account.h"
 
/*
 * Constructor, uses default values if none given on creation
 */
BankAccount::BankAccount(string account_name, long dollars, int cents, 
            string last_transaction) 
{
    account_name_ = account_name;
    dollars_ = dollars;
    cents_ = cents;
    SetLastTransaction(0,0, last_transaction);
    ClearRecentTransactions();
}
/*
 * Destructor, unused
 */
BankAccount::~BankAccount() 
{
    
}
/*
 * Mutator
 *sets all values in the recent_transactions array to "none"
 *sets the value of last_transaction to 0, 0 and "none"
 */
void BankAccount::ClearRecentTransactions()
{
    for(int i=0;i<kArray_size_;i++)
    {
    recent_transactions_[i] = "";
    }
    SetLastTransaction(0,0,"none");
}
/*
 * Mutator
 *sets the value of account_name_ to the input string
 */
void BankAccount::SetAccountName(string account_name) 
{
    account_name_ = account_name;
}
/*
 * Mutator
 *sets the value of dollars_ to the input long value
 */
void BankAccount::SetDollars(long dollars) 
{
    dollars_ = dollars;
}
/*
 * Mutator
 *sets the value of _cents to the input int value
 */
void BankAccount::SetCents(int cents) 
{
    cents_ = cents;
}
/*
 * Mutator
 *sets the value of of last_transaction to the input long, int and string
 *values
 */
void BankAccount::SetLastTransaction(long transaction_dollars, 
                                    int transaction_cents, 
                                    string last_transaction) 
{
    stringstream transaction;
    transaction << "$" << transaction_dollars << "." << transaction_cents 
                        << ". Transaction type: " << last_transaction;
    last_transaction_ = transaction.str();
}
/*
 * Mutator
 *sets the recent_transaction array at a designated location to the input
 *long, int and string value
 */
void BankAccount::SetRecentTransactions(long transaction_dollars, 
                            int transaction_cents, string transaction) 
{
    /*
     *creates a storage array to store the current values of recent_transaction
     *in an offset pattern, so that index 0 is empty, index 1 is the value of
     *index 0 in the original array, and the value that was at index 9 in the 
     *original array is dropped.  It then stores the new transaction value
     *into index 0 of the original array, and sets the rest of the array
     *equal to its matching index value of the storage array
     */
    string storage_array[kArray_size_];
    stringstream transaction_record;
    int transaction_length = (kArray_size_ - 1);
    for(int i = 0; i<transaction_length; i++)
    {
        storage_array[(i+1)] = recent_transactions_[i];
    }
    transaction_record << "$" << transaction_dollars << "." << transaction_cents 
                        << ". Transaction type: " << transaction;
    storage_array[0] = transaction_record.str();
    for(int i = 0;i<kArray_size_;i++)
    {
        recent_transactions_[i] = storage_array[i];
    }
}
/*
 * Mutator
 *adds the input long to the current value of dollars_ and the input int
 *to the current value of the input int then stores the new values back
 *into the dollars_ and cents_
 */
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
    /* Sets the variables to the new values, and adds them to the transaction
     * record variable
     */
    SetDollars(final_dollars);
    SetCents(final_cents);
    SetLastTransaction(dollars, cents, "Deposit");
    SetRecentTransactions(dollars, cents, "Deposit");
    
}
/*
 * Mutator
 *subtracts the value of the input long from dollars_ and subtracts the 
 *value of the input int from cents_ then stores the updated values back
 *into dollars_ and cents_
 */
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
    /* Sets the variables to the new values, and adds them to the transaction
     * record variable
     */
    SetDollars(final_dollars);
    SetCents(final_cents);
    SetLastTransaction(dollars, cents, "Withdrawl");
    SetRecentTransactions(dollars, cents, "Withdrawl");
}
/*
 * Accessor
 *gets the value of account_name_ and returns it
 */
string BankAccount::GetAccountName() 
{
    return account_name_;
}
/*
 * Accessor
 *gets the value of dollars_ and returns it
 */
long BankAccount::GetDollars() 
{
    return dollars_;
}
/*
 * Accessor
 *gets the value of cents_ and returns it
 */
int BankAccount::GetCents() 
{
    return cents_;
}
/*
 * Accessor
 *gets the value of last_transaction_ and returns it
 */
string BankAccount::GetLastTransaction() 
{
    return last_transaction_;
}
/*
 * Accessor
 *gets the value of recent_transaction_ and the specified index and 
 *returns it
 */
string BankAccount::GetRecentTransactions(int transaction_id) 
{
    return recent_transactions_[transaction_id];
}
/*
 * Accessor
 *combines the value of dollars_ and cents_ into a string stream with
 *specified characters then returns the string
 */
string BankAccount::ShowBalance() 
{
    /*
    *Gets the absolute value of the objects cents value and stores it into a 
    *variable.  It then gets the value of the objects dollars_ and cents_
    *variables and checks to see if they are equal to and less than 0.  If
    *they are then they send them to an output stream with a negative character
    *otherwise it sends it to the output stream without the negative character.
    *Adds the values of dollars and cents to the output stream separated by a 
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