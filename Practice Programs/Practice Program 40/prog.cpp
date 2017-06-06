#include <list>
using namespace std;

/**
      Changes the given lists so that they "cross over" like this:

      a: 0 ... n-1 n ...
                  x
      b: 0 ... m-1 m ...

      For example, if a is [1, 2, 3, 4], b is [5, 6, 7],
      n is 2 and m is 1, then a becomes [1, 2, 6, 7] and
      b becomes [5, 3, 4].

      Use iterators.

      You may assume that n < a.size() and m < b.size().
   */
void crossOver(list<int>& a, int n, list<int>& b, int m)
{
    list<int>::iterator it = a.begin();
    list<int>::iterator it1 = b.begin();
    advance(it, n);
    advance(it1, m);

    while( it != a.end() && it1 != b.end() )
    {
        iter_swap (it,it1);
        it++;
        it1++;
    }
}
