CC = clang
CFLAGS = -Wall -Wextra -Wpedantic
TARGETS = main.c hs_utils.c
HEADERS = hs_utils.h
EXECUTABLE = exe

all: $(TARGETS) $(HEADERS)
	clear
	$(CC) $(CFLAGS) -c hs_utils.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(TARGETS)
	rm -f *.o
	./$(EXECUTABLE)
