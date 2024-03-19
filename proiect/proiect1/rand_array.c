#include "rand_array.h"

/*
1. Implementati o functie unsigned\* makeRandArray(unsigned seed, unsigned
n), care primeste un seed si un numar natural n si returneaza un vector
alocat dinamic, continand n numere naturale pseodoaleatoare, uniform
 distribuite
*/

unsigned *make_rand_array(unsigned n) {

  unsigned *arr = (unsigned *)malloc((size_t)n * sizeof(unsigned));

  if (arr == NULL)
    return NULL;

  for (unsigned i = 0; i < n; i++)
    arr[i] = rand();

  return arr;
}

/*
2. Implementati o functie int\* makeRandLimitArray(int seed, unsigned n, int a,
int b) care primeste un seed, si numerele naturale n, a si b si returneaza un
vector alocat dinamic, continand n numere intregi pseudoaleatoare, uniform
distribuite, cuprinse intre a si b
*/

unsigned *make_rand_limit_array(unsigned n, unsigned a, unsigned b) {

  if (a > b)
    return NULL;

  unsigned *arr = (unsigned *)malloc((size_t)n * sizeof(unsigned));

  if (arr == NULL)
    return NULL;

  for (unsigned i = 0; i < n; i++)
    arr[i] = a + rand() % (b - a + 1);

  return arr;
}

/*
3. Implementati o functie cu antetul int* makeRandFlexiArray(unsigned n, int
(*getNewElem)(int*, unsigned)) care genereaza un vector alocat dinamic
cuprinzand elemente numere psoedoaleatoare. Pentru generarea unui nou
element din vector se va face apel la o functie "concreta" primita sub forma
unui pointer la o functie care primeste drept argumente un tablou si numarul
sau curent de elemente. Implementati functii "concrete" pentru generarea
unor vectori monoton crescatori si monoton descrescatori.
*/

int get_new_element_asc(int *arr, unsigned n, unsigned steps) {
  return arr[n - 1] + rand() % steps;
}

int get_new_element_desc(int *arr, unsigned n, unsigned steps) {
  return arr[n - 1] - rand() % steps;
}

int *make_rand_flexi_array(unsigned n,
                           int (*get_new_element)(int *, unsigned, unsigned),
                           unsigned steps) {

  int *arr = (int *)malloc((size_t)n * sizeof(int));

  if (arr == NULL)
    return NULL;

  arr[0] = rand();

  for (unsigned i = 1; i < n; i++)
    arr[i] = get_new_element(arr, i, steps);

  return arr;
}
