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
#include <string.h>
#include <vector>
#include <fstream>
#include <ncurses.h>

#include "files.h"


using namespace std;
// Write the current LineBuffer to a file
void writeToFile(string& NAME, vector<string> lines){
	ofstream oFILE;
	oFILE.open(NAME.c_str()); // Open the file for writing
	for(unsigned int y = 0; y < lines.size(); y++)	
		oFILE << lines[y].substr(0,lines[y].length() ) << endl; // Write a line to file without the spacer " " for the cursor
	oFILE.close(); // close the file after we are done
}
// TODO: Implement/delete
int getFileLength(ifstream file){
	return 0;
}
// Check if a file exists
bool fileExists(string& NAME){
	// Pretty self-explanatory...
	ifstream file(NAME.c_str());
	return file.good();
}
