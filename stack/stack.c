#include "stack.h"

stack init_stack(size_t cap) {

  stack st = (stack){0, cap, NULL};

  st.data = (stack_data *)malloc(cap * sizeof(stack_data));

  if (st.data == NULL) {
    if (DEBUG)
      printf("memory allocation failure\n");
    st.capacity = 0;
  }

  if (DEBUG) {
    printf("initialization successful\n");
    printf("stack capacity set to: %zu\n", st.capacity);
  }

  return st;
}

int is_empty(stack *st) {
  if (DEBUG && st->top == 0)
    printf("stack empty\n");
  return st->top == 0;
}

int is_full(stack *st) {
  if (DEBUG && st->top >= st->capacity)
    printf("stack full\n");
  return st->top >= st->capacity;
}

int push(stack *st, stack_data data) {
  if (is_full(st)) {
    if (DYNAMIC) {
      stack_data *temp = (stack_data *)realloc(
          st->data, (st->capacity + STACK_CHUNK) * sizeof(stack_data));

      if (temp == NULL) {

        if (DEBUG) {
          printf("memory reallocation failure\n");
          printf("stack capacity remains at: %zu\n", st->capacity);
          printf("no push happened\n");
          return 0;
        }

      } else {
        st->data = temp;
        st->capacity += STACK_CHUNK;

        if (DEBUG)
          printf("stack capacity increased to: %zu\n", st->capacity);
      }
    }
  }
  if (DEBUG)
    printf("push %d\n", data);

  st->data[st->top++] = data;
  return 1;
}

int pop(stack *st) {
  if (is_empty(st)) {
    return 0;
  }

  if (DEBUG)
    printf("pop %d\n", st->data[st->top - 1]);
  st->top--;
  return 1;
}

stack_data peek(stack *st) {
  if (is_empty(st)) {
    return 0;
  }

  if (DEBUG)
    printf("peek %d\n", st->data[st->top - 1]);

  return st->data[st->top - 1];
}

void free_stack(stack *st) {

  if (DEBUG)
    printf("free stack\n");

  free(st->data);
  *st = (stack){0, 0, NULL};
}
