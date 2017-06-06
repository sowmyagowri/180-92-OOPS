//File Name: Practice Program 10.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Week 2 Practice Program: 5
//Description: 
//Last Changed: Feb 6, 2017

#include <iostream>
#include <string>

using namespace std;

void swapFirstLastVowel(string&);

int main()
{
   string s = "Hello";
   swapFirstLastVowel(s);
   cout << s << endl;
   cout << "Expected: Holle" << endl;
   s = "Goodbye";
   swapFirstLastVowel(s);
   cout << s << endl;
   cout << "Expected: Geodbyo" << endl;
   s = "Tom";
   swapFirstLastVowel(s);
   cout << s << endl;
   cout << "Expected: Tom" << endl;
   s = "Bzzzt";
   cout << s << endl;
   cout << "Expected: Bzzzt" << endl;
   return 0;
}

#include <string>

using namespace std;

/**
   Returns true if c is a vowel.
*/
bool isVowel(char c)
{
   return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
      || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

/**
   Swaps the first and last vowel in the string s.
   For example, if s is "Farewell", it is changed to "Ferewall".
*/
void swapFirstLastVowel(string& s)
{
	int length, i, j, first_vowel_position = 0, last_vowel_position = 0;
	string letter;
	char letter_char;
	bool vowel = false;
	length = s.length( );
	for (i=0; i < length; i++)
	{
		letter = s.substr(i, 1);
		letter_char = letter[0];
		vowel = isVowel(letter_char);
		if (vowel == true)
		{
			first_vowel_position = last_vowel_position = s.find(letter);
			vowel = false;
			i++;
			for (j=i; j < length; j++)
			{
				i++;
				letter = s.substr(j, 1);
				letter_char = letter[0];
				vowel = isVowel(letter_char);
				if (vowel == true)
					last_vowel_position = s.find(letter, j);
			}
		}
	}
	if (first_vowel_position != last_vowel_position)
		s = s.substr(0, first_vowel_position) + s.substr(last_vowel_position, 1) + s.substr(first_vowel_position + 1, last_vowel_position - first_vowel_position - 1) + s.substr(first_vowel_position, 1) + s.substr(last_vowel_position + 1, length - 1);
	else
		s = s.substr(0, first_vowel_position) + s.substr(first_vowel_position, 1) + s.substr(first_vowel_position + 1, length - 1);
}
