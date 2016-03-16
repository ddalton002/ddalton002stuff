/*
 * Name        : atm.cpp
 * Author      : David Dalton
 * Description : Program to test the account programs
 */
 
#include "CinReader.cpp"
#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"
#include "credit_account.h"
#include <typeinfo>

int atm()
{
    CinReader reader;
    bool end_program = false;
    bool done = false;
    long dollars;
    int cents;
    do
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
            //Bank account options
            case 1:
            {
                BankAccount myBanking;
                cout << "Set the dollar amount of your account balance\n" << endl;
                balance_dollars = reader.readInt(0);
                cout << "Set the cent amount of your account balance\n" << endl;
                balance_cents = reader.readInt(0,99);
                myBanking.SetDollars(balance_dollars);
                myBanking.SetCents(balance_cents);
                cout << "Please select from the following options." << endl;
                while(!done)
                {
                    cout << "1 - Show account balance\n2 - Deposit\n3 - Withdraw\n4 - Show recent transactions\n5 - Clear Transaction history\n6 - Exit ATM\n" << endl;
                    int choice = reader.readInt(1,6);
                    switch(choice)
                    {
                        case 1:
                        {
                            cout << myBanking.ShowBalance() << endl;
                        break;
                        }
                        
                        case 2:
                        {
                            cout << "Please enter the amount in dollars you would like to deposit, followed by the amount in cents\n" << endl;
                            dollars = reader.readInt(0);
                            cents = reader.readInt(0,99);
                            myBanking.DepositAccount(dollars, cents);
                        break;
                        }
                        
                        case 3:
                        {
                            cout << "Please enter the amount in dollars you would like to withdraw, followed by the amount in cents\n" << endl;
                            dollars = reader.readInt(0);
                            cents = reader.readInt(0,99);
                            myBanking.WithdrawAccount(dollars, cents);
                        break;
                        }
                        
                        case 4:
                        {
                            for(int i = 0;i<10;i++)
                            {
                                if(myBanking.GetRecentTransactions(i) == "")
                                {
                                    cout << "none" << endl;
                                }else
                                {
                                cout << myBanking.GetRecentTransactions(i) << endl;
                                }
                            }
                            
                            cout << "Your last transaction was: " << myBanking.GetLastTransaction() << endl;
                        break;
                        }
                        
                        case 5:
                        {
                            myBanking.ClearRecentTransactions();
                        break;
                        }
                        
                        case 6:
                        {
                            done = true;
                        }
                    }
                }
            break;
            }
            
            //Checking account options
            case 2:
            {
                CheckingAccount myChecking;
                cout << "Set the dollar amount of your account balance" << endl;
                balance_dollars = reader.readInt(0);
                cout << "Set the cent amount of your account balance\n" << endl;
                balance_cents = reader.readInt(0,99);
                myChecking.SetDollars(balance_dollars);
                myChecking.SetCents(balance_cents);
                cout << "Please select from the following options." << endl;
                
                while(!done)
                {
                    cout << "1 - Show account balance\n2 - Deposit Money/Check\n3 - Withdraw/Write a check\n4 - Show recent transactions\n5 - Clear Transaction history\n6 - Exit ATM\n" << endl;
                    int choice = reader.readInt(1,6);
                    switch(choice)
                    {
                        case 1:
                        {
                            cout << myChecking.ShowBalance() << endl;
                        break;
                        }
                        
                        case 2:
                        {
                            cout << "Would you like to deposit money into your account or cash a check?" << endl;
                            cout << "Press 1 to deposit money and 2 to cash a check" << endl;
                            int choice = reader.readInt(1,2);
                            if(choice == 1)
                            {
                                cout << "Please enter the amount in dollars you would like to deposit, followed by the amount in cents\n" << endl;
                                dollars = reader.readInt(0);
                                cents = reader.readInt(0,99);
                                myChecking.DepositAccount(dollars, cents);
                            } else 
                            {
                                cout << "Please enter the dollar value of the check you are cashing, followed by the cent value" << endl;
                                dollars = reader.readInt(0);
                                cents = reader.readInt(0,99);
                                cout << "Please enter the amount you'd like to keep in dollars, followed by cents\n" << endl;
                                long kept_dollars = reader.readInt(0);
                                int kept_cents = reader.readInt(0,99);
                                myChecking.CashCheck(dollars, cents, kept_dollars, kept_cents);
                            }
                        break;
                        }
                        
                        case 3:
                        {
                            cout << "Please enter the check number that you are writing" << endl;
                            int check_number = reader.readInt(0);
                            cout << "Please enter the amount the check is for in dollars, followed by the amount in cents\n" << endl;
                            dollars = reader.readInt(0);
                            cents = reader.readInt(0,99);
                            myChecking.WriteCheck(check_number, dollars, cents);
                        break;
                        }
                        
                        case 4:
                        {
                            for(int i = 0;i<10;i++)
                            {
                                if(myChecking.GetRecentTransactions(i) == "")
                                {
                                    cout << "none" << endl;
                                }else
                                {
                                cout << myChecking.GetRecentTransactions(i) << endl;
                                }
                            }
                            
                        break;
                        }
                        
                        case 5:
                        {
                            myChecking.ClearRecentTransactions();
                        break;
                        }
                        case 6:
                        {
                            done = true;
                        }
                    }
                }
            break;
            }
            
            //Savings account options
            case 3:
            {
                SavingAccount mySavings;
                cout << "Set the dollar amount of your account balance" << endl;
                balance_dollars = reader.readInt(0);
                cout << "Set the cent amount of your account balance" << endl;
                balance_cents = reader.readInt(0,99);
                cout << "Select your interest rate\n" << endl;
                interest_rate = reader.readDouble();
                mySavings.SetDollars(balance_dollars);
                mySavings.SetCents(balance_cents);
                mySavings.SetInterestRate(interest_rate);
                cout << "Please select from the following options." << endl;
                while(!done)
                {
                    cout << "1 - Show account balance\n2 - Deposit\n3 - Withdraw\n4 - Show recent transactions\n5 - Clear Transaction history\n6 - Calculate Interest\n7 - Show interest accumulated\n8 - Exit ATM\n" << endl;
                    int choice = reader.readInt(1,8);
                    switch(choice)
                    {
                        case 1:
                        {
                            cout << mySavings.ShowBalance() << endl;
                        break;
                        }
                        
                        case 2:
                        {
                            cout << "Please enter the amount in dollars you would like to deposit, followed by the amount in cents\n" << endl;
                            dollars = reader.readInt(0);
                            cents = reader.readInt(0,99);
                            mySavings.DepositAccount(dollars, cents);
                        break;
                        }
                        
                        case 3:
                        {
                            cout << "Please enter the amount in dollars you would like to withdraw, followed by the amount in cents\n" << endl;
                            dollars = reader.readInt(0);
                            cents = reader.readInt(0,99);
                            mySavings.WithdrawAccount(dollars, cents);
                        break;
                        }
                        
                        case 4:
                        {
                            for(int i = 0;i<10;i++)
                            {
                                if(mySavings.GetRecentTransactions(i) == "")
                                {
                                    cout << "none" << endl;
                                }else
                                {
                                cout << mySavings.GetRecentTransactions(i) << endl;
                                }
                            }
                            
                        break;
                        }
                        
                        case 5:
                        {
                            mySavings.ClearRecentTransactions();
                        break;
                        }
                        
                        case 6:
                        {
                            mySavings.CalculateInterest();
                        break;
                        }
                        
                        case 7:
                        {
                            cout << "Interest accumulated this month: " << mySavings.GetInterestAccumulatedMonth() << endl;
                            cout << "Interest accumulated this year: " << mySavings.GetInterestAccumulatedYear() << "\n" << endl;
                        break;
                        }
                        
                        case 8:
                        {
                            done = true;
                        }
                    }
                }
            break;
            }
            
            //Credit Account options
            case 4:
            {
                CreditAccount myCredit;
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
                myCredit.SetDollars(balance_dollars);
                myCredit.SetCents(balance_cents);
                myCredit.SetMaxBalanceDollars(max_dollars);
                myCredit.SetMaxBalanceCents(max_cents);
                myCredit.SetInterestRate(interest_rate);
                
                cout << "Please select from the following options." << endl;
                while(!done)
                {
                    cout << "1 - Show account balance\n2 - Deposit\n3 - Withdraw\n4 - Calculate Interest\n5 - Clear Transaction history\n6 - Calculate interest\n7 - Show interest accumulated\n8 - Exit ATM\n" << endl;
                    int choice = reader.readInt(1,8);
                    switch(choice)
                    {
                        case 1:
                        {
                            cout << myCredit.ShowBalance() << endl;
                        break;
                        }
                        
                        case 2:
                        {
                            cout << "Please enter the amount you would like pay towards your balance in dollars, followed by cents\n" << endl << endl;
                            dollars = reader.readInt(0);
                            cents = reader.readInt(0,99);
                            myCredit.MakePayment(dollars, cents);
                        break;
                        }
                        
                        case 3:
                        {
                            cout << "Please enter the transaction number for the charge" << endl;
                            int transaction = reader.readInt(0);
                            cout << "Please enter the amount of the transaction in dollars, followed by cents\n" << endl;
                            dollars = reader.readInt(0);
                            cents = reader.readInt(0,99);
                            myCredit.ChargeCard(transaction, dollars, cents);
                        break;
                        }
                        
                        case 4:
                        {
                            for(int i = 0;i<10;i++)
                            {
                                if(myCredit.GetRecentTransactions(i) == "")
                                {
                                    cout << "none" << endl;
                                }else
                                {
                                cout << myCredit.GetRecentTransactions(i) << endl;
                                }
                            }
                            
                        break;
                        }
                        
                        case 5:
                        {
                            myCredit.ClearRecentTransactions();
                        break;
                        }
                        
                        case 6:
                        {
                            myCredit.CalculateInterest();
                        break;
                        }
                        
                        case 7:
                        {
                            cout << "Interest accumulated this month: " << myCredit.GetInterestAccumulatedMonth() << endl;
                            cout << "Interest accumulated this year: " << myCredit.GetInterestAccumulatedYear() << "\n" << endl;
                        break;
                        }
                        
                        
                        case 8:
                        {
                            done = true;
                        }
                    }
                }
            }//break
        }
    }while(!end_program);
}