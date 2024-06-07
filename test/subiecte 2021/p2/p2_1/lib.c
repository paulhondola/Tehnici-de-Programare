#include "lib.h"

// IN-OUT FUNCTIONS

char *read_string(FILE *file) {
  char *string = malloc(MAX_STRING_LEN);
  if (string == NULL)
    return NULL;

  if (fgets(string, MAX_STRING_LEN, file) == NULL)
    return NULL;

  unsigned len = strlen(string);

  if (string[len - 1] == '\n')
    string[len - 1] = '\0';

  return string;
}

int is_not_space(char *string, unsigned index) {
  return !isspace(string[index]) && isspace(string[index + 1]);
}

int get_word_count(char *string) {
  int spaces = 1;
  unsigned len = strlen(string);
  for (unsigned i = 0; i < len - 1; i++)
    if (is_not_space(string, i))
      spaces++;

  if (isspace(string[len - 1]))
    spaces--;

  return spaces;
}

char **create_string_array(FILE *file, int *size) {
  char *string = read_string(file);

  if (string == NULL)
    return NULL;

  *size = get_word_count(string);

  char **array = malloc(*size);
  if (array == NULL) {
    free(string);
    return NULL;
  }

  char *sep = " \n\t";
  char *token = strtok(string, sep);

  for (int i = 0; i < *size; i++) {
    array[i] = malloc(MAX_WORD_LEN);
    strncpy(array[i], token, MAX_WORD_LEN - 1);
    token = strtok(NULL, sep);
    perror(array[i]);
  }

  free(string);

  return array;
}

void print_string_array(FILE *file, char **array, int size) {
  for (int i = 0; i < size; i++)
    fprintf(file, "%s\n", array[i]);
}

// backtracking

int successor(int stack[], int stack_level, int size) {
  if (stack[stack_level] >= size - 1)
    return 0;

  stack[stack_level]++;
  return 1;
}

int valid(int stack[], int stack_level) { return 1; }

int valid_string(char **array, int size, int stack[], int stack_level) {
  return 1;
  if (stack_level != 1)
    return 1;

  unsigned len = strlen(array[stack[stack_level]]);

  if (strncmp(array[stack[0]], array[stack[1]], len - 1) == 0)
    return 1;

  return 0;
}

int solution(int stack_level, int size) { return stack_level == size - 1; }

int solution_string(char **array, int size, int stack[], int stack_level) {

  char concat[MAX_STRING_LEN] = "\0";

  for (int i = 1; i <= stack_level; i++) {
    strcat(concat, array[stack[i]]);

    // if (strlen(concat) > strlen(array[stack[0]]))
    // return 0;
  }

  int res = strcmp(array[stack[0]], concat);
  // printf("RES: %d\n", res);

  return res == 0;
}

void print_solution(char **array, int stack[], int size) {
  for (int i = 0; i < size; i++)
    printf("%s ", array[stack[i]]);

  printf("\n");
}

#define STACK_INIT_VALUE -1

int back(char **array, int size) {
  int permutations = 0;

  for (int i = size; i > 2; i--) {
    int stack_level = STACK_INIT_VALUE + 1;
    int stack[i];
    stack[stack_level] = STACK_INIT_VALUE;

    while (stack_level > STACK_INIT_VALUE) {
      if (successor(stack, stack_level, size)) {
        if (valid(stack, stack_level) &&
            valid_string(array, size, stack, stack_level)) {
          if (solution(stack_level, i)) {
            if (solution_string(array, size, stack, stack_level)) {
              permutations++;
              print_solution(array, stack, i);
            }
          } else {
            stack_level++;
            stack[stack_level] = STACK_INIT_VALUE;
          }
        } else {
          ;
        }
      } else {
        stack_level--;
      }
    }
  }

  return permutations;
}
