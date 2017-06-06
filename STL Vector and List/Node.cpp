#include <iostream>
#include "Node.h"

using namespace std;

// Static member variables, which are global to the class.
// These variables exist independently from any Node objects.
long Node::constructor_count;
long Node::copy_count;
long Node::destructor_count;

//Default Constructor for Node
Node::Node(const long the_value)
{
   value = the_value;
   constructor_count++;
}

//Copy constructor for Node
Node::Node(const Node& other)
{
   value = other.value;
   copy_count++;
}

// Overloaded > operator
bool Node::operator >(const Node& other) const
{
   if (value >= other.value)
      return true;
   else
      return false;
}

//Destructor for node
Node::~Node()
{
   destructor_count++;
}

long Node::get_value() const { return value; } //Getter function for value
long Node::get_constructor_count() { return constructor_count; } //Getter function for constructor count
long Node::get_copy_count() { return copy_count; } //Getter function for copy count
long Node::get_destructor_count() { return destructor_count; } //Getter function for destructor count

void Node::reset() //Reset all the counters
{
   constructor_count = 0;
   copy_count = 0;
   destructor_count = 0;
}
