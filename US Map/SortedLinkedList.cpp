#include "SortedLinkedList.h"
#include <iomanip>
#include <iostream>
#include <string>

SortedLinkedList::SortedLinkedList() //Default constructor
{
   head = NULL;
}

/**
 * Insert a new node into the sorted linked list.
 * Uses the overloaded Node::operator > to compare nodes.
 * @param node points to the node to insert.
 */
void SortedLinkedList::insert(Node *node)
{
   Node* previous;
   Node* current;

   if (head == NULL) //If the list is empty
   {
      node->next = NULL;
      head = node;
   }
   else
   {
      if (*head > *node) //Insert as the first node in the list
      {
         node->next = head;
         head = node;
      }
      else //Insert after a node to maintain the sorted order
      {
         current = head;
         while (current != NULL && *node > *current)
         {
            previous = current;
            current = current->next;
         }

         previous->next = node;
         node->next = current;
      }
   }
}

// Overloaded stream output insertion operator.
ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
   Node* previous = list.head;
   Node* current;
   int new_row = 0, printed = 0, current_position = 0;

   if (previous != NULL && previous->get_row() > 0)
   {
      for (int i = 0; i < previous->get_row(); i++)
         outs << endl;
   }

   outs << setw(previous->get_col()) << *previous;

   if (previous->get_name() == "")
      current_position = previous->get_col();
   else
      current_position = previous->get_col() + previous->get_name().length() + 1 + previous->get_state().length();

   current = previous->next;

   while (current != NULL)
   {
      if ( current->get_row() > previous->get_row() ) //To check every node if it can be printed in the same line or in a new line
      {
         new_row = 1;
         for (int i = 0; i < (current->get_row() - previous->get_row()); i++)
            outs << endl;
      }
      if (new_row == 0)
      {
         if ( current->get_col() > current_position ) //To check if the current node position overlaps an already printed node
         {
            outs << setw(current->get_col() - current_position) << *current;
            printed = 1;
         }

         if ( printed == 1 ) //Update the current cursor position only if the current node was printed
         {
            if ( current->get_name() == "" ) //Check if the node is a boundary
            {
               current_position = current->get_col(); //current cursor position is after printing #
               printed = 0;
            }
            else //Check if the node is a city
            {
               //current cursor position is after printing *+name+SPACE+state
               current_position = current->get_col() + current->get_name().length() + 1 +  current->get_state().length();
               printed = 0;
            }
         }
      }
      else
      {
         outs << setw(current->get_col()) << *current;

         if (current->get_name() == "")
            current_position = current->get_col();
         else
            current_position = current->get_col() + current->get_name().length() + 1 + current->get_state().length();
         new_row = 0;
      }

      previous = current;
      current = current->next;
   }

   //Clean-up the program before it terminates by explicitly deleting the Node object that was created using the keyword new
   //All other objects will be automatically deleted as and when they go out-of-scope
   current = list.head;
   while (current != NULL)
   {
      current->~Node();
      current = current->next;
   }
   return outs;
}
