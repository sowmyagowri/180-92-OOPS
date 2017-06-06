//File Name: Practice Program 21.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 21
//Description: 
/*
  The First National Bank of Stroustrup provides accounts in which
  deposits and balance inquiries have no charge, but there is a
  $10 charge for withdrawals if after the withdrawal the balance
  falls below $1000. Implement the withdraw member function.
*/
//Last Changed: Feb 25, 2017

#include <iostream>
#include <cmath>

using namespace std;

#include "BankAccount.h"

BankAccount::BankAccount()
{
   balance = 0;
}

void BankAccount::deposit(double amount)
{
   double newBalance = balance + amount;
   balance = newBalance;
}

void BankAccount::withdraw(double amount)
{
   double newBalance = balance - amount;
   if (newBalance < 1000)
       newBalance = newBalance - 10;
   balance = newBalance;
}

double BankAccount::getBalance()
{
   return balance;
}

int main()
{
   BankAccount account1;
   account1.deposit(10000);
   account1.withdraw(5000);
   cout << "Balance: " << account1.getBalance() << endl;
   cout << "Expected: 5000" << endl;
   account1.withdraw(4500);
   cout << "Balance: " << account1.getBalance() << endl;
   cout << "Expected: 490" << endl;


   BankAccount account2;
   account2.deposit(15000);
   account2.withdraw(10000);
   cout << "Balance: " << account2.getBalance() << endl;
   cout << "Expected: 5000" << endl;
   account2.withdraw(4000);
   cout << "Balance: " << account2.getBalance() << endl;
   cout << "Expected: 1000" << endl;

   return 0;
}
