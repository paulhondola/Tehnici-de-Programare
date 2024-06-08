#ifndef __PRIORITY_QUEUE_H
#define __PRIORITY_QUEUE_H

// DEPENDENCIES /////////////////////////////
#include <stdlib.h>
/////////////////////////////////////////////

// CONSTANTS ////////////////////////////////
#define MAX_PROCESS_NAME_LENGTH 100
/////////////////////////////////////////////

// STRUCTURES ///////////////////////////////
typedef struct QUEUE_DATA *queue_data;
typedef struct QUEUE *queue;
/////////////////////////////////////////////

// FUNCTIONS

// INITIALIZATION
queue init_queue(int);
queue_data create_queue_data(int pid, int priority, char *process_name);

// GETTERS
int get_queue_size(queue);
int get_queue_capacity(queue);

// QUEUE SIZE FUNCTIONS
int queue_is_empty(queue);
int queue_is_full(queue);
queue queue_realloc(queue);

// QUEUE OPERATIONS
queue enqueue(queue, queue_data);
queue dequeue(queue);
void move_queue(queue);
queue_data head(queue);
queue_data tail(queue);

// DEBUGGING
void print_queue(queue);

// FREE
void free_queue(queue);

#endif
