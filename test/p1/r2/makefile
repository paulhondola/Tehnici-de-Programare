CC = clang
CFLAGS = -Wall -Wextra -pedantic
EXE = exe
SRC = stack.c main.c
OBJ = stack.o main.o
HEADERS = stack.h

all:
	clear
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
	rm $(OBJ)
	./$(EXE)
