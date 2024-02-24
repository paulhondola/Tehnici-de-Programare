#include "list.h"

#define SIZE 10

int main(void) {
  list_t list = init_list();

  // add_front_node(&list, 1);
  // add_front_node(&list, 2);
  add_rear_node(&list, 3);
  add_rear_node(&list, 4);
  add_rear_node(&list, 5);

  pop_front(&list);
  pop_front(&list);
  print_list(list);

  return 0;
}
