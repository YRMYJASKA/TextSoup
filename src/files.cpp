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

// lines.cpp
#include <ncurses.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>

#include "files.h"

using namespace std;

// Write the current LineBuffer to a file
void writeToFile(string& NAME, vector<string> lines) {
	ofstream oFILE;
	oFILE.open(NAME.c_str());  // Open the file for writing
	for (unsigned int y = 0; y < lines.size(); y++)  // Write the given
							 // buffer line-by-line
							 // to the destination
							 // file
		oFILE << lines[y].substr(0, lines[y].length()) << endl;
	oFILE.close();  // close the file after we are done
}

// Check if a file exists
bool fileExists(string& NAME) {
	// Pretty self-explanatory...
	ifstream file(NAME.c_str());
	return file.good();
}
// Used to get the contents of files like help.txt
void printFile(string NAME) {
	string line;
	ifstream iFILE(NAME);
	while (iFILE) {
		getline(iFILE, line);
		cout << line << endl;
	}
	iFILE.close();
}
