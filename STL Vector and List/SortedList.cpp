#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

/**
 * Default constructor.
 * Reset the global Node counters.
 */
SortedList::SortedList()
{
   Node::reset();
}

/**
 * Destructor.
 * Reset the global Node counters.
 */
SortedList::~SortedList()
{
   Node::reset();
}

/**
 * @return the size of the data list.
 */
int SortedList::size() const { return data.size(); }

/**
 * Check that the data is sorted.
 * @return true if sorted, false if not.
 */
bool SortedList::check()
{
   if (data.size() == 0) return true;

   list<Node>::iterator it = data.begin();
   list<Node>::iterator prev = it;

   it++;

   // Ensure that each node is greater than the previous node.
   while ((it != data.end()) && (*it > *prev))
   {
      prev = it;
      it++;
   }

   return it == data.end();  // Good if reached the end.
}

/**
 * Insert a new node at the beginning of the data list.
 * @param value the new node's value.
 */
void SortedList::prepend(const long value)
{
   data.push_front ( Node(value) );
}

/**
 * Append a new node at the end of the data list.
 * @param value the new node's value.
 */
void SortedList::append(const long value)
{
   data.push_back ( Node(value) );
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedList::remove(const int index)
{
   if (index <= data.size() / 2)
   {
      list<Node>::iterator it = data.begin();
      advance(it, index);
      data.erase (it );
      return;
   }
   else
   {
      list<Node>::reverse_iterator rit = data.rbegin();
      advance(rit, (data.size() - index - 1));
      data.erase ((++rit).base());
      return;
   }
}

/**
 * Insert a new node into the data list at the
 * appropriate position to keep the list sorted.
 */
void SortedList::insert(const long value)
{
   int inserted = 0;

   for (list<Node>::iterator it = data.begin(); it != data.end(); it++)
   {
      if ( it->get_value() > value )
      {
         data.insert ( it , Node(value) );
         inserted = 1;
         break;
      }
   }

   if ( inserted == 0)
      data.push_back ( Node(value) );
}

/**
 * Return the data node at the indexed position.
 * @param the index of the node.
 * @return a copy of the data node.
 */
Node& SortedList::at(const int index)
{
   if (index <= data.size() / 2)
   {
      list<Node>::iterator it = data.begin();
      advance(it, index);
      return *it;
   }
   else
   {
      list<Node>::reverse_iterator rit = data.rbegin();
      advance(rit, (data.size() - index - 1));
      return *((++rit).base());
   }
}
