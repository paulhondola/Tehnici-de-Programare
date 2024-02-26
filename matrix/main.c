#include "files.h"
#include "matrix.h"
#include "matrix_data.h"

#define INPUT_FILE_NAME "date.txt"
#define OUTPUT_FILE_NAME "output.txt"

int main(void) {

  FILE *input_file = open_file(INPUT_FILE_NAME, "r");

  FILE *output_file = open_file(OUTPUT_FILE_NAME, "w");

  matrix_std_t a = {0, 0, NULL};
  matrix_std_t b = {0, 0, NULL};

  if (fscanf(input_file, "%d %d", &a.rows, &a.collumns) != 2) {
    printf("Invalid input -> a\n");
    return 1;
  };

  a = init_matrix_std(a.rows, a.collumns);

  read_data_matrix_std(&a, input_file);

  if (fscanf(input_file, "%d %d", &b.rows, &b.collumns) != 2) {
    printf("Invalid input -> b\n");
    return 1;
  };

  b = init_matrix_std(b.rows, b.collumns);

  read_data_matrix_std(&b, input_file);

  matrix_std_t c = {0, 0, NULL};
  matrix_std_t d = {0, 0, NULL};

  c = multiply_matrix_std(&a, &b);

  print_matrix_std(&c, output_file);

  d = multiply_matrix_std(&a, &c);

  print_matrix_std(&d, output_file);

  free_matrix_std(&a);

  free_matrix_std(&b);

  free_matrix_std(&c);
  free_matrix_std(&d);

  close_file(input_file);
  close_file(output_file);

  return 0;
}
