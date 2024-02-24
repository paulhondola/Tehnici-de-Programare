#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_CHUNK 16

typedef int stack_data;

typedef struct {
  int top;
  int capacity;
  stack_data *data;
} stack;

void init_stack(stack *st);

void push(stack *st, stack_data data);

void pop(stack *st);

stack_data peek(stack *st);

void free_stack(stack *st);

#endif
