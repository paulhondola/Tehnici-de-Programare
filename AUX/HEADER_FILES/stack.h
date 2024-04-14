#ifndef __STACK_H
#define __STACK_H

// LIBRARIES
#include <stdio.h>
#include <stdlib.h>

// CONSTANTS
#define STACK_DEBUG 1
#define STACK_DYNAMIC 1
#define STACK_CHUNK 16

// STRUCTURES
typedef int stack_data;
typedef struct STACK *stack;

// FUNCTIONS

// INITIALIZATION
stack init_stack(size_t capacity);

// GETTERS
size_t get_stack_size(stack stack);
size_t get_stack_capacity(stack stack);

// STACK SIZE FUNCTIONS
int stack_is_empty(stack stack);
int stack_is_full(stack stack);
stack stack_realloc(stack stack);

// STACK OPERATIONS
stack push(stack stack, stack_data data);
stack pop(stack stack);
stack_data peek(stack stack);

// DEBUGGING
void print_stack(stack stack);

// FREE
void free_stack(stack stack);

#endif
