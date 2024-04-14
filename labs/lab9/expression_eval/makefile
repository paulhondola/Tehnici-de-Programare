CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)
EXE = expr

all:
	clear
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
	./$(EXE)
