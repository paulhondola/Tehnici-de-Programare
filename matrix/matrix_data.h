#ifndef __MATRIX_DATA_H
#define __MATRIX_DATA_H

#include <stdio.h>
#include <stdlib.h>

typedef int matrix_data_t;
typedef int matrix_size_t;

typedef struct {
  matrix_size_t rows, collumns;
  matrix_data_t **data;
} matrix_std_t;

typedef struct {
  matrix_size_t rows, collumns;
  matrix_data_t *data;
} matrix_block_t;

#endif
