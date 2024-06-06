#include "cube/cube.h"

#define STACK_INIT_VALUE -1

int successor(int stack[], int stack_level, int stack_size) {
  if (stack[stack_level] >= stack_size - 1)
    return 0;

  stack[stack_level]++;
  return 1;
}

int valid_cube_condition(cube_t a, cube_t b) {
  return a.len < b.len && strcmp(a.color, b.color) != 0;
}

int valid(cube_t cubes[], int stack[], int stack_level) {

  for (int i = 0; i < stack_level; i++)
    if (stack[i] == stack[stack_level] ||
        !valid_cube_condition(cubes[stack[i]], cubes[stack[i + 1]]))
      return 0;

  return 1;
}

int solution(int stack_level, int stack_size) {
  return stack_level == stack_size - 1;
}

void print_solution(FILE *file, cube_t cubes[], int stack[], int stack_size) {
  for (int i = 0; i < stack_size; i++)
    // fprintf(file, "%d ", stack[i]);
    print_cube_data(file, cubes[stack[i]]);

  fputc('\n', file);
}

int back(FILE *file, cube_t cubes[], int max_stack_size, int min_stack_size) {
  int permutations = 0;

  for (int i = min_stack_size; i <= max_stack_size; i++) {

    fprintf(file, "////////// SIZE %d //////////\n", i);

    int stack_level = 0;
    int stack[i];
    stack[stack_level] = STACK_INIT_VALUE;

    while (stack_level > STACK_INIT_VALUE) {
      if (successor(stack, stack_level, max_stack_size)) {
        if (valid(cubes, stack, stack_level)) {
          if (solution(stack_level, i)) {
            print_solution(file, cubes, stack, i);
            permutations++;
          } else {
            stack_level++;
            stack[stack_level] = STACK_INIT_VALUE;
          }
        } else {
          ;
        }
      } else {
        stack_level--;
      }
    }
  }

  return permutations;
}

int comp_cube_size_asc(const void *p, const void *q) {
  return (*(cube_t *)p).len - (*(cube_t *)q).len;
}

void sort_cubes(cube_t arr[], int size) {
  qsort(arr, size, sizeof(cube_t), comp_cube_size_asc);
}

int main(void) {

  FILE *file = stdin;
  int arr_size = 0, stack_size = 0;

  if (fscanf(file, "%d %d ", &arr_size, &stack_size) != 2)
    return 1;

  cube_t arr[arr_size];

  read_cube_array(file, arr, arr_size);

  sort_cubes(arr, arr_size);

  print_cube_array(stdout, arr, arr_size);

  back(stdout, arr, arr_size, stack_size);

  return 0;
}
