#include <map>

using namespace std;

class GradeBook
{
 public:
   /**
      Adds a new student to the grade book.
   */
   void add_student(string student);
   /**
      Increments the score of an existing student.
   */
   void add_score(string student, int score);
   /**
      Gets the score of an existing student.
   */
   int get_score(string student);
 private:
   map<string, int> scores;
};
