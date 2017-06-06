#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

map<int, set<int>> invert(const map<int, int>& m);

int main()
{
   map<int, int> m;
   m[1] = 2;
   m[2] = 2;
   m[3] = 3;
   map<int, set<int>> result = invert(m);

   for (const auto& p : result)
   {
      cout << p.first << " -> { ";
      for (const auto& q : p.second)
      {
         cout << q << " ";
      }
      cout << "}" << " ";
   }
   cout << endl;
   cout << "Expected: 2 -> { 1 2 } 3 -> { 3 }" << endl;
   cout << boolalpha << (result.find(1) == result.end()) << endl;
   cout << "Expected: true" << endl;

   m = map<int, int> {};
   m[1] = 10;
   m[-1] = 10;
   m[2] = 20;
   m[-2] = 20;

   result = invert(m);
   for (const auto& p : result)
   {
      cout << p.first << " -> { ";
      for (const auto& q : p.second)
      {
         cout << q << " ";
      }
      cout << "}" << " ";
   }
   cout << endl;
   cout << "Expected: 10 -> { -1 1 } 20 -> { -2 2 }" << endl;
   cout << boolalpha << (result.find(0) == result.end()) << endl;
   cout << "Expected: true" << endl;

   return 0;
}
