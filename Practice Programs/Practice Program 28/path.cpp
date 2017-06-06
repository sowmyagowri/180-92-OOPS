/**
   This Path class uses an array, not a vector, to store the points
   of the path. Provide the missing constructor and member function.
*/
#include "path.h"

Path::Path(int n)
{
   _points = new Point[n];
   _capacity = n;
   _length = 0;
}

/*
  Produce a class Path that represents a path of points.
  Use a vector to store Point objects.
*/
void Path::add(int x, int y)
{
    if (length() < _capacity)
    {
        _points[length()] = Point(x, y);
        _length += 1;
    }
}

Point& Path::at(int index)
{
   return _points[index];
}

int Path::length()
{
   return _length;
}

void Path::print()
{
   for (int i = 0; i < length(); i++)
   {
      if (i > 0) cout << "->";
      Point& p = at(i);
      cout << "(" << p.x() << "," << p.y() << ")";
   }
   cout << endl;
}
