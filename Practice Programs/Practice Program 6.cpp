//File Name: Practice Program 6.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Week 2 Practice Program: 1
//Description: 
/*
   Computes the average of the middle values of four given values
   (that is, without the largest and smallest value).
   Hint: Use the given min function. You may also want to define a
   max helper function or take advantage of the fact that max can be
   computed from the min of the negative values.
*/
//Last Changed: Feb 6, 2017

#include <iostream>

int min(int a, int b, int c, int d);
int max(int a, int b, int c);
double middle(int a, int b, int c, int d);

using namespace std;

/**
   Computes the smallest of four values.
*/
int min(int a, int b, int c, int d)
{
   int result = a;
   if (b < result) result = b;
   if (c < result) result = c;
   if (d < result) result = d;
   return result;
}

/**
   Computes the largest of four values.
*/
int max(int a, int b, int c)
{
   int result = a;
   if (a > result) result = a;
   if (b > result) result = b;
   if (c > result) result = c;
   return result;
}

/**
   Computes the average of middle values.
*/
double middle(int a, int b, int c, int d)
{
	int minimum_value, maximum_value, mid_1, mid_2;
	double average;
	minimum_value = min(a, b, c, d);
	if (minimum_value == a)
	{
		maximum_value = max(b, c, d);

		if (maximum_value == b) average = (c + d) / 2.0;
		if (maximum_value == c) average = (b + d) / 2.0;
		if (maximum_value == d) average = (b + c) / 2.0;
	}
	if (minimum_value == b)
	{
		maximum_value = max(a, c, d);

		if (maximum_value == a) average = (c + d) / 2.0;
		if (maximum_value == c) average = (a + d) / 2.0;
		if (maximum_value == d) average = (a + c) / 2.0;
	}
	if (minimum_value == c)
	{
		maximum_value = max(a, b, d);

			if (maximum_value == a) average = (b + d) / 2.0;
			if (maximum_value == b) average = (a + d) / 2.0;
			if (maximum_value == d) average = (a + b) / 2.0;
	}
	if (minimum_value == d)
	{
		maximum_value = max(a, b, c);

			if (maximum_value == a) average = (b + c) / 2.0;
			if (maximum_value == b) average = (a + c) / 2.0;
			if (maximum_value == c) average = (a + b) / 2.0;
	}
	return average;
}

int main()
{
	int a, b, c, d;
	double average;
	cin >> a >> b >> c >> d;
	average = middle(a, b, c, d);
	cout << average << endl;
	return 0;
}
