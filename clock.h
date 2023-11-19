/*
    Dat Nguyen
    CS-210
    Module 3: Project One
    File: clock.h
    Purpose: Header file for the clock program.
            This file contains the declarations of the functions that manipulate time for both
            12-hour and 24-hour clock formats. These functions include adding hours, minutes,
            and seconds to the current time and displaying the time.
*/

#ifndef CLOCK_H  // Preprocessor guard to prevent multiple inclusions of header file
#define CLOCK_H

// Adds one hour to the given hour component. If is24HourClock is true, it rolls over after 23.
void AddOneHour(int& hour, bool is24HourClock);

// Adds one minute to the given minute component and rolls over to the next hour if necessary.
void AddOneMinute(int& hour, int& minute, bool is24HourClock);

// Adds one second to the given second component and rolls over to the next minute if necessary.
void AddOneSecond(int& hour, int& minute, int& second, bool is24HourClock);

// Displays the current time in both 12-hour and 24-hour formats side by side.
void DisplayTime(int hour12, int minute12, int second12, int hour24, int minute24, int second24);

#endif
