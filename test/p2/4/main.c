#include <stdio.h>

#define MAX 100

typedef struct {
  int **data;
  int n;
} matrix_t;

matrix_t init() matrix_t read_data() void print_matrix(matrix_t);

void frecv(int a[][MAX], int n, int f[1000]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i > j && i + j >= n)
        f[a[i][j]]++;
    }
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  int a[MAX][MAX];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int f[1000] = {0};
  frecv(a, n, f);
  for (int i = 0; i < 1000; i++)
    if (f[i] >= 2)
      printf("%d ", i);

  return 0;
}
