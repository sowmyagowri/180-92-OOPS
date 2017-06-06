//File Name: Practice Program 18.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 18
//Description: 
/*
  The print method receives as input a string followed by an asterisk
  and an integer. Print out the string as many time as indicated
  by the integer. For example, when called as print("Hi*3"),
  you print HiHiHi. If no integer is specified, print the string
  once.

  Hint: Look for the '*' starting from the back of the string.
  Then call atoi, passing a pointer to the integer starting after
  the '*'. You can also replace the '*' with a '\0' for easy
  printing of the first part.
*/
//Last Changed: Feb 17, 2017

#include <iostream>

using namespace std;

void print(char* arg);

int main()
{
   char a1[] = "Hello*2";
   print(a1);
   cout << "Expected: HelloHello" << endl;
   char a2[] = "Goodbye*3";
   print(a2);
   cout << "Expected: GoodbyeGoodbyeGoodbye" << endl;
   char a3[] = "HI*10";
   print(a3);
   cout << "Expected: HIHIHIHIHIHIHIHIHIHI" << endl;
   char a4[] = "Bonjour";
   print(a4);
   cout << "Expected: Bonjour" << endl;
   char a5[] = "4*4*4";
   print(a5);
   cout << "Expected: 4*44*44*44*4" << endl;

   return 0;
}

/*
  The print method receives as input a string followed by an asterisk
  and an integer. Print out the string as many time as indicated
  by the integer. For example, when called as print("Hi*3"),
  you print HiHiHi. If no integer is specified, print the string
  once.

  Hint: Look for the '*' starting from the back of the string.
  Then call atoi, passing a pointer to the integer starting after
  the '*'. You can also replace the '*' with a '\0' for easy
  printing of the first part.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void print(char* arg)
{
  int iter;

  string str(arg);

  size_t found;
  static const size_t npos = -1;
  found=str.find_last_of("*");

  if (found != npos)
  {
      iter = atoi(&arg[found+1]);
      arg[found] = '\0';
  }
  else
      iter=1;

  for (int i=0; i<iter; i++)
    cout << arg;

  cout << endl;
}
