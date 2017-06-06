//File Name: Big Pi.c
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 4
//Description: 
/*
 Compute and print the first thousand decimal places of pi
*/
//Last Changed: Feb 17, 2017

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <mpir.h>

using namespace std;

const int MAX_ITERATIONS = 6;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/***** Function declarations here. *****/
void print(const mpf_t& pi);

/**
 * The main.
 * Set constants, initialize variables, and iterate
 * to compute pi to the desired number of decimal places.
 */
int main()
{
  mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits

  //Declare all MPIR floating-point variables
  mpf_t a0, ai, ai_m1;
  mpf_t y0, yi, yi_m1;
  mpf_t pi, var1, var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15;


  //Declare all MPIR floating-point constants in the algorithm
  mpf_t const_1, const_2, const_3, const_4, const_6;

  //Combined Initialization and Assignment of all MPIR floating-point constants to unsigned integers
  mpf_init_set_ui (const_1, 1);
  mpf_init_set_ui (const_2, 2);
  mpf_init_set_ui (const_4, 4);
  mpf_init_set_ui (const_6, 6);

  //Initialization of all MPIR floating-point variables.
  mpf_init(pi);
  mpf_init(a0);
  mpf_init(ai);
  mpf_init(ai_m1);
  mpf_init(y0);
  mpf_init(yi);
  mpf_init(yi_m1);
  mpf_init(var1);
  mpf_init(var2);
  mpf_init(var3);
  mpf_init(var4);
  mpf_init(var5);
  mpf_init(var6);
  mpf_init(var7);
  mpf_init(var8);
  mpf_init(var9);
  mpf_init(var10);
  mpf_init(var11);
  mpf_init(var12);
  mpf_init(var13);
  mpf_init(var14);
  mpf_init(var15);

  mpf_sqrt (var14, const_2); //Calculate sqrt(2)

  mpf_mul (var15, var14, const_4); //Calculate 4*sqrt(2)

  mpf_sub (a0, const_6, var15); //Calculate a[0] as 6 - 4sqrt(2)

  mpf_sub (y0, var14, const_1); //Calculate y[0] as sqrt(2) - 1

  //Set a[0] and y[0] to MPIR variables for iteration
  mpf_set (ai_m1, a0);
  mpf_set (yi_m1, y0);

  // Loop MAX_ITERATIONS times.
  for (int i = 1; i <= MAX_ITERATIONS; i++)
  {
    //Start computing y[i]
    //---------------------

    //compute y[i-1] ^ 4 into var1
    mpf_pow_ui (var1, yi_m1, 4);

    //compute (1 - var1) into var2
    mpf_sub (var2, const_1, var1);

    //To compute the 4th root of var2 compute sqrt of sqrt(var2)
    //compute sqrt(var2) into var3
    mpf_sqrt (var3, var2);
    //compute sqrt(var3) into var4.
    mpf_sqrt (var4, var3);

    mpf_sub (var5, const_1, var4); //compute 1 - 4th root of (y[i-1] ^ 4)
    mpf_add (var6, var4, const_1); //compute 1 + 4th root of (y[i-1] ^ 4)

    mpf_div (yi, var5, var6); // Calculate y[i]

    //Start computing a[i]
    //---------------------

    //compute 1 + y[i] into var7.
    mpf_add (var7, yi, const_1);

    //compute var7 ^ 4 into var8
    mpf_pow_ui (var8, var7, 4);

    //compute a[i-1] * var8 into var9. First operand in the a[i] equation is ready.
    mpf_mul (var9, ai_m1, var8);

    //compute y[i] ^ 2 into var10
    mpf_pow_ui (var10, yi, 2);

    //compute 1 + y[i] + y[i] ^ 2.
    //1 + y[i] was calculated into var7 and y[i] ^ 2 was calculated into var10. So, var7 + var10 is calculated into var11.
    mpf_add (var11, var7, var10);

    //compute y[i](1 + y[i] + y[i] ^ 2) can be calculated from var11 * y[i] into var12
    mpf_mul (var12, yi, var11);

    //compute 2 ^ (2i + 1) and assign the value to const_3
    mpf_init_set_ui (const_3, pow(2, ((2 * i) + 1)));

    //comppute 2 ^ (2i + 1) * var12 into var13. Now, the second operand in the a[i] equation is ready.
    mpf_mul (var13, var12, const_3);

    mpf_sub (ai, var9, var13); // Calculate a[i]

    mpf_set (yi_m1, yi); // Assign y[i] to y[i-1] for next iteration
    mpf_set (ai_m1, ai); // Assign a[i] to a[i-1] for next iteration
  }

  //ai is 1/pi.So, pi is 1/ai
  mpf_div (pi, const_1, ai);

  print (pi); //Call print function to print pi

  //Free the space occupied by all the MPIR variables
  mpf_clear (a0);
  mpf_clear (ai);
  mpf_clear (ai_m1);
  mpf_clear (y0);
  mpf_clear (yi);
  mpf_clear (yi_m1);
  mpf_clear (const_1);
  mpf_clear (const_2);
  mpf_clear (const_3);
  mpf_clear (const_4);
  mpf_clear (const_6);
  mpf_clear (pi);
  mpf_clear (var1);
  mpf_clear (var2);
  mpf_clear (var3);
  mpf_clear (var4);
  mpf_clear (var5);
  mpf_clear (var6);
  mpf_clear (var7);
  mpf_clear (var8);
  mpf_clear (var9);
  mpf_clear (var10);
  mpf_clear (var11);
  mpf_clear (var12);
  mpf_clear (var13);
  mpf_clear (var14);
  mpf_clear (var15);

  return 0;
}


/***** Function definitions. *****/

void print(const mpf_t& pi)
{
  size_t n_digits = PRECISION;

  //Move MPIR floating-point variable Pi to a string (character array)
  char *str_pi = (char *) malloc(n_digits*sizeof(char));
  mp_exp_t exp_ptr;
  int numericalBase = 10;
  int length;
  int int_decimal;
  mpf_get_str(str_pi, &exp_ptr, numericalBase, n_digits, pi);

  int_decimal = exp_ptr;
  length = strlen(str_pi);

  int i = 0, j = 0, k = 0, l = 0;

  cout << (str_pi[i] - 48); //To print the number before the decimal point.

  if (int_decimal == 1) //To ensure that the exponent is correctly returned as 1 in the MPIR output function.
    cout << ".";

  //Format the output
  for (i = 1; i <= length; i++)
  {
    if(i <= length-1)
    {
      cout << (str_pi[i] - 48);
      j++;
      k++;
    }

    if (j == BLOCK_SIZE)
    {
      cout << " ";
      j = 0;
    }

    if (k == LINE_SIZE)
    {
      cout << endl;
      cout << "  ";
      k = 0;
      l++;
    }

    if (l == GROUP_SIZE)
    {
      cout << endl;
      cout << "  ";
      l = 0;
    }
  }
}
