#include "cube.h"
#include <stdio.h>

// READING

cube_t read_cube_data(FILE *file) {
  cube_t item = {0, "\0"};

  if (fscanf(file, "%d ", &item.len) != 1)
    return (cube_t){0, "\0"};

  if (fgets(item.color, MAX_NAME_LEN, file) == NULL)
    return (cube_t){0, "\0"};

  // check if the name ends with a newline

  unsigned len = strlen(item.color);
  if (item.color[len - 1] == '\n')
    item.color[len - 1] = '\0';

  return item;
}

void read_cube_array(FILE *file, cube_t arr[], int size) {
  for (int i = 0; i < size; i++)
    arr[i] = read_cube_data(file);
}

// PRINTING

void print_cube_data(FILE *file, cube_t item) {
  fprintf(file, "SIZE: %d COLOR: %s\n", item.len, item.color);
}

void print_cube_array(FILE *file, cube_t arr[], int size) {
  for (int i = 0; i < size; i++)
    print_cube_data(file, arr[i]);
}
