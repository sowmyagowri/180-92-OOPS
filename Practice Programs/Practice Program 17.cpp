//File Name: Practice Program 17.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Pratice Program: 17
//Description: 
/**
   Given a '\0'-terminated character array, split it by replacing
   each space in the character array with a '\0'. Return the number
   of strings into which you have split the input.
*/
//Last Changed: Feb 17, 2017

#include <iostream>
#include <cstring>

using namespace std;

int split(char* words);

int main()
{
   char words[] = "Hello Goodbye Bonjour Arrivederci";
   int n = split(words);
   cout << n << endl;
   cout << "Expected: " << 4 << endl;
   cout << words << endl;
   cout << "Expected: " << "Hello" << endl;
   cout << words + 6 << endl;
   cout << "Expected: " << "Goodbye" << endl;
   cout << words + 14 << endl;
   cout << "Expected: " << "Bonjour" << endl;
   cout << words + 22 << endl;
   cout << "Expected: " << "Arrivederci" << endl;

   char morewords[] = "Hello  Goodbye"; // Note two spaces
   n = split(morewords);
   cout << n << endl;
   cout << "Expected: " << 3 << endl;
   cout << morewords << endl;
   cout << "Expected: " << "Hello" << endl;
   cout << strlen(morewords + 6) << endl;
   cout << "Expected: " << 0 << endl;
   cout << morewords + 7 << endl;
   cout << "Expected: " << "Goodbye" << endl;

   return 0;
}

/**
   Given a '\0'-terminated character array, split it by replacing
   each space in the character array with a '\0'. Return the number
   of strings into which you have split the input.
*/
int split(char* words)
{
    int number_of_words = 0;
    for (int i=0; words[i] != '\0'; i++)
    {
        if (words[i] == ' ' )
        {
            words[i] = '\0';
            number_of_words++;
        }
    }
    number_of_words++;
    return number_of_words;
}
