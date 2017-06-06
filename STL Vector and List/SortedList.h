#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

#include <list>
#include <iterator>
#include "Node.h"

using namespace std;

/**
 * A sorted linked list of Node objects.
 */
class SortedList
{
public:
   SortedList();
   virtual ~SortedList();

   int size() const;
   bool check();

   void prepend(const long value);
   void append(const long value);
   void remove(const int index);
   void insert(const long value);
   Node& at(const int index);

private:
   list<Node> data;
};

#endif /* SORTEDLIST_H_ */
