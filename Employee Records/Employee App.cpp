//File Name: Employee Records.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 6
//Description: 
//Last Changed: Mar 4, 2017

#include "Employee.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void execute(char command, ifstream& input, vector<Employee> &list);
int binary_search(int input_id, vector<Employee> &list, int &position);
void print_all(vector<Employee> &list);
void print_stats(vector<Employee> &list);


enum ERROR_CODE {NO_ERROR, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

const string INPUT_FILE_NAME = "commands.in";

int main()
{
   // Open the input file.
   ifstream input;
   //input.open(INPUT_FILE_NAME);
   input.open("commands.in.txt");
   
   if (input.fail())
   {
      cout << "Failed to open " << INPUT_FILE_NAME << endl;
      return -1;
   }

   char command;
   vector<Employee> list;

   input >> command;

   while (!input.eof())
   {
      execute(command, input, list);
      input >> command;
   }

   print_all(list);
   print_stats(list);

   return 0;
}

void execute (char command, ifstream& input, vector<Employee> &list)
{
   Employee employee;
   string ignore_input;
   int input_id = 0, search_return = NOT_FOUND, position = 0;

   input >> ws;

   switch (command)
   {
      case '+':
         input >> employee;
         cout << command << " " << employee.get_id() << ": ";
         if (list.size() > 0) //search the table only if at least one entry is available
            search_return = binary_search(employee.get_id(), list, position);

         if (search_return == NOT_FOUND)
         {
            list.insert(list.begin() + position, employee);
            cout << employee;
         }

         if (search_return == DUPLICATE)
         {
            cout << "*** Duplicate ID ***" << endl;
         }
         break;
      case '-':
         input >> input_id;
         cout << command << " " << input_id << ": ";

         if (list.size() > 0) //search the table only if at least one entry is available
            search_return = binary_search(input_id, list, position);

         if (search_return == DUPLICATE)
         {
            cout << list[position];
            list.erase(list.begin() + position);
         }

         if (search_return == NOT_FOUND)
            cout << "*** ID not found ***" << endl;

         break;
      case '?':
         input >> input_id;
         cout << command << " " << input_id << ": ";

         if (list.size() > 0) //search the table only if at least one entry is available
            search_return = binary_search(input_id, list, position);

         if (search_return == DUPLICATE)
            cout << list[position];

         if (search_return == NOT_FOUND)
            cout << "*** ID not found ***" << endl;

         break;
      default:
         input >> input_id;
         cout << command << " " << input_id << ": ";
         cout << "*** Invalid command ***" << endl;

         getline(input, ignore_input); //read and ignore the rest of the line
         break;
   }
}

void print_all(vector<Employee> &list)
{
   cout << endl;
   cout << "All employees" << endl;
   cout << "-------------" << endl;

   for (int i = 0; i < list.size(); i++)
      cout << list[i];
}

void print_stats(vector<Employee> &list)
{
   float min_sal = list[0].get_salary();
   float max_sal = list[0].get_salary();
   float avg_sal = list[0].get_salary();

   for (int i = 1; i < list.size(); i++)
   {
      if (list[i].get_salary() > max_sal)
         max_sal = list[i].get_salary();

      if (list[i].get_salary() < min_sal)
         min_sal = list[i].get_salary();

      avg_sal += list[i].get_salary();
   }

   avg_sal /= list.size();

   cout << endl;
   cout << "Statistics" << endl;
   cout << "----------" << endl;
   cout << "Minimum salary = $" << fixed << right << setw(9) << setprecision(2) << min_sal << endl;
   cout << "Maximum salary = $" << fixed << right << setw(9) << setprecision(2) << max_sal << endl;
   cout << "Average salary = $" << fixed << right << setw(9) << setprecision(2) << avg_sal << endl;
}

//Binary search function
int binary_search(int input_id, vector<Employee> &list, int &position)
{
   int mid, left = 0 ;
   int right = list.size() - 1;

   while (left <= right)
   {
      mid = (right+left) / 2;
      if (list[mid].get_id() == input_id)
      {
         position = mid; //position at which the ID is found
         return DUPLICATE;
      }
      else if (input_id > list[mid].get_id())
         left = mid + 1;
      else if (input_id < list[mid].get_id())
         right = mid - 1;
   }
   position = left; //position after which new record should be inserted
   return NOT_FOUND;
}
