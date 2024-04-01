CC = clang
CFLAGS = -Wall -Wextra -pedantic
EXE = exe
SRC = matrix.c client.c
OBJ = matrix.o client.o
HEADERS = matrix.h

all:
	clear
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
	rm $(OBJ)
	./$(EXE)
