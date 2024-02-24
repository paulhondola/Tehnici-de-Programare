#include "lists.h"

node *new_node(node *list, int data) {
  node *head = (node *)malloc(sizeof(node));
  head->data = data;
  head->next = list;
  return head;
}

node *add_to_front(node *head, int data) { return new_node(head, data); }

node *add_to_back(node *head, int data) {
  node *iterator = head;

  if (iterator == NULL)
    return new_node(NULL, data);

  while (iterator->next != NULL) {
    iterator = iterator->next;
  }

  iterator->next = new_node(NULL, data);

  return head;
}

void print_list(node *head) {
  node *iterator = head;

  while (iterator != NULL) {
    printf("%d -> ", iterator->data);
    iterator = iterator->next;
  }

  printf("NULL\n");
}

node *pop_back(node *head) {
  node *iterator = head;

  if (iterator == NULL)
    return NULL;

  if (iterator->next == NULL) {
    free(iterator);
    return NULL;
  }

  while (iterator->next->next != NULL) {
    iterator = iterator->next;
  }

  free(iterator->next);
  iterator->next = NULL;

  return head;
}

node *pop_front(node *head) {
  node *temp = head;

  if (temp == NULL)
    return NULL;

  head = head->next;
  free(temp);

  return head;
}

node *insert_at(node *head, int data, int position) {
  node *iterator = head;
  node *new_node = NULL;

  // 1 -> 2 -> 3 -> NULL

  // insert 4 at position 1

  // 1 -> 4 -> 2 -> 3 -> NULL

  if (position == 0)
    return add_to_front(head, data);

  if (iterator == NULL) {
    perror("Position out of bounds");
    return head;
  }

  for (int i = 0; i < position - 1; i++) {
    iterator = iterator->next;

    if (iterator == NULL) {
      perror("Position out of bounds");
      return head;
    }
  }

  new_node = (node *)malloc(sizeof(node));

  new_node->data = data;

  new_node->next = iterator->next;

  iterator->next = new_node;

  return head;
}

void free_list(node *head) {
  node *iterator = NULL;

  while (head != NULL) {
    iterator = head;
    head = head->next;
    free(iterator);
  }
}

node *remove_element_x(node *head, int x) {
  // 1 -> x -> 2

  while (head->data == x) {
    head = pop_front(head);

    if (head == NULL)
      break;
  }

  if (head == NULL) {
    return head;
  }

  node *aux = NULL;
  node *iterator = head;

  while (iterator->next != NULL) {
    if (iterator->next->data == x) {
      aux = iterator->next;

      iterator->next = iterator->next->next;

      free(aux);
    } else
      iterator = iterator->next;
  }

  return head;
}
