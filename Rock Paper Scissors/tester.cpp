//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 10 (Calculator)
//Description: Write a Calculator class that prompts for and evaluates arithmetic expressions, and prints their results
//Last Changed: Apr 10, 2017

#include <iostream>
#include "calculator.h"

using namespace std;

int main()
{
    Calculator calculator;
    cout << "Expression? ";
    calculator.calculator();
    return 0;
}
