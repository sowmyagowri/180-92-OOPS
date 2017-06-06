//File Name: Practice Program 23.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 23
//Description: 
/*
  Provide the hours and minutes member functions.
 */
//Last Changed: Feb 25, 2017

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Time.h"

/*
  Provide the hours and minutes member functions.
 */
Time::Time(int hr, int min)
{
   minutesSinceMidnight = 0;
   add_minutes(60 * hr + min);
}

int Time::hours()
{
    int hour;
    div_t result = div(minutesSinceMidnight, 60);
    hour = result.quot;
    return hour;
}

int Time::minutes()
{
    int minutes;
    div_t result = div(minutesSinceMidnight, 60);
    minutes = result.rem;
    return minutes;
}

void Time::add_minutes(int minutes)
{
   minutesSinceMidnight += minutes;
   minutesSinceMidnight %= 24 * 60;
   if (minutesSinceMidnight < 0) minutesSinceMidnight += 24 * 60;
}

using namespace std;

int main()
{
   Time wakeup(6, 0);
   wakeup.add_minutes(5);
   cout << wakeup.hours() << ":" << setfill('0') << setw(2) << wakeup.minutes() << endl;
   cout << "Expected: 6:05" << endl;

   Time homework_due(18, 30);
   homework_due.add_minutes(3000);
   cout << homework_due.hours() << ":" << setfill('0') << setw(2) << homework_due.minutes() << endl;
   cout << "Expected: 20:30" << endl;

   return 0;
}
