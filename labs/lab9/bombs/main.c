#include "bombs.h"

int main(void) {

  FILE *input = fopen("bombs.in", "r");
  if (input == NULL) {
    perror("Failed to open input file\n");
    exit(-1);
  }

  FILE *output = fopen("bombs.out", "w");
  if (output == NULL) {
    perror("Failed to open output file\n");
    exit(-1);
  }

  size_t count = 0, index = 0;
  read_index_data(&count, &index, input);
  fprintf(output, "count = %zu, index = %zu\n", count, index);
  fprintf(output, "......................................................\n");

  bomb_t *bombs = read_bomb_array_data(count, input);
  print_bomb_array_data(bombs, count, output);

  explode(bombs[index - 1], bombs, count);

  fprintf(output, "......................................................\n");

  print_bomb_array_data(bombs, count, output);

  free(bombs);
  fclose(input);
  fclose(output);

  return 0;
}
