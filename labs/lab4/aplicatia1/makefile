CC = clang
CFLAGS = -Wall -Wextra -pedantic -Wconversion -I.
DEPS = stack.h
FILES = main.c stack.c
EXECUTABLE = exe

compile: $(FILES) $(DEPS)
	$(CC) -o $(EXECUTABLE) $(FILES) $(CFLAGS)

run: compile
	./$(EXECUTABLE)

leaks: compile
	leaks -q --atExit -- ./$(EXECUTABLE)
