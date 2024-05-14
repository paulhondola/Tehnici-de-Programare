#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

int is_vowel(char c) {
  const char *vowels = "aeiouAEIOU";
  return strchr(vowels, c) != NULL;
}

int is_consonant(char c) { return isalpha(c) && !is_vowel(c); }

int valid_no_test(int stack[], int stack_level, char *string) {
  for (int i = 1; i < stack_level; i++)
    if (stack[i] == stack[stack_level])
      return 0;

  return 1;
}

int valid(int stack[], int stack_level, char *string) {

  if (stack_level == 1)
    return 1;

  for (int i = 2; i <= stack_level; i++) {
    if (is_vowel(string[stack[i - 1] - 1] && is_vowel(string[stack[i] - 1])))
      return 0;
    if (is_consonant(string[stack[i - 1] - 1] &&
                     is_consonant(string[stack[i] - 1])))
      return 0;
  }

  return 1;
}

int solution(int k, int n) { return k == n; }

void tipar(int st[], int k, char *string) {
  for (int i = 1; i <= k; i++) {
    printf("%c ", string[st[i] - 1]);
  }
  printf("\n");
}

int successor(int st[], int k, int n) {
  // verifica daca pe nivelul curent mai se poate pune o valoare noua si daca
  // da, o pune si returneaza 1 iar daca nu se poate pune returneaza 0;
  if (st[k] < n) {
    st[k]++;
    return 1;
  }
  return 0;
}

int back(char *string) {

  int permutations = 0;

  int st[MAX_LEN] = {0};
  int len = strlen(string);
  int stack_level = 1;
  st[stack_level] = 0;
  while (stack_level > 0) {

    if (successor(st, stack_level, len)) {

      if (valid_no_test(st, stack_level, string)) {
        if (solution(stack_level, len)) {
          permutations++;
          tipar(st, stack_level, string);
        } else {
          stack_level++; // trecem pe nivelul urmator;
          st[stack_level] = 0;
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

  char string[MAX_LEN] = "";
  strcpy(string, argv[1]);

  qsort(string, strlen(string), sizeof(char), comparator);

  if (back(string) == 0) {
    printf("No permutations found\n");
  }

  return 0;
}
