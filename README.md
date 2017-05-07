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

3. ``./install && make``

Add the textSoup directory to the PATH environment variable and build the program using make

# Usage

# TODO:
### URGENT:
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
