#include "/Users/paulhondola/Faculta/Tehnici de Programare/proiect/rand array/rand_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CHUNK 1024
#define MAX_ELEMENT 100000
#define MAX_RUNS 10
#define MIN_SIZE 10
#define MAX_SIZE 50000

/*
a) Implementati o functie cu prototipul int findElemLin(int v[], unsigned n, int
x) care returneaza pozitia primei aparitii a elementului x in vectorul v avand n
elemente sau -1 daca acel numar nu apare in vector. Se va folosi un algoritm cu
complexitate liniara (spre exemplu
https://en.wikipedia.org/wiki/Linear_search#Basic_algorithm).
*/

int find_elem_lin(int *v, unsigned n, int x) {

  clock_t start, end;
  double cpu_time_used;

  start = clock();

  for (unsigned i = 0; i < n; i++) {
    if (v[i] == x) {

      end = clock();
      cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

      printf("%f\n", cpu_time_used);

      return i;
    }
  }

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%f\n", cpu_time_used);

  return -1;
}

/*
b) Implementati o
functie cu prototipul int findElemBin(int v[], unsigned n, int x) cauta
elementul, similar cu cerinta de la punctul a), dar opereaza asupra unui vector
sortat. Pentru rezolvare se va folosi un algoritm cu complexitate logartimica,
mai precis "cautarea binara", prin apelul adecvat al functiei bsearch din
stdlib.h.
*/

int comparator(const void *p, const void *q) {

  int a = *((int *)p);
  int b = *((int *)q);

  return a - b;
}

void sort_array(int *v, unsigned n) {
  qsort(v, (size_t)n, sizeof(v[0]), comparator);
}

int find_elem_bin(int *v, unsigned n, int x) {

  clock_t start, end;
  double cpu_time_used;

  start = clock();

  int *ptr = bsearch(&x, v, n, sizeof(v[0]), comparator);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("%f\n", cpu_time_used);

  if (ptr == NULL)
    return -1;

  return ptr - v;
}

/*
c) Masurati timpul de executie pentru un numar semnificativ de rulari
ale celor doua functii (spre exemplu 100 de rulari) si repetati acest proces
pentru un set de date din ce in ce mai mare (spre exemplu de la 100 de elemente
la 50000 de elemente din 100 de rulări). Tipariti datele pe iesirea standard si
redirectati iesirea spre un fisier .csv, iar mai apoi reprezentati grafic
rezultatele facand observatii asupra timpilor de executie raportat la marimea
datelor de intrare. Obs: Pentru generarea vectorilor cu date se va folosi una
dintre functiile create la prima sesiune de Proiect (pentru cerinta (b) este
necesar sa folositi functia de generare care primeste si pointer la functie,
deoarce trebuie generate numere cu ajutorul unei "politici"; in caz extrem
puteti genera un vector pseudoaleator uniform distribuit pe care mai apoi sa il
sortati);
*/

void print_array(int *arr, unsigned n) {
  for (unsigned i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {

  srand(time(NULL));

  unsigned size = rand() % (MAX_SIZE - MIN_SIZE + 1);

  int *array = make_rand_array(size);

  print_array(array, size);

  return 0;
}
