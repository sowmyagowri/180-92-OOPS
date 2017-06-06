//File Name: Rational Numbers.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 5
//Description: 
//Last Changed: Feb 24, 2017

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int gcd(int a, int b);

//ADT
class Rational
{
   public:
      Rational();
      Rational(int a);
      Rational(int a, int b);
      void set_a(int a);
      void set_b(int b);
      int get_a() const;
      int get_b() const;
      friend Rational operator +(const Rational& r1, const Rational& r2); //Over-loading the addition operator
      friend Rational operator -(const Rational& r1, const Rational& r2); //Over-loading the subtraction operator
      friend Rational operator *(const Rational& r1, const Rational& r2); //Over-loading the multiplication operator
      friend Rational operator /(const Rational& r1, const Rational& r2); //Over-loading the division operator

      friend ostream& operator <<(ostream& outs, const Rational& r); //Over-loading the stream extraction operator
      friend istream& operator >>(istream& outs, Rational& r); //Over-loading the stream insertion operator

   private:
      int a, b;  // numerator and denominator
};




const string INPUT_FILE_NAME = "rational.in";

//Function Declaration
void do_problem(const Rational r1, const Rational r2, const char op);
Rational evaluate(const Rational r1, const Rational r2, const char op);

int main()
{
   // Open the input file.
   ifstream input;
   //input.open(INPUT_FILE_NAME);
   input.open("rational.in.txt");

   if (input.fail())
   {
      cout << "Failed to open " << INPUT_FILE_NAME << endl;
      return -1;
   }

   Rational r1, r2;
   char op;
   do
   {
      input >> r1 >> op >> r2;
      do_problem(r1, r2, op);
      int c = input.peek();  // peek character for eof
      if ( c == EOF )
         break;
   } while (!input.eof());

   cout << endl << "Done!" << endl;
   return 0;
}

//Default constructor for rational number 0/0
Rational::Rational() : a(0), b(0)
{

}

//Constructor for whole number. Rational number of type a/1
Rational::Rational(int avalue)
{
   a = avalue;
   b = 1;
}

//Constructor for rational number of type a/b
Rational::Rational(int avalue, int bvalue)
{
   a = avalue;
   b = bvalue;
}

void Rational::set_a(int numerator) { a = numerator; }
void Rational::set_b(int denominator) { b = denominator; }
int Rational::get_a() const { return a; } //Getter function for numerator
int Rational::get_b() const { return b; } //Getter function for denominator

Rational operator +(const Rational& r1, const Rational& r2)
{
   Rational output;
   output.a = (r1.a * r2.b) + (r1.b * r2.a);
   output.b = r1.b * r2.b;
   if (output.b == 0)
       output.a = 0;
   return output;
}

Rational operator -(const Rational& r1, const Rational& r2)
{
   Rational output;
   output.a = (r1.a * r2.b) - (r1.b * r2.a);
   output.b = r1.b * r2.b;
   if (output.b == 0)
       output.a = 0;
   return output;
}
Rational operator *(const Rational& r1, const Rational& r2)
{
   Rational output;
   output.a = r1.a * r2.a;
   output.b = r1.b * r2.b;
   if (output.b == 0)
       output.a = 0;
   return output;
}

Rational operator /(const Rational& r1, const Rational& r2)
{
   Rational output;
   output.a = r1.a * r2.b;
   output.b = r1.b * r2.a;
   if (output.b == 0)
      output.a = 0;
   return output;
}

istream& operator >>(istream& ins, Rational& input)
{
   int a, b, temp;
   int set = 0;
   char c, ch;

   ins >> ws;  // eat up any leading white spaces
   c = ins.peek();  // peek character

   switch(c)
   {
      case '(' : //the input is of the form (a/b)
         ins >> ch >> ws >> a >> ws >> ch;
         if (ch == '/')
         {
            ins >> ws >> b;
            input.a = a;
            input.b = b;
            ins >> ws >> ch;
            set = 1;
         }
         break;
      default: //the input is either a whole number or a mixed number
         ins >> temp>> ws;
         c = ins.peek();  // peek character

         if (c == '(') //input is a mixed number
         {
            ins >> ch >> ws >> a >> ws >> ch >> ws >> b;
            a += temp*b;
            input.a = a;
            input.b = b;
            ins >> ws >> ch;
            set = 1;
            break;
         }
   }

   ins >> ws;
   c = ins.peek();  // peek character to check if end of line is reached
   if (c == '=')
      ins >> ch;
   switch (c)
   {
      case '=' :
      case '+' :
      case '-' :
      case '*' :
      case '/' :
         if (set == 0) //input is a whole number
         {
            input.a = temp;
            input.b = 1;
            ins >> ws;
         }
         break;
   }
   return ins;
}

ostream& operator <<(ostream& outs, const Rational& result)
{
   if (result.b == 1)
   {
      outs << result.a;
      return outs;
   }

   if (result.a == 0)
   {
      outs << 0;
      return outs;
   }

   if (result.a == result.b)
   {
      outs << 1;
      return outs;
   }

   int temp_a = result.a;
   int temp_b = result.b;
   int gcd_output = gcd (temp_a,temp_b); //function to calculate GCD
   temp_a /= gcd_output;
   temp_b /= gcd_output;
   int whole = (temp_a - (temp_a % temp_b)) / temp_b;
   int numero = temp_a % temp_b;
   if (whole == 0)
      outs << "(" << numero << "/" << temp_b << ")";
   else
      if (numero == 0)
         outs << whole;
      else
         outs << whole << "(" << numero << "/" << temp_b << ")";
   return outs;
}

//Recursive implementation of Euclid's GCD algorithm
int gcd(int temp_a, int temp_b)
{
   if (temp_b == 0)
      return temp_a;
   else
      gcd(temp_b, temp_a % temp_b);
}

void do_problem(const Rational r1, const Rational r2, const char op)
{
   Rational result = evaluate(r1, r2, op);
   cout << r1 << " " << op << " " << r2 << " = " << result << endl;
}

Rational evaluate(const Rational r1, const Rational r2, const char op)
{
   Rational evaluate_output;

   if ( op == '+')
      evaluate_output = r1 + r2;

   if ( op == '-')
      evaluate_output = r1 - r2;

   if ( op == '*')
      evaluate_output = r1 * r2;

   if ( op == '/')
      evaluate_output = r1 / r2;

   return evaluate_output;
}
