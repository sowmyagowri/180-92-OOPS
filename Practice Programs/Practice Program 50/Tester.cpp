#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

map<int, set<string>> wordsByLength(vector<string> words);

int main()
{
   vector<string> text = { "Mary", "had", "a", "tiny", "lamb" };
   map<int, set<string>> result = wordsByLength(text);
   set<string> as = result[1];
   copy(as.begin(), as.end(),
      ostream_iterator<string>(cout, " "));
   cout << endl;
   cout << "Expected: a" << endl;
   set<string> ls = result[4];
   copy(ls.begin(), ls.end(),
      ostream_iterator<string>(cout, " "));
   cout << endl;
   cout << "Expected: Mary lamb tiny" << endl;
   cout << boolalpha << (result.find(2) == result.end()) << endl;
   cout << "Expected: true" << endl;
   vector<string> text2 = { "its", "fleece", "was", "white", "as", "snow" };
   result = wordsByLength(text2);
   as = result[2];
   copy(as.begin(), as.end(),
      ostream_iterator<string>(cout, " "));
   cout << endl;
   cout << "Expected: as" << endl;
   set<string> ws = result[3];
   copy(ws.begin(), ws.end(),
      ostream_iterator<string>(cout, " "));
   cout << endl;
   cout << "Expected: its was" << endl;
   cout << boolalpha << (result.find(1) == result.end()) << endl;
   cout << "Expected: true" << endl;
   return 0;
}
