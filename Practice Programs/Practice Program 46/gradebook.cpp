#include "gradebook.h"

/**
   Implement the member functions of the GradeBook class that uses
   a map to keep student scores.
*/

void GradeBook::add_student(string student)
{
    scores[student] = 0;
}

void GradeBook::add_score(string student, int score)
{
    scores[student] += score;
}

int GradeBook::get_score(string student)
{
    return scores.at(student);
}
