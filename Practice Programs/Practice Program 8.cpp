//File Name: Practice Program 8.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Week 2 Practice Program: 3
//Description: 
//Last Changed: Feb 6, 2017

#include "grades.h"
/**
   Given a letter grade (A, B, C, D, F) and a suffix (None, Plus, Minus),
   produce the numerical value of the grade. An A is a 4, B a 3,
   C a 2, D a 1, and F a zero. The suffix Plus adds 0.3, the suffix
   Minus subtracts 0.3. However, an A+ has value 4 and an F+ and F-
   have value zero.
 */
double gradeValue(Grade g, Suffix s)
{
	double grade_num;
	switch (g)
	{
		case A:
			g = F;
			break;
		case B:
			g = D;
			break;
		case D:
			g = B;
			break;
		case F:
			g = A;
			break;
	}
	switch (s)
	{
		case None:
			grade_num = g;
			break;
		case Plus:
			grade_num = g+0.3;
			if (grade_num == 4.3)
				grade_num = g;
			if (grade_num == 0.3)
				grade_num = 0;
			break;
		case Minus:
			grade_num = g-0.3;
			if (grade_num == -0.3)
				grade_num = g;
			break;
	}

	return grade_num;
}
