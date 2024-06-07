#ifndef __LIB_H
#define __LIB_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100
#define MAX_WORD_LEN 15

char **create_string_array(FILE *file, int *size);
void print_string_array(FILE *file, char **array, int size);

int back(char **array, int size);

#endif
