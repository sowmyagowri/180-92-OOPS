#include "path.h"
/*
  Provide a function backtrack that, given a path, produces and prints
  a path that starts like the given path and then goes back to
  the beginning. For example, when given the path (1,2)->(3,4)->(5,6)
  you should produce and print (1,2)->(3,4)->(5,6)->(3,4)->(1,2).

  DO NOT COPY the Path parameter into the function. Use a reference
  parameter.

  DO NOT COPY Point objects. Note that Point::at(int) returns a
  reference, and Point::add(Point&) receives a reference.

  The Point class is instrumented to print messages for all copies.
*/
void backtrack(Path& p)
{
   for (int i = p.length() - 2; i >= 0; i--)
       p.add(p.at(i));
   p.print();
}

