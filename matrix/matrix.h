#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef int matrix_data_t;

typedef struct {
  int rows, collumns;
  matrix_data_t **data;
} matrix_t;

matrix_t init_matrix(int rows, int collumns);

void read_matrix_data(matrix_t *matrix, FILE *file);

void print_matrix(matrix_t *matrix, FILE *file);

void free_matrix(matrix_t *matrix);

matrix_data_t quadrant_sum(matrix_t *matrix, int option);

#endif
