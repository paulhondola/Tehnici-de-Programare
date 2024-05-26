NAME = 3
CC = gcc-14
CFLAGS = -fanalyzer -Wall -Wextra
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)
EXE = $(NAME).exe

run:
	clear
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
	./$(EXE) 2 2 ae
	./$(EXE) 2 2 af
	./$(EXE) 10 3 abcdefghij

leaks: run
	leaks -q --atExit -- ./$(EXE)
