COMPILER = clang
FLAGS = -Wall -Wextra -Werror -Wpedantic
FILES = main.c list.c
HEADERS = list.h
EXECUTABLE = exe

run: $(FILES) $(HEADERS)
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) $(FILES)
	./$(EXECUTABLE)

leaks: run
	leaks --atExit -q -- ./$(EXECUTABLE)
