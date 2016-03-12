/*
 * Name        : atm_test.cpp
 * Author      : David Dalton
 * Description : Program to test an atm program
 */
 
#include "CinReader.cpp"
#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"
#include "credit_account.h"
#include <typeinfo>

class ATM 
{
 public:
  void CreateAccount();
  void Menu();
  void ShowBalance();
  void ClearTransactionHistory();
  void ShowTransactionHistory();
  void Deposit();
  void Withdraw();
  void CalculateInterest();
  void ShowInterest();
  void SetBool(bool done);
  
  bool GetBool();
  
 private:
  bool done_;
  string current_account_;
  CinReader reader;
};

int main()
{
    ATM myATM;
    myATM.Menu();
}


void ATM::CreateAccount()
{
    cout << "Select the type of account you wish to create" << endl;
    cout << "1 Bank Account 2 - Checking 3 - Savings 4 - Credit\n" << endl;
    int choice = reader.readInt(1,4);
    string account_name;
    long balance_dollars;
    int balance_cents;
    double interest_rate;
    switch(choice)
    { 
        case 1:
            cout << "Enter the name of your account" << endl;
            account_name = reader.readString();
            cout << "Set the dollar amount of your account balance" << endl;
            balance_dollars = reader.readInt(0);
            cout << "Set the cent amount of your account balance\n" << endl;
            balance_cents = reader.readInt(0,99);
            CheckingAccount(account_name, balance_dollars, balance_cents);
            Menu();
        break;
        
        case 2:
            cout << "Enter the name of your account" << endl;
            account_name = reader.readString();
            cout << "Set the dollar amount of your account balance" << endl;
            balance_dollars = reader.readInt(0);
            cout << "Set the cent amount of your account balance\n" << endl;
            balance_cents = reader.readInt(0,99);
            CheckingAccount(account_name, balance_dollars, balance_cents);
            Menu();
        break;
        
        case 3:
            cout << "Enter the name of your account" << endl;
            account_name = reader.readString();
            cout << "Set the dollar amount of your account balance" << endl;
            balance_dollars = reader.readInt(0);
            cout << "Set the cent amount of your account balance" << endl;
            balance_cents = reader.readInt(0,99);
            cout << "Select your interest rate\n" << endl;
            interest_rate = reader.readDouble();
            SavingAccount(account_name, balance_dollars,balance_cents, interest_rate);
            Menu();
        break;
        
        case 4:
            cout << "Enter the name of your account" << endl;
            account_name = reader.readString();
            cout << "Set the dollar amount of your account balance" << endl;
            balance_dollars = reader.readInt(0);
            cout << "Set the cent amount of your account balance" << endl;
            balance_cents = reader.readInt(0,99);
            cout << "Select your interest rate. NOTE: Must be greater or equal to 0.0" << endl;
            interest_rate = reader.readDouble();
            cout << "Set the dollar amount for your max balance" << endl;
            long max_dollars = reader.readInt(0);
            cout << "Set the cent amount for your max balance\n" << endl;
            int max_cents = reader.readInt(0, 99);
            CreditAccount(account_name, balance_dollars, balance_cents, max_dollars, max_cents, interest_rate);
            Menu();
    }
}

void ATM::Menu() 
{
    cout << "Enter the name of the account you would like to use" << endl;
    current_account_ = reader.readString();
    cout << "Please select from the following options." << endl;
    cout << "1 - Create an account\n2 - Show account balance\n3 - Deposit\n4 - Withdraw\n5 - Clear Transaction history\n6 - Calculate Interest\n 7 - Show interest accumulated\n8 - Exit ATM\n" << endl;
    int choice = reader.readInt(1,6);
    switch(choice)
    {
        case 1:
            CreateAccount();
        break;

        case 2:
            ShowBalance();
        break;
        
        case 3:
            Deposit();
        break;
        
        case 4:
            Withdraw();
        break;
        
        case 5:
            ClearTransactionHistory();
        break;
        
        case 6:
            CalculateInterest();
        break;
        
        case 7:
            ShowInterest();
        break;
        
        case 8:
            exit(0);
    }
    
}

