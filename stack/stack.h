#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_DEBUG 1
#define STACK_DYNAMIC 1
#define STACK_CHUNK 32

typedef int stack_data;

typedef struct {
  size_t top;
  size_t capacity;
  stack_data *data;
} stack;

stack init_stack(size_t initial_capacity);

int stack_is_empty(stack *st);

int stack_is_full(stack *st);

int stack_realloc(stack *st);

int push(stack *st, stack_data data);

int pop(stack *st);

stack_data peek(stack *st);

void print_stack(stack *st);

void free_stack(stack *st);

#endif
