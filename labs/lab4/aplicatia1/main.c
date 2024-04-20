/*
Aplicatia 1:

Sa se defineasca si implementeze un tip de date Stack_t si operatiile specifice
unei stive astfel:

Stack_t push(Stack_t, Element_t);
Element_t pop(Stack_t);
Element_t peek(Stack_t);
a) structura de date va fi implementata in mod static (fara redimensionarea
capacitatii); se vor verifica operatiile la depasire de overflow si underflow;

b) structura de date va fi implementata in mod dinamic (cu utilizarea
operatiilor de gestiune dinamica a memoriei); in continuare operatiile pot da
flag-uri de eroare (var globala)
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  STACK_OK,
  STACK_EMPTY,
  STACK_FULL
} stack_code;

stack_code error_code;

typedef int stack_data;

typedef struct
{
  size_t top;
  size_t capacity;
  stack_data *data;
} stack;

stack init_stack(size_t cap)
{

  stack st = {0, 0, NULL};

  st.data = (stack_data *)malloc(cap * sizeof(stack_data));

  if (st.data == NULL)
  {
    st.capacity = 0;
    error_code = STACK_EMPTY;
    return st;
  }

  st.top = 0;
  st.capacity = cap;
  error_code = STACK_OK;
  return st;
}

stack push(stack *st, stack_data data)
{
  if (st->top >= st->capacity)
  {
    error_code = STACK_FULL;
    return *st;
  }

  error_code = STACK_OK;
  st->data[st->top++] = data;

  return *st;
}

stack_data pop(stack *st)
{
  if (error_code != STACK_EMPTY)
  {
    error_code = STACK_OK;
    st->top--;
    return st->data[st->top];
  }

  error_code = STACK_EMPTY;
  return 0;
}

stack_data peek(stack *st)
{
  if (error_code == STACK_EMPTY)
  {
    error_code = STACK_EMPTY;
    return 0;
  }
  error_code = STACK_OK;
  return st->data[st->top - 1];
}

int main(void)
{

  stack st = init_stack(10);

  if (error_code == STACK_EMPTY)
  {
    perror("Error: STACK_EMPTY");
    return 1;
  }

  for (int i = 0; i < 11; i++)
  {
    st = push(&st, i);
    if (error_code == STACK_FULL)
    {
      perror("Error: STACK_FULL");
    }

    printf("Element: %d\n", peek(&st));
  }

  free(st.data);

  return 0;
}
