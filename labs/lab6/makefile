CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -lm

EXE = exe

k_th:
	$(CC) $(CFLAGS) -o $(EXE) k_th.c
	time ./$(EXE) 13

3_val:
	$(CC) $(CFLAGS) -o $(EXE) 3_val.c
	time ./$(EXE) < random_numbers.txt

binary_search:
	$(CC) $(CFLAGS) -c binary_search.c
	$(CC) $(CFLAGS) -o $(EXE) binary_search.o rand_array.o
	./$(EXE) > output.csv
