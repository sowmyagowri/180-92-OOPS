//File Name: Prime L.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 3.c
//Description: 
/**
 * Generate and print prime in snake pattern of various sizes.
 */
//Last Changed: Feb 12, 2017

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

void do_prime_snake_pattern(const int n, const int start);
void compute_primes(vector<int> &primes, const int n, const int start);
void make_snake_pattern(vector< vector<int> > &snakepattern, const int n, const int start);
void print_snake_pattern(vector< vector<int> > &snakepattern, const int n);
void print_prime_snake_pattern(vector< vector<int> > &snakepattern, vector<int> &primes, const int n);

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
    do_prime_snake_pattern(300, 21);
}
void do_prime_snake_pattern(const int n, const int start)
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
    vector< vector<int> > snakepattern(1000, vector<int> (1000)); //Declare a 2D vector of spirals

    compute_primes(primes, n, start); // To determine if the number is a prime

    make_snake_pattern(snakepattern, n, start); //To populate the values (. and #) in the 2D spiral vector

    cout << "Snake pattern matrix of size " << n << " starting at " << start << "." << endl;
    cout << endl;
    print_snake_pattern(snakepattern, n); //To print the 2D diagonal matrix

    cout << "Prime Snake Pattern of size " << n << " starting at " << start << "." << endl;
    cout << endl;
    print_prime_snake_pattern(snakepattern, primes, n); //To print the 2D Prime Spirals vector

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

void make_snake_pattern(vector< vector<int> > &snakepattern, const int n, const int start)
{
    //Snake pattern starting at top left
    int i = 0;
    int j = 0;

    snakepattern[i][j] = start; //Start populating values from the top left of the matrix

    int count = 1;
    if(1==n)
        return;
    else
    {
        for (int k = 0; k <= n-1; k=k+2)
        {
            for (int iter = 1; iter <= n-1; iter++)
            {
                j=j+1;                              //Move towards the right
                snakepattern[i][j] = start+count;
                count++;
            }
                i=i+1;                              //Move one row down
                if (i == n)
                    break;
                snakepattern[i][j] = start+count;
                count++;

            for (int iter = 1; iter <= n-1; iter++)
            {
                j=j-1;                              //Move towards the left
                snakepattern[i][j] = start+count;
                count++;
            }

            i=i+1;                                  //Move one row down
            if (i == n)
                break;
            snakepattern[i][j] = start+count;
            count = count+1;
        }
        return;
    }
}

void print_snake_pattern(vector< vector<int> > &snakepattern, const int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << setw(4) << right << snakepattern[i][j] << " ";
        }
        cout << endl; //To start printing in next line if row size is reached
     }
    cout << endl;
    return;
}

void print_prime_snake_pattern(vector< vector<int> > &snakepattern, vector<int> &primes, const int n)
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
                if (snakepattern[i][j] == primes[k])
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
