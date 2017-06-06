//File Name: Practice Program 24.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 24
//Description: 
/*
   Compute the distance between this point and another point.
   @param other the other point
   @return the distance between them.
*/
//Last Changed: Feb 25, 2017

#include <iostream>
#include <cmath>

using namespace std;

#include "point.h"

Point::Point(double xvalue, double yvalue)
{
   x = xvalue;
   y = yvalue;
}

double Point::get_x() { return x; }
double Point::get_y() { return y; }

double Point::distance(Point other)
{
    double xdistance = pow((x - other.x), 2.0);
    double ydistance = pow((y - other.y), 2.0);

    double distance = sqrt(xdistance + ydistance);
    return distance;
}

int main()
{
   Point p(1, 2);
   Point q(4, 6);
   cout << p.distance(q) << endl;
   cout << "Expected: 5" << endl;
   Point o(0, 0);
   cout << p.distance(o) << endl;
   cout << "Expected: " << sqrt(5) << endl;

   return 0;
}