void ATM::ShowBalance() 
{
    
    cout << current_account_.ShowBalance() << endl;
    Menu();
}

void ATM::ClearTransactionHistory() 
{
    current_account_.ClearRecentTransactions();
    Menu();
}

void ATM::ShowTransactionHistory() 
{
    for(int i = 0;i<10;i++)
    {
        cout << current_account_.GetLastTransaction(i) << endl;
    }
    Menu();
}

void ATM::Deposit() 
{
    long dollars;
    int cents;
    string type = typeid(account_name_).name()
    if(type == "CheckingAccount")
    {
        cout << "Would you like to deposit money into your account or cash a check?" << endl;
        cout << "Press 1 to deposit money and 2 to cash a check" << endl;
        int choice = reader.readInt(1,2);
        if(choice == 1)
        {
            cout << "Please enter the amount in dollars you would like to deposit, followed by the amount in cents\n" << endl;
            dollars = reader.readLong(0);
            cents = reader.readint(0,99);
            CheckingAccount.DepositAccount(dollars, cents);
            Menu();
        } else 
        {
            cout << "Please enter the dollar value of the check you are cashing, followed by the cent value" << endl;
            dollars = reader.readLong(0);
            cents = reader.readInt(0,99);
            cout << "Please enter the amount you'd like to keep in dollars, followed by cents\n" << endl
            long kept_dollars = reader.readLong(0);
            int kept_cents = reader.readInt(0,99);
            CheckingAccountCashCheck(dollars, cents, kept_dollars, kept_cents);
            Menu();
        }
    } else if(type == "CreditAccount") 
    {
        cout << "Please enter the amount you would like pay towards your balance in dollars, followed by cents\n" << endl; << endl;
        dollars = reader.readLong(0);
        cents = reader.readint(0,99);
        CreditAccount.MakePayment(dollars, cents);
        Menu();
    } else
    {
        cout << "Please enter the amount in dollars you would like to deposit, followed by the amount in cents\n" << endl;
        dollars = reader.readLong(0);
        cents = reader.readint(0,99);
        account_name_.DepositAccount(dollars, cents);
        Menu();
}

void ATM::Withdraw() 
{
    string type = typeid(account_name_).name()
    long dollars;
    int cents;
    if(type == "CheckingAccount")
    {
        cout << "Please enter the check number that you are writing" << endl;
        int check_number = reader.readInt(0);
        cout << "Please enter the amount the check is for in dollars, followed by the amount in cents\n" << endl;
        dollars = reader.readLong(0);
        cents = reader.readInt(0,99);
        CheckingAccount.WriteCheck(dollars, cents);
        Menu();
    } else if(type == "CreditAccount") 
    {
        cout << "Please enter the transaction number for the charge" << endl;
        int transaction = reader.readInt(0);
        cout << "Please enter the amount of the transaction in dollars, followed by cents\n" << endl;
        dollars = reader.readLong(0);
        cents = reader.readCents(0,99);
        CreditAccountMakePayment(transaction, dollars, cents);
        Menu();
    } else 
    {
        cout << "Please enter the amount in dollars you would like to withdraw, followed by the amount in cents\n" << endl;
        dollars = reader.readLong(0);
        cents = reader.readint(0,99);
        account_name_.WithdrawAccount(dollars, cents);
        Menu();
    }
}

void ATM::CalculateInterest() 
{
    string type = typeid(account_name_).name()
    if(type == "CheckingAccount" || type == "SavingAccount") 
    {
        account_name_.CalculateInterest
    } else 
    {
        cout << "ERROR: Incorrect account type\n" << endl;
    }
    Menu();
}

void ATM::ShowInterest() 
{
    cout << "Interest accumulated this month: " << account_name_.GetInterestAccumulatedMonth() << endl;
    cout << "Interest accumulated this year: " << account_name_.GetInterestAccumulatedYear() << "\n" << endl;
    Menu();
}
void SetBool(bool done)
{
    done_ = done;
}
bool GetBool() 
{
    return done_;
}