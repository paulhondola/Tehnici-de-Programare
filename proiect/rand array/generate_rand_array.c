#include "rand_array.h"
#include <stdio.h>

void rand_arr(unsigned n) {
  int *arr = make_rand_array(n);

  printf("\nStandard random array:\n");

  for (unsigned i = 0; i < n; i++)
    printf("%d ", arr[i]);

  free(arr);
}

void rand_limit(unsigned n, unsigned a, unsigned b) {
  int *arr = make_rand_array(10);

  arr = make_rand_limit_array(n, a, b);

  printf("\n\nLimited random array:\n");

  for (unsigned i = 0; i < n; i++)
    printf("%d ", arr[i]);

  free(arr);
}

void rand_flex_asc(unsigned n, unsigned steps) {

  int *arr_flex = make_rand_flexi_array(n, get_new_element_asc, steps);

  printf("\n\nASC random array:\n");

  for (unsigned i = 0; i < n; i++)
    printf("%d ", arr_flex[i]);

  free(arr_flex);
}

void rand_flex_desc(unsigned n, unsigned steps) {

  int *arr_flex = make_rand_flexi_array(n, get_new_element_desc, steps);

  printf("\n\nDESC random array:\n");

  for (unsigned i = 0; i < 10; i++)
    printf("%d ", arr_flex[i]);

  free(arr_flex);
}

int main(void) {

  srand(time(NULL));

  // rand_arr(10);

  // rand_limit(1000, 0, 100000);

  rand_flex_asc(10, 1000);

  // rand_flex_desc(10, 1000);

  return 0;
}
