// files.hpp
#ifndef FILES_H
#define FILES_H

// Include the libraries
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

// File Functions
bool fileExists(string &NAME);                        // Checks if there exists a file with a name
int getFileLength(ifstream file);                     // Get file's size (bytes, lines)
vector<string> getFileLines(string &NAME);            // Load a file
void writeToFile(string &NAME, vector<string> lines); // Write to file
void printFile(string NAME);                          // Write buffer to file

#endif // FILES_H
