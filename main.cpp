/*
    Dat Nguyen
    CS-210
    Module 3: Project One
    File: main.cpp
    Purpose: This program simulates a 12-hour and a 24-hour clock.
            The user can set the initial time and then add hours, minutes, or seconds to the clocks.
            The program allows the user to view and modify the time in both clocks simultaneously.
*/

#include "clock.h"             // Include the interface for clock operations
#include "clock_functions.h"   // Include the declarations for additional clock functions
#include <iostream>            // Include for input/output stream operations
#include <limits>              // Include for numeric limits used in input validation

using namespace std;          // Use the standard namespace to avoid prefixing std::

int main() {
    // Declare variables to hold the current time for both 12-hour and 24-hour formats
    int hour12, minute12, second12;  // Variables for the 12-hour clock time components
    int hour24, minute24, second24;  // Variables for the 24-hour clock time components

    // Call the function to set the initial time of the 12-hour and 24-hour clocks
    SetInitialTime(hour12, minute12, second12, hour24, minute24, second24);

    // Enter the main loop to process user choices for modifying the time
    ProcessUserChoices(hour12, minute12, second12, hour24, minute24, second24);

    return 0;  // Exit the program with a status code of 0 (success)
}
