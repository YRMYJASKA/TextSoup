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
// Files.h

#ifndef FILES_H
#define FILES_H

#include <string.h>
#include <fstream>

using namespace std;

// File Functions
bool fileExists(string& NAME); // Checks if there exists a file with a name
int getFileLength(ifstream file); // Get file's size (bytes, lines)
void getFileLines(string& NAME); // Load a file 
void writeToFile(string& NAME, vector<string> lines); // Write to file
void printFile(string NAME);
#endif // FILES_H
