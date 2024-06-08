// DEPENDENCIES
#include "priority_queue.h"
#include <stdio.h>
#include <string.h>

// STRUCTURES
struct QUEUE_DATA {
  int PID;
  int priority;
  char process_name[MAX_PROCESS_NAME_LENGTH];
};

struct QUEUE {
  int head;
  int tail;
  int capacity;
  queue_data *data;
};

// INIT ///////////////////////////////////////////////////
queue init_queue(int capacity) {
  queue q = malloc(sizeof(struct QUEUE));

  if (q == NULL)
    return q;

  q->data = malloc(sizeof(queue_data) * capacity);

  if (q->data == NULL) {
    free(q);
    return NULL;
  }

  q->head = 0;
  q->tail = 0;
  q->capacity = capacity;

  return q;
}

queue_data create_queue_data(int pid, int priority, char *process_name) {

  queue_data data = malloc(sizeof(struct QUEUE_DATA));

  if (data == NULL)
    return NULL;

  data->PID = pid;
  data->priority = priority;
  strncpy(data->process_name, process_name, MAX_PROCESS_NAME_LENGTH - 1);

  return data;
}
///////////////////////////////////////////////////////////

int queue_is_empty(queue q) { return q->head >= q->tail; }
int queue_is_full(queue q) { return q->tail >= q->capacity; }

// OPERATIONS

void insert_at(queue q, queue_data data, int index) {

  for (int i = q->tail - 1; i >= index; i--) {
    q->data[i + 1] = q->data[i];
  }

  q->data[index] = data;
  q->tail++;
}

int check_higher_priority(queue_data new_data, queue_data data) {
  return new_data->priority < data->priority;
}

void priority_insert(queue q, queue_data data) {

  for (int i = q->head; i < q->tail; i++)
    if (check_higher_priority(data, q->data[i])) {
      insert_at(q, data, i);
      return;
    }

  insert_at(q, data, q->tail);
}

queue enqueue(queue q, queue_data data) {
  if (queue_is_full(q))
    return q;

  if (queue_is_empty(q)) {
    q->data[q->tail++] = data;
    return q;
  }

  priority_insert(q, data);

  return q;
}

queue dequeue(queue q) {
  if (queue_is_empty(q))
    return q;

  q->head++;

  free(q->data[q->head - 1]);

  return q;
}

queue_data head(queue q) {
  if (queue_is_empty(q))
    return NULL;

  return q->data[q->head];
}

queue_data tail(queue q) {
  if (queue_is_empty(q))
    return NULL;

  return q->data[q->tail - 1];
}

// DEBUGGING
void print_queue_data(queue_data data) {

  printf("PID: %d | PRIORITY: %d | PROCESS: %s\n", data->PID, data->priority,
         data->process_name);
}

void print_queue(queue q) {

  if (queue_is_empty(q)) {
    printf("EMPTY!\n");
    return;
  }

  for (int i = q->head; i < q->tail; i++) {
    print_queue_data(q->data[i]);
  }
}

// FREE
void free_queue(queue q) {
  for (int i = q->head; i < q->tail; i++)
    free(q->data[i]);

  free(q->data);
  free(q);
}
