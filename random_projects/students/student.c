#include "student.h"

struct STUDENT_T
{
  char *name;
  char *opt1;
  char *opt2;
  char *opt3;
  char *opt4;
};

char **format_optional_data(char *line)
{

  char **optional_data = (char **)malloc(CODE_COUNT * sizeof(char *));

  if (optional_data == NULL)
  {
    printf("Error: Could not allocate memory for optional_data\n");
    exit(1);
  }

  char *token = strtok(line, " ");

  for (unsigned i = 0; i < CODE_COUNT; i++)
  {

    if (token == NULL)
    {
      printf("Error: Could not read optional data\n");
      exit(1);
    }

    optional_data[i] =
        (char *)malloc((MAX_OPTIONAL_NAME_LEN + 1) * sizeof(char));

    if (optional_data[i] == NULL)
    {
      printf("Error: Could not allocate memory for optional_data[%d]\n", i);
      exit(1);
    }

    strcpy(optional_data[i], token);

    token = strtok(NULL, " ");
  }

  return optional_data;
}

student_t read_student_data(FILE *file)
{

  student_t student = (student_t)malloc(sizeof(struct STUDENT_T));

  if (student == NULL)
  {
    printf("Error: Could not allocate memory for student\n");
    exit(1);
  }

  *student = (struct STUDENT_T){NULL, NULL, NULL, NULL, NULL};

  char line[MAX_LINE_LENGTH];

  // READ STUDENT NAME

  if (fgets(line, MAX_LINE_LENGTH, file) == NULL)
    return student;

  // line was shorter than MAX_LINE_LENGTH, remove newline character
  if (line[strlen(line) - 1] == '\n')
    line[strlen(line) - 1] = '\0';

  student->name = malloc((strlen(line) + 1) * sizeof(char));

  if (student->name == NULL)
  {
    printf("Error: Could not allocate memory for student.name\n");
    exit(1);
  }

  strcpy(student->name, line);

  // READ OPTIONAL DATA

  if (fgets(line, MAX_LINE_LENGTH, file) == NULL)
    return student;

  // line was shorter than MAX_LINE_LENGTH, remove newline character

  if (line[strlen(line) - 1] == '\n')
    line[strlen(line) - 1] = '\0';

  char **optional_data = format_optional_data(line);

  student->opt1 = optional_data[0];
  student->opt2 = optional_data[1];
  student->opt3 = optional_data[2];
  student->opt4 = optional_data[3];

  free(optional_data);

  return student;
}

student_t *get_students(unsigned count, FILE *file)
{

  student_t *students = (student_t *)malloc(count * sizeof(student_t));

  if (students == NULL)
  {
    printf("Error: Could not allocate memory for students\n");
    exit(1);
  }

  for (unsigned i = 0; i < count; i++)
    students[i] = read_student_data(file);

  return students;
}

int compare_student_names(const void *p, const void *q)
{
  student_t st_p = *(student_t *)(p);
  student_t st_q = *(student_t *)(q);
  return strcmp(st_p->name, st_q->name);
}

void sort_students(student_t *students, unsigned count)
{
  qsort(students, count, sizeof(students), compare_student_names);
}

int get_student_index(const char *searched, student_t *students,
                      unsigned count)
{

  for (unsigned i = 0; i < count; i++)
    if (strcmp(students[i]->name, searched) == 0)
      return i;

  return -1;
}

void print_student_data(student_t st)
{
  printf("NAME: %s\nOPTIONALS: ", st->name);
  printf("%s ", st->opt1);
  printf("%s ", st->opt2);
  printf("%s ", st->opt3);
  printf("%s ", st->opt4);
  printf("\n");
}

void free_student_data(student_t st)
{
  free(st->name);
  free(st->opt1);
  free(st->opt2);
  free(st->opt3);
  free(st->opt4);
  free(st);
}
