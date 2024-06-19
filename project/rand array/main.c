#include "rand_array.h"
#include <stdio.h>

// RAND LIMIT PARAMETERS
#define SIZE 10000
#define LOWER 0
#define UPPER 100
#define STEPS 10
#define INIT_VALUE 100

// DISTRIBUTION PARAMETERS
#define MEAN 0.0
#define STANDARD_DEVIATION 1.0
#define LAMBDA 2.45

void print_int_array(FILE *file, int *array, unsigned n) {
  for (unsigned i = 0; i < n; i++)
    fprintf(file, "%d ", array[i]);
}

void print_double_array(FILE *file, double *arr, unsigned n) {
  for (unsigned i = 0; i < n; i++)
    fprintf(file, "%lf\n", arr[i]);
}

void rand_arr(FILE *file, unsigned n) {
  int *arr = make_rand_array(n);

  fprintf(file, "Standard random array:\n");

  print_int_array(file, arr, n);

  free(arr);
}

void rand_limit(FILE *file, unsigned n, unsigned a, unsigned b) {
  int *arr = make_rand_array(10);

  arr = make_rand_limit_array(n, a, b);

  fprintf(file, "\n\nLimited random array:\nLOWER LIMIT: %d | UPPER LIMIT:%d\n",
          a, b);

  print_int_array(file, arr, n);

  free(arr);
}

void rand_flex_asc(FILE *file, unsigned n, int init_value, unsigned steps) {

  int *arr = make_rand_flexi_array(n, init_value, get_new_element_asc, steps);

  fprintf(file, "\n\nASC random array:\nINIT VALUE: %d | MAX STEPS: %d\n",
          init_value, steps);

  print_int_array(file, arr, n);

  free(arr);
}

void rand_flex_desc(FILE *file, unsigned n, int init_value, unsigned steps) {

  int *arr = make_rand_flexi_array(n, init_value, get_new_element_desc, steps);

  fprintf(file, "\n\nDESC random array:\nMAX STEPS: %d\n", steps);

  print_int_array(file, arr, n);

  free(arr);
}

int prj_1_procedure(char *filepath, size_t size) {
  FILE *file = fopen(filepath, "w");

  if (file == NULL) {
    perror("Invalid file path!");
    return 0;
  }

  rand_arr(file, size);
  rand_limit(file, size, LOWER, UPPER);
  rand_flex_asc(file, size, INIT_VALUE, STEPS);
  rand_flex_desc(file, size, INIT_VALUE, STEPS);

  return 1;
}

int prj_2_procedure(char *filepath_gauss, char *filepath_poisson, size_t size) {

  FILE *file1 = fopen(filepath_gauss, "w");

  if (file1 == NULL) {
    perror("Invalid file path!");
    return 0;
  }

  FILE *file2 = fopen(filepath_poisson, "w");

  if (file2 == NULL) {
    perror("Invalid file path!");
    return 0;
  }

  double *gauss = generate_gauss_distribution(size, MEAN, STANDARD_DEVIATION);

  double *poisson = generate_poisson_distribution(size, LAMBDA);

  fprintf(file1, "GAUSSIAN DISTRIBUTION\nMEAN: %lf | STD DEV:%lf\n", MEAN,
          STANDARD_DEVIATION);

  print_double_array(file1, gauss, size);

  fprintf(file2, "POISSON DISTRIBUTION\nLAMBDA: %lf\n", LAMBDA);

  print_double_array(file2, poisson, size);

  free(gauss);
  free(poisson);

  return 1;
}

int main(int argc, char **argv) {

  size_t size = SIZE;

  if (argc != 5) {
    perror("Invalid arg count!");
    return 1;
  }

  srand(time(NULL));

  // 1 for running the first part -> random arrays
  // 2 for running the second part -> gauss / poisson arrays
  // 3 for running both

  int option = atoi(argv[1]);

  switch (option) {
  case 1:
    if (prj_1_procedure(argv[2], size) == 0)
      return 2;
    break;
  case 2:
    if (prj_2_procedure(argv[3], argv[4], size) == 0)
      return 3;
    break;
  case 3:
    if (prj_1_procedure(argv[2], size) == 0)
      return 4;
    if (prj_2_procedure(argv[3], argv[4], size) == 0)
      return 5;
    break;
  default:
    perror("Invalid option!");
    break;
  }

  return 0;
}
