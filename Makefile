CC=g++
SRC=src/main.cpp src/files.cpp
FLAGS=-lncurses -Wall -std=c++11
OUTPUT=textSoup
all:
	$(CC) $(SRC) -o $(OUTPUT) $(FLAGS)
