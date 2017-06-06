#ifndef QUEUE_H
#define QUEUE_H

#include <string>

using namespace std;

struct QueueNode
{
   string data;
   QueueNode *link;
};

typedef QueueNode* QueueNodePtr;

class Queue
{
 public:
   Queue();
   //Initializes the object to an empty queue.
   ~Queue();
   void add(string item);
   //Postcondition: item has been added to the back of the queue.
   string remove();
   //Precondition: The queue is not empty.
   //Returns the item at the front of the queue and
   //removes that item from the queue.
   bool empty() const;
   //Returns true if the queue is empty. Returns false otherwise.
 private:
   Queue(const Queue& aQueue);
   QueueNodePtr front;//Points to the head of a linked list.
   //Items are removed at the head
   QueueNodePtr back;//Points to the node at the other end of the
   //linked list. Items are added at this end.
};
#endif //QUEUE_H
