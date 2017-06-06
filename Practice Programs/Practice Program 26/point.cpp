#include "point.h"

Point::Point(int x, int y) { _x = x; _y = y; }
int Point::x() const { return _x; }
int Point::y() const { return _y; }
