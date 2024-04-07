#ifndef __LIST_H
#define __LIST_H

// libraries
#include <stdio.h>
#include <stdlib.h>

// constants
#define DEBUG 1

// structures
typedef double list_data_t;
typedef struct NODE *node_t;
typedef struct LIST *list_t;

// node functions
node_t create_node(list_data_t data);
void print_node_data(node_t node);

// list functions
list_t init_list(void);
void print_list(list_t list);
void free_list(list_t list);

// adding
list_t add_front_node(list_t list, node_t node);
list_t add_rear_node(list_t list, node_t node);
list_t add_index_node(list_t list, node_t node, size_t index);

// removing
list_t remove_front_node(list_t list);
list_t remove_rear_node(list_t list);
list_t remove_index_node(list_t list, size_t index);

#endif
