#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int matrix[MAX][MAX];

void fill_square(int n, int m, int k, int fill) {
  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++)
      matrix[n + i][m + j] = fill;
}

void generate_matrix(int n, int m, int k) {
  int fill = 0;
  for (int i = 0; i < n; i += k) {
    for (int j = 0; j < m; j += k) {
      fill_square(i, j, k, fill);
      fill = !fill;
    }

    if (m / k % 2 == 0)
      fill = !fill;
  }
}

void print_matrix(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int n = 24;
  int m = 12;
  int k = 2;

  generate_matrix(n, m, k);
  print_matrix(n, m);

  return 0;
}
