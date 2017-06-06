/*
 * Time.h
 *
 *  Created on: Feb 25, 2017
 *      Author: sends
 */

/**
   A time of the day between 0:00 and 23:59
*/
class Time
{
 public:
   /**
      @param hr the hour (between 0 and 23)
      @param min the minutes (between 0 and 59)
    */
   Time(int hr, int min);
   /**
      @return the hours in military time (between 0 and 23).
   */
   int hours();
   /**
      @return the minutes (between 0 and 59)
   */
   int minutes();
   /**
      @param the minutes to add or subtract (if negative)
   */
   void add_minutes(int minutes);
 private:
   int minutesSinceMidnight;
};
