CC=g++
SRC=src/main.cpp src/lines.cpp
FLAGS=-lncurses
OUTPUT=textSoup
all:
	$(CC) $(SRC) -o $(OUTPUT) $(FLAGS)
