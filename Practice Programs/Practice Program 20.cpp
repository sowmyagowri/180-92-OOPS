//File Name: Practice Program 20.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 20
//Description:
/*
  Return a pointer to the nth occurrence of a repeated character
  in the given string. For example, if str is "occurrence" and n is 2,
  return a pointer to the first r.
*/
//Last Changed: Feb 18, 2017

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const char* nthrep(const char* str, int n);

int main()
{
   const char* p = "occurrence";
   const char* r = nthrep(p, 1);
   cout << r - p << endl;
   cout << "Expected: 1" << endl;
   r = nthrep(p, 2);
   cout << r - p << endl;
   cout << "Expected: 4" << endl;
   r = nthrep(p, 3);
   cout << boolalpha << (r == NULL) << endl;
   cout << "Expected: true" << endl;
   p = "abbaccccaddabbra";
   r = nthrep(p, 2);
   cout << r - p << endl;
   cout << "Expected: 4" << endl;
   r = nthrep(p, 3);
   cout << r - p << endl;
   cout << "Expected: 9" << endl;
}

/*
  Return a pointer to the nth occurrence of a repeated character
  in the given string. For example, if str is "occurrence" and n is 2,
  return a pointer to the first r.
*/
const char* nthrep(const char* str, int n)
{
   const char* p = str;
   const char* r = NULL;
   char prev_repeated_char;
   char current_repeated_char;
   int len = strlen(str);
   int count = 0;
   while (p < str + len && count < n)
   {
       r = p + 1;
       if ( *r == *p )
       {
           if (count > 1)
           {
               current_repeated_char = *p;
               if (prev_repeated_char != current_repeated_char)
               {
                   count++;
                   prev_repeated_char = *p;
               }
           }
           else
           {
               count++;
               prev_repeated_char = *p;
           }
          r = p;
       }
       else
           r = NULL;
       p++;
   }
   p = str;
   return r;
}
