#ifndef PATH_H
#define PATH_H
#include <vector>
#include <iostream>

using namespace std;

#include "point.h"

/*
  A Path represents a path of points.
*/
class Path
{
 public:
   /**
      Creates a path with up to n points.
   */
   Path(int n);
   /**
      Adds the given point to the end of this path if there is space.
   */
   void add(int x, int y);
   /**
      Yields a reference to the point with the given index.
      The index must be >= 0 and < length().
   */
   Point& at(int index);
   /**
      The length of this path.
   */
   int length();
   /**
      Prints this path.
   */
   void print();
 private:
   Point* _points;
   int _capacity;
   int _length;
};
#endif
