#include "files.h"
#include "matrix.h"

#define INPUT_FILE_NAME "date.txt"
#define OUTPUT_FILE_NAME "output.txt"

#define MAX_ROWS 100
#define MAX_COLS 100

int main(void) {

  FILE *input = open_file(INPUT_FILE_NAME, "r");

  int n = 0;

  if (fscanf(input, "%d", &n) != 1) {
    perror("Invalid Input!");
    exit(1);
  }

  matrix_std_t m = init_matrix(n, n);

  read_matrix_data(&m, input);

  close_file(input);

  FILE *output = open_file(OUTPUT_FILE_NAME, "w");

  print_matrix(&m, output);

  close_file(output);

  matrix_block_t b = convert_matrix_to_block(&m);

  output = open_file(OUTPUT_FILE_NAME, "a");

  print_matrix_block(&b, output);

  close_file(output);

  free_matrix(&m);
  free_matrix_block(&b);

  return 0;
}
