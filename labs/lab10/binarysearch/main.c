/*
1. Algoritmul de cautare binara a unui element intr-un tablou ordonat.

a) Implementati o functie recursiva cu antetul int cataBin(int x, int v[],
unsigned stg, unsigned dr); care cauta elementul x in tabloul v ordonat (nu
conteaza daca crescator sau descrescator) si returneaza pozitia pe care sa
gaseste una dintre aparitiile lui x sau -1 daca x nu apare in tablou.

Indicatie: algoritmul a fost prezentat in pseudocod in cadrul sesiunii de curs
din saptamana 7;

b) Implementati functia de mai sus, in maniera nerecursiva (iterativa)

Indicatie: puteti folosi descrierea in pseudocod de aici
https://www.pbinfo.ro/articole/3633/cautarea-binara
*/

#include "/Users/paulhondola/Faculta/Tehnici de Programare/project/rand array/rand_array.h"
#include <stdio.h>
#include <time.h>
#define SIZE 100

void print_array(int *v, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int binarysearch_rec(int searched, int v[], unsigned left, unsigned right) {
  if (left > right)
    return -1;

  unsigned middle = (left + right) / 2;

  if (v[middle] == searched)
    return middle;

  if (v[middle] < searched)
    return binarysearch_rec(searched, v, middle + 1, right);

  return binarysearch_rec(searched, v, left, middle - 1);
}

int binarysearch_iterative(int searched, int v[], unsigned left,
                           unsigned right) {
  /*
  st ← 1
  dr ← n
  poz ← 0
  CÂTTIMP st≤dr SI poz=0 EXECUTĂ
      m ← (st + dr) DIV 2
      DACĂ v[m] = x ATUNCI
          poz = m
      ALTFEL
          DACĂ v[m] < x ATUNCI
              st ← m + 1
          ALTFEL
              dr ← m - 1
          SFDACĂ
      SFDACĂ
  SFCÂTTIMP

  DACĂ poz≠0 ATUNCI
      // x apare în vector pe poziția poz
  ALTFEL
      // x nu apare în vector
  SFDACĂ
  */

  int position = -1;

  while (left <= right && position == -1) {
    unsigned middle = (left + right) / 2;

    if (v[middle] == searched)
      position = middle;
    else {
      if (v[middle] < searched)
        left = middle + 1;
      else
        right = middle - 1;
    }
  }

  return position;
}

int main(void) {

  srand(time(NULL));

  int *v = make_rand_flexi_array(SIZE, get_new_element_asc, 10);

  int element = 100;
  int index_rec = binarysearch_rec(element, v, 0, SIZE - 1);
  int index_iterative = binarysearch_iterative(element, v, 0, SIZE - 1);

  printf("Index of element %d: %d\n", element,
         v[index_rec] == element ? index_rec : -1);

  printf("Index of element %d: %d\n", element,
         v[index_iterative] == element ? index_iterative : -1);

  print_array(v, SIZE);

  return 0;
}
