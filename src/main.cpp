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

using namespace std;
// Important variables
int MAX_X, MAX_Y; // Window's current dimensions
int CURS_X = 0, CURS_Y = 0; // Cursor's position
int key; // The value of the key presses is stored into 'int key'
FILE* ofile;
string fileName = ""; // Name of the file
int main(int argc, char *argv[]){
	
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
		refresh();
		getmaxyx(stdscr, MAX_Y, MAX_X);
		
		key = getch(); // Fetch keypress
		switch(key){
			// Exit
			case KEY_F(1):
			running = false;
			break;
			// Backspace
			case 127:
			break;
			//Add the keypress to the line
			default:
			break;
		}
		clear();
	}
	// Terminate the program
	endwin();
	return 0;
}
