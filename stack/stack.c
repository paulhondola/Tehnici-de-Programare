#include "stack.h"

void init_stack(stack *st) {
  st->capacity = STACK_CHUNK;
  st->top = -1;
  st->data = (stack_data *)malloc(st->capacity * sizeof(stack_data));

  if (st->data == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
}

void push(stack *st, stack_data data) {
  if (st->top == st->capacity - 1) {
    st->capacity += STACK_CHUNK;
    st->data =
        (stack_data *)realloc(st->data, st->capacity * sizeof(stack_data));

    if (st->data == NULL) {
      printf("Memory allocation failed\n");
      exit(2);
    }
  }

  st->data[++st->top] = data;
}

void pop(stack *st) {
  if (st->top == -1) {
    printf("Stack is empty\n");
    return;
  }

  st->top--;
}

stack_data peek(stack *st) {
  if (st->top == -1) {
    printf("Stack is empty\n");
    return -1;
  }

  return st->data[st->top];
}
