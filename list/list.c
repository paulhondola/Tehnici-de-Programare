#include "list.h"

list_t init_list(void) { return (list_t){NULL, NULL}; }

void add_front_node(list_t *list, list_data_t input_data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = input_data;
  new_node->next = list->head;
  list->head = new_node;

  if (list->rear == NULL) {
    list->rear = new_node;
  }
}

void add_rear_node(list_t *list, list_data_t input_data) {
  if (list->rear == NULL) {
    add_front_node(list, input_data);
    return;
  }
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = input_data;
  new_node->next = NULL;

  list->rear->next = new_node;
  list->rear = list->rear->next;
}

void pop_front(list_t *list) {
  if (list->head == NULL) {
    printf("List is empty\n");
    return;
  }

  node_t *temp = list->head;
  list->head = list->head->next;
  free(temp);
}

void pop_rear(list_t *list) {
  node_t *iterator = list->head;

  if (iterator == NULL) {
    printf("List is empty\n");
    return;
  }

  if (iterator->next == NULL) {
    free(iterator);
    list->head = NULL;
    list->rear = NULL;
    return;
  }

  while (iterator->next != list->rear) {
    iterator = iterator->next;
  }

  free(iterator->next);
  iterator->next = NULL;

  list->rear = iterator;
}

void print_list(list_t list) {
  node_t *current = list.head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}
