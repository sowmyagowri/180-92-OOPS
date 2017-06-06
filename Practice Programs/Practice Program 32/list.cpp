#include <iostream>

using namespace std;

#include "list.h"

void head_insert(NodePtr& head, int the_number)
{
   NodePtr temp_ptr;
   temp_ptr = new Node;

   temp_ptr->data = the_number;

   temp_ptr->link = head;
   head = temp_ptr;
}

void print(NodePtr head)
{
   NodePtr temp_ptr = head;
   while (temp_ptr != NULL)
   {
      cout << temp_ptr->data << " -> ";
      temp_ptr = temp_ptr->link;
   }
   cout << "NULL" << endl;
}
