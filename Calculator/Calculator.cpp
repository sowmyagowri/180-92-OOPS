#include "Calculator.h"

int Calculator::cnt_open_braces = 0; //Initialize the static variables
int Calculator::cnt_close_braces = 0; //Initialize the static variables


//Default Constructor for Calculator
Calculator::Calculator()
{
   result = 0;
}

//Read the input
char Calculator::get_input()
{
    char ch;
    cin >> ch;
    return ch;
}

//Calculate the factor
double Calculator::factor()
{
    double result = 0;
    char ch = get_input();

    if (ch == '(')
    {
        cnt_open_braces++;
        result = expression(); //A factor can be an expression
        ch = get_input();
        if (ch != ')')
        {
            string error = string("***** Missing )");
            throw runtime_error(error.c_str());
        }
        else
        {
            cnt_close_braces++;
            char c = cin.peek();
            if (c == ')')
            {
                cnt_close_braces++;
                if (cnt_close_braces > cnt_open_braces) //check if the total number of open and close braces are same
                {
                    string error = string("**** Unexpected )");
                    throw runtime_error(error.c_str());
                }
                else
                    cnt_close_braces--;
            }
        }

    }
    else if (isdigit(ch))
    {
        cin.unget();
        cin >> result;
    }
    else
    {
        string error = string("***** Unexpected ") + ch;
        throw runtime_error(error.c_str());
    }
    return result;
}

//Calculate the term
double Calculator::term()
{
    double ch;
    double result = factor(); //A term is a factor
    ch = get_input();
    if (ch == '*' || ch == '/')
    {
        double b = term();
        if (ch == '*')
            result *= b;
        else
        {
            if (b == 0) throw runtime_error("***** Division by zero"); //Check divide-by-zero error
            result /= b;
        }
    }
    else
    {
        if (ch == '+' || ch == '-' || ch == '=' || ch == '(' || ch == ')')
            cin.unget();
        else
        {
            cin.unget();
            char ch = get_input();
            string error = string("***** Unexpected ") + ch;
            throw runtime_error(error.c_str());
        }
    }
    return result;
}

//Calculate the expression
double Calculator::expression()
{
    double result = term(); //An expression is a term
    char ch = get_input();

    if (ch == '-' || ch=='+')
    {
        double b = expression();
        if (ch == '+')
            result += b;
        else
            result -= b;
    }
    else
    {
        if (ch == '*' || ch == '/' || ch == '=' || ch == '(' || ch == ')')
            cin.unget();
        else
        {
            cin.unget();
            char ch = get_input();
            string error = string("***** Unexpected ") + ch;
            throw runtime_error(error.c_str());
        }
    }
    return result;
}
