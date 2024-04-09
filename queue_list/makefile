CC = clang
CFLAGS = -Wall -Wextra -pedantic
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)
EXE = exe

all:
	clear
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
	./$(EXE)
