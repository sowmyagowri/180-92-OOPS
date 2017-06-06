#include "list.h"
#include <iostream>

/*
   This function removes every second element from the given linked
   list. For example, if a list contains 12 15 26 25 11 (and then NULL),
   it is modified to contain 12 26 11 (and then NULL).
*/
void remove_every_second(NodePtr head)
{
   NodePtr previous = head;
   NodePtr current;
   if (previous != NULL)
      current = previous->link;

   while (current != NULL && previous != NULL)
   {
      previous->link = current->link;
      previous = current->link;
      delete current;
      if (previous != NULL)
          current = previous->link;
   }
}
