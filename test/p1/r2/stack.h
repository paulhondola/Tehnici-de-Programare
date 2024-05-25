#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

typedef enum
{
    STACK_OK,
    STACK_OVERFLOW,
    STACK_UNDERFLOW
} stack_status;
typedef int element_t;

typedef struct STACK_T *stack;
typedef struct VECTOR_T *vector;

stack init_stack(size_t);

stack_status push(stack, element_t);

stack_status pop(stack);

element_t peek(stack);

stack stack_sum(stack, stack);

size_t get_stack_size(stack);

size_t get_stack_capacity(stack);

void free_stack(stack);

vector filter_stack(stack, int (*)(element_t));

void print_vector(vector);

void free_vector(vector);
#endif
