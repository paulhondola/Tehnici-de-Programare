/*
1. Implementati algorimtul de cautare binara pe o lista simplu inlantuita (se va
implementa sub forma de ArrayList pentru a permite acces aleator la elemente).
*/

#include "/Users/paulhondola/Faculta/Tehnici de Programare/libraries/headers/arraylist.h"
#include "/Users/paulhondola/Faculta/Tehnici de Programare/project/rand array/rand_array.h"
#include <stdlib.h>

void print_list(array_list_t list) {
  size_t size = get_size(list);

  for (size_t i = 0; i < size; i++) {
    print_node_data(get_node(list, i), stdout);
    printf("\n");
  }
}

int bin_search(array_list_t list, size_t left, size_t right, int value) {

  if (left > right)
    return -1;

  node_t node = get_node(list, (left + right) / 2);

  if (get_payload(node) == value)
    return (left + right) / 2;

  if (get_payload(node) > value)
    return bin_search(list, left, (left + right) / 2 - 1, value);

  return bin_search(list, (left + right) / 2 + 1, right, value);
}

int main(void) {

  srand(time(NULL));

  int *v = make_rand_flexi_array(100, get_new_element_asc, 10);

  array_list_t list = init_array_list();

  for (int i = 0; i < 100; i++) {
    add_rear_node(list, create_node(v[i]));
  }

  print_list(list);

  int value = 100;

  printf("Index of %d: %d\n", value,
         bin_search(list, 0, get_size(list) - 1, value));

  return 0;
}
