#ifndef SORTEDVECTOR_H_
#define SORTEDVECTOR_H_

#include <vector>
#include <iterator>
#include "Node.h"

using namespace std;

/**
 * A sorted vector of Node objects.
 */
class SortedVector
{
public:
   SortedVector();
   virtual ~SortedVector();

   int size() const;
   bool check() const;

   void prepend(const long value);
   void append(const long value);
   void remove(const int index);
   void insert(const long value);
   Node& at(const int index);
   void reserve(const int size); //Reserve a vector of required size.

private:
   vector<Node> data;
};

#endif /* SORTEDVECTOR_H_ */
