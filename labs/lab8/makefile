COMPILER = clang
FLAGS = -Wall -Wextra -Wpedantic
SRC = main.c
OBJ = main.o list.o
EXECUTABLE = exe

TARGET = all

$(TARGET) : $(FILES)
	clear
	$(COMPILER) $(FLAGS) -c $(SRC)
	$(COMPILER) -o $(EXECUTABLE) $(OBJ)
	./$(EXECUTABLE)
