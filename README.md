# TextSoup 

Yet another text editor


# Installation:
## Requirements
* ``` git ```
* ``` make ```
* ``` g++ 6.3 ```
* ``` C++11 ```
* ``` nCurses ``` , a C/C++ library
## Installing
1. ``git clone https://github.com/yrmyjaska/TextSoup``

Clone the git repository to a directory

2. ``cd TextSoup``

Change to the TextSoup directory

3. ``sudo make install && make``

Add the textSoup directory to the PATH environment variable and generate config files.

Then build the program using make
# Usage
``soup [file name | --help | --license | --version]``

	--help: Shows this message
	--license: Shows the GPL license of this program (You run '| less' witht his command)
	--version: Just displays the current version of this program

Controls:
	
	<Ctrl>Q : Exit program 
	<Ctrl>S : Save the current buffer into the file name specified at startup
	<Ctrl>O : Open a file by a certain name
	<Ctrl>C : Exit a choice or prompt (eg. whilst saving you can press <Ctrl>C to cancel it)
# Copyright
Copyright (C) 2017 Jyry Hjelt
