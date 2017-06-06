#include "City.h"

 //Default Constructor for City
City::City() : coordinate()
{
   name = " ";
   state = " ";
}

//Constructor for City with name and state. This object will be used for printing the map.
City::City(string name_input, string state_input) : coordinate()
{
   name = name_input;
   state = state_input;
}

//Constructor for City
City::City(string name_input, string state_input, double latitude_input, double longitude_input) : coordinate(latitude_input, longitude_input)
{
   name = name_input;
   state = state_input;
}

void City::set_name(string name_input) { name = name_input; } //Setter function for name
void City::set_state(string state_input) { state = state_input; } //Setter function for state
void City::set_coordinate(double latitude_input, double longitude_input) { Coordinate(latitude_input, longitude_input);} //Setter function for coordinate

string City::get_name() const { return name; } //Getter function for name
string City::get_state() const { return state; } //Getter function for state
Coordinate City::get_coordinate() const { return coordinate; } //Getter function for coordinate

// Overloaded stream output insertion operator.
ostream& operator <<(ostream& outs, const City& city)
{
   outs << city.name << " " << city.state;
   return outs;
}

// Overloaded stream input extraction operator.
istream& operator >>(istream& ins, City& city)
{
   string str;

   getline(ins, city.name, ',' ); //read the input line till name

   getline(ins, city.state, ',' ); //read the input line till state

   ins >> city.coordinate; //read the coordinates

   return ins;
}
