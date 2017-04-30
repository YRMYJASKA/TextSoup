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
int MAX_X, MAX_Y; // Window's current dimensions
int CURS_X = 0, CURS_Y = 0; // Cursor's position
int key; // The value of the key presses is stored into 'int key'
FILE* ofile; // Output file
string fileName = ""; // Name of the file
vector<string> LineBuffer(1); //the buffer that stores the lines

int main(int argc, char *argv[]){
	// If there was an file name inputted
	if(argc > 1){
		fileName = argv[1];
	}

	// Initializing the curses session
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(TRUE);
	
	// Main loop
	bool running = true;
	while(running){	
		// Update
		updateScr();	
		key = getch(); // Fetch keypress
		switch(key){
			// Exit (^Q)
			case 17:
				running = false;
			break;
			// Backspace
			case 127:
			case KEY_BACKSPACE:
				if(CURS_X >= 0){
					LineBuffer[CURS_Y].erase(CURS_X, 1);
					CURS_X--;
				}else{
					if(CURS_Y > 0){
						LineBuffer.erase(LineBuffer.begin() + CURS_Y);
						CURS_Y--;
					}
				}
			break;
			// Enter
			case int('\n'):
				LineBuffer.resize(LineBuffer.size()+1);
				CURS_Y++;
			break;
			//Add the keypress to the current line
			default:
				LineBuffer[CURS_Y] += char(key);
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
	refresh();
	getmaxyx(stdscr, MAX_Y, MAX_X);
	for(int i = 0; i < LineBuffer.size(); i++)
		mvprintw(i,1,LineBuffer[i].c_str());
}

