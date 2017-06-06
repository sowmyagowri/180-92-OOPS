#include <string>
#include "list.h"

using namespace std;

int open_printed = 0;

/**
   Look at the recursively defined List class in list.h.
   A List is either empty or it has a head and a tail.
   Implement the show function that yields a visual
   string of the list elements, separated by ->, and
   surrounded by [].
   If the list is empty, return "[]".
*/
string show(const List& lst)
{
    string display;
    if (open_printed == 0)
    {
        if (lst.isEmpty())
        {
            open_printed = 0;
            return "[]";
        }

        if (lst.tail().isEmpty())
        {
            open_printed = 0;
            return "[" + lst.head() + "]";
        }

        open_printed = 1;
        display = "[";
    }

    if (lst.isEmpty()) return "]";

    if (lst.tail().isEmpty())
        display = display + lst.head() + show(lst.tail());
    else
        display = display + lst.head() + "->" + show(lst.tail());

    open_printed = 0;
    return display;
}




