/*
Se genereaza aleator un vector A formati din numere naturale, din intervalul
1-100, pe un total de  200 pozitii. Se genereaza tot aleator un numar natural B,
in intervalul 1-2. Se parcurge  vectorul A, “eliminand” din el elementele de pe
pozitii impare, daca B=1 sau pare daca B=2. Dupa fiecare parcurgere se afiseaza
numarul iteratiei si vectorul. Se continua pana cand mai este doar un singur
element.

Exemplu

intrare:
A= 2 5 7 8 9 10 1 3 6 4 (simplificat)
B=1

Afiseaza:
Iteratia 1: 5 8 10 3 4
Iteratia 2: 8 3
Iteratia 3: 3
*/

#include "rand_lib.h"
#include <stdio.h>
#include <time.h>

int iteration = 0;

void print_array(int array[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}

void remove_elements(int array[], int size, int opt) {

  // opt 1 -> remove even positions
  if (size == 0)
    return;

  printf("Iteration %d: ", iteration++);
  print_array(array, size);

  int jump = 1;
  for (int i = 2 - opt; i <= size / 2; i++) {
    array[i] = array[i + jump++];
  }

  // 1 -> start removing from 1
  // 2 -> start removing from 0

  if (size > 1 && size % 2 && opt == 1) {
    remove_elements(array, size / 2 + 1, opt);
  } else
    remove_elements(array, size / 2, opt);
}

#define SIZE 200
#define LOWER_LIMIT 0
#define UPPER_LIMIT 100

int main(void) {

  int *A = generate_random_array(SIZE, LOWER_LIMIT, UPPER_LIMIT);
  int B = generate_random_number(1, 2);

  remove_elements(A, SIZE, B);
  return 0;
}
