#include "student.h"
#include <iso646.h>

#define MAX_NAME_LEN 100
#define OPT_LEN 3
#define OPT_COUNT 4

struct STUDENT_DATA {
  char name[MAX_NAME_LEN];
  char opt[OPT_COUNT][OPT_LEN];
};

// INPUT
student_data_t read_student_data(FILE *file) {
  student_data_t data = malloc(sizeof(struct STUDENT_DATA));

  if (data == NULL)
    return NULL;

  // read name

  if (fgets(data->name, MAX_NAME_LEN, file) == NULL)
    return NULL;

  // if the name ends with a newline, remove it
  // if it does not, consume it

  unsigned len = strlen(data->name);

  if (data->name[len - 1] == '\n')
    data->name[len - 1] = '\0';
  else
    fgetc(file);

  // read opt data

  if (fscanf(file, "%2s %2s %2s %2s\n", data->opt[0], data->opt[1],
             data->opt[2], data->opt[3]) != 4)
    return NULL;

  return data;
}

student_data_t *read_student_data_array(FILE *file, const int size) {

  student_data_t *array = malloc(sizeof(student_data_t) * (size));

  if (array == NULL)
    return NULL;

  for (int i = 0; i < size; i++)
    array[i] = read_student_data(file);

  return array;
}

// OUTPUT
void print_student_data(FILE *file, const student_data_t data) {

  if (data == NULL) {
    fprintf(file, "NULL\n");
    return;
  }

  fprintf(file, "NAME: %s\nOPT: %s %s %s %s\n", data->name, data->opt[0],
          data->opt[1], data->opt[2], data->opt[3]);
}

void print_student_data_array(FILE *file, const student_data_t *data,
                              const int size) {

  if (data == NULL) {
    fprintf(file, "NULL ARRAY");
    return;
  }

  for (int i = 0; i < size; i++)
    print_student_data(file, data[i]);
}

// COMPARATORS
int compare_student_names_asc(const void *p, const void *q) {
  return strcmp(((student_data_t)p)->name, ((student_data_t)q)->name);
}

int compare_names(const void *p, const void *q) {
  return strcmp((char *)p, (char *)q);
}

// SORTING
void sort_by_name(student_data_t *array, int size) {
  qsort(array, size, sizeof(student_data_t), compare_student_names_asc);
}

// SEARCHING

int b_search(student_data_t *array, char *searched, int left, int right) {

  if (left > right)
    return -1;

  int mid = (left + right) / 2;

  int result = compare_names(searched, array[mid]->name);

  if (result == 0)
    return mid;

  if (result == 1)
    return b_search(array, searched, mid + 1, right);
  else
    return b_search(array, searched, left, mid - 1);
}

/*
int b_search(student_data_t *array, int size, char *searched) {
  char **names = malloc(sizeof(char *) * size);

  if (names == NULL)
    return -2;

  for (int i = 0; i < size; i++) {
    names[i] = malloc(MAX_NAME_LEN);

    if (names[i] == NULL) {
      for (int j = 0; j < i; j++)
        free(names[i]);
      free(names);
      return -2;
    }

    strcpy(names[i], array[i]->name);
  }

  char *found = bsearch(&searched, names, size, sizeof(char *), compare_names);

  perror(found);

  for (int i = 0; i < size; i++)
    free(names[i]);
  free(names);

  return -1;
}
*/
