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
      Increments the score of an existing student and an existing
      task, or sets the score for the task if it didn't exist.
   */
   void add_score(string student, string task, int score);
   /**
      Gets the score of an existing task for an existing student,
      or -1 if the task doesn't exist for that student.
   */
   int get_score(string student, string task);
 private:
   map<string, map<string, int>> scores;
};
