#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:

   Node(); // Default constructor
   Node(const Element& element); //Constructor for node

   int get_value() const; // Getter function for data value of the element object

   // Public pointer to the next node in the list.
   Node *next;

   Element element;
};

#endif /* NODE_H_ */
