#include "list.h"
#include <iostream>
/*
   This function removes every even element from the given linked
   list. For example, if a list contains 16 26 25 12 11 (and then NULL),
   it is modified to contain 25 11 (and then NULL).
*/
void remove_every_even(NodePtr& head)
{
    NodePtr previous = head;
    NodePtr current;
    NodePtr next;
    int all_set = 0;

    if (previous != NULL && previous->link != nullptr)
        current = previous->link;
    else
        current = NULL;

    if (current != NULL && current->link != nullptr)
        next = current->link;
    else
        next = NULL;


   if (previous != NULL && previous->data % 2 ==0)
   {
       do
       {
            head = current;
            delete previous;
            previous = head;

            if (previous != NULL && previous->link != nullptr)
                current = previous->link;
            else
                current = NULL;

            if (current != NULL && current->link != nullptr)
                next = current->link;
            else
                next = NULL;

            if (previous == NULL || previous->data % 2 !=0)
                all_set = 1;

       }while (all_set == 0);
   }

    while (current != NULL)
    {
        if (current->data % 2 ==0)
        {
            if (current->link != nullptr)
                previous->link = current->link;
            else
                previous->link = nullptr;

            delete current;

            if (next != NULL)
            {
                current = next;
                next = current->link;
            }
            else
                current = next = NULL;
        }
        else
        {
            previous = current;
            current = previous->link;

            if (current != NULL)
                next = current->link;

        }
    }
}
