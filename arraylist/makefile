CC = gcc
CFLAGS = -Wall -Wextra -Wconversion -pedantic
SRC = main.c arraylist.c
HEADERS = arraylist.h
EXE = arraylist.exe

all: $(SRC) $(HEADERS)
	clear
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)
	./$(EXE) > log
