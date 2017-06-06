/*
Your task is to break a positive number into its individual digits, for example, to turn 1729
into 1, 7, 2, and 9. It is easy to get the last digit of a number n as n % 10. But that gets
the numbers in reverse order. Solve this problem with a stack. Your program should
ask the user for an integer, then print its digits separated by spaces.
*/

#include <iostream>

using namespace std;

#include "stack.h"

void print_digits(int n)
{
   Stack digit_stack;
   int input_num = n;
   int reverse_num = 0;

   while (input_num != 0)
   {
       reverse_num = (reverse_num * 10) + (input_num % 10);
       digit_stack.push((reverse_num %10));
       input_num /= 10;
   }

   while (!digit_stack.empty())
   {
      cout << digit_stack.pop() << " ";
   }
   cout << endl;
}
