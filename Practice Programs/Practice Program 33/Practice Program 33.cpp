//File Name: Practice Program 33.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 33
//Description: 
//Last Changed: Mar 15, 2017

#include <iostream>

using namespace std;

void print_digits(int n);

int main()
{
   print_digits(1729);
   cout << "Expected: 1 7 2 9" << endl;
   print_digits(1);
   cout << "Expected: 1" << endl;
   print_digits(11235811);
   cout << "Expected: 1 1 2 3 5 8 1 1" << endl;
}
