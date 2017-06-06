#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
/*
 * Reference: ftp://ftp.cs.princeton.edu/pub/cs226/linksort/shellsort.c
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
   int h = 1; //shellsort increment
   int done; //flag to stop pass early if no exchanges

   // determine the initial increment sequence h
   for (h = 1; h <= data.size() / 3; h = 3*h + 1);

   while (h >= 1)
   {
      done = 0;
      while (done != 1)
      {
         done = 1;
         for (int i = data.size() - 1; i >= h; i--)
         {
            compare_count++;
            if (data[i] < data[i-h])
            {
               swap(i,i-h);
               done = 0;
            }
         }
      }
      h /= 3;
   }
}
