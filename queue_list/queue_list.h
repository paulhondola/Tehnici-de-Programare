#ifndef __QUEUE_LIST_H
#define __QUEUE_LIST_H

#include "/Users/paulhondola/Faculta/Tehnici de Programare/list/list.h"

typedef list_data_t payload_t;
typedef list_t queue_list_t;

// INIT
queue_list_t init_stack(void);

// FREE
void free_stack(queue_list_t stack);

// DISPLAY
void print_stack(queue_list_t stack);

// SIZE
size_t get_size(queue_list_t stack);

// PUSH
queue_list_t push(queue_list_t stack, payload_t info);

// POP
queue_list_t pop(queue_list_t stack);

// PEEK
payload_t peek(queue_list_t stack);

// ISEMPTY
int is_empty(queue_list_t stack);

#endif
