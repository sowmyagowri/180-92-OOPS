//File Name: Practice Program 31.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 31
//Description: 
//Last Changed: Mar 14, 2017

#include <iostream>

using namespace std;

#include "list.h"

void remove_every_second(NodePtr head);

int main()
{
   NodePtr lst = NULL;
   head_insert(lst, 25);
   head_insert(lst, 16);
   head_insert(lst, 9);
   head_insert(lst, 4);
   head_insert(lst, 1);
   remove_every_second(lst);
   print(lst);
   cout << "Expected: 1 -> 9 -> 25 -> NULL" << endl;

   lst = NULL;
   head_insert(lst, 49);
   head_insert(lst, 36);
   head_insert(lst, 25);
   head_insert(lst, 16);
   head_insert(lst, 9);
   head_insert(lst, 4);
   head_insert(lst, 1);
   head_insert(lst, 0);
   remove_every_second(lst);
   print(lst);
   cout << "Expected: 0 -> 4 -> 16 -> 36 -> NULL" << endl;

   lst = NULL;
   head_insert(lst, 4);
   head_insert(lst, 1);
   remove_every_second(lst);
   print(lst);
   cout << "Expected: 1 -> NULL" << endl;

   lst = NULL;
   head_insert(lst, 1);
   remove_every_second(lst);
   print(lst);
   cout << "Expected: 1 -> NULL" << endl;

   lst = NULL;
   remove_every_second(lst);
   print(lst);
   cout << "Expected: NULL" << endl;

   return 0;
}
