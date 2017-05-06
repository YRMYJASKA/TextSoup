/*
*    TextSoup, Yet another text editor
*    Copyright (C) 2017  Jyry Hjelt
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*/
// main.cpp

// Include the libraries
#include <iostream>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>

#include "lines.h"

using namespace std;

// Important variables
unsigned int MAX_X, MAX_Y; // Window's current dimensions
unsigned int CURS_X = 0,  CURS_Y = 0; // Cursor's position
int key; // The value of the key presses is stored into 'int key'
string fileName = ""; // Name of the file
vector<string> LineBuffer(1); //the buffer that stores the lines
bool running = true;
unsigned lineArea = 0; // Variable used to draw more lines that the screens height allows
int main(int argc, char *argv[]){
	// If there was an file name inputted
	if(argc > 1){
		fileName = argv[1];
	}else{
		cout << "Please enter a file name or a correct flag!" << endl;
		cout << "Enter 'soup --help' display usage and help" << endl;
		return 1;	
	}
	if(ifstream(fileName)){
		getFileLines(fileName);
	}
	// Initializing the curses session
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
	start_color();
	// Initialize colour pairs for different colours
	init_pair(1, COLOR_BLACK, COLOR_WHITE); // Inverted colour pair (cursor)
	// Add the cursor buffer to the first line
	LineBuffer[0] = " ";	
	// Main loop
	while(running){	
		// Update
		updateScr();	
		key = getch(); // Fetch keypress
		switch(key){
			// Exit (^Q)
			case 17:
				running = false;
			break;
			// Save (^S)
			case 19:
				writeToFile(fileName, LineBuffer);
			break;
			// Backspace
			case 127:
			case KEY_BACKSPACE:
				if(CURS_X > 0){
					LineBuffer[CURS_Y].erase(CURS_X-1, 1); // Delete the character under the cursor
					if(CURS_X > 0)
						CURS_X--; // Move the cursor to the left
				}else{
					if(CURS_Y > 0){ // Checking we are not deleting the first line
						LineBuffer[CURS_Y - 1].pop_back(); // Delete the cursor buffer
						CURS_X = LineBuffer[CURS_Y-1].length(); // Set the cursors X value at the corect position
						LineBuffer[CURS_Y - 1] += LineBuffer[CURS_Y]; // Append the string above with the remains of the last line
						LineBuffer.erase(LineBuffer.begin() + CURS_Y);
						CURS_Y--; // Change to the line above
						if(CURS_Y < lineArea && lineArea > 0)
							lineArea--;
					}
				}

			break;
			// Enter
			case int('\n'):
				//LineBuffer.resize(LineBuffer.size()+1); // Adding a room for the new line in the buffer
				// Add the text on te rights side of the cursor to the new line below
				if(true){
					LineBuffer.insert(LineBuffer.begin() + CURS_Y + 1, LineBuffer[CURS_Y].substr(CURS_X, LineBuffer[CURS_Y].length()));				
				}else{
					LineBuffer.insert(LineBuffer.begin() + CURS_Y + 1, LineBuffer[CURS_Y].substr(CURS_X, LineBuffer[CURS_Y].length()));				
				}
				LineBuffer[CURS_Y].erase(CURS_X, LineBuffer[CURS_Y].length()-1); // Erase the right side from the previous line
				// If the last line didnt have a cursor buffer
				if(LineBuffer[CURS_Y].back() != ' ')
					LineBuffer[CURS_Y] += ' '; // Add the cursor buffer to the end of the line
				// Set correct  Y and X values
				CURS_Y++;
				if(CURS_Y >= MAX_Y-TOP_PADDING)
						lineArea++;

				CURS_X = 0;
			break;
			// Arrow keys
			case KEY_LEFT:
				if(CURS_X != 0){
					 CURS_X--;
				}
	
			break;
			case KEY_RIGHT:
				if(CURS_X < LineBuffer[CURS_Y].length() - 1){
					CURS_X++;
				}

			break;
			case KEY_UP:
				if(CURS_Y != 0){
					CURS_Y--;
					if(CURS_X + 1>= LineBuffer[CURS_Y].length())
						CURS_X = LineBuffer[CURS_Y].length()-1;
				        if(CURS_Y < lineArea && lineArea > 0)
						lineArea--;	
				}
			break;
			case KEY_DOWN:
				if(CURS_Y + 1 < LineBuffer.size()){
					CURS_Y++;
					if(CURS_X + 1 >= LineBuffer[CURS_Y].length())
						CURS_X = LineBuffer[CURS_Y].length()-1; 
					if(CURS_Y >= MAX_Y-TOP_PADDING)
						lineArea++;
				}
			break;
			//Add the keypress to the current line
			default:
				LineBuffer[CURS_Y].insert(LineBuffer[CURS_Y].begin()+CURS_X, char(key));
				CURS_X += 1;
			break;
		}
		clear();
	}
	// Terminate the program
	endwin();
	return 0;
}
void updateScr(){
	// Refresh
	refresh();
	getmaxyx(stdscr, MAX_Y, MAX_X);
	attron(COLOR_PAIR(1));
	// Print status bar
	mvprintw(0,0, fileName.c_str());
	mvprintw(0, fileName.length()," %i,%i L: %i LineArea: %i", CURS_X, CURS_Y, LineBuffer.size(), lineArea);
	attroff(COLOR_PAIR(1));
	int z = 0;
	for(unsigned int i = 0; i < LineBuffer.size(); i++){
		// Draw the line
		if(i < lineArea)
			continue;

		mvprintw(z + TOP_PADDING, 0, "%d", i+1);
		if(i == CURS_Y){ // If this line has te cursor on it
			for(unsigned int x = 0; x < LineBuffer[i].length(); x++){
				if(x == CURS_X){
					attron(COLOR_PAIR(1));
					mvprintw(z + TOP_PADDING, x+LEFT_PADDING , "%c", LineBuffer[i].at(x));	// Draw the cursor to the correct position. 
					attroff(COLOR_PAIR(1));
				}
				else{
					mvprintw(z + TOP_PADDING, x + LEFT_PADDING, "%c", LineBuffer[i].at(x));	// Draw the regular character
				}
			}
		}
		else{ // If not the cursor line draw without special handling
			mvprintw(z + TOP_PADDING, LEFT_PADDING,LineBuffer[i].c_str()); 
		}
		z++;
	}
}
void getFileLines(string& NAME){
	string line;
	ifstream iFILE;
	iFILE.open(NAME.c_str()); // Open the file stream
	// Write the file line-by-line to the LineBuffer
	while(getline(iFILE, line)){
		LineBuffer.push_back(line+" ");
	}
	iFILE.close(); // Close file stream
}
