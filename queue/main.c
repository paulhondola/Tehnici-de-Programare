#include "queue.h"

int main(void) {
  queue q;

  init_queue(&q);

  enqueue(&q, 10);
  enqueue(&q, 20);

  enqueue(&q, 30);
  enqueue(&q, 40);

  dequeue(&q);
  dequeue(&q);
  dequeue(&q);

  enqueue(&q, 50);

  print_queue(&q);

  free_queue(&q);
  return 0;
}
