// Implementati o functie care citeste de la intrarea standard valori naturale
// (citirea se opreste la intalnirea primei valori de 0) si afiseaza cele mai
// mari trei valori de trei cifre care nu se gasesc printre numerele citite.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAPACITY 1000

unsigned *generate_array(void) {

  unsigned *arr = NULL;

  arr = calloc(CAPACITY, sizeof(unsigned));

  unsigned input = 0;

  while (1) {
    if (scanf("%u", &input) != 1 || input == 0) {
      break;
    }

    if (input >= 100 && input <= 999) {
      arr[input] = 1;
    }
  }

  return arr;
}

unsigned *find_largest_values(unsigned *arr) {
  unsigned *largest_values = calloc(3, sizeof(unsigned));

  unsigned largest = 0;
  unsigned second_largest = 0;
  unsigned third_largest = 0;

  for (unsigned i = 999; i >= 100; i--) {
    if (arr[i] == 1) {
      if (largest == 0) {
        largest = i;
      } else if (second_largest == 0) {
        second_largest = i;
      } else if (third_largest == 0) {
        third_largest = i;
        break;
      }
    }
  }

  largest_values[0] = largest;
  largest_values[1] = second_largest;
  largest_values[2] = third_largest;

  return largest_values;
}

int main(void) {

  clock_t start, end;
  double cpu_time_used;

  start = clock();

  unsigned *arr = generate_array();

  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("\nTime taken to generate array: %f\n", cpu_time_used);

  for (unsigned i = 100; i < CAPACITY; i++) {
    printf("%u ", arr[i]);
  }

  start = clock();

  unsigned *largest_values = find_largest_values(arr);

  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("\nTime taken to find 3 biggest values: %f\n", cpu_time_used);

  printf("Largest values:\n");
  for (unsigned i = 0; i < 3; i++) {
    printf("%u ", largest_values[i]);
  }

  free(arr);
  free(largest_values);

  return 0;
}
