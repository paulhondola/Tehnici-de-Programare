/*
2.Se citesc dintr-un fisier transmis ca si parametru in linie de comanda,
numerele naturale n si k (n<=26, k<=n) si apoi un alfabet format din n litere
distincte.

Sa se afiseze toate parolele de cate k litere care respecta urmatoarele cerinte:

2 litere consecutive nu pot fi egale sau vocale

2 litere alaturate nu pot avea coduri ASCII consecutive ( nu pot exista parole
care sa contina sirurile bc sau cb de exemplu)

In cazul in care nu s-au putut crea parole, se va afisa mesajul “EROARE”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INIT_VALUE -1

int successor(int stack[], int level, int n) {
  if (stack[level] < n - 1) {
    stack[level]++;
    return 1;
  }
  return 0;
}

int is_vowel(char c) {
  char *vowels = "AEIOUaeiou";
  return strchr(vowels, c) != NULL;
}

int are_consecutive(char a, char b) { return abs(a - b) == 1; }

int valid(int stack[], int level) {
  for (int i = 0; i < level; i++)
    if (stack[i] == stack[level])
      return 0;

  return 1;
}

int valid_alphabet(int stack[], int level, char alphabet[]) {
  if (level == 0)
    return 1;

  char a = alphabet[stack[level - 1]];
  char b = alphabet[stack[level]];

  if (a == b)
    return 0;

  if (is_vowel(a) && is_vowel(b))
    return 0;

  if (are_consecutive(a, b))
    return 0;

  return 1;
}

int solution(int level, int n) { return level == n - 1; }

void print_alphabet(int stack[], int n, char alphabet[]) {
  for (int i = 0; i < n; i++)
    printf("%c ", alphabet[stack[i]]);
  printf("\n");
}

void print_perm(int stack[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", stack[i]);
  printf("\n");
}

int back(int n, int k, char *alphabet) {
  int permutations = 0;
  int stack[n];
  int level = 0;
  stack[0] = INIT_VALUE;

  while (level > INIT_VALUE) {

    if (successor(stack, level, n)) {
      if (valid_alphabet(stack, level, alphabet)) {
        if (solution(level, k)) {
          permutations++;
          // print_perm(stack, k);
          print_alphabet(stack, k, alphabet);
        } else {
          level++;
          stack[level] = INIT_VALUE;
        }
      } else {
        ;
      }
    } else {
      level--;
    }
  }

  return permutations;
}

int main(int argc, char **argv) {

  if (argc != 4)
    return 1;

  int n, k;

  n = atoi(argv[1]);
  k = atoi(argv[2]);
  char alphabet[n];

  strcpy(alphabet, argv[3]);

  int perm = back(n, k, alphabet);

  if (perm)
    printf("Permutations: %d\n", perm);
  else
    printf("Failed to generate a password\n");

  return 0;
}
