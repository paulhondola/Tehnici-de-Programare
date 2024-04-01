#include "stack.h"
#include <stdlib.h>

struct STACK_T {
  element_t *data;
  size_t size;
  size_t capacity;
};

struct VECTOR_T {
  element_t *data;
  size_t size;
};

size_t get_stack_size(stack st) { return st->size; }

size_t get_stack_capacity(stack st) { return st->capacity; }

stack init_stack(size_t capacity) {
  stack st = malloc(sizeof(struct STACK_T));

  if (st == NULL) {
    perror("STACK ALLOC ERROR");
    return NULL;
  }

  *st = (struct STACK_T){NULL, 0, capacity};

  st->data = malloc(capacity * sizeof(element_t));

  if (st->data == NULL) {
    free(st);
    perror("STACK DATA ALLOC ERROR");
    return NULL;
  }

  return st;
}

stack_status push(stack st, element_t el) {
  if (st->size == st->capacity) {
    return STACK_OVERFLOW;
  }

  st->data[st->size++] = el;

  return STACK_OK;
}

stack_status pop(stack st) {
  if (st->size == 0) {
    return STACK_UNDERFLOW;
  }

  st->size--;

  return STACK_OK;
}

element_t peek(stack st) {
  if (st->size == 0) {
    return -1;
  }

  return st->data[st->size - 1];
}

stack stack_sum(stack a, stack b) {

  size_t max_cap = a->capacity > b->capacity ? a->capacity : b->capacity;
  size_t max_size = a->size > b->size ? a->size : b->size;

  stack sum = init_stack(max_cap);

  if (sum == NULL) {
    perror("STACK SUM ALLOC ERROR");
    return NULL;
  }

  for (size_t i = 0; i < max_size; i++) {
    element_t a_el = i < a->size ? a->data[i] : 0;
    element_t b_el = i < b->size ? b->data[i] : 0;

    if (push(sum, a_el + b_el) != STACK_OK) {
      free_stack(sum);
      return NULL;
    }
  }

  return sum;
}

void free_stack(stack st) {
  free(st->data);
  free(st);
}

stack copy_stack(stack main) {
  stack copy = init_stack(main->capacity);

  if (copy == NULL) {
    perror("STACK COPY ALLOC ERROR");
    return NULL;
  }

  copy->size = main->size;

  for (size_t i = 0; i < main->size; i++) {
    copy->data[i] = main->data[i];
  }

  return copy;
}

vector init_vector(size_t size) {
  vector v = malloc(sizeof(struct VECTOR_T));

  if (v == NULL) {
    perror("VECTOR ALLOC ERROR");
    return NULL;
  }

  *v = (struct VECTOR_T){NULL, size};

  v->data = malloc(size * sizeof(element_t));

  if (v->data == NULL) {
    free(v);
    perror("VECTOR DATA ALLOC ERROR");
    return NULL;
  }

  return v;
}

vector filter_stack(stack st, int (*predicate)(element_t)) {

  vector filtered = init_vector(st->size);

  size_t index = 0;
  for (size_t i = 0; i < st->size; i++)
    if (predicate(st->data[i]))
      filtered->data[index++] = st->data[i];

  filtered->size = index;

  filtered->data = realloc(filtered->data, index * sizeof(element_t));

  return filtered;
}

void print_vector(vector v) {
  for (size_t i = 0; i < v->size; i++)
    printf("%d ", v->data[i]);
  printf("\n");
}

void free_vector(vector v) {
  free(v->data);
  free(v);
}
