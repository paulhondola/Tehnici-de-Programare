CC = clang
CFLAGS = -Wall -Wextra -pedantic
EXE = exe
SRC = student.c sort_students.c
OBJ = student.o sort_students.o
HEADERS = student.h

all:
	clear
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
	rm $(OBJ)
	./$(EXE)
