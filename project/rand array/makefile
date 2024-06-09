CC = clang
CFLAGS = -lm -Wall -Wextra -Wpedantic
SRC = src/main.c lib/rand_array.c
EXE = src/exe
OUTPUT_FILES = output/rand_arrays.txt output/gauss.txt output/poisson.txt
OPTION = 3

run:
	clear
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)
	./$(EXE) $(OPTION) $(OUTPUT_FILES)
