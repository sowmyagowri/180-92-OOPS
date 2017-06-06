#ifndef WORDMAP_H_
#define WORDMAP_H_

#include <map>
#include <ctime>
#include <chrono>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

class WordMap : public TimedContainer
{
public:
    WordMap();
    virtual ~WordMap();

    map<string, Word>& get_data();
    int get_count(const string text) const;

    void insert(const string text);
    map<string, Word>::iterator search(const string text);

private:
    map<string, Word> data;
};

#endif /* WORDMAP_H_ */
