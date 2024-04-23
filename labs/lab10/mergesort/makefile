NAME = merge_sort
CC = gcc-13
CFLAGS = -fanalyzer -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)
EXE = $(NAME).exe

run:
	clear
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
	./$(EXE)

leaks: run
	leaks -q --atExit -- ./$(EXE)
