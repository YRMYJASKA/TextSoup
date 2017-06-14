CC=g++
SRC=src/main.cpp src/files.cpp
FLAGS=-lncurses -Wall -std=c++11
OUTPUT=bin/textSoup
all:
	$(CC) $(SRC) -o $(OUTPUT) $(FLAGS)
install:
	# Run with sudo
	# Make the binary directory for textsoup
	mkdir bin
	# Make the binary directory usable (This is executed as root...)
	chmod 777 bin

	# Add the program to the PATH
	echo "export PATH=${PATH}:$(shell pwd)/bin" >> ~/.profile || echo "Error adding to PATH in .profile!"
	echo "export PATH=${PATH}:$(shell pwd)/bin" >> ~/.zshrc || echo "Error adding to PATH in .zshrc!"
	echo "export PATH=${PATH}:$(shell pwd)/bin" >> ~/.bashrc || echo "Error adding to PATH in .bashrc!"

	# Creating /etc/ config files
	mkdir /etc/textSoup
	echo "$(shell pwd)" > /etc/textSoup/location

	# Logs in /var/log/
	touch /var/log/textsoup.log
	# Make the log file writeable
	chmod 666 /var/log/textsoup.log
uninstall:
	# Run with sudo
	
	rm -r bin
	
	rm -r /etc/textSoup/ 
	
	rm /var/log/textsoup.log
	
	echo "Remember to remove PATH exports in your profile files!"

