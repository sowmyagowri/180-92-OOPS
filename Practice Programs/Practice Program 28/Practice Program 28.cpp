//File Name: Practice Program 28.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 28
//Description: 
//Last Changed: Mar 5, 2017

#include "path.h"

int main()
{
   cout << "Adding to p1" << endl;
   Path p1(10);
   p1.add(1, 2);
   p1.add(2, 6);
   p1.add(3, 8);
   p1.add(4, 3);
   p1.add(5, 0);
   p1.add(6, -1);
   p1.print();
   cout << "Adding to p2" << endl;
   Path p2(2);
   p2.add(3, 4);
   p2.add(5, 6);
   p2.add(7, 8);
   p2.print();
   cout << "All done" << endl;

   return 0;
}
