#ifndef __MATRIX_STD_H
#define __MATRIX_STD_H

#include "matrix_data.h"

matrix_std_t init_matrix(int rows, int collumns);

void read_matrix_data(matrix_std_t *matrix, FILE *file);

void print_matrix(matrix_std_t *matrix, FILE *file);

void free_matrix(matrix_std_t *matrix);

matrix_data_t quadrant_sum(matrix_std_t *matrix, int option);

#endif
