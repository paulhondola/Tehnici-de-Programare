NAME = cube
CC = gcc-14
CFLAGS = -fanalyzer -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)
EXE = $(NAME).exe

run:
	clear
	$(CC) $(CFLAGS) -c $(SRC)

leaks: run
	leaks -q --atExit -- ./$(EXE)
