#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"

using namespace std;
using namespace std::chrono;

WordMap::WordMap()
{
}

WordMap::~WordMap()
{
}

map<string, Word>& WordMap::get_data() { return data; }

int WordMap::get_count(const string text) const
{
    return data.at(text).get_count();
}

void WordMap::insert(const string text)
{
    pair<map<string,Word>::iterator,bool> it;
    // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

    it = data.insert (pair<string,Word>(text,Word(text)));

    if (it.second==false)
        data.at(text).increment_count();

    // Compute and increment the elapsed time in microseconds.
    steady_clock::time_point end_time = steady_clock::now();

    long usec = duration_cast<microseconds>(end_time - start_time).count();
    this->increment_elapsed_time(usec);
}

map<string, Word>::iterator WordMap::search(const string text)
{
    // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

    map<string, Word>::iterator it = data.find(text);

    // Compute and increment the elapsed time in microseconds.
    steady_clock::time_point end_time = steady_clock::now();

    long usec = duration_cast<microseconds>(end_time - start_time).count();
    this->increment_elapsed_time(usec);

    return it;
}
