#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

void removeEvenPositions(list<int>& lst);

int main()
{
   list<int> nums = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
   removeEvenPositions(nums);
   copy(nums.begin(), nums.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 1 3 8 21" << endl;
   list<int> nums2 = { 1, 4, 9, 16, 25, 36 };
   removeEvenPositions(nums2);
   copy(nums2.begin(), nums2.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 4 16 36" << endl;
   return 0;
}
