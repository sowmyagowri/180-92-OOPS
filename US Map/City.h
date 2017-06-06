#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>

#include "Coordinate.h"

using namespace std;

/**
 * City data.
 */
class City
{
public:

   City(); //Default Constructor
   City(string name_input, string state_input); //Constructor for city to print the name and state
   City(string name_input, string state_input, double latitude_input, double longitude_input); //Constructor for city

   void set_name(string name_input); //Setter function for name
   void set_state(string state_input); //Setter function for state
   void set_coordinate(double latitude_input, double longitude_input); //Setter function for coordinate

   string get_name() const; //Getter function for name
   string get_state() const; //Getter function for state
   Coordinate get_coordinate() const; //Getter function for coordinate

   // Overloaded stream I/O operators.
   friend ostream& operator <<(ostream& outs, const City& city);
   friend istream& operator >>(istream& ins, City& city);

private:
   string name;
   string state;
   Coordinate coordinate;
};

#endif /* CITY_H_ */
