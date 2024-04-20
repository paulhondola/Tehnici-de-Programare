#include "kvs.h"
#include <time.h>
#define PI 3.14159265359
#define SIZE 10000

int main(void)
{

  KVS_t dataset = init_kvs(SIZE);

  for (int i = 0; i < SIZE; i++)
    dataset = add_element(dataset, (EL_t){.key = i, .value = PI});

  print_kvs(dataset);

  srand(time(NULL));

  unsigned element;

  for (int i = 0; i < 100; i++)
  {
    element = rand() % (SIZE * 2);
    printf("Element %u at index: %d\n", element, search_key(dataset, element));
  }

  free_kvs(dataset);

  return 0;
}
