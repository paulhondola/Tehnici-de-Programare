#include <stdio.h>
#include <stdlib.h>

/*
Se dau N dame şi o tablă de şah de dimensiune NxN. Să se găsească toate
modalităţile de a aranja toate damele astfel încât oricare două dame să nu se
atace. Două dame se atacă dacă se află pe aceeaşi linie, coloană sau diagonală.
Se cere să se afişeze prima soluţie în ordine lexicografică şi numărul total de
soluţii.

Date de intrare
Fişierul de intrare damesah.in va contine pe prima linie numărul natural N,
având semnificaţia din enunţ.

Date de ieşire
În fişierul de ieşire damesah.out se vor găsi două linii. Pe prima linie va fi
afişată prima soluţie în ordine lexicografică. Aceasta solutie va fi formată din
N numere, al i-lea număr reprezentând coloana pe care se află dama de pe linia
i. Pe cea de-a doua linie, se va găsi numărul total de soluţii.

Restricţii
§  4 ≤ N ≤ 13

Exemplu
damesah.in

damesah.out

4

2 4 1 3
2

Explicatie
Pentru N = 4 dame, prima solutie generata va fi 2 4 1 3. Fiecare numar V[i]
reprezinta coloana pe care se va afla dama de pe linia i. S-au gasit in total 2
solutii.

Problema se va rezolva utilizand un algoritm de backtracking.
*/
#define STACK_INIT_VALUE 0

int successor(int stack[], int level, int size) {
  if (stack[level] >= size)
    return 0;

  stack[level]++;
  return 1;
}

int valid(int stack[], int level) {
  for (int i = 1; i < level; i++)
    if (abs(level - i) == abs(stack[level] - stack[i]) ||
        stack[i] == stack[level])
      return 0;
  return 1;
}

int solution(int level, int size) { return level == size; }

void print_solution(int stack[], int size) {
  for (int i = 1; i <= size; i++)
    printf("%d ", stack[i]);
  printf("\n");
}

int back(int size) {
  int permutations = 0;
  int stack[size + 1];
  int level = STACK_INIT_VALUE + 1;
  stack[0] = STACK_INIT_VALUE;
  stack[1] = STACK_INIT_VALUE;

  while (level > STACK_INIT_VALUE) {
    if (successor(stack, level, size)) {
      if (valid(stack, level)) {
        if (solution(level, size)) {
          permutations++;
          print_solution(stack, size);
        } else {
          level++;
          stack[level] = STACK_INIT_VALUE;
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

int main(void) {

  int n = 0;

  if (scanf("%d", &n) != 1)
    return 1;

  printf("%d", back(n));

  return 0;
}
