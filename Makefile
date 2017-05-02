CC=g++
SRC=src/main.cpp src/lines.cpp
FLAGS=-lncurses -Wall -std=c++14
OUTPUT=textSoup
all:
	$(CC) $(SRC) -o $(OUTPUT) $(FLAGS)
