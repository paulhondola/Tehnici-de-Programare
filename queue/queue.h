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
  size_t size;
  size_t capacity;
  queue_data *data;
} queue;

queue init_queue(size_t capacity);

int enqueue(queue *q, queue_data data);

int dequeue(queue *q);

queue_data peek_head(queue *q);

queue_data peek_rear(queue *q);

void free_queue(queue *q);

#endif
