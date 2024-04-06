#include "arraylist.h"

// structures

struct NODE {
  payload_t payload;
  struct NODE *next;
};

struct ARRAY_LIST {
  struct NODE *item;
  size_t size;
  size_t capacity;
  struct NODE **hash_table;
};

// payload functions

payload_t create_payload(int key, double value, char name[]) {
  if (DEBUG == 1)
    fprintf(stderr, "Creating payload\n");
  payload_t payload = {.key = key, .value = value};
  strncpy(payload.name, name, sizeof(payload.name) - 1);
  return payload;
}

// node functions

node_t create_node(payload_t info) {
  if (DEBUG == 1)
    fprintf(stderr, "Creating node\n");
  node_t node = (node_t)malloc(sizeof(struct NODE));

  if (node == NULL) {
    if (DEBUG == 1)
      fprintf(stderr, "Node allocation: FAIL\n");
    return NULL;
  }

  if (DEBUG == 1)
    fprintf(stderr, "Node allocation: SUCCESS\n");

  *node = (struct NODE){.payload = info, .next = NULL};
  return node;
}

void print_payload(node_t node, FILE *file) {
  fprintf(file, "KEY: %d / VALUE: %f / NAME: %s\n", node->payload.key,
          node->payload.value, node->payload.name);
}

node_t get_node(array_list_t list, size_t index) {
  if (DEBUG == 1)
    fprintf(stderr, "Getting node at index %zu\n", index);
  return list->hash_table[index];
}

// arraylist functions

array_list_t init_array_list(void) {
  if (DEBUG == 1)
    fprintf(stderr, "Initializing array list\n");

  array_list_t list = (array_list_t)malloc(sizeof(struct ARRAY_LIST));

  // if the allocation fails, return NULL

  if (list == NULL) {
    if (DEBUG == 1)
      fprintf(stderr, "Array list allocation: FAIL\n");
    return NULL;
  }

  if (DEBUG == 1)
    fprintf(stderr, "Array list allocation: SUCCESS\n");

  *list = (struct ARRAY_LIST){
      .item = NULL, .size = 0, .capacity = 0, .hash_table = NULL};

  return list;
}

// insert and remove aux functions

void remove_aux_function(array_list_t list, node_t node, size_t index) {
  list->size--;
  for (size_t i = index; i < list->size; i++)
    list->hash_table[i] = list->hash_table[i + 1];
  free(node);
}

void insert_aux_function(array_list_t list, node_t node, size_t index) {
  list->size++;
  for (size_t i = list->size - 1; i > index; i--)
    list->hash_table[i] = list->hash_table[i - 1];
  list->hash_table[index] = node;
}

// add

array_list_t add_to_front(array_list_t list, node_t node) {
  if (DEBUG == 1)
    fprintf(stderr, "Adding new node to front\n");

  // if the list is empty -> alloc new memory for the hash table
  if (list->size == 0) {
    if (DEBUG == 1)
      fprintf(stderr, "List is empty\n");

    list->hash_table =
        (struct NODE **)malloc(sizeof(struct NODE *) * HASH_TABLE_CHUNK);

    // if the allocation fails, return NULL
    if (list->hash_table == NULL) {
      if (DEBUG == 1)
        fprintf(stderr, "Hash table allocation: FAIL\n");
      return NULL;
    }

    if (DEBUG == 1)
      fprintf(stderr, "Hash table allocation: SUCCESS\n");

    list->capacity = HASH_TABLE_CHUNK;
  }

  // if the size has reached full capacity, reallocate
  else if (list->size == list->capacity) {
    if (DEBUG == 1)
      fprintf(stderr, "List has reached full capacity, realloc one more chunk "
                      "for the hash table\n");

    list->capacity += HASH_TABLE_CHUNK;
    list->hash_table = (struct NODE **)realloc(
        list->hash_table, sizeof(struct NODE *) * list->capacity);

    // if the reallocation fails, return NULL
    if (list->hash_table == NULL) {
      if (DEBUG == 1)
        fprintf(stderr, "Hash table reallocation: FAIL\n");
      return NULL;
    }

    if (DEBUG == 1)
      fprintf(stderr, "Hash table reallocation: SUCCESS, new capacity: %zu\n",
              list->capacity);
  }

  if (DEBUG == 1)
    fprintf(stderr, "New node added to front: SUCCESS, size increased to %zu\n",
            list->size + 1);

  node->next = list->item;
  list->item = node;
  insert_aux_function(list, node, 0);

  return list;
}

array_list_t add_to_index(array_list_t, node_t, size_t);

// remove
array_list_t remove_from_front(array_list_t list) {

  if (list->size == 0) {
    if (DEBUG == 1)
      fprintf(stderr, "List is empty\n");
    return list;
  }

  if (DEBUG == 1)
    fprintf(stderr, "Removing node from front\n");

  node_t aux = list->item;
  list->item = list->item->next;
  remove_aux_function(list, aux, 0);
  return list;
}

array_list_t remove_from_index(array_list_t list, size_t index) {
  if (list->size == 0) {
    if (DEBUG == 1)
      fprintf(stderr, "List is empty\n");
    return list;
  }

  if (index == 0)
    return remove_from_front(list);

  if (DEBUG == 1)
    fprintf(stderr, "Removing node from index %zu\n", index);

  node_t removed = list->hash_table[index];
  list->hash_table[index - 1]->next = list->hash_table[index + 1];
  remove_aux_function(list, removed, index);
  return list;
}

// print
void print_array_list(array_list_t list, FILE *file) {
  if (DEBUG == 1)
    fprintf(stderr, "Printing array list -> size: %zu\n", list->size);

  for (size_t i = 0; i < list->size; i++)
    print_payload(get_node(list, i), file);
}

// free
void free_array_list(array_list_t list) {
  for (size_t i = 0; i < list->size; i++) {
    if (DEBUG == 1)
      fprintf(stderr, "Freeing node at index %zu\n", i);
    free(list->hash_table[i]);
  }

  if (DEBUG == 1) {
    size_t list_size = sizeof(*list);
    size_t hash_table_size = sizeof(list->hash_table) * list->capacity;
    size_t node_size = sizeof(struct NODE) * list->size;

    fprintf(stderr, "TOTAL FREED MEMORY: %zu\n",
            list_size + hash_table_size + node_size);

    fprintf(stderr, "NODES: %zu(bytes) * %zu(count) = %zu\n",
            sizeof(struct NODE), list->size, node_size);
    fprintf(stderr, "HASH TABLE: %zu(bytes) * %zu(count) = %zu\n",
            sizeof(list->hash_table), list->capacity, hash_table_size);
    fprintf(stderr, "LIST: %zu(bytes)\n", list_size);
  }

  free(list->hash_table);
  free(list);
}
