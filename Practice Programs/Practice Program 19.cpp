//File Name: Practice Program 19.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program 19
//Description:
/*
  Repeats a string n times and places it into a buffer, filling
  it up as much as possible, and providing a terminating 0.
  Use strncpy.
  @param str a string
  @param n an integer
  @param result a character array to hold the result
  @param sz the size of result
*/
//Last Changed: Feb 18, 2017

#include <iostream>
#include <cstring>

using namespace std;

void repeat(const char* str, int n, char result[], int sz);

int main()
{
   char results[28];
   char* r2 = results;
   char* r1 = results + 10;
   char* r4 = results + 21;
   char* r3 = results + 22;
   char* r5 = results + 26;
   strcpy(r5, "x");
   repeat("Hello", 2, r1, 11);
   repeat("Goodbye", 3, r2, 10);
   repeat("Goodbye", 3, r3, 4);
   repeat("HI", 10, r4, 1);
   cout << r1 << endl;
   cout << "Expected: HelloHello" << endl;
   cout << r2 << endl;
   cout << "Expected: GoodbyeGo" << endl;
   cout << r3 << endl;
   cout << "Expected: Goo" << endl;
   cout << "\"" << r4 << "\"" << endl;
   cout << "Expected: \"\"" << endl;
   cout << "\"" << r5 << "\"" << endl;
   cout << "Expected: \"x\"" << endl;

   return 0;
}

/*
  Repeats a string n times and places it into a buffer, filling
  it up as much as possible, and providing a terminating 0.
  Use strncpy.
  @param str a string
  @param n an integer
  @param result a character array to hold the result
  @param sz the size of result
*/
void repeat(const char* str, int n, char result[], int sz)
{
   if (sz <= 0) return;
   int len = strlen(str);
   int sz_available = sz;
   char* p = result;
   for (int i = 0; i < n && p < result + sz; i++)
   {
      if (len < sz_available)
      {
          strncpy(p,str,len);
          p +=len;
          sz_available -= len;
      }
      else
          strncpy(p,str,sz_available);
   }
   result[sz-1] = '\0';
   return;
}
