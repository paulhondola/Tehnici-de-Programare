#ifndef __STACK_H
#define __STACK_H

// DEPENDENCIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DATA STRUCTURES
struct STACK;
struct NODE;

typedef struct NODE *node_t;
typedef struct STACK *stack;

// FUNCTIONS

// INIT
stack init_stack(void);
node_t create_node(int data, int priority);

// GETTERS
int top(stack stack);
int get_size(stack stack);

// OPERATIONS
stack push(stack stack, node_t node);
stack pop(stack stack);
void print_stack(stack stack);
void free_stack(stack stack);

#endif
