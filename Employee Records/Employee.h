/*
 * Employee.h
 *
 *  Created on: Mar 4, 2017
 *      Author: sends
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
using namespace std;

class Employee
{
public:

   Employee(); // Default constructor
   Employee(int id_input, string last_name_input, string first_name_input, int salary_input);

   void set_id(int id_input);
   void set_lastname(string last_name_input);
   void set_firstname(string first_name_input);
   void set_salary(int salary_input);

   int get_id() const;
   string get_lastname() const;
   string get_firstname() const;
   int get_salary() const;

   friend istream& operator >>(istream& ins, Employee& e); //Over-loading the stream extraction operator
   friend ostream& operator <<(ostream& outs, const Employee& e); //Over-loading the stream insertion operator

private:
   int id, salary;
   string last_name, first_name;
};

#endif /* EMPLOYEE_H_ */
