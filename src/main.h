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

#ifndef LINES_H
#define LINES_H

#include <string.h>
#include <vector>
#include <fstream>

// Some constant values
#define BUFF_SIZE 1024
#define TOP_PADDING 2
#define LEFT_PADDING 4

using namespace std;

// General routines for the program
void updateScr(); // Updating the screen 
void getLocation(); // Get the location of source code
#endif // LINES_H
