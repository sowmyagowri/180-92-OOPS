//File Name: Practice Program 32.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 32
//Description: 
//Last Changed: Mar 14, 2017

#include <iostream>

using namespace std;

#include "list.h"

void remove_every_even(NodePtr& head);

int main()
{

   NodePtr lst = NULL;
   head_insert(lst, 25);
   head_insert(lst, 16);
   head_insert(lst, 9);
   head_insert(lst, 4);
   head_insert(lst, 1);
   remove_every_even(lst);
   print(lst);
   cout << "Expected: 1 -> 9 -> 25 -> NULL" << endl;

  lst = NULL;
   head_insert(lst, 49);
   head_insert(lst, 25);
   head_insert(lst, 36);
   head_insert(lst, 16);
   head_insert(lst, 9);
   head_insert(lst, 4);
   head_insert(lst, 1);
   head_insert(lst, 0);
   remove_every_even(lst);
   print(lst);
   cout << "Expected: 1 -> 9 -> 25 -> 49 -> NULL" << endl;

   lst = NULL;
   head_insert(lst, 4);
   head_insert(lst, 1);
   remove_every_even(lst);
   print(lst);
   cout << "Expected: 1 -> NULL" << endl;

   lst = NULL;
   head_insert(lst, 1);
   remove_every_even(lst);
   print(lst);
   cout << "Expected: 1 -> NULL" << endl;

   lst = NULL;
   head_insert(lst, 8);
   head_insert(lst, 4);
   head_insert(lst, 1);
   remove_every_even(lst);
   print(lst);
   cout << "Expected: 1 -> NULL" << endl;


   lst = NULL;
   head_insert(lst, 8);
   head_insert(lst, 4);
   remove_every_even(lst);
   print(lst);
   cout << "Expected: NULL" << endl;

   lst = NULL;
   remove_every_even(lst);
   print(lst);
   cout << "Expected: NULL" << endl;

   return 0;
}
