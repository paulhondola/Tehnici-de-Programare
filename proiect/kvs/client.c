#include "kvs.h"
#define PI 3.14159265359
#define SIZE 10

int main(void) {

  KVS_t dataset = init_kvs(SIZE);

  EL_t input_data;

  for (int i = 0; i < SIZE; i++) {

    input_data = (EL_t){.key = i, .value = PI * i};

    dataset = add_element(dataset, input_data);
  }

  print_kvs(dataset);

  free_kvs(dataset);

  return 0;
}
