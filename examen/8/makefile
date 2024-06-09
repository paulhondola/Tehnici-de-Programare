NAME = 8
CC = gcc-14
CFLAGS = -fanalyzer -Wall -Wextra
SRC = src/main.c lib/hdd.c
EXE = exe/$(NAME).exe

run:
	clear
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)
	./$(EXE)

leaks: run
	leaks -q --atExit -- ./$(EXE)
