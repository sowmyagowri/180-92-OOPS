#include "QuickSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSortOptimal::QuickSortOptimal(string name) : QuickSorter(name) {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
   int mid = (left+right)/2;

   compare_count++;
   if ( data[mid] < data[left] )
      swap(left,mid);

   compare_count++;
   if ( data[right] < data[left] )
      swap(left,right);

   compare_count++;
   if ( data[right] < data[mid] )
      swap(mid,right);

   swap(left,mid); //The left-most element is always the pivot

   return data[left];
}
