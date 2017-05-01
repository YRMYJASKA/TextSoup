CC=g++
SRC=src/main.cpp src/lines.cpp
FLAGS=-lncurses -Wall -Wpedantic
OUTPUT=textSoup
all:
	$(CC) $(SRC) -o $(OUTPUT) $(FLAGS)
