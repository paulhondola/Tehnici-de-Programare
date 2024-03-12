#include "stack.h"

stack init_stack(size_t capacity) {

  stack st = (stack){0, capacity, NULL};

  st.data = (stack_data *)malloc(capacity * sizeof(stack_data));

  if (st.data == NULL) {
    if (STACK_DEBUG)
      printf("memory allocation failed\n");
    st.capacity = 0;
  }

  if (STACK_DEBUG) {
    printf("initialization successful\n");
    printf("stack capacity set to: %zu\n", st.capacity);
  }

  return st;
}

int stack_is_empty(stack *st) {
  if (STACK_DEBUG && st->top == 0)
    printf("stack empty\n");
  return st->top == 0;
}

int stack_is_full(stack *st) {
  if (STACK_DEBUG && st->top >= st->capacity)
    printf("stack full\n");
  return st->top >= st->capacity;
}

int stack_realloc(stack *st) {
  stack_data *temp = (stack_data *)realloc(
      st->data, (st->capacity + STACK_CHUNK) * sizeof(stack_data));

  if (temp == NULL) {
    if (STACK_DEBUG) {
      printf("memory reallocation failed\n");
      printf("stack capacity remains at: %zu\n", st->capacity);
      printf("no push happened\n");
    }
    return 0;
  }

  st->data = temp;
  st->capacity += STACK_CHUNK;

  if (STACK_DEBUG)
    printf("stack capacity increased to: %zu\n", st->capacity);

  return 1;
}

int push(stack *st, stack_data data) {

  // full -> dynamic -> realloc -> fail or not
  // full -> static -> no push

  if (stack_is_full(st)) {
    if (STACK_DYNAMIC) {
      if (!stack_realloc(st))
        return 0;
    } else {
      if (STACK_DEBUG)
        printf("no push happened\n");
      return 0;
    }
  }
  if (STACK_DEBUG)
    printf("push %d\n", data);

  st->data[st->top++] = data;
  return 1;
}

int pop(stack *st) {
  if (stack_is_empty(st)) {
    return 0;
  }

  if (STACK_DEBUG)
    printf("pop %d\n", st->data[st->top - 1]);

  st->top--;
  return 1;
}

stack_data peek(stack *st) {
  if (stack_is_empty(st)) {
    return 0;
  }

  if (STACK_DEBUG)
    printf("peek %d\n", st->data[st->top - 1]);

  return st->data[st->top - 1];
}

void free_stack(stack *st) {

  if (STACK_DEBUG)
    printf("free stack\n");

  free(st->data);
  *st = (stack){0, 0, NULL};
}

void print_stack(stack *st) {
  for (size_t i = 0; i < st->top; i++) {
    printf("%d ", st->data[i]);
  }
}
