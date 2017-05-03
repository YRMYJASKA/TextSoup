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
// lines.h

// TODO: change the name to something more clear. lines.h isn't used just for line handling anymore.
#ifndef LINES_H
#define LINES_H

#include <string.h>
#include <vector>
#include <fstream>

#define BUFF_SIZE 1024

#define TOP_PADDING 2
#define LEFT_PADDING 4
using namespace std;

// Declare fuctions for the program
void updateScr(); // Updating the screen 
void writeToFile(string& NAME, vector<string> lines); // Write to file

bool fileExists(string& NAME); // Checks if there exists a file with a name
int getFileLength(ifstream file); // Get file's size (bytes, lines)
void getFileLines(string& NAME); // Load a file 


#endif // LINES_H
