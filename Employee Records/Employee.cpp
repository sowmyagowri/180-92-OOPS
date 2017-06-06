//File Name: Employee.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 6
//Description: 
//Last Changed: Mar 4, 2017

#include "Employee.h"
#include <iostream>

//Default constructor for Employee with 0 for id and salary and SPACES for first name & last name
Employee::Employee() : id(0), last_name(" "), first_name(" "), salary(0)
{

}

//Constructor for employee record
Employee::Employee(int id_input, string last_name_input, string first_name_input, int salary_input)
{
   id = id_input;
   last_name = last_name_input;
   first_name = first_name_input;
   salary = salary_input;
}

void Employee::set_id(int id_input) { id = id_input; } //Setter function for id
void Employee::set_lastname(string last_name_input) { last_name = last_name_input; } //Setter function for last name
void Employee::set_firstname(string first_name_input) { first_name = first_name_input; } //Setter function for first name
void Employee::set_salary(int salary_input) { salary = salary_input; } //Setter function for salary

int Employee::get_id() const { return id; } //Getter function for id
string Employee::get_lastname() const { return last_name; } //Getter function for last name
string Employee::get_firstname() const { return first_name; } //Getter function for first name
int Employee::get_salary() const { return salary; } //Getter function for salary

//Over-loading the stream extraction operator
istream& operator >>(istream& ins, Employee& employee)
{
   string str;

   getline(ins, str, ',' ); //read the input line till ID
   employee.id = stoi(str);

   getline(ins, employee.last_name, ',' ); //read the input line till last name

   getline(ins, employee.first_name, ',' ); //read the input line till first name

   getline(ins, str, '\n' ); //read the input line till end of line
   employee.salary = stoi(str);

   return ins;
}

//Over-loading the stream insertion operator
ostream& operator <<(ostream& outs, const Employee& e)
{
   outs << "Employee{ID=" << e.id << ", last=" << e.last_name << ", first=" << e.first_name << ", salary=" << e.salary <<"}" << endl;
   return outs;
}
