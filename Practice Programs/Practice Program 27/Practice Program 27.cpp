//File Name: Practice Program 27.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 27
//Description: 
//Last Changed: Mar 5, 2017

#include "path.h"
#include "prog.h"

int main()
{
   cout << "Adding to p1" << endl;
   Path p1;
   p1.add(1, 2);
   p1.add(2, 6);
   p1.add(3, 8);
   p1.add(4, 3);
   p1.add(5, 0);
   p1.add(6, -1);
   cout << "Calling backtrack(p1)" << endl;
   backtrack(p1);

   cout << "Adding to p2" << endl;
   Path p2;
   p2.add(3, 4);
   p2.add(5, 6);
   p2.add(7, 8);
   cout << "Calling backtrack(p2)" << endl;
   backtrack(p2);
   cout << "All done" << endl;

   return 0;
}

void backtrack(Path& p)
{
   for (int i = p.length() - 2; i >= 0; i--)
       p.add(p.at(i));
   p.print();
}

