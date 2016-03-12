/*
 * Name        : checking_account.cpp
 * Author      : David Dalton
 * Description : CheckingAccount function definition
 * Source      : Luke Sathrum, lines x to y
 */
 
#include "checking_account.h"

CheckingAccount::CheckingAccount(string account_name ,long dollars, int cents, 
                                string last_transaction, string amount_cashed,
                                string amount_kept, string amount_deposited) 
{
    BankAccount::SetAccountName(account_name);
    BankAccount::SetDollars(dollars);
    BankAccount::SetCents(cents) ;
    BankAccount::SetLastTransaction(0, 0, last_transaction);
    BankAccount::ClearRecentTransactions();
    amount_cashed_ = amount_cashed;
    amount_kept_ =  amount_kept;
    amount_deposited_ = amount_deposited;
}
CheckingAccount::~CheckingAccount() 
{
    
}
void CheckingAccount::SetAmountKept(long kept_dollars, int kept_cents) 
{
    stringstream kept;
    kept << '$' << setw(1) << setfill('0') << kept_dollars << "." 
      << setfill('0') << setw(2) << kept_cents;
}
void CheckingAccount::WriteCheck(int check_number, long check_dollars, 
                                    int check_cents) 
{
    stringstream check;
    long current_dollars = BankAccount::GetDollars();
    int current_cents = BankAccount::GetCents();
    // Get all the cents of current balance
    long all_cents1 = current_cents + current_dollars * 100;
    // Get all the cents of withdrawn amount
    long all_cents2 = check_cents + check_dollars * 100;
    if(all_cents1 >= all_cents2)
    {
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
        BankAccount::SetDollars(final_dollars);
        BankAccount::SetCents(final_cents);
        check << "Check #" << check_number;
        BankAccount::SetLastTransaction(final_dollars, final_cents, check.str());
        BankAccount::SetRecentTransactions(final_dollars, final_cents, check.str());
    } else
    {
        BankAccount::SetLastTransaction(0,0,"CHECK ERROR: INSUFFICIENT FUNDS");
        BankAccount::SetRecentTransactions(0,0,"CHECK ERROR: INSUFFICIENT FUNDS");
    }
}
string CheckingAccount::GetAmountedKept() 
{
    return amount_kept_;
}
void CheckingAccount::CashCheck(long check_dollars, int check_cents, 
                        long check_dollars_deposited,
                        int check_cents_deposited) 
{
    if ((check_dollars_deposited <= check_dollars) || 
    (check_dollars_deposited == 0 && check_cents_deposited <= check_cents))
    {
        stringstream money_kept;
        long current_dollars = BankAccount::GetDollars();
        int current_cents = BankAccount::GetCents();
        // Get all the cents of current balance
        long all_cents1 = current_cents + current_dollars * 100;
        // Get all the cents of deposited amount
        long all_cents2 = check_cents_deposited + check_dollars_deposited * 100;
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
        long kept_dollars = check_dollars - check_dollars_deposited;
        int kept_cents = check_cents - check_cents_deposited;
        SetAmountKept(kept_dollars, kept_cents);
        money_kept << "Cashed Check, " << GetAmountedKept() << " kept.";
        BankAccount::SetDollars(final_dollars);
        BankAccount::SetCents(final_cents);
        BankAccount::SetLastTransaction(final_dollars, final_cents, money_kept.str());
        BankAccount::SetRecentTransactions(final_dollars, final_cents, money_kept.str());
    } else
    {
        BankAccount::SetLastTransaction(0, 0, "CHECK CASHING ERROR");
        BankAccount::SetRecentTransactions(0, 0, "CHECK CASHING ERROR");
    }
}
