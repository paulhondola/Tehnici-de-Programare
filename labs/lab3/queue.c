#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 5

typedef int queue_item;

typedef struct {
  queue_item *data;
  int front;
  int rear;
  int size;
  int capacity;
} queue_t;

queue_t init_queue(int capacity) {
  queue_t q;
  q.data = (queue_item *)malloc(capacity * sizeof(queue_item));
  q.front = -1;
  q.rear = -1;
  q.size = 0;
  q.capacity = capacity;
  return q;
}

queue_t enqueue(queue_t q, queue_item item) {
  if (q.size == q.capacity) {
    printf("Queue is full\n");
  } else {
    if (q.size == 0) {
      q.front = 0;
    }

    q.data[++q.rear] = item;
    q.size++;
  }

  return q;
}

queue_t dequeue(queue_t q) {
  if (q.size == 0) {
    printf("Queue is empty\n");
  } else {
    q.front++;
  }

  return q;
}

queue_item qpeek(queue_t q) {
  if (q.size == 0) {
    printf("Queue is empty\n");
    return -1;
  }

  return q.data[q.front];
}

void show_queue(queue_t q) {
  if (q.size == 0) {
    printf("Queue is empty\n");
    return;
  }

  for (int i = q.front; i <= q.rear; i++) {
    printf("%d ", q.data[i]);
  }
  printf("\n");
}

int main(void) {
  queue_t q = init_queue(QUEUE_CAPACITY);

  q = enqueue(q, 1);
  q = enqueue(q, 2);
  q = enqueue(q, 3);
  q = enqueue(q, 4);
  q = enqueue(q, 5);

  show_queue(q);

  free(q.data);
  return 0;
}
