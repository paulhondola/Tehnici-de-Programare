CC = clang
CFLAGS = -Wall -Wextra -Wpedantic

SRC = client.c kvs.c
HEADER = kvs.h

EXE = exe

all: $(SRC)
	clear
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)
	./$(EXE)
