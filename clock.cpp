/*
    Dat Nguyen
    CS-210
    Module 3: Project One
    File: clock.cpp
    Purpose: Implementation file for the clock program.
            This file defines the functions that manipulate time for both 12-hour and 24-hour clock formats.
            It includes adding hours, minutes, and seconds to the current time and displaying the time.
*/

#include "clock.h"             // Include the interface for clock operations
#include <iostream>            // Include for input/output stream operations
#include <iomanip>             // Include for input/output manipulation

using namespace std;          // Use the standard namespace to avoid prefixing std::

bool isPM = false;            // Global flag to track AM/PM status (PM if true)

// Adds one hour to the given hour, rolls over if necessary, and adjusts for 12 or 24-hour format.
void AddOneHour(int& hour, bool is24HourClock) {
    hour++; // Increment the hour
    // Conditional logic for handling 12-hour and 24-hour clock differences
    if (!is24HourClock) {
        // For 12-hour clock format
        if (hour == 12) {
            // Toggle AM/PM when reaching 12 o'clock
            isPM = !isPM;
        } else if (hour > 12) {
            // Reset to 1 after surpassing 12 hours
            hour = 1;
        }
    } else if (hour >= 24) {
        // For 24-hour clock format, reset to 0 after 23 hours
        hour = 0;
    }
}

// Adds one minute to the given minute, rolls over to the next hour if necessary.
void AddOneMinute(int& hour, int& minute, bool is24HourClock) {
    minute++; // Increment the minute
    if (minute >= 60) {
        // Reset minute to 0 and increment hour if 60 minutes are reached
        minute = 0;
        AddOneHour(hour, is24HourClock);
    }
}

// Adds one second to the given second, rolls over to the next minute if necessary.
void AddOneSecond(int& hour, int& minute, int& second, bool is24HourClock) {
    second++; // Increment the second
    if (second >= 60) {
        // Reset second to 0 and increment minute if 60 seconds are reached
        second = 0;
        AddOneMinute(hour, minute, is24HourClock);
    }
}

// Displays the current time in both 12-hour and 24-hour formats side by side.
void DisplayTime(int hour12, int minute12, int second12, int hour24, int minute24, int second24) {
    // Handling midnight (00:00) and noon (12:00) for 12-hour format display
    int displayHour12 = hour12 % 12;
    if (displayHour12 == 0) displayHour12 = 12; // Convert '0' hour to '12' for display

    // Begin output formatting
    cout << endl << endl;
    // Display top border of asterisks for visual separation of clocks
    cout << "*************************" << "         " << "*************************" << endl;
    // Display clock headers
    cout << "*     12-Hour Clock     *         *     24-Hour Clock     *" << endl;
    // Display the time for the 12-hour clock with appropriate padding and AM/PM notation
    cout << "*     " << setfill('0') << setw(2) << displayHour12 << ":"
         << setw(2) << minute12 << ":"
         << setw(2) << second12 << (isPM ? " PM" : " AM") << "       *         ";
    // Display the time for the 24-hour clock with appropriate padding
    cout << "*      " << setfill('0') << setw(2) << hour24 << ":"
         << setw(2) << minute24 << ":"
         << setw(2) << second24 << "         *" << endl;
    // Display bottom border of asterisks for visual separation of clocks
    cout << "*************************" << "         " << "*************************" << endl << endl << endl;
}
