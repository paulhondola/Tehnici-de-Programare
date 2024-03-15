CC = clang
CFLAGS = -Wall -Wextra -pedantic -Wconversion -I.
DEPS = queue.h
FILES = main.c queue.c
EXECUTABLE = exe

run: $(FILES) $(DEPS)
	$(CC) -o $(EXECUTABLE) $(FILES) $(CFLAGS)
	./$(EXECUTABLE) 1 1 32

leaks: run
	leaks -q --atExit -- ./$(EXECUTABLE) 0 1 16
