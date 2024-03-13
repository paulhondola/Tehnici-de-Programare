#include "queue.h"

queue init_queue(size_t capacity) {

  queue q = {0, 0, capacity, NULL};

  q.data = (queue_data *)malloc(capacity * sizeof(queue_data));

  if (q.data == NULL) {
    if (QUEUE_DEBUG)
      printf("Memory allocation failed\n");

    q.capacity = 0;
    return q;
  }

  q.capacity = capacity;

  if (QUEUE_DEBUG) {
    printf("Initialization successful\n");
    printf("Queue capacity set to: %zu\n", q.capacity);
  }

  return q;
}

int queue_is_empty(queue *q) {
  if (QUEUE_DEBUG && q->head == q->tail)
    printf("queue empty\n");
  return q->head == q->tail;
}

int queue_is_full(queue *q) {
  if (QUEUE_DEBUG && q->tail >= q->capacity)
    printf("queue full\n");
  return q->tail >= q->capacity;
}

int queue_realloc(queue *q) {
  queue_data *temp = (queue_data *)realloc(
      q->data, (q->capacity + QUEUE_CHUNK) * sizeof(queue_data));

  if (temp == NULL) {
    if (QUEUE_DEBUG) {
      printf("memory reallocation failed\n");
      printf("queue capacity remains at: %zu\n", q->capacity);
      printf("no enqueue happened\n");
    }
    return 0;
  }

  q->data = temp;
  q->capacity += QUEUE_CHUNK;

  if (QUEUE_DEBUG)
    printf("queue capacity increased to: %zu\n", q->capacity);

  return 1;
}

int enqueue(queue *q, queue_data data) {

  if (queue_is_full(q)) {
    if (QUEUE_DYNAMIC) {
      if (!queue_realloc(q))
        return 0;
    } else {
      if (QUEUE_DEBUG)
        printf("no enqueue happened\n");
      return 0;
    }
  }

  if (QUEUE_DEBUG)
    printf("enqueue: %d\n", data);

  q->data[q->tail++] = data;

  return 1;
}

int dequeue(queue *q) {
  if (queue_is_empty(q)) {
    return 0;
  }

  if (QUEUE_DEBUG) {
    printf("dequeue %d\n", q->data[q->head]);
  }

  q->head++;
  return 1;
}

queue_data head(queue *q) {

  if (queue_is_empty(q)) {
    return 0;
  }

  if (QUEUE_DEBUG)
    printf("head: %d\n", q->data[q->head]);

  return q->data[q->head];
}

queue_data tail(queue *q) {

  if (queue_is_empty(q)) {
    return 0;
  }

  if (QUEUE_DEBUG)
    printf("tail: %d\n", q->data[q->tail - 1]);

  return q->data[q->tail - 1];
}

void print_queue(queue *q) {
  for (size_t i = q->head; i < q->tail; i++) {
    printf("%d ", q->data[i]);
  }
}

void free_queue(queue *q) {
  if (QUEUE_DEBUG)
    printf("free queue\n");

  free(q->data);
  *q = (queue){0, 0, 0, NULL};
}
