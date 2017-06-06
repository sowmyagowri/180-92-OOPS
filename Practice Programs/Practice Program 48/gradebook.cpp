#include "gradebook.h"

/**
   Now we change the gradebook again so that one can increment the
   score of a task (like in the first program).
*/

void GradeBook::add_student(string student)
{
   scores[student][""] = 0;
}

void GradeBook::add_score(string student, string task, int score)
{
   scores[student][task] += score;
}

int GradeBook::get_score(string student, string task)
{
   int score = scores[student][task];
   if (score == 0)
       return -1;
   else
       return score;

}
