CC = clang
CFLAGS = -Wall -Wextra -pedantic
EXE = exe
SRC = pasager.c main.c
OBJ = pasager.o main.o
HEADERS = pasager.h

all:
	clear
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
	rm $(OBJ)
	./$(EXE)
