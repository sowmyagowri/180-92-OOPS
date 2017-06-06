#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;
using namespace std::chrono;

WordVector::WordVector()
{
}

WordVector::~WordVector()
{
}

vector<Word>& WordVector::get_data() { return data; }

int WordVector::get_count(const string text) const
{
    int pos = this->find(text,0,data.size());

    if(pos >= 0)
        return data.at(pos).get_count();
    else
        return 0;
}

void WordVector::insert(const string text)
{
    // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

 //Using a Binary search for insertion

    int pos = find(text,0,data.size()-1);

    if (pos < 0) // A negative pos means that the text was not found
    {
        pos *= -1;
        data.insert ( data.begin()+pos-1, Word(text) );
    }
    else // The text was found. So, the count has to be incremented
    {
        vector<Word>::iterator it = data.begin();
        advance (it,pos);
        it->increment_count();
    }

    // Compute and increment the elapsed time in microseconds.
    steady_clock::time_point end_time = steady_clock::now();

    long usec = duration_cast<microseconds>(end_time - start_time).count();
    this->increment_elapsed_time(usec);
}

vector<Word>::iterator WordVector::search(const string text)
{
    // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

    vector<Word>::iterator it = data.begin();

    int pos = find(text,0,data.size()-1);

    if (pos == 0)
        it = data.begin();
    if (pos > 0)
        advance (it,pos);
    else
        it = data.end();

    // Compute and increment the elapsed time in microseconds.
    steady_clock::time_point end_time = steady_clock::now();

    long usec = duration_cast<microseconds>(end_time - start_time).count();
    this->increment_elapsed_time(usec);

    return it;
}

int WordVector::find(const string text, int low, int high) const
{
    if (low <= high)
    {
        int mid = (low + high)/2;

        if (text == data[mid].get_text())
            return mid;
        else if (text < data[mid].get_text() )
                return find(text, low, mid-1);
            else
                return find(text, mid+1, high);
    }

    //Returning ( position to be inserted - 1 ) instead of just a -1 in order to use binary search for insertion
    return -(low + 1);
}
