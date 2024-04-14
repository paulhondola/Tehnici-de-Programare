NAME = arraylist
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)
HEADER = $(NAME).h
EXPORT_OBJ = $(NAME).o
EXE = $(NAME).exe

all:
	clear
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
	./$(EXE)
	cp $(EXPORT_OBJ) "/Users/paulhondola/Faculta/Tehnici de Programare/OBJECT_FILES"
	cp $(HEADER) "/Users/paulhondola/Faculta/Tehnici de Programare/HEADER_FILES"

leaks: run
	leaks -q --atExit -- ./$(EXE)
