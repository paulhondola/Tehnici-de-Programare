#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINES 10
#define MAX_COLLUMNS 10
#define MAX_MATRIX_VALUE 100

int *init_matrix(int lines, int collumns) {
  int *matrix = (int *)malloc(lines * collumns * sizeof(int));

  srand(time(NULL));

  for (int i = 0; i < lines * collumns; i++) {
    matrix[i] = rand() % MAX_MATRIX_VALUE;
  }

  return matrix;
}

void print_matrix(int **matrix, int lines, int collumns) {
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < collumns; j++) {
      printf("%d ", *((*matrix) + i * collumns + j));
    }
    printf("\n");
  }
}

int main(void) {
  int *matrix = init_matrix(MAX_LINES, MAX_COLLUMNS);

  print_matrix(&matrix, MAX_LINES, MAX_COLLUMNS);

  free(matrix);

  return 0;
}
