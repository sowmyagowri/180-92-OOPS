#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

/**
  Makes a map associating integers with the words
  having that length.
  @param words an array of strings
  @return the map
*/
map<int, set<string>> wordsByLength(vector<string> words)
{
    map<int, set<string>> mymap;

    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
        mymap[(*it).length()].insert(*it);

    return mymap;
}
