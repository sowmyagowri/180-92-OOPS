#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A linked list node.
 */
class Node
{
public:

   Node(); // Default constructor
   Node(Coordinate& coordinate); //Constructor for node with border location
   Node(City& city);  //Constructor for node with city location

   void set_name(string name); //Setter function for name
   void set_state(string state); //Setter function for state
   void set_row_col(const Coordinate& coordinate); //Setter function for row and col

   string get_name() const; // Getter function for name
   string get_state() const; //Getter function for state
   int get_row() const; //Getter function for row
   int get_col() const; //Getter function for col

   // Public pointer to the next node in the list.
   Node *next;

   // Overloaded > operator.
   bool operator >(const Node& other);

   // Overloaded stream output insertion operator.
   friend ostream& operator <<(ostream& outs, const Node& node);

private:
   string name;   // city name,  or the empty string for a border location
   string state;  // city state, or the empty string for a border location
   int row;       // print row
   int col;       // print column

   void convert_coordinate(const Coordinate& coordinate);
};

#endif /* NODE_H_ */
