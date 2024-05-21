/*
3. Se dă numărul natural n. Determinati o modalitate de așezare a numerelor din
mulțimea 1,2,…,n pe un cerc astfel încât suma a oricare două nume învecinate să
fie pătrat perfect.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

int is_square(int n) {
  int root = sqrt(n);
  return root * root == n;
}

int successor(int stack[], int level, int n) {

  if (stack[level] < n) {
    stack[level]++;
    return 1;
  }

  return 0;
}

int valid(int stack[], int level) {

  for (int i = 1; i < level; i++)
    if (stack[i] == stack[level])
      return 0;

  if (level > 1)
    return is_square(stack[level] + stack[level - 1]);

  return 1;
}

int solution_perm(int stack[], int level, int count) { return level == count; }

int solution(int stack[], int level, int count) {

  if (level != count)
    return 0;

  return is_square(stack[1] + stack[count]);
}

void print(int stack[], int count) {

  for (int i = 1; i <= count; i++)
    printf("%d ", stack[i]);

  printf("\n");
}

void back(int n) {
  int stack[MAX_STACK_SIZE] = {0, 0};
  int level = 1;

  while (level > 0) {
    if (successor(stack, level, n)) {
      if (valid(stack, level)) {
        if (solution(stack, level, n)) {
          print(stack, n);
        } else {
          level++;
          stack[level] = 0;
        }
      } else {
        ;
      }
    } else {
      level--;
    }
  }
}

int main(int argc, char *argv[]) {

  if (argc < 2)
    return 1;

  back(atoi(argv[1]));

  return 0;
}
