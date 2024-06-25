#include "stack.h"

// DATA STRUCTURES
struct NODE {
  int data;
  int priority;
  struct NODE *next;
};

struct STACK {
  node_t top;
  int size;
};

// INIT
stack init_stack() {
  stack stack = malloc(sizeof(struct STACK));
  return stack;
}

node_t create_node(int data, int priority) {
  node_t node = malloc(sizeof(struct NODE));

  if (node == NULL)
    return NULL;

  (*node) = (struct NODE){data, priority, NULL};

  return node;
}

// OPERATIONS
int check_priority(node_t main, node_t comparator) {
  return main->priority < comparator->priority;
}

stack push(stack stack, node_t node) {
  stack->size++;

  // stiva este goala
  if (stack->size == 1) {
    stack->top = node;
    return stack;
  }

  // daca nodul dat este prioritar
  if (check_priority(node, stack->top)) {
    node->next = stack->top;
    stack->top = node;
    return stack;
  }

  node_t prev_iter = stack->top;
  node_t iter = stack->top->next;

  while (iter != NULL) {
    if (check_priority(node, iter)) {
      node->next = iter;
      prev_iter->next = node;
      return stack;
    }

    prev_iter = prev_iter->next;
    iter = iter->next;
  }

  // daca nodul trebuie adaugat la fundul stivei

  prev_iter->next = node;

  return stack;
}

stack pop(stack stack) {
  // stiva este goala
  if (stack->size == 0)
    return stack;

  // stiva are doar un element
  if (stack->size == 1) {
    stack->size = 0;
    free(stack->top);
    return stack;
  }

  stack->size--;

  node_t temp = stack->top;
  stack->top = stack->top->next;

  free(temp);

  return stack;
}

// GETTERS
int top(stack stack) { return stack->top->data; }

int get_size(stack stack) { return stack->size; }

// DEBUG
void print_stack(stack stack) {
  if (stack->size == 0) {
    printf("Stack is empty!\n");
    return;
  }

  node_t iter = stack->top;

  while (iter != NULL) {
    printf("DATA: %d | PRIORITY: %d\n", iter->data, iter->priority);
    iter = iter->next;
  }
}

// DESTRUCTOR
void free_stack(stack stack) {
  node_t iter = NULL;
  for (int i = 0; i < stack->size; i++) {
    iter = stack->top;
    stack->top = stack->top->next;
    free(iter);
  }
  free(stack);
}
