#include "stack.h"
#include <stdio.h>

int main(void) {

  stack st = {0, 0, NULL};
  stack_code code = STACK_OK;

  code = init_stack(&st, 5);

  if (code == STACK_EMPTY) {
    perror("Memory alloc failure");
    return 1;
  }

  for (int i = 0; i < 10; i++) {
    if (push(&st, i) == STACK_FULL) {
      perror("Memory alloc failure");
      return 1;
    }
  }

  for (int i = 0; i < 10; i++) {
    if (is_empty(&st) != STACK_EMPTY) {
      printf("Data: %d\n", peek(&st));
    }

    if (pop(&st) == STACK_EMPTY) {
      perror("Stack is empty");
    }
  }

  printf("Size: %zu\n", st.top);

  if (is_empty(&st) != STACK_EMPTY) {
    printf("Data: %d\n", peek(&st));
  }

  free(st.data);
  return 0;
}
