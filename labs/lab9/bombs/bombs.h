#ifndef __BOMBS_H
#define __BOMBS_H

#include <stdio.h>
#include <stdlib.h>

enum bomb_type { FALSE, TRUE };

typedef struct BOMB {
  int x;
  int y;
  int radius;
  enum bomb_type state;
} bomb_t;

// READING
void read_index_data(size_t *count, size_t *index, FILE *file);
bomb_t read_bomb_data(FILE *file);
bomb_t *read_bomb_array_data(size_t count, FILE *file);

// WRITING
void print_bomb_data(bomb_t bomb, FILE *file);
void print_bomb_array_data(bomb_t *bombs, size_t count, FILE *file);
void print_bomb_statistics(bomb_t *bombs, size_t count, FILE *file);
// AUX
int is_in_radius(bomb_t main, bomb_t secondary);
void explode(bomb_t main_bomb, bomb_t *bombs, size_t count);

#endif
