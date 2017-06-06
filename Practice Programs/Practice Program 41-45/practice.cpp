/*
#include <string>

using namespace std;

/**
   Return true if the given string contains at least two
   different characters. Use recursion. Do not use loops.
   Hint: If str[0] is not the same as str[1], you have
   your answer. Otherwise, look at str.substr(1) (the substring of str
   from position 1 to the end).
*/
/*
bool someDifferent(string str)
{
   if ( str.length() < 2 )  return false;
   else if ( str[0] != str[1] ) return true;
   else return someDifferent(str.substr(1));
}

#include <string>

using namespace std;

/**
   Mix two strings by alternating characters from them. If one string
   runs out before the other, just pick from the longer one.
   For example, mix("Fred", "Wilma") is "FWrieldma".
   Use recursion. Do not use loops.
   Hint: str.substr(1) is the substring of str from position 1 to
   the end.
*/
/*
string mix(string a, string b)
{
   if (a.length() == 0) return b;
   if (b.length() == 0) return a;
   return a.substr(0,1) + b.substr(0,1) + mix(a.substr(1), b.substr(1));
}


#include <string>

using namespace std;

/**
   Given a string, return a string of all lowercase letters contained in it.
   Use recursion. Do not use loops.
   A lowercase letter is a character between 'a' and 'z' inclusive.
   Hint: str.substr(1) is the substring of str from position 1 to
   the end.
*/
/*
string lcl(string str)
{
   if (str.length() == 0) return "";

   if ( isalpha(str[0]) && islower(str[0]) ) return str.substr(0,1) + lcl(str.substr(1));
   else return lcl(str.substr(1));
}

#include <string>
#include <vector>

using namespace std;

void lclHelper(string str, string currentGroup, vector<string>& lclGroups)
{
   if (str.length() == 0) return;

   if ( isalpha(str[0]) && islower(str[0]) )
   {
      currentGroup = currentGroup + str.substr(0,1);
      if (str.length() == 1)
      {
         lclGroups.push_back(currentGroup);
         currentGroup = "";
      }
      lclHelper(str.substr(1),currentGroup, lclGroups);
   }
   else
   {
      if (currentGroup != "")
         lclGroups.push_back(currentGroup);
      lclHelper(str.substr(1),"", lclGroups);
   }
}

/**
   Given a string, return a vector of all substrings consisting of
   lowercase letters contained in it. For example, if str is "I like 7 and 13",
   return a vector containing "like", and "and".
   Use a recursive helper method. Do not use loops.
   A lowercase letter is a character between 'a' and 'z' inclusive.

*/
/*
vector<string> lclGroups(string str)
{
   vector<string> result;
   lclHelper(str, "", result);
   return result;
}

#include <string>
#include <vector>

using namespace std;
double prodQuotHelper(vector<double> v, int index)
{
   if (v.empty()) return 1;
   if ( index == v.size() - 1 ) return v[index] / 1;
   if ( index == v.size() - 2 ) return v[index] / v[index+1];
   return ((v[index] / v[index+1]) * prodQuotHelper(v, index+2));
}

/**
   Given a vector of floating-point numbers, return the product quotient
   v[0] / v[1] * v[2] / v[3] * ...
   If the vector is empty, the product quotient is 1.
   Use a recursive helper method. Do not use loops.

*/
/*
double prodQuot(vector<double> v)
{
   return prodQuotHelper(v, 0);
}

*/
