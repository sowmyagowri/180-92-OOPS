//File Name: Practice Program 35.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 35
//Description: 
//Last Changed: Mar 15, 2017

/*
A queue is often useful when you need to break a task into simpler tasks. Here you will use a queue to enumerate all permutations
of a string.

Suppose you want to find all permutations of the string meat.

Add the string +meat on the queue.
While the queue is not empty
   Remove a string from the queue
   If that string ends in a + (such as tame+)
      Remove the + and print the string
   Else
      Remove each letter in turn from the right of the +.
      Insert it just before the +.
      Add the resulting string on the stack.
      For example, after removing e+mta, you add em+ta, et+ma, and ea+mt.
*/

#include <iostream>

using namespace std;

#include "queue.h"

int main()
{
   string word;
   cin >> word;
   Queue work_queue;
   work_queue.add("+" + word);
   while (!work_queue.empty())
   {
      string str = work_queue.remove();
      int i = 0;
      while (str.substr(i, 1) != "+") i++;
      if (i == str.length() - 1)
         cout << str.substr(0, i) << endl;
      else
      {
         for (int j = i + 1; j < str.length(); j++)
         {
            // Make a string consisting of
            // the part of before the +
            // the letter at index j
            // +
            // everything after the + and before index j
            // everything after index j
            string to_add = str.substr(0, i) + str.substr(j, 1) + "+" + str.substr(i + 1, j - i - 1) + str.substr(j + 1, str.length() - j - 1);

            work_queue.add(to_add);
         }
      }
   }

   return 0;
}
