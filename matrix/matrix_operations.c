#include "matrix_operations.h"

matrix_std_t add_matrix_std(matrix_std_t *a, matrix_std_t *b) {

  if (a->rows != b->rows || a->collumns != b->collumns) {
    perror("Invalid matrix addition: a->rows != b->rows or a->collumns != "
           "b->collumns");
    exit(1);
  }

  matrix_std_t c = init_matrix_std(a->rows, a->collumns);

  matrix_size_t i, j;

  for (i = 0; i < a->rows; i++) {
    for (j = 0; j < a->collumns; j++) {
      c.data[i][j] = a->data[i][j] + b->data[i][j];
    }
  }

  return c;
}

matrix_std_t multiply_matrix_std(matrix_std_t *a, matrix_std_t *b) {

  if (a->collumns != b->rows) {
    perror("Invalid matrix multiplication: a->collumns != b->rows");
    exit(1);
  }

  matrix_std_t c = init_matrix_std(a->rows, b->collumns);

  matrix_size_t i, j;

  for (i = 0; i < a->rows; i++) {
    for (j = 0; j < b->collumns; j++) {
      c.data[i][j] = 0;
      for (matrix_size_t k = 0; k < a->collumns; k++) {
        c.data[i][j] += a->data[i][k] * b->data[k][j];
      }
    }
  }

  return c;
}

matrix_std_t transpose_matrix_std(matrix_std_t *m) {
  matrix_std_t t = init_matrix_std(m->collumns, m->rows);

  matrix_size_t i, j;

  for (i = 0; i < m->rows; i++) {
    for (j = 0; j < m->collumns; j++)
      t.data[j][i] = m->data[i][j];
  }

  return t;
}
