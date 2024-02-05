
#include <stdio.h>
#include <time.h>

int main(void) {

  // time_t now = time(NULL);
  // time(&now); //  ^^^<<--- same as above
  // ctime() is only portable way  to print out what's in a time_t
  // printf("%s", ctime(&now)); // ctime() prints time in LOCAL time
  //
  // struct tm my_localtime = *localtime(&now);
  // struct tm the_utctime = *gmtime(&now);
  //
  // printf("Local: %s", asctime(&my_localtime));
  // printf("  UTC: %s", asctime(&the_utctime));
  //
  // const char *utc_zone = the_utctime.tm_zone;
  // const char *localtime_zone = my_localtime.tm_zone;
  // printf("utc_zone = %s\n", utc_zone);
  // printf("localtime_zone = %s\n", localtime_zone);
  // printf("----------------------------------------------");

  // struct tm some_time = {
  //     .tm_year = 82,  // years since 1900
  //     .tm_mon = 3,    // months since January -- [0, 11]
  //     .tm_mday = 12,  // day of the month -- [1, 31]
  //     .tm_hour = 12,  // hours since midnight -- [0, 23]
  //     .tm_min = 0,    // minutes after the hour -- [0, 59]
  //     .tm_sec = 4,    // seconds after the minute -- [0, 60]
  //     .tm_isdst = -1, // Daylight Saving Time flag
  // };
  // time_t some_time_epoch;
  // some_time_epoch = mktime(&some_time);
  // printf("%s", ctime(&some_time_epoch));
  // printf("Is DST: %d\n", some_time.tm_isdst);
  //
  // time_t now = time(NULL);
  // struct tm *local = localtime(&now);
  // struct tm *utc = gmtime(&now);
  //
  // printf("Local time: %s", ctime(&now));    // Local time with time_t
  // printf("Local time: %s", asctime(local)); // Local time with struct tm
  // printf("UTC       : %s", asctime(utc));   // UTC with a struct tm
  //
  //

  char s[128];
  time_t now = time(NULL);
  // %c: print date as per current locale
  // strftime(s, sizeof s, "%c", localtime(&now));
  // puts(s);

  // %A: full weekday name
  // %B: full month name
  // %d: day of the month
  // strftime(s, sizeof s, "%A, %B %d", localtime(&now));
  // puts(s); // Sunday, February 28

  // %I: hour (12 hour clock)
  // %M: minute
  // %S: second
  // %p: AM or PM
  // strftime(s, sizeof s, "It's %I:%M:%S %p", localtime(&now));
  // puts(s); // It's 10:29:00 PM

  // %F: ISO 8601 yyyy-mm-dd
  // %T: ISO 8601 hh:mm:ss
  // %z: ISO 8601 time zone offset
  // strftime(s, sizeof s, "ISO 8601: %FT%T%z", localtime(&now));
  // puts(s); // ISO 8601: 2021-02-28T22:29:00-0800
  //
  //
  // ALL FORMAT SPECIFIERS for strftime() func
  /*
    -- %a           Locale’s abbreviated weekday name. [tm_wday];
    -- %A           Locale’s full weekday name. [tm_wday];
    -- %b           Locale’s abbreviated month name. [tm_mon];
    -- %B           Locale’s full month name. [tm_mon];
    -- %c           Locale’s appropriate date and time representation.;
    -- %C           Year divided by 100 and truncated to an integer, as a
                    decimal number (00–99). [tm_year];
    -- %d           Day of the month as a decimal number (01–31). [tm_mday];
    -- %D           Equivalent to "%m/%d/%y". [tm_mon, tm_mday, tm_year];
    -- %e           Day of the month as a decimal number (1–31); a single digit
                    is preceded by a space. [tm_mday];
    -- %F           Equivalent to “%Y-%m-%d” (the ISO 8601 date format).
                    [tm_year, tm_mon, tm_mday];
    -- %g           Last 2 digits of the week-based year (see below) as a
                    decimal number (00–99). [tm_year, tm_wday, tm_yday];
    -- %G           Week-based year (see below) as a decimal number (e.g.,
                    1997). [tm_year, tm_wday, tm_yday];
    -- %h           Equivalent to “%b”. [tm_mon];
    -- %H           Hour (24-hour clock) as a decimal number (00–23). [tm_hour];
    -- %I           Hour (12-hour clock) as a decimal number (01–12). [tm_hour];
    -- %j           Day of the year as a decimal number (001–366). [tm_yday];
    -- %m           Month as a decimal number (01–12).;
    -- %M           Minute as a decimal number (00–59). [tm_min];
    -- %n           A new-line character.;
    -- %p           Locale’s equivalent of the AM/PM designations associated
                    with a 12-hour clock. [tm_hour];
    -- %r           Locale’s 12-hour clock time. [tm_hour, tm_min, tm_sec];
    -- %R           Equivalent to "%H:%M". [tm_hour, tm_min];
    -- %S           Second as a decimal number (00–60). [tm_sec];
    -- %t           A horizontal-tab character.;
    -- %T           Equivalent to "%H:%M:%S" (the ISO 8601 time format).
                    [tm_hour, tm_min, tm_sec];
    -- %u           ISO 8601 weekday as a decimal number (1–7), where Monday
                    is 1. [tm_wday];
    -- %U           Week number of the year (the first Sunday as the first day
                    of week 1) as a decimal number (00–53). [tm_year, tm_wday,
                    tm_yday];
    -- %V           ISO 8601 week number (see below) as a decimal number
                    (01–53). [tm_year, tm_wday, tm_yday];
    -- %w           Weekday as a decimal number (0–6), where Sunday is 0.;
    -- %W           Week number of the year (the first Monday as the first day
                    of week 1) as a decimal number (00–53). [tm_year, tm_wday,
                    tm_yday];
    -- %x           Locale’s appropriate date representation.;
    -- %X           Locale’s appropriate time representation.;
    -- %y           Last 2 digits of the year as a decimal number (00–99).
                    [tm_year];
    -- %Y           Year as a decimal number (e.g., 1997). [tm_year];
    -- %z           Offset from UTC in the ISO 8601 format "-0430" (meaning 4
                    hours 30 minutes behind UTC, west of Greenwich), or by no
                    characters if no time zone is determinable. [tm_isdst];
    -- %Z           Locale’s time zone name or abbreviation, or by no characters
                    if no time zone is determinable. [tm_isdst];
    -- %%           A plain ol’ %;
*/

  // # of seconds||nanos since epoch
  // note: nanoseconds == billlionths of a second
  // struct timespec ts;
  // timespec_get(&ts, TIME_UTC); // TIME_UTC macro here indicates
  //                              // that we want to now the seconds since EPOCH
  // printf("%ld s, %ld ns\n", ts.tv_sec, ts.tv_nsec);
  // double float_time = ts.tv_sec + ts.tv_nsec / 1000000000.0;
  // printf("%f seconds since epoch\n", float_time);
  //

  // Compute differences between time IN SECONDS [ difftime(time0, time1) ]
  struct tm time_a = {
      .tm_year = 82,  // years since 1900
      .tm_mon = 3,    // months since January -- [0, 11]
      .tm_mday = 12,  // day of the month -- [1, 31]
      .tm_hour = 4,   // hours since midnight -- [0, 23]
      .tm_min = 00,   // minutes after the hour -- [0, 59]
      .tm_sec = 04,   // seconds after the minute -- [0, 60]
      .tm_isdst = -1, // Daylight Saving Time flag
  };

  struct tm time_b = {
      .tm_year = 120, // years since 1900
      .tm_mon = 10,   // months since January -- [0, 11]
      .tm_mday = 15,  // day of the month -- [1, 31]
      .tm_hour = 16,  // hours since midnight -- [0, 23]
      .tm_min = 27,   // minutes after the hour -- [0, 59]
      .tm_sec = 00,   // seconds after the minute -- [0, 60]
      .tm_isdst = -1, // Daylight Saving Time flag
  };

  time_t cal_a = mktime(&time_a);
  time_t cal_b = mktime(&time_b);
  double diff = difftime(cal_b, cal_a);
  double years = diff / 60 / 60 / 24 / 365.2425; // close enough
  printf("%f seconds (%f years) between events\n", diff, years);
}
