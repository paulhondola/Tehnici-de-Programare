#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
#define DYNAMIC 1
#define STACK_CHUNK 10

typedef int stack_data;

typedef struct {
  size_t top;
  size_t capacity;
  stack_data *data;
} stack;

stack init_stack(size_t capacity);

int is_empty(stack *st);

int is_full(stack *st);

int push(stack *st, stack_data data);

int pop(stack *st);

stack_data peek(stack *st);

void free_stack(stack *st);

#endif
