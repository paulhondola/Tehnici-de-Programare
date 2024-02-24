CC = clang
CFLAGS = -Wall -Wextra -pedantic -Wconversion -I.
DEPS = files.h matrix.h
FILES = main.c files.c matrix.c
EXECUTABLE = exe

run: $(FILES) $(DEPS)
	$(CC) -o $(EXECUTABLE) $(FILES) $(CFLAGS)
