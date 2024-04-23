// 4. Se dă un vector cu n elemente numere naturale. Folosind metoda Divide et
// Impera să se verifice dacă are elementele ordonate crescător.

#include "/Users/paulhondola/Faculta/Tehnici de Programare/project/rand array/rand_array.h"
#include <stdio.h>
#define SIZE 100

void print_array(int *v, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int check_sorted_asc(int *v, unsigned left, unsigned right) {
  unsigned mid = (left + right) / 2;

  if (left == right)
    return 1;

  if (v[mid] > v[mid + 1])
    return 0;

  return check_sorted_asc(v, left, mid) && check_sorted_asc(v, mid + 1, right);
}

int main(void) {

  int *sorted = make_rand_flexi_array(SIZE, get_new_element_asc, 10);
  int *sorted_desc = make_rand_flexi_array(SIZE, get_new_element_desc, 10);
  int *unsorted = make_rand_limit_array(SIZE, 0, 1000);

  printf("check sort: %d\n", check_sorted_asc(sorted, 0, SIZE - 1));
  printf("check sort: %d\n", check_sorted_asc(sorted_desc, 0, SIZE - 1));
  printf("check sort: %d\n", check_sorted_asc(unsorted, 0, SIZE - 1));

  return 0;
}
