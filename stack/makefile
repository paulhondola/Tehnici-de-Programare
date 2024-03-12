CC = clang
CFLAGS = -Wall -Wextra -pedantic -Wconversion -I.
DEPS = stack.h
FILES = main.c stack.c
EXECUTABLE = exe

run: $(FILES) $(DEPS)
	$(CC) -o $(EXECUTABLE) $(FILES) $(CFLAGS)
	./$(EXECUTABLE)

leaks: run
	leaks -q --atExit -- ./$(EXECUTABLE)
