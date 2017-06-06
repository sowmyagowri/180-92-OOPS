//File Name: Program 1.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Problem: 1
//Description: 
/*
  Read a sequence of integers from cin that is terminated by
  a zero (which is not a part of the sequence). Print out the
  average of the first and last value of the sequence.
  If there is only one value, print it. If there are none, print 0.
  Do not use an array or vector.
*/
//Last Changed: January 30, 2017

#include <iostream>
using namespace std;
int main() 
{
	int input_number, first_value, last_value, count(0);
	double avg(0);

	cin >> input_number;
	first_value = input_number;
	while (input_number > 0)
	{
		count++;
		last_value = input_number;
		cin >> input_number;
		if (0 == input_number)
			break;
	}
	if (1 == count)
	{
		avg = first_value;
	}
	else
	{
		if (0 == count)
		{
			//No Input
		}
		else
		{
			avg = ( first_value + last_value ) / 2.0;
		}
	}
	cout << "Average: " << avg << endl;
	return 0;
}
