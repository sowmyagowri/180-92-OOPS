//File Name: Practice Program 13.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Problem: 13
//Description: 
//Last Changed: Feb 11, 2017

#include <iostream>
#include <vector>
using namespace std;

void replavg(double a[], int n);

void print(double v[], int size)
{
   cout << "{";
   for (int i = 0; i < size; i++)
   {
      cout << v[i];
      if (i < size - 1) cout << ", ";
   }
   cout << "}" << endl;
}

int main()
{
   double values[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
   replavg(values, sizeof(values) / sizeof(values[0]));
   print(values, sizeof(values) / sizeof(values[0]));
   cout << "Expected: {3, 3.5, 1, 4.5, 5, 3.5, 7.5, 6}" << endl;

   double values2[] = { 1, -2, 3, -4, 5, -6 };
   replavg(values2, sizeof(values2) / sizeof(values2[0]));
   print(values2, sizeof(values2) / sizeof(values2[0]));
   cout << "Expected: {1, 2, -3, 4, -5, -6}" << endl;

   double values3[] = { 1, 2 };
   replavg(values3, sizeof(values3) / sizeof(values3[0]));
   print(values3, sizeof(values3) / sizeof(values3[0]));
   cout << "Expected: {1, 2}" << endl;

   double values4[] = { 1 };
   replavg(values4, sizeof(values4) / sizeof(values4[0]));
   print(values4, sizeof(values4) / sizeof(values4[0]));
   cout << "Expected: {1}" << endl;

   double values5[] = {};
   replavg(values5, sizeof(values5) / sizeof(values5[0]));
   print(values5, sizeof(values5) / sizeof(values5[0]));
   cout << "Expected: {}" << endl;

   return 0;
}

#include <vector>
using namespace std;

/**
   Replaces each element in an array with the average of its
   neighbors. The first and last element are not changed. Do
   not declare any arrays or vectors.
   @param a an array
   @param n the length of the array
*/
void replavg(double a[], int n)
{
    double previous, current;
    if ( n <=2 )
        return;
    for (int i=1; i<n-1; i++)
     {
        if (1 == i)
            previous = a[0];
         current = (previous + a[i+1]) / 2;
         previous = a[i];
         a[i] = current;
     }
}
