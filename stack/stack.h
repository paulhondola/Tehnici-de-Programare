#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

extern int STACK_DEBUG;
extern int STACK_DYNAMIC;
extern int STACK_CHUNK;

typedef int stack_data;

typedef struct {
  size_t top;
  size_t capacity;
  stack_data *data;
} stack;

stack init_stack(size_t);

int stack_is_empty(stack *);

int stack_is_full(stack *);

int stack_realloc(stack *);

int push(stack *, stack_data);

int pop(stack *);

stack_data peek(stack *);

void print_stack(stack *);

void free_stack(stack *);

#endif
