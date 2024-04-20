#include "/Users/paulhondola/Faculta/Tehnici de Programare/AUX/DATA_STRUCTURES/list/list.h"
#include <time.h>
#define ARR_CHUNK 10
#define MAX 100

list_t create_element_list(int *arr, size_t size)
{

  list_t list = init_list();

  for (size_t i = 0; i < size; i++)
    list = add_rear_node(list, create_node(arr[i]));

  /*
  for (int i = size - 1; i >= 0; i--)
    list = add_front_node(list, create_node(arr[i]));
  */
  return list;
}

int *create_array_from_list(list_t list, size_t *size)
{

  size_t capacity = 0;
  size_t index = 0;

  int *arr = NULL;

  node_t iterator = get_list_head(list);

  while (iterator != NULL)
  {
    if (index == capacity)
    {
      capacity += ARR_CHUNK;
      arr = realloc(arr, capacity * sizeof(list_data_t));

      if (arr == NULL)
      {
        perror("realloc");
        exit(EXIT_FAILURE);
      }
    }

    arr[index++] = get_node_data(iterator);
    iterator = get_next_node(iterator);
  }

  *size = index;

  free(iterator);

  return arr;
}

void write_data_to_file(const char *filename, size_t size)
{

  FILE *file = fopen(filename, "w");

  if (file == NULL)
  {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));

  for (size_t i = 0; i < size; i++)
    fprintf(file, "%d ", rand() % MAX);

  fclose(file);
}

list_t create_list_from_file(const char *filename)
{

  FILE *file = fopen(filename, "r");

  if (file == NULL)
  {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  list_t list = init_list();

  int data;

  while (fscanf(file, "%d", &data) == 1)
    list = add_rear_node(list, create_node(data));

  fclose(file);

  return list;
}

list_t *create_odd_even_lists(list_t list)
{

  list_t *all_elements = malloc(sizeof(list_t) * 2);
  all_elements[0] = init_list();
  all_elements[1] = init_list();

  // 0 -> even, 1 -> odd

  node_t iterator = get_list_head(list);

  while (iterator != NULL)
  {

    all_elements[get_node_data(iterator) % 2] =
        add_rear_node(all_elements[get_node_data(iterator) % 2],
                      create_node(get_node_data(iterator)));

    iterator = get_next_node(iterator);
  }

  free(iterator);

  return all_elements;
}

int is_equal_to(list_data_t main, list_data_t compare)
{
  return main == compare;
}

void filter_list(list_t list,
                 list_data_t (*condition)(list_data_t, list_data_t),
                 list_data_t compare)
{

  node_t iterator = get_list_head(list);
  size_t index = 0;

  while (iterator != NULL)
  {
    /*
  if (condition(get_node_data(iterator), compare)) {
    printf("hello");
    list = remove_index_node(list, index);
  }

  else {
    iterator = get_next_node(iterator);
    index++;
  }
  */

    iterator = get_next_node(iterator);
    print_node_data(iterator);
  }
}

int main(void)
{

  //////////////////////////////////////////////////

  int arr[] = {1, 2, 3, 4, 5};
  size_t size = 5;
  list_t list = create_element_list(arr, size);

  print_list(list);

  int *new_arr = create_array_from_list(list, &size);

  printf("New array:\n");
  for (size_t i = 0; i < size; i++)
    printf("%d ", new_arr[i]);

  printf("\n");

  printf("Old list:\n");
  print_list(list);
  printf("\n");

  free(new_arr);
  free_list(list);

  /////////////////////////////////////////////////////

  write_data_to_file("date.txt", 1000);

  list_t all_elements = create_list_from_file("date.txt");

  print_list(all_elements);

  list_t *file_elements = create_odd_even_lists(all_elements);

  printf("\nEven elements:\n");

  print_list(file_elements[0]);

  printf("\nOdd elements:\n");

  print_list(file_elements[1]);

  free_list(file_elements[0]);
  free_list(file_elements[1]);
  free(file_elements);

  ////////////////////////////////////////////////////////////////

  filter_list(all_elements, is_equal_to, 5);

  printf("\nFiltered list:\n");

  print_list(list);

  free_list(list);

  return 0;
}
