COMPILER = clang
FLAGS = -Wall -Wextra -Werror -Wpedantic

FILES = random_lists.c lists.c
HEADERS = lists.h

EXECUTABLE = exe

TARGET = all

$(TARGET) : $(FILES) $(HEADERS)
	$(COMPILER) -o $(EXECUTABLE) $(FILES) $(FLAGS)