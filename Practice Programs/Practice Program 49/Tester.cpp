#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

map<int, int> lengthFrequency(vector<string> words);

int main()
{
   vector<string> text = { "Mary", "had", "a", "tiny", "lamb" };
   map<int, int> freq = lengthFrequency(text);
   cout << freq[1] << endl;
   cout << "Expected: 1" << endl;
   cout << freq[4] << endl;
   cout << "Expected: 3" << endl;
   cout << boolalpha << (freq.find(2) == freq.end()) << endl;
   cout << "Expected: true" << endl;
   vector<string> text2 = { "its", "fleece", "was", "white", "as", "snow" };
   freq = lengthFrequency(text2);
   cout << freq[3] << endl;
   cout << "Expected: 2" << endl;
   cout << freq[4] << endl;
   cout << "Expected: 1" << endl;
   cout << boolalpha << (freq.find(2) == freq.end()) << endl;
   cout << "Expected: false" << endl;
   return 0;
}
