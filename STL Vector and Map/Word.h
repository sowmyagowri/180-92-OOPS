#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

class Word
{
public:
    Word();
    Word(string text);
    virtual ~Word();

    string get_text() const;
    int get_count() const;

    void increment_count();

    // Overloaded != operator.
    bool operator !=(const Word& other);

private:
    string text;
    int count;
};

#endif /* WORD_H_ */
