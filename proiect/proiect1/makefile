CC = clang
CFLAGS = -Wall -Wextra -Wpedantic

FILES = main.c rand_array.c rand_array.h

EXE = exe

all: $(FILES)
	clear
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c rand_array.c
	$(CC) $(CFLAGS) -o $(EXE) main.c rand_array.c
	rm -f *.o
	./$(EXE)
