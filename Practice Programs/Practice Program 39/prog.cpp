#include <list>
#include <iostream>
using namespace std;

/**
   Swap the first and second half of the list. For example,
   if lst contains 1 2 4 8 16 32, afterwards it should contain
   8 16 32 1 2 4.  If the list has odd length, the middle
   element should become the last element of the result.

   Use iterators.
*/
void swapHalves(list<int>& lst)
{
    int mid, count = 0;

    if (lst.size() % 2 == 0)
        mid = lst.size() / 2;
    else
        mid = (lst.size() - 1) / 2;

    list<int>::reverse_iterator rit = lst.rbegin();
    while(count < mid)
    {
        lst.push_front (*rit);
        rit++;
        lst.pop_back();
        rit = lst.rbegin();
        count++;
    }
}
