CC = clang
CFLAGS = -Wall -Wextra -Wpedantic

FILES = generate_rand_array.c rand_array.c rand_array.h

EXE = exe

all: $(FILES)
	clear
	$(CC) $(CFLAGS) -c generate_rand_array.c
	$(CC) $(CFLAGS) -c rand_array.c
	$(CC) $(CFLAGS) -o $(EXE) generate_rand_array.c rand_array.c
	./$(EXE) > output.txt
