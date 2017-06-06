//File Name: Program 5.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Problem: 5
//Description: 
/*
  Read a file and print out the average number of words per sentence.
  A sentence is a sequence of strings that is
  terminated by a string ending in "." (which is a part of the sequence).
  The file is terminated by a string "." which is not a sentence.
  Print out the average length of all sentences. You may assume there
  is at least one sentence.
*/
//Last Changed: Jan 31, 2017

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	double average;
	string word;
	char filename [16];
	int count_words(0);
	double count_period(0.00);

	// create a file-reading object
	cout << "File name: " << endl;
	cin >> filename;

	ifstream input_stream (filename); // open a file

	if (input_stream.fail())
		exit(1); // exit if file not found

	//read each line of the file and stop reading if the sentence is a "."

	input_stream >> word;
	while("." != word) // To read till EOF condition of Termination by a string "."
	{
		if ("." == word.substr(word.length( ) - 1)) //check for "." in sentences to find the end of each sentence
			count_period++;

		count_words++;
		input_stream >> word;
	}

   	average = count_words/count_period;
   	cout.setf(ios::fixed);
   	cout.setf(ios::showpoint);
   	cout.precision(1);
   	cout << "Average: " << average << endl;
	input_stream.close( );
	return 0;
}
