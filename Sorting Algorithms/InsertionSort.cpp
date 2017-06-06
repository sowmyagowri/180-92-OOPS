#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
/*
 *Reference http://www.sanfoundry.com/cpp-program-sort-array/
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
   for (int i = 1; i < size; i++)
   {
      for (int j = i; j > 0; j--)
      {
         compare_count++;

         if (data[j] < data[j-1])
            swap(j, j-1);
         else
            break;
      }
   }
}
