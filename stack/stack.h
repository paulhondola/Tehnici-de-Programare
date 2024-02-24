#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef int stack_data;

typedef struct {
  int top;
  int max_size;
  stack_data data[STACK_SIZE];
} stack;

void init_stack(stack *st);

void push(stack *st, stack_data data);

void pop(stack *st);

stack_data peek(stack *st);

#endif
