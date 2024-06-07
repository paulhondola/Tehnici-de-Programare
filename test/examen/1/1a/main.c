#include <stdio.h>
#include <stdlib.h>

/*
1. Se citesc dintr-un fisier transmis ca si parametru in linie de comanda, un
numar natural n (n<=100000) si apoi n numere intregi. Se parcurge vectorul
format din aceste numere, salvand sumele elementelor consecutive. Dupa fiecare
parcurgere se afiseaza numarul iteratiei si vectorul rezultat. Se va repeta
acest pas pana cand vectorul va contine un singur numar. Exemplu

intrare:

5
2 5 7 -3 9

Afiseaza:
Iteratia 1: 7 12 4 6
Iteratia 2: 19 16 10
Iteratia 3: 35 26
Iteratia 4: 61
*/

void print_array(int array[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}

void rec_array_sum(int array[], int size) {
  if (size < 0)
    return;

  print_array(array, size);
  for (int i = 0; i < size - 1; i++)
    array[i] = array[i] + array[i + 1];

  return rec_array_sum(array, size - 1);
}

int main(void) {

  int size = 5;
  int array[] = {2, 5, 7, -3, 9};

  rec_array_sum(array, size);

  return 0;
}
