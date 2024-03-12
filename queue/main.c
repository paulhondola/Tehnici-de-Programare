#include "queue.h"

int main(void) {
  queue q;

  q = init_queue(10);

  for (int i = 0; i < 106; i++)
    enqueue(&q, i);

  for (int i = 0; i < 50; i++)
    dequeue(&q);

  for (int i = 106; i < 130; i++)
    enqueue(&q, i);

  free_queue(&q);

  return 0;
}
