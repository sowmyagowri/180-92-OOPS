#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

void swapHalves(list<int>& lst);

int main()
{
   list<int> nums = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
   swapHalves(nums);
   copy(nums.begin(), nums.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 8 13 21 34 1 1 2 3 5" << endl;
   list<int> nums2 = { 1, 1, 2, 3, 5, 8, 13, 21 };
   swapHalves(nums2);
   copy(nums2.begin(), nums2.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 5 8 13 21 1 1 2 3" << endl;
   list<int> nums3 = { 1, 2 };
   swapHalves(nums3);
   copy(nums3.begin(), nums3.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 2 1" << endl;
   list<int> nums4 = { 1 };
   swapHalves(nums4);
   copy(nums4.begin(), nums4.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 1" << endl;
   list<int> nums5 = { };
   swapHalves(nums5);
   cout << "{";
   copy(nums5.begin(), nums5.end(),
      ostream_iterator<int>(cout, " "));
   cout << "}" << endl;
   cout << "Expected: {}" << endl;
   return 0;
}
