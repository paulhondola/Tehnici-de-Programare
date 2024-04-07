COMPILER = clang
FLAGS = -Wall -Wextra -Wpedantic
FILES = main.c list.c
OBJ = main.o list.o
HEADERS = list.h
EXECUTABLE = exe

run: $(FILES) $(HEADERS)
	clear
	$(COMPILER) $(FLAGS) -c $(FILES)
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) $(OBJ)
	./$(EXECUTABLE) > log

leaks: run
	leaks --atExit -q -- ./$(EXECUTABLE)
