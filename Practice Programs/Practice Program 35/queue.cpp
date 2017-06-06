#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "queue.h"
using namespace std;

//Uses cstddef:
Queue::Queue() : front(NULL), back(NULL)
{
   //Intentionally empty.
}

Queue::~Queue()
{
   while (!empty()) remove();
}
//Uses cstddef:
bool Queue::empty() const
{
   return (back == NULL);//front == NULL would also work
}

//Uses cstddef:
void Queue::add(string item)
{
   if (empty())
   {
      front = new QueueNode;
      front->data = item;
      front->link = NULL;
      back = front;
   }
   else
   {
      QueueNodePtr temp_ptr;
      temp_ptr = new QueueNode;
      temp_ptr->data = item;
      temp_ptr->link = NULL;
      back->link = temp_ptr;
      back = temp_ptr;
   }
}

//Uses cstdlib and iostream:
string Queue::remove()
{
   if (empty())
   {
      cout << "Error: Removing an item from an empty queue.\n";
      exit(1);
   }
   string result = front->data;
   QueueNodePtr discard;
   discard = front;
   front = front->link;
   if (front == NULL) //if you removed the last node
      back = NULL;
   delete discard;
   return result;
}
