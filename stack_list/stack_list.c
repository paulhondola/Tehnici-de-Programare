#include "stack_list.h"

// STRUCTURE

struct STACK_LIST {
  list_t list;
  size_t size;
};

// INIT - initialize the stack with an empty list and size 0
stack_list_t init_stack(void) {
  stack_list_t stack = malloc(sizeof(struct STACK_LIST));
  *stack = (struct STACK_LIST){init_list(), 0};
  return stack;
}

// FREE
void free_stack(stack_list_t stack) {
  free_list(stack->list);
  free(stack);
}

// DISPLAY
void print_stack(stack_list_t stack) { print_list(stack->list); }

// SIZE - return the size of the stack
size_t get_size(stack_list_t stack) { return stack->size; }

// OPERATIONS

// PUSH - add an element to the top of the stack

stack_list_t push(stack_list_t stack, payload_t info) {
  stack->list = add_head_node(stack->list, create_node(info));
  stack->size++;
  return stack;
}

// POP - remove the top element from the stack

stack_list_t pop(stack_list_t stack) {
  if (stack->size == 0) {
    return stack;
  }
  stack->list = remove_head_node(stack->list);
  stack->size--;
  return stack;
}

// PEEK - return the top element of the stack

payload_t peek(stack_list_t stack) {
  if (stack->size == 0) {
    return 0;
  }
  return get_node_data(get_list_head(stack->list));
}

// ISEMPTY - check if the stack is empty

int is_empty(stack_list_t stack) { return stack->size == 0; }
