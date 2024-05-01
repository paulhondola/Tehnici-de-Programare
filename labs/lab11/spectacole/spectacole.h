#ifndef __SPECTACOLE_H
#define __SPECTACOLE_H

#include <stdio.h>

#define DEBUG 1
#define MAX_NAME_LEN 100
#define MAX_SPECTACOLE 100

typedef struct {
  int hour;
  int minute;
} time;

typedef struct {
  char name[MAX_NAME_LEN];
  time start;
  time end;
} spectacol;

spectacol *read_spectacol(FILE *input_file);
spectacol **read_all_spectacole(FILE *input_file, int *count);

void sort_spectacole(spectacol **spectacole, int count);

void print_spectacol(spectacol *spectacol);

#endif
