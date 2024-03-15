#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>

extern int LIST_DEBUG;

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

int add_front_node(list_t *list, list_data_t data);

int add_rear_node(list_t *list, list_data_t data);

int pop_front(list_t *list);

int pop_rear(list_t *list);

void print_list(list_t *list);

void free_list(list_t *list);

#endif
