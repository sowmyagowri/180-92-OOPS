#ifndef NODE_H_
#define NODE_H_

/**
 * A node for the sorted vector and sorted linked list.
 */
class Node
{
public:
   Node(const long the_value);
   Node(const Node& other);
   virtual ~Node();

   long get_value() const;

   // Access and reset the values of the static member variables.
   static long get_constructor_count();
   static long get_copy_count();
   static long get_destructor_count();
   static void reset();

   // Overloaded > operator
   bool operator >(const Node& other) const;

private:
   long value;

   // Static member variables, which are global to the class.
   // These variables exist independently from any Node objects.
   static long constructor_count;
   static long copy_count;
   static long destructor_count;
};

#endif /* NODE_H_ */
