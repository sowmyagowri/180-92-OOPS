#include <iostream>
#include "list.h"

using namespace std;

string show(const List& lst);

EList nil;

int main()
{
   cout << show(NEList("Mary", NEList("had", NEList("a", NEList("little", NEList("lamb", EList())))))) << endl;
   cout << "Expected: [Mary->had->a->little->lamb]" << endl;
   cout << show("Its" += "fleece" += "was" += "white" += "as" += "snow" += nil) << endl;
   cout << "Expected: [Its->fleece->was->white->as->snow]" << endl;
   cout << show("Fred" += "Wilma" += nil) << endl;
   cout << "Expected: [Fred->Wilma]" << endl;
   cout << show("Fred" += nil) << endl;
   cout << "Expected: [Fred]" << endl;
   cout <<  show(nil) << endl;
   cout << "Expected: []" << endl;
   return 0;
}
