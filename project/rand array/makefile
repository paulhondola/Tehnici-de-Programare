CC = clang
CFLAGS = -lm -Wall -Wextra -Wpedantic
SRC = main.c rand_array.c
EXE = exe
OUTPUT_FILES = rand_arrays.txt gauss.txt poisson.txt
OPTION = 3

run:
	clear
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)
	./$(EXE) $(OPTION) $(OUTPUT_FILES)
