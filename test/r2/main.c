#include "stack.h"

int is_odd(element_t x) { return x % 2; }

int main(void) {

  stack st1 = init_stack(10);

  if (st1 == NULL) {
    printf("STACK ALLOC ERROR\n");
    return 1;
  }

  stack st2 = init_stack(15);

  if (st2 == NULL) {
    printf("STACK ALLOC ERROR\n");
    return 2;
  }

  for (size_t i = 0; i < get_stack_capacity(st1); i++)
    if (push(st1, i) != STACK_OK)
      printf("OVERFLOW ERROR\n");

  for (size_t i = 0; i < get_stack_capacity(st2); i++)
    if (push(st2, i) != STACK_OK)
      printf("OVERFLOW ERROR\n");

  stack st3 = stack_sum(st1, st2);

  if (st3 == NULL) {
    printf("STACK SUM ERROR\n");
    free_stack(st1);
    free_stack(st2);
    return 3;
  }

  size_t st3_size = get_stack_size(st3);

  for (size_t i = 0; i < st3_size; i++) {
    printf("%d ", peek(st3));
    pop(st3);
  }

  vector odd = filter_stack(st1, is_odd);

  printf("VECTOR:\n");
  print_vector(odd);

  free_vector(odd);

  odd = filter_stack(st2, is_odd);

  printf("VECTOR:\n");

  print_vector(odd);

  free_vector(odd);

  free_stack(st1);

  free_stack(st2);

  free_stack(st3);

  return 0;
}
