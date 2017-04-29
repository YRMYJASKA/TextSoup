CC=g++
SRC=src/main.cpp 
FLAGS=-lncurses
OUTPUT=textSoup
all:
	$(CC) $(SRC) -o $(OUTPUT) $(FLAGS)
