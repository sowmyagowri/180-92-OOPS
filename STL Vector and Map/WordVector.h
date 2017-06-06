#ifndef WORDVECTOR_H_
#define WORDVECTOR_H_

#include <vector>
#include <ctime>
#include <chrono>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

class WordVector : public TimedContainer
{
public:
    WordVector();
    virtual ~WordVector();

    vector<Word>& get_data();
    int get_count(const string text) const;

    void insert(const string text);
    vector<Word>::iterator search(const string text);

private:
    vector<Word> data;

    int find(const string text, int low, int high) const;
};

#endif /* WORDVECTOR_H_ */
