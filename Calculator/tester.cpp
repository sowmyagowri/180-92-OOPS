//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 10
//Description: 
//Last Changed: Apr 12, 2017

#include <iostream>
#include <cctype>
#include "calculator.h"

using namespace std;

int main()
{
    Calculator calculator;
    cout <<"Expression? ";
    char input = cin.peek();

    while (input != '.')
    {
        try
        {
            cout << calculator.expression() << endl;
        }
        catch(exception &error)
        {
            cout << error.what();
            string str;
            getline(cin,str,'\n'); //read and ignore the rest of the input in case of error
            cout << endl;
        }

        cout << endl << "Expression? ";
        input = cin.peek();
        if (input == '=')
            cin >> input;
    };

    cout << endl << "Done!";
    return 0;
}
