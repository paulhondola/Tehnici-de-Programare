#include "student.h"

int main(void)
{
  FILE *input_file = fopen("students.txt", "r");

  if (input_file == NULL)
  {
    printf("Error: Could not open file\n");
    return 1;
  }

  unsigned line_count = 0;

  if (fscanf(input_file, "%u", &line_count) != 1)
  {
    printf("Error: Could not read student count\n");
    return 1;
  }

  unsigned student_count = line_count / 2;

  fgetc(input_file); // consume newline character

  student_t *students = get_students(student_count, input_file);

  sort_students(students, student_count);

  int index = get_student_index("HONDOLA PAUL", students, student_count);

  if (index == -1)
    printf("NO STUDENT WITH THAT NAME");
  else
    print_student_data(students[index]);

  // for (unsigned i = 0; i < student_count; i++)
  // print_student_data(students[i]);

  for (unsigned i = 0; i < student_count; i++)
    free_student_data(students[i]);

  free(students);

  fclose(input_file);

  return 0;
}
