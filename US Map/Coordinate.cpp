#include "Coordinate.h"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

//Default Constructor for Coordinates
Coordinate::Coordinate()
{
   latitude = 0.0;
   longitude = 0.0;
}

//Constructor for Coordinates
Coordinate::Coordinate(double latitude_input, double longitude_input)
{
   latitude = latitude_input;
   longitude = longitude_input;
}

void Coordinate::set_latitude(double latitude_input) { latitude = latitude_input; } //Setter function for latitude
void Coordinate::set_longitude(double longitude_input) { longitude = longitude_input; } //Setter function for longitude

double Coordinate::get_latitude() const { return latitude; } //Getter function for latitude
double Coordinate::get_longitude() const { return longitude; } //Getter function for longitude

//Over-loading the stream extraction operator
istream& operator >>(istream& ins, Coordinate& coordinate)
{
   string str;

   getline(ins, str, ',' ); //read the input line till latitude

   coordinate.latitude = stod(str);

   getline(ins, str, '\n' ); //read the input line till end of line

   coordinate.longitude = stod(str);

   //peek and read only if EOF is reached
   char c = ins.peek();  // peek character
   if (c == ins.eof())
      ins >> str;

   return ins;
}
