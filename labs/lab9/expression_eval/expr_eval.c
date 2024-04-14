#include "/Users/paulhondola/Faculta/Tehnici de Programare/AUX/DATA_STRUCTURES/stack/stack.h"
#include <string.h>

#define MAX_SIZE 100

void read_expression(char expression[]) {
  printf("Introduceti o expresie aritmetica: ");
  fgets(expression, MAX_SIZE, stdin);
}

int eval_expression(char expression[]) {
  int result = 0;

  size_t len = strlen(expression);

  stack st = init_stack(len);

  // + 2 * 3 5 => 3 * 5 + 2

  for (long long int i = len - 1; i >= 0; i--) {
    if ()
  }

  free(st);

  return result;
}

int main(void) {

  char expression[MAX_SIZE];
  read_expression(expression);

  printf("%s\n", expression);

  printf("The result of the expression is: %d", eval_expression(expression));

  return 0;
}
