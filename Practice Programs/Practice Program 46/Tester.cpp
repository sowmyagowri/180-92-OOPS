#include <iostream>
#include "gradebook.h"

using namespace std;

int main()
{
   GradeBook grade_book;
   grade_book.add_student("Fred");
   grade_book.add_student("Sally");
   grade_book.add_student("Harry");
   grade_book.add_student("Mary");
   grade_book.add_score("Fred", 1);
   grade_book.add_score("Fred", 2);
   grade_book.add_score("Sally", 3);
   grade_book.add_score("Mary", 4);
   grade_book.add_score("Fred", 1);
   grade_book.add_score("Mary", 1);
   cout << grade_book.get_score("Fred") << endl;
   cout << "Expected: 4" << endl;
   cout << grade_book.get_score("Harry") << endl;
   cout << "Expected: 0" << endl;
   cout << grade_book.get_score("Mary") << endl;
   cout << "Expected: 5" << endl;
   cout << grade_book.get_score("Sally") << endl;
   cout << "Expected: 3" << endl;

   return 0;
}
