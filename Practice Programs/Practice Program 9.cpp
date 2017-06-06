//File Name: Practice Program 9.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Week 2 Practice Program: 4
//Description: 
//Last Changed: Feb 6, 2017

#include <iostream>
#include <string>

using namespace std;

void firstLastVowel(string, int&, int&);

int main()
{
   int f = -2;
   int l = -2;
   firstLastVowel("meat", f, l);
   cout << f << " " << l << endl;
   cout << "Expected: 1 2" << endl;
   firstLastVowel("Expectation", f, l);
   cout << f << " " << l << endl;
   cout << "Expected: 0 9" << endl;
   firstLastVowel("Tom", f, l);
   cout << f << " " << l << endl;
   cout << "Expected: 1 1" << endl;
   firstLastVowel("Brrrh", f, l);
   cout << f << " " << l << endl;
   cout << "Expected: -1 -1" << endl;
   return 0;
}

#include <string>
bool isVowel(char c);

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
   Sets first to the index of the first vowel in the string s
   and last to the index of the last vowel in s. If s has no vowels,
   first and last are set to -1.
*/
void firstLastVowel(string s, int& first, int& last)
{
	int length, i, j;
	string letter;
	char letter_char;
	bool vowel = false;
	first = -1;
	last = -1;
	length = s.length( );
	for (i=0; i < length; i++)
	{
		letter = s.substr(i, 1);
		letter_char = letter[0];
		vowel = isVowel(letter_char);
		if (vowel == true)
		{
			first = last = s.find(letter);
			vowel = false;
			i++;
			for (j=i; j < length; j++)
			{
				i++;
				letter = s.substr(j, 1);
				letter_char = letter[0];
				vowel = isVowel(letter_char);
				if (vowel == true)
					last = s.find(letter, j);
			}
		}
	}
}
