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
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

// Functions
int mainLoop();
// Important "constants"
int MAX_X, MAX_Y;
int CURS_X, CURS_Y;
int running = 1;
char key;
FILE* ofile;
int main(int argc, char *argv[]){
	
	// Initializing the curses session
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(TRUE);
	// Main loop
	while(running){	
	refresh();
	getmaxyx(stdscr, MAX_Y, MAX_X);
	mvprintw(0,0,"%i", MAX_X); 	
	key = getch();
	if(key == KEY_F(1))
		running = 0;
	}
	// End curses session
	getch(); //Debug
	endwin();
	return 0;
}
int mainLoop(){
}
