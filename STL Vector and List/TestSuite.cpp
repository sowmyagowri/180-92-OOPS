#include <string>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

/**
 * Test function: Insert new nodes at the beginning of the data vector.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_prepends(SortedVector& sv, const int size)
{
   sv.reserve(size);
   for (int i=1; i<=size; i++)
      sv.prepend(size - i);
}

/**
 * Test function: Insert new nodes at the beginning of the data list.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_prepends(SortedList& sl, const int size)
{
   for (int i=1; i<=size; i++)
      sl.prepend(size - i);
}

/**
 * Test function: Append new nodes at the end of the data vector.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_appends(SortedVector& sv, const int size)
{
   sv.reserve(size);
   for (int i=0; i<size; i++)
      sv.append(i);
}

/**
 * Test function: Append new nodes at the end of the data list.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_appends(SortedList& sl, const int size)
{
   for (int i=0; i<size; i++)
      sl.append(i);
}

/**
 * Test function: Access nodes in the data vector.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 * @throw an exception if anything goes wrong.
 */
void vector_gets(SortedVector& sv, const int size) throw (string)
{
   // First fill the vector data.
   sv.reserve(size);
   vector_appends(sv, size);
   Node::reset();

   // Loop to access nodes at random positions.
   for (int i = 0; i < GETS_COUNT; i++)
   {
      srand(time(NULL));
      int index = rand() % size;
      long value = sv.at(index).get_value();

      // Make sure we got the correct node.
      if (index != value) throw string("Vector data mismatch!");
   }
}

/**
 * Test function: Access nodes in the data list.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 * @throw an exception if anything goes wrong.
 */
void list_gets(SortedList& sl, const int size) throw (string)
{
   // First fill the list data.
   list_appends(sl, size);
   Node::reset();

   // Loop to access nodes at random positions.
   for (int i = 0; i < GETS_COUNT; i++)
   {
      srand(time(NULL));
      int index = rand() % size;
      long value = sl.at(index).get_value();

      // Make sure we got the correct node.
      if (index != value) throw string("List data mismatch!");
   }
}

/**
 * Test function: Remove all the nodes from the data vector
 *                one at a time.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_removes(SortedVector& sv, const int size)
{
   // First fill the vector data.
   sv.reserve(size);
   vector_appends(sv, size);
   Node::reset();

   // Loop to remove a node at a random position
   // one at a time until the nodes are all gone.
   while (sv.size() > 0)
   {
      srand(time(NULL));
      int index = rand() % sv.size();
      sv.remove (index);
   }
}

/**
 * Test function: Remove all the nodes from the data list
 *                one at a time.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_removes(SortedList& sl, const int size)
{
   // First fill the list data.
   list_appends(sl, size);
   Node::reset();

   while (sl.size() > 0)
   {
      srand(time(NULL));
      int index = rand() % sl.size();
      sl.remove (index);
   }
}

/**
 * Test function: Insert random values into the sorted data vector.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_inserts(SortedVector& sv, const int size)
{
   sv.reserve(size);
   while (sv.size() < size)
   {
      srand(time(NULL));
      int value = rand() % size;
      sv.insert (value);
   }
}

/**
 * Test function: Insert random values into the sorted data list.
 * @param sl the linked list test subject.
 * @param size the data size of the linked list.
 */
void list_inserts(SortedList& sl, const int size)
{
   while (sl.size() < size)
   {
      srand(time(NULL));
      int value = rand() % size;
      sl.insert (value);
   }
}
