//File Name: Program 4.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Problem: 4
//Description: 
/*
  Read a sentence; that is, a sequence of strings from cin that is
  terminated by a string ending in "." (which is a part of the sequence).
  Print out the average length of all strings, reported to two digits
  and enclosed in [], in a sentence:
  The average length is [x.yy] characters.
*/
//Last Changed: Jan 30, 2017

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string string_sequence;
int length(0);
double average(0.00), count(0.00);

int main()
{
	do
	{
		cin >> string_sequence;
		length += string_sequence.length();
		count++;
	}while ("." != string_sequence.substr(string_sequence.length( ) - 1));
	average = length / count;
	//Magic Formula to output a double value in ordinary everyday notation with two digits after the decimal point:
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	//
	cout << "The average length is [" << average << "] characters." << endl;
   return 0;
}
