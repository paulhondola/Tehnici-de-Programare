CC = clang
CFLAGS = -Wall -Wextra -pedantic -Wconversion -I.
DEPS = aux.h
FILES = main.c aux.c
EXECUTABLE = exe

run: $(FILES) $(DEPS)
	$(CC) -o $(EXECUTABLE) $(FILES) $(CFLAGS)

