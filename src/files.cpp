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
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <vector>

#include "files.h"
#include "logging.hpp"

using namespace std;

// Write the current LineBuffer to a file
void writeToFile(string &NAME, vector<string> lines) {
	ofstream outfile;
	outfile.open(NAME.c_str()); // Open the file for writing

	// Write the given line buffer into the file
	for (unsigned int y = 0; y < lines.size(); y++) {
		outfile << lines[y].substr(0, lines[y].length() - 1) << endl;
	}
	outfile.close(); // close the file after we are done

	// Log the event
	string msg = "Wrote " + to_string(lines.size()) + " lines into a file";
	Logging::logEntry(msg, Logging::INFO);
}

// Check if a file exists
bool fileExists(string &NAME) {
	// Pretty self-explanatory...
	ifstream file(NAME.c_str());
	return file.good();
}
// Used to get the contents of files like help.txt
void printFile(string NAME) {
	string line;
	ifstream infile;
	infile.open((NAME.c_str()));
	while (infile) {
		getline(infile, line);
		cout << line << endl;
	}
	infile.close();

	// Log the event
	string msg = "Printed file to terminal. (" + NAME + ")";
	Logging::logEntry(msg, Logging::INFO);
}
// Get a file's lines
vector<string> getFileLines(string &NAME) {
	string line;	  // Buffer for the line
	vector<string> lines; // A buffer for the lines
	ifstream infile;
	infile.open(NAME.c_str()); // Open the file stream

	// Write the file line-by-line to the lines variable
	while (getline(infile, line)) {
		lines.push_back(line + " "); // Append every line to the LineBuffer
	}
	infile.close(); // Close file stream


	return lines;
}
