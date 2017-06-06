#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

/**
   Makes a map associating integers with the number of words
   whose length is the given integer.
   @param words a vector of strings
   @return the map

*/
map<int, int> lengthFrequency(vector<string> words)
{
    map<int, int> mymap;

    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
        mymap[(*it).length()]++;

    return mymap;
}
