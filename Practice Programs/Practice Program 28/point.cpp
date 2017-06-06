#include <iostream>
using namespace std;
#include "point.h"

Point::Point()
{
   _x = 0; _y = 0;
   cout << "Constructing (" << _x << ", " << _y << ")" << endl;
}

Point::Point(int x, int y)
{
   _x = x; _y = y;
   cout << "Constructing (" << _x << ", " << _y << ")" << endl;
}

int Point::x() const { return _x; }
int Point::y() const { return _y; }

Point::Point(const Point& other)
{
   cout << "Copying (" << other.x() << "," << other.y() << ")" << endl;
   _x = other._x;
   _y = other._y;
}

Point& Point::operator=(const Point& other)
{
   cout << "Assigning (" << other.x() << "," << other.y() << ") to (" << x() << "," << y() << ")" << endl;
   _x = other._x;
   _y = other._y;
}

Point::~Point()
{
   cout << "Destroying (" << x() << "," << y() << ")" << endl;
}
