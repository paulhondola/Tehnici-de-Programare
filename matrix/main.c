#include "files.h"
#include "matrix.h"

#define FILE_NAME "date.txt"

#define MAX_ROWS 100
#define MAX_COLS 100

int main(void) {
  FILE *file = open_file(FILE_NAME, "r");

  int n = 0;

  if (fscanf(file, "%d", &n) != 1) {
    perror("Invalid input");
    exit(1);
  }

  matrix_t m = init_matrix(n, n);

  read_matrix_data(&m, file);

  print_matrix(&m, stdout);

  for (int i = 1; i <= 4; i++)
    printf("%d -> %d\n", i, quadrant_sum(&m, i));

  free_matrix(&m);

  close_file(file);
  return 0;
}
