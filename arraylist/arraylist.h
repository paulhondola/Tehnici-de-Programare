#ifndef __ARRAYLIST_H
#define __ARRAYLIST_H

// libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constants

#define MAX_NAME_SIZE 100
#define HASH_TABLE_CHUNK 16
#define DEBUG 1

// structures

typedef struct PAYLOAD {
  int key;
  double value;
  char name[MAX_NAME_SIZE];
} payload_t;

typedef struct NODE *node_t;
typedef struct ARRAY_LIST *array_list_t;

// functions

// payload functions

payload_t create_payload(int, double, char[]);

// node functions

node_t create_node(payload_t);
void print_payload(node_t, FILE *);

// array list functions

array_list_t init_array_list(void);

// adding
array_list_t add_to_front(array_list_t, node_t);
array_list_t add_to_index(array_list_t, node_t, size_t);

// removing
array_list_t remove_from_front(array_list_t);
array_list_t remove_from_index(array_list_t, size_t);

// getting
node_t get_node(array_list_t, size_t);

// printing
void print_array_list(array_list_t, FILE *);

// freeing
void free_array_list(array_list_t);

#endif
