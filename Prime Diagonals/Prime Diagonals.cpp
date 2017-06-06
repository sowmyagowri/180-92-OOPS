//File Name: Prime Diagonals.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 3.c
//Description: 
/**
 * Generate and print prime diagonal of various sizes.
 */
//Last Changed: Feb 12, 2017

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

void do_prime_diagonal(const int n, const int start);
void compute_primes(vector<int> &primes, const int n, const int start);
void make_diagonal(vector< vector<int> > &diagonal, const int n, const int start);
void print_diagonal(vector< vector<int> > &diagonal, const int n);
void print_prime_diagonal(vector< vector<int> > &spiral, vector<int> &primes, const int n);

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
    do_prime_diagonal(10, 3);
}
void do_prime_diagonal(const int n, const int start)
{
    //To check if start value is between 0 and 50
    if (start <= 0)
    {
        cout << "***** Error: Starting value " << start << " < 1 or > 50" << endl;
        cout << endl;
        return;
    }

    cout << endl;

    vector<int> primes; //Declare a 1D vector of primes

    //vector< vector<int> >  vector_name(rowsize, vector<int> (colsize, value)); //2d Vector declaration syntax
    vector< vector<int> > diagonal(1000, vector<int> (1000)); //Declare a 2D vector of spirals

    compute_primes(primes, n, start); // To determine if the number is a prime

    make_diagonal(diagonal, n, start); //To populate the values (. and #) in the 2D spiral vector

    cout << "Diagonal matrix of size " << n << " starting at " << start << "." << endl;
    cout << endl;
    print_diagonal(diagonal, n); //To print the 2D diagonal matrix

    cout << "Prime Diagonal of size " << n << " starting at " << start << "." << endl;
    cout << endl;
    print_prime_diagonal(diagonal, primes, n); //To print the 2D Prime Spirals vector

    return;
}

void compute_primes(vector<int> &primes, const int n, const int start)
{
    int max_number = (n*n) + start - 1;
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

void make_diagonal(vector< vector<int> > &diagonal, const int n, const int start)
{
    //Diagonal starting at top left
    int i = 0;
    int j = 0;

    diagonal[i][j] = start; //Start populating values from top left of the matrix

    int count = 1;
    if(1==n)
        return;
    else
    {
        //To populate from top left of the matrix towards the central diagonal
        for (int k = 1; k <= n-1; k=k+1)
        {
            i=k;j=0;                                      //start each diagonal at left edge
            diagonal[i][j] = start+count;
            count = count+1;
            for (int iter = 1; iter <= k; iter++)
            {
                i=i-1;j=j+1;                              //Move up diagonally
                diagonal[i][j] = start+count;
                count = count+1;
            }
        }

        //To populate after the central diagonal towards the bottom right
        for (int k = 1; k <= n-1; k=k+1)
        {
            i=n-1;j=k;                                    //start each diagonal at bottom edge
            diagonal[i][j] = start+count;
            count = count+1;
            if(k==n-1)
                return;
            else
            {
                for (int iter = 1; iter <= n-k-1; iter++)
                {
                    i=i-1;j=j+1;                          //Move up diagonally
                    diagonal[i][j] = start+count;
                    count = count+1;
                }
            }
        }

        return;
    }
}

void print_diagonal(vector< vector<int> > &diagonal, const int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << setw(4) << right << diagonal[i][j] << " ";
        }
        cout << endl; //To start printing in next line if row size is reached
     }
    cout << endl;
    return;
}

void print_prime_diagonal(vector< vector<int> > &diagonal, vector<int> &primes, const int n)
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
                if (diagonal[i][j] == primes[k])
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
