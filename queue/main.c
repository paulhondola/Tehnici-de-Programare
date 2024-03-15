#include "queue.h"

int main(int argc, char *argv[]) {

  if (argc != 4) {
    perror("Invalid number of arguments -> need 3 -> 1. QUEUE_DEBUG 2. "
           "QUEUE_DYNAMIC 3. QUEUE_CHUNK");
    return 1;
  }

  QUEUE_DEBUG = atoi(argv[1]);
  QUEUE_DYNAMIC = atoi(argv[2]);
  QUEUE_CHUNK = (size_t)atoi(argv[3]);

  queue q;

  q = init_queue(QUEUE_CHUNK);

  for (int i = 0; i < 106; i++)
    enqueue(&q, i);

  for (int i = 0; i < 50; i++)
    dequeue(&q);

  for (int i = 106; i < 130; i++)
    enqueue(&q, i);

  free_queue(&q);

  return 0;
}
