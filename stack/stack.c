#include "stack.h"

void init_stack(stack *st) {
  st->max_size = STACK_SIZE;
  st->top = -1;
}

void push(stack *st, stack_data data) {
  if (st->top == STACK_SIZE) {
    printf("Stack is full\n");
    return;
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
