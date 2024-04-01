#include "matrix.h"

#define PI 3.14159265359
#define ROWS 3
#define COLS 3

void assign_table(matrix_t m, size_t rows, size_t cols,
                  element_t values[rows][cols]) {
  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++)
      if (assign_value(m, i, j, values[i][j]) == MATRIX_OVERFLOW)
        printf("matrix overflow\n");
}

int main(void) {

  matrix_t m1 = init_matrix(ROWS, COLS);
  matrix_t m2 = init_matrix(ROWS + 1, COLS + 1);

  element_t values1[ROWS][COLS + 1] = {{PI * 1, PI * 2, PI * 3},
                                       {PI * 5, PI * 6, PI * 7},
                                       {PI * 9, PI * 10, PI * 11}};

  element_t values2[ROWS + 1][COLS + 1] = {
      {PI * 1, PI * 2, PI * 3, PI * 4},
      {PI * 4, PI * 5, PI * 6, PI * 7},
      {PI * 7, PI * 8, PI * 9, PI * 10},
      {PI * 10, PI * 11, PI * 12, PI * 13}};

  assign_table(m1, ROWS, COLS, values1);

  assign_table(m2, ROWS + 1, COLS + 1, values2);

  matrix_t m3 = sum(m1, m2);

  printf("\nMATRIX 1\n");
  print_matrix(m1);

  printf("\nMATRIX 2\n");
  print_matrix(m2);

  printf("\nMATRIX 3\n");
  print_matrix(m3);

  vector_t v = filter(m3, bigger, 40);

  printf("\nFILTERED VECTOR\n");
  print_vector(v);

  free_vector(v);
  free_matrix(m1);
  free_matrix(m2);
  free_matrix(m3);
  return 0;
}
