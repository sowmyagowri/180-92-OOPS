//File Name: Primes.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 3.c
//Description: 
/**
 * Generate and print prime in 'L' pattern of various sizes.
 */
//Last Changed: Feb 12, 2017

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

void do_prime_pattern(const int n, const int start);
void compute_primes(vector<int> &primes, const int n, const int start);
void make_spiral(vector< vector<int> > &spiral, const int n, const int start);
void print_pattern(vector< vector<int> > &spiral, const int n);
void print_prime_pattern(vector< vector<int> > &spiral, vector<int> &primes, const int n);

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
    do_prime_pattern(9, 11);
}
void do_prime_pattern(const int n, const int start)
{
    if (start <= 0)
    {
        cout << "***** Error: Starting value " << start << " < 1" << endl;
        cout << endl;
        return;
    }

    if (start % 2 == 0) //To check if the input starting number is odd
    {
        cout << "***** Error: Start " << start << " must be odd." << endl;
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

    vector<int> primes; //Declare a 1D vector of primes

    vector< vector<int> > numbers; //Declare a 2D vector of spirals

    //vector< vector<int> >  vector_name(rowsize, vector<int> (colsize, value)); //2d Vector declaration syntax
    vector< vector<int> > spiral(1000, vector<int> (1000)); //Declare a 2D vector of spirals

    compute_primes(primes, n, start); // To determine if the number is a prime

    make_spiral(spiral, n, start); //To populate the values (. and #) in the 2D spiral vector

    cout << "Spiral of size " << n << " starting at " << start << "." << endl;
    cout << endl;
    print_pattern(spiral, n); //To print the 2D diagonal matrix

    cout << "Prime Spiral of size " << n << " starting at " << start << "." << endl;
    cout << endl;
    print_prime_pattern(spiral, primes, n); //To print the 2D Prime Spirals vector

    return;
}

void compute_primes(vector<int> &primes, const int n, const int start)
{
    int max_number = (4*n*n) + start - 1;
    int array_size = max_number + 1;

    //An intermediate vector to determine primes using Sieve_of_Eratosthenes
    //All entries have been initialized to true. A value in prime[i] will finally be false if i is Not a prime, else will remain true.
    vector<bool> numbers (array_size, 1);

    for (int i=2; i*i<=max_number; i++)
    {
       // If prime[i] is not changed, then it is a prime
       if (numbers[i] == true)
       {
           // Update all multiples of i to false which means not prime.
           for (int j=i*2; j<=max_number; j += i)
               numbers[j] = false;
        }
     }

    // Populate only the prime numbers in a vector
    for (int i=2; i<=max_number; i++)
    {
        if (numbers[i])
        {
            primes.push_back(i);
        }
     }
     return;
}

void make_spiral(vector< vector<int> > &spiral, const int n, const int start)
{
    //Determine the size of the matrix
    int i = (n-1)/2;
    int j = (n-1)/2;

    int count = 0;
    if((start % 5) == 0)
    {
        count +=2;
        spiral[i][j] = start + 2; //Start populating values from the center of the matrix
    }
    else
        spiral[i][j] = start;

    count +=2;

    if(1==n)
        return;
    else
    {
        for (int k = 3; k <= n; k=k+2)
        {
            j=j+1;
            if((( start + count ) % 5) == 0)
                {
                    count +=2;
                    spiral[i][j] = start + count;
                }
                else
                    spiral[i][j] = start + count;

            count +=2;
            for (int iter = 1; iter <= k-2; iter++)
            {
                i=i-1;                                  //Move up
                if((( start + count ) % 5) == 0)
                {
                    count +=2;
                    spiral[i][j] = start + count;
                }
                else
                    spiral[i][j] = start + count;
                count +=2;
            }
            for (int iter = 1; iter <= k-1; iter++)
            {
                j=j-1;                                  //Start moving left (anti-clockwise)
                if((( start + count ) % 5) == 0)
                {
                    count +=2;
                    spiral[i][j] = start + count;
                }
                else
                    spiral[i][j] = start + count;
                count +=2;
            }
            for (int iter = 1; iter <= k-1; iter++)
            {
                i=i+1;                                  //Move down
                if((( start + count ) % 5) == 0)
                {
                    count +=2;
                    spiral[i][j] = start + count;
                }
                else
                    spiral[i][j] = start + count;
                count +=2;
            }
            for (int iter = 1; iter <= k-1; iter++)
            {
                j=j+1;                                  //Start moving right
                if((( start + count ) % 5) == 0)
                {
                    count +=2;
                    spiral[i][j] = start + count;
                }
                else
                    spiral[i][j] = start + count;
                count +=2;
            }
        }
        return;
    }
}

void print_pattern(vector< vector<int> > &spiral, const int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << setw(4) << right << spiral[i][j] << " ";
        }
        cout << endl; //To start printing in next line if row size is reached
     }
    cout << endl;
    return;
}

void print_prime_pattern(vector< vector<int> > &spiral, vector<int> &primes, const int n)
{
    int hash_printed;
    for (int i=0; i<n; i++)
    {
        hash_printed = 0;
        for (int j=0; j<n; j++)
        {
            hash_printed = 0;
            for (int k=0; k<=primes.size(); k++)
            {
                if (spiral[i][j] == primes[k])
                {
                    cout << "#";
                    hash_printed = 1;
                    break;
                }
            }
            if (hash_printed == 0) //Print a "." if the number isn't a prime
                cout << ".";
        }
        cout << endl; //To start printing in next line for every new row
    }
    cout << endl;
    return;

}
