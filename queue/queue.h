#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CHUNK 16

typedef int queue_data;

typedef struct queue {
  int head;
  int rear;
  int size;
  int capacity;
  queue_data *data;
} queue;

void init_queue(queue *q);

void enqueue(queue *q, queue_data data);

void dequeue(queue *q);

queue_data peek_head(queue *q);

queue_data peek_rear(queue *q);

void free_queue(queue *q);

#endif
