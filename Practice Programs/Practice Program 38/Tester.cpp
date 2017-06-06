#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

void swapNeighbors(list<int>& lst);

int main()
{
   list<int> nums = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
   swapNeighbors(nums);
   copy(nums.begin(), nums.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 1 1 3 2 8 5 21 13 34" << endl;
   list<int> nums2 = { 1, 2, 3, 5, 8, 13, 21, 34 };
   swapNeighbors(nums2);
   copy(nums2.begin(), nums2.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 2 1 5 3 13 8 34 21" << endl;
   return 0;
}
