#include "matrix_std.h"

matrix_std_t init_matrix_std(int rows, int collumns) {
  matrix_std_t m = {rows, collumns, NULL};

  m.data =
      (matrix_data_t **)malloc((unsigned long)rows * sizeof(matrix_data_t *));

  if (m.data == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  for (matrix_size_t i = 0; i < m.rows; i++) {
    m.data[i] = (matrix_data_t *)realloc(m.data[i], (unsigned long)collumns *
                                                        sizeof(matrix_data_t));
    if (m.data[i] == NULL) {
      printf("Memory allocation failed\n");
      exit(1);
    }
  }

  return m;
}

void read_data_matrix_std(matrix_std_t *m, FILE *file) {
  for (matrix_size_t i = 0; i < m->rows; i++)
    for (matrix_size_t j = 0; j < m->collumns; j++)
      if (fscanf(file, "%d", &m->data[i][j]) != 1) {
        printf("Invalid input\n");
        exit(1);
      }
}

void print_matrix_std(matrix_std_t *m, FILE *file) {
  for (matrix_size_t i = 0; i < m->rows; i++) {
    for (matrix_size_t j = 0; j < m->collumns; j++) {
      fprintf(file, "%d ", m->data[i][j]);
    }
    fprintf(file, "\n");
  }
}

void free_matrix_std(matrix_std_t *m) {
  for (matrix_size_t i = 0; i < m->rows; i++) {
    free(m->data[i]);
  }
  free(m->data);
  m->rows = 0;
  m->collumns = 0;
  m->data = NULL;
}

matrix_data_t sum_matrix_std(matrix_std_t *m) {
  matrix_data_t sum = 0;
  for (matrix_size_t i = 0; i < m->rows; i++)
    for (matrix_size_t j = 0; j < m->collumns; j++)
      sum += m->data[i][j];

  return sum;
}

matrix_data_t sum_above_primary_diagonal_matrix_std(matrix_std_t *m) {
  matrix_data_t sum = 0;

  for (matrix_size_t i = 0; i < m->rows; i++)
    for (matrix_size_t j = i + 1; j < m->collumns; j++)
      sum += m->data[i][j];

  return sum;
}

matrix_data_t sum_below_secondary_diagonal_matrix_std(matrix_std_t *m) {
  matrix_data_t sum = 0;

  for (matrix_size_t i = 0; i < m->rows; i++)
    for (matrix_size_t j = 0; j < i; j++)
      sum += m->data[i][j];

  return sum;
}

matrix_data_t quadrant_sum_matrix_std(matrix_std_t *m, int option) {

  matrix_data_t sum = 0;
  matrix_size_t i = 0, j = 0;
  // primary upper -> i < j
  // primary lower -> i > j
  // secondary upper -> i + j < n - 1
  // secondary lower -> i + j > n - 1
  // 1 -> top -> i < j && i + j < n - 1
  // 2 -> right -> i < j && i + j > n - 1
  // 3 -> bottom -> i > j && i + j > n - 1
  // 4 -> left -> i > j && i + j < n - 1

  switch (option) {
  case 1:
    for (i = 0; i < m->rows; i++)
      for (j = i + 1; j < m->rows; j++)
        if (i + j < m->rows - 1)
          sum += m->data[i][j];
    break;
  case 2:
    for (i = 0; i < m->rows; i++)
      for (j = i + 1; j < m->rows; j++)
        if (i + j > m->rows - 1)
          sum += m->data[i][j];
    break;
  case 3:
    for (i = 0; i < m->rows; i++)
      for (j = 0; j < i; j++)
        if (i + j > m->rows - 1)
          sum += m->data[i][j];
    break;
  case 4:
    for (i = 0; i < m->rows; i++)
      for (j = 0; j < i; j++)
        if (i + j < m->rows - 1)
          sum += m->data[i][j];
    break;
  default:
    printf("Invalid option\n");
    break;
  }
  return sum;
}
