/*
    Dat Nguyen
    CS-210
    Module 3: Project One
    File: clock_functions.cpp
    Purpose: This implementation file defines the utility functions used in the clock program.
            It includes the logic for setting the initial time, processing user choices,
            validating individual time components, and displaying the menu.
*/

#include "clock_functions.h" // Include the function declarations
#include "clock.h"           // Include the clock operations
#include <iostream>          // Include for input/output stream operations
#include <limits>            // Include for numeric limits used in input validation

using namespace std;        // Use the standard namespace to avoid prefixing std::

extern bool isPM;  // Declare external linkage for isPM, which is defined in clock.cpp

// Sets the initial time for both the 12-hour and 24-hour clocks.
void SetInitialTime(int& hour12, int& minute12, int& second12, int& hour24, int& minute24, int& second24) {
    cout << endl << "Set initial time for the clocks." << endl;
    // Prompt the user to input the hour and ensure it's in the valid range (0-23)
    while (true) {
        cout << endl << "Enter the hour (0-23): ";
        cin >> hour24;
        if (cin.fail() || hour24 < 0 || hour24 >= 24) {
            // Input validation failed, prompt the user again after clearing the error state
            cout << endl << "Invalid input, please enter a number between 0 and 23." << endl;
            cin.clear(); // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input
        } else {
            // Valid input received, break the loop
            break;
        }
    }

    // Determine AM/PM status based on the 24-hour time input
    isPM = hour24 >= 12;

    // Adjust the hour for the 12-hour clock, handle noon and midnight cases
    hour12 = hour24 % 12;
    if(hour24 == 0) { // Midnight
        hour12 = 12;
        isPM = false; // Set to false because 00:00 in 24-hour time is 12:00 AM
    } else if (hour24 == 12) { // Noon
        isPM = true;  // Set to true because 12:00 in 24-hour time is 12:00 PM
    } else if (hour24 > 12) { // Afternoon/Evening
        hour12 = hour24 - 12;
    }

    // Get and validate input for minutes and seconds from the user
    minute12 = GetValidatedTimeComponent("minutes");
    second12 = GetValidatedTimeComponent("seconds");

    // Initialize the 24-hour clock's minutes and seconds to match the 12-hour clock
    minute24 = minute12;
    second24 = second12;
}

// Processes user choices from the menu and performs the corresponding clock operation.
void ProcessUserChoices(int& hour12, int& minute12, int& second12, int& hour24, int& minute24, int& second24) {
    int choice; // Store the user's choice from the menu
    bool exitProgram = false; // Flag to determine when to exit the menu loop

    // Continue displaying the menu and processing choices until the user decides to exit
    while (!exitProgram) {
        // Display both clocks with the current time
        DisplayTime(hour12, minute12, second12, hour24, minute24, second24);

        // Show the menu and prompt the user for their choice
        DisplayMenu();
        cin >> choice;

        // Validate the choice and perform the corresponding action
        if (!cin) {
            // If input is not an integer, handle the error and prompt again
            cin.clear(); // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input
            cout << endl << "Invalid input, please try again." << endl;
        } else {
            // Handle the user's menu selection
            switch (choice) {
                case 1:
                    // Add one hour to both the 12-hour and 24-hour clocks
                    AddOneHour(hour12, false); // Pass false for 12-hour clock
                    AddOneHour(hour24, true);  // Pass true for 24-hour clock
                    break;
                case 2:
                    // Add one minute to both the 12-hour and 24-hour clocks
                    AddOneMinute(hour12, minute12, false); // Pass false for 12-hour clock
                    AddOneMinute(hour24, minute24, true);  // Pass true for 24-hour clock
                    break;
                case 3:
                    // Add one second to both the 12-hour and 24-hour clocks
                    AddOneSecond(hour12, minute12, second12, false); // Pass false for 12-hour clock
                    AddOneSecond(hour24, minute24, second24, true);  // Pass true for 24-hour clock
                    // Check for midnight transition to toggle AM/PM indicator
                    if (hour24 == 0 && hour12 == 12) {
                        isPM = false; // After midnight it should be AM
                    }
                    break;
                case 4:
                    // Set the flag to exit the program
                    exitProgram = true;
                    break;
                default:
                    // Handle invalid menu options
                    cout << endl << "Invalid option, please try again." << endl;
            }
        }
    }
}

// Prompts the user for a specific time component (hours, minutes, or seconds) and validates it.
int GetValidatedTimeComponent(const string& componentName) {
    int component; // Store the time component entered by the user
    // Prompt for input until a valid time component is received
    while (true) {
        cout << endl << "Enter the " << componentName << " (0-59): ";
        cin >> component;
        if (cin.fail() || component < 0 || component >= 60) {
            // If input is invalid, prompt the user again after clearing the error state
            cout << endl << "Invalid input, please enter a number between 0 and 59." << endl;
            cin.clear(); // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input
        } else {
            // Valid input received, break the loop
            break;
        }
    }
    return component; // Return the validated time component
}

// Prints the clock operation menu to the console.
void DisplayMenu() {
    // Display a header with asterisks for aesthetics
    cout << "*************************" << endl;
    // List each menu option with a number and description
    cout << "* 1 - Add One Hour      *" << endl;
    cout << "* 2 - Add One Minute    *" << endl;
    cout << "* 3 - Add One Second    *" << endl;
    cout << "* 4 - Exit Program      *" << endl;
    // Display a footer with asterisks for aesthetics
    cout << "*************************" << endl << endl << endl;
    // Prompt the user to select a menu option
    cout << "Enter choice (1-4): ";
}
