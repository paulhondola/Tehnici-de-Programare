// DEPENDENCIES
#include "stack.h"
#include <time.h>

// PARAMETERS
#define MAX 100
#define ITER 100
#define REMOVE 10

int main(void) {

  stack stack = init_stack();

  srand(time(NULL));

  // adaugam valori aleatoare pentru date si prioritate
  for (int i = 0; i < ITER; i++) {
    node_t node = create_node(rand() % MAX, rand() % MAX);

    // adaugam pe stiva
    stack = push(stack, node);
  }

  print_stack(stack);

  for (int i = 0; i < REMOVE; i++)
    stack = pop(stack);

  printf("--------------------------------\n");

  print_stack(stack);

  free_stack(stack);

  return 0;
}
