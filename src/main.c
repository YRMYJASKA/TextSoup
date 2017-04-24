#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

// Functions
int mainLoop();
// Important "constants"
int MAX_X, MAX_Y;
int CURS_X, CURS_Y;

int main(int argc, char *argv[]){
	
	// Initializing the curses session
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	// End curses session
	endwin();
	return 0;
}
int mainLoop(){
	return 0;
}
