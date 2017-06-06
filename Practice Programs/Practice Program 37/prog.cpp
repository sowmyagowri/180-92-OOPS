#include <list>
using namespace std;

/**
   Remove the even elements of the linked list.
   Use an iterator.
*/
void removeEven(list<int>& lst)
{
    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        if (*it % 2 == 0)
            it = lst.erase(it);
    }
}
