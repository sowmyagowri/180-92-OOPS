#include <list>
using namespace std;

/**
   Remove the elements at position 0, 2, 4, 6, ..., of the
   linked list.
   Use an iterator.
*/
void removeEvenPositions(list<int>& lst)
{
    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        it = lst.erase(it);
        if (it == lst.end())
            break;
    }
}
