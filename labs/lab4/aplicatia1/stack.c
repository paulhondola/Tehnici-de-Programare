#include "stack.h"

stack_code init_stack(stack *st, size_t cap) {

  *st = (stack){0, 0, NULL};

  st->data = (stack_data *)malloc(cap * sizeof(stack_data));

  if (st->data == NULL) {
    st->capacity = 0;
    return STACK_EMPTY;
  }

  st->capacity = cap;
  return STACK_OK;
}

stack_code is_empty(stack *st) {
  if (st->top == 0) {
    return STACK_EMPTY;
  }

  return STACK_OK;
}

stack_code is_full(stack *st) {
  if (st->top >= st->capacity) {
    return STACK_FULL;
  }

  return STACK_OK;
}

stack_code push(stack *st, stack_data data) {
  if (is_full(st) == STACK_FULL) {
    st->capacity += STACK_CHUNK;
    st->data =
        (stack_data *)realloc(st->data, st->capacity * sizeof(stack_data));

    if (st->data == NULL) {
      st->capacity = 0;
      return STACK_FULL;
    }
  }

  st->data[st->top++] = data;
  return STACK_OK;
}

stack_code pop(stack *st) {
  if (is_empty(st) == STACK_EMPTY) {
    return STACK_EMPTY;
  }

  st->top--;
  if (is_empty(st) == STACK_EMPTY)
    return STACK_EMPTY;

  return STACK_OK;
}

stack_data peek(stack *st) {
  if (is_empty(st) == STACK_EMPTY) {
    return 0;
  }
  return (st->data[st->top - 1]);
}
