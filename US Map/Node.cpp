#include <math.h>
#include <iomanip>
#include "Node.h"

//Default Constructor for Node
Node::Node()
{
   name = "";
   state = "";
   row = 0;
   col = 0;
   next = NULL;
}

//Constructor for node with border location
Node::Node(Coordinate& coordinate)
{
   convert_coordinate(coordinate);
   name = "";
   state = "";
   next = NULL;
}

//Constructor for node with city location
Node::Node(City& city)
{
   name = city.get_name();
   state = city.get_state();
   convert_coordinate(city.get_coordinate());
   next = NULL;
}

void Node::set_name(string name_input) { name = name_input; } //Setter function for name
void Node::set_state(string state_input) { state = state_input; } //Setter function for state
void Node::set_row_col(const Coordinate& coordinate) {convert_coordinate(coordinate);} //Setter function for row and col

string Node::get_name() const { return name; } //Getter function for name
string Node::get_state() const { return state; } //Getter function for state
int Node::get_row() const { return row; } //Getter function for row
int Node::get_col() const { return col; } //Getter function for col


/**
 * Convert a coordinate's latitude and longitude
 * into a row and column, respectively, for printing.
 */
void Node::convert_coordinate(const Coordinate& coordinate)
{
   row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
   col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

/**
 * Overloaded > operator used to determine
 * where to insert a node into the linked list.
 * The list is sorted first by row and then by column.
 */
bool Node::operator >(const Node &other)
{
   if (row > other.row)
      return true;
   else
      if (row < other.row)
         return false;

   if (row == other.row)
   {
      if (col > other.col)
         return true;
      else
         return false;
   }
}

// Overloaded stream output insertion operator.
ostream& operator <<(ostream& outs, const Node& node)
{
   if (node.name == "") //Print the boundary
      outs << "#";
   else
   {
      City city(node.name, node.state); //Print the city
      outs << "*" << city;
   }

   return outs;
}
