/*
1. Se citesc dintr-un fisier transmis ca si paramtru in linie de comanda,
numerele naturale n si m (n<=15, m<=n) si apoi n cuvinte distincte cu cel mult
10 litere fiecare.

Sa se afiseze toate secventele de cate m cuvinte dintre cele citite care sa
respecte conditiile jocului "fazan" (ultimele doua caractere ale cuvantului
anterior sunt egale cu primele doua caractere ale cuvantului curent)

Exemplu:
Fisierul contine:
8 3
paul alina asfalt nas ultim imagine nasture real

Se va afisa:
paul ultim imagine
alina nas asfalt
alina nasture real
nasture real alina
real alina nas
real alina nasture
*/

#include <stdio.h>
#include <string.h>
#define MAX_WORD_LEN 100
#define MAX_WORD_COUNT 100

// in/out functions
int read_data(FILE *file, int *n, int *aranj,
              char words[MAX_WORD_COUNT][MAX_WORD_LEN]) {
  if (fscanf(file, "%d %d", n, aranj) != 2) {
    return 0;
  }

  fgetc(file); // consume new line

  long long int len = (MAX_WORD_COUNT + 1) * MAX_WORD_LEN + 1;
  char line[len]; // accomodate the white space between the words and the
                  // terminator

  if (fgets(line, len, file) == NULL)
    return 0;

  char *sep = " \n";

  char *token = strtok(line, sep);
  for (int i = 0; i < *n; i++) {
    if (token == NULL)
      return 0;

    strcpy(words[i], token);
    token = strtok(NULL, sep);
  }

  return 1;
}

void print_words(int n, char words[MAX_WORD_COUNT][MAX_WORD_LEN]) {
  printf("----------WORDS----------\n");
  for (int i = 0; i < n; i++)
    printf("%s\n", words[i]);

  printf("-------------------------\n");
}

int is_fazan(char x[MAX_WORD_LEN], char y[MAX_WORD_LEN]) {
  int len = strlen(x) - 2;
  return strncmp(x + len, y, 2) == 0;
}

// backtracking functions
int successor(int stack[], int level, int n) {
  if (stack[level] < n - 1) {
    stack[level]++;
    return 1;
  }
  return 0;
}

int valid_stack(int stack[], int level) {
  for (int i = 0; i < level; i++)
    if (stack[i] == stack[level])
      return 0;
  return 1;
}

int valid_words(int stack[], int level,
                char words[MAX_WORD_COUNT][MAX_WORD_LEN]) {
  if (level == 0)
    return 1;

  return is_fazan(words[stack[level - 1]], words[stack[level]]);
}

int solution(int level, int n) { return level == n - 1; }

void print_stack(int stack[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", stack[i]);

  printf("\n");
}

void print_solution(int stack[], int n,
                    char words[MAX_WORD_COUNT][MAX_WORD_LEN]) {
  for (int i = 0; i < n; i++)
    printf("%s ", words[stack[i]]);

  printf("\n");
}

int back(int n, int aranj, char words[MAX_WORD_COUNT][MAX_WORD_LEN]) {
  int stack[MAX_WORD_COUNT + 1] = {-1};
  int level = 0;
  int permutations = 0;

  while (level > -1) {
    if (successor(stack, level, n)) {
      if (valid_stack(stack, level) && valid_words(stack, level, words)) {
        if (solution(level, aranj)) {
          permutations++;
          // print_stack(stack, aranj);
          print_solution(stack, aranj, words);
        } else {
          level++; // solution
          stack[level] = -1;
        }
      } else {
        ; // valid
      }
    } else {
      level--; // successor
    }
  }

  return permutations;
}

int main(int argc, char **argv) {
  if (argc != 2)
    return 1;

  FILE *input = fopen(argv[1], "r");
  if (input == NULL) {
    perror(argv[1]);
    return 2;
  }

  int n, aranj;
  char words[MAX_WORD_COUNT][MAX_WORD_LEN];

  if (read_data(input, &n, &aranj, words) == 0) {
    perror("invalid read procedure");
    return 3;
  }

  print_words(n, words);

  int perm = back(n, aranj, words);

  printf("\nPermutations done: %d\n", perm);

  return 0;
}
