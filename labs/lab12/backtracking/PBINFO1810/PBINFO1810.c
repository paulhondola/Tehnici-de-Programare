/*
Scrieți un program care citeşte o valoare naturală nenulă impară pentru n şi
apoi generează şi afişează în ordine crescătoare lexicografic toate combinaţiile
formate din n cifre care îndeplinesc următoarele proprietăţi:

- încep şi se termină cu 0;
- modulul diferenţei între oricare două cifre alăturate dintr-o combinaţie
este 1. Astfel, pentru n=5, combinaţiile afişate sunt, în ordine, următoarele:
01010, 01210
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
#define INIT_VALUE -1

int successor(int st[], int k, int n) {
  if (st[k] < n) {
    st[k]++;
    return 1;
  }
  return 0;
}

int valid(int st[], int k) {
  for (int i = 1; i <= k; i++)
    if (abs(st[i] - st[i - 1]) != 1)
      return 0;

  return 1;
}

int solution(int st[], int k, int n) {
  return (k == n - 2) && abs(st[k] - st[k + 1]) == 1;
}

void print(int st[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", st[i]);
  printf("\n\n");
}

int back(const int n) {
  int st[MAX_SIZE];

  st[0] = 0;
  st[n - 1] = 0;

  int stack_level = 1;
  st[stack_level] = INIT_VALUE;

  int permutations = 0;

  while (stack_level > 0) {
    if (successor(st, stack_level, n)) {
      if (valid(st, stack_level)) {
        if (solution(st, stack_level, n)) {
          permutations++;
          print(st, n);
        } else {
          stack_level++;
          st[stack_level] = INIT_VALUE;
        }
      } else {
        ;
      }
    } else {
      stack_level--;
    }
  }

  return permutations;
}

int main(int argc, char *argv[]) {

  if (argc != 2)
    return 1;

  int perm = back(atoi(argv[1]));

  printf("PERMUTATIONS: %d\n", perm);

  return 0;
}
