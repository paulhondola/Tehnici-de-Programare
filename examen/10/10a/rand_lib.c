#include "rand_lib.h"
#include <stdlib.h>
#include <time.h>

int *generate_random_array(int size, int lower, int upper) {
  int *array = malloc(size * sizeof(*array));

  if (array == NULL)
    return NULL;

  srand(time(NULL));
  for (int i = 0; i < size; i++)
    array[i] = rand() % (upper - lower + 1) + lower;

  return array;
}

int generate_random_number(int lower, int upper) {
  srand(time(NULL));
  return rand() % (upper - lower + 1) + lower;
}
