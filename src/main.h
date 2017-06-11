// main.h

#ifndef MAIN_H
#define MAIN_H

// Some constant values
#define TOP_PADDING 2  // Padding to print the status bar
#define LEFT_PADDING 4 // Padding fo the line numbers

// Define the control key values
#define Q 17
#define S 19
#define C 3
#define ENTER int('\n')

// Enum for the message bar's status
enum MsgBarStatus { SAVE, OPEN, EXIT, CLEAR };

// General routines for the program
void updateScr();    // Updating the screen
void getLocation();  // Get the location of source code
void handleMsgBar(MsgBarStatus status); // Handle the message bar's prompt

#endif // MAIN_H
