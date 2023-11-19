```markdown
# Clock Program - CS 210 Project

## Overview
This project, developed as part of CS 210 at Southern New Hampshire University, is a C++ application that simulates a 12-hour and 24-hour clock. It allows users to set the initial time, add hours, minutes, or seconds to the time, and display the updated time in both 12-hour and 24-hour formats.

## Features
- Set initial time for both 12-hour and 24-hour clocks.
- Add hours, minutes, or seconds to the current time.
- Display the time in 12-hour (with AM/PM) and 24-hour formats.
- User-friendly console interface for interaction.

## How to Run
To run this program, ensure that you have a C++ compiler installed. Follow these steps:
1. Clone or download this repository to your local machine.
2. Navigate to the directory containing the project files.
3. Compile the source files. For example, using g++:
   ```bash
   g++ -o clockProgram clock.cpp clock_functions.cpp
   ```
4. Run the compiled program:
   ```bash
   ./clockProgram
   ```

## Files in the Project
- `clock.cpp`: Contains the core logic for time manipulation and display functions.
- `clock.h`: Header file with declarations for the clock functions.
- `clock_functions.cpp`: Contains functions for user input handling and menu display.
- `README.md`: This file explains how to run the project.

## How to Use
After starting the program, follow the on-screen prompts:
1. Set the initial time when prompted.
2. Choose an option to add hours, minutes, or seconds, or to exit the program.
3. The updated time will be displayed after each operation.

## Contributions
This project was developed by Dat Nguyen. Contributions, suggestions, and feedback are welcome.

## License
This project is licensed under the terms of the MIT license.
