#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_CHUNK 16

typedef enum { STACK_OK, STACK_EMPTY, STACK_FULL } stack_code;

typedef int stack_data;

typedef struct {
  size_t top;
  size_t capacity;
  stack_data *data;
} stack;

stack_code init_stack(stack *st, size_t capacity);

stack_code is_empty(stack *st);

stack_code is_full(stack *st);

stack_code push(stack *st, stack_data data);

stack_code pop(stack *st);

stack_data peek(stack *st);

void free_stack(stack *st);

#endif
