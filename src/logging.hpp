#ifndef LOGGING_H
#define LOGGING_H
// Logging header for the textSoup text editor
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#define LOG_FILE "/etc/textSoup/textsoup.log"

namespace Logging {

enum ErrType { WARN, FATAL, NOTE, INFO };

// Returns the string equivalent to the ErrType enum
inline string getErrorStr(Logging::ErrType type) {
	switch (type) {
	case WARN:
		return "WARNING";
	case FATAL:
		return "FATAL";
	case NOTE:
		return "NOTE";
	case INFO:
		return "INFO";
	}
	return "INTERNAL_ERROR!";
}

// Make a log entry to the specified file (or the default...)
inline void logEntry(string entry, Logging::ErrType type, string location = LOG_FILE) {
	ofstream outfile;
	// Get the correct time
	time_t t = time(NULL);
	tm time_now = *localtime(&t);
	// Get the string format of the error type
	string type_str = "[" + getErrorStr(type) + "] ";

	// Open the file for appending
	outfile.open(location, ios_base::app | ios_base::out);

	// Put the log entry together
	outfile << put_time(&time_now, "%D %H:%M:%S ") << type_str << entry << endl;

	// Close the file
	outfile.close();
}

// Print a 'end of session' statement to clearly distinguish sessions
inline void logEndSession(string location = LOG_FILE) {
	ofstream outfile;

	outfile.open(location, ios_base::app | ios_base::out);

	outfile << "----------END OF SESSION----------" << endl;

	outfile.close();
}

} // Logging
#endif // LOGGING_H
