#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
   quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{

   if (left < right)
   {
      Element& pivot = choose_pivot(left,right);

      /* Partitioning index */
      int p_index = partition(left, right, pivot);
      quicksort(left, p_index - 1);
      quicksort(p_index + 1, right);
   }
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
   return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
/*
 * Reference: D.S. Malik textbook page 557
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
   int index, smallIndex;

   smallIndex = left;

   for ( index = left + 1; index <= right; index++)
   {
      compare_count++;
      if(data[index] < pivot)
      {
         smallIndex++;
         swap(smallIndex, index);
      }
   }
   swap(left, smallIndex);
   return smallIndex;
}
