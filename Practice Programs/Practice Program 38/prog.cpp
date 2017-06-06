#include <list>
using namespace std;

/**
   Swap neighboring elements of this linked list. If the
   length is odd, leave the last element unchanged.
*/
void swapNeighbors(list<int>& lst)
{
    list<int>::iterator it1;
    int temp;
    for (list<int>::iterator it = lst.begin(); it != lst.end(); advance(it,2))
    {
        it1=it;
        it1++;
        if (it1 != lst.end())
            iter_swap(it,it1);
        else
            break;
    }
}
