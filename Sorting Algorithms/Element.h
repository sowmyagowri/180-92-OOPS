#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
   Element();
   Element(long val);
   Element(const Element& other);
   virtual ~Element();

   long get_value() const;

   // Access and reset the values of the static member variables.
   static long get_copy_count();
   static long get_destructor_count();
   static void reset();

   // Overloaded < operator.
   bool operator <(const Element& other);

   // Overloaded > operator.
   bool operator >(const Element& other) const;

   // Overloaded stream output insertion operator.
   friend ostream& operator <<(ostream& outs, const Element& element);

private:
   long value;

   // Static member variables, which are global to the class.
   // These variables exist independently from any Node objects.
   static long copy_count;
   static long destructor_count;
};

#endif /* DATA_H_ */
