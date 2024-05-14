/*
Un student are de dat n examene numerotate de la 1 la n intr-o sesiune formata
din m zile (m este cel putin de 2 ori mai mare decat n). Afisati toate modurile
in care isi poate programa studentul examenele astfel incat sa nu dea 2 examene
in zile consecutive si sa dea examenele in ordine de la 1 la n. Ex: n=3 m=6
Solutii:
010203
100203
102003
102030
(0 codifica zilele libere)
*/

#include <stdio.h>
#include <stdlib.h>
#define INIT_VALUE -1
#define MAX_DAYS 100

int valid(int st[], int k) {

  for (int i = 1; i < k; i++) {
    if (st[i] * st[i + 1] != 0)
      return 0;

    if (st[i] && st[k] && st[i] >= st[k])
      return 0;
  }

  return 1;
}
int solutie(int st[], int k, int n, int m) {

  if (k == n) {
    int sum = 0;
    int checksum = m * (m + 1) / 2;
    for (int i = 1; i <= n; i++)
      sum += st[i];

    printf("sum: %d\n", sum);
    printf("checksum: %d\n", checksum);
    return 1; // sum == checksum;
  }

  return 0;
}

void tipar(int st[], int k) {
  for (int i = 1; i <= k; i++) {
    printf("%d ", st[i]);
  }
  printf("\n");
}

int succesor(int st[], int k, int n) {
  // verifica daca pe nivelul curent mai se poate pune o valoare noua si daca
  // da, o pune si returneaza 1 iar daca nu se poate pune returneaza 0;
  if (st[k] < n) {
    st[k]++;
    return 1;
  }
  return 0;
}

void back(int examene, int zile) {

  int st[MAX_DAYS] = {INIT_VALUE, INIT_VALUE};
  int k = 1;

  while (k > 0) {

    if (succesor(st, k, examene)) {
      if (valid(st, k)) {
        if (solutie(st, k, zile, examene)) {
          tipar(st, k);
        } else {
          k++; // trecem pe nivelul urmator;
          st[k] = INIT_VALUE;
        }
      }
    } else {
      k--; // cobram pe nivelul anterior si continuam de la ultima valoare
           // atinsa
    }
  }
}

int main(int argc, char *argv[]) {
  int examene = atoi(argv[1]);
  int zile = atoi(argv[2]);

  back(examene, zile);

  return 0;
}
