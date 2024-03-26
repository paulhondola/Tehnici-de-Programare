CC = clang
CFLAGS = -Wall -Wextra -Wpedantic

FILES = client.c kvs.c kvs.h

EXE = exe

all: $(FILES)
	clear
	$(CC) $(CFLAGS) -c kvs.c
	$(CC) $(CFLAGS) -c client.c
	$(CC) $(CFLAGS) -o $(EXE) client.o kvs.o
	rm -f *.o
	./$(EXE)
