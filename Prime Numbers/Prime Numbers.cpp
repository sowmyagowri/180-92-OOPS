//File Name: Prime Numbers.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 3.a
//Description: 
/*
 * Write a C++ program that uses the Sieve of Eratosthenes to compute the prime numbers under 1000 and
 * print then them to the standard output
 */
//Last Changed: Feb 10, 2017

#include <iostream>
#include <iomanip>
#include <cstring>

void compute_primes(bool prime[], int size);
void print_primes (bool prime[], int size);
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

/*
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
*/
int main() 
{
    int array_size = MAX_NUMBER+1;
    // Create a boolean array prime[]
    bool prime[array_size];

    //Initialize all entries to true. A value in prime[i] will finally be false if i is Not a prime, else will remain true.
    memset(prime, true, sizeof(prime));

    compute_primes(prime, MAX_NUMBER); // To determine if the number is a prime

    print_primes(prime, MAX_NUMBER); // To print the output table

    cout << endl << endl;
    cout << "Done!" << endl;

   return 0;
}

void compute_primes(bool prime[], int MAX_NUMBER)
{
    for (int i=2; i*i<=MAX_NUMBER; i++)
    {
        // If prime[i] is not changed, then it is a prime
        if (prime[i] == true)
        {
            // Update all multiples of i to false which means not prime.
            for (int j=i*2; j<=MAX_NUMBER; j += i)
                prime[j] = false;
        }
    }
}
void print_primes(bool prime[], int MAX_NUMBER)
{
    int column=0;

    // Print all prime numbers
    for (int i=2; i<=MAX_NUMBER; i++)
    {
        if (prime[i])
        {
            column++;
            cout << setw(3) << right << i << " ";
        }
        if (column == ROW_SIZE)
        {
            cout << endl; //To start printing in next line if row size is reached
            column = 0;
        }
    }
    return;
}
