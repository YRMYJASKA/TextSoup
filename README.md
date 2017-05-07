# TextSoup 

Yet another text editor


# Installation:
## Requirements
* ``` git ```
* ``` make ```
* ``` g++ 6.3 ```
* ``` C++14 ```
* ``` nCurses ``` , a C/C++ library
## Installing
1. ``git clone https://github.com/yrmyjaska/TextSoup``

Clone the git repository to a directory

2. ``cd TextSoup``

Change to the TextSoup directory

3. ``make``

Build the program using make

Remember to add the directory to your PATH variabel to use outside of the original directory.

(An installation script incoming soon)
# Usage

# TODO:
### URGENT:
* Installation script that installs the program easily
* Tab support and automatic indenting
	* Now you can press tab to append 4 sapces into a string, but still doesn't work well with actual tabs
	* Find out how to count how many spaces in front of a string to make automatic indenting
### POLISH:
* Add multi-threading for the update routine to stop the flickering
* Fix .travis.yml to build the project correctly in g++4.9+ **(or switch services)**
### FEATURES:
* Syntax highlighting
	* C++
	* C
	* Python
	* (More languages)
* Search function
* Save to a different file
* Config file (.souprc)
# Copyright
Copyright (C) 2017 Jyry Hjelt
