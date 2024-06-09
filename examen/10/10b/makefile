NAME = 10b
CC = gcc-14
CFLAGS = -fanalyzer -Wall -Wextra
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)
EXE = $(NAME).exe

run:
	clear
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)
	./$(EXE)

leaks: run
	leaks -q --atExit -- ./$(EXE)
