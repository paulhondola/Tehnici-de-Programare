#ifndef __LISTS_H
#define __LISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *new_node(node *list, int data);

node *add_to_front(node *head, int data);

node *add_to_back(node *head, int data);

node *pop_front(node *head);

node *pop_back(node *head);

void print_list(node *head);

void free_list(node *head);

node *remove_element_x(node *head, int x);

node *insert_at(node *head, int data, int position);

#endif
