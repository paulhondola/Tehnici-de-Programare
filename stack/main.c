#include "stack.h"

int main(int argc, char *argv[]) {

  if (argc != 4) {
    perror("Invalid number of arguments -> need 3 -> 1. STACK_DEBUG 2. "
           "STACK_DYNAMIC 3. STACK_CHUNK");
    return 1;
  }

  STACK_DEBUG = atoi(argv[1]);
  STACK_DYNAMIC = atoi(argv[2]);
  STACK_CHUNK = (size_t)atoi(argv[3]);

  stack st = init_stack(32);

  for (int i = 0; i < 100; i++) {
    push(&st, i);
  }

  for (int i = 0; i < 100; i++) {
    pop(&st);
  }

  free_stack(&st);

  return 0;
}
