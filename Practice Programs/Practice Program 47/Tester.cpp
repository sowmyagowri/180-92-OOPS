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
   grade_book.set_score("Fred", "Homework 1", 4);
   grade_book.set_score("Fred", "Homework 2", 2);
   grade_book.set_score("Sally", "Homework 1", 3);
   grade_book.set_score("Mary", "Homework 1", 4);
   grade_book.set_score("Fred", "Homework 3", 1);
   grade_book.set_score("Mary", "Homework 1", 5);
   cout << grade_book.get_score("Fred", "Homework 1") << endl;
   cout << "Expected: 4" << endl;
   cout << grade_book.get_score("Fred", "Homework 2") << endl;
   cout << "Expected: 2" << endl;
   cout << grade_book.get_score("Mary", "Homework 1") << endl;
   cout << "Expected: 5" << endl;
   cout << grade_book.get_score("Sally", "Homework 1") << endl;
   cout << "Expected: 3" << endl;

   return 0;
}
