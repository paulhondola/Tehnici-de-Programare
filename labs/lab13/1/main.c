#include <stdio.h>

/*
1. Scrieți un program care citește un număr natural n cu cifre distincte și care
să calculeze și să afișeze suma S a tuturor numerelor obținute prin rearanjarea
cifrelor lui n.
*/

#define MAX_STACK 100

typedef struct BackBehaviour {
  int count;
  int *data;
  int (*successor)(int *, int, int, int *);
  int (*valid)(int *, int, int, int *);
  int (*solution)(int *, int, int, int *);
  void (*print)(int *, int, int *);
} BackBehaviour_t;

int convert_number_to_array(int number, int array[]) {
  int count = 0;

  while (number) {
    array[count++] = number % 10;
    number /= 10;
  }

  return count;
}

int convert_array_to_number(int count, int array[], int stack[]) {
  int number = 0;
  for (int i = 1; i <= count; i++)
    number = number * 10 + array[stack[i] - 1];

  return number;
}

int successor(int *stack, int level, int count, int *data) {
  if (stack[level] < count) {
    stack[level]++;
    return 1;
  }
  return 0;
}

int valid(int *stack, int level, int count, int *data) {
  for (int i = 1; i < level; i++)
    if (stack[i] == stack[level])
      return 0;

  return 1;
}

int solution(int *stack, int level, int count, int *data) {
  return level == count;
}

void print(int *stack, int level, int *data) {
  for (int i = 1; i <= level; i++)
    printf("%d ", data[stack[i] - 1]);
  printf("\n");
}

int back(BackBehaviour_t behaviour) {
  int sum = 0;
  int stack[MAX_STACK] = {0, 0};
  int level = 1;

  while (level > 0) {
    if (behaviour.successor(stack, level, behaviour.count, NULL)) {
      if (behaviour.valid(stack, level, behaviour.count, NULL)) {
        if (behaviour.solution(stack, level, behaviour.count, NULL)) {
          behaviour.print(stack, level, behaviour.data);
          sum += convert_array_to_number(level, behaviour.data, stack);
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
  return sum;
}

int main(void) {

  int number = 135;
  int payload[MAX_STACK];

  int count = convert_number_to_array(number, payload);

  BackBehaviour_t behaviour = {.count = count,
                               .data = payload,
                               .successor = successor,
                               .valid = valid,
                               .solution = solution,
                               .print = print};

  printf("SUM: %d\n", back(behaviour));

  return 0;
}
