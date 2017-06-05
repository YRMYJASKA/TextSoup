// files.h

#ifndef FILES_H
#define FILES_H

#include <fstream>
#include <string.h>

using namespace std;

// File Functions
bool fileExists(string &NAME);			      // Checks if there exists a file with a name
int getFileLength(ifstream file);		      // Get file's size (bytes, lines)
void getFileLines(string &NAME);		      // Load a file
void writeToFile(string &NAME, vector<string> lines); // Write to file
void printFile(string NAME);			      // Write buffer to file

#endif // FILES_H
