#include "kvs.h"

struct kv_store {
  struct kv_pair *pairs;
  size_t size;
  size_t capacity;
};

KVS_t init_kvs(size_t cap) {
  KVS_t dataset = NULL;

  dataset = (KVS_t)malloc(sizeof(struct kv_store));

  if (dataset == NULL) {
    perror("No memory :(");
    return NULL;
  }

  *dataset = (struct kv_store){.pairs = NULL, .size = 0, .capacity = cap};

  dataset->pairs = (struct kv_pair *)malloc(cap * sizeof(struct kv_pair));

  if (dataset->pairs == NULL) {
    perror("No memory :(");
    cap = 0;
  }

  return dataset;
}

KVS_t add_element(KVS_t dataset, EL_t element) {
  if (dataset->size == dataset->capacity) {
    return dataset;
  }

  dataset->pairs[dataset->size++] =
      (struct kv_pair){element.key, element.value};

  return dataset;
}

void print_kvs(KVS_t dataset) {

  printf("SIZE: %zu\n", dataset->size);
  printf("CAPACITY: %zu\n", dataset->capacity);

  for (size_t i = 0; i < dataset->size; i++) {
    printf("Key: %u, Value: %f\n", dataset->pairs[i].key,
           dataset->pairs[i].value);
  }
}

void free_kvs(KVS_t dataset) {
  free(dataset->pairs);
  free(dataset);
}
