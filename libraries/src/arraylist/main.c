#include "arraylist.h"

int main(void)
{

  array_list_t list = init_array_list();

  if (list == NULL)
    return 1;

  for (int i = 0; i < 10; i++)
    list = add_front_node(
        list, create_node(create_payload(i, i * 3.14, "payload 1")));

  print_array_list(list, stdout);

  printf("................................................................\n");

  for (int i = 10; i < 20; i++)
    list = add_rear_node(list,
                         create_node(create_payload(i, i * 3.14, "payload 2")));

  print_array_list(list, stdout);

  printf("................................................................\n");

  for (int i = 20; i < 30; i++)
    list = add_index_node(
        list, create_node(create_payload(i, i * 3.14, "payload 3")), 10);

  print_array_list(list, stdout);

  printf("................................................................\n");

  for (int i = 0; i < 10; i++)
    list = remove_index_node(list, 10);

  print_array_list(list, stdout);

  printf("................................................................\n");

  for (int i = 0; i < 10; i++)
    list = remove_front_node(list);

  print_array_list(list, stdout);

  printf("................................................................\n");

  for (int i = 0; i < 10; i++)
    list = remove_rear_node(list);

  print_array_list(list, stdout);

  printf("................................................................\n");

  free_array_list(list);

  return 0;
}
