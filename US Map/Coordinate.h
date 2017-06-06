#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate
{
public:

   Coordinate(); // Default constructor
   Coordinate(double latitude_input, double longitude_input); //Constructor for coordinates

   void set_latitude(double latitude_input); // Setter function for latitude
   void set_longitude(double longitude_input); // Setter function for longitude

   double get_latitude() const; // Getter function for latitude
   double get_longitude() const; // Getter function for longitude

   // Overloaded input stream extraction operator.
   friend istream& operator >>(istream& ins, Coordinate& coordinate);

   // Constants for this app's input data.
   static const double MAX_LATITUDE;
   static const double MIN_LONGITUDE;

private:
   double latitude;
   double longitude;
};

#endif /* COORDINATE_H_ */
