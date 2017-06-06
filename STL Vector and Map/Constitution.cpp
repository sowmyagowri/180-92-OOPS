#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <stdlib.h>
#include "Word.h"
#include "WordVector.h"
#include "WordMap.h"

using namespace std;

const string INPUT_FILE_NAME = "USConstitution.txt";
const int    MAX_SEARCHES    = 100000;

void time_word_insertions(ifstream& in, WordVector& v, WordMap& m);
void make_spot_checks(WordVector& v, WordMap& m) throw(string);
void check_concordances(WordVector& v, WordMap& m) throw(string);
void time_word_searches(WordVector& v, WordMap& m) throw(string);
void vector_map_dump(WordVector& v, WordMap& m);
string commafy(const long n);

int main()
{
    ifstream in;
    //in.open(INPUT_FILE_NAME);
    in.open("USConstitution.txt");
    if (in.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    WordVector v;
    WordMap    m;

    try {
        time_word_insertions(in, v, m);
        make_spot_checks(v, m);
        check_concordances(v, m);
        time_word_searches(v, m);
        //vector_map_dump(v, m);
    }
    catch (string& msg)
    {
        cout << endl << endl << "***** " << msg << endl;
    }

    return 0;
}

void time_word_insertions(ifstream& in, WordVector& v, WordMap& m)
{
    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;

    cout << "Timed insertions ..." << endl;

    v.reset_elapsed_time();
    m.reset_elapsed_time();

    // Loop once per line of the input file.
    while (getline(in, line))
    {
        line_count++;
        character_count += line.length();

        for (auto& i : line)
        {
            if (ispunct(i)) //To remove punctuation
                i = ' ';
            if (isdigit(i)) //To remove numbers
                i = ' ';
            if (isupper(i)) //To convert upper-case to lower-case
                i = tolower(i);
        }

        istringstream iss(line);
        string word;

        // Loop once per word in the line.
        while (iss >> word)
        {
            word_count++;
            v.insert(word);
            m.insert(word);
        }
    }

    cout << "          Lines: " << setw(6) << commafy(line_count) << endl;
    cout << "     Characters: " << setw(6) << commafy(character_count) << endl;
    cout << "          Words: " << setw(6) << commafy(word_count) << endl;
    cout << endl;
    cout << "    Vector size: " << commafy(v.get_data().size()) << endl;
    cout << "       Map size: " << commafy(m.get_data().size()) << endl;
    cout << endl;
    cout << "    Vector total insertion time: " << setw(8)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "       Map total insertion time: " << setw(8)
         << commafy(m.get_elapsed_time()) << " usec" << endl;
}

void make_spot_checks(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Spot checks of word counts ..." << endl;

    vector<Word>&      vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    vector<string> texts = {
        "amendment", "article", "ballot", "citizens", "congress",
        "constitution", "democracy", "electors", "government", "law",
        "legislature", "people", "president", "representatives",
        "right", "trust", "united", "vice", "vote"
    };

    for (string text : texts)
    {
        cout << "    " << text << ": ";

        vector<Word>::iterator      itv = v.search(text);
        map<string, Word>::iterator itm = m.search(text);

        if(itv == vdata.end())
            cout << " vector:(not found)";
        else
            cout << " vector:" << (*itv).get_count();

        if (itm == mdata.end())
            cout << " map:(not found)" << endl;
        else
            cout << " map:" << itm->second.get_count() << endl;
    }
}

void check_concordances(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Checking concordances ... ";  cout.flush();

    vector<Word>&      vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    int vsize = vdata.size();
    int msize = mdata.size();

    if (vsize == 0) throw("Empty vector.");
    if (msize == 0) throw("Empty map.");

    if (vsize != msize ) throw(string("Size mismatch: ") + to_string(vsize) +
                                                 " and " + to_string(msize));

    vector<Word>::iterator      itv = vdata.begin();
    map<string, Word>::iterator itm = mdata.begin();

    while (itv != vdata.end())
    {
        if (*itv != itm->second)
        {
            throw string(string("Data mismatch: ")
                    + itv->get_text() + ":" + to_string(itv->get_count())
                    + " and " + itm->second.get_text() + ":"
                    + to_string(itm->second.get_count()));
        }

        ++itv;
        ++itm;
    }

    cout << "both match!" << endl;
}

void time_word_searches(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Timed searches (" << commafy(MAX_SEARCHES)
                 << " searches) ..." << endl;

    vector<Word>& vdata = v.get_data();

    int size = vdata.size();

    v.reset_elapsed_time();
    m.reset_elapsed_time();

    for (int i = 1; i <= MAX_SEARCHES; i++)
    {
        srand(time(NULL));
        int index = rand()%size;
        string text = v.get_data()[index].get_text();

        vector<Word>::iterator it = v.search(text);
        map<string, Word>::iterator itm = m.search(text);
    }

    cout << endl;
    cout << "    Vector total search time: " << setw(8)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "       Map total search time: " << setw(8)
         << commafy(m.get_elapsed_time()) << " usec" << endl;
}

void vector_map_dump(WordVector& v, WordMap& m)
{
    cout << endl << "Vector Dump ... " << endl;  cout.flush();

    vector<Word>&      vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    vector<Word>::iterator      itv = vdata.begin();
    map<string, Word>::iterator itm = mdata.begin();

    while (itv != vdata.end())
    {
        cout << itv->get_text() + ":" + to_string(itv->get_count()) << endl;
        ++itv;
    }

    cout << endl << "Map Dump ... " << endl;  cout.flush();

    while (itm != mdata.end())
    {
        cout << itm->second.get_text() + ":" + to_string(itm->second.get_count()) << endl;
        ++itm;
    }
}

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(const long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
