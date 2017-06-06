#include <iostream>
#include "Element.h"

using namespace std;

long Element::copy_count;
long Element::destructor_count;

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
   value = other.value;
   copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
   destructor_count++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

void Element::reset()
{
   copy_count = 0;
   destructor_count = 0;
}

long Element::get_copy_count() { return copy_count; }

long Element::get_destructor_count() { return destructor_count; }

/**
 * Overloaded < operator
 */
bool Element::operator <(const Element &other)
{
   if (value < other.value)
      return true;
   else
      return false;
}

/**
 * Overloaded > operator for VectorSorter.cpp
 */
bool Element::operator >(const Element &other) const
{
   if (value > other.value)
      return true;
   else
      return false;
}

// Overloaded stream output insertion operator for VectorSorter.cpp
ostream& operator <<(ostream& outs, const Element& element)
{
   outs << element.value;
   return outs;
}
