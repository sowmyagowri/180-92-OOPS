//File Name: Presidents.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 1
//Description:
/*
	To read the input file presidents.in field-by-field using the >> input extraction operator, not an entire line at a time.
	Let the >> operator read integer values – you should not have any code that converts strings to integer values.
	Include each president's age at death (leave it blank if he’s still alive) as calculated simply from his birth and death years.
	Compute the overall average age at death of all the former presidents who have died.
*/
//Last Changed: Jan 31, 2017

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

//const string INPUT_FILE_NAME = "presidents.in";

char filename [16];

const char *INPUT_FILE_NAME = "presidents.in";
string input_word, first_name, middle_name, last_name, middle_or_last, last_name_1, last_name_2;
string died_year, age, party, start_year, end_year;
char first_letter_char_1, first_letter_char_2;
int born_year_int, died_year_int, age_int, sum_of_age, middle_name_flag(0);
double average_age(0.0),count_presidents_dead(0.0);

/**
 * The main: Read the input file and print the report.
 */
int main()
{

    // Open the input file.

    ifstream input;
    //input.open(INPUT_FILE_NAME);

    input.open("presidents.in.txt");

    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // Print the Header
    cout << "First name Middle name Last name Born Died Age Start End Party" << endl;
    cout << "---------- ----------- --------- ---- ---- --- ----- ---- -----" << endl;

    //Start reading the input file word-by-word
    input >> input_word;

    do
    {
    	if (input_word != end_year )
    		first_name = input_word;

    	middle_name = "";
    	input >> middle_or_last;

    	if ((1 == middle_or_last.length( )) or (2 == middle_or_last.length( )))
    		//To check if the middle name has one or  more initials with or without period
    	{
    		middle_name = middle_or_last;
    		input >> input_word;
    		middle_name_flag = 0;

    		while ( (1 == input_word.length()) or (2 == input_word.length()))
    		{
    			middle_name = middle_name + " " + input_word;
    			input >> input_word;
    			middle_name_flag = 1;
    		}
    	}
    	else
    	{
    		first_letter_char_1 = middle_or_last[0];
    		input >> input_word;

    		middle_name_flag = 2;
    		first_letter_char_2 = input_word[0];

    		if ((isupper (first_letter_char_1)) and (first_letter_char_2 != '(' ))
    		{
    			if (islower(first_letter_char_2)) //To check if the last name has two words with at least a middle name present
    			{
    				middle_name = middle_or_last;
    				middle_name_flag = 3;
    			}
    			else
    			{
    				middle_name = middle_or_last;
    				middle_name_flag = 4;
    				middle_or_last = input_word;
    				first_letter_char_1 = middle_or_last[0];

    				input >> input_word;
    				first_letter_char_2 = input_word[0];

    				while ( '(' != first_letter_char_2 )
    				{
    					//To check if the middle name has one or more words
    					middle_name = middle_name + " " + middle_or_last;
    					middle_name_flag = 3;
							while ((isupper (first_letter_char_1)) and ( isupper (first_letter_char_2)))

							{
								middle_name = middle_name + " " + middle_or_last;
								middle_or_last = input_word;
								first_letter_char_1 = middle_or_last[0];
								input >> input_word;
								first_letter_char_2 = input_word[0];
							}


    				}
    			 }
    		 }
    	}

    	last_name = input_word;

    	if (first_letter_char_2 != '(' ) //has both middle name and last name
    	{
    		if ( 2 == middle_name_flag )
    		{
				first_letter_char_1 = middle_or_last[0];
				//Check if the first letter of the last name is lowercase to determine whether the last name has 2 words
				if (islower(first_letter_char_1))
				{
				last_name_1 = middle_or_last;
				last_name_2 = input_word;
				last_name = last_name_1 + " " + last_name_2;
				}
    		}
    	}
    	if (( 2 == middle_name_flag ) and (first_letter_char_2 == '(' ))
    		last_name = middle_or_last;

    	if (input_word != "(" ) // No middle name or No middle name but 2 last names
    	{
    	   if ( 4 == middle_name_flag )
    	   {
				input_word = middle_or_last;
				//Check if the first letter of the last name is lowercase to determine whether the last name has 2 words
				first_letter_char_1 = input_word[0];
				if (islower(first_letter_char_1))
				{
					last_name_1 = middle_or_last;
					input >> input_word;
					last_name_2 = input_word;
					last_name = last_name_1 + " " + last_name_2;
					input >> input_word;
				}
    	    }
    	 }

    	if (( 4 == middle_name_flag ) and (first_letter_char_2 == '(' ))
    	{
    	    	last_name = middle_or_last;

    	}

		if ("(" == input_word)
		{
			input >> born_year_int;
		}
		else
		{
			input >> input_word;
			input >> born_year_int;
		}

		input >> input_word;

		//To check if died year is present
    	if (")" == input_word)
    	{
   			died_year = "";
   			died_year_int = 0;
   			age = "  ";
   			age_int = 0;
   		}
   		else
    	{
   			input >> died_year_int;
        	age_int = died_year_int - born_year_int;
        	input >> input_word;
   		}

		input >> party;

		input >> start_year;

		input >> input_word;

		//To check if end year is present
		if ("-" == input_word)
		{
			input >> end_year;
			input >> input_word;
		}
		else

			end_year = start_year;



		//Print the report line

    	cout << setw(11) << left << first_name << setw(12) << left << middle_name << setw(11) << left << last_name;
    	cout << setw(5) << left << born_year_int;

    	if (died_year_int > 0)
    		cout << setw(5) << left << died_year_int << setw(3) << right << age_int;
    	else
    		cout << setw(5) << left << died_year << setw(3) << right << age;

    	cout << setw(6) << right << start_year << setw(5) << right << end_year << " " << party << endl;

    	if (died_year_int > 0)
    	{
    		count_presidents_dead++;
    		sum_of_age += age_int;
    	}


   } while (input_word != "."); // Read till EOF condition of Termination by a string "."

    //Calculate the average age
    average_age = sum_of_age / count_presidents_dead;

    cout << endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "Average age at death = " << average_age << endl;

    return 0;
}
