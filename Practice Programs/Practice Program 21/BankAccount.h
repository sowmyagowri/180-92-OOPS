/*
 * BankAccount.h
 *
 *  Created on: Feb 25, 2017
 *      Author: sends
 */

/**
   A bank account has a balance that can be changed by
   deposits and withdrawals.
*/
class BankAccount
{
 public:
   /**
      Constructs a bank account with a zero balance.
   */
   BankAccount();

   /**
      Deposits money into the bank account.
      @param amount the amount to deposit
   */
   void deposit(double amount);

   /**
      Withdraws money from the bank account.
      @param amount the amount to withdraw
   */
   void withdraw(double amount);

   /**
      Gets the current balance of the bank account.
      @return the current balance
   */
   double getBalance();

 private:
   double balance;
};
