#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int list_data_t;

typedef struct node {
  list_data_t data;
  struct node *next;
} node_t;

typedef struct {
  node_t *head;
  node_t *rear;
} list_t;

list_t init_list(void);

void add_front_node(list_t *list, int data);

void add_rear_node(list_t *list, int data);

void pop_front(list_t *list);

void pop_rear(list_t *list);

void print_list(list_t list);

#endif
