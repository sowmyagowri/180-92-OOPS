//File Name: Practice Program 7.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Week 2 Practice Program: 2
//Description: 
//Last Changed: Feb 6, 2017

#include <iostream>
#include <string>

using namespace std;
/**
   Turn a string of the form firstname lastname or
   firstname middlename(s) lastname into lastname, firstname
   (and middlenames if present).
   For example, lastfirst("John Pierpont Flathead") should return
   "Flathead, John Pierpont". If the string contains no spaces, return
   it unchanged.
   Hint: If s is a string, then s.substr(i, n) is the substring
   starting at index i of length n. And if s and t are two strings,
   then s + t is the concatenation of the two strings. You will want
   to return a string of the form
   s.substr(i1, n1) + ", " + s.substr(i2, n2)
   except if s contains no spaces.
*/
string lastfirst(string s)
{
	int i=0, last_space_occurrence, length;
	string last_first;
	length = s.length();
	do
	{
		last_space_occurrence = s.find(" ", i);
		if (-1 != last_space_occurrence)
			i = last_space_occurrence + 1; // to find the next space in the given input name
		else
		{
			last_space_occurrence = i - 1; // to retain the position of the last space in the given input name
			i = length;  // to break the while loop
		}
	}while(i < length);
	if ( last_space_occurrence ==  -1 ) // to check if there is only one word in the input name
		last_first = s;
	else
		last_first = s.substr(last_space_occurrence + 1, length - last_space_occurrence - 2) + ", " + s.substr(0, last_space_occurrence);
	return last_first;
}

int main()
{
	string input, last_first_name;
	getline (cin, input);
	last_first_name = lastfirst (input);
	cout << last_first_name << endl;
	return 0;
}
