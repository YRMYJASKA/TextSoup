CC=gcc
SRC=src/main.c  
FLAGS=-lncurses
OUTPUT=textSoup
all:
	$(CC) $(SRC) -o $(OUTPUT) $(FLAGS)
