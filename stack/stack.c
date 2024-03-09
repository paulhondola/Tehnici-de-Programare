#include "stack.h"

stack_code init_stack(stack *st, size_t cap) {

  *st = (stack){0, 0, NULL};

  st->data = (stack_data *)malloc(cap * sizeof(stack_data));

  if (st->data == NULL) {
    st->capacity = 0;
    return EMPTY;
  }

  st->capacity = cap;
  return OK;
}

stack_data is_empty(stack *st) {
  if (st->top == 0) {
    return EMPTY;
  }

  return OK;
}

stack_data is_full(stack *st) {
  if (st->top >= st->capacity) {
    return FULL;
  }

  return OK;
}

stack_code push(stack *st, stack_data data) {
  if (st->top >= st->capacity) {
    st->capacity += STACK_CHUNK;
    st->data =
        (stack_data *)realloc(st->data, st->capacity * sizeof(stack_data));

    if (st->data == NULL) {
      st->capacity = 0;
      return FULL;
    }
  }

  st->data[st->top++] = data;
  return OK;
}

stack_code pop(stack *st) {
  if (st->top == 0) {
    return EMPTY;
  }

  st->top--;
  return OK;
}

stack_data peek(stack *st) {
  if (st->top == 0) {
    return -1;
  }

  return st->data[st->top - 1];
}
