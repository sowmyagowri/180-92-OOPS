#include "Node.h"
#include "Element.h"

//Default Constructor for Node
Node::Node()
{
   Element();
   next = NULL;
}

//Constructor for node with input element object
Node::Node(const Element& input)
{
   element = input;
   next = NULL;
}

//Getter function for data value of element object
int Node::get_value() const { return element.get_value(); }
