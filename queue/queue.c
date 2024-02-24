#include "queue.h"

void init_queue(queue *q) {
  q->head = -1;
  q->rear = -1;
  q->size = 0;
  q->used_size = 0;
  q->capacity = QUEUE_CHUNK;

  q->data =
      (queue_data *)malloc((unsigned long)q->capacity * sizeof(queue_data));

  if (q->data == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
}

void enqueue(queue *q, queue_data data) {
  if (q->used_size == q->capacity - 1) {
    q->capacity += QUEUE_CHUNK;
    q->data = (queue_data *)realloc(
        q->data, ((unsigned long)q->capacity * sizeof(queue_data)));

    if (q->data == NULL) {
      printf("Memory allocation failed\n");
      exit(2);
    }
  }

  if (q->head == -1) {
    q->head = 0;
  }

  q->data[++q->rear] = data;

  q->used_size++;
  q->size++;
}

void dequeue(queue *q) {
  if (q->size == 0) {
    printf("Queue is empty\n");
    return;
  }

  q->head++;
  q->size--;
}

queue_data peek_head(queue *q) { return q->data[q->head]; }

queue_data peek_rear(queue *q) { return q->data[q->rear]; }

void print_queue(queue *q) {

  if (q->size == 0) {
    printf("Queue is empty\n");
    return;
  }

  for (int i = q->head; i <= q->rear; i++) {
    printf("%d ", q->data[i]);
  }

  printf("\n");
}

void free_queue(queue *q) {
  free(q->data);
  q->head = -1;
  q->rear = -1;
  q->size = 0;
  q->capacity = 0;
}
