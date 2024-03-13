#include "list.h"

list_t init_list(void) { return (list_t){NULL, NULL}; }

int add_front_node(list_t *list, list_data_t input_data) {

  node_t *new_node = (node_t *)malloc(sizeof(node_t));

  if (new_node == NULL) {
    if (LIST_DEBUG)
      printf("memory allocation failed\n");

    return 0;
  }

  if (LIST_DEBUG)
    printf("new node linked to front / data linked: %d\n", input_data);

  *new_node = (node_t){input_data, list->head};

  list->head = new_node;

  if (list->rear == NULL) {
    list->rear = new_node;
  }

  return 1;
}

int add_rear_node(list_t *list, list_data_t input_data) {

  if (list->rear == NULL) {
    if (!add_front_node(list, input_data)) {
      return 0;
    }
    return 1;
  }

  node_t *new_node = (node_t *)malloc(sizeof(node_t));

  if (new_node == NULL) {
    if (LIST_DEBUG)
      printf("memory allocation failed\n");

    return 0;
  }

  if (LIST_DEBUG)
    printf("new node linked to rear / data linked: %d\n", input_data);

  *new_node = (node_t){input_data, NULL};

  list->rear->next = new_node;
  list->rear = list->rear->next;

  return 1;
}

int pop_front(list_t *list) {
  if (list->head == NULL) {
    printf("list is empty, no action taken\n");
    return -1;
  }

  if (list->head->next == NULL) {

    if (LIST_DEBUG)
      printf("removed last item in list\n");

    free(list->head);

    *list = (list_t){NULL, NULL};

    return 0;
  }

  if (LIST_DEBUG)
    printf("pop front / data: %d\n", list->head->data);

  node_t *temp = list->head;
  list->head = list->head->next;
  free(temp);

  return 1;
}

int pop_rear(list_t *list) {

  if (list->head == NULL) {
    printf("list is empty, no action taken\n");
    return -1;
  }

  if (list->head->next == NULL) {

    if (LIST_DEBUG)
      printf("removed last item in list\n");

    free(list->head);
    *list = (list_t){NULL, NULL};

    return 0;
  }

  if (LIST_DEBUG)
    printf("pop front / data: %d\n", list->rear->data);

  node_t *iterator = list->head;

  while (iterator->next != list->rear) {
    iterator = iterator->next;
  }

  free(iterator->next);
  iterator->next = NULL;

  list->rear = iterator;

  return 1;
}

void print_list(list_t *list) {

  node_t *current = list->head;

  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("NULL\n");
}

void free_list(list_t *list) {
  node_t *current = list->head;

  while (current != NULL) {
    node_t *temp = current;
    current = current->next;
    free(temp);
  }

  *list = (list_t){NULL, NULL};
}
