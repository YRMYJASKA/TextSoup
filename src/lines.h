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

#define BUFF_SIZE 1024
using namespace std;

void updateScr();

int getFileLength(ifstream file);
vector<string> getFileLines(ifstream file); 
#endif // LINES_H
