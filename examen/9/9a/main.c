#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 4096
/*
Sa se scrie un program care primeste ca argument din linia de comanda un numar
natural n<3000. Programul va descompune acest numar n ca suma de puteri
crescatoare ale lui 2. Functia pentru descompunerea lui n va fi implementata
recursiv.

Exemplu: Pentru n=86 va afisa 2 4 16 64 (86 se descompune ca 2+4+16+64)
Hint: exista un  k=log2(N), putere maxima a lui 2 pentru care 2^k<=n
*/

void _2factor(int n, int max_2_factor) {
  if (n == 0)
    return;

  if (max_2_factor > n) {
    _2factor(n, max_2_factor >> 1);
  } else {
    _2factor(n - max_2_factor, max_2_factor);
    printf("%d ", max_2_factor);
  }
}

int main(int argc, char **argv) {
  if (argc != 2)
    return 1;

  int n = atoi(argv[1]);
  _2factor(n, MAX_VALUE);

  return 0;
}
