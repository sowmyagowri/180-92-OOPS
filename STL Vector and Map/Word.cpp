#include <string>
#include "Word.h"
using namespace std;

Word::Word() : text(""), count(0)
{
}

Word::Word(string text) : text(text), count(1)
{
}

Word::~Word()
{
}

string Word::get_text()  const { return text; }
int    Word::get_count() const { return count; }

void   Word::increment_count() { count++; }

/**
 * Overloaded != operator used to determine
 * if there is mismatch of data between vector content and map value
 */
bool Word::operator !=(const Word &other)
{
   if (text != other.text)
      return true;
   else
      if (count != other.count)
         return true;
      else
          return false;
}
