#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

/*
Se citeste un numar natural n. Generati si afisati toate combinatiile de cate n
cifre binare care nu au doua cifre de 1 alaturate. Exemplu: n=3 combinatiile
sunt:
0 0 0
0 0 1
0 1 0
1 0 0
1 0 1
*/

int valid_no_test(int stack[], int stack_level) { return 1; }

int valid(int stack[], int stack_level) {

  if (stack_level == 1)
    return 1;

  for (int i = 2; i <= stack_level; i++)
    if (stack[i - 1] == 1 && stack[i] == 1)
      return 0;

  return 1;
}

int solution(int k, int n) { return k == n; }

void tipar(int st[], int k) {
  for (int i = 1; i <= k; i++) {
    printf("%d ", st[i]);
  }
  printf("\n");
}

int successor(int st[], int k, int n) {
  // verifica daca pe nivelul curent mai se poate pune o valoare noua si daca
  // da, o pune si returneaza 1 iar daca nu se poate pune returneaza 0;
  if (st[k] < 1) {
    st[k]++;
    return 1;
  }
  return 0;
}

int back(const int n) {

  int permutations = 0;

  int st[MAX_LEN] = {0};
  int stack_level = 1;
  st[stack_level] = -1;
  while (stack_level > 0) {

    if (successor(st, stack_level, n)) {
      if (valid(st, stack_level)) {
        if (solution(stack_level, n)) {
          permutations++;
          tipar(st, stack_level);
        } else {
          stack_level++; // trecem pe nivelul urmator;
          st[stack_level] = -1;
        }
      }
    } else {
      stack_level--; // cobram pe nivelul anterior si continuam de la ultima
                     // valoare atinsa
    }
  }

  return permutations;
}

int comparator(const void *p, const void *q) {
  return (*(char *)p - *(char *)q);
}

// stiva -> 1 -> <= len
// string -> 0 -> < len
int main(int argc, char *argv[]) {

  if (argc != 2)
    return 1;

  int perm = back(atoi(argv[1]));

  printf("\npermutations: %d\n", perm);

  return 0;
}
