#include "arraylist.h"

// TODO: INDEX BASED INSERTION AND DELETION

int main(void) {

  array_list_t list = init_array_list();

  if (list == NULL)
    return 1;

  for (int i = 0; i < 10; i++)
    list = add_to_front(list, create_node(create_payload(i, i * 3.14, "pi")));

  print_array_list(list, stdout);

  for (int i = 0; i < 15; i++)
    list = remove_from_front(list);

  print_array_list(list, stdout);

  free_array_list(list);

  return 0;
}
