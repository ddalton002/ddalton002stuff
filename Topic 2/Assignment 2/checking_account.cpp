/*
 * Name        : checking_account.cpp
 * Author      : David Dalton
 * Description : CheckingAccount function definition
 * Source      : Luke Sathrum, modified portions of money lab and item lab
 */
 
#include "checking_account.h"

/*
 * Constructor, uses default values if none given on creation
 */
CheckingAccount::CheckingAccount(string account_name ,long dollars, int cents, 
                                string last_transaction, string amount_kept) 
{
    BankAccount::SetAccountName(account_name);
    BankAccount::SetDollars(dollars);
    BankAccount::SetCents(cents) ;
    BankAccount::SetLastTransaction(0, 0, last_transaction);
    amount_kept_ =  amount_kept;
    BankAccount::ClearRecentTransactions();
}
/*
 * Destructor, unused
 */
CheckingAccount::~CheckingAccount() 
{
    
}
/*
 * Mutator
 *sets all values in the recent_transactions array to "none"
 *sets the value of last_transaction to 0, 0 and "none"
 */
void CheckingAccount::SetAmountKept(long kept_dollars, int kept_cents) 
{
    stringstream kept;
    kept << '$' << setw(1) << setfill('0') << kept_dollars << "." 
      << setfill('0') << setw(2) << kept_cents;
}
/*
 * Mutator
 *calls the GetDollars() and GetCents() function and stores the results in 
 *separate variables.  Then it adds the values of those two variables together
 *and adds the values the two input variables together and multiples each
 *resulting sum by 100.  Subtracts second value from the original value
 *unless the second value is larger.
 */
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
        // Sets the value of dollars_ and cents_ to the resulting values
        BankAccount::SetDollars(final_dollars);
        BankAccount::SetCents(final_cents);
        check << "Check #" << check_number;
        // Writes the transaction to the last_transaction_ and
        // recent_transaction_[0]
        BankAccount::SetLastTransaction(final_dollars, final_cents, check.str());
        BankAccount::SetRecentTransactions(final_dollars, final_cents, check.str());
    } else
    {
        /*
         *If the second value is greater then the original balance value, 
         *writes and error message to the transaction recrod value and negates
         *the transaction.
         */
        BankAccount::SetLastTransaction(0,0,"CHECK ERROR: INSUFFICIENT FUNDS");
        BankAccount::SetRecentTransactions(0,0,"CHECK ERROR: INSUFFICIENT FUNDS");
    }
}
/*
 * Mutator
 *adds a specified amount of the check_dollars and check_cents variable
 *to the dollars_ and cents_ values.
 */
void CheckingAccount::CashCheck(long check_dollars, int check_cents, 
                        long check_dollars_deposited,
                        int check_cents_deposited) 
{
    /*
     *checksthat the amount specified to be kept is less then or equal to 
     *the total amount of the original check value.
     */
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
        // Subtracts the amount specified to be kept from the original values
        long kept_dollars = check_dollars - check_dollars_deposited;
        int kept_cents = check_cents - check_cents_deposited;
        // Stores the kept amount into the amount_kept_ variable
        SetAmountKept(kept_dollars, kept_cents);
        money_kept << "Cashed Check, " << GetAmountedKept() << " kept.";
        // Sets dollars_ and cents_ to the results of the final amounts
        BankAccount::SetDollars(final_dollars);
        BankAccount::SetCents(final_cents);
        // Adds the results to the transactional record variable
        BankAccount::SetLastTransaction(final_dollars, final_cents, money_kept.str());
        BankAccount::SetRecentTransactions(final_dollars, final_cents, money_kept.str());
    } else
    {
        //Sets the transaction record variables to a error message
        BankAccount::SetLastTransaction(0, 0, "CHECK CASHING ERROR");
        BankAccount::SetRecentTransactions(0, 0, "CHECK CASHING ERROR");
    }
}
/*
 * Accessor
 *gets the value of amount_kept_ and returns it
 */
string CheckingAccount::GetAmountedKept() 
{
    return amount_kept_;
}
