/*
 * Name        : credit_account.cpp
 * Author      : David Dalton
 * Description : CreditAccount function definition
 * Source      : Luke Sathrum, modified portions of money lab and item lab
 */
 
#include "credit_account.h"

/*
 * Constructor, uses default values if none given on creation
 */
CreditAccount::CreditAccount(string account_name, long dollars, 
                    int cents, double interest_rate,
                    long max_balance_dollars, 
                    int max_balance_cents,
                    string last_transaction,
                    string interest_accumulated_month, 
                    string interest_accumulated_year) 
{
    BankAccount::SetAccountName(account_name);
    BankAccount::SetDollars(dollars);
    BankAccount::SetCents(cents) ;
    BankAccount::SetLastTransaction(0, 0, last_transaction);
    BankAccount::ClearRecentTransactions();
    SetMaxBalanceDollars(max_balance_dollars);
    SetMaxBalanceCents(max_balance_cents);
    interest_rate_ = interest_rate;
    interest_accumulated_month_ = interest_accumulated_month;
    interest_accumulated_year_ = interest_accumulated_year;;
}
/*
 * Destructor, unused
 */
CreditAccount::~CreditAccount() 
{
    
}
/*
 * Mutator
 *
 */
void CreditAccount::SetInterestRate(double interest_rate) 
{
    interest_rate_ = interest_rate;
}
/*
 * Mutator
 *
 */
void CreditAccount::SetMaxBalanceDollars(long max_balance_dollars) 
{
    max_balance_dollars_ = max_balance_dollars;
}
/*
 * Mutator
 *
 */
void CreditAccount::SetMaxBalanceCents(int max_balance_cents) 
{
    max_balance_cents_ = max_balance_cents;
}
/*
 * Mutator
 *
 */
void CreditAccount::SetInterestAccumulatedMonth(long accumulated_dollars, 
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
/*
 * Mutator
 *
 */
void CreditAccount::SetInterestAccumulatedYear(long accumulated_dollars, 
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
/*
 * Mutator
 *
 */
void CreditAccount::MakePayment(long payment_dollars, int payment_cents) 
{
    long current_dollars = GetDollars();
    int current_cents = GetCents();
    // Get all the cents of current balance
    long all_cents1 = current_cents + current_dollars * 100;
    // Get all the cents of withdrawn amount
    long all_cents2 = payment_cents + payment_dollars * 100;
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
        SetLastTransaction(final_dollars, final_cents, "Credit Card Payment");
        SetRecentTransactions(final_dollars, final_cents, "Credit Card Payment");
    } else 
    {
        BankAccount::SetDollars(0);
        BankAccount::SetCents(0);
        SetLastTransaction(current_dollars, current_cents, "Credit Card Payment");
        SetRecentTransactions(current_dollars, current_cents, "Credit Card Payment");
    }
}
/*
 * Mutator
 *
 */
void CreditAccount::ChargeCard(long transaction_number, long charge_dollars, 
                        int charge_cents) 
{
    stringstream charge;
    long current_dollars = GetDollars();
    int current_cents = GetCents();
    long max_balance_dollars = GetMaxBalanceDollars();
    int max_balance_cents = GetMaxBalanceCents();
    // Get all the cents of current balance
    long all_cents1 = current_cents + current_dollars * 100;
    // Get all the cents of deposited amount
    long all_cents2 = charge_cents + charge_dollars * 100;
    // Add all the cents together
    long sum_all_cents = all_cents1 + all_cents2;
    // Handle the fact that money can be negative
    long abs_all_cents = abs(sum_all_cents);
    long final_dollars = abs_all_cents / 100;
    int final_cents = abs_all_cents % 100;
    // If the result of the operation was negative, negate final dollars and cents
    if((final_dollars <= max_balance_dollars) || (final_dollars == max_balance_dollars && final_cents <= max_balance_cents))
    {
        if (sum_all_cents < 0) {
         final_dollars = -final_dollars;
         final_cents = -final_cents;
        }
        BankAccount::SetDollars(final_dollars);
        BankAccount::SetCents(final_cents);
        charge << "Transaction #" << transaction_number;
            BankAccount::SetLastTransaction(final_dollars, final_cents, charge.str());
            BankAccount::SetRecentTransactions(final_dollars, final_cents, charge.str());
    } else
    {
        BankAccount::SetLastTransaction(0,0,"CARD ERROR: INSUFFICIENT FUNDS");
        BankAccount::SetRecentTransactions(0,0,"CARD ERROR: INSUFFICIENT FUNDS");
    }
}
/*
 * Mutator
 *
 */
void CreditAccount::CalculateInterest() 
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
/*
 * Accessor
 *gets the value of interest and returns it
 */
double CreditAccount::GetInterestRate() 
{
    return interest_rate_;
}
/*
 * Accessor
 *gets the value of max_balance_dollars_ and returns it
 */
long CreditAccount::GetMaxBalanceDollars() 
{
    return max_balance_dollars_;
}
/*
 * Accessor
 *gets the value of max_balance_cents_ and returns it
 */
int CreditAccount::GetMaxBalanceCents() 
{
    return max_balance_cents_;
}
/*
 * Accessor
 *calls the GetMaxBalanceDollars() and GetMaxBalanceCents() functions to get
 *the values of their variables.  It then stores the values of those variables
 *and sends them to a stringstream along with default characters.  It then
 *returns the string
 */
string CreditAccount::GetMaxBalance() 
{
    /*
    *Gets the absolute value of the objects cents value and stores it into a 
    *variable.  It then gets the value of the objects dollars_ and cents_
    *variables and checks to see if they are equal to and less than 0.  If
    *they are then they send them to an output stream with a negative character
    *otherwise it sends it to the output stream without the negative character
    *then returns the output stream
    */
    stringstream max_balance;
    long dollars = GetMaxBalanceDollars();
    int cents = GetMaxBalanceCents();
    {
      max_balance << "Your balance is: $" << setw(1) << setfill('0') << dollars << "." 
        << setfill('0') << setw(2) << cents;
    }
    return max_balance.str();
}
/*
 * Accessor
 *gets the value of interest_accumulated_month_ and returns it
 */
string CreditAccount::GetInterestAccumulatedMonth() 
{
    return interest_accumulated_month_;
}
/*
 * Accessor
 *gets the value of interest_accumulated_year_ and returns it
 */
string CreditAccount::GetInterestAccumulatedYear() 
{
    return interest_accumulated_year_;
}