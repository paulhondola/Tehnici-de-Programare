/*
3. Dacă este dat un șir s care conține doar caracterele '(', ')', '{', '}', '['
și ']', să se determine dacă șirul de intrare este valid.

Un șir de intrare este valid dacă:

Parantezele deschise trebuie închise cu aceeași tipologie de paranteze.
Parantezele deschise trebuie completate în ordinea corectă. Fiecare paranteză
închisă are o paranteză deschisă corespunzătoare de același tip.

Sugestie: Vom itera prin caracterele șirului. Pentru fiecare paranteză deschisă,
vom folosi o stivă pentru a o stoca. De asemenea, vom utiliza o hartă care ne
indică parantezele închise corespunzătoare pentru fiecare paranteză deschisă.

Pentru fiecare paranteză închisă, verificăm dacă elementul din vârful stivei
este paranteza deschisă corespunzătoare. Dacă este, scoatem elementul din vârful
stivei și continuăm.

Dacă elementul din vârful stivei nu este paranteza deschisă corespunzătoare sau
stiva este goală, vom returna false. Dacă stiva este goală, șirul de intrare
este valid. În caz contrar, nu este valid.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 100
#define DEBUG 1

typedef enum { STACK_OK, STACK_EMPTY, STACK_FULL } stack_code;

stack_code error_code;

typedef char stack_data;

typedef struct {
  size_t top;
  size_t capacity;
  stack_data *data;
} stack;

stack init_stack(size_t cap) {

  stack st = {0, cap, NULL};

  st.data = (stack_data *)malloc(cap * sizeof(stack_data));

  if (st.data == NULL) {
    st.capacity = 0;
    error_code = STACK_EMPTY;
    return st;
  }

  error_code = STACK_OK;
  return st;
}

stack push(stack *st, stack_data data) {
  if (st->top >= st->capacity) {
    error_code = STACK_FULL;
    return *st;
  }

  error_code = STACK_OK;
  st->data[st->top++] = data;

  return *st;
}

stack_data pop(stack *st) {
  if (st->top == 0) {
    error_code = STACK_EMPTY;
    return 0;
  }

  error_code = STACK_OK;
  st->top--;
  return st->data[st->top];
}

stack_data peek(stack *st) {
  if (st->top == 0) {
    error_code = STACK_EMPTY;
    return 0;
  }

  error_code = STACK_OK;
  return st->data[st->top - 1];
}

FILE *open_file(const char *file_name, const char *mode) {
  FILE *file = fopen(file_name, mode);

  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  return file;
}

void close_file(FILE *file) {
  if (fclose(file) == EOF) {
    perror("Error closing file");
    exit(EXIT_FAILURE);
  }
}

int check_validity(char *str) {

  size_t capacity = strlen(str);

  stack st = init_stack(capacity);

  if (st.data == NULL) {
    return -1;
  }

  st = push(&st, str[0]);

  if (DEBUG) {
    printf("PUSH %zu %c\n", st.top, peek(&st));
  }

  for (size_t i = 1; i < capacity; i++) {

    switch (str[i]) {
    case ')':

      if (peek(&st) == '(') {

        if (DEBUG) {
          printf("POP %c due to %c\n", peek(&st), str[i]);
        }

        pop(&st);

      } else {

        st = push(&st, str[i]);

        if (DEBUG) {
          printf("PUSH %zu %c\n", st.top, peek(&st));
        }
      }
      break;

    case ']':

      if (peek(&st) == '[') {

        if (DEBUG) {
          printf("POP %c due to %c\n", peek(&st), str[i]);
        }

        pop(&st);

      } else {

        st = push(&st, str[i]);

        if (DEBUG) {
          printf("PUSH %zu %c\n", st.top, peek(&st));
        }
      }
      break;

    case '}':

      if (peek(&st) == '{') {

        if (DEBUG) {
          printf("POP %c due to %c\n", peek(&st), str[i]);
        }

        pop(&st);

      } else {

        if (DEBUG) {
          printf("PUSH %zu %c\n", st.top, peek(&st));
        }

        st = push(&st, str[i]);
      }
      break;

    default:

      st = push(&st, str[i]);

      if (DEBUG) {
        printf("PUSH %zu %c\n", st.top, peek(&st));
      }

      break;
    }
  }

  free(st.data);

  return st.top == 0;
}

int main(void) {
  FILE *input_file = open_file("data.txt", "r");

  char str[STRING_SIZE];

  if (fgets(str, STRING_SIZE, input_file) == NULL) {
    perror("Error reading from file");
    return 1;
  }

  if (str[strlen(str) - 1] == '\n') {
    str[strlen(str) - 1] = '\0';
  }

  int code = check_validity(str);

  switch (code) {
  case -1:
    printf("Memory allocation failure\n");
    break;

  case 0:
    printf("The string is not valid\n");
    break;

  case 1:
    printf("The string is valid\n");
    break;
  }

  return 0;
}
