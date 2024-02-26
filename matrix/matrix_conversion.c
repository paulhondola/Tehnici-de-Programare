#include "matrix_conversion.h"

matrix_block_t convert_matrix_to_block(matrix_std_t *m) {
  matrix_block_t block = init_matrix_block(m->rows, m->collumns);

  for (matrix_size_t i = 0; i < m->rows; i++)
    for (matrix_size_t j = 0; j < m->collumns; j++)
      block.data[i * m->collumns + j] = m->data[i][j];

  return block;
}

matrix_std_t convert_block_to_matrix(matrix_block_t *b) {
  matrix_std_t m = init_matrix(b->rows, b->collumns);

  for (matrix_size_t i = 0; i < b->rows; i++)
    for (matrix_size_t j = 0; j < b->collumns; j++)
      m.data[i][j] = b->data[i * b->collumns + j];

  return m;
}
