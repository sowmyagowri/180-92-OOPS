//File Name: Spiral.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 3.b
//Description: 
/*
 *Generate and print spirals of various sizes.
 */
//Last Changed: Feb 12, 2017

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

void do_spiral(const int n, const int start);
void make_spiral(int spiral[MAX_SIZE][MAX_SIZE], const int n, const int start);
void print_spiral(int spiral[MAX_SIZE][MAX_SIZE], const int n);
/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
}

void do_spiral(const int n, const int start)
{
    cout << "Spiral of size " << n << " starting at " << start << endl;
    if (n > MAX_SIZE) //To check if input size is within the max size limit of 101
    {
        cout << "***** Error: Size " << n << " greater than " << MAX_SIZE << " ." << endl;
        cout << endl;
        return;
    }
    if (start > MAX_START) //To check if input starting number is within the max starting limit of 50
    {
        cout << "***** Error: Start " << start << " greater than " << MAX_START << " ." << endl;
        cout << endl;
        return;
    }
    if (n % 2 == 0) //To check if the input size is odd
    {
        cout << "***** Error: Size " << n << " must be odd." << endl;
        cout << endl;
        return;
    }

    cout << endl;
    int spiral[MAX_SIZE][MAX_SIZE]; //Declare the 2D array with the maximum size
    make_spiral(spiral, n, start); //To populate the values in spiral
    print_spiral(spiral, n); //To print the spiral
    return;
}

/*
spiral index stepping algorithm

if size = 1
    count=1;
    i=1; j=1;
else
    for k=3, 5, 7, ... upto size of spiral
        increment j
        then
        decrement i for k-2 iter
        then
        decrement j for k-1 iter
        then
        increment i for k-1 iter
        then
        increment j for k-1 iter
*/

void make_spiral(int spiral[MAX_SIZE][MAX_SIZE], const int n, const int start)
{
    //Determine the size of the matrix
    int i = (n-1)/2;
    int j = (n-1)/2;

    spiral[i][j] = start; //Start populating values from the center of the matrix

    int count = 1;
    if(1==n)
        return;
    else
    {
        for (int k = 3; k <= n; k=k+2)
        {
            j=j+1;                                      //Move right initially
            spiral[i][j] = start+count;
            count++;
            for (int iter = 1; iter <= k-2; iter++)
            {
                i=i-1;                                  //Move up
                spiral[i][j] = start+count;
                count++;
            }
            for (int iter = 1; iter <= k-1; iter++)
            {
                j=j-1;                                  //Start moving left (anti-clockwise)
                spiral[i][j] = start+count;
                count++;
            }
            for (int iter = 1; iter <= k-1; iter++)
            {
                i=i+1;                                  //Move down
                spiral[i][j] = start+count;
                count++;
            }
            for (int iter = 1; iter <= k-1; iter++)
            {
                j=j+1;                                  //Start moving right
                spiral[i][j] = start+count;
                count++;
            }
        }
        return;
    }
}

void print_spiral(int spiral[MAX_SIZE][MAX_SIZE], const int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << setw(3) << right << spiral[i][j] << " ";
        }
        cout << endl; //To start printing in next line if row size is reached
     }
    cout << endl;
    return;
}
