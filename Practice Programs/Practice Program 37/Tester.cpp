#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

void removeEven(list<int>& lst);

int main()
{
   list<int> nums = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
   removeEven(nums);
   copy(nums.begin(), nums.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 1 1 3 5 13 21" << endl;
   list<int> nums2 = { 1, 4, 9, 16, 25, 36 };
   removeEven(nums2);
   copy(nums2.begin(), nums2.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 1 9 25" << endl;
   return 0;
}
