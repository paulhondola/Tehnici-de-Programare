#include "/Users/paulhondola/Faculta/Tehnici de Programare/AUX/DATA_STRUCTURES/stack/stack.h"
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void read_expression(char expression[])
{
  printf("Introduceti o expresie aritmetica: ");
  fgets(expression, MAX_SIZE, stdin);
}

int eval_expression(char expression[])
{
  int result = 0;

  size_t len = strlen(expression);

  stack st = init_stack(len);

  // - 12 * 3 5 => 12 - 3 * 5

  int num = 0, index = 0;
  for (long long int i = len - 1; i >= 0; i--)
  {
    if (isdigit(expression[i]))
    {
      num = pow(10, index++) * (expression[i] - '0') + num;
    }
    else if (expression[i] == ' ' || expression[i] == '\n')
    {
      if (num != 0)
      {
        push(st, num);
        num = 0;
        index = 0;
      }
    }
    else
    {

      // operator detected, pop 2 elements from the stack and apply the operator
      int op1 = peek(st);
      st = pop(st);
      int op2 = peek(st);
      st = pop(st);

      switch (expression[i])
      {
      case '+':
        push(st, op1 + op2);
        break;
      case '-':
        push(st, op1 - op2);
        break;
      case '*':
        push(st, op1 * op2);
        break;
      case '/':
        push(st, op1 / op2);
        break;
      case '%':
        push(st, op1 % op2);
        break;
      case '^':
        push(st, pow(op1, op2));
        break;
      default:
        printf("Invalid operator\n");
        exit(EXIT_FAILURE);
      }
    }
  }

  result = peek(st);

  free(st);

  return result;
}

int main(void)
{

  char expression[MAX_SIZE];
  read_expression(expression);

  printf("%s\n", expression);

  printf("The result of the expression is: %d", eval_expression(expression));

  return 0;
}
