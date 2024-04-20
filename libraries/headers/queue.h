#ifndef __QUEUE_H
#define __QUEUE_H

// libraries
#include <stdio.h>
#include <stdlib.h>

// constants
#define QUEUE_DEBUG 1
#define QUEUE_DYNAMIC 1
#define QUEUE_CHUNK 16

// data structures
typedef int queue_data;
typedef struct QUEUE *queue;

// FUNCTIONS

// INITIALIZATION
queue init_queue(size_t capacity);

// GETTERS
size_t get_queue_size(queue queue);
size_t get_queue_capacity(queue queue);

// QUEUE SIZE FUNCTIONS
int queue_is_empty(queue queue);
int queue_is_empty(queue queue);
queue queue_realloc(queue queue);

// QUEUE OPERATIONS
queue enqueue(queue queue, queue_data data);
queue dequeue(queue queue);
void move_queue(queue queue);
queue_data head(queue queue);
queue_data tail(queue queue);

// DEBUGGING
void print_queue(queue queue);

// FREE
void free_queue(queue queue);

#endif
