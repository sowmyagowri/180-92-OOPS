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
      Sets the score of an existing student and a new or existing task.
   */
   void set_score(string student, string task, int score);
   /**
      Gets the score of an existing task for an existing student.
   */
   int get_score(string student, string task);
 private:
   map<string, map<string, int>> scores;
};
