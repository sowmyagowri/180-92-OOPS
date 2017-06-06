//File Name: Practice Program 25.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 25
//Description: 
/*
   Compute the midpoint between this point and another point.
   @param other the other point
   @return the point halfway between them.
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

/**
   Compute the midpoint between this point and another point.
   @param other the other point
   @return the point halfway between them.
*/
Point Point::midpoint(Point other)
{
    double xdistance = (x + other.x) / 2.0;
    double ydistance = (y + other.y) / 2.0;

    return Point(xdistance, ydistance);
}


int main()
{
   Point p(1, 2);
   Point q(4, 6);
   Point r = p.midpoint(q);
   cout << r.get_x() << " " << r.get_y() << endl;
   cout << "Expected: 2.5 4" << endl;
   Point o(0, 0);
   r = p.midpoint(o);
   cout << r.get_x() << " " << r.get_y() << endl;
   cout << "Expected: 0.5 1" << endl;

   return 0;
}
