// main.h
#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>

using namespace std;

// Some constant values
#define TOP_PADDING 3  // Padding to print the status bar
#define LEFT_PADDING 4 // Padding fo the line numbers

// Results of searchFile will be sotred into this array in the format of:
// x,y (line, column)
vector<vector<int>> searchResults;

// Define the control key values
#define Q 17
#define S 19
#define C 3
#define O 15
#define F 6
#define ENTER int('\n')

// Enum for the message bar's status
enum MsgBarStatus { SAVE, OPEN, EXIT, FIND, CLEAR };

// General routines for the program
void updateScr();			// Updating the screen
void getLocation();			// Get the location of source code
void handleMsgBar(MsgBarStatus status); // Handle the message bar's prompt
int spacesLastLine(int y);

// Searching
void searchFile(string s);

#endif // MAIN_H
