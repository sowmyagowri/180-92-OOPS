#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <iostream>
#include <string>

using namespace std;

class Calculator
{
    public:

        Calculator(); //Default Constructor
        double get_result() const; //Getter function for result

        double expression(); //Function to calculate the expression
        double term(); //Function to calculate the term
        double factor(); //Function to calculate the factor

        char get_input(); //Function to read from cin

        static int cnt_open_braces; //Static variables to keep a count of open braces
        static int cnt_close_braces; //Static variables to keep a count of close braces

    private:
        int result;
};

#endif /* CALCULATOR_H_ */
