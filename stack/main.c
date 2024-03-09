#include "stack.h"

int main(void) {

  stack st;
  stack_code code;

  code = init_stack(&st, 5);

  if (code == EMPTY) {
  }
  free(st.data);

  return 0;
}
