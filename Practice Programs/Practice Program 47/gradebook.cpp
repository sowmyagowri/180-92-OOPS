#include "gradebook.h"

/**
   The gradebook of the preceding problem wasn't very useful
   because it only keeps a single score for each student.

   In this problem, we make the gradebook more realistic by
   keeping a map of tasks to scores for each student.

*/

void GradeBook::add_student(string student)
{
   scores[student][""] = 0;
}

void GradeBook::set_score(string student, string task, int score)
{
   scores[student][task] = score;
}

int GradeBook::get_score(string student, string task)
{
   return scores[student][task];
}
