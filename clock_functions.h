/*
    Dat Nguyen
    CS-210
    Module 3: Project One
    File: clock_functions.h
    Purpose: This header file contains declarations for utility functions used in the clock program.
            It defines the interface for setting the initial time, processing user choices,
            validating individual time components, and displaying the menu.
*/

#ifndef CLOCK_FUNCTIONS_H  // Prevent multiple inclusions of header
#define CLOCK_FUNCTIONS_H

#include <string> // Include the string header to use std::string

// Sets the initial time for both 12-hour and 24-hour clocks based on user input.
void SetInitialTime(int& hour12, int& minute12, int& second12, int& hour24, int& minute24, int& second24);

// Processes the user choices for adding time or exiting the program.
void ProcessUserChoices(int& hour12, int& minute12, int& second12, int& hour24, int& minute24, int& second24);

// Validates and returns a time component (hour, minute, or second) entered by the user.
int GetValidatedTimeComponent(const std::string& componentName);

// Displays the user menu with options to add time or exit the program.
void DisplayMenu();

#endif
