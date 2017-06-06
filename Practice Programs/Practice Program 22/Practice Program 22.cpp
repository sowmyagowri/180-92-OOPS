//File Name: Practice Program 22.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 22
//Description: 
/*
  The Second National Bank of Stroustrup provides accounts in which
  deposits and balance inquiries have no charge. After a deposit,
  the first two withdrawals are free, but any further withdrawals
  have a charge of $10 until the next deposit. Implement the
  deposit and withdraw member functions.
*/
//Last Changed: Feb 25, 2017

#include <iostream>
#include <cmath>

using namespace std;

#include "BankAccount.h"

BankAccount::BankAccount()
{
   balance = 0;
   withdrawals = 0;
}

void BankAccount::deposit(double amount)
{
   double newBalance = balance + amount;
   balance = newBalance;
   withdrawals = 0;
}

void BankAccount::withdraw(double amount)
{
   double newBalance = balance - amount;
   withdrawals++;
   if (withdrawals > 2)
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
   account1.withdraw(1000);
   cout << "Balance: " << account1.getBalance() << endl;
   cout << "Expected: 4000" << endl;
   account1.withdraw(2000);
   cout << "Balance: " << account1.getBalance() << endl;
   cout << "Expected: 1990" << endl;
   account1.deposit(1000);
   account1.withdraw(500);
   cout << "Balance: " << account1.getBalance() << endl;
   cout << "Expected: 2490" << endl;


   BankAccount account2;
   account2.deposit(16000);
   account2.withdraw(1000);
   account2.withdraw(1000);
   account2.withdraw(1000);
   account2.withdraw(1000);
   cout << "Balance: " << account2.getBalance() << endl;
   cout << "Expected: 11980" << endl;
   account2.deposit(20);
   account2.withdraw(4000);
   cout << "Balance: " << account2.getBalance() << endl;
   cout << "Expected: 8000" << endl;

   return 0;
}
