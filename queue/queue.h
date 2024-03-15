#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>

extern int QUEUE_DEBUG; // default 0
extern int QUEUE_DYNAMIC; // default 0
extern size_t QUEUE_CHUNK; // default 32

typedef int queue_data;

typedef struct queue {
  size_t head;
  size_t tail;
  size_t capacity;
  queue_data *data;
} queue;

queue init_queue(size_t);

int queue_is_empty(queue *);

int queue_is_empty(queue *);

int queue_realloc(queue *);

int enqueue(queue *, queue_data);

int dequeue(queue *);

void move_queue(queue *);

queue_data head(queue *);

queue_data tail(queue *);

void print_queue(queue *);

void free_queue(queue *);

#endif
