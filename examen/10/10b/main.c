/*
Scrieti un program care rezolva sudoku cu cifre de la 1-4. Matricea initiala
este data intr-un fisier trimis ca si parametru de intrare, cu 0 sunt notate
spatiile libere. Toate solutiile vor fi tiparite pe ecran.

Exemplu:

Fisier intrare:
0 0 0 3
0 1 0 4
4 2 0 0
1 0 4 0

Solutie:
2 4 1 3
3 1 2 4
4 2 3 1
1 3 4 2
*/
#include <stdio.h>

#define LINES 4

int sudoku[LINES][LINES] = {
    {0, 0, 0, 3}, {0, 1, 0, 4}, {4, 2, 0, 0}, {1, 0, 4, 0}};

int stack[LINES * LINES];

int static_index = 0;
int static_indexes[LINES * LINES];

void get_static_indexes() {
  for (int i = 0; i < LINES * LINES; i++)
    if (stack[i] != 0)
      static_indexes[static_index++] = i;
}

int check_static_square(int level) {
  for (int i = 0; i < static_index; i++)
    if (level == static_indexes[i])
      return 0;
  return 1;
}

void convert_to_block() {
  for (int i = 0; i < LINES; i++)
    for (int j = 0; j < LINES; j++)
      stack[j * LINES + i] = sudoku[i][j];
}

void print_matrix() {
  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < LINES; j++)
      printf("%d ", stack[j * LINES + i]);
    printf("\n");
  }
}

int successor(int level, int size) {
  if (stack[level] >= size)
    return 0;
  stack[level]++;
  return 1;
}

int valid(int level, int size) {
  for (int i = 0; i < level; i++)
    if (stack[i] % size == stack[level] % size ||
        stack[i] / size == stack[level] / size)
      return 0;
  return 1;
}

int solution(int level, int size) { return level == size * size - 1; }

void back() {
  int level = 0;
  const int init_value = 0;

  while (level > -1) {

    if (successor(level, LINES)) {
      if (valid(level, LINES)) {
        if (solution(level, LINES)) {
          print_matrix();
        } else {
          level++;

          if (check_static_square(level))
            level++;
          else
            stack[level] = init_value;
        }
      } else {
        ;
      }
    } else {
      level--;
    }
  }
}

int main(void) {

  convert_to_block();
  get_static_indexes();

  back();
  return 0;
}
