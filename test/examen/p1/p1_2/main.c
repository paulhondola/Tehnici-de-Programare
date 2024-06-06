#include "student.h"

int main(void) {

  int size = 0;

  if (scanf("%d\n", &size) != 1)
    return 1;

  size /= 2;

  student_data_t *data = read_student_data_array(stdin, size);

  sort_by_name(data, size);

  print_student_data_array(stdout, data, size);

  char *searched1 = "ABALARU STEFAN";
  char *searched2 = "ABDOL REZE SAMIEE";
  char *searched3 = "POL PETROL";
  char *searched4 = "NU STIU";

  printf("Index: %d\n", b_search(data, searched1, 0, size - 1));
  printf("Index: %d\n", b_search(data, searched2, 0, size - 1));
  printf("Index: %d\n", b_search(data, searched3, 0, size - 1));
  printf("Index: %d\n", b_search(data, searched4, 0, size - 1));

  return 0;
}
