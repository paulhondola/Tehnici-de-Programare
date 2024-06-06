#ifndef __CUBE_H
#define __CUBE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 10
typedef struct {
  unsigned len;
  char color[MAX_NAME_LEN];
} cube_t;

cube_t read_cube_data(FILE *file);
void read_cube_array(FILE *file, cube_t arr[], int size);

void print_cube_data(FILE *file, cube_t item);
void print_cube_array(FILE *file, cube_t arr[], int size);

#endif
