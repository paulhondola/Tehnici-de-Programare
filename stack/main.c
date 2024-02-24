#include "stack.h"

int main(void) {

  stack st;

  init_stack(&st);

  push(&st, 10);
  push(&st, 20);

  pop(&st);
  pop(&st);
  printf("Peek: %d\n", peek(&st));

  return 0;
}
