//File Name: Practice Program 11.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Problem: 11
//Description: 
//Last Changed: Feb 11, 2017

#include <iostream>

double avgpos(int a[], int alen);

using namespace std;

int main() 
{
   int a[6] = { 1, 2, 4, -3, 5, -6 };
   double average = avgpos(a, 6);
   cout << average << endl;
   return 0;
}

/**
   Computes the average of all positive elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all positive elements in a, or 0 if there are none.
*/
double avgpos(int a[], int alen)
{
    int count=0, sum=0, average=0;
    for (int i=0; i<alen; i++)
    {
      if (a[i] > 0)
      {
        count++;
        sum += a[i];
      }
     }
    if (sum > 0)
        average = sum / count;
    return average;

}
