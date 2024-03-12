#include "stack.h"

int main(void) {

  stack st = init_stack(10);

  for (int i = 0; i < 1000; i++) {
    push(&st, i);
  }

  for (int i = 0; i < 11; i++) {
    pop(&st);
  }

  free_stack(&st);

  return 0;
}
