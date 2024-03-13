#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_DEBUG 1
#define QUEUE_DYNAMIC 1
#define QUEUE_CHUNK 32

typedef int queue_data;

typedef struct queue {
  size_t head;
  size_t tail;
  size_t capacity;
  queue_data *data;
} queue;

queue init_queue(size_t capacity);

int queue_is_empty(queue *q);

int queue_is_empty(queue *q);

int queue_realloc(queue *q);

int enqueue(queue *q, queue_data data);

int dequeue(queue *q);

queue_data head(queue *q);

queue_data tail(queue *q);

void print_queue(queue *q);

void free_queue(queue *q);

#endif
